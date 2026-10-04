#!/usr/bin/env python3
"""GENESIS: Assert presentation / QoL configs that define the new feel."""

from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

CHECKS: list[tuple[str, str, str]] = [
    # path, pattern that must match, description
    ("include/config/genesis.h", r"#define\s+GENESIS_PROJECT\s+TRUE", "GENESIS_PROJECT"),
    ("include/config/general.h", r"#define\s+EXPANSION_INTRO\s+FALSE", "skip pret splash"),
    ("include/config/pokemon.h", r"#define\s+P_GBA_STYLE_SPECIES_GFX\s+FALSE", "DS-style sprites"),
    ("include/config/pokemon.h", r"#define\s+P_SHOW_TERA_TYPE\s+GEN_9", "Tera on summary"),
    ("include/config/overworld.h", r"#define\s+OW_POPUP_GENERATION\s+GEN_5", "Gen5 map pop-ups"),
    ("include/config/overworld.h", r"#define\s+OW_FOLLOWERS_ENABLED\s+TRUE", "followers"),
    ("include/config/battle.h", r"#define\s+B_SHOW_TYPES\s+SHOW_TYPES_ALWAYS", "type indicators"),
    ("include/config/battle.h", r"#define\s+B_SHOW_EFFECTIVENESS\s+SHOW_EFFECTIVENESS_ALWAYS", "effectiveness"),
    ("include/config/battle.h", r"#define\s+B_NEW_TERRAIN_BACKGROUNDS\s+TRUE", "terrain BGs"),
    ("include/config/battle.h", r"#define\s+B_ENEMY_MON_SHADOW_STYLE\s+GEN_LATEST", "enemy shadows"),
]


def main() -> int:
    issues: list[str] = []
    for rel, pattern, desc in CHECKS:
        path = ROOT / rel
        if not path.exists():
            issues.append(f"missing {rel}")
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        if not re.search(pattern, text):
            issues.append(f"{rel}: failed check for {desc} ({pattern})")

    legends = ROOT / "src/data/pokemon/species_info/genesis_legendaries.h"
    text = legends.read_text(encoding="utf-8", errors="replace") if legends.exists() else ""
    for needle in ("gMonFrontPic_GiratinaAltered", "gMonFrontPic_Reshiram", "gMonFrontPic_Arceus"):
        if needle not in text:
            issues.append(f"legendaries missing stand-in gfx ref {needle}")

    if issues:
        print(f"CONFIG VALIDATION FAILED ({len(issues)}):")
        for issue in issues:
            print(f"  - {issue}")
        return 1

    print("CONFIG VALIDATION OK")
    for _, _, desc in CHECKS:
        print(f"  OK {desc}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
