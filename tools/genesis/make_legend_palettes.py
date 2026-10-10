#!/usr/bin/env python3
"""Generate Genesis legendary recolor palettes from DS stand-in sheets."""
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def read_jasc(path: Path) -> list[tuple[int, int, int]]:
    lines = path.read_text(encoding="utf-8").strip().splitlines()
    assert lines[0] == "JASC-PAL"
    n = int(lines[2])
    colors = []
    for line in lines[3 : 3 + n]:
        r, g, b = map(int, line.split())
        colors.append((r, g, b))
    return colors


def write_jasc(path: Path, colors: list[tuple[int, int, int]]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    body = ["JASC-PAL", "0100", str(len(colors))]
    body.extend(f"{r} {g} {b}" for r, g, b in colors)
    path.write_text("\n".join(body) + "\n", encoding="utf-8")


def clamp(v: int) -> int:
    return max(0, min(255, v))


def shift_aethernox(c: tuple[int, int, int]) -> tuple[int, int, int]:
    """Chaos: push reds toward violet, golds toward cyan-teal."""
    r, g, b = c
    if r + g + b < 24:
        return c
    # Strong reds / pinks -> violet
    if r > g + 20 and r > b:
        return (clamp(int(r * 0.55 + 40)), clamp(int(g * 0.35 + 20)), clamp(int(b * 0.2 + r * 0.55)))
    # Golds / yellows -> teal
    if r > 150 and g > 100 and b < 80:
        return (clamp(int(g * 0.25)), clamp(int(r * 0.55 + 40)), clamp(int(r * 0.5 + 60)))
    # Greys -> cool slate
    if abs(r - g) < 20 and abs(g - b) < 20:
        return (clamp(r - 10), clamp(g), clamp(b + 24))
    return (clamp(int(r * 0.7)), clamp(int(g * 0.55 + 30)), clamp(int(b * 0.9 + 40)))


def shift_solara(c: tuple[int, int, int]) -> tuple[int, int, int]:
    """Creation: warmer gold dawn, keep whites, blue ice -> amber."""
    r, g, b = c
    if r + g + b < 24:
        return c
    # Cool blues -> amber gold
    if b > r + 15 and b > g:
        return (clamp(int(b * 0.85)), clamp(int(g * 0.55 + b * 0.25)), clamp(int(r * 0.2)))
    # Already warm reds stay brighter
    if r > 180 and g > 40:
        return (255, clamp(g + 20), clamp(b + 10))
    if r > 200 and g > 200 and b > 200:
        return (255, 248, 220)
    return (clamp(r + 16), clamp(g + 8), clamp(int(b * 0.85)))


def shift_genesis(c: tuple[int, int, int]) -> tuple[int, int, int]:
    """Potential: aurora teal / soft gold whites."""
    r, g, b = c
    if r + g + b < 24:
        return c
    # Greens (Arceus accents) -> aurora teal
    if g > r + 30 and g > b:
        return (clamp(int(g * 0.15)), clamp(int(g * 0.85)), clamp(int(g * 0.75 + 40)))
    # Yellow metal -> soft gold
    if r > 150 and g > 120 and b < 100:
        return (clamp(r), clamp(g + 10), clamp(b + 40))
    # Neutrals -> cool white-teal
    if abs(r - g) < 25 and abs(g - b) < 25:
        return (clamp(r - 8), clamp(g + 12), clamp(b + 20))
    return (clamp(int(r * 0.85 + 20)), clamp(int(g * 0.9 + 30)), clamp(int(b * 0.95 + 40)))


def convert(src: Path, dst: Path, fn) -> None:
    write_jasc(dst, [fn(c) for c in read_jasc(src)])
    print("wrote", dst.relative_to(ROOT))


def main() -> None:
    pairs = [
        ("graphics/pokemon/giratina/origin", "graphics/pokemon/aethernox", shift_aethernox),
        ("graphics/pokemon/reshiram", "graphics/pokemon/solara", shift_solara),
        ("graphics/pokemon/arceus", "graphics/pokemon/genesis", shift_genesis),
    ]
    names = ("normal.pal", "shiny.pal", "overworld_normal.pal", "overworld_shiny.pal")
    for src_dir, dst_dir, fn in pairs:
        for name in names:
            src = ROOT / src_dir / name
            if not src.exists() and name.startswith("overworld"):
                continue
            if not src.exists():
                print("missing", src)
                continue
            convert(src, ROOT / dst_dir / name, fn)


if __name__ == "__main__":
    main()
