#ifndef GUARD_CONFIG_GENESIS_H
#define GUARD_CONFIG_GENESIS_H

// GENESIS: Master feature flags for Pokémon Genesis custom systems.
// Prefer Expansion configs (include/config/*.h) for upstream features.
// Only add Genesis-specific toggles here.

// --- Core identity ---------------------------------------------------------
#define GENESIS_PROJECT                     TRUE
#define GENESIS_SAVE_VERSION                1

// --- World / progression ---------------------------------------------------
#define GENESIS_ENABLE_LEVEL_SCALING        FALSE   // Thin wrapper; hand-authored story bosses stay fixed
#define GENESIS_ENABLE_LEVEL_CAP            FALSE   // Uses Expansion caps.h when enabled
#define GENESIS_ENABLE_GYM_REMATCHES        FALSE
#define GENESIS_ENABLE_QUEST_LOG            FALSE
#define GENESIS_ENABLE_ACHIEVEMENTS         FALSE

// --- Overworld QoL (wrappers around Expansion where needed) ----------------
#define GENESIS_ENABLE_FOLLOWERS            TRUE    // Mirrors OW_FOLLOWERS_ENABLED enablement
#define GENESIS_ENABLE_AUTOSAVE             FALSE
#define GENESIS_ENABLE_AUTO_REPEL           TRUE    // Uses Expansion I_REPEL_LURE_MENU + last-used var
#define GENESIS_ENABLE_DEXNAV               TRUE    // Requires DN_* flags/vars in dexnav.h
#define GENESIS_ENABLE_FAST_TRAVEL          FALSE

// --- Battle / gimmicks -----------------------------------------------------
#define GENESIS_ENABLE_FAST_BATTLE          TRUE    // Prefer Expansion B_FAST_* settings
#define GENESIS_ENABLE_TYPE_INDICATORS      TRUE    // Prefer Expansion B_SHOW_EFFECTIVENESS
#define GENESIS_ENABLE_EXP_SHARE            TRUE    // Prefer Expansion I_EXP_SHARE_FLAG
#define GENESIS_ENABLE_GENESIS_FORM         FALSE   // Custom data-driven form system (Phase G)
#define GENESIS_ONE_GIMMICK_PER_STORY_BATTLE TRUE  // Story rule; Chaos Battles override postgame
#define GENESIS_ENABLE_CHAOS_BATTLES        FALSE

// --- Endgame ---------------------------------------------------------------
#define GENESIS_ENABLE_BATTLE_FRONTIER      TRUE    // Use Expansion Frontier facilities
#define GENESIS_ENABLE_WORLD_TOURNAMENT     FALSE
#define GENESIS_ENABLE_POSTGAME             FALSE

// --- Gimmick story unlock badges (1-indexed gym badge count) ---------------
#define GENESIS_BADGE_UNLOCK_MEGA           4
#define GENESIS_BADGE_UNLOCK_Z_MOVES        7
#define GENESIS_BADGE_UNLOCK_DYNAMAX        8
#define GENESIS_BADGE_UNLOCK_TERA           12

#endif // GUARD_CONFIG_GENESIS_H
