#!/usr/bin/env python3
"""GENESIS: Report missing/invalid Pokémon data references (Phase E starter).

Run from repo root:
  python3 tools/genesis/validate_pokedex.py

Exits non-zero when critical issues are found (for CI / release gates).
"""

from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def count_pattern(path: Path, pattern: str) -> int:
    text = path.read_text(encoding="utf-8", errors="replace")
    return len(re.findall(pattern, text))


def check_species_enabled() -> list[str]:
    issues: list[str] = []
    path = ROOT / "include" / "config" / "species_enabled.h"
    text = path.read_text(encoding="utf-8", errors="replace")
    for gen in range(1, 10):
        m = re.search(rf"#define P_GEN_{gen}_POKEMON\s+(\w+)", text)
        if not m or m.group(1) != "TRUE":
            issues.append(f"P_GEN_{gen}_POKEMON is not TRUE")
    for flag in (
        "P_MEGA_EVOLUTIONS",
        "P_GIGANTAMAX_FORMS",
        "P_REGIONAL_FORMS",
        "P_TERA_FORMS",
    ):
        m = re.search(rf"#define {flag}\s+(\w+)", text)
        if not m or m.group(1) != "TRUE":
            issues.append(f"{flag} is not TRUE")
    disabled = re.findall(r"#define P_FAMILY_\w+\s+FALSE", text)
    if disabled:
        issues.append(f"{len(disabled)} P_FAMILY_* explicitly FALSE")
    return issues


def main() -> int:
    issues: list[str] = []

    species_h = ROOT / "include" / "constants" / "species.h"
    if not species_h.exists():
        issues.append(f"missing {species_h}")
    else:
        text = species_h.read_text(encoding="utf-8", errors="replace")
        species_count = count_pattern(species_h, r"\bSPECIES_[A-Z0-9_]+\s*=")
        print(f"SPECIES_* enum entries: {species_count}")
        if species_count < 100:
            issues.append("species.h looks truncated")
        for name in ("SPECIES_AETHERNOX", "SPECIES_SOLARA", "SPECIES_GENESIS"):
            if name not in text:
                issues.append(f"missing {name}")

    issues.extend(check_species_enabled())
    if not any("P_GEN_" in i or "P_FAMILY_" in i or "P_MEGA" in i or "P_GIGA" in i or "P_REGIONAL" in i or "P_TERA" in i for i in issues):
        print("All P_GEN_1-9 and major form toggles are TRUE")

    species_info = ROOT / "src" / "data" / "pokemon" / "species_info.h"
    if not species_info.exists():
        issues.append("missing species_info.h")
    else:
        print(f"found {species_info}")

    genesis_legends = ROOT / "src" / "data" / "pokemon" / "species_info" / "genesis_legendaries.h"
    if not genesis_legends.exists():
        issues.append("missing genesis_legendaries.h")
    else:
        print(f"found {genesis_legends}")

    genesis_form = ROOT / "src" / "genesis_form.c"
    if not genesis_form.exists():
        issues.append("missing src/genesis_form.c")
    else:
        print(f"found {genesis_form}")

    if issues:
        print("VALIDATION FAILED:")
        for issue in issues:
            print(f"  - {issue}")
        return 1

    print("VALIDATION OK (basic checks)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
