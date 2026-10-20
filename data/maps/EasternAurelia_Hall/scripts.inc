EasternAurelia_Hall_MapScripts::
	.byte 0

@ City desks (stand-in for Mirage→Summit east). Leaders unlock in badge order 9-16.

EasternAurelia_Hall_EventScript_Iris::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_09_GET, EasternAurelia_Hall_EventScript_IrisDone
	msgbox EasternAurelia_Hall_Text_IrisIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_IrisWarp, MSGBOX_DEFAULT
	warpsilent MAP_MIRAGE_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_IrisDone::
	msgbox EasternAurelia_Hall_Text_IrisDone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_IrisWarp, MSGBOX_DEFAULT
	warpsilent MAP_MIRAGE_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_Celia::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_09_GET, EasternAurelia_Hall_EventScript_NeedIris
	goto_if_set FLAG_GENESIS_BADGE_10_GET, EasternAurelia_Hall_EventScript_CeliaDone
	msgbox EasternAurelia_Hall_Text_CeliaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_CeliaWarp, MSGBOX_DEFAULT
	warpsilent MAP_VERDANTIS_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_CeliaDone::
	msgbox EasternAurelia_Hall_Text_CeliaDone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_CeliaWarp, MSGBOX_DEFAULT
	warpsilent MAP_VERDANTIS_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_Noctis::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_10_GET, EasternAurelia_Hall_EventScript_NeedCelia
	goto_if_set FLAG_GENESIS_BADGE_11_GET, EasternAurelia_Hall_EventScript_NoctisDone
	msgbox EasternAurelia_Hall_Text_NoctisIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_NoctisWarp, MSGBOX_DEFAULT
	warpsilent MAP_OBSIDIAN_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_NoctisDone::
	msgbox EasternAurelia_Hall_Text_NoctisDone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_NoctisWarp, MSGBOX_DEFAULT
	warpsilent MAP_OBSIDIAN_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_Drake::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_11_GET, EasternAurelia_Hall_EventScript_NeedNoctis
	goto_if_set FLAG_GENESIS_BADGE_12_GET, EasternAurelia_Hall_EventScript_DrakeDone
	msgbox EasternAurelia_Hall_Text_DrakeIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_DrakeWarp, MSGBOX_DEFAULT
	warpsilent MAP_ASTRAL_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_DrakeDone::
	msgbox EasternAurelia_Hall_Text_DrakeDone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_DrakeWarp, MSGBOX_DEFAULT
	warpsilent MAP_ASTRAL_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_Luna::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_12_GET, EasternAurelia_Hall_EventScript_NeedDrake
	goto_if_set FLAG_GENESIS_BADGE_13_GET, EasternAurelia_Hall_EventScript_LunaDone
	msgbox EasternAurelia_Hall_Text_LunaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_LunaWarp, MSGBOX_DEFAULT
	warpsilent MAP_TIDYMOON_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_LunaDone::
	msgbox EasternAurelia_Hall_Text_LunaDone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_LunaWarp, MSGBOX_DEFAULT
	warpsilent MAP_TIDYMOON_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_Morrigan::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_13_GET, EasternAurelia_Hall_EventScript_NeedLuna
	goto_if_set FLAG_GENESIS_BADGE_14_GET, EasternAurelia_Hall_EventScript_MorriganDone
	msgbox EasternAurelia_Hall_Text_MorriganIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_MorriganWarp, MSGBOX_DEFAULT
	warpsilent MAP_EON_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_MorriganDone::
	msgbox EasternAurelia_Hall_Text_MorriganDone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_MorriganWarp, MSGBOX_DEFAULT
	warpsilent MAP_EON_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_Colleague::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_14_GET, EasternAurelia_Hall_EventScript_NeedMorrigan
	goto_if_set FLAG_GENESIS_BADGE_15_GET, EasternAurelia_Hall_EventScript_ColleagueDone
	msgbox EasternAurelia_Hall_Text_ColleagueIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_ColleagueWarp, MSGBOX_DEFAULT
	warpsilent MAP_GENESIS_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_ColleagueDone::
	msgbox EasternAurelia_Hall_Text_ColleagueDone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_ColleagueWarp, MSGBOX_DEFAULT
	warpsilent MAP_GENESIS_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_Mentor::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_15_GET, EasternAurelia_Hall_EventScript_NeedColleague
	goto_if_set FLAG_GENESIS_BADGE_16_GET, EasternAurelia_Hall_EventScript_MentorDone
	msgbox EasternAurelia_Hall_Text_MentorIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_MentorWarp, MSGBOX_DEFAULT
	warpsilent MAP_SUMMIT_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_MentorDone::
	msgbox EasternAurelia_Hall_Text_MentorDone, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_MentorWarp, MSGBOX_DEFAULT
	warpsilent MAP_SUMMIT_CITY, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_NeedIris::
	msgbox EasternAurelia_Hall_Text_NeedIris, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedCelia::
	msgbox EasternAurelia_Hall_Text_NeedCelia, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedNoctis::
	msgbox EasternAurelia_Hall_Text_NeedNoctis, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedDrake::
	msgbox EasternAurelia_Hall_Text_NeedDrake, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedLuna::
	msgbox EasternAurelia_Hall_Text_NeedLuna, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedMorrigan::
	msgbox EasternAurelia_Hall_Text_NeedMorrigan, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedColleague::
	msgbox EasternAurelia_Hall_Text_NeedColleague, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_Decline::
	msgbox EasternAurelia_Hall_Text_Decline, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_LegendSeeker::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, EasternAurelia_Hall_EventScript_LegendSeekerEarly
	goto_if_unset FLAG_GENESIS_ECLIPSE_DEFEATED, EasternAurelia_Hall_EventScript_LegendSeekerEclipseGate
	setflag FLAG_GENESIS_LEGEND_QUEST_HINT
	setflag FLAG_GENESIS_ECLIPSE_ARCHIVE_OPEN
	msgbox EasternAurelia_Hall_Text_SanctumOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_SanctumWarp, MSGBOX_DEFAULT
	warpsilent MAP_GENESIS_LEGEND_SANCTUM, 4, 6
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_LegendSeekerEarly::
	msgbox EasternAurelia_Hall_Text_LegendEarly, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_LegendSeekerEclipseGate::
	msgbox EasternAurelia_Hall_Text_EclipseGate, MSGBOX_DEFAULT
	release
	end

