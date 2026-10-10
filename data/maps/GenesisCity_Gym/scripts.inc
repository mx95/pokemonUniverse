@ GENESIS CITY GYM -- Normal / COLLEAGUE / Badge 15 (moved from EasternAurelia_Hall desk).
@ Needs the previous badge (MORRIGAN).

GenesisCity_Gym_MapScripts::
	.byte 0

GenesisCity_Gym_EventScript_Colleague::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_14_GET, GenesisCity_Gym_EventScript_NeedPrev
	goto_if_set FLAG_GENESIS_BADGE_15_GET, GenesisCity_Gym_EventScript_ColleagueDone
	msgbox GenesisCity_Gym_Text_ColleagueIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GenesisCity_Gym_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_COLLEAGUE, GenesisCity_Gym_Text_ColleagueDefeat
	message GenesisCity_Gym_Text_GotGenesisBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_15_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox GenesisCity_Gym_Text_ColleagueAfter, MSGBOX_DEFAULT
	release
	end

GenesisCity_Gym_EventScript_ColleagueDone::
	msgbox GenesisCity_Gym_Text_ColleagueDone, MSGBOX_DEFAULT
	release
	end

GenesisCity_Gym_EventScript_NeedPrev::
	msgbox GenesisCity_Gym_Text_NeedPrev, MSGBOX_DEFAULT
	release
	end

GenesisCity_Gym_EventScript_Decline::
	msgbox GenesisCity_Gym_Text_Decline, MSGBOX_DEFAULT
	release
	end

GenesisCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_15_GET, GenesisCity_Gym_EventScript_GymGuidePostVictory
	msgbox GenesisCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

GenesisCity_Gym_EventScript_GymGuidePostVictory::
	msgbox GenesisCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

GenesisCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_15_GET, GenesisCity_Gym_EventScript_GymStatueCertified
	goto GenesisCity_Gym_EventScript_GymStatue
	end

GenesisCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_15_GET, GenesisCity_Gym_EventScript_GymStatueCertified
	goto GenesisCity_Gym_EventScript_GymStatue
	end

GenesisCity_Gym_EventScript_GymStatueCertified::
	msgbox GenesisCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

GenesisCity_Gym_EventScript_GymStatue::
	msgbox GenesisCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

GenesisCity_Gym_Text_Decline:
	.string "Return when the tide of battle calls.$"

GenesisCity_Gym_Text_NeedPrev:
	.string "COLLEAGUE: Genesis City only hosts\n"
	.string "those who hold MORRIGAN's EON BADGE.$"

GenesisCity_Gym_Text_ColleagueIntro:
	.string "COLLEAGUE: GENESIS CITY GYM--\n"
	.string "NORMAL-type specialist of the hub.\p"
	.string "Adaptability is our creed.\n"
	.string "Show me a Champion's toolkit!$"

GenesisCity_Gym_Text_ColleagueDefeat:
	.string "Preparation meets destiny…$"

GenesisCity_Gym_Text_GotGenesisBadge:
	.string "{PLAYER} received the GENESIS BADGE!$"

GenesisCity_Gym_Text_ColleagueAfter:
	.string "COLLEAGUE: Genesis City clears you.\n"
	.string "Next: AURELIA SUMMIT--Mentor's ROCK.$"

GenesisCity_Gym_Text_ColleagueDone:
	.string "COLLEAGUE: Ask our plaque about\n"
	.string "SLAKING--lazy power, NORMAL force.$"

GenesisCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to GENESIS CITY GYM!\p"
	.string "COLLEAGUE uses NORMAL-type POKéMON.\p"
	.string "They're plain but dependable.\nThey're weak to FIGHTING only, and\lGHOST moves can't touch them.\p"
	.string "Go get that GENESIS BADGE!$"

GenesisCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The GENESIS BADGE is yours!\p"
	.string "Three more desks wait in EASTERN\nAURELIA HALL.$"

GenesisCity_Gym_Text_GymStatue:
	.string "GENESIS CITY POKéMON GYM$"

GenesisCity_Gym_Text_GymStatueCertified:
	.string "GENESIS CITY POKéMON GYM\p"
	.string "COLLEAGUE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
