#!/usr/bin/env python3
"""Pitch-shift stand-in legend cries into unique Genesis cry WAVs (no ffmpeg)."""
from __future__ import annotations

import struct
import wave
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CRY = ROOT / "sound/direct_sound_samples/cries"

JOBS = [
    ("giratina", "aethernox", 0.82),
    ("reshiram", "solara", 1.18),
    ("arceus", "genesis", 0.94),
]


def pitch_shift(src: Path, dst: Path, rate_mult: float) -> None:
    with wave.open(str(src), "rb") as w:
        nch, sw, rate, nframes, comptype, _ = w.getparams()
        raw = w.readframes(nframes)
    if nch != 1 or comptype != "NONE":
        raise SystemExit(f"expected mono PCM: {src}")
    if sw == 1:
        samples = list(raw)
        pack = lambda seq: bytes(max(0, min(255, int(x))) for x in seq)
    elif sw == 2:
        samples = list(struct.unpack("<" + "h" * (len(raw) // 2), raw))
        pack = lambda seq: struct.pack("<" + "h" * len(seq), *[int(x) for x in seq])
    else:
        raise SystemExit(f"unsupported sample width {sw}: {src}")

    new_len = max(1, int(len(samples) / rate_mult))
    out = []
    for i in range(new_len):
        pos = i * rate_mult
        i0 = int(pos)
        i1 = min(i0 + 1, len(samples) - 1)
        frac = pos - i0
        out.append(samples[i0] * (1 - frac) + samples[i1] * frac)
    data = pack(out)
    with wave.open(str(dst), "wb") as w:
        w.setnchannels(1)
        w.setsampwidth(sw)
        w.setframerate(rate)
        w.writeframes(data)
    print(f"Wrote {dst.relative_to(ROOT)} ({len(out)} samples, x{rate_mult}, {sw*8}-bit)")


def main() -> int:
    for src_stem, dst_stem, mult in JOBS:
        src = CRY / f"{src_stem}.wav"
        dst = CRY / f"{dst_stem}.wav"
        if not src.exists():
            raise SystemExit(f"missing {src}")
        pitch_shift(src, dst, mult)
        bin_path = CRY / f"{dst_stem}.bin"
        if bin_path.exists():
            bin_path.unlink()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
