# Pokémon Roster — Genesis

## Official species (Gen 1–9)

On `genesis/base` (pokeemerald-expansion **1.17.0**), **all** `P_GEN_1`–`P_GEN_9` families and form toggles are already `TRUE`:

- Mega / Primal / Ultra Burst / Gigantamax / Tera forms
- Regional forms (Alolan, Galarian, Hisuian, Paldean)
- Cross-gen evolutions
- Pikachu extra forms

**Do not copy sprites or data from Radical Red, Unbound, or other ROM hacks.** Expansion already ships battle, icon, overworld, and cry assets for the modern National Dex.

Missing overworld art (if any) falls back to the Substitute / question-mark placeholder (`OW_SUBSTITUTE_PLACEHOLDER`).

## Original Genesis legendaries

| Species ID | Types | Role | Graphics status |
|------------|-------|------|-----------------|
| `SPECIES_AETHERNOX` | Dragon/Dark | Chaos | Placeholder (question mark) |
| `SPECIES_SOLARA` | Psychic/Fire | Creation | Placeholder (question mark) |
| `SPECIES_GENESIS` | Normal/Mystery | Potential / energy source | Placeholder (question mark) |

Data lives in `src/data/pokemon/species_info/genesis_legendaries.h`.

### Custom art pipeline (when ready)

1. Author 64×64 front/back + palettes under `graphics/pokemon/<name>/`
2. Add `INCGFX_*` declarations in `src/data/graphics/pokemon.h`
3. Point `.frontPic` / `.backPic` / `.palette` / `.iconSprite` / OVERWORLD at the new assets
4. Optional: unique cry sample under `sound/direct_sound_samples/cries/`
5. Rebuild and verify in the summary sprite visualizer (Select on Summary)

Concept references (non-ROM): see generated design notes in chat / art brief — not shipping proprietary third-party sprites.

## Wild availability

Database availability ≠ route availability. Encounters are being expanded per map as Aurelia is authored.

- **Route 1 (Route 101):** multi-gen early birds/field mons (Gen 2–9 samples) mixed with Hoenn early species
- Remaining routes: still Expansion Hoenn tables until remapped for Aurelia

Long-term: every obtainable species should appear via wild, gift, trade, quest, Frontier, or postgame hunt — tracked in `docs/PROJECT_STATUS.md`.

## Validation

```bash
python3 tools/genesis/validate_pokedex.py
```
