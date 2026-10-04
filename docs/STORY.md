# Pokémon Genesis — Story

## Theme

Genesis Energy connects Mega Evolution, Primal Reversion, Z-Power, Dynamax/Gigantamax, Terastallization, and Ultra Burst. It is a living force tied to the legendary Pokémon **Genesis**.

## Cast

| Role | Name | Notes |
|------|------|-------|
| Player | Customizable | Name + gender |
| Rival | **Kai** | Confident → learns cooperation |
| Professor | **Professor Aurelia** | Adaptation / battle phenomena |
| Villain | **Dr. Caelum** | Founder of Team Eclipse |

### Team Eclipse captains

| Captain | Specialty |
|---------|-----------|
| Nova | Mega Evolution |
| Arc | Z-Moves (renamed from Volt to avoid Gym Leader collision) |
| Forge | Dynamax (renamed from Titan) |
| Prism | Terastallization |
| Origin | Primal / ancient Pokémon |

Gym Leaders Volt and Titan retain their Phase 2 names.

## Legendaries (original)

| Species | Types | Role |
|---------|-------|------|
| Aethernox | Dragon/Dark | Chaos |
| Solara | Psychic/Fire | Creation |
| Genesis | Normal/??? | Potential / source of phenomena |

## Acts (stand-in path)

| Act | Flag / state | Hook maps |
|-----|--------------|-----------|
| 1 | `FLAG_GENESIS_ACT1_FOREST_DONE` | Lumen Forest (Petalburg Woods) |
| 2 | `FLAG_GENESIS_ACT2_DONE` + museum Eclipse beat | Gym 3 / Oceanic Museum |
| 3 | `FLAG_GENESIS_ACT3_DONE` | Meteor Falls + Mt. Chimney |
| 4 | `FLAG_GENESIS_ACT4_DONE` + `FLAG_GENESIS_ECLIPSE_DEFEATED` | Seafloor Cavern (Caelum) |
| 5 | `FLAG_GENESIS_ACT5_DONE` | Mossdeep Space Center (Tera foreshadow) |
| 6 | `FLAG_GENESIS_ACT6_DONE` | Sky Pillar Top |
| 7 | `FLAG_GENESIS_ACT7_DONE` | Magma Hideout 4F (Nova) |
| 8 | `FLAG_GENESIS_ACT8_DONE` / Champion | Ever Grande Champions Room |

Rival Kai beats: after Act 2, after Seafloor, before Elite Four (`FLAG_GENESIS_RIVAL_BEAT_*`).

## Story puzzles (QA solutions — not shown in-game)

| Puzzle | Flag | Location | Solution |
|--------|------|----------|----------|
| Crystal Relay | `FLAG_GENESIS_PUZZLE_CRYSTAL_RELAY` | New Mauville Inside | Need Genesis Crystal; press **Blue → Green → Red** |
| Echo Sealed | `FLAG_GENESIS_PUZZLE_ECHO_SEALED` | Sealed Chamber (after Dig + Act 3) | Riddle answers: **No**, then **Yes**; Strength-style press |
| Phenomena Lock | `FLAG_GENESIS_PUZZLE_PHENOMENA` | Sky Pillar 1F pylons | Order **Grass → Water → Fire**; scientist resets |
| Eclipse Cipher | `FLAG_GENESIS_PUZZLE_ECLIPSE_CIPHER` | Magma Hideout 1F | Console: **Yes**, then **No**; Switch **A** then **B** |

## Postgame chapters

Eastern Aurelia Hall (badges 9–16), Legend Sanctum (`MAP_GENESIS_LEGEND_SANCTUM`) for Aethernox/Solara/Genesis, World Tournament Tower stub, Battle Frontier. Completing all three legends sets `FLAG_GENESIS_FORM_UNLOCKED` — SPECIES_GENESIS gets a switch-in overlay (types/ability/stats) when `GENESIS_ENABLE_GENESIS_FORM` is on.

## Battle gimmick rules

- Normal story battles: **one gimmick per trainer**
- Postgame Chaos Battles: multiple gimmicks under explicit rules
- Communicate which gimmick is available in each battle