@ Hall clerk: desk directory + return warp to Reception Gate (Fly QoL companion)
EasternAurelia_Hall_EventScript_HallClerk::
	lock
	faceplayer
	msgbox EasternAurelia_Hall_Text_ClerkWelcome, MSGBOX_DEFAULT
	message EasternAurelia_Hall_Text_ClerkAsk
	waitmessage
	multichoice 0, 0, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, EasternAurelia_Hall_EventScript_ClerkReturn
	case 1, EasternAurelia_Hall_EventScript_ClerkStay
	case 2, EasternAurelia_Hall_EventScript_ClerkDirectory
	case MULTI_B_PRESSED, EasternAurelia_Hall_EventScript_ClerkStay
	end

EasternAurelia_Hall_EventScript_ClerkReturn::
	msgbox EasternAurelia_Hall_Text_ClerkWarpOut, MSGBOX_DEFAULT
	warpsilent MAP_BATTLE_FRONTIER_RECEPTION_GATE, 4, 11
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_ClerkStay::
	msgbox EasternAurelia_Hall_Text_ClerkStay, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_ClerkDirectory::
	msgbox EasternAurelia_Hall_Text_ClerkDirectory, MSGBOX_DEFAULT
	release
	end

@ Desk plaques (bg signs) — stand-in city labels until full maps exist
EasternAurelia_Hall_EventScript_DeskMirage::
	lockall
	msgbox EasternAurelia_Hall_Text_DeskMirage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_DeskMirageCancel
	warpsilent MAP_MIRAGE_CITY, 9, 8
	waitstate
	releaseall
	end

EasternAurelia_Hall_EventScript_DeskMirageCancel::
	releaseall
	end

EasternAurelia_Hall_EventScript_DeskVerdantis::
	msgbox EasternAurelia_Hall_Text_DeskVerdantis, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_DeskVerdantisCancel
	warpsilent MAP_VERDANTIS_CITY, 9, 8
	waitstate
	end

EasternAurelia_Hall_EventScript_DeskVerdantisCancel::
	release
	end

EasternAurelia_Hall_EventScript_DeskObsidian::
	msgbox EasternAurelia_Hall_Text_DeskObsidian, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_DeskObsidianCancel
	warpsilent MAP_OBSIDIAN_CITY, 9, 8
	waitstate
	end

