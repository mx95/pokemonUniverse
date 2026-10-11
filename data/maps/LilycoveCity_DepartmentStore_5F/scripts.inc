LilycoveCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LilycoveCity_DepartmentStore_5F_OnWarp
	.byte 0

@ During the abnormal weather from Kyogre/Groudon awakening the dept store rooftop is inaccessible
@ Likely done to avoid dealing with showing the weather. Technically the rooftop is indoors
LilycoveCity_DepartmentStore_5F_OnWarp:
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 2, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 3, LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs
	.2byte 0

LilycoveCity_DepartmentStore_5F_EventScript_BlockRoofStairs::
	setobjectxy LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, 16, 2
	turnobject LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, DIR_NORTH
	end

LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Dolls:
	.2byte DECOR_PICHU_DOLL
	.2byte DECOR_PIKACHU_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_JIGGLYPUFF_DOLL
	.2byte DECOR_DUSKULL_DOLL
	.2byte DECOR_WYNAUT_DOLL
	.2byte DECOR_BALTOY_DOLL
	.2byte DECOR_KECLEON_DOLL
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_SWABLU_DOLL
	.2byte DECOR_GULPIN_DOLL
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Cushions
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Cushions:
	.2byte DECOR_PIKA_CUSHION
	.2byte DECOR_ROUND_CUSHION
	.2byte DECOR_ZIGZAG_CUSHION
	.2byte DECOR_SPIN_CUSHION
	.2byte DECOR_DIAMOND_CUSHION
	.2byte DECOR_BALL_CUSHION
	.2byte DECOR_GRASS_CUSHION
	.2byte DECOR_FIRE_CUSHION
	.2byte DECOR_WATER_CUSHION
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_ClerkMidRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Posters
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Posters:
	.2byte DECOR_BALL_POSTER
	.2byte DECOR_GREEN_POSTER
	.2byte DECOR_RED_POSTER
	.2byte DECOR_BLUE_POSTER
	.2byte DECOR_CUTE_POSTER
	.2byte DECOR_PIKA_POSTER
	.2byte DECOR_LONG_POSTER
	.2byte DECOR_SEA_POSTER
	.2byte DECOR_SKY_POSTER
	pokemartlistend

LilycoveCity_DepartmentStore_5F_EventScript_ClerkFarRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration2 LilycoveCity_DepartmentStore_5F_Pokemart_Mats
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_5F_Pokemart_Mats:
	.2byte DECOR_SURF_MAT
	.2byte DECOR_THUNDER_MAT
	.2byte DECOR_FIRE_BLAST_MAT
	.2byte DECOR_POWDER_SNOW_MAT
	.2byte DECOR_ATTRACT_MAT
	.2byte DECOR_FISSURE_MAT
	.2byte DECOR_SPIKES_MAT
	.2byte DECOR_GLITTER_MAT
	.2byte DECOR_JUMP_MAT
	.2byte DECOR_SPIN_MAT
	pokemartlistend

@ GENESIS: Boutique Aurelia — contest scarves as fashion looks (OW sprite kits still deferred)
LilycoveCity_DepartmentStore_5F_EventScript_PokefanF::
	lock
	faceplayer
	setflag FLAG_GENESIS_CLOTHING_STUB_SEEN
	goto_if_set FLAG_BADGE03_GET, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueOpen
	msgbox LilycoveCity_DepartmentStore_5F_Text_ClothingStubEarly, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueOpen::
	msgbox LilycoveCity_DepartmentStore_5F_Text_BoutiqueWelcome, MSGBOX_DEFAULT
LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu::
	message LilycoveCity_DepartmentStore_5F_Text_BoutiqueAsk
	waitmessage
	multichoice 0, 0, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueBuy
	case 1, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueWear
	case 2, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueInfo
	case MULTI_B_PRESSED, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueBye
	end

LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueInfo::
	msgbox LilycoveCity_DepartmentStore_5F_Text_BoutiqueInfo, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu

LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueBye::
	msgbox LilycoveCity_DepartmentStore_5F_Text_BoutiqueBye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueBuy::
	goto_if_unset FLAG_GENESIS_OUTFIT_RED, LilycoveCity_DepartmentStore_5F_EventScript_BuyRed
	goto_if_unset FLAG_GENESIS_OUTFIT_BLUE, LilycoveCity_DepartmentStore_5F_EventScript_BuyBlue
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_DepartmentStore_5F_EventScript_BuyChampionCheck
	msgbox LilycoveCity_DepartmentStore_5F_Text_BoutiqueOwnedBasic, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu

