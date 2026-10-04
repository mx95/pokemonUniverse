#include "global.h"
#include "genesis_story.h"
#include "config/genesis.h"
#include "constants/genesis.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/items.h"
#include "event_data.h"
#include "item.h"

// GENESIS: Story helper specials (expand as acts are authored).
// Keep story logic out of upstream battle systems.

u32 Genesis_GetGimmickUnlockBadge(u32 gimmickId)
{
    switch (gimmickId)
    {
    case 1: // Mega
        return GENESIS_BADGE_UNLOCK_MEGA;
    case 2: // Z-Moves
        return GENESIS_BADGE_UNLOCK_Z_MOVES;
    case 3: // Dynamax
        return GENESIS_BADGE_UNLOCK_DYNAMAX;
    case 4: // Terastallization
        return GENESIS_BADGE_UNLOCK_TERA;
    default:
        return 0;
    }
}

void Genesis_ApplyBattleGimmickFlags(void)
{
    if (FlagGet(FLAG_GENESIS_DYNAMAX_UNLOCKED))
        FlagSet(FLAG_SYS_DYNAMAX_BATTLE);

    if (FlagGet(FLAG_GENESIS_TERA_UNLOCKED))
    {
        FlagSet(FLAG_SYS_TERA_ORB_CHARGED);
        FlagSet(FLAG_SYS_TERA_ORB_NO_COST);
    }
}

static u32 Genesis_CountBadges(void)
{
    u32 count = 0;
    if (FlagGet(FLAG_BADGE01_GET)) count++;
    if (FlagGet(FLAG_BADGE02_GET)) count++;
    if (FlagGet(FLAG_BADGE03_GET)) count++;
    if (FlagGet(FLAG_BADGE04_GET)) count++;
    if (FlagGet(FLAG_BADGE05_GET)) count++;
    if (FlagGet(FLAG_BADGE06_GET)) count++;
    if (FlagGet(FLAG_BADGE07_GET)) count++;
    if (FlagGet(FLAG_BADGE08_GET)) count++;
    if (FlagGet(FLAG_GENESIS_BADGE_09_GET)) count++;
    if (FlagGet(FLAG_GENESIS_BADGE_10_GET)) count++;
    if (FlagGet(FLAG_GENESIS_BADGE_11_GET)) count++;
    if (FlagGet(FLAG_GENESIS_BADGE_12_GET)) count++;
    if (FlagGet(FLAG_GENESIS_BADGE_13_GET)) count++;
    if (FlagGet(FLAG_GENESIS_BADGE_14_GET)) count++;
    if (FlagGet(FLAG_GENESIS_BADGE_15_GET)) count++;
    if (FlagGet(FLAG_GENESIS_BADGE_16_GET)) count++;
    return count;
}

void Genesis_UpdateLevelCap(void)
{
#if GENESIS_ENABLE_LEVEL_CAP
    static const u8 sCaps[] = {
        15, 18, 22, 26, 32, 36, 42, 48, 55, // 0-8 Hoenn badges
        58, 60, 62, 65, 68, 70, 72, 75      // 9-16 eastern
    };
    u32 badges = Genesis_CountBadges();
    u32 cap;

    if (FlagGet(FLAG_SYS_GAME_CLEAR))
        cap = 100;
    else if (badges >= ARRAY_COUNT(sCaps))
        cap = sCaps[ARRAY_COUNT(sCaps) - 1];
    else
        cap = sCaps[badges];

    VarSet(VAR_GENESIS_LEVEL_CAP, cap);
#else
    VarSet(VAR_GENESIS_LEVEL_CAP, 100);
#endif
}

void Genesis_InitSave(void)
{
    if (!FlagGet(FLAG_GENESIS_SAVE_INIT))
    {
        VarSet(VAR_GENESIS_SAVE_VERSION, GENESIS_SAVE_VERSION);
        VarSet(VAR_GENESIS_DIFFICULTY, GENESIS_DIFFICULTY_NORMAL);
        FlagSet(FLAG_GENESIS_SAVE_INIT);
    }
    Genesis_UpdateLevelCap();
}

void Genesis_TryUnlockGenesisForm(void)
{
    if (FlagGet(FLAG_GENESIS_DEFEATED_AETHERNOX)
     && FlagGet(FLAG_GENESIS_DEFEATED_SOLARA)
     && FlagGet(FLAG_GENESIS_DEFEATED_GENESIS_MON))
    {
        FlagSet(FLAG_GENESIS_FORM_UNLOCKED);
        FlagSet(FLAG_GENESIS_ACHIEVEMENT_LEGENDS);
        VarSet(VAR_GENESIS_STORY_STATE, GENESIS_STORY_LEGENDS_DONE);
    }
}

void Genesis_GetWTRuleIndex(void)
{
    gSpecialVar_Result = VarGet(VAR_DAYS) % 3;
}

void Genesis_OnGameClear(void)
{
    bool32 firstClear = !FlagGet(FLAG_GENESIS_CHAMPION_DONE);

    FlagSet(FLAG_GENESIS_CHAMPION_DONE);
    FlagSet(FLAG_GENESIS_ACHIEVEMENT_CHAMPION);
    FlagSet(FLAG_GENESIS_ACT8_DONE);
    FlagSet(FLAG_GENESIS_TERA_UNLOCKED);
    FlagSet(FLAG_GENESIS_ECLIPSE_DEFEATED);
    FlagSet(FLAG_GENESIS_ACHIEVEMENT_ECLIPSE);
    FlagSet(FLAG_GENESIS_ECLIPSE_ARCHIVE_OPEN);
    FlagSet(FLAG_GENESIS_EASTERN_OPEN);
    VarSet(VAR_GENESIS_STORY_STATE, GENESIS_STORY_POSTGAME);
    VarSet(VAR_GENESIS_SAVE_VERSION, GENESIS_SAVE_VERSION);
    Genesis_UpdateLevelCap();

    if (firstClear && !CheckBagHasItem(ITEM_TERA_ORB, 1))
        AddBagItem(ITEM_TERA_ORB, 1);

    FlagSet(FLAG_SYS_TERA_ORB_CHARGED);
    FlagSet(FLAG_SYS_TERA_ORB_NO_COST);
}
