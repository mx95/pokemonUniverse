#!/usr/bin/env python3
"""GENESIS: Assert Mirage City live eastern map wiring."""

from __future__ import annotations

import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

REQUIRED_MAPS = [
    "MirageCity",
    "MirageCity_Gym",
    "MirageCity_PokemonCenter_1F",
    "MirageCity_PokemonCenter_2F",
    "MirageCity_Mart",
]


def main() -> int:
    issues: list[str] = []

    groups = json.loads((ROOT / "data/maps/map_groups.json").read_text(encoding="utf-8"))
    special = groups.get("gMapGroup_SpecialArea", [])
    for name in REQUIRED_MAPS:
        if name not in special:
            issues.append(f"map_groups.json SpecialArea missing {name}")
        map_json = ROOT / "data/maps" / name / "map.json"
        scripts = ROOT / "data/maps" / name / "scripts.inc"
        if not map_json.exists():
            issues.append(f"missing {map_json.relative_to(ROOT)}")
        if not scripts.exists():
            issues.append(f"missing {scripts.relative_to(ROOT)}")

    outdoor = json.loads((ROOT / "data/maps/MirageCity/map.json").read_text(encoding="utf-8"))
    if outdoor.get("region_map_section") != "MAPSEC_MIRAGE_CITY":
        issues.append("MirageCity map.json must use MAPSEC_MIRAGE_CITY")
    if outdoor.get("layout") != "LAYOUT_MIRAGE_CITY":
        issues.append("MirageCity must use dedicated LAYOUT_MIRAGE_CITY (Porymap-editable)")

    gym = json.loads((ROOT / "data/maps/MirageCity_Gym/map.json").read_text(encoding="utf-8"))
    if gym.get("layout") != "LAYOUT_MIRAGE_CITY_GYM":
        issues.append("MirageCity_Gym must use dedicated LAYOUT_MIRAGE_CITY_GYM")

    layouts = json.loads((ROOT / "data/layouts/layouts.json").read_text(encoding="utf-8"))
    by_id = {L["id"]: L for L in layouts.get("layouts", [])}
    for layout_id, folder in (
        ("LAYOUT_MIRAGE_CITY", "MirageCity"),
        ("LAYOUT_MIRAGE_CITY_GYM", "MirageCity_Gym"),
    ):
        if layout_id not in by_id:
            issues.append(f"layouts.json missing {layout_id}")
            continue
        for rel in (f"data/layouts/{folder}/map.bin", f"data/layouts/{folder}/border.bin"):
            if not (ROOT / rel).exists():
                issues.append(f"missing Porymap layout file {rel}")
        entry = by_id[layout_id]
        if entry.get("blockdata_filepath") != f"data/layouts/{folder}/map.bin":
            issues.append(f"{layout_id} blockdata_filepath must point at data/layouts/{folder}/map.bin")

    event_scripts = (ROOT / "data/event_scripts.s").read_text(encoding="utf-8", errors="replace")
    for name in REQUIRED_MAPS:
        needle = f'data/maps/{name}/scripts.inc'
        if needle not in event_scripts:
            issues.append(f"event_scripts.s missing include for {name}")

    hall = (ROOT / "data/maps/EasternAurelia_Hall/scripts.inc").read_text(encoding="utf-8", errors="replace")
    for needle in ("MAP_MIRAGE_CITY", "warpsilent MAP_MIRAGE_CITY"):
        if needle not in hall:
            issues.append(f"Eastern Hall missing {needle}")

    gym_scripts = (ROOT / "data/maps/MirageCity_Gym/scripts.inc").read_text(encoding="utf-8", errors="replace")
    for needle in ("TRAINER_GENESIS_IRIS", "FLAG_GENESIS_BADGE_09_GET", "TRAINER_GENESIS_MIRAGE_A"):
        if needle not in gym_scripts:
            issues.append(f"Mirage gym scripts missing {needle}")

    opponents = (ROOT / "include/constants/opponents.h").read_text(encoding="utf-8", errors="replace")
    for needle in ("TRAINER_GENESIS_MIRAGE_A", "TRAINER_GENESIS_MIRAGE_B", "TRAINER_GENESIS_MIRAGE_C"):
        if needle not in opponents:
            issues.append(f"opponents.h missing {needle}")

    party = (ROOT / "src/data/trainers.party").read_text(encoding="utf-8", errors="replace")
    for needle in ("TRAINER_GENESIS_MIRAGE_A", "TRAINER_GENESIS_MIRAGE_B", "TRAINER_GENESIS_MIRAGE_C"):
        if f"=== {needle} ===" not in party:
            issues.append(f"trainers.party missing {needle}")

    sections = (ROOT / "src/data/region_map/region_map_sections.json").read_text(encoding="utf-8", errors="replace")
    if '"id": "MAPSEC_MIRAGE_CITY"' not in sections or '"name": "MIRAGE CITY"' not in sections:
        issues.append("region_map_sections.json missing MIRAGE CITY")

    heals = (ROOT / "src/data/heal_locations.json").read_text(encoding="utf-8", errors="replace")
    if "HEAL_LOCATION_MIRAGE_CITY" not in heals:
        issues.append("heal_locations.json missing HEAL_LOCATION_MIRAGE_CITY")

    if issues:
        print(f"MIRAGE VALIDATION FAILED ({len(issues)}):")
        for issue in issues:
            print(f"  - {issue}")
        return 1

    print("MIRAGE VALIDATION OK")
    for name in REQUIRED_MAPS:
        print(f"  OK {name}")
    print("  OK Hall warp + Iris gym badge 9")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
