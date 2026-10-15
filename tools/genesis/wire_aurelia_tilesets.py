#!/usr/bin/env python3
"""Wire Aurelia secondary tilesets into graphics/headers/metatiles/layouts."""
from __future__ import annotations

import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

# (folder, CamelName, num_tiles or None, parent Camel for anim callback, layout id)
PACKS = [
    ("ironridge", "Ironridge", 503, "Dewford", "LAYOUT_DEWFORD_TOWN"),
    ("celestia", "Celestia", 503, "Mauville", "LAYOUT_MAUVILLE_CITY"),
    ("frostveil", "Frostveil", 450, "Lavaridge", "LAYOUT_LAVARIDGE_TOWN"),
    ("solaris", "Solaris", 493, "Fortree", "LAYOUT_FORTREE_CITY"),
    ("stormbreak", "Stormbreak", None, "Mossdeep", "LAYOUT_MOSSDEEP_CITY"),
    ("titania", "Titania", 328, "Sootopolis", "LAYOUT_SOOTOPOLIS_CITY"),
    ("mirage_city", "MirageCity", 159, "Petalburg", None),  # layout via map.json later
    ("genesis_city", "GenesisCityTiles", 159, "Petalburg", None),
]

# Map weather updates: map.json path relative → weather
WEATHER = {
    "data/maps/DewfordTown/map.json": "WEATHER_SHADE",
    "data/maps/MauvilleCity/map.json": "WEATHER_SUNNY_CLOUDS",
    "data/maps/LavaridgeTown/map.json": "WEATHER_SHADE",
    "data/maps/FortreeCity/map.json": "WEATHER_DROUGHT",
    "data/maps/MossdeepCity/map.json": "WEATHER_RAIN",
    "data/maps/SootopolisCity/map.json": "WEATHER_FOG_HORIZONTAL",
    "data/maps/MirageCity/map.json": "WEATHER_DROUGHT",  # keep
}


def pal_block(folder: str) -> str:
    lines = [f'    INCGFX_U16("data/tilesets/secondary/{folder}/palettes/{i:02d}.pal", ".gbapal"),' for i in range(16)]
    return "\n".join(lines)


def tiles_line(folder: str, camel: str, num_tiles) -> str:
    if num_tiles is None:
        return f'const u32 gTilesetTiles_{camel}[] = INCGFX_U32("data/tilesets/secondary/{folder}/tiles.png", ".4bpp.fastSmol");'
    return (
        f'const u32 gTilesetTiles_{camel}[] = INCGFX_U32("data/tilesets/secondary/{folder}/tiles.png", '
        f'".4bpp.fastSmol", "-num_tiles {num_tiles} -Wnum_tiles");'
    )


def ensure_graphics() -> None:
    path = ROOT / "src/data/tilesets/graphics.h"
    text = path.read_text(encoding="utf-8")
    marker = "// GENESIS: Port Azure"
    # insert after Port Azure palettes block end — find port_azure 15.pal closing
    anchor = 'INCGFX_U16("data/tilesets/secondary/port_azure/palettes/15.pal", ".gbapal"),\n};\n'
    if "gTilesetTiles_Ironridge" in text:
        print("graphics.h already wired")
        return
    chunks = []
    for folder, camel, num, _parent, _layout in PACKS:
        chunks.append(
            f"\n// GENESIS: {camel} secondary tileset\n"
            f"{tiles_line(folder, camel, num)}\n\n"
            f"const u16 gTilesetPalettes_{camel}[][16] =\n{{\n{pal_block(folder)}\n}};\n"
        )
    insert = "".join(chunks)
    if anchor not in text:
        raise SystemExit("port_azure anchor missing in graphics.h")
    path.write_text(text.replace(anchor, anchor + insert, 1), encoding="utf-8", newline="\n")
    print("graphics.h wired")


def ensure_metatiles() -> None:
    path = ROOT / "src/data/tilesets/metatiles.h"
    text = path.read_text(encoding="utf-8")
    if "gMetatiles_Ironridge" in text:
        print("metatiles.h already wired")
        return
    anchor = (
        'const u16 gMetatileAttributes_PortAzure[] = INCBIN_U16("data/tilesets/secondary/port_azure/metatile_attributes.bin");\n'
    )
    lines = []
    for folder, camel, *_ in PACKS:
        lines.append(f'const u16 gMetatiles_{camel}[] = INCBIN_U16("data/tilesets/secondary/{folder}/metatiles.bin");')
        lines.append(
            f'const u16 gMetatileAttributes_{camel}[] = INCBIN_U16("data/tilesets/secondary/{folder}/metatile_attributes.bin");'
        )
    if anchor not in text:
        raise SystemExit("port_azure metatiles anchor missing")
    path.write_text(text.replace(anchor, anchor + "\n".join(lines) + "\n", 1), encoding="utf-8", newline="\n")
    print("metatiles.h wired")


