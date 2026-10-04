#include "global.h"
#include "item.h"
#include "script.h"
#include "event_data.h"
#include "malloc.h"
#include "shop_criteria.h"
#include "constants/flags.h"

static EWRAM_DATA const u16 *sDynamicShopItemListRef = NULL;

static bool32 ShopCriteriaByBadgeCount(u32 count);
static bool32 ShopCriteriaByFlag(u32 flagId);
static UNUSED bool32 ShopCriteriaByVar(u32 varId, u32 varValue);

void TryBuildDynamicShopItemList(const u16 **ogItemList, u16 *resultingTotal)
{
    sDynamicShopItemListRef = *ogItemList;

    u16 *list = AllocZeroed((*resultingTotal + 1) * sizeof(u16));
    u32 overallIdx = 0, idx = 0;

    while (idx < *resultingTotal)
    {
        enum Item item = sDynamicShopItemListRef[idx];

        if (IsItemShopCriteriaFulfilled(item))
        {
            list[overallIdx] = item;
            overallIdx++;
        }

        idx++;
    }

    list[overallIdx] = ITEM_NONE;

    *ogItemList = list;
    *resultingTotal = overallIdx;
}

void TryFreeDynamicShopItemList(const u16 **ogItemList)
{
    Free((u16 *)*ogItemList);
    *ogItemList = sDynamicShopItemListRef;
}

static bool32 ShopCriteriaByBadgeCount(u32 count)
{
    u32 badgeCount = 0;
    u32 badgeFlag;

    for (badgeFlag = FLAG_BADGE01_GET; badgeFlag < FLAG_BADGE01_GET + NUM_BADGES; badgeFlag++)
    {
        if (FlagGet(badgeFlag))
            badgeCount++;
    }

    return badgeCount >= count;
}

static bool32 ShopCriteriaByFlag(u32 flagId)
{
    return FlagGet(flagId);
}

static UNUSED bool32 ShopCriteriaByVar(u32 varId, u32 varValue)
{
    return VarGet(varId) >= varValue;
}

bool32 ShopCriteria_Badge3(enum Item itemId)
{
    (void)itemId;
    return ShopCriteriaByBadgeCount(3);
}

bool32 ShopCriteria_Badge6(enum Item itemId)
{
    (void)itemId;
    return ShopCriteriaByBadgeCount(6);
}

bool32 ShopCriteria_GameClear(enum Item itemId)
{
    (void)itemId;
    return ShopCriteriaByFlag(FLAG_SYS_GAME_CLEAR);
}
