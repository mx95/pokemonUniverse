#!/usr/bin/env python3
"""Clone petalburg secondary tileset into verdant_town with recolored house palettes."""
from __future__ import annotations

import shutil
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SRC = ROOT / "data/tilesets/secondary/petalburg"
DST = ROOT / "data/tilesets/secondary/verdant_town"


def load_pal(path: Path):
    lines = path.read_text(encoding="utf-8").splitlines()
    colors = []
    for line in lines[3:]:
        if not line.strip():
            continue
        r, g, b = map(int, line.split())
        colors.append([r, g, b])
    return lines[:3], colors


def save_pal(path: Path, header, colors):
    out = header + [f"{r} {g} {b}" for r, g, b in colors]
    path.write_text("\n".join(out) + "\n", encoding="utf-8", newline="\n")


def shift(c, dr, dg, db):
    r, g, b = c
    return [max(0, min(255, r + dr)), max(0, min(255, g + dg)), max(0, min(255, b + db))]


def main() -> int:
    if DST.exists():
        shutil.rmtree(DST)
    shutil.copytree(SRC, DST)

    pals = DST / "palettes"

    # 08: greener accents / cooler trim
    h, cols = load_pal(pals / "08.pal")
    for i in range(1, 5):
        cols[i] = shift(cols[i], -20, 25, 10)
    for i in range(11, 15):
        cols[i] = shift(cols[i], -10, 15, 35)
    save_pal(pals / "08.pal", h, cols)

    # 09: coral roofs + parchment walls
    h, cols = load_pal(pals / "09.pal")
    for i in (12, 13, 14):
        r, g, b = cols[i]
        cols[i] = [min(255, r + 20), max(0, g - 40), max(0, b - 20)]
    for i in (1, 2, 3, 4):
        cols[i] = shift(cols[i], 15, 5, -25)
    save_pal(pals / "09.pal", h, cols)

    # 10: teal building trim
    h, cols = load_pal(pals / "10.pal")
    for i in (12, 13, 14):
        r, g, b = cols[i]
        cols[i] = [max(0, r - 60), min(255, g + 10), min(255, b + 40)]
    for i in (1, 2, 3, 4):
        cols[i] = shift(cols[i], -5, 10, 20)
    save_pal(pals / "10.pal", h, cols)

    print(f"Created {DST.relative_to(ROOT)} with recolored house palettes")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
