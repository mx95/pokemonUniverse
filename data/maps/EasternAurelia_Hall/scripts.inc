EasternAurelia_Hall_MapScripts::
	.byte 0

@ City desks (stand-in for Mirage→Summit east). Leaders unlock in badge order 9-16.

EasternAurelia_Hall_EventScript_Iris::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_09_GET, EasternAurelia_Hall_EventScript_IrisDone
	msgbox EasternAurelia_Hall_Text_IrisIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_IRIS, EasternAurelia_Hall_Text_IrisDefeat
	message EasternAurelia_Hall_Text_GotMirageBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_09_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox EasternAurelia_Hall_Text_IrisAfter, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_IrisDone::
	msgbox EasternAurelia_Hall_Text_IrisDone, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_Celia::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_09_GET, EasternAurelia_Hall_EventScript_NeedIris
	goto_if_set FLAG_GENESIS_BADGE_10_GET, EasternAurelia_Hall_EventScript_CeliaDone
	msgbox EasternAurelia_Hall_Text_CeliaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_CELIA, EasternAurelia_Hall_Text_CeliaDefeat
	message EasternAurelia_Hall_Text_GotJungleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_10_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox EasternAurelia_Hall_Text_CeliaAfter, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_CeliaDone::
	msgbox EasternAurelia_Hall_Text_CeliaDone, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_Noctis::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_10_GET, EasternAurelia_Hall_EventScript_NeedCelia
	goto_if_set FLAG_GENESIS_BADGE_11_GET, EasternAurelia_Hall_EventScript_NoctisDone
	msgbox EasternAurelia_Hall_Text_NoctisIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_NOCTIS, EasternAurelia_Hall_Text_NoctisDefeat
	message EasternAurelia_Hall_Text_GotObsidianBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_11_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox EasternAurelia_Hall_Text_NoctisAfter, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NoctisDone::
	msgbox EasternAurelia_Hall_Text_NoctisDone, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_Drake::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_11_GET, EasternAurelia_Hall_EventScript_NeedNoctis
	goto_if_set FLAG_GENESIS_BADGE_12_GET, EasternAurelia_Hall_EventScript_DrakeDone
	msgbox EasternAurelia_Hall_Text_DrakeIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_DRAKE_GYM, EasternAurelia_Hall_Text_DrakeDefeat
	message EasternAurelia_Hall_Text_GotAstralBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_12_GET
	setflag FLAG_GENESIS_TERA_UNLOCKED
	setflag FLAG_SYS_TERA_ORB_CHARGED
	call Genesis_EventScript_UpdateLevelCap
	msgbox EasternAurelia_Hall_Text_DrakeAfter, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_DrakeDone::
	msgbox EasternAurelia_Hall_Text_DrakeDone, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_Luna::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_12_GET, EasternAurelia_Hall_EventScript_NeedDrake
	goto_if_set FLAG_GENESIS_BADGE_13_GET, EasternAurelia_Hall_EventScript_LunaDone
	msgbox EasternAurelia_Hall_Text_LunaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_LUNA, EasternAurelia_Hall_Text_LunaDefeat
	message EasternAurelia_Hall_Text_GotMoonBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_13_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox EasternAurelia_Hall_Text_LunaAfter, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_LunaDone::
	msgbox EasternAurelia_Hall_Text_LunaDone, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_Morrigan::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_13_GET, EasternAurelia_Hall_EventScript_NeedLuna
	goto_if_set FLAG_GENESIS_BADGE_14_GET, EasternAurelia_Hall_EventScript_MorriganDone
	msgbox EasternAurelia_Hall_Text_MorriganIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_MORRIGAN, EasternAurelia_Hall_Text_MorriganDefeat
	message EasternAurelia_Hall_Text_GotEonBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_14_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox EasternAurelia_Hall_Text_MorriganAfter, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_MorriganDone::
	msgbox EasternAurelia_Hall_Text_MorriganDone, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_Colleague::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_14_GET, EasternAurelia_Hall_EventScript_NeedMorrigan
	goto_if_set FLAG_GENESIS_BADGE_15_GET, EasternAurelia_Hall_EventScript_ColleagueDone
	msgbox EasternAurelia_Hall_Text_ColleagueIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_COLLEAGUE, EasternAurelia_Hall_Text_ColleagueDefeat
	message EasternAurelia_Hall_Text_GotGenesisBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_15_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox EasternAurelia_Hall_Text_ColleagueAfter, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_ColleagueDone::
	msgbox EasternAurelia_Hall_Text_ColleagueDone, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_Mentor::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_15_GET, EasternAurelia_Hall_EventScript_NeedColleague
	goto_if_set FLAG_GENESIS_BADGE_16_GET, EasternAurelia_Hall_EventScript_MentorDone
	msgbox EasternAurelia_Hall_Text_MentorIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_MENTOR, EasternAurelia_Hall_Text_MentorDefeat
	message EasternAurelia_Hall_Text_GotAscensionBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_16_GET
	setvar VAR_GENESIS_STORY_STATE, GENESIS_STORY_EASTERN_DONE
	call Genesis_EventScript_UpdateLevelCap
	msgbox EasternAurelia_Hall_Text_MentorAfter, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_MentorDone::
	msgbox EasternAurelia_Hall_Text_MentorDone, MSGBOX_DEFAULT
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
	setflag FLAG_GENESIS_LEGEND_QUEST_HINT
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
	msgbox EasternAurelia_Hall_Text_DeskMirage, MSGBOX_SIGN
	end

