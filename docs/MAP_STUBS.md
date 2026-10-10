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
| stand-in (city maps) | Mirage City | Psychic / Iris | `MAP_MIRAGE_CITY` (+ `_POKEMON_CENTER_1F/2F`, `_MART`, `_GYM`); Oldale layout clone, Hall desk warps in (badge 9) |
| stand-in (city maps) | Verdantis City | Bug / Celia | `MAP_VERDANTIS_CITY` (+ `_POKEMON_CENTER_1F/2F`, `_MART`, `_GYM`); Fortree layout clone, Hall desk warps in (badge 10) |
| stand-in (city maps) | Obsidian City | Dark / Noctis | `MAP_OBSIDIAN_CITY` (+ `_POKEMON_CENTER_1F/2F`, `_MART`, `_GYM`); Lavaridge layout clone, Hall desk warps in (badge 11) |
| stand-in (city maps) | Astral City | Dragon / Drake | `MAP_ASTRAL_CITY` (+ `_POKEMON_CENTER_1F/2F`, `_MART`, `_GYM`); Slateport layout clone, Hall desk warps in (badge 12 / Tera) |
| stand-in (city maps) | Tidymoon City | Fairy / Luna | `MAP_TIDYMOON_CITY` (+ `_POKEMON_CENTER_1F/2F`, `_MART`, `_GYM`); Mossdeep layout clone, Hall desk warps in (badge 13) |
| stand-in (city maps) | Eon City | Ghost / Morrigan | `MAP_EON_CITY` (+ `_POKEMON_CENTER_1F/2F`, `_MART`, `_GYM`); Mauville layout clone, Hall desk warps in (badge 14) |
| stand-in (city maps) | Genesis City | Normal / Colleague | `MAP_GENESIS_CITY` (+ `_POKEMON_CENTER_1F/2F`, `_MART`, `_GYM`); Petalburg layout clone, Hall desk warps in (badge 15) |
| stand-in (city maps) | Summit City (Aurelia Summit east) | Rock / Mentor | `MAP_SUMMIT_CITY` (+ `_POKEMON_CENTER_1F/2F`, `_MART`, `_GYM`); Rustboro layout clone, Hall desk warps in (badge 16) |
| stand-in (city maps) | Venom Hollow | Poison / Vesper | `MAP_VENOM_HOLLOW` (+ `_POKEMON_CENTER_1F/2F`, `_MART`, `_GYM`); Fallarbor layout clone, Hall desk warps in (badge 17) |
| stand-in (city maps) | Terracotta Mesa | Ground / Terra | `MAP_TERRACOTTA_MESA` (+ `_POKEMON_CENTER_1F/2F`, `_MART`, `_GYM`); Verdanturf layout clone, Hall desk warps in (badge 18) |

### Mirage City stub flow

`EasternAurelia_Hall` Mirage desk / Iris NPC (yes/no) → `warpsilent MAP_MIRAGE_CITY` (6,17) → Gym door (15,16) → `MAP_MIRAGE_CITY_GYM` (Iris, `TRAINER_GENESIS_IRIS`, badge 9). Transit Attendant in town warps back to the Hall. After badge 9 the town girl starts the GARDEVOIR totem (`Genesis_EventScript_TownMon_Mirage`). Reuses `LAYOUT_OLDALE_TOWN` / `LAYOUT_RUSTBORO_CITY_GYM` / `LAYOUT_POKEMON_CENTER_*` / `LAYOUT_MART` (no new layouts); `MAPSEC_MIRAGE_CITY` has no region-map tile yet (not Fly-able). Outdoor map is in `gMapGroup_TownsAndRoutes`, interiors in `gMapGroup_IndoorMirage`.

### Verdantis City stub flow

`EasternAurelia_Hall` Celia NPC / Verdantis desk plaque (needs badge 9; yes/no) -> `warpsilent MAP_VERDANTIS_CITY` (5,7) -> Gym door (22,11) -> `MAP_VERDANTIS_CITY_GYM` (Celia, `TRAINER_GENESIS_CELIA`, badge 10 / Jungle Badge; gated on badge 9). Transit Attendant in town warps back to the Hall (1,6). After badge 10 the town girl starts the VOLCARONA totem (`Genesis_EventScript_TownMon_Verdantis`). Reuses `LAYOUT_FORTREE_CITY` / `LAYOUT_RUSTBORO_CITY_GYM` / `LAYOUT_POKEMON_CENTER_*` / `LAYOUT_MART`; music `MUS_RG_VIRIDIAN_FOREST`; `MAPSEC_VERDANTIS_CITY` has no region-map tile yet. Outdoor map is in `gMapGroup_TownsAndRoutes`, interiors in `gMapGroup_IndoorVerdantis`. Heal location `HEAL_LOCATION_VERDANTIS_CITY`.

### Obsidian City stub flow

