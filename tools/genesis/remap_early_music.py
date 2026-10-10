#!/usr/bin/env python3
"""One-shot remap of early Aurelia stand-in maps away from Emerald default BGM."""
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[2]

REPLACEMENTS = {
    "data/maps/LittlerootTown/map.json": ("MUS_ROUTE101", "MUS_RG_PALLET"),
    "data/maps/LittlerootTown_BrendansHouse_1F/map.json": ("MUS_LITTLEROOT", "MUS_RG_PALLET"),
    "data/maps/LittlerootTown_BrendansHouse_2F/map.json": ("MUS_LITTLEROOT", "MUS_RG_PALLET"),
    "data/maps/LittlerootTown_MaysHouse_1F/map.json": ("MUS_LITTLEROOT", "MUS_RG_PALLET"),
    "data/maps/LittlerootTown_MaysHouse_2F/map.json": ("MUS_LITTLEROOT", "MUS_RG_PALLET"),
    "data/maps/LittlerootTown_ProfessorBirchsLab/map.json": ("MUS_BIRCH_LAB", "MUS_RG_OAK_LAB"),
    "data/maps/Route101/map.json": ("MUS_ROUTE101", "MUS_RG_ROUTE1"),
    "data/maps/Route102/map.json": ("MUS_ROUTE101", "MUS_RG_ROUTE3"),
    "data/maps/Route103/map.json": ("MUS_ROUTE101", "MUS_ROUTE104"),
    "data/maps/OldaleTown/map.json": ("MUS_OLDALE", "MUS_VERDANTURF"),
    "data/maps/OldaleTown_House1/map.json": ("MUS_OLDALE", "MUS_VERDANTURF"),
    "data/maps/OldaleTown_House2/map.json": ("MUS_OLDALE", "MUS_VERDANTURF"),
    "data/maps/PetalburgCity/map.json": ("MUS_PETALBURG", "MUS_RG_VERMILLION"),
    "data/maps/PetalburgCity_House1/map.json": ("MUS_PETALBURG", "MUS_RG_VERMILLION"),
    "data/maps/PetalburgCity_House2/map.json": ("MUS_PETALBURG", "MUS_RG_VERMILLION"),
    "data/maps/PetalburgCity_WallysHouse/map.json": ("MUS_PETALBURG", "MUS_RG_VERMILLION"),
    "data/maps/PetalburgWoods/map.json": ("MUS_PETALBURG_WOODS", "MUS_RG_VIRIDIAN_FOREST"),
}

FORCE_SET = {
    "data/maps/EasternAurelia_Hall/map.json": "MUS_B_TOWER_RS",
    "data/maps/Genesis_LegendSanctum/map.json": "MUS_RG_LAVENDER",
    "data/maps/Genesis_WorldTournament/map.json": "MUS_RG_VICTORY_ROAD",
}


def main() -> None:
    for rel, pair in REPLACEMENTS.items():
        path = ROOT / rel
        if not path.exists():
            print("missing", rel)
            continue
        text = path.read_text(encoding="utf-8")
        old, new = pair
        needle = f'"music": "{old}"'
        if needle not in text:
            m = re.search(r'"music": "([^"]+)"', text)
            print("skip", rel, "has", m.group(1) if m else "?")
            continue
        path.write_text(text.replace(needle, f'"music": "{new}"', 1), encoding="utf-8")
        print("ok", rel, old, "->", new)

    for rel, new in FORCE_SET.items():
        path = ROOT / rel
        if not path.exists():
            print("missing", rel)
            continue
        text = path.read_text(encoding="utf-8")
        text2, n = re.subn(r'"music": "[^"]+"', f'"music": "{new}"', text, count=1)
        path.write_text(text2, encoding="utf-8")
        print("set", rel, "->", new, f"(subs={n})")


if __name__ == "__main__":
    main()
