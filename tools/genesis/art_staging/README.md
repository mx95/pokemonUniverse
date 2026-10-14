# Genesis art staging

SpriteCook (and other) exports land here before GBA conversion.

| File | Species | Notes |
|------|---------|-------|
| `aethernox_front.png` | Aethernox | Stage for unique front sheet (currently DS Giratina Origin + palette) |
| `solara_front.png` | Solara | Stage for unique front sheet (currently DS Reshiram + palette) |
| `genesis_front.png` | Genesis | Stage for unique front sheet (currently DS Arceus + palette) |

Converted into the ROM via `python3 tools/genesis/convert_staged_legend_fronts.py`
→ `graphics/pokemon/{species}/anim_front.png` + `back.png` + pals, wired in
`src/data/graphics/pokemon.h` and `genesis_legendaries.h`.

Party icons + overworld sheets are derived from battle fronts via
`python3 tools/genesis/make_legend_icon_ow.py` (not third-party geometry).
