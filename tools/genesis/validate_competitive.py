#!/usr/bin/env python3
"""GENESIS: Assert competitive prep desk + WT facility polish are wired."""

from __future__ import annotations

import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

CHECKS: list[tuple[str, list[str], str]] = [
    (
        "data/scripts/genesis_competitive.inc",
        [
            "Genesis_EventScript_CompetitiveDesk",
            "canhypertrain",
            "hypertrain",
            "ITEM_BOTTLE_CAP",
            "ITEM_GOLD_BOTTLE_CAP",
            "Genesis_Pokemart_Competitive",
            "FLAG_SYS_GAME_CLEAR",
        ],
        "competitive desk script",
    ),
    (
        "data/maps/OldaleTown_PokemonCenter_1F/scripts.inc",
        ["Genesis_EventScript_CompetitiveDesk"],
        "Lumen Center Gentleman wires desk",
    ),
    (
        "data/event_scripts.s",
        ['data/scripts/genesis_competitive.inc'],
        "event_scripts includes competitive",
    ),
    (
        "include/config/genesis.h",
        ["GENESIS_ENABLE_COMPETITIVE_SERVICES", "TRUE"],
        "competitive services flag",
    ),
    (
        "data/maps/WorldTournament_Lobby/scripts.inc",
        [
            "ASTRA returns for a rematch",
            "RematchWallace",
            "Genesis_GetWTRuleIndex",
            "GiveFrontierBattlePoints",
            "Rule--Dawn Bracket",
        ],
        "WT facility 4-round + day rematch polish",
    ),
    (
        "data/maps/BattleFrontier_BattleTowerLobby/scripts.inc",
        ["MAP_WORLD_TOURNAMENT_LOBBY"],
        "Tower boy warps to WT facility",
    ),
    (
        "src/genesis_story.c",
        ["% 4"],
        "WT rematch day rotation is 4-way",
    ),
    (
        "data/maps/Genesis_Laboratory/map.json",
        ["MAP_GENESIS_LABORATORY", "Genesis_Laboratory_EventScript_Director"],
        "Genesis Laboratory stub map",
    ),
    (
        "data/maps/EasternAurelia_Hall/scripts.inc",
        ["MAP_GENESIS_LABORATORY", "MAP_WORLD_TOURNAMENT_LOBBY"],
        "Hall seeks Lab + clerk WT warp",
    ),
]


def main() -> int:
    issues: list[str] = []
    for rel, needles, desc in CHECKS:
        path = ROOT / rel
        if not path.exists():
            issues.append(f"missing {rel} ({desc})")
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        for needle in needles:
            if needle not in text:
                issues.append(f"{rel}: missing {needle!r} ({desc})")

    if issues:
        print(f"COMPETITIVE VALIDATION FAILED ({len(issues)}):")
        for issue in issues:
            print(f"  - {issue}")
        return 1

    print("COMPETITIVE VALIDATION OK")
    for _, _, desc in CHECKS:
        print(f"  OK {desc}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
