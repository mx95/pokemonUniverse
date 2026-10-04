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
| stand-in | Mirage City | Psychic / Iris | Eastern Hall desk + plaque (badge 9) |
| stand-in | Verdantis City | Bug / Celia | Eastern Hall desk + plaque (badge 10) |
| stand-in | Obsidian City | Dark / Noctis | Eastern Hall desk + plaque (badge 11) |
| stand-in | Astral City | Dragon / Drake | Eastern Hall desk + plaque (badge 12 / Tera) |
| stand-in | Tidymoon City | Fairy / Luna | Eastern Hall desk + plaque (badge 13) |
| stand-in | Eon City | Ghost / Morrigan | Eastern Hall desk + plaque (badge 14) |
| stand-in | Genesis City | Mixed / Colleague | Eastern Hall desk + plaque (badge 15) |
| stand-in | Aurelia Summit (east) | Mixed / Mentor | Eastern Hall desk + plaque (badge 16) |

## Postgame / facilities

- Battle Frontier (Expansion facilities; Aurelia branding)
- Eastern Aurelia Hall (`MAP_EASTERN_AURELIA_HALL`) — city-desk stand-ins for gyms 9–16 (unique leader dialogue + plaques), Hall clerk (directory / return warp), Legend Sanctum seeker; enter via Reception Gate greeter after Champion (Fly → Frontier → greeter)
- Legend Sanctum (`MAP_GENESIS_LEGEND_SANCTUM`) — Aethernox / Solara / Genesis foci
- World Tournament lobby v2 — Battle Tower 3-round bracket (Mentor → Astra → Victor) + rematch BP
- Genesis Laboratory (later)
- Custom legendary / Mythical outdoor quest maps (later)

## `genesis/maps` next steps

Prefer script/config polish until Porymap city geometry is ready. Full Mirage→Summit east maps replace Hall desks later; OldaleTown_Gym / EasternAurelia_Hall show the copy-layout stub pattern.
