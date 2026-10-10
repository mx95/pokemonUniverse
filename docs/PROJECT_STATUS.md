# Pokémon Genesis — Project Status

Living tracker for the Ultimate Feature / QoL / World / Gameplay specification.

**Rule (§179):** Do not implement all features in one pass. Work in feature groups: search Expansion → reuse/extend → compile → test → commit → update this file → continue.

**Priority (§172):** FUN > CONVENIENCE > DEPTH > COMPLEXITY. Prefer Expansion implementations over custom rewrites.

Status values: `PLANNED` | `DESIGN` | `IN DEVELOPMENT` | `IMPLEMENTED` | `TESTING` | `COMPLETE` | `BUGGED` | `DEFERRED`

---

## Current baseline

| Item | Status | Notes |
|------|--------|-------|
| Expansion base 1.17.0 | COMPLETE | Branch `genesis/base`; HnS on `archive/heart-and-soul` |
| ROM build `pokemonGenesis.gba` | COMPLETE | Verified WSL2 build (~32 MB) |
| Genesis config flags | IMPLEMENTED | `include/config/genesis.h` |
| Docs skeleton | IMPLEMENTED | `docs/GENESIS.md`, `REGION_AURELIA.md`, `STORY.md`, `BUGS.md` |
| Validation / smoke tests | IMPLEMENTED | `make genesis-check` (`tools/genesis/run_smoke_tests.py`) |
| Early-game Aurelia branding | IMPLEMENTED | Verdant/Lumen/Port Azure NPC + sign text |
| Genesis Form framework stub | IMPLEMENTED | Switch-in overlay enabled; unlock after all three legends |
| Verdant → Route 1 → Lumen loop | IMPLEMENTED | Temporary Hoenn map aliases + rebrand |
| Route 2 + Lumen Forest + Port Azure | IMPLEMENTED | Map names + multi-gen encounters |
| Act 1 Lumen Forest (Crystal / Eclipse) | IMPLEMENTED | Flags + Petalburg Woods rewrite; DexNav post-lab |
| Gym 1 Flora (Lumen) | IMPLEMENTED | `OldaleTown_Gym` from Rustboro pattern; Verdant Badge |
| Gym 3 Marina (Port Azure stand-in) | IMPLEMENTED | Petalburg Gym Water rebrand; Tidal Badge |
| Gyms 2/4–8 stand-in path | IMPLEMENTED | Bran/Volt/Glacia/Ra/Skye/Titan on Hoenn gyms; Mega/Z/Dynamax items |
| Elite Four + Champion | IMPLEMENTED | Umbra/Shade/Boreas/Drake + Champion Astra; Tera on clear |
| Postgame Frontier hooks | IMPLEMENTED | Aurelia Frontier branding; Eastern Hall city desks + clerk QoL; WT Tower bout; legend seeker |
| DS-style / “3D” presentation | IMPLEMENTED | Gen4/5 sprites, Gen5 pop-ups, shadows, modern particles |
| Title / opening branding | IMPLEMENTED | GENESIS VERSION banner, teal title grade, RG title theme; Birch speech skipped; Corviknight taxi intro (no truck) |

---

## Priority 1 — Core (next focus)

| Feature group | Spec §§ | Status | Expansion reuse |
|---------------|---------|--------|-----------------|
| Pokémon / forms / moves DB | — | COMPLETE | Expansion Gen 1–9 + forms all enabled; see `docs/POKEMON_ROSTER.md` |
| Original legendaries Aethernox/Solara/Genesis | — | IMPLEMENTED | DS stand-ins (Giratina Origin / Reshiram / Arceus); Sanctum lore polish |
| Route 1 multi-gen encounters | — | IMPLEMENTED | Early sample of Gen 2–9 field mons |
| Route 2 / Lumen Forest encounters | — | IMPLEMENTED | Multi-gen early + forest tables |
| Custom legendary battle sprites | — | PLANNED | Replace DS stand-ins with unique authored art |
| Battle engine + gimmicks | 83–85 | IMPLEMENTED (upstream) | Mega/Z/Dynamax/Tera/Primal/Ultra; gate via story flags |
| Save system / versioning | 103 | IMPLEMENTED | `VAR_GENESIS_SAVE_VERSION` + `Genesis_InitSave` on New Game |
| Verdant / Lumen playable polish | 2–4 | TESTING | Branding smoke-tested; needs in-emulator checklist |
| Aurelia maps (custom geometry) | 3–4 | IN DEVELOPMENT | Hall city-desk polish started; full geometry still planned — see `MAP_STUBS.md` |
| 16 Gyms + badges | 5–7 | IMPLEMENTED (stand-in) | Badges 1–8 Hoenn gyms; 9–18 Eastern Hall (all 18 types; Poison/Ground desks added) |
| Main story (8 acts) | 65–66, 131–132 | IMPLEMENTED (stand-in) | Acts 1–8 flags/dialogue + 4 puzzle setpieces + Kai beats |
| Elite Four + Champion | 8–9 | IMPLEMENTED | Umbra/Shade/Boreas/Drake + Astra; rematches via Expansion |
| Core QoL (already toggled) | 15, 22, 25–26, 52 | IMPLEMENTED | Reusable TMs, Exp Share, followers, DexNav, auto-repel menu, type indicators |
| Level scaling / caps | 11–12 | IMPLEMENTED | Soft EXP cap via `VAR_GENESIS_LEVEL_CAP`; badge-driven |
| Difficulty modes | 10 | IMPLEMENTED | `VAR_GENESIS_DIFFICULTY` / `B_VAR_DIFFICULTY`; New Game → Normal |

