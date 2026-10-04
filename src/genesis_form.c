#include "global.h"
#include "genesis_form.h"
#include "constants/species.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/flags.h"
#include "constants/battle.h"
#include "event_data.h"
#include "battle.h"
#include "battle_scripts.h"
#include "battle_util.h"
#include "pokemon.h"
#include "constants/pokemon.h"

// GENESIS: Data-driven Genesis Form — switch-in overlay (types/ability/stats).

#if GENESIS_ENABLE_GENESIS_FORM

const struct GenesisFormEntry gGenesisFormTable[] =
{
    {
        .species = SPECIES_GENESIS,
        .formSpecies = SPECIES_GENESIS, // overlay-only (no permanent species swap)
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_MYSTERY,
        .ability = ABILITY_PROTEAN,
        .statChanges = {0, 1, 1, 1, 1, 1}, // HP unused; +1 Atk/Def/SpA/SpD/Spe
        .durationTurns = 0,
        .activationItem = ITEM_NONE,
        .gfxId = 0,
    },
};

const u16 gGenesisFormTableCount = ARRAY_COUNT(gGenesisFormTable);

const struct GenesisFormEntry *GetGenesisFormEntry(u16 species)
{
    u16 i;
    for (i = 0; i < gGenesisFormTableCount; i++)
    {
        if (gGenesisFormTable[i].species == species)
            return &gGenesisFormTable[i];
    }
    return NULL;
}

bool32 CanActivateGenesisForm(u16 species)
{
    if (!FlagGet(FLAG_GENESIS_FORM_UNLOCKED))
        return FALSE;
    return GetGenesisFormEntry(species) != NULL;
}

bool32 TryGenesisFormActivation(u32 battler)
{
    const struct GenesisFormEntry *entry;
    struct PartyState *partyState;
    u32 i;
    s8 stage;

    if (GetBattlerSide(battler) != B_SIDE_PLAYER)
        return FALSE;

    entry = GetGenesisFormEntry(gBattleMons[battler].species);
    if (entry == NULL || !CanActivateGenesisForm(gBattleMons[battler].species))
        return FALSE;

    partyState = GetBattlerPartyState(battler);
    if (partyState == NULL || partyState->genesisFormActive)
        return FALSE;

    partyState->genesisFormActive = TRUE;

    gBattleMons[battler].types[0] = entry->type1;
    gBattleMons[battler].types[1] = entry->type2;
    gBattleMons[battler].types[2] = TYPE_MYSTERY;
    gBattleMons[battler].ability = entry->ability;

    for (i = STAT_ATK; i < NUM_STATS; i++)
    {
        stage = gBattleMons[battler].statStages[i] + entry->statChanges[i];
        if (stage < MIN_STAT_STAGE)
            stage = MIN_STAT_STAGE;
        if (stage > MAX_STAT_STAGE)
            stage = MAX_STAT_STAGE;
        gBattleMons[battler].statStages[i] = stage;
    }

    gBattleScripting.battler = battler;
    gBattlerAbility = battler;
    gLastUsedAbility = entry->ability;
    BattleScriptCall(BattleScript_AbilityPopUp);
    return TRUE;
}

#endif // GENESIS_ENABLE_GENESIS_FORM