def ensure_headers() -> None:
    path = ROOT / "src/data/tilesets/headers.h"
    text = path.read_text(encoding="utf-8")
    if "gTileset_Ironridge" in text:
        print("headers.h already wired")
        return
    anchor = "const struct Tileset gTileset_PortAzure =\n{\n    .isCompressed = TRUE,\n    .isSecondary = TRUE,\n    .tiles = gTilesetTiles_PortAzure,\n    .palettes = gTilesetPalettes_PortAzure,\n    .metatiles = gMetatiles_PortAzure,\n    .metatileAttributes = gMetatileAttributes_PortAzure,\n    .callback = InitTilesetAnim_Petalburg,\n};\n"
    blocks = []
    for folder, camel, _n, parent, _l in PACKS:
        blocks.append(
            f"\nconst struct Tileset gTileset_{camel} =\n{{\n"
            f"    .isCompressed = TRUE,\n"
            f"    .isSecondary = TRUE,\n"
            f"    .tiles = gTilesetTiles_{camel},\n"
            f"    .palettes = gTilesetPalettes_{camel},\n"
            f"    .metatiles = gMetatiles_{camel},\n"
            f"    .metatileAttributes = gMetatileAttributes_{camel},\n"
            f"    .callback = InitTilesetAnim_{parent},\n"
            f"}};\n"
        )
    if anchor not in text:
        raise SystemExit("PortAzure header anchor missing")
    path.write_text(text.replace(anchor, anchor + "".join(blocks), 1), encoding="utf-8", newline="\n")
    print("headers.h wired")


def ensure_tilesets_h() -> None:
    path = ROOT / "include/tilesets.h"
    text = path.read_text(encoding="utf-8")
    if "gTileset_Ironridge" in text:
        print("tilesets.h already wired")
        return
    anchor = "extern const struct Tileset gTileset_PortAzure;\n"
    extras = "".join(f"extern const struct Tileset gTileset_{camel};\n" for _, camel, *_ in PACKS)
    path.write_text(text.replace(anchor, anchor + extras, 1), encoding="utf-8", newline="\n")
    print("tilesets.h wired")


def ensure_layouts() -> None:
    path = ROOT / "data/layouts/layouts.json"
    data = json.loads(path.read_text(encoding="utf-8"))
    mapping = {
        "LAYOUT_DEWFORD_TOWN": "gTileset_Ironridge",
        "LAYOUT_MAUVILLE_CITY": "gTileset_Celestia",
        "LAYOUT_LAVARIDGE_TOWN": "gTileset_Frostveil",
        "LAYOUT_FORTREE_CITY": "gTileset_Solaris",
        "LAYOUT_MOSSDEEP_CITY": "gTileset_Stormbreak",
        "LAYOUT_SOOTOPOLIS_CITY": "gTileset_Titania",
    }
    # Also clone layouts for Mirage/Genesis if they use Oldale/Petalburg — change map.json layout field instead.
    changed = 0
    for layout in data["layouts"]:
        lid = layout.get("id")
        if lid in mapping and layout.get("secondary_tileset") != mapping[lid]:
            layout["secondary_tileset"] = mapping[lid]
            changed += 1
    path.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8", newline="\n")
    print(f"layouts.json updated ({changed})")


def ensure_weather() -> None:
    for rel, weather in WEATHER.items():
        path = ROOT / rel
        if not path.exists():
            continue
        data = json.loads(path.read_text(encoding="utf-8"))
        if data.get("weather") != weather:
            data["weather"] = weather
            path.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8", newline="\n")
            print(f"weather {rel} -> {weather}")


def ensure_eastern_map_tilesets() -> None:
    """Point Mirage/Genesis outdoor maps at dedicated tileset via layout clones in layouts.json."""
    layouts_path = ROOT / "data/layouts/layouts.json"
    data = json.loads(layouts_path.read_text(encoding="utf-8"))
    by_id = {l["id"]: l for l in data["layouts"]}

    def clone_layout(src_id: str, new_id: str, new_name: str, tileset: str, border: str, block: str) -> None:
        if new_id in by_id:
            by_id[new_id]["secondary_tileset"] = tileset
            return
        src = by_id[src_id]
        clone = dict(src)
        clone["id"] = new_id
        clone["name"] = new_name
        clone["secondary_tileset"] = tileset
        # reuse same bin paths (geometry clone)
        data["layouts"].append(clone)
        by_id[new_id] = clone

    clone_layout(
        "LAYOUT_OLDALE_TOWN",
        "LAYOUT_MIRAGE_CITY",
        "MirageCity_Layout",
        "gTileset_MirageCity",
        by_id["LAYOUT_OLDALE_TOWN"]["border_filepath"],
        by_id["LAYOUT_OLDALE_TOWN"]["blockdata_filepath"],
    )
    clone_layout(
        "LAYOUT_PETALBURG_CITY",
        "LAYOUT_GENESIS_CITY",
        "GenesisCity_Layout",
        "gTileset_GenesisCityTiles",
        by_id["LAYOUT_PETALBURG_CITY"]["border_filepath"],
        by_id["LAYOUT_PETALBURG_CITY"]["blockdata_filepath"],
    )
    layouts_path.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8", newline="\n")

    for map_rel, layout_id in (
        ("data/maps/MirageCity/map.json", "LAYOUT_MIRAGE_CITY"),
        ("data/maps/GenesisCity/map.json", "LAYOUT_GENESIS_CITY"),
    ):
        p = ROOT / map_rel
        m = json.loads(p.read_text(encoding="utf-8"))
        m["layout"] = layout_id
        p.write_text(json.dumps(m, indent=2) + "\n", encoding="utf-8", newline="\n")
        print(f"{map_rel} -> {layout_id}")


def main() -> int:
    ensure_graphics()
    ensure_metatiles()
    ensure_headers()
    ensure_tilesets_h()
    ensure_layouts()
    ensure_eastern_map_tilesets()
    ensure_weather()
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