EasternAurelia_Hall_EventScript_DeskObsidianCancel::
	release
	end

EasternAurelia_Hall_EventScript_DeskAstral::
	msgbox EasternAurelia_Hall_Text_DeskAstral, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_DeskAstralCancel
	warpsilent MAP_ASTRAL_CITY, 9, 8
	waitstate
	end

EasternAurelia_Hall_EventScript_DeskAstralCancel::
	release
	end

EasternAurelia_Hall_EventScript_DeskTidymoon::
	msgbox EasternAurelia_Hall_Text_DeskTidymoon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_DeskTidymoonCancel
	warpsilent MAP_TIDYMOON_CITY, 9, 8
	waitstate
	end

EasternAurelia_Hall_EventScript_DeskTidymoonCancel::
	release
	end

EasternAurelia_Hall_EventScript_DeskEon::
	msgbox EasternAurelia_Hall_Text_DeskEon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_DeskEonCancel
	warpsilent MAP_EON_CITY, 9, 8
	waitstate
	end

EasternAurelia_Hall_EventScript_DeskEonCancel::
	release
	end

EasternAurelia_Hall_EventScript_DeskGenesis::
	msgbox EasternAurelia_Hall_Text_DeskGenesis, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_DeskGenesisCancel
	warpsilent MAP_GENESIS_CITY, 9, 8
	waitstate
	end

EasternAurelia_Hall_EventScript_DeskGenesisCancel::
	release
	end

EasternAurelia_Hall_EventScript_DeskSummit::
	msgbox EasternAurelia_Hall_Text_DeskSummit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_DeskSummitCancel
	warpsilent MAP_SUMMIT_CITY, 9, 8
	waitstate
	end

EasternAurelia_Hall_EventScript_DeskSummitCancel::
	release
	end

EasternAurelia_Hall_EventScript_HallDirectory::
	msgbox EasternAurelia_Hall_Text_HallDirectory, MSGBOX_SIGN
	end

EasternAurelia_Hall_Text_Decline:
	.string "Return when the tide of battle calls.$"

EasternAurelia_Hall_Text_NeedIris:
	.string "CELIA: Verdantis waits its turn.\n"
	.string "Earn IRIS's MIRAGE BADGE in the city first.$"

EasternAurelia_Hall_Text_NeedCelia:
	.string "NOCTIS: Obsidian stays sealed until\n"
	.string "you earn CELIA's JUNGLE BADGE.$"

EasternAurelia_Hall_Text_NeedNoctis:
	.string "DRAKE: Astral City's stars won't turn\n"
	.string "until NOCTIS yields the OBSIDIAN BADGE.$"

EasternAurelia_Hall_Text_NeedDrake:
	.string "LUNA: Tidymoon's tide follows the stars.\n"
	.string "Challenge DRAKE for the ASTRAL BADGE.$"

EasternAurelia_Hall_Text_NeedLuna:
	.string "MORRIGAN: Eon's spirits keep to order.\n"
	.string "Bring LUNA's MOON BADGE first.$"

EasternAurelia_Hall_Text_NeedMorrigan:
	.string "COLLEAGUE: Genesis City only hosts\n"
	.string "those who hold MORRIGAN's EON BADGE.$"

EasternAurelia_Hall_Text_NeedColleague:
	.string "MENTOR: The Summit desk opens after\n"
	.string "you claim the GENESIS BADGE.$"

EasternAurelia_Hall_Text_IrisIntro:
	.string "GUIDE: MIRAGE CITY is open beyond this\n"
	.string "desk. IRIS waits in her Psychic GYM.\p"
	.string "Travel to MIRAGE CITY now?$"

EasternAurelia_Hall_Text_IrisWarp:
	.string "Stepping through the teleport net…$"

EasternAurelia_Hall_Text_IrisDone:
	.string "GUIDE: You hold the MIRAGE BADGE.\n"
	.string "Return to MIRAGE CITY?$"

EasternAurelia_Hall_Text_CeliaWarp:
	.string "Opening the teleport net to VERDANTIS CITY.$"

EasternAurelia_Hall_Text_CeliaIntro:
	.string "GUIDE: VERDANTIS CITY is open beyond this\n"
	.string "desk--CELIA's BUG GYM awaits.\p"
	.string "Travel to VERDANTIS CITY now?$"

EasternAurelia_Hall_Text_CeliaDone:
	.string "GUIDE: You hold the JUNGLE BADGE.\n"
	.string "Return to VERDANTIS CITY?$"

