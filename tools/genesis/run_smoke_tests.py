#!/usr/bin/env python3
"""GENESIS: Run static smoke tests that confirm the project/ROM is healthy.

Usage (from repo root):
  python3 tools/genesis/run_smoke_tests.py
  python3 tools/genesis/run_smoke_tests.py --with-rom-tests   # also runs a filtered `make check`

Exit code is non-zero if any validator fails.
"""

from __future__ import annotations

import argparse
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

STATIC_VALIDATORS = [
    "validate_pokedex.py",
    "validate_branding.py",
    "validate_config.py",
    "validate_rom.py",
]


def run_python(script: str) -> int:
    path = ROOT / "tools" / "genesis" / script
    print(f"\n=== {script} ===")
    proc = subprocess.run([sys.executable, str(path)], cwd=ROOT)
    return proc.returncode


def run_make_check_subset() -> int:
    print("\n=== make check (smoke subset) ===")
    # Small Expansion battle/system filters — proves the test ELF + runner work.
    # Filter matches test *names* (e.g. "Spikes …"), not filenames.
    filter_name = "Spikes"
    cmd = ["make", "check", "-j8", f"TESTS={filter_name}"]
    try:
        proc = subprocess.run(cmd, cwd=ROOT)
        return proc.returncode
    except FileNotFoundError:
        wsl_cmd = (
            "cd /mnt/c/Users/skapn/OneDrive/Desktop/Projects/PokemonUniverse/pokemonUniverse "
            f"&& make check -j8 TESTS={filter_name}"
        )
        proc = subprocess.run(["wsl", "-d", "Ubuntu", "-u", "root", "-e", "bash", "-lc", wsl_cmd])
        return proc.returncode


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--with-rom-tests",
        action="store_true",
        help="Also run a filtered Expansion `make check` (requires WSL toolchain)",
    )
    parser.add_argument(
        "--skip-rom",
        action="store_true",
        help="Skip validate_rom.py (useful before the first build)",
    )
    args = parser.parse_args()

    failed: list[str] = []
    for script in STATIC_VALIDATORS:
        if args.skip_rom and script == "validate_rom.py":
            print(f"\n=== {script} (skipped) ===")
            continue
        if run_python(script) != 0:
            failed.append(script)

    if args.with_rom_tests:
        if run_make_check_subset() != 0:
            failed.append("make check TESTS=Spikes")

    print("\n========== SUMMARY ==========")
    if failed:
        print("SMOKE TESTS FAILED:")
        for name in failed:
            print(f"  - {name}")
        return 1

    print("SMOKE TESTS PASSED")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
