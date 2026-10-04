#!/usr/bin/env python3
"""GENESIS: Fail if early-game player-facing text still uses Emerald branding."""

from __future__ import annotations

import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

EARLY_SCRIPT_FILES = [
    "data/maps/LittlerootTown/scripts.inc",
    "data/maps/LittlerootTown_BrendansHouse_1F/scripts.inc",
    "data/maps/LittlerootTown_MaysHouse_1F/scripts.inc",
    "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.inc",
    "data/maps/OldaleTown/scripts.inc",
    "data/maps/OldaleTown_Gym/scripts.inc",
    "data/maps/Route101/scripts.inc",
    "data/maps/Route102/scripts.inc",
    "data/maps/PetalburgCity/scripts.inc",
    "data/maps/PetalburgCity_Gym/scripts.inc",
    "data/maps/PetalburgWoods/scripts.inc",
    "data/text/birch_speech.inc",
    "data/text/pokedex_rating.inc",
]

# Ban only on .string / quoted dialogue lines.
BANNED = [
    re.compile(r"PROF\. BIRCH"),
    re.compile(r"\bHOENN\b"),
    re.compile(r"PETALBURG CITY"),
    re.compile(r"PETALBURG GYM"),
    re.compile(r"\bLITTLEROOT\b"),
    re.compile(r"\bOLDALE\b"),
    re.compile(r"^.*\.string.*\bMAY:\s"),
    re.compile(r"^.*\.string.*\bBRENDAN:\s"),
    re.compile(r"TEAM AQUA"),
]

GYM_SCRIPT_FILES = [
    "data/maps/OldaleTown_Gym/scripts.inc",
    "data/maps/PetalburgCity_Gym/scripts.inc",
]

GYM_BANNED = [
    re.compile(r"^.*\.string.*\bDAD:\s"),
    re.compile(r"^.*\.string.*\bNORMAN\b"),
    re.compile(r"^.*\.string.*\bROXANNE\b"),
    re.compile(r"BALANCE BADGE"),
]

REQUIRED_MAP_NAMES = {
    "MAPSEC_LITTLEROOT_TOWN": "VERDANT TOWN",
    "MAPSEC_OLDALE_TOWN": "LUMEN CITY",
    "MAPSEC_ROUTE_101": "ROUTE 1",
    "MAPSEC_ROUTE_102": "ROUTE 2",
    "MAPSEC_PETALBURG_CITY": "PORT AZURE",
    "MAPSEC_PETALBURG_WOODS": "LUMEN FOREST",
    "MAPSEC_DEWFORD_TOWN": "IRONRIDGE CITY",
    "MAPSEC_MAUVILLE_CITY": "CELESTIA CITY",
    "MAPSEC_LAVARIDGE_TOWN": "FROSTVEIL CITY",
    "MAPSEC_FORTREE_CITY": "SOLARIS CITY",
    "MAPSEC_MOSSDEEP_CITY": "STORMBREAK CITY",
    "MAPSEC_SOOTOPOLIS_CITY": "TITANIA CITY",
    "MAPSEC_EVER_GRANDE_CITY": "AURELIA SUMMIT",
}


def dialogue_lines(path: Path) -> list[tuple[int, str]]:
    out: list[tuple[int, str]] = []
    for i, line in enumerate(path.read_text(encoding="utf-8", errors="replace").splitlines(), 1):
        s = line.lstrip()
        if ".string" in line or s.startswith('"'):
            out.append((i, line))
    return out


def check_banned_strings() -> list[str]:
    issues: list[str] = []
    for rel in EARLY_SCRIPT_FILES:
        path = ROOT / rel
        if not path.exists():
            issues.append(f"missing {rel}")
            continue
        for lineno, line in dialogue_lines(path):
            for pat in BANNED:
                if pat.search(line):
                    issues.append(f"{rel}:{lineno}: banned branding -> {line.strip()[:100]}")
                    break
    for rel in GYM_SCRIPT_FILES:
        path = ROOT / rel
        if not path.exists():
            issues.append(f"missing {rel}")
            continue
        for lineno, line in dialogue_lines(path):
            for pat in GYM_BANNED:
                if pat.search(line):
                    issues.append(f"{rel}:{lineno}: gym branding -> {line.strip()[:100]}")
                    break
    return issues


def check_region_map() -> list[str]:
    issues: list[str] = []
    path = ROOT / "src/data/region_map/region_map_sections.json"
    data = json.loads(path.read_text(encoding="utf-8"))
    by_id = {entry["id"]: entry.get("name", "") for entry in data["map_sections"]}
    for mapsec, expected in REQUIRED_MAP_NAMES.items():
        actual = by_id.get(mapsec)
        if actual != expected:
            issues.append(f"region map {mapsec}: expected {expected!r}, got {actual!r}")
    return issues


def check_title_assets() -> list[str]:
    issues: list[str] = []
    version = ROOT / "graphics/title_screen/emerald_version.png"
    if not version.exists():
        issues.append("missing title version PNG")
    general = (ROOT / "include/config/general.h").read_text(encoding="utf-8", errors="replace")
    if not re.search(r"#define\s+EXPANSION_INTRO\s+FALSE", general):
        issues.append("EXPANSION_INTRO should be FALSE (skip pret splash)")
    title_c = (ROOT / "src/title_screen.c").read_text(encoding="utf-8", errors="replace")
    if "CreateCopyrightBanner(" in title_c and "omit Game Freak" not in title_c:
        # Call site should be gone
        if re.search(r"^\s*CreateCopyrightBanner\s*\(", title_c, re.M):
            issues.append("title screen still calls CreateCopyrightBanner")
    strings = (ROOT / "src/strings.c").read_text(encoding="utf-8", errors="replace")
    if 'gText_ExpandedPlaceholder_Emerald[] = _("EMERALD")' in strings:
        issues.append("version placeholder still says EMERALD")
    if 'gText_ExpandedPlaceholder_Emerald[] = _("GENESIS")' not in strings:
        issues.append("version placeholder missing GENESIS")
    return issues


def check_intro_skip() -> list[str]:
    issues: list[str] = []
    main_menu = (ROOT / "src/main_menu.c").read_text(encoding="utf-8", errors="replace")
    if "skip professor" not in main_menu.lower() and "GENESIS: prepare dialogue" not in main_menu:
        issues.append("main_menu.c missing Genesis professor-skip path")
    if "Task_NewGameBirchSpeech_StartPlayerFadeIn" not in main_menu:
        issues.append("main_menu.c missing jump to gender/name flow")
    return issues


def main() -> int:
    issues: list[str] = []
    issues.extend(check_banned_strings())
    issues.extend(check_region_map())
    issues.extend(check_title_assets())
    issues.extend(check_intro_skip())

    if issues:
        print(f"BRANDING VALIDATION FAILED ({len(issues)} issue(s)):")
        for issue in issues:
            print(f"  - {issue}")
        return 1

    print("BRANDING VALIDATION OK")
    print(f"  checked {len(EARLY_SCRIPT_FILES)} early-game script/text files")
    print(f"  region map aliases: {', '.join(REQUIRED_MAP_NAMES.values())}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