EasternAurelia_Hall_Text_NoctisWarp:
	.string "Opening the teleport net to OBSIDIAN CITY.$"

EasternAurelia_Hall_Text_NoctisIntro:
	.string "GUIDE: OBSIDIAN CITY is open beyond this\n"
	.string "desk--NOCTIS's DARK GYM awaits.\p"
	.string "Travel to OBSIDIAN CITY now?$"

EasternAurelia_Hall_Text_NoctisDone:
	.string "GUIDE: You hold the OBSIDIAN BADGE.\n"
	.string "Return to OBSIDIAN CITY?$"

EasternAurelia_Hall_Text_DrakeWarp:
	.string "Opening the teleport net to ASTRAL CITY.$"

EasternAurelia_Hall_Text_DrakeIntro:
	.string "GUIDE: ASTRAL CITY is open beyond this\n"
	.string "desk--DRAKE's DRAGON GYM awaits.\p"
	.string "Travel to ASTRAL CITY now?$"

EasternAurelia_Hall_Text_DrakeDone:
	.string "GUIDE: You hold the ASTRAL BADGE.\n"
	.string "Return to ASTRAL CITY?$"

EasternAurelia_Hall_Text_LunaWarp:
	.string "Opening the teleport net to TIDYMOON CITY.$"

EasternAurelia_Hall_Text_LunaIntro:
	.string "GUIDE: TIDYMOON CITY is open beyond this\n"
	.string "desk--LUNA's FAIRY GYM awaits.\p"
	.string "Travel to TIDYMOON CITY now?$"

EasternAurelia_Hall_Text_LunaDone:
	.string "GUIDE: You hold the MOON BADGE.\n"
	.string "Return to TIDYMOON CITY?$"

EasternAurelia_Hall_Text_MorriganWarp:
	.string "Opening the teleport net to EON CITY.$"

EasternAurelia_Hall_Text_MorriganIntro:
	.string "GUIDE: EON CITY is open beyond this\n"
	.string "desk--MORRIGAN's GHOST GYM awaits.\p"
	.string "Travel to EON CITY now?$"

EasternAurelia_Hall_Text_MorriganDone:
	.string "GUIDE: You hold the EON BADGE.\n"
	.string "Return to EON CITY?$"

EasternAurelia_Hall_Text_ColleagueWarp:
	.string "Opening the teleport net to GENESIS CITY.$"

EasternAurelia_Hall_Text_ColleagueIntro:
	.string "GUIDE: GENESIS CITY is open beyond this\n"
	.string "desk--the COLLEAGUE's MIXED GYM awaits.\p"
	.string "Travel to GENESIS CITY now?$"

EasternAurelia_Hall_Text_ColleagueDone:
	.string "GUIDE: You hold the GENESIS BADGE.\n"
	.string "Return to GENESIS CITY?$"

EasternAurelia_Hall_Text_MentorWarp:
	.string "Opening the teleport net to AURELIA SUMMIT.$"

EasternAurelia_Hall_Text_MentorIntro:
	.string "GUIDE: AURELIA SUMMIT (east) is open\n"
	.string "beyond this desk--the MENTOR awaits.\p"
	.string "Travel to AURELIA SUMMIT now?$"

EasternAurelia_Hall_Text_MentorDone:
	.string "GUIDE: You hold the ASCENSION BADGE.\n"
	.string "Return to AURELIA SUMMIT?$"

EasternAurelia_Hall_Text_LegendEarly:
	.string "Return when you are CHAMPION.\n"
	.string "The legends will answer then.$"

EasternAurelia_Hall_Text_EclipseGate:
	.string "The LEGEND SANCTUM stays sealed while\n"
	.string "TEAM ECLIPSE's residue lingers.\p"
	.string "Defeat them completely, then return.$"

EasternAurelia_Hall_Text_SanctumOffer:
	.string "The LEGEND SANCTUM is open to you.\n"
	.string "Shall I show you the three foci?$"

EasternAurelia_Hall_Text_SanctumWarp:
	.string "This way--tread carefully.$"

EasternAurelia_Hall_Text_ClerkWelcome:
	.string "Eastern AURELIA HALL clerk.\n"
	.string "Eight live cities, one hall.$"
	.string "Eight city desks, one hall--for now.$"

