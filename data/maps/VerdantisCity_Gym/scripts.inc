@ VERDANTIS CITY GYM -- Bug / CELIA / Badge 10 (moved from EasternAurelia_Hall desk).
@ Needs the previous badge (IRIS); Tera unlock stays with DRAKE (Badge 12) in the Eastern Hall.

VerdantisCity_Gym_MapScripts::
	.byte 0

VerdantisCity_Gym_EventScript_Celia::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_09_GET, VerdantisCity_Gym_EventScript_NeedPrev
	goto_if_set FLAG_GENESIS_BADGE_10_GET, VerdantisCity_Gym_EventScript_CeliaDone
	msgbox VerdantisCity_Gym_Text_CeliaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VerdantisCity_Gym_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_CELIA, VerdantisCity_Gym_Text_CeliaDefeat
	message VerdantisCity_Gym_Text_GotJungleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_10_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox VerdantisCity_Gym_Text_CeliaAfter, MSGBOX_DEFAULT
	release
	end

VerdantisCity_Gym_EventScript_CeliaDone::
	msgbox VerdantisCity_Gym_Text_CeliaRematchAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VerdantisCity_Gym_EventScript_CeliaDoneEnd
	trainerbattle_no_intro TRAINER_GENESIS_CELIA, VerdantisCity_Gym_Text_CeliaDefeat
VerdantisCity_Gym_EventScript_CeliaDoneEnd::
	msgbox VerdantisCity_Gym_Text_CeliaDone, MSGBOX_DEFAULT
	release
	end

VerdantisCity_Gym_EventScript_NeedPrev::
	msgbox VerdantisCity_Gym_Text_NeedPrev, MSGBOX_DEFAULT
	release
	end

VerdantisCity_Gym_EventScript_Decline::
	msgbox VerdantisCity_Gym_Text_Decline, MSGBOX_DEFAULT
	release
	end

VerdantisCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_10_GET, VerdantisCity_Gym_EventScript_GymGuidePostVictory
	msgbox VerdantisCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

VerdantisCity_Gym_EventScript_GymGuidePostVictory::
	msgbox VerdantisCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

VerdantisCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_10_GET, VerdantisCity_Gym_EventScript_GymStatueCertified
	goto VerdantisCity_Gym_EventScript_GymStatue
	end

VerdantisCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_10_GET, VerdantisCity_Gym_EventScript_GymStatueCertified
	goto VerdantisCity_Gym_EventScript_GymStatue
	end

VerdantisCity_Gym_EventScript_GymStatueCertified::
	msgbox VerdantisCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

VerdantisCity_Gym_EventScript_GymStatue::
	msgbox VerdantisCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

VerdantisCity_Gym_Text_Decline:
	.string "Return when the canopy calls.$"

VerdantisCity_Gym_Text_NeedPrev:
	.string "CELIA: Verdantis waits its turn.\nClear IRIS's MIRAGE CITY gym first.$"

VerdantisCity_Gym_Text_CeliaIntro:
	.string "CELIA: VERDANTIS CITY GYM, reporting!\nRainforest canopies, buzzing trails…\pMy BUG swarm thrives on motion.\nReady for the jungle challenge?$"

VerdantisCity_Gym_Text_CeliaDefeat:
	.string "My swarm fell… Take this!$"

VerdantisCity_Gym_Text_GotJungleBadge:
	.string "{PLAYER} received the JUNGLE BADGE!$"

VerdantisCity_Gym_Text_CeliaAfter:
	.string "CELIA: Grow wild like Verdantis vines.\nNext: OBSIDIAN CITY--NOCTIS waits.$"

VerdantisCity_Gym_Text_CeliaRematchAsk:
	.string "CELIA: The swarm is still buzzing.\n"
	.string "Want another rematch?$"

VerdantisCity_Gym_Text_CeliaDone:
	.string "CELIA: Verdantis keeps blooming.\nCome back when you need green noise.$"

VerdantisCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to VERDANTIS CITY GYM!\pCELIA uses BUG-type POKéMON.\pThey're tough against GRASS, PSYCHIC\nand DARK, but weak to FIRE, FLYING,\land ROCK.\pGo get that JUNGLE BADGE!$"

VerdantisCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\nThe JUNGLE BADGE is yours!\pEight more desks wait in EASTERN\nAURELIA HALL.$"

VerdantisCity_Gym_Text_GymStatue:
	.string "VERDANTIS CITY POKéMON GYM$"

VerdantisCity_Gym_Text_GymStatueCertified:
	.string "VERDANTIS CITY POKéMON GYM\p"
	.string "CELIA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
