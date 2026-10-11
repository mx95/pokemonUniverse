@ EON CITY GYM -- Ghost / MORRIGAN / Badge 14 (moved from EasternAurelia_Hall desk).
@ Needs the previous badge (LUNA).

EonCity_Gym_MapScripts::
	.byte 0

EonCity_Gym_EventScript_Morrigan::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_13_GET, EonCity_Gym_EventScript_NeedPrev
	goto_if_set FLAG_GENESIS_BADGE_14_GET, EonCity_Gym_EventScript_MorriganDone
	msgbox EonCity_Gym_Text_MorriganIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EonCity_Gym_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_MORRIGAN, EonCity_Gym_Text_MorriganDefeat
	message EonCity_Gym_Text_GotEonBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_14_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox EonCity_Gym_Text_MorriganAfter, MSGBOX_DEFAULT
	release
	end

EonCity_Gym_EventScript_MorriganDone::
	msgbox EonCity_Gym_Text_MorriganRematchAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EonCity_Gym_EventScript_MorriganDoneEnd
	trainerbattle_no_intro TRAINER_GENESIS_MORRIGAN, EonCity_Gym_Text_MorriganDefeat
EonCity_Gym_EventScript_MorriganDoneEnd::
	msgbox EonCity_Gym_Text_MorriganDone, MSGBOX_DEFAULT
	release
	end

EonCity_Gym_EventScript_NeedPrev::
	msgbox EonCity_Gym_Text_NeedPrev, MSGBOX_DEFAULT
	release
	end

EonCity_Gym_EventScript_Decline::
	msgbox EonCity_Gym_Text_Decline, MSGBOX_DEFAULT
	release
	end

EonCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_14_GET, EonCity_Gym_EventScript_GymGuidePostVictory
	msgbox EonCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

EonCity_Gym_EventScript_GymGuidePostVictory::
	msgbox EonCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

EonCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_14_GET, EonCity_Gym_EventScript_GymStatueCertified
	goto EonCity_Gym_EventScript_GymStatue
	end

EonCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_14_GET, EonCity_Gym_EventScript_GymStatueCertified
	goto EonCity_Gym_EventScript_GymStatue
	end

EonCity_Gym_EventScript_GymStatueCertified::
	msgbox EonCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

EonCity_Gym_EventScript_GymStatue::
	msgbox EonCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

EonCity_Gym_Text_Decline:
	.string "Return when the tide of battle calls.$"

EonCity_Gym_Text_NeedPrev:
	.string "MORRIGAN: Eon's spirits keep to order.\n"
	.string "Bring LUNA's MOON BADGE first.$"

EonCity_Gym_Text_MorriganIntro:
	.string "MORRIGAN: EON CITY GYM.\n"
	.string "Where spirits linger between eras…\p"
	.string "Face my GHOSTS, if you dare.$"

EonCity_Gym_Text_MorriganDefeat:
	.string "Even spirits bow to you…$"

EonCity_Gym_Text_GotEonBadge:
	.string "{PLAYER} received the EON BADGE!$"

EonCity_Gym_Text_MorriganAfter:
	.string "MORRIGAN: Honor what lingers in Eon.\n"
	.string "GENESIS CITY--the Colleague--awaits.$"

EonCity_Gym_Text_MorriganRematchAsk:
	.string "MORRIGAN: Echoes of the lost still linger.\n"
	.string "Care for a rematch?$"

EonCity_Gym_Text_MorriganDone:
	.string "MORRIGAN: Eon's bells still toll for you.\n"
	.string "Listen when the past whispers.$"

EonCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to EON CITY GYM!\p"
	.string "MORRIGAN uses GHOST-type POKéMON.\p"
	.string "They're tough against POISON and BUG,\nand NORMAL and FIGHTING can't touch\lthem. They're weak to GHOST and DARK.\p"
	.string "Go get that EON BADGE!$"

EonCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The EON BADGE is yours!\p"
	.string "Four more desks wait in EASTERN\nAURELIA HALL.$"

EonCity_Gym_Text_GymStatue:
	.string "EON CITY POKéMON GYM$"

EonCity_Gym_Text_GymStatueCertified:
	.string "EON CITY POKéMON GYM\p"
	.string "MORRIGAN'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
