# Pokémon Roster — Genesis

## Official species (Gen 1–9)

On `genesis/base` (pokeemerald-expansion **1.17.0**), **all** `P_GEN_1`–`P_GEN_9` families and form toggles are already `TRUE`.

Battle sprites use Expansion's **Gen 4/5 DS-style** art by default (`P_GBA_STYLE_SPECIES_GFX FALSE`). That is the closest “3D” look the GBA supports—there is no real 3D renderer. Overworld map pop-ups use Gen 5 / B2W2 style (`OW_POPUP_GENERATION GEN_5`).

**Do not copy sprites or data from Radical Red, Unbound, or other ROM hacks.**

## Original Genesis legendaries

| Species ID | Types | Interim DS-style art | Unique art |
|------------|-------|----------------------|------------|
| `SPECIES_AETHERNOX` | Dragon/Dark | Giratina (Altered) stand-in | Planned |
| `SPECIES_SOLARA` | Psychic/Fire | Reshiram stand-in | Planned |
| `SPECIES_GENESIS` | Normal/Mystery | Arceus stand-in | Planned |

Concept reference: `docs/art/genesis_legendaries_concept.png`

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
- **Route 2 (Route 102):** multi-gen grass/field (Shinx, elemental monkeys, Flabébé, Cutiefly, Blipbug, Nymble, …)
- **Lumen Forest (Petalburg Woods):** multi-gen forest (Budew, Sewaddle, Foongus, Scatterbug, Fomantis, Skwovet, Shroodle, …)
- Remaining routes: still Expansion Hoenn tables until remapped for Aurelia

Long-term: every obtainable species should appear via wild, gift, trade, quest, Frontier, or postgame hunt — tracked in `docs/PROJECT_STATUS.md`.

## Validation

```bash
python3 tools/genesis/validate_pokedex.py
```
