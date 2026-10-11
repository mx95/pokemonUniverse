#!/usr/bin/env python3
from pathlib import Path

root = Path(__file__).resolve().parents[2]
empty = []
for base in ("src", "data", "include"):
    for p in (root / base).rglob("*"):
        if not p.is_file():
            continue
        if p.suffix not in {".c", ".h", ".inc", ".s"}:
            continue
        if p.stat().st_size == 0:
            empty.append(p.relative_to(root).as_posix())
print(f"empty critical: {len(empty)}")
for e in empty:
    print(e)
