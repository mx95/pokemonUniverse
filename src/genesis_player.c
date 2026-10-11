#include "global.h"
#include "genesis_player.h"
#include "config/genesis.h"
#include "constants/rgb.h"
#include "constants/vars.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "graphics.h"
#include "palette.h"
#include "sprite.h"

// Clothing color indices in Brendan/May object event palettes (see *.pal).
#define GENESIS_OUTFIT_CLOTH_START 5
#define GENESIS_OUTFIT_CLOTH_COUNT 4

enum {
    GENESIS_OUTFIT_DEFAULT = 0,
    GENESIS_OUTFIT_RED = 1,
    GENESIS_OUTFIT_BLUE = 2,
    GENESIS_OUTFIT_CHAMPION = 3,
};

// Fixed clothing shades (GBA 5-bit RGB) swapped onto indices 5-8.
static const u16 sOutfitClothes[][GENESIS_OUTFIT_CLOTH_COUNT] = {
    [GENESIS_OUTFIT_RED] = {
        RGB(31, 10, 8),
        RGB(24, 6, 5),
        RGB(16, 4, 3),
        RGB(10, 2, 2),
    },
    [GENESIS_OUTFIT_BLUE] = {
        RGB(12, 18, 31),
        RGB(8, 12, 26),
        RGB(5, 8, 20),
        RGB(3, 5, 14),
    },
    [GENESIS_OUTFIT_CHAMPION] = {
        RGB(31, 18, 26),
        RGB(28, 12, 20),
        RGB(22, 8, 16),
        RGB(14, 4, 10),
    },
};

static const u16 *Genesis_GetBasePlayerPalette(void)
{
    if (gSaveBlock2Ptr->playerGender == FEMALE)
        return gObjectEventPal_May;
    return gObjectEventPal_Brendan;
}

void Genesis_ApplyOutfitToPalette(u8 paletteNum)
{
    u16 outfit;
    u16 *unfaded;
    u16 *faded;
    const u16 *base;
    u32 i;

    if (paletteNum == 0xFF)
        return;

    base = Genesis_GetBasePlayerPalette();
    unfaded = &gPlttBufferUnfaded[OBJ_PLTT_ID(paletteNum)];
    faded = &gPlttBufferFaded[OBJ_PLTT_ID(paletteNum)];

    // Restore stock colors first so outfit swaps are idempotent.
    for (i = 0; i < 16; i++)
    {
        unfaded[i] = base[i];
        faded[i] = base[i];
    }

    outfit = VarGet(VAR_GENESIS_OUTFIT);
    if (outfit == GENESIS_OUTFIT_DEFAULT || outfit > GENESIS_OUTFIT_CHAMPION)
        return;

    for (i = 0; i < GENESIS_OUTFIT_CLOTH_COUNT; i++)
    {
        unfaded[GENESIS_OUTFIT_CLOTH_START + i] = sOutfitClothes[outfit][i];
        faded[GENESIS_OUTFIT_CLOTH_START + i] = sOutfitClothes[outfit][i];
    }
}

void Genesis_RefreshPlayerOutfit(void)
{
    u8 paletteNum = LoadPlayerObjectEventPalette(gSaveBlock2Ptr->playerGender);
    // LoadPlayerObjectEventPalette already applies outfit; call again after
    // forcing a restore path when the palette was already resident.
    Genesis_ApplyOutfitToPalette(paletteNum);
}
