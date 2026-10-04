#!/usr/bin/env python3
"""Build polished Genesis title-screen graphics from Expansion originals."""
from __future__ import annotations

import subprocess
from pathlib import Path

from PIL import Image, ImageDraw, ImageFont

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / "graphics" / "title_screen"
BASE = "e8bd1cd7b0"  # expansion/1.17.0


def _git_bytes(path: str) -> bytes:
    return subprocess.check_output(["git", "show", f"{BASE}:{path}"], cwd=ROOT)


def _restore(path: str) -> Path:
    dest = ROOT / path
    dest.write_bytes(_git_bytes(path))
    return dest


def _font(size: int) -> ImageFont.FreeTypeFont | ImageFont.ImageFont:
    for name in (
        "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf",
        "/usr/share/fonts/truetype/liberation/LiberationSans-Bold.ttf",
        "C:/Windows/Fonts/arialbd.ttf",
        "C:/Windows/Fonts/segoeuib.ttf",
    ):
        p = Path(name)
        if p.exists():
            return ImageFont.truetype(str(p), size)
    return ImageFont.load_default()


def make_genesis_version() -> None:
    """128x32 8bpp banner: GENESIS VERSION (two 64x32 halves)."""
    w, h = 128, 32
    img = Image.new("RGBA", (w, h), (0, 0, 0, 0))
    draw = ImageDraw.Draw(img)
    font = _font(13)
    text = "GENESIS VERSION"
    bbox = draw.textbbox((0, 0), text, font=font)
    tw, th = bbox[2] - bbox[0], bbox[3] - bbox[1]
    x = (w - tw) // 2
    y = max(0, (h - th) // 2 - 1)

    # Deep navy outline for readability over the logo
    for ox in (-2, -1, 0, 1, 2):
        for oy in (-2, -1, 0, 1, 2):
            if ox or oy:
                draw.text((x + ox, y + oy), text, font=font, fill=(8, 24, 48, 255))
    # Soft teal top highlight
    draw.text((x, y - 1), text, font=font, fill=(120, 220, 230, 255))
    # Silver body
    draw.text((x, y), text, font=font, fill=(235, 248, 255, 255))

    q = img.convert("RGB").quantize(colors=16, method=Image.Quantize.MEDIANCUT)
    # Force index 0 to black for GBA transparency conventions
    pal = q.getpalette() or []
    if len(pal) >= 3:
        pal[0:3] = [0, 0, 0]
        q.putpalette(pal)
    q.save(OUT / "emerald_version.png")
    print("wrote emerald_version.png", q.size)


def _rgb555(r: int, g: int, b: int) -> int:
    return ((r >> 3) & 31) | (((g >> 3) & 31) << 5) | (((b >> 3) & 31) << 10)


def _rgb555_to_rgb(c: int) -> tuple[int, int, int]:
    r = (c & 31) * 255 // 31
    g = ((c >> 5) & 31) * 255 // 31
    b = ((c >> 10) & 31) * 255 // 31
    return r, g, b


def _shift_teal(r: int, g: int, b: int) -> tuple[int, int, int]:
    import colorsys

    if r > 240 and g > 240 and b > 240:
        return r, g, b
    h, s, v = colorsys.rgb_to_hsv(r / 255.0, g / 255.0, b / 255.0)
    if s < 0.08:
        return (
            max(0, min(255, int(r * 0.85))),
            max(0, min(255, int(g * 0.95))),
            max(0, min(255, int(b * 1.15 + 10))),
        )
    if 0.05 < h < 0.25:  # yellow/orange markings stay warm
        h = 0.12
        s = min(1.0, s * 1.05)
        v = min(1.0, v * 1.05)
    else:
        h = (h + 0.14) % 1.0  # greens → teal/blue
        s = min(1.0, s * 1.08)
        v = min(1.0, v * 0.95)
    rr, gg, bb = colorsys.hsv_to_rgb(h, s, v)
    return int(rr * 255), int(gg * 255), int(bb * 255)


def write_genesis_palette() -> None:
    """Hue-shift Expansion's Rayquaza/clouds palette toward teal while keeping indices."""
    import struct

    # Prefer checked-in JASC .pal from Expansion (gbapal is a build artifact).
    pal_text = _git_bytes("graphics/title_screen/rayquaza_and_clouds.pal").decode("ascii")
    colors = []
    for line in pal_text.splitlines()[3:]:
        parts = line.split()
        if len(parts) == 3:
            colors.append(_shift_teal(*(int(x) for x in parts)))

    lines = ["JASC-PAL", "0100", str(len(colors))]
    out_raw = bytearray()
    for r, g, b in colors:
        lines.append(f"{r} {g} {b}")
        out_raw += struct.pack("<H", _rgb555(r, g, b))
    (OUT / "rayquaza_and_clouds.pal").write_text("\n".join(lines) + "\n", encoding="ascii")
    (OUT / "rayquaza_and_clouds.gbapal").write_bytes(out_raw)
    print("wrote rayquaza_and_clouds.pal/.gbapal", len(colors), "colors")


def restore_geometry() -> None:
    """Bring back Expansion tile sheets + tilemaps so the title layout is correct."""
    for rel in (
        "graphics/title_screen/rayquaza.png",
        "graphics/title_screen/clouds.png",
        "graphics/title_screen/rayquaza.bin",
        "graphics/title_screen/clouds.bin",
    ):
        _restore(rel)
        print("restored", rel)


def main() -> None:
    OUT.mkdir(parents=True, exist_ok=True)
    restore_geometry()
    write_genesis_palette()
    make_genesis_version()
    print("title assets ready")


if __name__ == "__main__":
    main()
