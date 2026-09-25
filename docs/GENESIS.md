# Pokémon Genesis

Original GBA Pokémon RPG built on **pokeemerald-expansion**.

## Base

| Field | Value |
|-------|-------|
| Upstream | [rh-hideout/pokeemerald-expansion](https://github.com/rh-hideout/pokeemerald-expansion) |
| Pinned tag | `expansion/1.17.0` |
| Commit | `e8bd1cd7b03fc032ea37e3ecd38b379b5d01a1e7` |
| Local branch | `genesis/base` |
| HnS archive | `archive/heart-and-soul` (Pokémon Heart & Soul / Modern Emerald) |

**Do not** sync Heart & Soul Johto maps/scripts into this tree as the Genesis world.

Radical Red and Unbound are **design references only**. Do not copy their assets, maps, characters, dialogue, or proprietary content.

## Build

Requires pret Expansion toolchain (see `INSTALL.md`). On Windows, use WSL2 Ubuntu.

```bash
make -j$(nproc)
```

Output ROM: `pokemonGenesis.gba` (Genesis branding; Expansion default was `pokeemerald.gba`).

**Verified:** `expansion/1.17.0` (`e8bd1cd7b0`) builds successfully to `pokemonGenesis.gba` (~32 MB) on WSL2 Ubuntu with `gcc-arm-none-eabi`.

## Custom isolation

| Concern | Location |
|---------|----------|
| Feature flags | `include/config/genesis.h` |
| Story / region docs | `docs/STORY.md`, `docs/REGION_AURELIA.md` |
| Bugs | `docs/BUGS.md` |
| Feature status board | `docs/PROJECT_STATUS.md` |
| Ultimate wishlist (QoL/world/endgame) | Captured in `PROJECT_STATUS.md`; implement by priority groups only |
| Genesis Form (planned) | data-driven tables under `src/data/genesis/` |
| Comment marker | `// GENESIS:` |

Prefer existing Expansion APIs under `include/config/`, battle systems, species data, DexNav, followers, and Battle Frontier.

## Implementation order (Ultimate Spec §172 / §179)

1. **Priority 1:** Core maps, story, 16 gyms, save, battle gates, essential QoL  
2. **Priority 2:** DexNav polish, quests, Frontier, postgame services, customization  
3. **Priority 3:** Achievements extras, contests, secret bases, photo, cooking, NG+  

After each feature group: compile → test ROM → commit → update `PROJECT_STATUS.md` → update `BUGS.md` if needed.

## Branch map

| Branch | Purpose |
|--------|---------|
| `genesis/base` | Pinned Expansion + Genesis scaffold |
| `genesis/pokemon-data` | Species / forms / legendaries |
| `genesis/battle` | Battle config / difficulty |
| `genesis/gimmicks` | Story gimmick gates |
| `genesis/genesis-form` | Genesis Form framework |
| `genesis/story` | Story scripts / flags |
| `genesis/maps` | Aurelia maps |
| `genesis/trainers` | Gyms / Eclipse / League |
| `genesis/postgame` | Postgame / Frontier missions |
| `genesis/testing` | Validation scripts / tests |

## Design rules

1. Never rewrite Expansion battle gimmicks that already exist.
2. Never invent APIs before searching the repo.
3. Compile after significant changes; do not claim features complete without a ROM build + playtest.
4. Quality over feature count.
