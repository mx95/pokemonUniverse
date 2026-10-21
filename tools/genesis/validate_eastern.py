#!/usr/bin/env python3
"""GENESIS: Assert eastern cities 10–16 + World Tournament lobby wiring."""

from __future__ import annotations

import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

CITIES = [
    ("VerdantisCity", "MAPSEC_VERDANTIS_CITY", "LAYOUT_VERDANTIS_CITY", "CELIA", "FLAG_GENESIS_BADGE_10_GET", "VERDANTIS"),
    ("ObsidianCity", "MAPSEC_OBSIDIAN_CITY", "LAYOUT_OBSIDIAN_CITY", "NOCTIS", "FLAG_GENESIS_BADGE_11_GET", "OBSIDIAN"),
    ("AstralCity", "MAPSEC_ASTRAL_CITY", "LAYOUT_ASTRAL_CITY", "DRAKE", "FLAG_GENESIS_BADGE_12_GET", "ASTRAL"),
    ("TidymoonCity", "MAPSEC_TIDYMOON_CITY", "LAYOUT_TIDYMOON_CITY", "LUNA", "FLAG_GENESIS_BADGE_13_GET", "TIDYMOON"),
    ("EonCity", "MAPSEC_EON_CITY", "LAYOUT_EON_CITY", "MORRIGAN", "FLAG_GENESIS_BADGE_14_GET", "EON"),
    ("GenesisCity", "MAPSEC_GENESIS_CITY", "LAYOUT_GENESIS_CITY", "COLLEAGUE", "FLAG_GENESIS_BADGE_15_GET", "GENESISCITY"),
    ("SummitCity", "MAPSEC_SUMMIT_CITY", "LAYOUT_SUMMIT_CITY", "MENTOR", "FLAG_GENESIS_BADGE_16_GET", "SUMMIT"),
]

DOOR_CHECKS = [
    (15, 14, 0x041, "mart"),
    (9, 6, 0x36C, "gym"),
    (15, 6, 0x061, "center"),
    (4, 16, 0x2A5, "hall"),
    (1, 9, 0x2A5, "teleport"),
]


def cell(path: Path, w: int, x: int, y: int) -> int:
    data = path.read_bytes()
    return struct.unpack_from("<H", data, 2 * (y * w + x))[0] & 0x3FF