EasternAurelia_Hall_EventScript_DeskVerdantis::
	msgbox EasternAurelia_Hall_Text_DeskVerdantis, MSGBOX_SIGN
	end

EasternAurelia_Hall_EventScript_DeskObsidian::
	msgbox EasternAurelia_Hall_Text_DeskObsidian, MSGBOX_SIGN
	end

EasternAurelia_Hall_EventScript_DeskAstral::
	msgbox EasternAurelia_Hall_Text_DeskAstral, MSGBOX_SIGN
	end

EasternAurelia_Hall_EventScript_DeskTidymoon::
	msgbox EasternAurelia_Hall_Text_DeskTidymoon, MSGBOX_SIGN
	end

EasternAurelia_Hall_EventScript_DeskEon::
	msgbox EasternAurelia_Hall_Text_DeskEon, MSGBOX_SIGN
	end

EasternAurelia_Hall_EventScript_DeskGenesis::
	msgbox EasternAurelia_Hall_Text_DeskGenesis, MSGBOX_SIGN
	end

EasternAurelia_Hall_EventScript_DeskSummit::
	msgbox EasternAurelia_Hall_Text_DeskSummit, MSGBOX_SIGN
	end

EasternAurelia_Hall_EventScript_HallDirectory::
	msgbox EasternAurelia_Hall_Text_HallDirectory, MSGBOX_SIGN
	end

EasternAurelia_Hall_Text_Decline:
	.string "Return when the tide of battle calls.$"

EasternAurelia_Hall_Text_NeedIris:
	.string "CELIA: Verdantis waits its turn.\n"
	.string "Clear IRIS's Mirage desk first.$"

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
	.string "IRIS: Welcome to the MIRAGE CITY desk.\n"
	.string "Our streets fold light into riddles.\p"
	.string "I am the PSYCHIC LEADER of Mirage.\n"
	.string "See through the veil--shall we begin?$"

EasternAurelia_Hall_Text_IrisDefeat:
	.string "The mirage clears… Well fought!$"

EasternAurelia_Hall_Text_GotMirageBadge:
	.string "{PLAYER} received the MIRAGE BADGE!$"

EasternAurelia_Hall_Text_IrisAfter:
	.string "IRIS: Mirage City stamps your path.\n"
	.string "Next desk: VERDANTIS--CELIA awaits.$"

EasternAurelia_Hall_Text_IrisDone:
	.string "IRIS: Mirage City's teleport net still\n"
	.string "hums for you. Trust what you perceive.$"

EasternAurelia_Hall_Text_CeliaIntro:
	.string "CELIA: VERDANTIS CITY desk, reporting!\n"
	.string "Rainforest canopies, buzzing trails…\p"
	.string "My BUG swarm thrives on motion.\n"
	.string "Ready for the jungle challenge?$"

EasternAurelia_Hall_Text_CeliaDefeat:
	.string "My swarm fell… Take this!$"

EasternAurelia_Hall_Text_GotJungleBadge:
	.string "{PLAYER} received the JUNGLE BADGE!$"

