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


def main() -> int:
    issues: list[str] = []

    species_h = ROOT / "include" / "constants" / "species.h"
    if not species_h.exists():
        issues.append(f"missing {species_h}")
    else:
        # Expansion 1.17+ uses enum Species { SPECIES_* = N, ... }
        species_count = count_pattern(species_h, r"\bSPECIES_[A-Z0-9_]+\s*=")
        print(f"SPECIES_* enum entries: {species_count}")
        if species_count < 100:
            issues.append("species.h looks truncated")

    species_info = ROOT / "src" / "data" / "pokemon" / "species_info.h"
    # Expansion may split species_info across includes
    if not species_info.exists():
        alt = list((ROOT / "src" / "data" / "pokemon").glob("**/species_info*.h"))
        if not alt:
            issues.append("no species_info headers found under src/data/pokemon")
        else:
            print(f"species_info headers: {len(alt)}")
    else:
        print(f"found {species_info}")

    # GENESIS Form table present when feature is compiled
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