def main() -> int:
    issues: list[str] = []

    groups = json.loads((ROOT / "data/maps/map_groups.json").read_text(encoding="utf-8"))
    special = groups.get("gMapGroup_SpecialArea", [])
    event_scripts = (ROOT / "data/event_scripts.s").read_text(encoding="utf-8", errors="replace")
    layouts = json.loads((ROOT / "data/layouts/layouts.json").read_text(encoding="utf-8"))
    by_id = {L["id"]: L for L in layouts.get("layouts", [])}
    hall = (ROOT / "data/maps/EasternAurelia_Hall/scripts.inc").read_text(encoding="utf-8", errors="replace")
    opponents = (ROOT / "include/constants/opponents.h").read_text(encoding="utf-8", errors="replace")
    party = (ROOT / "src/data/trainers.party").read_text(encoding="utf-8", errors="replace")
    sections = (ROOT / "src/data/region_map/region_map_sections.json").read_text(encoding="utf-8", errors="replace")
    heals = (ROOT / "src/data/heal_locations.json").read_text(encoding="utf-8", errors="replace")
    fall = (ROOT / "data/layouts/FallarborTown/map.bin").read_bytes()
    mirage = (ROOT / "data/layouts/MirageCity/map.bin").read_bytes()

    for folder, mapsec, layout, leader, badge, prefix in CITIES:
        required = [
            folder,
            f"{folder}_Gym",
            f"{folder}_PokemonCenter_1F",
            f"{folder}_PokemonCenter_2F",
            f"{folder}_Mart",
        ]
        for name in required:
            if name not in special:
                issues.append(f"map_groups SpecialArea missing {name}")
            if not (ROOT / "data/maps" / name / "map.json").exists():
                issues.append(f"missing map.json for {name}")
            if not (ROOT / "data/maps" / name / "scripts.inc").exists():
                issues.append(f"missing scripts.inc for {name}")
            if f'data/maps/{name}/scripts.inc' not in event_scripts:
                issues.append(f"event_scripts.s missing {name}")

        outdoor = json.loads((ROOT / "data/maps" / folder / "map.json").read_text(encoding="utf-8"))
        if outdoor.get("region_map_section") != mapsec:
            issues.append(f"{folder} must use {mapsec}")
        if outdoor.get("layout") != layout:
            issues.append(f"{folder} must use {layout}")

        gym = json.loads((ROOT / "data/maps" / f"{folder}_Gym" / "map.json").read_text(encoding="utf-8"))
        if gym.get("layout") != f"{layout}_GYM":
            issues.append(f"{folder}_Gym must use {layout}_GYM")

        for layout_id, lfolder in ((layout, folder), (f"{layout}_GYM", f"{folder}_Gym")):
            if layout_id not in by_id:
                issues.append(f"layouts.json missing {layout_id}")
            else:
                for rel in (f"data/layouts/{lfolder}/map.bin", f"data/layouts/{lfolder}/border.bin"):
                    if not (ROOT / rel).exists():
                        issues.append(f"missing {rel}")

        map_const = "MAP_" + "_".join(
            part.upper() for part in __import__("re").findall(r"[A-Z][a-z0-9]*", folder)
        )
        if f"warpsilent {map_const}" not in hall:
            issues.append(f"Hall missing warpsilent {map_const}")
        needle = {
            "CELIA": "TRAINER_GENESIS_CELIA",
            "NOCTIS": "TRAINER_GENESIS_NOCTIS",
            "DRAKE": "TRAINER_GENESIS_DRAKE_GYM",
            "LUNA": "TRAINER_GENESIS_LUNA",
            "MORRIGAN": "TRAINER_GENESIS_MORRIGAN",
            "COLLEAGUE": "TRAINER_GENESIS_COLLEAGUE",
            "MENTOR": "TRAINER_GENESIS_MENTOR",
        }[leader]
        if f"trainerbattle_no_intro {needle}" in hall:
            issues.append(f"Hall still battles {needle} at desk")

        gym_scripts = (ROOT / "data/maps" / f"{folder}_Gym" / "scripts.inc").read_text(encoding="utf-8", errors="replace")
        if badge not in gym_scripts:
            issues.append(f"{folder}_Gym missing {badge}")
        for letter in "ABC":
            tname = f"TRAINER_GENESIS_{prefix}_{letter}"
            if tname not in gym_scripts:
                issues.append(f"{folder}_Gym missing {tname}")
            if tname not in opponents:
                issues.append(f"opponents.h missing {tname}")
            if f"=== {tname} ===" not in party:
                issues.append(f"trainers.party missing {tname}")

        if f'"id": "{mapsec}"' not in sections:
            issues.append(f"region_map_sections.json missing {mapsec}")
        heal = "HEAL_LOCATION_" + map_const[4:]
        if heal not in heals:
            issues.append(f"heal_locations.json missing {heal}")

        city_bin = ROOT / "data/layouts" / folder / "map.bin"
        for x, y, expect, label in DOOR_CHECKS:
            got = cell(city_bin, 20, x, y)
            if got != expect:
                issues.append(f"{folder} door {label} ({x},{y}) {got:#x} != {expect:#x}")
        warps = {(w["x"], w["y"]) for w in outdoor.get("warp_events", [])}
        for x, y, _, label in DOOR_CHECKS:
            if (x, y) not in warps:
                issues.append(f"{folder} map.json missing warp at {label} ({x},{y})")
        raw = city_bin.read_bytes()
        if raw == fall:
            issues.append(f"{folder} map.bin identical to Fallarbor")
        if raw == mirage:
            issues.append(f"{folder} map.bin identical to Mirage")

    # Astral Tera + Summit story beat
    astral = (ROOT / "data/maps/AstralCity_Gym/scripts.inc").read_text(encoding="utf-8", errors="replace")
    if "FLAG_GENESIS_TERA_UNLOCKED" not in astral:
        issues.append("Astral gym must unlock Tera")
    summit = (ROOT / "data/maps/SummitCity_Gym/scripts.inc").read_text(encoding="utf-8", errors="replace")
    if "GENESIS_STORY_EASTERN_DONE" not in summit:
        issues.append("Summit gym must set GENESIS_STORY_EASTERN_DONE")

    # WT facility
    if "WorldTournament_Lobby" not in special:
        issues.append("map_groups missing WorldTournament_Lobby")
    if 'data/maps/WorldTournament_Lobby/scripts.inc' not in event_scripts:
        issues.append("event_scripts.s missing WorldTournament_Lobby")
    if "LAYOUT_WORLD_TOURNAMENT_LOBBY" not in by_id:
        issues.append("layouts.json missing LAYOUT_WORLD_TOURNAMENT_LOBBY")
    if not (ROOT / "data/layouts/WorldTournament_Lobby/map.bin").exists():
        issues.append("missing WorldTournament_Lobby map.bin")
    if '"id": "MAPSEC_WORLD_TOURNAMENT"' not in sections:
        issues.append("region_map_sections.json missing WORLD TOURNAMENT")
    tower = (ROOT / "data/maps/BattleFrontier_BattleTowerLobby/scripts.inc").read_text(encoding="utf-8", errors="replace")
    if "MAP_WORLD_TOURNAMENT_LOBBY" not in tower:
        issues.append("Tower lobby missing warp to WT facility")
    wt = (ROOT / "data/maps/WorldTournament_Lobby/scripts.inc").read_text(encoding="utf-8", errors="replace")
    for needle in ("TRAINER_GENESIS_WT_CHAMP", "FLAG_GENESIS_WT_CLEARED", "FLAG_SYS_GAME_CLEAR"):
        if needle not in wt:
            issues.append(f"WT lobby missing {needle}")

    save = (ROOT / "include/config/genesis.h").read_text(encoding="utf-8", errors="replace")
    import re

    m = re.search(r"#define\s+GENESIS_SAVE_VERSION\s+(\d+)", save)
    if not m or int(m.group(1)) < 6:
        issues.append("GENESIS_SAVE_VERSION should be >= 6 for eastern trainer expansion")

    if issues:
        print(f"EASTERN VALIDATION FAILED ({len(issues)}):")
        for issue in issues:
            print(f"  - {issue}")
        return 1

    print("EASTERN VALIDATION OK")
    for folder, *_ in CITIES:
        print(f"  OK {folder}")
    print("  OK WorldTournament_Lobby + Tower warp")
    print("  OK Hall desks warp to live cities 10-16")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