EasternAurelia_Hall_Text_CeliaAfter:
	.string "CELIA: Grow wild like Verdantis vines.\n"
	.string "Next: OBSIDIAN CITY--NOCTIS waits.$"

EasternAurelia_Hall_Text_CeliaDone:
	.string "CELIA: Verdantis keeps blooming.\n"
	.string "Come back when you need green noise.$"

EasternAurelia_Hall_Text_NoctisIntro:
	.string "NOCTIS: OBSIDIAN CITY desk.\n"
	.string "Volcanic glass. Quiet streets. Night.\p"
	.string "DARK POKéMON answer only the bold.\n"
	.string "Step into the ash--or walk away.$"

EasternAurelia_Hall_Text_NoctisDefeat:
	.string "The night yields…$"

EasternAurelia_Hall_Text_GotObsidianBadge:
	.string "{PLAYER} received the OBSIDIAN BADGE!$"

EasternAurelia_Hall_Text_NoctisAfter:
	.string "NOCTIS: Carry Obsidian's calm into light.\n"
	.string "ASTRAL CITY--DRAKE--is next.$"

EasternAurelia_Hall_Text_NoctisDone:
	.string "NOCTIS: Obsidian's vents still glow.\n"
	.string "Walk unafraid of your own shadow.$"

EasternAurelia_Hall_Text_DrakeIntro:
	.string "DRAKE: ASTRAL CITY desk--observatory\n"
	.string "of Eastern AURELIA.\p"
	.string "My DRAGONS chart the sky.\n"
	.string "Win, and TERA energy crystallizes!$"

EasternAurelia_Hall_Text_DrakeDefeat:
	.string "The stars align for you…$"

EasternAurelia_Hall_Text_GotAstralBadge:
	.string "{PLAYER} received the ASTRAL BADGE!$"

EasternAurelia_Hall_Text_DrakeAfter:
	.string "DRAKE: Feel GENESIS ENERGY crystallize.\n"
	.string "TERASTALLIZATION answers you now.\p"
	.string "Next desk: TIDYMOON CITY--LUNA.$"

EasternAurelia_Hall_Text_DrakeDone:
	.string "DRAKE: Astral's scopes still track you.\n"
	.string "Shape the battlefield as you will.$"

EasternAurelia_Hall_Text_LunaIntro:
	.string "LUNA: TIDYMOON CITY desk--tide pools,\n"
	.string "island lights, soft FAIRY glow.\p"
	.string "Dance with me under the moon?$"

EasternAurelia_Hall_Text_LunaDefeat:
	.string "The moon sets… Beautiful battle.$"

EasternAurelia_Hall_Text_GotMoonBadge:
	.string "{PLAYER} received the MOON BADGE!$"

EasternAurelia_Hall_Text_LunaAfter:
	.string "LUNA: Soft power still wins wars.\n"
	.string "EON CITY's desk--MORRIGAN--is next.$"

EasternAurelia_Hall_Text_LunaDone:
	.string "LUNA: Tidymoon's waves remember you.\n"
	.string "Kindness is not weakness, Champion.$"

EasternAurelia_Hall_Text_MorriganIntro:
	.string "MORRIGAN: EON CITY desk.\n"
	.string "Where spirits linger between eras…\p"
	.string "Face my GHOSTS, if you dare.$"

EasternAurelia_Hall_Text_MorriganDefeat:
	.string "Even spirits bow to you…$"

EasternAurelia_Hall_Text_GotEonBadge:
	.string "{PLAYER} received the EON BADGE!$"

EasternAurelia_Hall_Text_MorriganAfter:
	.string "MORRIGAN: Honor what lingers in Eon.\n"
	.string "GENESIS CITY--the Colleague--awaits.$"

EasternAurelia_Hall_Text_MorriganDone:
	.string "MORRIGAN: Eon's bells still toll for you.\n"
	.string "Listen when the past whispers.$"

EasternAurelia_Hall_Text_ColleagueIntro:
	.string "COLLEAGUE: GENESIS CITY desk--\n"
	.string "hub of prep, tutors, and mixed teams.\p"
	.string "No single type owns this city.\n"
	.string "Show me a Champion's toolkit!$"

EasternAurelia_Hall_Text_ColleagueDefeat:
	.string "Preparation meets destiny…$"

