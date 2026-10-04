#!/usr/bin/env python3
"""GENESIS: Validate pokemonGenesis.gba header / size after a build."""

from __future__ import annotations

import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
ROM_CANDIDATES = [
    ROOT / "pokemonGenesis.gba",
    ROOT / "pokemonGenesis_new.gba",
]

EXPECTED_TITLE = b"POKEMON GENE"  # 12 chars, space-padded in header
EXPECTED_CODE = b"BPEE"
MIN_SIZE = 8 * 1024 * 1024
EXPECTED_PADDED = 32 * 1024 * 1024


def read_header(path: Path) -> dict:
    data = path.read_bytes()
    # GBA cartridge header @ 0xA0
    title = data[0xA0:0xAC]
    code = data[0xAC:0xB0]
    maker = data[0xB0:0xB2]
    return {
        "size": len(data),
        "title": title,
        "code": code,
        "maker": maker,
        "entry": data[0:4],
    }


def main() -> int:
    rom = next((p for p in ROM_CANDIDATES if p.exists()), None)
    if rom is None:
        print("ROM VALIDATION FAILED: no pokemonGenesis.gba found — run `make` first")
        return 1

    hdr = read_header(rom)
    issues: list[str] = []

    if hdr["size"] < MIN_SIZE:
        issues.append(f"ROM too small ({hdr['size']} bytes)")
    if hdr["title"] != EXPECTED_TITLE:
        issues.append(f"title {hdr['title']!r} != {EXPECTED_TITLE!r}")
    if hdr["code"] != EXPECTED_CODE:
        issues.append(f"game code {hdr['code']!r} != {EXPECTED_CODE!r}")
    # Nintendo logo / entry point sanity: first word is ARM branch
    entry = struct.unpack("<I", hdr["entry"])[0]
    if (entry & 0xFF000000) != 0xEA000000 and (entry & 0xFF000000) != 0x85000000:
        # Emerald uses 0xEA...... branch; some dumps start differently — soft check
        if entry == 0:
            issues.append("entry point is zero")

    print(f"ROM: {rom.name}")
    print(f"  size:  {hdr['size']} bytes", end="")
    if hdr["size"] == EXPECTED_PADDED:
        print(" (32 MiB padded)")
    else:
        print()
    print(f"  title: {hdr['title']!r}")
    print(f"  code:  {hdr['code']!r}")

    if issues:
        print("ROM VALIDATION FAILED:")
        for issue in issues:
            print(f"  - {issue}")
        return 1

    print("ROM VALIDATION OK")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
