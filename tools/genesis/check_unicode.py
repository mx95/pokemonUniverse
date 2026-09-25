#!/usr/bin/env python3
from pathlib import Path
files = [
    Path("data/text/birch_speech.inc"),
    Path("data/maps/LittlerootTown/scripts.inc"),
    Path("data/maps/OldaleTown/scripts.inc"),
    Path("data/maps/Route101/scripts.inc"),
]
allowed = set("éÉ“”…")
for p in files:
    t = p.read_text(encoding="utf-8")
    bad = [(i + 1, c, hex(ord(c))) for i, c in enumerate(t) if ord(c) > 127 and c not in allowed]
    print(p, "ok" if not bad else bad[:20])
