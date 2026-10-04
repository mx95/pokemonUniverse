#!/usr/bin/env python3
"""GENESIS: Rewrite player-facing early-game Emerald strings to Aurelia branding."""

from __future__ import annotations

from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

FILES = [
    "data/maps/LittlerootTown/scripts.inc",
    "data/maps/LittlerootTown_BrendansHouse_1F/scripts.inc",
    "data/maps/LittlerootTown_MaysHouse_1F/scripts.inc",
    "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.inc",
    "data/maps/PetalburgCity/scripts.inc",
    "data/maps/OldaleTown/scripts.inc",
    "data/maps/Route101/scripts.inc",
    "data/maps/Route102/scripts.inc",
    "data/text/pokedex_rating.inc",
    "data/text/birch_speech.inc",
]

REPLACEMENTS = [
    ("PROF. BIRCH", "PROF. AURELIA"),
    ("PETALBURG CITY", "PORT AZURE"),
    ("PETALBURG GYM", "PORT AZURE GYM"),
    ("the HOENN region", "the AURELIA region"),
    ("the HOENN POKéDEX", "the AURELIA POKéDEX"),
    ("of HOENN", "of AURELIA"),
    ("in HOENN", "in AURELIA"),
    ("over HOENN", "over AURELIA"),
    ("HOENN locales", "AURELIA locales"),
    ("HOENN region", "AURELIA region"),
    ("HOENN POKéDEX", "AURELIA POKéDEX"),
    ("the HOENN", "the AURELIA"),
    ("MAY: ", "KAI: "),
    ("BRENDAN: ", "KAI: "),
    ("HOENN", "AURELIA"),  # leftover dialogue mentions
]


def is_dialogue_line(line: str) -> bool:
    s = line.lstrip()
    return ".string" in line or s.startswith('"')


def main() -> int:
    total = 0
    for rel in FILES:
        path = ROOT / rel
        if not path.exists():
            print(f"MISSING {rel}")
            continue
        lines = path.read_text(encoding="utf-8", errors="replace").splitlines(True)
        out: list[str] = []
        changed = 0
        for line in lines:
            new = line
            if is_dialogue_line(line):
                for old, repl in REPLACEMENTS:
                    if old in new:
                        changed += new.count(old)
                        new = new.replace(old, repl)
            out.append(new)
        if changed:
            path.write_text("".join(out), encoding="utf-8", newline="")
            print(f"{rel}: {changed} replacements")
            total += changed
        else:
            print(f"{rel}: no changes")
    print(f"TOTAL {total}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
