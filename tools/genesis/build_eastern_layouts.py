#!/usr/bin/env python3
"""GENESIS: Rebuild unique eastern city / gym layout binaries (badges 10–16).

Door metatiles stay aligned with Mirage-style warp coords (gym 9,6 / center 15,6 /
mart 15,14 / hall 4,16 / teleport 1,9). Each city gets a distinct plaza theme.

Usage (repo root):
  python3 tools/genesis/build_eastern_layouts.py
"""

from __future__ import annotations

import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

# Shared Fallarbor door stamps (metatile checks)
DOOR_CHECKS = {
    "gym": (9, 6, 0x36C),
    "center": (15, 6, 0x061),
    "mart": (15, 14, 0x041),
    "hall": (4, 16, 0x2A5),
    "teleport": (1, 9, 0x2A5),
}


def load_map(path: Path, w: int, h: int) -> list[int]:
    data = path.read_bytes()
    cells = [struct.unpack_from("<H", data, i)[0] for i in range(0, len(data), 2)]
    if len(cells) != w * h:
        raise SystemExit(f"{path}: expected {w * h} cells, got {len(cells)}")
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


def stamp_buildings(m, fall) -> None:
    w = 20
    stamp(m, w, 7, 2, fall, 20, 6, 3, 5, 5)  # gym door (9,6)
    stamp(m, w, 14, 3, fall, 20, 13, 4, 4, 4)  # center (15,6)
    stamp(m, w, 14, 12, fall, 20, 14, 13, 4, 3)  # mart (15,14)
    stamp(m, w, 3, 14, fall, 20, 5, 15, 4, 3)  # hall (4,16)
    stamp(m, w, 1, 7, fall, 20, 1, 4, 4, 3)  # teleport (1,9)


def verify_doors(m, label: str) -> None:
    w = 20
    for name, (x, y, expect) in DOOR_CHECKS.items():
        got = m[y * w + x] & 0x3FF
        if got != expect:
            raise SystemExit(f"{label} door {name} at ({x},{y}) got {got:#x}, want {expect:#x}")


def base_tiles():
    return {
        "sand": pack(0x279, 0, 3),
        "path_h": pack(0x2E9, 0, 3),
        "path_hl": pack(0x2E8, 0, 3),
        "path_hr": pack(0x2EA, 0, 3),
        "path_v": pack(0x2F1, 0, 3),
        "path_vt": pack(0x2F0, 0, 3),
        "path_vb": pack(0x2F2, 0, 3),
        "flower": pack(0x29F, 0, 3),
        "rock_a": pack(0x206, 0, 3),
        "rock_b": pack(0x207, 0, 3),
        "water": pack(0x0A1, 0, 1),
        "grass": pack(0x001, 0, 3),
        "ash": pack(0x20A, 0, 3),
        "wall": pack(0x265, 1, 0),
        "tree": pack(0x00E, 1, 3),
        "tall": pack(0x00D, 0, 3),
    }


def rim_walls(m, w, h, t) -> None:
    for x in range(w):
        m[0 * w + x] = t["wall"]
        m[1 * w + x] = t["wall"]
        m[(h - 1) * w + x] = t["rock_a"] if x % 2 == 0 else t["rock_b"]
    for y in range(h):
        m[y * w] = t["wall"]
        m[y * w + w - 1] = t["wall"]


def common_paths(m, w, t) -> None:
    hpath(m, w, 5, 16, 7, t["path_hl"], t["path_h"], t["path_hr"])
    vpath(m, w, 7, 7, 14, t["path_vt"], t["path_v"], t["path_vb"])
    vpath(m, w, 12, 7, 14, t["path_vt"], t["path_v"], t["path_vb"])
    hpath(m, w, 5, 15, 15, t["path_hl"], t["path_h"], t["path_hr"])
    hpath(m, w, 7, 12, 8, t["path_hl"], t["path_h"], t["path_hr"])
    hpath(m, w, 7, 12, 13, t["path_hl"], t["path_h"], t["path_hr"])
    hpath(m, w, 2, 7, 10, t["path_hl"], t["path_h"], t["path_hr"])
    vpath(m, w, 5, 7, 10, t["path_vt"], t["path_v"], t["path_vb"])
    vpath(m, w, 9, 6, 7, t["path_vt"], t["path_v"], t["path_vb"])
    vpath(m, w, 15, 6, 7, t["path_vt"], t["path_v"], t["path_vb"])
    vpath(m, w, 15, 14, 15, t["path_vt"], t["path_v"], t["path_vb"])
    vpath(m, w, 4, 15, 15, t["path_vt"], t["path_v"], t["path_vb"])


