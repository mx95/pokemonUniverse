// GENESIS: Original Aurelia legendary Pokémon.
// Uses Expansion Gen 4/5 DS-style (3D-looking) sprites as stand-ins until
// unique art ships. Battle + overworld share those assets.
// See docs/POKEMON_ROSTER.md and docs/art/genesis_legendaries_concept.png

    [SPECIES_AETHERNOX] =
    {
        .baseHP        = 100,
        .baseAttack    = 135,
        .baseDefense   = 95,
        .baseSpeed     = 115,
        .baseSpAttack  = 120,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_DARK),
        .catchRate = 3,
        .expYield = 300,
        .evYield_Attack = 2,
        .evYield_Speed = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Aethernox"),
        .cryId = CRY_GIRATINA,
        .natDexNum = NATIONAL_DEX_AETHERNOX,
        .categoryName = _("Chaos"),
        .height = 42,
        .weight = 2500,
        .description = COMPOUND_STRING(
            "Said to embody the chaos born when\n"
            "GENESIS ENERGY fractures. Its wings\n"
            "tear at the fabric of battle itself."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 387,
        .trainerOffset = 6,
        // Stand-in: DS-style Giratina Origin (distinct from Altered for chaos motif)
        .frontPic = gMonFrontPic_GiratinaOrigin,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_GiratinaOrigin,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_GiratinaOrigin,
        .shinyPalette = gMonShinyPalette_GiratinaOrigin,
        .iconSprite = gMonIcon_GiratinaOrigin,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 11, SHADOW_SIZE_L)
        FOOTPRINT(GiratinaOrigin)
        OVERWORLD(
            sPicTable_GiratinaOrigin,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GiratinaOrigin,
            gShinyOverworldPalette_GiratinaOrigin
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sGiratinaLevelUpLearnset,
        .teachableLearnset = sGiratinaTeachableLearnset,
    },

    [SPECIES_SOLARA] =
    {
        .baseHP        = 110,
        .baseAttack    = 90,
        .baseDefense   = 100,
        .baseSpeed     = 95,
        .baseSpAttack  = 140,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FIRE),
        .catchRate = 3,
        .expYield = 300,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_DROUGHT, ABILITY_NONE, ABILITY_PSYCHIC_SURGE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Solara"),
        .cryId = CRY_RESHIRAM,
        .natDexNum = NATIONAL_DEX_SOLARA,
        .categoryName = _("Creation"),
        .height = 38,
        .weight = 2100,
        .description = COMPOUND_STRING(
            "A radiant force of creation. When\n"
            "GENESIS ENERGY stabilizes, Solara's\n"
            "flames weave order from chaos."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        // Stand-in: DS-style Reshiram
        .frontPic = gMonFrontPic_Reshiram,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Reshiram,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Reshiram,
        .shinyPalette = gMonShinyPalette_Reshiram,
        .iconSprite = gMonIcon_Reshiram,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 12, SHADOW_SIZE_L)
        FOOTPRINT(Reshiram)
        OVERWORLD(
            sPicTable_Reshiram,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Reshiram,
            gShinyOverworldPalette_Reshiram
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sReshiramLevelUpLearnset,
        .teachableLearnset = sReshiramTeachableLearnset,
    },

    [SPECIES_GENESIS] =
    {
        .baseHP        = 120,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_MYSTERY),
        .catchRate = 3,
        .expYield = 340,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PROTEAN, ABILITY_NONE, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Genesis"),
        .cryId = CRY_ARCEUS,
        .natDexNum = NATIONAL_DEX_GENESIS,
        .categoryName = _("Potential"),
        .height = 50,
        .weight = 9999,
        .description = COMPOUND_STRING(
            "The living source of GENESIS ENERGY.\n"
            "It connects every battle phenomenon-\n"
            "Mega, Z-Power, Dynamax, and beyond."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 455,
        .trainerOffset = 8,
        // Stand-in: DS-style Arceus
        .frontPic = gMonFrontPic_Arceus,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Arceus,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Arceus,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_ArceusNormal,
        .shinyPalette = gMonShinyPalette_ArceusNormal,
        .iconSprite = gMonIcon_ArceusNormal,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 13, SHADOW_SIZE_L)
        FOOTPRINT(Arceus)
        OVERWORLD(
            sPicTable_ArceusNormal,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ArceusNormal,
            gShinyOverworldPalette_ArceusNormal
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sArceusLevelUpLearnset,
        .teachableLearnset = sArceusTeachableLearnset,
    },
