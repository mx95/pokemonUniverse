#ifndef GUARD_GENESIS_CHALLENGE_H
#define GUARD_GENESIS_CHALLENGE_H

#include "wild_encounter.h"

// GENESIS: Optional challenge-mode helpers (Nuzlocke / monotype)

void Genesis_NuzlockeOnWhiteOut(void);
bool32 Genesis_IsNuzlockeActive(void);
bool32 Genesis_IsMonotypeActive(void);
bool32 Genesis_SpeciesMatchesMonotype(enum Species species);
void Genesis_TryBiasWildMonIndex(const struct WildPokemon *wildPokemon, u8 *index, u8 count);
void Genesis_TryWeatherRareSlot(u8 *wildMonIndex, u8 area);
void Genesis_SetMonotypeFromLead(void);

#endif // GUARD_GENESIS_CHALLENGE_H
