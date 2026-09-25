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
| Validation starter | IMPLEMENTED | `tools/genesis/validate_pokedex.py` |
| Genesis Form framework stub | DESIGN | Tables/API exist; `GENESIS_ENABLE_GENESIS_FORM` off |
| Verdant → Route 1 → Lumen loop | IMPLEMENTED | Temporary Hoenn map aliases + rebrand |
| Route 2 + Lumen Forest + Port Azure | IMPLEMENTED | Map names + multi-gen encounters |
| DS-style / “3D” presentation | IMPLEMENTED | Gen4/5 sprites, Gen5 pop-ups, shadows, modern particles |

---

## Priority 1 — Core (next focus)

| Feature group | Spec §§ | Status | Expansion reuse |
|---------------|---------|--------|-----------------|
| Pokémon / forms / moves DB | — | COMPLETE | Expansion Gen 1–9 + forms all enabled; see `docs/POKEMON_ROSTER.md` |
| Original legendaries Aethernox/Solara/Genesis | — | IMPLEMENTED | DS-style Expansion stand-ins (Giratina/Reshiram/Arceus); unique art planned |
| Route 1 multi-gen encounters | — | IMPLEMENTED | Early sample of Gen 2–9 field mons |
| Route 2 / Lumen Forest encounters | — | IMPLEMENTED | Multi-gen early + forest tables |
| Custom legendary battle sprites | — | PLANNED | Replace DS stand-ins with unique art |
| Battle engine + gimmicks | 83–85 | IMPLEMENTED (upstream) | Mega/Z/Dynamax/Tera/Primal/Ultra; gate via story flags |
| Save system / versioning | 103 | PLANNED | Expansion save + `GENESIS_SAVE_VERSION` |
| Verdant / Lumen playable polish | 2–4 | TESTING | Needs in-emulator playtest checklist |
| Aurelia maps (custom geometry) | 3–4 | PLANNED | Replace aliases; see `MAP_STUBS.md` |
| 16 Gyms + badges | 5–7 | PLANNED | Thematic teams; rematches post-Champion |
| Main story (8 acts) | 65–66, 131–132 | PLANNED | Team Eclipse arc; Kai rival |
| Elite Four + Champion | 8–9 | PLANNED | Strategy-based E4; Champion rematch |
| Core QoL (already toggled) | 15, 22, 25–26, 52 | IMPLEMENTED | Reusable TMs, Exp Share, followers, DexNav, auto-repel menu, type indicators |
| Level scaling / caps | 11–12 | PLANNED | Expansion `caps.h` + Genesis policy layer |
| Difficulty modes | 10 | DESIGN | Map Ultimate names → Expansion: Story→Easy, Standard→Normal, Hard→Hard; Expert/Champion = Genesis extensions |

---

## Priority 2 — Systems

| Feature group | Spec §§ | Status | Notes |
|---------------|---------|--------|-------|
| Quest system + tracker | 62–64, 120–122 | PLANNED | Main/side/legendary categories |
| DexNav polish + encounter search | 47–48 | IN DEVELOPMENT | Enabled; need UI unlock scripting + search locations |
| Character customization | 57–58 | PLANNED | Clothing shops; badge unlocks |
| Followers interactions | 52–53 | PLANNED | Mood cosmetic-only |
| Battle Frontier facilities | 73–82 | PLANNED | Prefer Expansion facilities first (Tower→Factory→Dome→Arena) |
| Postgame competitive services | 37–46, 139 | PLANNED | IV/EV/nature/ability/egg-move tutors |
| World Tournament | 135 | PLANNED | Postgame only |
| Genesis Form (full) | 85 | DESIGN | Must differ from Mega; late unlock |
| Fast travel / Smart Fly | 23–24 | PLANNED | Progressive unlocks |
| HM field-move rework | 19–20 | PLANNED | Prefer Expansion field-move configs first |
| Universal bike Mach/Acro | 21 | PLANNED | Search Expansion bike toggle |

---

## Priority 3 — Optional / polish

| Feature group | Spec §§ | Status | Notes |
|---------------|---------|--------|-------|
| Achievements + titles | 60–61 | PLANNED | Trainer Card display |
| Cooking / picnic / camping | 54–56 | DEFERRED | GBA budget; lightweight if ever |
| Contests | 150 | DEFERRED | Expansion contest base exists |
| Secret bases | 152–153 | DEFERRED | Expansion secret bases exist; customize later |
| Photo system | 157–158 | DEFERRED | Memory-heavy |
| Randomizer / Nuzlocke / Monotype | 141–145 | PLANNED | Optional challenge modes; story-safe |
| New Game+ | 140 | DEFERRED | After save versioning solid |
| Seasons | 89 | DEFERRED | Palette + encounter hooks only |
| Music player | 154 | DEFERRED | Postgame |
| NPC encyclopedia | 115 | DEFERRED | Optional |

---

## World evolution checklist (§4)

Track as maps/story land:

- [ ] Gym 4 → new shops
- [ ] Gym 8 → eastern Aurelia opens
- [ ] Eclipse defeated → blocked areas open
- [ ] Champion → new NPCs / rematches
- [ ] Legendary quests → dialogue updates
- [ ] Weather events → rare encounters

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

1. **In-emulator playtest** of Verdant → Route 1 → Lumen (starter, lab, Center, Mart).
2. **`genesis/maps`:** Port Azure stub + Route connections (first custom/new map work beyond aliases).
3. **`genesis/story`:** story flag block + Act 1 scripts (Genesis Crystal / first Eclipse contact).
4. Keep updating this file after each group.

---

## Known gaps vs Ultimate Spec

- Difficulty labels in Ultimate (STORY / STANDARD / CHAMPION / NUZLOCKE / etc.) exceed Expansion’s Easy/Normal/Hard — design before coding Expert+.
- Many QoL items already exist in Expansion; enable/configure before writing new UI.
- Cooking, photo, seasons, NG+: deferred for ROM/RAM budget (§171).
- Radical Red / Unbound remain **inspiration only** — no asset/content copying.
