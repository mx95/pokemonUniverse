#!/usr/bin/env python3
"""Generate Genesis title-screen graphics (version banner + animated BG)."""
from __future__ import annotations

from pathlib import Path

from PIL import Image, ImageDraw, ImageFont

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / "graphics" / "title_screen"


def _font(size: int) -> ImageFont.ImageFont:
    for name in (
        "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf",
        "/usr/share/fonts/truetype/liberation/LiberationSans-Bold.ttf",
        "C:/Windows/Fonts/arialbd.ttf",
        "C:/Windows/Fonts/segoeui.ttf",
    ):
        p = Path(name)
        if p.exists():
            return ImageFont.truetype(str(p), size)
    return ImageFont.load_default()


def make_genesis_version() -> None:
    """Two 64x32 halves → 128x32 8bpp sheet matching emerald_version.png."""
    w, h = 128, 32
    img = Image.new("RGBA", (w, h), (0, 0, 0, 0))
    draw = ImageDraw.Draw(img)
    font = _font(14)
    text = "GENESIS VERSION"
    # Measure and center
    bbox = draw.textbbox((0, 0), text, font=font)
    tw, th = bbox[2] - bbox[0], bbox[3] - bbox[1]
    x = (w - tw) // 2
    y = (h - th) // 2 - 1
    # Black outline
    for ox in (-1, 0, 1):
        for oy in (-1, 0, 1):
            if ox or oy:
                draw.text((x + ox, y + oy), text, font=font, fill=(0, 0, 0, 255))
    # Silver-white fill with slight teal tint for Genesis
    draw.text((x, y), text, font=font, fill=(220, 245, 255, 255))
    # Convert to palette (keep index 0 transparent-ish black for GBA tools)
    pal = Image.new("P", (1, 1))
    palette = [0, 0, 0] + [220, 245, 255] * 3 + [0, 0, 0] * 252
    # Build a small unique palette from image
    q = img.convert("RGB").quantize(colors=16, method=Image.Quantize.MEDIANCUT)
    q.save(OUT / "emerald_version.png")
    print("wrote emerald_version.png", q.size)


def make_clouds() -> None:
    """Soft aurora / genesis-energy wisps — same size as clouds.png."""
    src = Image.open(OUT / "clouds.png")
    w, h = src.size
    img = Image.new("RGB", (w, h), (8, 28, 48))
    draw = ImageDraw.Draw(img)
    # Horizontal energy bands
    bands = [
        ((0, h // 5), (w, h // 5 + 3), (40, 180, 200)),
        ((0, h // 3), (w, h // 3 + 2), (80, 220, 180)),
        ((0, 2 * h // 5), (w, 2 * h // 5 + 4), (120, 160, 255)),
        ((0, 3 * h // 5), (w, 3 * h // 5 + 2), (60, 200, 160)),
        ((0, 4 * h // 5), (w, 4 * h // 5 + 3), (100, 140, 230)),
    ]
    for (x0, y0), (x1, y1), color in bands:
        for i in range(-2, 3):
            c = tuple(max(0, min(255, ch + i * 12)) for ch in color)
            draw.line([(0, y0 + i), (w - 1, y1 + i)], fill=c, width=1)
        # Soft blobs
        for bx in range(0, w, max(8, w // 6)):
            draw.ellipse([bx, y0 - 3, bx + 14, y1 + 4], fill=color)
    q = img.quantize(colors=16, method=Image.Quantize.MEDIANCUT)
    q.save(OUT / "clouds.png")
    print("wrote clouds.png", q.size)


def make_silhouette() -> None:
    """Replace Rayquaza with a Genesis Energy serpent / aura silhouette."""
    src = Image.open(OUT / "rayquaza.png")
    w, h = src.size
    # Deep teal field (index colors for 4bpp BG)
    img = Image.new("RGB", (w, h), (6, 22, 36))
    draw = ImageDraw.Draw(img)
    # Vertical coiled energy form (center)
    cx = w // 2
    # Body coils
    points = []
    for i in range(0, h, 2):
        wave = int(18 * __import__("math").sin(i / 14.0))
        points.append((cx + wave - 10, i))
    for i in range(h - 1, -1, -2):
        wave = int(18 * __import__("math").sin(i / 14.0))
        points.append((cx + wave + 10, i))
    if len(points) >= 3:
        draw.polygon(points, fill=(12, 70, 58))
    # Glowing orbs along the body (legendary marking color pulses on palette index)
    import math

    for i, t in enumerate(range(12, h - 12, h // 7)):
        ox = int(18 * math.sin(t / 14.0))
        r = 4 + (i % 2)
        draw.ellipse(
            [cx + ox - r, t - r, cx + ox + r, t + r],
            fill=(240, 220, 60),
        )
    # Crown / crest at top
    draw.polygon([(cx, 4), (cx - 16, 28), (cx + 16, 28)], fill=(18, 90, 72))
    draw.ellipse([cx - 5, 8, cx + 5, 18], fill=(255, 230, 80))
    q = img.quantize(colors=16, method=Image.Quantize.MEDIANCUT)
    q.save(OUT / "rayquaza.png")
    print("wrote rayquaza.png", q.size)


def main() -> None:
    make_genesis_version()
    make_clouds()
    make_silhouette()


if __name__ == "__main__":
    main()