LilycoveCity_DepartmentStore_5F_EventScript_BuyChampionCheck::
	goto_if_set FLAG_GENESIS_OUTFIT_CHAMPION, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueComplete
	msgbox LilycoveCity_DepartmentStore_5F_Text_BuyChampion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu
	checkmoney 10000
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueNoMoney
	removemoney 10000
	setflag FLAG_GENESIS_OUTFIT_CHAMPION
	setflag FLAG_GENESIS_ACHIEVEMENT_FASHION
	giveitem ITEM_PINK_SCARF
	setvar VAR_GENESIS_OUTFIT, 3
	callnative Genesis_RefreshPlayerOutfit
	msgbox LilycoveCity_DepartmentStore_5F_Text_WearSet, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu

LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueComplete::
	msgbox LilycoveCity_DepartmentStore_5F_Text_BoutiqueComplete, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu

LilycoveCity_DepartmentStore_5F_EventScript_BuyRed::
	msgbox LilycoveCity_DepartmentStore_5F_Text_BuyRed, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu
	checkmoney 3000
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueNoMoney
	removemoney 3000
	setflag FLAG_GENESIS_OUTFIT_RED
	giveitem ITEM_RED_SCARF
	setvar VAR_GENESIS_OUTFIT, 1
	callnative Genesis_RefreshPlayerOutfit
	msgbox LilycoveCity_DepartmentStore_5F_Text_WearSet, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu

LilycoveCity_DepartmentStore_5F_EventScript_BuyBlue::
	goto_if_unset FLAG_BADGE06_GET, LilycoveCity_DepartmentStore_5F_EventScript_NeedBadge6
	msgbox LilycoveCity_DepartmentStore_5F_Text_BuyBlue, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu
	checkmoney 5000
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueNoMoney
	removemoney 5000
	setflag FLAG_GENESIS_OUTFIT_BLUE
	giveitem ITEM_BLUE_SCARF
	setvar VAR_GENESIS_OUTFIT, 2
	callnative Genesis_RefreshPlayerOutfit
	msgbox LilycoveCity_DepartmentStore_5F_Text_WearSet, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu

LilycoveCity_DepartmentStore_5F_EventScript_NeedBadge6::
	msgbox LilycoveCity_DepartmentStore_5F_Text_NeedBadge6, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu

LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueNoMoney::
	msgbox LilycoveCity_DepartmentStore_5F_Text_NoMoney, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu

LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueWear::
	msgbox LilycoveCity_DepartmentStore_5F_Text_WearDefaultQ, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_DepartmentStore_5F_EventScript_SetWear0
	goto_if_unset FLAG_GENESIS_OUTFIT_RED, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu
	msgbox LilycoveCity_DepartmentStore_5F_Text_WearRedQ, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_DepartmentStore_5F_EventScript_SetWear1
	goto_if_unset FLAG_GENESIS_OUTFIT_BLUE, LilycoveCity_DepartmentStore_5F_EventScript_WearChampAsk
	msgbox LilycoveCity_DepartmentStore_5F_Text_WearBlueQ, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_DepartmentStore_5F_EventScript_SetWear2
LilycoveCity_DepartmentStore_5F_EventScript_WearChampAsk::
	goto_if_unset FLAG_GENESIS_OUTFIT_CHAMPION, LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu
	msgbox LilycoveCity_DepartmentStore_5F_Text_WearChampQ, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_DepartmentStore_5F_EventScript_SetWear3
	goto LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu

LilycoveCity_DepartmentStore_5F_EventScript_SetWear0::
	setvar VAR_GENESIS_OUTFIT, 0
	callnative Genesis_RefreshPlayerOutfit
	msgbox LilycoveCity_DepartmentStore_5F_Text_WearSet, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu

LilycoveCity_DepartmentStore_5F_EventScript_SetWear1::
	setvar VAR_GENESIS_OUTFIT, 1
	callnative Genesis_RefreshPlayerOutfit
	msgbox LilycoveCity_DepartmentStore_5F_Text_WearSet, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu

LilycoveCity_DepartmentStore_5F_EventScript_SetWear2::
	setvar VAR_GENESIS_OUTFIT, 2
	callnative Genesis_RefreshPlayerOutfit
	msgbox LilycoveCity_DepartmentStore_5F_Text_WearSet, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu

LilycoveCity_DepartmentStore_5F_EventScript_SetWear3::
	setvar VAR_GENESIS_OUTFIT, 3
	callnative Genesis_RefreshPlayerOutfit
	msgbox LilycoveCity_DepartmentStore_5F_Text_WearSet, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_5F_EventScript_BoutiqueMenu

