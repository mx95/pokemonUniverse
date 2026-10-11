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

// Clothing / accent indices in Brendan/May object event palettes (see *.pal).
#define GENESIS_OUTFIT_CLOTH_START 5
#define GENESIS_OUTFIT_CLOTH_COUNT 4
#define GENESIS_OUTFIT_ACCENT_A 9   // bag / light trim
#define GENESIS_OUTFIT_ACCENT_B 10  // secondary accent
#define GENESIS_OUTFIT_ACCENT_C 11
#define GENESIS_OUTFIT_ACCENT_D 12
#define GENESIS_OUTFIT_ACCENT_E 13

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

// Accents (hat/bag/trim) for stronger OW read at a glance.
static const u16 sOutfitAccents[][5] = {
    [GENESIS_OUTFIT_RED] = {
        RGB(31, 28, 12), // gold trim
        RGB(28, 22, 6),
        RGB(20, 14, 4),
        RGB(31, 14, 6),
        RGB(22, 8, 4),
    },
    [GENESIS_OUTFIT_BLUE] = {
        RGB(20, 28, 31), // ice trim
        RGB(10, 22, 28),
        RGB(6, 14, 22),
        RGB(8, 20, 31),
        RGB(4, 12, 24),
    },
    [GENESIS_OUTFIT_CHAMPION] = {
        RGB(31, 31, 24), // champion gold/white
        RGB(31, 26, 10),
        RGB(28, 20, 8),
        RGB(31, 22, 28),
        RGB(24, 12, 20),
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

    unfaded[GENESIS_OUTFIT_ACCENT_A] = sOutfitAccents[outfit][0];
    faded[GENESIS_OUTFIT_ACCENT_A] = sOutfitAccents[outfit][0];
    unfaded[GENESIS_OUTFIT_ACCENT_B] = sOutfitAccents[outfit][1];
    faded[GENESIS_OUTFIT_ACCENT_B] = sOutfitAccents[outfit][1];
    unfaded[GENESIS_OUTFIT_ACCENT_C] = sOutfitAccents[outfit][2];
    faded[GENESIS_OUTFIT_ACCENT_C] = sOutfitAccents[outfit][2];
    unfaded[GENESIS_OUTFIT_ACCENT_D] = sOutfitAccents[outfit][3];
    faded[GENESIS_OUTFIT_ACCENT_D] = sOutfitAccents[outfit][3];
    unfaded[GENESIS_OUTFIT_ACCENT_E] = sOutfitAccents[outfit][4];
    faded[GENESIS_OUTFIT_ACCENT_E] = sOutfitAccents[outfit][4];
}

void Genesis_RefreshPlayerOutfit(void)
{
    u8 paletteNum = LoadPlayerObjectEventPalette(gSaveBlock2Ptr->playerGender);
    // LoadPlayerObjectEventPalette already applies outfit; call again after
    // forcing a restore path when the palette was already resident.
    Genesis_ApplyOutfitToPalette(paletteNum);
}