EasternAurelia_Hall_Text_GotGenesisBadge:
	.string "{PLAYER} received the GENESIS BADGE!$"

EasternAurelia_Hall_Text_ColleagueAfter:
	.string "COLLEAGUE: Genesis City clears you.\n"
	.string "Final desk: AURELIA SUMMIT--Mentor.$"

EasternAurelia_Hall_Text_ColleagueDone:
	.string "COLLEAGUE: Genesis City stays open.\n"
	.string "Use every tool you've collected.$"

EasternAurelia_Hall_Text_MentorIntro:
	.string "MENTOR: AURELIA SUMMIT--east desk.\n"
	.string "Not a throne. A threshold.\p"
	.string "Ascension is the bond you forged.\n"
	.string "Show me everything!$"

EasternAurelia_Hall_Text_MentorDefeat:
	.string "You have ascended…$"

EasternAurelia_Hall_Text_GotAscensionBadge:
	.string "{PLAYER} received the ASCENSION BADGE!$"

EasternAurelia_Hall_Text_MentorAfter:
	.string "MENTOR: Eastern AURELIA recognizes you.\n"
	.string "Seek the legendaries with our researcher,\l"
	.string "and the WORLD TOURNAMENT at the Tower.$"

EasternAurelia_Hall_Text_MentorDone:
	.string "MENTOR: The Summit watches your path.\n"
	.string "Legends, Frontier, Tournament--choose.$"

EasternAurelia_Hall_Text_LegendEarly:
	.string "Return when you are CHAMPION.\n"
	.string "The legends will answer then.$"

EasternAurelia_Hall_Text_SanctumOffer:
	.string "The LEGEND SANCTUM is open to you.\n"
	.string "Shall I show you the three foci?$"

EasternAurelia_Hall_Text_SanctumWarp:
	.string "This way--tread carefully.$"

EasternAurelia_Hall_Text_ClerkWelcome:
	.string "Eastern AURELIA HALL clerk.\n"
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
	.string "Back row: MIRAGE · VERDANTIS ·\n"
	.string "OBSIDIAN · ASTRAL.\p"
	.string "Front row: TIDYMOON · EON ·\n"
	.string "GENESIS CITY · SUMMIT EAST.\p"
	.string "Researcher (center): Legend Sanctum.\n"
	.string "Exit warps return to Reception Gate.$"

EasternAurelia_Hall_Text_DeskMirage:
	.string "MIRAGE CITY desk -- Badge 9\n"
	.string "LEADER IRIS · PSYCHIC · Mirage Badge$"

EasternAurelia_Hall_Text_DeskVerdantis:
	.string "VERDANTIS CITY desk -- Badge 10\n"
	.string "LEADER CELIA · BUG · Jungle Badge$"

EasternAurelia_Hall_Text_DeskObsidian:
	.string "OBSIDIAN CITY desk -- Badge 11\n"
	.string "LEADER NOCTIS · DARK · Obsidian Badge$"

EasternAurelia_Hall_Text_DeskAstral:
	.string "ASTRAL CITY desk -- Badge 12\n"
	.string "LEADER DRAKE · DRAGON · Astral / Tera$"

EasternAurelia_Hall_Text_DeskTidymoon:
	.string "TIDYMOON CITY desk -- Badge 13\n"
	.string "LEADER LUNA · FAIRY · Moon Badge$"

EasternAurelia_Hall_Text_DeskEon:
	.string "EON CITY desk -- Badge 14\n"
	.string "LEADER MORRIGAN · GHOST · Eon Badge$"

EasternAurelia_Hall_Text_DeskGenesis:
	.string "GENESIS CITY desk -- Badge 15\n"
	.string "COLLEAGUE · MIXED · Genesis Badge$"

EasternAurelia_Hall_Text_DeskSummit:
	.string "AURELIA SUMMIT (east) -- Badge 16\n"
	.string "MENTOR · MIXED · Ascension Badge$"

EasternAurelia_Hall_Text_HallDirectory:
	.string "EASTERN AURELIA HALL\n"
	.string "City desks 9-16 · Legend Sanctum warp\p"
	.string "Access: Fly to BATTLE FRONTIER, then\n"
	.string "ask the Reception Gate greeter.$"
