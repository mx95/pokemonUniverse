#ifndef GUARD_GENESIS_STORY_H
#define GUARD_GENESIS_STORY_H

// GENESIS: Story helper API

u32 Genesis_GetGimmickUnlockBadge(u32 gimmickId);
void Genesis_ApplyBattleGimmickFlags(void);
void Genesis_OnGameClear(void);
void Genesis_InitSave(void);
void Genesis_UpdateLevelCap(void);
void Genesis_TryUnlockGenesisForm(void);

#endif // GUARD_GENESIS_STORY_H