EasternAurelia_Hall_Text_ClerkAsk:
	.string "Return to the Reception Gate?\n"
	.string "(YES / NO / desk directory)$"

EasternAurelia_Hall_Text_ClerkWarpOut:
	.string "Fly back to the BATTLE FRONTIER any\n"
	.string "time, then speak with the greeter.\p"
	.string "I'll send you to the Reception Gate.$"

EasternAurelia_Hall_Text_ClerkStay:
	.string "Browse the desks when you're ready.\n"
	.string "Plaques name each Eastern city.$"

EasternAurelia_Hall_Text_ClerkDirectory:
	.string "All eight eastern cities are live maps.\n"
	.string "Desk guides and plaques warp you in.\p"
	.string "Back row: MIRAGE · VERDANTIS ·\n"
	.string "OBSIDIAN · ASTRAL.\p"
	.string "Front row: TIDYMOON · EON ·\n"
	.string "GENESIS CITY · SUMMIT EAST.\p"
	.string "Researcher: Legend Sanctum.\n"
	.string "WORLD TOURNAMENT lobby via Frontier.$"
	.string "Other eastern cities still use desks.\p"
	.string "Back row: MIRAGE · VERDANTIS ·\n"
	.string "OBSIDIAN · ASTRAL.\p"
	.string "Front row: TIDYMOON · EON ·\n"
	.string "GENESIS CITY · SUMMIT EAST.\p"
	.string "Researcher (center): Legend Sanctum.\n"
	.string "Exit warps return to Reception Gate.$"

EasternAurelia_Hall_Text_DeskMirage:
	.string "MIRAGE CITY -- Badge 9 (live map)\n"
	.string "LEADER IRIS · PSYCHIC · Mirage Badge\p"
	.string "Warp to MIRAGE CITY?$"

EasternAurelia_Hall_Text_DeskVerdantis:
	.string "VERDANTIS CITY -- Badge 10 (live map)\n"
	.string "LEADER CELIA · BUG · Jungle Badge\p"
	.string "Warp to VERDANTIS CITY?$"
	.string "LEADER CELIA · BUG · Jungle Badge$"

EasternAurelia_Hall_Text_DeskObsidian:
	.string "OBSIDIAN CITY -- Badge 11 (live map)\n"
	.string "LEADER NOCTIS · DARK · Obsidian Badge\p"
	.string "Warp to OBSIDIAN CITY?$"
	.string "LEADER NOCTIS · DARK · Obsidian Badge$"

EasternAurelia_Hall_Text_DeskAstral:
	.string "ASTRAL CITY -- Badge 12 (live map)\n"
	.string "LEADER DRAKE · DRAGON · Astral / Tera\p"
	.string "Warp to ASTRAL CITY?$"
	.string "LEADER DRAKE · DRAGON · Astral / Tera$"

EasternAurelia_Hall_Text_DeskTidymoon:
	.string "TIDYMOON CITY -- Badge 13 (live map)\n"
	.string "LEADER LUNA · FAIRY · Moon Badge\p"
	.string "Warp to TIDYMOON CITY?$"
	.string "LEADER LUNA · FAIRY · Moon Badge$"

EasternAurelia_Hall_Text_DeskEon:
	.string "EON CITY -- Badge 14 (live map)\n"
	.string "LEADER MORRIGAN · GHOST · Eon Badge\p"
	.string "Warp to EON CITY?$"
	.string "LEADER MORRIGAN · GHOST · Eon Badge$"

EasternAurelia_Hall_Text_DeskGenesis:
	.string "GENESIS CITY -- Badge 15 (live map)\n"
	.string "COLLEAGUE · MIXED · Genesis Badge\p"
	.string "Warp to GENESIS CITY?$"
	.string "COLLEAGUE · MIXED · Genesis Badge$"

EasternAurelia_Hall_Text_DeskSummit:
	.string "AURELIA SUMMIT (east) -- Badge 16 (live map)\n"
	.string "MENTOR · MIXED · Ascension Badge\p"
	.string "Warp to AURELIA SUMMIT?$"
	.string "MENTOR · MIXED · Ascension Badge$"

EasternAurelia_Hall_Text_HallDirectory:
	.string "EASTERN AURELIA HALL\n"
	.string "City desks 9-16 · Legend Sanctum warp\p"
	.string "Access: Fly to BATTLE FRONTIER, then\n"
	.string "ask the Reception Gate greeter.$"