def theme_verdantis(m, w, t) -> None:
    """Bug canopy — grass rings + flower nodes."""
    for i in range(w * 20):
        m[i] = t["grass"]
    rim_walls(m, w, 20, t)
    common_paths(m, w, t)
    rect_fill(m, w, 8, 9, 11, 12, t["tall"])
    for x, y in [(6, 9), (13, 9), (6, 12), (13, 12), (8, 8), (11, 13), (2, 12), (17, 11)]:
        m[y * w + x] = t["flower"]
    rect_fill(m, w, 2, 2, 4, 3, t["tree"])
    rect_fill(m, w, 16, 17, 17, 18, t["tree"])


def theme_obsidian(m, w, t) -> None:
    """Dark ash streets + volcanic rock."""
    for i in range(w * 20):
        m[i] = t["ash"]
    rim_walls(m, w, 20, t)
    common_paths(m, w, t)
    rect_fill(m, w, 8, 9, 11, 12, t["rock_a"])
    for x, y in [(3, 3), (16, 3), (3, 17), (17, 10), (10, 17)]:
        m[y * w + x] = t["rock_b"]
    rect_fill(m, w, 2, 17, 4, 18, t["sand"])


def theme_astral(m, w, t) -> None:
    """Dragon observatory — sand plaza + water mirror + rock spires."""
    for i in range(w * 20):
        m[i] = t["sand"]
    rim_walls(m, w, 20, t)
    common_paths(m, w, t)
    rect_fill(m, w, 8, 9, 11, 12, t["water"])
    for y in (3, 17):
        for x in (2, 5, 14, 17):
            m[y * w + x] = t["rock_a"]
    for x, y in [(7, 9), (12, 9), (7, 12), (12, 12)]:
        m[y * w + x] = t["flower"]


def theme_tidymoon(m, w, t) -> None:
    """Fairy tide pools — water L + flowers."""
    for i in range(w * 20):
        m[i] = t["sand"]
    rim_walls(m, w, 20, t)
    common_paths(m, w, t)
    rect_fill(m, w, 8, 9, 11, 12, t["water"])
    rect_fill(m, w, 2, 11, 5, 13, t["water"])
    for x, y in [(6, 8), (13, 8), (6, 13), (13, 13), (9, 14), (10, 8), (3, 10), (17, 12)]:
        m[y * w + x] = t["flower"]


def theme_eon(m, w, t) -> None:
    """Ghost mist — ash + irregular water pockets."""
    for i in range(w * 20):
        m[i] = t["ash"]
    rim_walls(m, w, 20, t)
    common_paths(m, w, t)
    rect_fill(m, w, 8, 9, 11, 12, t["water"])
    m[10 * w + 3] = t["water"]
    m[11 * w + 17] = t["water"]
    m[17 * w + 10] = t["water"]
    for x, y in [(2, 3), (17, 3), (2, 17), (16, 16)]:
        m[y * w + x] = t["rock_b"]


def theme_genesis(m, w, t) -> None:
    """Mixed hub — grass bands + sand plaza + water diamond."""
    for i in range(w * 20):
        m[i] = t["sand"]
    rim_walls(m, w, 20, t)
    common_paths(m, w, t)
    rect_fill(m, w, 2, 2, 5, 4, t["grass"])
    rect_fill(m, w, 14, 16, 17, 18, t["grass"])
    rect_fill(m, w, 8, 9, 11, 12, t["water"])
    for x, y in [(7, 10), (12, 10), (9, 8), (10, 13)]:
        m[y * w + x] = t["flower"]


