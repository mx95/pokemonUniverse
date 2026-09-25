#include "global.h"
#include "genesis_form.h"

// GENESIS: Placeholder table — populate per species as content is authored.
// Keep this data-driven; do not add giant switch statements.

#if GENESIS_ENABLE_GENESIS_FORM

const struct GenesisFormEntry gGenesisFormTable[] =
{
    // Example stub (disabled until species exist):
    // {
    //     .species = SPECIES_NONE,
    //     .formSpecies = SPECIES_NONE,
    //     .type1 = TYPE_NORMAL,
    //     .type2 = TYPE_MYSTERY,
    //     .ability = ABILITY_NONE,
    //     .statChanges = {0},
    //     .durationTurns = 3,
    //     .activationItem = ITEM_NONE,
    //     .gfxId = 0,
    // },
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
    return GetGenesisFormEntry(species) != NULL;
}

#endif // GENESIS_ENABLE_GENESIS_FORM