`EasternAurelia_Hall` Noctis NPC / Obsidian desk plaque (needs badge 10; yes/no) -> `warpsilent MAP_OBSIDIAN_CITY` (9,7) -> Gym door (5,15) -> `MAP_OBSIDIAN_CITY_GYM` (Noctis, `TRAINER_GENESIS_NOCTIS`, badge 11 / Obsidian Badge; gated on badge 10). Transit Attendant in town warps back to the Hall (1,6). After badge 11 the town girl starts the HYDREIGON totem (`Genesis_EventScript_TownMon_Obsidian`). Reuses `LAYOUT_LAVARIDGE_TOWN` (Dewford has no Mart door) / `LAYOUT_RUSTBORO_CITY_GYM` / `LAYOUT_POKEMON_CENTER_*` / `LAYOUT_MART`; music `MUS_ABANDONED_SHIP`; `MAPSEC_OBSIDIAN_CITY` has no region-map tile yet. Outdoor map is in `gMapGroup_TownsAndRoutes`, interiors in `gMapGroup_IndoorObsidian`. Heal location `HEAL_LOCATION_OBSIDIAN_CITY`.

### Astral City stub flow

`EasternAurelia_Hall` Drake NPC / Astral desk plaque (needs badge 11; yes/no) -> `warpsilent MAP_ASTRAL_CITY` (19,20) -> Gym door (10,12) -> `MAP_ASTRAL_CITY_GYM` (Drake, `TRAINER_GENESIS_DRAKE_GYM`, badge 12 / Astral Badge; gated on badge 11). Drake's win still sets `FLAG_GENESIS_TERA_UNLOCKED` / `FLAG_SYS_TERA_ORB_CHARGED` (Tera unlock stays here). Transit Attendant in town warps back to the Hall (1,6). After badge 12 the town girl starts the DRAGONITE totem (`Genesis_EventScript_TownMon_Astral`). Reuses `LAYOUT_SLATEPORT_CITY` / `LAYOUT_RUSTBORO_CITY_GYM` / `LAYOUT_POKEMON_CENTER_*` / `LAYOUT_MART`; Slateport's Battle Tent door stands in for the Gym door (sign = tent sign); music `MUS_SOOTOPOLIS`; `MAPSEC_ASTRAL_CITY` has no region-map tile yet. Outdoor map is in `gMapGroup_TownsAndRoutes`, interiors in `gMapGroup_IndoorAstralCity`. Heal location `HEAL_LOCATION_ASTRAL_CITY`.

### Tidymoon City stub flow

`EasternAurelia_Hall` Luna NPC / Tidymoon desk plaque (needs badge 12; yes/no) -> `warpsilent MAP_TIDYMOON_CITY` (28,17) -> Gym door (38,9) -> `MAP_TIDYMOON_CITY_GYM` (Luna, `TRAINER_GENESIS_LUNA`, badge 13 / Moon Badge; gated on badge 12). Transit Attendant in town warps back to the Hall (1,6). After badge 13 the town girl starts the TOGEKISS totem (`Genesis_EventScript_TownMon_Tidymoon`). Reuses `LAYOUT_MOSSDEEP_CITY` / `LAYOUT_RUSTBORO_CITY_GYM` / `LAYOUT_POKEMON_CENTER_*` / `LAYOUT_MART`; music `MUS_RG_SEVII_123`; `MAPSEC_TIDYMOON_CITY` has no region-map tile yet. Outdoor map is in `gMapGroup_TownsAndRoutes`, interiors in `gMapGroup_IndoorTidymoonCity`. Heal location `HEAL_LOCATION_TIDYMOON_CITY`.

### Eon City stub flow

`EasternAurelia_Hall` Morrigan NPC / Eon desk plaque (needs badge 13; yes/no) -> `warpsilent MAP_EON_CITY` (22,6) -> Gym door (8,5) -> `MAP_EON_CITY_GYM` (Morrigan, `TRAINER_GENESIS_MORRIGAN`, badge 14 / Eon Badge; gated on badge 13). Transit Attendant in town warps back to the Hall (1,6). After badge 14 the town girl starts the DRAGAPULT totem (`Genesis_EventScript_TownMon_Eon`). Reuses `LAYOUT_MAUVILLE_CITY` / `LAYOUT_RUSTBORO_CITY_GYM` / `LAYOUT_POKEMON_CENTER_*` / `LAYOUT_MART`; music `MUS_RG_POKE_TOWER`; `MAPSEC_EON_CITY` has no region-map tile yet. Outdoor map is in `gMapGroup_TownsAndRoutes`, interiors in `gMapGroup_IndoorEonCity`. Heal location `HEAL_LOCATION_EON_CITY`.

### Genesis City stub flow

`EasternAurelia_Hall` Colleague NPC / Genesis desk plaque (needs badge 14; yes/no) -> `warpsilent MAP_GENESIS_CITY` (20,17) -> Gym door (15,8) -> `MAP_GENESIS_CITY_GYM` (Colleague, `TRAINER_GENESIS_COLLEAGUE`, badge 15 / Genesis Badge; gated on badge 14). Transit Attendant in town warps back to the Hall (1,6). After badge 15 the town girl starts the SLAKING totem (`Genesis_EventScript_TownMon_GenesisCity`). Reuses `LAYOUT_PETALBURG_CITY` / `LAYOUT_RUSTBORO_CITY_GYM` / `LAYOUT_POKEMON_CENTER_*` / `LAYOUT_MART`; music `MUS_PETALBURG`; `MAPSEC_GENESIS_CITY` has no region-map tile yet. Outdoor map is in `gMapGroup_TownsAndRoutes`, interiors in `gMapGroup_IndoorGenesisCity`. Heal location `HEAL_LOCATION_GENESIS_CITY`.