def theme_summit(m, w, t) -> None:
    """Summit threshold — rock rim + sparse grass + high path."""
    for i in range(w * 20):
        m[i] = t["sand"]
    rim_walls(m, w, 20, t)
    for x in range(w):
        m[2 * w + x] = t["rock_a"] if x % 2 == 0 else t["rock_b"]
    common_paths(m, w, t)
    rect_fill(m, w, 8, 9, 11, 12, t["rock_a"])
    rect_fill(m, w, 2, 16, 5, 17, t["grass"])
    for x, y in [(10, 8), (9, 13), (6, 11), (13, 11)]:
        m[y * w + x] = t["flower"]


THEMES = {
    "VerdantisCity": theme_verdantis,
    "ObsidianCity": theme_obsidian,
    "AstralCity": theme_astral,
    "TidymoonCity": theme_tidymoon,
    "EonCity": theme_eon,
    "GenesisCity": theme_genesis,
    "SummitCity": theme_summit,
}


def build_city(folder: str) -> None:
    fall = load_map(ROOT / "data/layouts/FallarborTown/map.bin", 20, 20)
    t = base_tiles()
    w = h = 20
    m = [t["sand"]] * (w * h)
    THEMES[folder](m, w, t)
    stamp_buildings(m, fall)
    verify_doors(m, folder)
    out = ROOT / "data/layouts" / folder
    save_map(out / "map.bin", m)
    (out / "border.bin").write_bytes((ROOT / "data/layouts/FallarborTown/border.bin").read_bytes())
    # Ensure uniqueness vs Fallarbor and vs Mirage
    fall_bytes = (ROOT / "data/layouts/FallarborTown/map.bin").read_bytes()
    mirage = ROOT / "data/layouts/MirageCity/map.bin"
    raw = (out / "map.bin").read_bytes()
    if raw == fall_bytes:
        raise SystemExit(f"{folder} still identical to Fallarbor")
    if mirage.exists() and raw == mirage.read_bytes():
        raise SystemExit(f"{folder} identical to MirageCity")
    print("Wrote", out / "map.bin")


def build_gym(folder: str, variant: int) -> None:
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
    # Variant pillar patterns so gyms are not byte-identical
    offsets = [
        (5, 7, 9, 11, 13),
        (4, 6, 8, 10, 14),
        (5, 6, 9, 12, 14),
        (4, 7, 10, 11, 13),
        (5, 8, 9, 11, 14),
        (4, 6, 9, 12, 13),
        (5, 7, 10, 12, 14),
    ][variant % 7]
    for y in offsets:
        gym[y * gw + 2] = pillar
        gym[y * gw + 3] = block
        gym[y * gw + 8] = pillar
        gym[y * gw + 7] = block
    for y in (6 + (variant % 3), 10, 14 - (variant % 2)):
        if 4 <= y <= 15:
            gym[y * gw + 5] = rail
    for y in range(0, 4):
        for x in range(gw):
            gym[y * gw + x] = src[y * gw + x]
    for y in range(17, 20):
        for x in range(gw):
            gym[y * gw + x] = src[y * gw + x]

    if (gym[19 * gw + 5] & 0x3FF) != 0x006 or (gym[19 * gw + 6] & 0x3FF) != 0x007:
        raise SystemExit(f"{folder} gym exit doors missing")

    out = ROOT / "data/layouts" / f"{folder}_Gym"
    save_map(out / "map.bin", gym)
    (out / "border.bin").write_bytes((ROOT / "data/layouts/RustboroCity_Gym/border.bin").read_bytes())
    print("Wrote", out / "map.bin")


def build_wt_lobby() -> None:
    src_dir = ROOT / "data/layouts/BattleFrontier_BattleTowerLobby"
    out = ROOT / "data/layouts/WorldTournament_Lobby"
    out.mkdir(parents=True, exist_ok=True)
    # Dedicated copy so Porymap can diverge later
    (out / "map.bin").write_bytes((src_dir / "map.bin").read_bytes())
    (out / "border.bin").write_bytes((src_dir / "border.bin").read_bytes())
    print("Wrote", out / "map.bin")


def main() -> int:
    for i, folder in enumerate(THEMES):
        build_city(folder)
        build_gym(folder, i)
    build_wt_lobby()
    print("Eastern layouts rebuilt OK")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
