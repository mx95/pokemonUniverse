#include "global.h"
#include "genesis_story.h"
#include "config/genesis.h"
#include "constants/genesis.h"

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
