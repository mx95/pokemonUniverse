#ifndef GUARD_CONFIG_GENESIS_H
#define GUARD_CONFIG_GENESIS_H

// GENESIS: Master feature flags for Pokémon Genesis custom systems.
// Prefer Expansion configs (include/config/*.h) for upstream features.
// Only add Genesis-specific toggles here.

// --- Core identity ---------------------------------------------------------
#define GENESIS_PROJECT                     TRUE
#define GENESIS_SAVE_VERSION                6 // +Poison/Ground gyms; town-mon bitfields; type coverage

// --- World / progression ---------------------------------------------------
#define GENESIS_ENABLE_LEVEL_SCALING        FALSE   // Thin wrapper; hand-authored story bosses stay fixed
#define GENESIS_ENABLE_LEVEL_CAP            TRUE    // Uses Expansion caps.h + VAR_GENESIS_LEVEL_CAP
#define GENESIS_ENABLE_GYM_REMATCHES        TRUE
#define GENESIS_ENABLE_QUEST_LOG            TRUE    // Lightweight quest board NPC
#define GENESIS_ENABLE_ACHIEVEMENTS         TRUE    // Flag-based unlocks (e.g. Verdant Ace)
#define GENESIS_ENABLE_RANDOMIZER           FALSE   // Optional; wild remap not wired yet
#define GENESIS_ENABLE_NUZLOCKE             TRUE    // Whiteout releases fainted party mons
#define GENESIS_ENABLE_MONOTYPE_CHALLENGE   TRUE    // Flag + type var; catch filter later
#define GENESIS_ENABLE_DAMAGE_DISPLAY       FALSE   // Competitive / simulator UI only
#define GENESIS_ENABLE_QUEST_MARKERS        FALSE   // Optional; never forced

// --- Overworld QoL (wrappers around Expansion where needed) ----------------
#define GENESIS_ENABLE_FOLLOWERS            TRUE    // Mirrors OW_FOLLOWERS_ENABLED enablement
#define GENESIS_ENABLE_AUTOSAVE             FALSE
#define GENESIS_ENABLE_AUTO_REPEL           TRUE    // Uses Expansion I_REPEL_LURE_MENU + last-used var
#define GENESIS_ENABLE_DEXNAV               TRUE    // Lab grants search + detector (FLAG_SYS_DEXNAV_*)
#define GENESIS_ENABLE_FAST_TRAVEL          TRUE    // Smart Fly via OW_FLAG_POKE_RIDER = FLAG_RECEIVED_HM_FLY

// --- Battle / gimmicks -----------------------------------------------------
#define GENESIS_ENABLE_FAST_BATTLE          TRUE    // Prefer Expansion B_FAST_* settings
#define GENESIS_ENABLE_TYPE_INDICATORS      TRUE    // Prefer Expansion B_SHOW_EFFECTIVENESS
#define GENESIS_ENABLE_EXP_SHARE            TRUE    // Prefer Expansion I_EXP_SHARE_FLAG
#define GENESIS_ENABLE_GENESIS_FORM         TRUE    // Switch-in overlay when FLAG_GENESIS_FORM_UNLOCKED
#define GENESIS_ONE_GIMMICK_PER_STORY_BATTLE TRUE  // Story rule; Chaos Battles override postgame
#define GENESIS_ENABLE_CHAOS_BATTLES        FALSE

// --- Endgame ---------------------------------------------------------------
#define GENESIS_ENABLE_BATTLE_FRONTIER      TRUE    // Use Expansion Frontier facilities
#define GENESIS_ENABLE_WORLD_TOURNAMENT     TRUE  // Tower lobby 3-round bracket + rematch
#define GENESIS_ENABLE_POSTGAME             TRUE

// --- Gimmick story unlock badges (1-indexed gym badge count) ---------------
#define GENESIS_BADGE_UNLOCK_MEGA           3  // Volt (Mauville / BADGE03) on 8-badge stand-in
#define GENESIS_BADGE_UNLOCK_Z_MOVES        7  // Skye (Mossdeep / BADGE07)
#define GENESIS_BADGE_UNLOCK_DYNAMAX        8  // Titan (Sootopolis / BADGE08)
#define GENESIS_BADGE_UNLOCK_TERA           0  // Postgame (Hall of Fame), not a badge

#endif // GUARD_CONFIG_GENESIS_H
