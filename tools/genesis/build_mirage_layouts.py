#!/usr/bin/env python3
"""GENESIS: Rebuild unique Mirage City / Gym layout binaries.

Seeds building footprints from Fallarbor / Rustboro gym metatiles, then
composes an oasis plaza layout. Safe to re-run; keeps door metatiles aligned
with data/maps/MirageCity/map.json warp_events.

Usage (repo root):
  python3 tools/genesis/build_mirage_layouts.py
"""

from __future__ import annotations

import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def load_map(path: Path, w: int, h: int) -> list[int]:
    data = path.read_bytes()
    cells = [struct.unpack_from("<H", data, i)[0] for i in range(0, len(data), 2)]
    if len(cells) != w * h:
        raise SystemExit(f"{path}: expected {w*h} cells, got {len(cells)}")
    return cells


def save_map(path: Path, cells: list[int]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(b"".join(struct.pack("<H", c) for c in cells))


def pack(mid: int, coll: int = 0, elev: int = 3) -> int:
    return (mid & 0x3FF) | ((coll & 3) << 10) | ((elev & 0xF) << 12)


def stamp(dst, dw, dx, dy, src, sw, sx, sy, bw, bh) -> None:
    for y in range(bh):
        for x in range(bw):
            dst[(dy + y) * dw + (dx + x)] = src[(sy + y) * sw + (sx + x)]


def rect_fill(dst, w, x0, y0, x1, y1, value) -> None:
    for y in range(y0, y1 + 1):
        for x in range(x0, x1 + 1):
            dst[y * w + x] = value


def hpath(dst, w, x0, x1, y, left, mid, right) -> None:
    if x1 < x0:
        x0, x1 = x1, x0
    dst[y * w + x0] = left
    for x in range(x0 + 1, x1):
        dst[y * w + x] = mid
    if x1 != x0:
        dst[y * w + x1] = right


def vpath(dst, w, x, y0, y1, top, mid, bot) -> None:
    if y1 < y0:
        y0, y1 = y1, y0
    dst[y0 * w + x] = top
    for y in range(y0 + 1, y1):
        dst[y * w + x] = mid
    if y1 != y0:
        dst[y1 * w + x] = bot


def build_city() -> None:
    fall = load_map(ROOT / "data/layouts/FallarborTown/map.bin", 20, 20)
    sand = pack(0x279, 0, 3)
    path_h, path_hl, path_hr = pack(0x2E9, 0, 3), pack(0x2E8, 0, 3), pack(0x2EA, 0, 3)
    path_v, path_vt, path_vb = pack(0x2F1, 0, 3), pack(0x2F0, 0, 3), pack(0x2F2, 0, 3)
    flower = pack(0x29F, 0, 3)
    rock_a, rock_b = pack(0x206, 0, 3), pack(0x207, 0, 3)
    water = pack(0x0A1, 0, 1)
    grass = pack(0x001, 0, 3)
    ash = pack(0x20A, 0, 3)
    wall = pack(0x265, 1, 0)

    w = h = 20
    m = [sand] * (w * h)
    for x in range(w):
        m[0 * w + x] = wall
        m[1 * w + x] = wall
        m[(h - 1) * w + x] = rock_a if x % 2 == 0 else rock_b
    for y in range(h):
        m[y * w] = wall
        m[y * w + w - 1] = wall

    rect_fill(m, w, 2, 2, 5, 3, ash)
    rect_fill(m, w, 14, 17, 17, 18, ash)
    rect_fill(m, w, 2, 17, 4, 18, grass)

    hpath(m, w, 5, 16, 7, path_hl, path_h, path_hr)
    vpath(m, w, 7, 7, 14, path_vt, path_v, path_vb)
    vpath(m, w, 12, 7, 14, path_vt, path_v, path_vb)
    hpath(m, w, 5, 15, 15, path_hl, path_h, path_hr)
    hpath(m, w, 7, 12, 8, path_hl, path_h, path_hr)
    hpath(m, w, 7, 12, 13, path_hl, path_h, path_hr)
    hpath(m, w, 2, 7, 10, path_hl, path_h, path_hr)
    vpath(m, w, 5, 7, 10, path_vt, path_v, path_vb)
    vpath(m, w, 9, 6, 7, path_vt, path_v, path_vb)
    vpath(m, w, 15, 6, 7, path_vt, path_v, path_vb)
    vpath(m, w, 15, 14, 15, path_vt, path_v, path_vb)
    vpath(m, w, 4, 15, 15, path_vt, path_v, path_vb)

    rect_fill(m, w, 8, 9, 11, 12, water)
    for x, y in [(7, 9), (7, 12), (12, 9), (12, 12), (7, 10), (12, 11), (9, 8), (10, 13)]:
        m[y * w + x] = flower

    # Buildings last (door coords must match MirageCity/map.json)
    stamp(m, w, 7, 2, fall, 20, 6, 3, 5, 5)  # gym door (9,6)
    stamp(m, w, 14, 3, fall, 20, 13, 4, 4, 4)  # center (15,6)
    stamp(m, w, 14, 12, fall, 20, 14, 13, 4, 3)  # mart (15,14)
    stamp(m, w, 3, 14, fall, 20, 5, 15, 4, 3)  # hall (4,16)
    stamp(m, w, 1, 7, fall, 20, 1, 4, 4, 3)  # teleport (1,9)

    checks = {
        "gym": (9, 6, 0x36C),
        "center": (15, 6, 0x061),
        "mart": (15, 14, 0x041),
        "hall": (4, 16, 0x2A5),
        "teleport": (1, 9, 0x2A5),
    }
    for name, (x, y, expect) in checks.items():
        got = m[y * w + x] & 0x3FF
        if got != expect:
            raise SystemExit(f"door {name} at ({x},{y}) got {got:#x}, want {expect:#x}")

    out = ROOT / "data/layouts/MirageCity"
    save_map(out / "map.bin", m)
    (out / "border.bin").write_bytes((ROOT / "data/layouts/FallarborTown/border.bin").read_bytes())
    print("Wrote", out / "map.bin")


def build_gym() -> None:
    gw, gh = 11, 20
    src = load_map(ROOT / "data/layouts/RustboroCity_Gym/map.bin", gw, gh)
    gym = src[:]
    floor = next(c for c in src if (c & 0x3FF) == 0x201)

    def find(mid: int) -> int:
        for c in src:
            if (c & 0x3FF) == mid:
                return c
        return floor

    pillar, block, rail = find(0x216), find(0x237), find(0x219)
    for y in range(4, 16):
        for x in range(1, 10):
            gym[y * gw + x] = floor
    for y in (5, 7, 9, 11, 13):
        gym[y * gw + 2] = pillar
        gym[y * gw + 3] = block
        gym[y * gw + 8] = pillar
        gym[y * gw + 7] = block
    for y in (6, 10, 14):
        gym[y * gw + 5] = rail
    for y in range(0, 4):
        for x in range(gw):
            gym[y * gw + x] = src[y * gw + x]
    for y in range(17, 20):
        for x in range(gw):
            gym[y * gw + x] = src[y * gw + x]

    if (gym[19 * gw + 5] & 0x3FF) != 0x006 or (gym[19 * gw + 6] & 0x3FF) != 0x007:
        raise SystemExit("gym exit doors missing")

    out = ROOT / "data/layouts/MirageCity_Gym"
    save_map(out / "map.bin", gym)
    (out / "border.bin").write_bytes((ROOT / "data/layouts/RustboroCity_Gym/border.bin").read_bytes())
    print("Wrote", out / "map.bin")


def main() -> int:
    build_city()
    build_gym()
    print("Mirage layouts rebuilt OK")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
