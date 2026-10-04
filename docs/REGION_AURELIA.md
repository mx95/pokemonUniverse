# Aurelia Region

Pokémon Genesis takes place in **Aurelia**, themed around Genesis Energy connecting major battle phenomena.

## Major locations (16 gyms)

| # | Location | Theme / Type | Leader | Badge | Notes |
|---|----------|--------------|--------|-------|-------|
| 1 | Verdant Town | Start | — | — | Player house, rival, Prof. lab |
| 2 | Lumen City | Grass | Flora | Verdant | Trainer School, first tutors |
| 3 | Port Azure | Water | Marina | Tidal | Harbor, ferry, Battle Tent |
| 4 | Ironridge City | Rock | Bran | Ore | Mines, fossils |
| 5 | Celestia City | Electric | Volt | Volt | **Mega Evolution** unlock |
| 6 | Frostveil City | Ice | Glacia | Frost | Snow, ruins |
| 7 | Solaris City | Ground | Ra | Solar | Desert, temples |
| 8 | Stormbreak City | Flying | Skye | Tempest | Weather lab; **Z-Moves** unlock |
| 9 | Titania City | Steel | Titan | Titan | Industry; **Dynamax** unlock |
| — | *Eastern Aurelia opens* | | | | After badge 8 |
| 10 | Mirage City | Psychic | Iris | Mirage | Illusions, teleport net |
| 11 | Verdantis City | Bug | Celia | Jungle | Rainforest |
| 12 | Obsidian City | Dark | Noctis | Obsidian | Volcano |
| 13 | Astral City | Dragon | Drake | Astral | Observatory; **Tera** unlock |
| 14 | Tidymoon City | Fairy | Luna | Moon | Islands, dive |
| 15 | Eon City | Ghost | Morrigan | Eon | Spirit World quests |
| 16 | Genesis City | Normal/Mixed | (colleague) | Genesis | Prep hub |
| 17 | Aurelia Summit | Dragon/Mixed | (mentor) | Ascension | League unlock |

## Starter loop (Phase B)

Temporary map aliases reuse Expansion Hoenn layouts until custom Aurelia geometry is authored:

| Genesis name | Temporary map IDs | Region map display | Facilities |
|--------------|-------------------|--------------------|------------|
| Verdant Town | `MAP_LITTLEROOT_*` | VERDANT TOWN | Player/rival houses, Prof. Aurelia lab |
| Route 1 | `MAP_ROUTE101` | ROUTE 1 | Wild encounters, starter rescue |
| Lumen City | `MAP_OLDALE_*` | LUMEN CITY | Pokémon Center, Poké Mart |
| Route 2 | `MAP_ROUTE102` | ROUTE 2 | Multi-gen early encounters |
| Port Azure | `MAP_PETALBURG_*` | PORT AZURE | Gym 3 stand-in (Water / Marina) |
| Lumen Forest | `MAP_PETALBURG_WOODS` | LUMEN FOREST | Act 1 Crystal / Eclipse |
| Ironridge | `MAP_DEWFORD_*` | IRONRIDGE CITY | Gym 2 Bran (Rock) |
| Celestia | `MAP_MAUVILLE_*` | CELESTIA CITY | Gym 4 Volt + Mega unlock |
| Frostveil | `MAP_LAVARIDGE_*` | FROSTVEIL CITY | Gym 5 Glacia (Ice) |
| Solaris | `MAP_FORTREE_*` | SOLARIS CITY | Gym 6 Ra (Ground) |
| Stormbreak | `MAP_MOSSDEEP_*` | STORMBREAK CITY | Gym 7 Skye + Z unlock |
| Titania | `MAP_SOOTOPOLIS_*` | TITANIA CITY | Gym 8 Titan + Dynamax unlock |
| Aurelia Summit | `MAP_EVER_GRANDE_*` | AURELIA SUMMIT | Elite Four + Champion Astra |
| Eastern Aurelia Hall | `MAP_EASTERN_AURELIA_HALL` | BATTLE FRONTIER | Postgame gyms 9–16 + legend seeker |

**Stand-in note:** Hoenn badge order covers gyms 1–8. Gyms 9–16 are sequential challenges in Eastern Aurelia Hall (warp from Frontier Reception Gate after Champion). Custom city geometry replaces the Hall later.

Verdant's dedicated small Center/Mart will be added with custom map geometry later; early healing/shopping uses Lumen City.

Do not port Heart & Soul Johto maps.

## Facilities (every major city)

Pokémon Center, Poké Mart, wild encounters on adjoining routes, trainers, items, scripted story beats, and music as content is authored.
