@ MIRAGE CITY GYM -- Psychic / IRIS / Badge 9 (moved from EasternAurelia_Hall desk).
@ Tera unlock stays with DRAKE (Badge 12) in the Eastern Hall.

MirageCity_Gym_MapScripts::
	.byte 0

MirageCity_Gym_EventScript_Iris::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_09_GET, MirageCity_Gym_EventScript_IrisDone
	msgbox MirageCity_Gym_Text_IrisIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageCity_Gym_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_IRIS, MirageCity_Gym_Text_IrisDefeat
	message MirageCity_Gym_Text_GotMirageBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_09_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox MirageCity_Gym_Text_IrisAfter, MSGBOX_DEFAULT
	release
	end

MirageCity_Gym_EventScript_IrisDone::
	msgbox MirageCity_Gym_Text_IrisRematchAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageCity_Gym_EventScript_IrisDoneEnd
	trainerbattle_no_intro TRAINER_GENESIS_IRIS, MirageCity_Gym_Text_IrisDefeat
MirageCity_Gym_EventScript_IrisDoneEnd::
	msgbox MirageCity_Gym_Text_IrisDone, MSGBOX_DEFAULT
	release
	end

MirageCity_Gym_EventScript_Decline::
	msgbox MirageCity_Gym_Text_Decline, MSGBOX_DEFAULT
	release
	end

MirageCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_09_GET, MirageCity_Gym_EventScript_GymGuidePostVictory
	msgbox MirageCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MirageCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MirageCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MirageCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_09_GET, MirageCity_Gym_EventScript_GymStatueCertified
	goto MirageCity_Gym_EventScript_GymStatue
	end

MirageCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_09_GET, MirageCity_Gym_EventScript_GymStatueCertified
	goto MirageCity_Gym_EventScript_GymStatue
	end

MirageCity_Gym_EventScript_GymStatueCertified::
	msgbox MirageCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MirageCity_Gym_EventScript_GymStatue::
	msgbox MirageCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MirageCity_Gym_Text_Decline:
	.string "Return when your mind is clear.$"

MirageCity_Gym_Text_IrisIntro:
	.string "IRIS: Welcome to the MIRAGE CITY GYM.\n"
	.string "Our streets fold light into riddles.\p"
	.string "I am the PSYCHIC LEADER of Mirage.\n"
	.string "See through the veil--shall we begin?$"

MirageCity_Gym_Text_IrisDefeat:
	.string "The mirage clears… Well fought!$"

MirageCity_Gym_Text_GotMirageBadge:
	.string "{PLAYER} received the MIRAGE BADGE!$"

MirageCity_Gym_Text_IrisAfter:
	.string "IRIS: Mirage City stamps your path.\n"
	.string "Next desk: VERDANTIS--CELIA awaits.$"

MirageCity_Gym_Text_IrisRematchAsk:
	.string "IRIS: The MIRAGE CITY challenge never\n"
	.string "fades. Care for a rematch?$"

MirageCity_Gym_Text_IrisDone:
	.string "IRIS: Mirage City's teleport net still\n"
	.string "hums for you. Trust what you perceive.$"

MirageCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to MIRAGE CITY GYM!\p"
	.string "IRIS uses PSYCHIC-type POKéMON.\p"
	.string "They're tough against FIGHTING and\n"
	.string "POISON, but weak to BUG, GHOST,\l"
	.string "and DARK.\p"
	.string "Go get that MIRAGE BADGE!$"

MirageCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The MIRAGE BADGE is yours!\p"
	.string "Nine more desks wait in EASTERN\n"
	.string "AURELIA HALL.$"

MirageCity_Gym_Text_GymStatue:
	.string "MIRAGE CITY POKéMON GYM$"

MirageCity_Gym_Text_GymStatueCertified:
	.string "MIRAGE CITY POKéMON GYM\p"
	.string "IRIS'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
