#ifndef GUARD_CONSTANTS_GENESIS_H
#define GUARD_CONSTANTS_GENESIS_H

// GENESIS: Story / world constants.
// FLAG_GENESIS_* / VAR_GENESIS_STORY_STATE are defined in flags.h / vars.h.

// Story act markers (high-level documentation / script comparisons)
#define GENESIS_ACT_INTRO           1
#define GENESIS_ACT_BADGES_1_3      2
#define GENESIS_ACT_ANCIENT         3
#define GENESIS_ACT_Z_DYNAMAX       4
#define GENESIS_ACT_ASTRAL          5
#define GENESIS_ACT_ENGINE          6
#define GENESIS_ACT_LABORATORY      7
#define GENESIS_ACT_RESOLUTION      8

// VAR_GENESIS_STORY_STATE values (stand-in full path)
#define GENESIS_STORY_START             0
#define GENESIS_STORY_FOREST_COMPLETE   1
#define GENESIS_STORY_GYM1_READY        2
#define GENESIS_STORY_GYM1_DONE         3
#define GENESIS_STORY_GYM2_DONE         4
#define GENESIS_STORY_GYM3_DONE         5
#define GENESIS_STORY_GYM4_DONE         6  // Mega unlock
#define GENESIS_STORY_GYM5_DONE         7
#define GENESIS_STORY_GYM6_DONE         8
#define GENESIS_STORY_GYM7_DONE         9  // Z unlock
#define GENESIS_STORY_GYM8_DONE         10 // Dynamax unlock
#define GENESIS_STORY_ECLIPSE_FALLEN    11
#define GENESIS_STORY_CHAMPION          12
#define GENESIS_STORY_POSTGAME          13
#define GENESIS_STORY_EASTERN_OPEN      14
#define GENESIS_STORY_EASTERN_DONE      15
#define GENESIS_STORY_LEGENDS_DONE      16
#define GENESIS_STORY_ACT5_DONE         17 // Space Center Tera foreshadow
#define GENESIS_STORY_ACT6_DONE         18 // Sky Pillar phenomena
#define GENESIS_STORY_ACT7_DONE         19 // Eclipse commanders climax

// Puzzle progress nibbles in VAR_GENESIS_PUZZLE_STATE
#define GENESIS_PUZZLE_RELAY_NONE       0
#define GENESIS_PUZZLE_RELAY_BLUE       1
#define GENESIS_PUZZLE_RELAY_GREEN      2
#define GENESIS_PUZZLE_PHENOMENA_NONE   0
#define GENESIS_PUZZLE_PHENOMENA_GRASS  1
#define GENESIS_PUZZLE_PHENOMENA_WATER  2
#define GENESIS_PUZZLE_PHENOMENA_FIRE   3
#define GENESIS_PUZZLE_CIPHER_NONE      0
#define GENESIS_PUZZLE_CIPHER_Q1        1
#define GENESIS_PUZZLE_CIPHER_SWITCH_A  2
#define GENESIS_PUZZLE_CIPHER_SWITCH_B  3

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