---

## Priority 2 — Systems

| Feature group | Spec §§ | Status | Notes |
|---------------|---------|--------|-------|
| Quest system + tracker | 62–64, 120–122 | IMPLEMENTED | Lumen Center board: acts 1–8, puzzles, eastern, legends, WT |
| DexNav polish + encounter search | 47–48 | IMPLEMENTED | Lab grants search + detector; search levels still off (saveblock) |
| Character customization | 57–58 | IMPLEMENTED (stub) | Lilycove Boutique Aurelia dialogue; needs OW outfit art |
| Followers interactions | 52–53 | IMPLEMENTED (v1) | Genesis conditional mood lines (forest/Celestia/rain/League/Sanctum) |
| Battle Frontier facilities | 73–82 | IMPLEMENTED | Expansion Frontier live post-Champion; Aurelia branding |
| Postgame competitive services | 37–46, 139 | IMPLEMENTED (stub) | Bottle Cap + Ability Capsule tutor in Lumen Center |
| World Tournament | 135 | IMPLEMENTED (facility) | Dedicated WT lobby map + Reception Gate / Tower warps; 4-round bracket + heals |
| Genesis Form (full) | 85 | IMPLEMENTED (v1) | Switch-in type/ability/stat overlay for SPECIES_GENESIS |
| Fast travel / Smart Fly | 23–24 | IMPLEMENTED | `OW_FLAG_POKE_RIDER` = Fly HM; R on Town Map / PokéNav |
| HM field-move rework | 19–20 | IMPLEMENTED (v1) | Defog + Rock Climb enabled; Fortree field-move guide NPC |
| Universal bike Mach/Acro | 21 | IMPLEMENTED | Rydel gives both; R+SELECT toggles while riding |
| Mega-capable starters | — | IMPLEMENTED | All 12 mega starter lines after bag type pick; matching stone at Gym 4 |
| AI Metagross side quest | — | IMPLEMENTED | New Mauville Totem shiny Mega Metagross; catch after defeat |

---

## Priority 3 — Optional / polish

| Feature group | Spec §§ | Status | Notes |
|---------------|---------|--------|-------|
| Achievements + titles | 60–61 | IMPLEMENTED (v2) | Lumen PC Achievement Board + flags (Ace/Eclipse/Champion/WT/Legends) |
| Cooking / picnic / camping | 54–56 | DEFERRED | GBA budget; lightweight if ever |
| Contests | 150 | DEFERRED | Expansion contest base exists |
| Secret bases | 152–153 | DEFERRED | Expansion secret bases exist; customize later |
| Photo system | 157–158 | DEFERRED | Memory-heavy |
| Randomizer / Nuzlocke / Monotype | 141–145 | IMPLEMENTED (v1) | Aide challenge menu; Nuzlocke whiteout; monotype wild bias |
| New Game+ | 140 | DEFERRED | After save versioning solid |
| Seasons | 89 | DEFERRED | Palette + encounter hooks only |
| Music player | 154 | DEFERRED | Postgame |
| NPC encyclopedia | 115 | DEFERRED | Optional |

---

## World evolution checklist (§4)

Track as maps/story land:

- [x] Gym 4 → new shops (Mauville Mart + shopCriteria badge gates)
- [x] Gym 8 → eastern Aurelia opens (post-Champion Reception Gate → Eastern Hall)
- [x] Eclipse defeated → Legend Sanctum + archive flag open
- [x] Champion → Frontier + Eastern Hall + WT stub
- [x] Legendary quests → Eastern Hall seeker (Aethernox/Solara/Genesis)
- [x] Weather events → rare encounters (Route 119/120 rain/sun bias)

---

## Gimmick unlock order (§83)

| Unlock | Badge / timing | Flag / config |
|--------|----------------|---------------|
| Mega | Badge 4 | Story gate |
| Z-Moves | Badge 7 | Story gate |
| Dynamax | Badge 8 | `FLAG_SYS_DYNAMAX_BATTLE` |
| Tera | Badge 12 | `FLAG_SYS_TERA_ORB_*` |
| Primal / Ultra / Genesis Form | Postgame | Genesis Form config |

Story battles: one gimmick per trainer (`GENESIS_ONE_GIMMICK_PER_STORY_BATTLE`).

---

## Next recommended feature group

1. **In-emulator playtest** of Corviknight intro, mega starters, town totems, WT facility, 18-type gyms.
2. **`genesis/maps`:** first real eastern city (or Lumen/Verdant custom geometry) when Porymap bandwidth allows; Hall desks remain until then.
3. Unique legendary battle sprites (replace DS stand-ins).
4. Puzzle rewards / Nuzlocke catch filter / Genesis Form battle UX polish.

---

## Known gaps vs Ultimate Spec

- Difficulty labels in Ultimate (STORY / STANDARD / CHAMPION / NUZLOCKE / etc.) exceed Expansion’s Easy/Normal/Hard — design before coding Expert+.
- Many QoL items already exist in Expansion; enable/configure before writing new UI.
- Cooking, photo, seasons, NG+: deferred for ROM/RAM budget (§171).
- Radical Red / Unbound remain **inspiration only** — no asset/content copying.