### Summit City (Aurelia Summit east) stub flow

`EasternAurelia_Hall` Mentor NPC / Summit desk plaque (needs badge 15; yes/no) -> `warpsilent MAP_SUMMIT_CITY` (16,39) -> Gym door (27,19) -> `MAP_SUMMIT_CITY_GYM` (Mentor, `TRAINER_GENESIS_MENTOR`, badge 16 / Ascension Badge; gated on badge 15). Beating Mentor sets `GENESIS_STORY_EASTERN_DONE`. Transit Attendant in town warps back to the Hall (1,6). After badge 16 the town girl starts the TYRANITAR totem (`Genesis_EventScript_TownMon_Summit`). Reuses `LAYOUT_RUSTBORO_CITY` / `LAYOUT_RUSTBORO_CITY_GYM` / `LAYOUT_POKEMON_CENTER_*` / `LAYOUT_MART`; music `MUS_RG_MT_MOON`; `MAPSEC_SUMMIT_CITY` has no region-map tile yet. Outdoor map is in `gMapGroup_TownsAndRoutes`, interiors in `gMapGroup_IndoorSummitCity`. Heal location `HEAL_LOCATION_SUMMIT_CITY`.

### Venom Hollow stub flow

`EasternAurelia_Hall` Vesper NPC / Venom desk plaque (needs badge 16; yes/no) -> `warpsilent MAP_VENOM_HOLLOW` (14,8) -> Gym door (8,7) -> `MAP_VENOM_HOLLOW_GYM` (Vesper, `TRAINER_GENESIS_VESPER`, badge 17 / Venom Badge; gated on badge 16). Transit Attendant in town warps back to the Hall (1,6). After badge 17 the town girl starts the GENGAR totem (`Genesis_EventScript_TownMon_Venom`). Reuses `LAYOUT_FALLARBOR_TOWN` / `LAYOUT_RUSTBORO_CITY_GYM` / `LAYOUT_POKEMON_CENTER_*` / `LAYOUT_MART`; Fallarbor's Battle Tent door stands in for the Gym door (sign = tent sign); music `MUS_RG_ROCKET_HIDEOUT`; `MAPSEC_VENOM_HOLLOW` has no region-map tile yet. Outdoor map is in `gMapGroup_TownsAndRoutes`, interiors in `gMapGroup_IndoorVenomHollow`. Heal location `HEAL_LOCATION_VENOM_HOLLOW`.

### Terracotta Mesa stub flow

`EasternAurelia_Hall` Terra NPC / Terracotta desk plaque (needs badge 17; yes/no) -> `warpsilent MAP_TERRACOTTA_MESA` (16,4) -> Gym door (3,7) -> `MAP_TERRACOTTA_MESA_GYM` (Terra, `TRAINER_GENESIS_TERRA`, badge 18 / Terra Badge; gated on badge 17). Transit Attendant in town warps back to the Hall (1,6). After badge 18 the town girl starts the GARCHOMP totem (`Genesis_EventScript_TownMon_Terracotta`). Reuses `LAYOUT_VERDANTURF_TOWN` / `LAYOUT_RUSTBORO_CITY_GYM` / `LAYOUT_POKEMON_CENTER_*` / `LAYOUT_MART`; Verdanturf's Battle Tent door stands in for the Gym door (sign = tent sign); music `MUS_DESERT`; `MAPSEC_TERRACOTTA_MESA` has no region-map tile yet. Outdoor map is in `gMapGroup_TownsAndRoutes`, interiors in `gMapGroup_IndoorTerracottaMesa`. Heal location `HEAL_LOCATION_TERRACOTTA_MESA`.

## Postgame / facilities

- Battle Frontier (Expansion facilities; Aurelia branding)
- Eastern Aurelia Hall (`MAP_EASTERN_AURELIA_HALL`) — city-desk warps for gyms 9–18 (leader battles live in each city's Gym) (unique leader dialogue + plaques), Hall clerk (directory / return warp), Legend Sanctum seeker; enter via Reception Gate greeter after Champion (Fly → Frontier → greeter)
- Legend Sanctum (`MAP_GENESIS_LEGEND_SANCTUM`) — Aethernox / Solara / Genesis foci
- World Tournament lobby v2 — Battle Tower 3-round bracket (Mentor → Astra → Victor) + rematch BP
- Genesis Laboratory (later)
- Custom legendary / Mythical outdoor quest maps (later)

## `genesis/maps` next steps

Prefer script/config polish until Porymap city geometry is ready. Full Mirage→Summit east maps replace Hall desks later; OldaleTown_Gym / EasternAurelia_Hall show the copy-layout stub pattern.
