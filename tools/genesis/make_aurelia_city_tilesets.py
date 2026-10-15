#!/usr/bin/env python3
"""Clone Hoenn secondary tilesets into Aurelia-branded palette variants."""
from __future__ import annotations

import shutil
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SEC = ROOT / "data/tilesets/secondary"

# name, source folder, list of (pal_file, [(idx, dr,dg,db)|('set', idx, r,g,b)...])
# Simplified: per-pal global shifts for indices 1-4 and 11-14
CITY_PACKS = [
    # mid-game
    ("ironridge", "dewford", (-25, -10, 20), (-40, -20, 10), (-15, 5, 25)),
    ("celestia", "mauville", (20, 10, -30), (40, 25, -40), (10, 5, -20)),
    ("frostveil", "lavaridge", (-20, 10, 45), (-30, 20, 50), (-10, 15, 35)),
    ("solaris", "fortree", (35, 15, -25), (45, 5, -35), (20, 10, -15)),
    ("stormbreak", "mossdeep", (-15, -5, 30), (-25, 0, 40), (-10, 5, 25)),
    ("titania", "sootopolis", (-30, -15, -10), (-20, -5, 15), (-25, -20, 5)),
    # eastern twins (break Lumen / Port Azure clones)
    ("mirage_city", "lumen_town", (40, -10, -20), (50, 0, -30), (25, -5, -15)),
    ("genesis_city", "port_azure", (15, -25, 10), (25, -35, 20), (10, -20, 15)),
]


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


def apply_pack(dst: Path, s08, s09, s10) -> None:
    pals = dst / "palettes"
    for fname, s in (("08.pal", s08), ("09.pal", s09), ("10.pal", s10)):
        path = pals / fname
        if not path.exists():
            continue
        h, cols = load_pal(path)
        for i in range(1, min(5, len(cols))):
            cols[i] = shift(cols[i], *s)
        for i in range(11, min(15, len(cols))):
            cols[i] = shift(cols[i], s[0] // 2, s[1] // 2, s[2])
        save_pal(path, h, cols)


def main() -> int:
    for name, src_name, s08, s09, s10 in CITY_PACKS:
        src = SEC / src_name
        dst = SEC / name
        if not src.exists():
            print(f"SKIP missing source {src_name}")
            continue
        if dst.exists():
            shutil.rmtree(dst)
        shutil.copytree(src, dst)
        apply_pack(dst, s08, s09, s10)
        print(f"Created {dst.relative_to(ROOT)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
