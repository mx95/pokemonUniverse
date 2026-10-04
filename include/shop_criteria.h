#ifndef GUARD_SHOP_CRITERIA_H
#define GUARD_SHOP_CRITERIA_H

#include "item.h"

void TryBuildDynamicShopItemList(const u16 **ogItemList, u16 *resultingTotal);
void TryFreeDynamicShopItemList(const u16 **ogItemList);

// GENESIS: progressive Mart unlocks
bool32 ShopCriteria_Badge3(enum Item itemId);
bool32 ShopCriteria_Badge6(enum Item itemId);
bool32 ShopCriteria_GameClear(enum Item itemId);

#endif // GUARD_SHOP_CRITERIA_H
