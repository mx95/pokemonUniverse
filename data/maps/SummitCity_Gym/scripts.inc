@ SUMMIT CITY GYM -- Rock / MENTOR / Badge 16 (moved from EasternAurelia_Hall desk).
@ Needs the previous badge (COLLEAGUE).

SummitCity_Gym_MapScripts::
	.byte 0

SummitCity_Gym_EventScript_Mentor::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_15_GET, SummitCity_Gym_EventScript_NeedPrev
	goto_if_set FLAG_GENESIS_BADGE_16_GET, SummitCity_Gym_EventScript_MentorDone
	msgbox SummitCity_Gym_Text_MentorIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SummitCity_Gym_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_MENTOR, SummitCity_Gym_Text_MentorDefeat
	message SummitCity_Gym_Text_GotAscensionBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_16_GET
	setvar VAR_GENESIS_STORY_STATE, GENESIS_STORY_EASTERN_DONE
	call Genesis_EventScript_UpdateLevelCap
	msgbox SummitCity_Gym_Text_MentorAfter, MSGBOX_DEFAULT
	release
	end

SummitCity_Gym_EventScript_MentorDone::
	msgbox SummitCity_Gym_Text_MentorDone, MSGBOX_DEFAULT
	release
	end

SummitCity_Gym_EventScript_NeedPrev::
	msgbox SummitCity_Gym_Text_NeedPrev, MSGBOX_DEFAULT
	release
	end

SummitCity_Gym_EventScript_Decline::
	msgbox SummitCity_Gym_Text_Decline, MSGBOX_DEFAULT
	release
	end

SummitCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_16_GET, SummitCity_Gym_EventScript_GymGuidePostVictory
	msgbox SummitCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SummitCity_Gym_EventScript_GymGuidePostVictory::
	msgbox SummitCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SummitCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_16_GET, SummitCity_Gym_EventScript_GymStatueCertified
	goto SummitCity_Gym_EventScript_GymStatue
	end

SummitCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_16_GET, SummitCity_Gym_EventScript_GymStatueCertified
	goto SummitCity_Gym_EventScript_GymStatue
	end

SummitCity_Gym_EventScript_GymStatueCertified::
	msgbox SummitCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SummitCity_Gym_EventScript_GymStatue::
	msgbox SummitCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SummitCity_Gym_Text_Decline:
	.string "Return when the tide of battle calls.$"

SummitCity_Gym_Text_NeedPrev:
	.string "MENTOR: The Summit GYM opens after\n"
	.string "you claim the GENESIS BADGE.$"

SummitCity_Gym_Text_MentorIntro:
	.string "MENTOR: SUMMIT CITY GYM--ROCK.\n"
	.string "Not a throne. A threshold of stone.\p"
	.string "Ascension is the bond you forged.\n"
	.string "Show me your bedrock!$"

SummitCity_Gym_Text_MentorDefeat:
	.string "You have ascended…$"

SummitCity_Gym_Text_GotAscensionBadge:
	.string "{PLAYER} received the ASCENSION BADGE!$"

SummitCity_Gym_Text_MentorAfter:
	.string "MENTOR: Stone yields to you.\n"
	.string "Two desks remain--VESPER's POISON\l"
	.string "in Venom Hollow, then TERRA's GROUND.$"

SummitCity_Gym_Text_MentorDone:
	.string "MENTOR: The Summit watches your path.\n"
	.string "VENOM HOLLOW and TERRACOTTA await.\p"
	.string "Also seek TYRANITAR at our plaque.$"

SummitCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to SUMMIT CITY GYM!\p"
	.string "MENTOR uses ROCK-type POKéMON.\p"
	.string "They're tough against NORMAL, FIRE,\nPOISON and FLYING, but weak to\lWATER, GRASS, FIGHTING, GROUND\land STEEL.\p"
	.string "Go get that ASCENSION BADGE!$"

SummitCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The ASCENSION BADGE is yours!\p"
	.string "Two more desks wait in EASTERN\nAURELIA HALL.$"

SummitCity_Gym_Text_GymStatue:
	.string "SUMMIT CITY POKéMON GYM$"

SummitCity_Gym_Text_GymStatueCertified:
	.string "SUMMIT CITY POKéMON GYM\p"
	.string "MENTOR'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
