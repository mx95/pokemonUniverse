# Genesis validation & smoke tests

Run from the repo root after building when possible.

## Quick start

```bash
# Static checks (pokedex, branding, configs, ROM header) — seconds
python3 tools/genesis/run_smoke_tests.py
# or
make genesis-check

# Also run a filtered Expansion battle ROM test (WSL + ARM toolchain)
python3 tools/genesis/run_smoke_tests.py --with-rom-tests
# or
make genesis-check-rom
```

## Individual validators

| Script | What it proves |
|--------|----------------|
| `validate_pokedex.py` | Gen 1–9 enabled; Genesis legendaries exist |
| `validate_branding.py` | Early Aurelia names; no PROF. BIRCH / HOENN / PETALBURG CITY in starter loop dialogue |
| `validate_config.py` | DS-style sprites, Gen5 pop-ups, followers, type UI, splash skipped |
| `validate_rom.py` | `pokemonGenesis.gba` header is `POKEMON GENE` / `BPEE` and sized correctly |

## Expansion ROM tests

Full suite (long):

```bash
make check-tools
make check -j$(nproc)
```

Smoke subset used by `--with-rom-tests`:

```bash
make check -j8 TESTS=Spikes
```