LilycoveCity_DepartmentStore_5F_EventScript_Woman::
	lockall
	applymovement LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal
	goto LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather
	end

LilycoveCity_DepartmentStore_5F_EventScript_WomanNormal::
	msgbox LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_WomanLegendaryWeather::
	msgbox LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEPARTMENT_STORE_STAIRS_WOMAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_LittleGirl::
	msgbox LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_5F_Text_ClothingStubEarly:
	.string "BOUTIQUE AURELIA--opening soon!\p"
	.string "We're stitching TRAINER looks that\n"
	.string "unlock with GYM BADGES.\p"
	.string "Come back after Celestia's badge!$"

LilycoveCity_DepartmentStore_5F_Text_BoutiqueWelcome:
	.string "Welcome to BOUTIQUE AURELIA!\p"
	.string "Scarves mark your look for Contests\n"
	.string "and style notes. Full overworld kits\l"
	.string "arrive when the tailor finishes sprites.$"

LilycoveCity_DepartmentStore_5F_Text_BoutiqueAsk:
	.string "Buy a look, wear one, or hear more?\n"
	.string "(YES=Buy / NO=Wear / INFO)$"

LilycoveCity_DepartmentStore_5F_Text_BoutiqueInfo:
	.string "Badge 3: Verdant Red Scarf.\n"
	.string "Badge 6: Azure Blue Scarf.\l"
	.string "Champion: Pink Champion look.\p"
	.string "Looks are tracked as fashion unlocks.\n"
	.string "OW sprite swaps need future art.$"

LilycoveCity_DepartmentStore_5F_Text_BoutiqueBye:
	.string "Come back when your style evolves!$"

LilycoveCity_DepartmentStore_5F_Text_BuyRed:
	.string "Verdant Red Scarf look--¥3000?\n"
	.string "Includes a RED SCARF for Contests.$"

LilycoveCity_DepartmentStore_5F_Text_BuyBlue:
	.string "Azure Blue Scarf look--¥5000?\n"
	.string "Includes a BLUE SCARF for Contests.$"

LilycoveCity_DepartmentStore_5F_Text_BuyChampion:
	.string "Champion Pink look--¥10000?\n"
	.string "Includes a PINK SCARF. Prestige only!$"

LilycoveCity_DepartmentStore_5F_Text_NeedBadge6:
	.string "The Azure look unlocks after badge 6.\n"
	.string "Come back after Stormbreak's badge.$"

LilycoveCity_DepartmentStore_5F_Text_NoMoney:
	.string "You don't have enough money…$"

LilycoveCity_DepartmentStore_5F_Text_BoutiqueOwnedBasic:
	.string "You own the early looks.\n"
	.string "Champion couture waits after the League!$"

LilycoveCity_DepartmentStore_5F_Text_BoutiqueComplete:
	.string "Your wardrobe is complete!\n"
	.string "Fashion Master of AURELIA--for now.$"

LilycoveCity_DepartmentStore_5F_Text_WearDefaultQ:
	.string "Wear the default Traveler look?$"

LilycoveCity_DepartmentStore_5F_Text_WearRedQ:
	.string "Wear Verdant Red?$"

LilycoveCity_DepartmentStore_5F_Text_WearBlueQ:
	.string "Wear Azure Blue?$"

LilycoveCity_DepartmentStore_5F_Text_WearChampQ:
	.string "Wear Champion Pink?$"

LilycoveCity_DepartmentStore_5F_Text_WearSet:
	.string "Look selected! Scarves are in your bag.\n"
	.string "Overworld sprite kits still pending art.$"

LilycoveCity_DepartmentStore_5F_Text_PlaceFullOfCuteDolls:
	.string "This place is full of cute DOLLS.\p"
	.string "I should buy some for me, instead of\n"
	.string "just for my children.$"

LilycoveCity_DepartmentStore_5F_Text_GettingDollInsteadOfPokemon:
	.string "I'm not big enough to raise POKéMON,\n"
	.string "so I'm getting a cute DOLL instead.$"

LilycoveCity_DepartmentStore_5F_Text_SellManyCuteMatsHere:
	.string "They sell many cute MATS here.\p"
	.string "I wonder which one I should get?\n"
	.string "Maybe I'll buy them all…$"

LilycoveCity_DepartmentStore_5F_Text_ClosedRooftopForWeather:
	.string "I think they closed the rooftop\n"
	.string "because the weather is wild today.$"
