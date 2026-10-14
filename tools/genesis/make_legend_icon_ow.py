#!/usr/bin/env python3
"""Derive party icons + overworld sheets from unique legend anim_front.png art.

Outputs per species under graphics/pokemon/<species>/:
  - icon.png       (32x64 indexed, 2 stacked frames)
  - overworld.png  (384x64 indexed, 6 facing frames for SIZE_64x64 followers)
"""
from __future__ import annotations

from pathlib import Path

from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
SPECIES = ("aethernox", "solara", "genesis")


def clone_palette(src: Image.Image, size: tuple[int, int]) -> Image.Image:
    out = Image.new("P", size)
    out.putpalette(src.getpalette())
    return out


def make_icon(frame: Image.Image) -> Image.Image:
    """32x64 icon: two near-identical 32x32 frames."""
    rgba = frame.convert("RGBA").resize((32, 32), Image.Resampling.NEAREST)
    # Re-quantize using the front frame palette for consistency
    pal_img = Image.new("P", (32, 32))
    pal_img.putpalette(frame.getpalette())
    # Map onto existing palette via convert after compositing
    bg = Image.new("RGBA", (32, 32), (0, 0, 0, 0))
    bg.paste(rgba, (0, 0), rgba)
    # Nearest-color remap to frame palette
    src_pal = frame.getpalette() or [0] * 48
    colors = [(src_pal[i * 3], src_pal[i * 3 + 1], src_pal[i * 3 + 2]) for i in range(16)]
    pixels = []
    for y in range(32):
        for x in range(32):
            r, g, b, a = bg.getpixel((x, y))
            if a < 16:
                pixels.append(0)
                continue
            best, best_d = 1, 1e18
            for i, (cr, cg, cb) in enumerate(colors):
                if i == 0:
                    continue
                d = (r - cr) ** 2 + (g - cg) ** 2 + (b - cb) ** 2
                if d < best_d:
                    best_d = d
                    best = i
            pixels.append(best)
    small = Image.new("P", (32, 32))
    small.putpalette(src_pal)
    small.putdata(pixels)

    icon = clone_palette(frame, (32, 64))
    icon.paste(small, (0, 0))
    # Second frame: 1px vertical nudge for a tiny idle bob
    bob = Image.new("P", (32, 32))
    bob.putpalette(src_pal)
    bob_pixels = [0] * (32 * 32)
    for y in range(31):
        for x in range(32):
            bob_pixels[(y + 1) * 32 + x] = small.getpixel((x, y))
    bob.putdata(bob_pixels)
    icon.paste(bob, (0, 32))
    return icon


def make_overworld(frame: Image.Image) -> Image.Image:
    """384x64 sheet: 6x 64x64 frames (down/up/side x2 walk)."""
    ow = clone_palette(frame, (384, 64))
    # Frame layout matches Expansion large follower sheets.
    placements = [
        (0, 0),    # down idle
        (64, 0),   # down walk
        (128, 0),  # up idle
        (192, 0),  # up walk
        (256, 0),  # side idle
        (320, 0),  # side walk
    ]
    for i, (ox, oy) in enumerate(placements):
        cell = frame.copy()
        if i in (1, 3, 5):
            # Walk frame: 1px horizontal nudge
            nudged = clone_palette(frame, (64, 64))
            nudged.paste(frame, (1 if i != 5 else -1, 0))
            cell = nudged
        if i >= 4:
            cell = cell.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
        ow.paste(cell, (ox, oy))
    return ow


def convert_one(species: str) -> None:
    src = ROOT / "graphics" / "pokemon" / species / "anim_front.png"
    if not src.exists():
        raise SystemExit(f"missing {src}")
    anim = Image.open(src)
    if anim.mode != "P":
        raise SystemExit(f"{src} must be indexed")
    frame = anim.crop((0, 0, 64, 64))

    out_dir = src.parent
    icon = make_icon(frame)
    icon_path = out_dir / "icon.png"
    icon.save(icon_path)

    ow = make_overworld(frame)
    ow_path = out_dir / "overworld.png"
    ow.save(ow_path)

    print(f"OK {species}: {icon_path.relative_to(ROOT)} + {ow_path.relative_to(ROOT)}")


def main() -> None:
    for species in SPECIES:
        convert_one(species)
    print("Done. Wire gMonIcon_* / gObjectEventPic_* / sPicTable_* and rebuild.")


if __name__ == "__main__":
    raise SystemExit(main())
