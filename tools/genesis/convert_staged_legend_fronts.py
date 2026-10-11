#!/usr/bin/env python3
"""Convert tools/genesis/art_staging/*_front.png into GBA-ready anim_front + pals.

Outputs per species under graphics/pokemon/<species>/:
  - anim_front.png  (64x128 indexed, 2 stacked frames)
  - back.png        (64x64 indexed, horizontally flipped front)
  - normal.pal / shiny.pal (JASC from front palette; shiny = hue-shifted)

Index 0 is forced transparent. Rebuild ROM after running.
"""
from __future__ import annotations

import colorsys
import struct
from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
STAGING = ROOT / "tools" / "genesis" / "art_staging"
SPECIES = ("aethernox", "solara", "genesis")


def write_jasc_pal(path: Path, colors: list[tuple[int, int, int]]) -> None:
    while len(colors) < 16:
        colors.append((0, 0, 0))
    colors = colors[:16]
    lines = ["JASC-PAL", "0100", "16"]
    for r, g, b in colors:
        lines.append(f"{r} {g} {b}")
    path.write_text("\n".join(lines) + "\n", encoding="ascii")


def hue_shift_rgb(rgb: tuple[int, int, int], degrees: float) -> tuple[int, int, int]:
    r, g, b = [c / 255.0 for c in rgb]
    h, s, v = colorsys.rgb_to_hsv(r, g, b)
    h = (h + degrees / 360.0) % 1.0
    r2, g2, b2 = colorsys.hsv_to_rgb(h, s, v)
    return (int(r2 * 255), int(g2 * 255), int(b2 * 255))


def quantize_to_16(img: Image.Image) -> Image.Image:
    """RGBA -> P mode, 16 colors, index 0 transparent."""
    rgba = img.convert("RGBA")
    # Composite onto a unique magenta key so we can reclaim transparency after quantize.
    key = (255, 0, 255, 255)
    bg = Image.new("RGBA", rgba.size, key)
    composed = Image.alpha_composite(bg, rgba)
    # Quantize opaque pixels only
    rgb = composed.convert("RGB")
    q = rgb.quantize(colors=15, method=Image.Quantize.MEDIANCUT)
    # Build palette: slot 0 = key/transparent black for GBA, then 15 colors
    pal = q.getpalette()[: 15 * 3]
    # Remap: find key color index if present
    q_rgba = q.convert("RGBA")
    out = Image.new("P", q.size)
    new_pal = [0, 0, 0]  # index 0 transparent
    color_map: dict[tuple[int, int, int], int] = {(0, 0, 0): 0}
    # Collect unique colors excluding near-magenta key
    for y in range(q.size[1]):
        for x in range(q.size[0]):
            r, g, b, a = q_rgba.getpixel((x, y))
            if (r, g, b) == (255, 0, 255) or a == 0:
                continue
            if (r, g, b) not in color_map:
                if len(new_pal) // 3 >= 16:
                    continue
                color_map[(r, g, b)] = len(new_pal) // 3
                new_pal.extend([r, g, b])
    while len(new_pal) < 48:
        new_pal.extend([0, 0, 0])
    out.putpalette(new_pal)
    pixels = []
    for y in range(q.size[1]):
        for x in range(q.size[0]):
            r, g, b, a = q_rgba.getpixel((x, y))
            src_a = rgba.getpixel((x, y))[3]
            if src_a < 16 or (r, g, b) == (255, 0, 255):
                pixels.append(0)
            else:
                # nearest in color_map
                best = 1
                best_d = 1e18
                for (cr, cg, cb), idx in color_map.items():
                    if idx == 0:
                        continue
                    d = (r - cr) ** 2 + (g - cg) ** 2 + (b - cb) ** 2
                    if d < best_d:
                        best_d = d
                        best = idx
                pixels.append(best if (r, g, b) not in color_map else color_map[(r, g, b)])
    out.putdata(pixels)
    return out


def prep_frame(src: Path) -> Image.Image:
    im = Image.open(src).convert("RGBA")
    # Fit into 64x64 with nearest-neighbor
    im.thumbnail((64, 64), Image.Resampling.NEAREST)
    canvas = Image.new("RGBA", (64, 64), (0, 0, 0, 0))
    ox = (64 - im.width) // 2
    oy = (64 - im.height) // 2
    canvas.paste(im, (ox, oy), im)
    return quantize_to_16(canvas)


def palette_from_p(img: Image.Image) -> list[tuple[int, int, int]]:
    pal = img.getpalette() or [0] * 48
    colors = []
    for i in range(16):
        colors.append((pal[i * 3], pal[i * 3 + 1], pal[i * 3 + 2]))
    return colors


def convert_one(species: str) -> None:
    src = STAGING / f"{species}_front.png"
    if not src.exists():
        raise SystemExit(f"missing {src}")
    out_dir = ROOT / "graphics" / "pokemon" / species
    out_dir.mkdir(parents=True, exist_ok=True)

    frame = prep_frame(src)
    # anim_front: two stacked identical frames (keeps 2-frame anim slots valid)
    anim = Image.new("P", (64, 128))
    anim.putpalette(frame.getpalette())
    anim.paste(frame, (0, 0))
    anim.paste(frame, (0, 64))
    anim_path = out_dir / "anim_front.png"
    anim.save(anim_path)

    back = frame.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
    back_path = out_dir / "back.png"
    back.save(back_path)

    colors = palette_from_p(frame)
    write_jasc_pal(out_dir / "normal.pal", colors)
    shiny = [colors[0]] + [hue_shift_rgb(c, 40.0) for c in colors[1:]]
    write_jasc_pal(out_dir / "shiny.pal", shiny)

    # Keep overworld pals in sync with battle (simple copy)
    write_jasc_pal(out_dir / "overworld_normal.pal", colors)
    write_jasc_pal(out_dir / "overworld_shiny.pal", shiny)

    print(f"OK {species}: {anim_path.relative_to(ROOT)} + back + pals")


def main() -> None:
    for species in SPECIES:
        convert_one(species)
    print("Done. Wire gMonFrontPic_* / gMonBackPic_* and rebuild.")


if __name__ == "__main__":
    main()
