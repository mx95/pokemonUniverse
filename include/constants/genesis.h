#ifndef GUARD_CONSTANTS_GENESIS_H
#define GUARD_CONSTANTS_GENESIS_H

// GENESIS: Story / world constants and reserved flag block documentation.
// Wire concrete FLAG_/VAR_ IDs as story scripts are authored (genesis/story).

// Story act markers (script-facing documentation; use event flags when implemented)
#define GENESIS_ACT_INTRO           1
#define GENESIS_ACT_BADGES_1_3      2
#define GENESIS_ACT_ANCIENT         3
#define GENESIS_ACT_Z_DYNAMAX       4
#define GENESIS_ACT_ASTRAL          5
#define GENESIS_ACT_ENGINE          6
#define GENESIS_ACT_LABORATORY      7
#define GENESIS_ACT_RESOLUTION      8

// Team Eclipse captain IDs (for trainer / dialogue routing)
#define ECLIPSE_CAPTAIN_NOVA        1
#define ECLIPSE_CAPTAIN_ARC         2
#define ECLIPSE_CAPTAIN_FORGE       3
#define ECLIPSE_CAPTAIN_PRISM       4
#define ECLIPSE_CAPTAIN_ORIGIN      5

// Difficulty modes (runtime; map to Expansion trainer difficulty var when enabled)
#define GENESIS_DIFFICULTY_EASY     0
#define GENESIS_DIFFICULTY_NORMAL   1
#define GENESIS_DIFFICULTY_HARD     2
#define GENESIS_DIFFICULTY_EXPERT   3

#endif // GUARD_CONSTANTS_GENESIS_H
