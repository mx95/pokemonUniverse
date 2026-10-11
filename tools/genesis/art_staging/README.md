# Genesis art staging

SpriteCook (and other) exports land here before GBA conversion.

| File | Species | Notes |
|------|---------|-------|
| `aethernox_front.png` | Aethernox | Stage for unique front sheet (currently DS Giratina Origin + palette) |
| `solara_front.png` | Solara | Stage for unique front sheet (currently DS Reshiram + palette) |
| `genesis_front.png` | Genesis | Stage for unique front sheet (currently DS Arceus + palette) |

Conversion into `graphics/pokemon/{species}/` needs palette reduction (16 colors), nearest-neighbor resize to the Expansion front size, and anim/front.png wiring in `genesis_legendaries.h`. Do not copy third-party Pokémon geometry.
