#include "global.h"
#include "genesis_story.h"
#include "config/genesis.h"
#include "constants/genesis.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/items.h"
#include "constants/species.h"
#include "event_data.h"
#include "item.h"
#include "starter_choose.h"

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
    if (FlagGet(FLAG_GENESIS_BADGE_17_GET)) count++;
    if (FlagGet(FLAG_GENESIS_BADGE_18_GET)) count++;
    return count;
}

void Genesis_UpdateLevelCap(void)
{
#if GENESIS_ENABLE_LEVEL_CAP
    static const u8 sCaps[] = {
        15, 18, 22, 26, 32, 36, 42, 48, 55, // 0-8 Hoenn badges
        58, 60, 62, 65, 68, 70, 72, 75,     // 9-16 eastern
        78, 80                              // 17-18 Poison / Ground
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

// VAR_0x8004 = town-mon quest index (0-31). Done bits live in QUEST_BITS / TOWNMON_HI.
void Genesis_TownMonIsDone(void)
{
    u32 index = gSpecialVar_0x8004;
    u16 bits;

    if (index < 16)
        bits = VarGet(VAR_GENESIS_QUEST_BITS);
    else
        bits = VarGet(VAR_GENESIS_TOWNMON_HI);

    gSpecialVar_Result = (bits & (1u << (index & 15))) != 0;
}

void Genesis_TownMonSetDone(void)
{
    u32 index = gSpecialVar_0x8004;
    u16 bits;
    u16 var;

    if (index < 16)
        var = VAR_GENESIS_QUEST_BITS;
    else
        var = VAR_GENESIS_TOWNMON_HI;

    bits = VarGet(var);
    bits |= (u16)(1u << (index & 15));
    VarSet(var, bits);
    gSpecialVar_Result = TRUE;
}

void Genesis_GiveStarterMegaStone(void)
{
    u16 species;
    enum Item stone = ITEM_NONE;

    if (FlagGet(FLAG_GENESIS_STARTER_MEGA_STONE))
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    species = GetStarterPokemon(VarGet(VAR_STARTER_MON));
    switch (species)
    {
    case SPECIES_BULBASAUR:  stone = ITEM_VENUSAURITE; break;
    case SPECIES_CHARMANDER: stone = ITEM_CHARIZARDITE_X; break;
    case SPECIES_SQUIRTLE:   stone = ITEM_BLASTOISINITE; break;
    case SPECIES_TREECKO:    stone = ITEM_SCEPTILITE; break;
    case SPECIES_TORCHIC:    stone = ITEM_BLAZIKENITE; break;
    case SPECIES_MUDKIP:     stone = ITEM_SWAMPERTITE; break;
    case SPECIES_CHIKORITA:  stone = ITEM_MEGANIUMITE; break;
    case SPECIES_TOTODILE:   stone = ITEM_FERALIGITE; break;
    case SPECIES_TEPIG:      stone = ITEM_EMBOARITE; break;
    case SPECIES_CHESPIN:    stone = ITEM_CHESNAUGHTITE; break;
    case SPECIES_FENNEKIN:   stone = ITEM_DELPHOXITE; break;
    case SPECIES_FROAKIE:    stone = ITEM_GRENINJITE; break;
    default:                 stone = ITEM_NONE; break;
    }

    if (stone == ITEM_NONE || !AddBagItem(stone, 1))
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    FlagSet(FLAG_GENESIS_STARTER_MEGA_STONE);
    gSpecialVar_0x8004 = stone;
    gSpecialVar_Result = TRUE;
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
