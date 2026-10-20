# Aurelia map stubs — remaining cities

Phase B delivers the Verdant Town → Route 1 → Lumen City loop by rebranding
Expansion's Littleroot / Route 101 / Oldale maps (see docs/REGION_AURELIA.md).

The following locations are **planned** for `genesis/maps`. Each needs maps,
layouts, NPCs, trainers, encounters, Center/Mart where appropriate, and story hooks.

Do not invent map IDs until Porymap entries are created.

| Priority | Location | Gym | Status |
|----------|----------|-----|--------|
| done (alias) | Verdant Town | — | MAP_LITTLEROOT_* |
| done (alias) | Route 1 | — | MAP_ROUTE101 |
| done (alias) | Lumen City | Grass / Flora | MAP_OLDALE_* + MAP_OLDALE_TOWN_GYM |
| done (alias) | Port Azure | Water / Marina | MAP_PETALBURG_* |
| done (alias) | Ironridge City | Rock / Bran | MAP_DEWFORD_* |
| done (alias) | Celestia City | Electric / Volt | MAP_MAUVILLE_* (+ Mega Ring) |
| done (alias) | Frostveil City | Ice / Glacia | MAP_LAVARIDGE_* |
| done (alias) | Solaris City | Ground / Ra | MAP_FORTREE_* |
| done (alias) | Stormbreak City | Flying / Skye | MAP_MOSSDEEP_* (+ Z-Power Ring) |
| done (alias) | Titania City | Steel / Titan | MAP_SOOTOPOLIS_* (+ Dynamax Band) |
| done (alias) | Aurelia Summit | League | MAP_EVER_GRANDE_* (E4 + Champion Astra) |
| live (Porymap layouts) | Mirage City | Psychic / Iris | `MAP_MIRAGE_CITY*` + `LAYOUT_MIRAGE_CITY` / `_GYM` |
| live (Porymap layouts) | Verdantis City | Bug / Celia | `MAP_VERDANTIS_CITY*` + dedicated layouts |
| live (Porymap layouts) | Obsidian City | Dark / Noctis | `MAP_OBSIDIAN_CITY*` + dedicated layouts |
| live (Porymap layouts) | Astral City | Dragon / Drake | `MAP_ASTRAL_CITY*` + dedicated layouts (Tera unlock) |
| live (Porymap layouts) | Tidymoon City | Fairy / Luna | `MAP_TIDYMOON_CITY*` + dedicated layouts |
| live (Porymap layouts) | Eon City | Ghost / Morrigan | `MAP_EON_CITY*` + dedicated layouts |
| live (Porymap layouts) | Genesis City | Mixed / Colleague | `MAP_GENESIS_CITY*` + dedicated layouts |
| live (Porymap layouts) | Aurelia Summit (east) | Mixed / Mentor | `MAP_SUMMIT_CITY*` + dedicated layouts |

## Postgame / facilities

- Battle Frontier (Expansion facilities; Aurelia branding)
- Eastern Aurelia Hall (`MAP_EASTERN_AURELIA_HALL`) — warp desks for gyms 9–16 (live cities), Hall clerk, Legend Sanctum seeker; enter via Reception Gate greeter after Champion (Fly → Frontier → greeter)
- Eastern cities 9–16 — Center / Mart / Gym each; Hall attendant + teleport net return warps; rebuild outdoor/gym bins with `python3 tools/genesis/build_eastern_layouts.py` (Mirage: `build_mirage_layouts.py`)
- Legend Sanctum (`MAP_GENESIS_LEGEND_SANCTUM`) — Aethernox / Solara / Genesis foci
- World Tournament lobby (`MAP_WORLD_TOURNAMENT_LOBBY`) — dedicated facility; Tower boy warps here; 4-round bracket + 4-way day rematch BP
- Competitive prep desk (Lumen Center Gentleman) — Hyper Train + Gold Cap + supply mart
- Genesis Laboratory (later)
- Custom legendary / Mythical outdoor quest maps (later)

## `genesis/maps` next steps

1. Optional Porymap polish on Mirage→Summit (tileset / decoration) without moving door warps.
2. Unique Center/Mart layouts only if a city needs non-standard interiors.
3. Unique legendary battle sprites (replace DS stand-ins).

Scaffold / validate:

```bash
python3 tools/genesis/scaffold_eastern_cities.py   # idempotent
python3 tools/genesis/validate_eastern.py
python3 tools/genesis/validate_mirage.py
```
