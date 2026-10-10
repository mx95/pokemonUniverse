#include "global.h"
#include "genesis_challenge.h"
#include "config/genesis.h"
#include "constants/flags.h"
#include "constants/species.h"
#include "constants/vars.h"
#include "constants/weather.h"
#include "constants/wild_encounter.h"
#include "constants/battle.h"
#include "event_data.h"
#include "field_weather.h"
#include "battle.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "wild_encounter.h"
#include "overworld.h"
#include "battle_script_commands.h"

bool32 Genesis_IsNuzlockeActive(void)
{
#if GENESIS_ENABLE_NUZLOCKE
    return FlagGet(FLAG_GENESIS_CHALLENGE_NUZLOCKE);
#else
    return FALSE;
#endif
}

bool32 Genesis_IsMonotypeActive(void)
{
#if GENESIS_ENABLE_MONOTYPE_CHALLENGE
    return FlagGet(FLAG_GENESIS_CHALLENGE_MONOTYPE);
#else
    return FALSE;
#endif
}

bool32 Genesis_SpeciesMatchesMonotype(enum Species species)
{
#if GENESIS_ENABLE_MONOTYPE_CHALLENGE
    u16 type;

    if (!Genesis_IsMonotypeActive())
        return TRUE;

    type = VarGet(VAR_GENESIS_MONOTYPE_TYPE);
    if (type == TYPE_NONE)
        return TRUE;

    return IsSpeciesOfType(species, type);
#else
    (void)species;
    return TRUE;
#endif
}

static bool32 Genesis_HasCaughtInMapSec(u32 mapsec)
{
    u32 i, box, pos;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE
         && GetMonData(&gPlayerParty[i], MON_DATA_MET_LOCATION) == mapsec)
            return TRUE;
    }

    for (box = 0; box < TOTAL_BOXES_COUNT; box++)
    {
        for (pos = 0; pos < IN_BOX_COUNT; pos++)
        {
            if (GetBoxMonDataAt(box, pos, MON_DATA_SPECIES) != SPECIES_NONE
             && GetBoxMonDataAt(box, pos, MON_DATA_MET_LOCATION) == mapsec)
                return TRUE;
        }
    }
    return FALSE;
}

bool32 Genesis_CanCatchWildMonNuzlocke(void)
{
#if GENESIS_ENABLE_NUZLOCKE
    if (!Genesis_IsNuzlockeActive())
        return TRUE;

    // Static / legend / totem / roamers are exempt (shared mapsecs + quest design).
    if (gBattleTypeFlags & (BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_ROAMER | BATTLE_TYPE_TRAINER))
        return TRUE;

    return !Genesis_HasCaughtInMapSec(GetCurrentRegionMapSectionId());
#else
    return TRUE;
#endif
}

bool32 Genesis_CanCatchWildMonMonotype(void)
{
#if GENESIS_ENABLE_MONOTYPE_CHALLENGE
    enum Species species;
    u32 battler;

    if (!Genesis_IsMonotypeActive())
        return TRUE;

    if (gBattleTypeFlags & (BATTLE_TYPE_LEGENDARY | BATTLE_TYPE_ROAMER | BATTLE_TYPE_TRAINER))
        return TRUE;

    battler = GetCatchingBattler();
    species = gBattleMons[battler].species;
    return Genesis_SpeciesMatchesMonotype(species);
#else
    return TRUE;
#endif
}

bool32 Genesis_CanCatchWildMon(void)
{
    return Genesis_CanCatchWildMonNuzlocke() && Genesis_CanCatchWildMonMonotype();
}

static void Genesis_CompactPartySlots(void)
{
    u32 i, j;

    for (i = 0; i < PARTY_SIZE - 1; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) == SPECIES_NONE)
        {
            for (j = i + 1; j < PARTY_SIZE; j++)
            {
                if (GetMonData(&gParties[B_TRAINER_PLAYER][j], MON_DATA_SPECIES) != SPECIES_NONE)
                {
                    gParties[B_TRAINER_PLAYER][i] = gParties[B_TRAINER_PLAYER][j];
                    ZeroMonData(&gParties[B_TRAINER_PLAYER][j]);
                    break;
                }
            }
        }
    }
}

void Genesis_NuzlockeOnWhiteOut(void)
{
#if GENESIS_ENABLE_NUZLOCKE
    u32 i;

    if (!Genesis_IsNuzlockeActive())
        return;

    // Fainted mons are gone for the rest of the run (no box transfer).
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) != SPECIES_NONE
         && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_HP) == 0)
            ZeroMonData(&gParties[B_TRAINER_PLAYER][i]);
    }
    Genesis_CompactPartySlots();
#endif
}

void Genesis_TryBiasWildMonIndex(const struct WildPokemon *wildPokemon, u8 *index, u8 count)
{
#if GENESIS_ENABLE_MONOTYPE_CHALLENGE
    u8 i;

    if (wildPokemon == NULL || index == NULL || count == 0)
        return;
    if (!Genesis_IsMonotypeActive())
        return;
    if (Genesis_SpeciesMatchesMonotype(wildPokemon[*index].species))
        return;

    for (i = 0; i < count; i++)
    {
        if (Genesis_SpeciesMatchesMonotype(wildPokemon[i].species))
        {
            *index = i;
            return;
        }
    }
#else
    (void)wildPokemon;
    (void)index;
    (void)count;
#endif
}

void Genesis_TryWeatherRareSlot(u8 *wildMonIndex, u8 area)
{
    u8 weather;

    if (wildMonIndex == NULL || area != WILD_AREA_LAND)
        return;

    weather = GetCurrentWeather();
    if ((weather == WEATHER_RAIN
      || weather == WEATHER_RAIN_THUNDERSTORM
      || weather == WEATHER_DOWNPOUR)
     && (Random() % 100) < 12)
    {
        *wildMonIndex = NUM_LAND_MONS_ENCOUNTER_SLOTS - 1;
    }
    else if ((weather == WEATHER_SUNNY || weather == WEATHER_SUNNY_CLOUDS)
          && (Random() % 100) < 8)
    {
        *wildMonIndex = NUM_LAND_MONS_ENCOUNTER_SLOTS - 2;
    }
}

void Genesis_SetMonotypeFromLead(void)
{
#if GENESIS_ENABLE_MONOTYPE_CHALLENGE
    enum Species species = GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES);

    if (species == SPECIES_NONE)
    {
        VarSet(VAR_GENESIS_MONOTYPE_TYPE, TYPE_NONE);
        return;
    }

    VarSet(VAR_GENESIS_MONOTYPE_TYPE, GetSpeciesType(species, 0));
#endif
}
