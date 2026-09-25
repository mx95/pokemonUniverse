#ifndef GUARD_GENESIS_FORM_H
#define GUARD_GENESIS_FORM_H

// GENESIS: Data-driven Genesis Form battle mechanic (Phase G).
// Enabled only when GENESIS_ENABLE_GENESIS_FORM is TRUE.
// Do not hardcode per-species switch logic — use tables below.

#include "config/genesis.h"

#define GENESIS_FORM_NUM_STATS 6

struct GenesisFormEntry
{
    u16 species;              // Base species eligible for Genesis Form
    u16 formSpecies;          // Target form species ID (or SPECIES_NONE if overlay-only)
    u8 type1;
    u8 type2;
    u16 ability;
    s8 statChanges[GENESIS_FORM_NUM_STATS]; // Temporary battle stat stage deltas
    u16 durationTurns;        // 0 = until switch / faint / end of battle
    u16 activationItem;       // ITEM_NONE if flag/script gated
    u16 gfxId;                // Optional visual override index
};

#if GENESIS_ENABLE_GENESIS_FORM
extern const struct GenesisFormEntry gGenesisFormTable[];
extern const u16 gGenesisFormTableCount;

const struct GenesisFormEntry *GetGenesisFormEntry(u16 species);
bool32 CanActivateGenesisForm(u16 species);
#else
static inline const struct GenesisFormEntry *GetGenesisFormEntry(u16 species) { (void)species; return NULL; }
static inline bool32 CanActivateGenesisForm(u16 species) { (void)species; return FALSE; }
#endif

#endif // GUARD_GENESIS_FORM_H
