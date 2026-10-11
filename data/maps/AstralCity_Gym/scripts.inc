@ ASTRAL CITY GYM -- Dragon / DRAKE / Badge 12 (moved from EasternAurelia_Hall desk).
@ Needs the previous badge (NOCTIS) (Tera unlock stays here on DRAKE's win).

AstralCity_Gym_MapScripts::
	.byte 0

AstralCity_Gym_EventScript_Drake::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_11_GET, AstralCity_Gym_EventScript_NeedPrev
	goto_if_set FLAG_GENESIS_BADGE_12_GET, AstralCity_Gym_EventScript_DrakeDone
	msgbox AstralCity_Gym_Text_DrakeIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, AstralCity_Gym_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_DRAKE_GYM, AstralCity_Gym_Text_DrakeDefeat
	message AstralCity_Gym_Text_GotAstralBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_12_GET
	setflag FLAG_GENESIS_TERA_UNLOCKED
	setflag FLAG_SYS_TERA_ORB_CHARGED
	call Genesis_EventScript_UpdateLevelCap
	msgbox AstralCity_Gym_Text_DrakeAfter, MSGBOX_DEFAULT
	release
	end

AstralCity_Gym_EventScript_DrakeDone::
	msgbox AstralCity_Gym_Text_DrakeRematchAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, AstralCity_Gym_EventScript_DrakeDoneEnd
	trainerbattle_no_intro TRAINER_GENESIS_DRAKE_GYM, AstralCity_Gym_Text_DrakeDefeat
AstralCity_Gym_EventScript_DrakeDoneEnd::
	msgbox AstralCity_Gym_Text_DrakeDone, MSGBOX_DEFAULT
	release
	end

AstralCity_Gym_EventScript_NeedPrev::
	msgbox AstralCity_Gym_Text_NeedPrev, MSGBOX_DEFAULT
	release
	end

AstralCity_Gym_EventScript_Decline::
	msgbox AstralCity_Gym_Text_Decline, MSGBOX_DEFAULT
	release
	end

AstralCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_12_GET, AstralCity_Gym_EventScript_GymGuidePostVictory
	msgbox AstralCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

AstralCity_Gym_EventScript_GymGuidePostVictory::
	msgbox AstralCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

AstralCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_12_GET, AstralCity_Gym_EventScript_GymStatueCertified
	goto AstralCity_Gym_EventScript_GymStatue
	end

AstralCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_12_GET, AstralCity_Gym_EventScript_GymStatueCertified
	goto AstralCity_Gym_EventScript_GymStatue
	end

AstralCity_Gym_EventScript_GymStatueCertified::
	msgbox AstralCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

AstralCity_Gym_EventScript_GymStatue::
	msgbox AstralCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

AstralCity_Gym_Text_Decline:
	.string "Return when the tide of battle calls.$"

AstralCity_Gym_Text_NeedPrev:
	.string "DRAKE: Astral City's stars won't turn\n"
	.string "until NOCTIS yields the OBSIDIAN BADGE.$"

AstralCity_Gym_Text_DrakeIntro:
	.string "DRAKE: ASTRAL CITY GYM--observatory\n"
	.string "of Eastern AURELIA.\p"
	.string "My DRAGONS chart the sky.\n"
	.string "Win, and TERA energy crystallizes!$"

AstralCity_Gym_Text_DrakeDefeat:
	.string "The stars align for you…$"

AstralCity_Gym_Text_GotAstralBadge:
	.string "{PLAYER} received the ASTRAL BADGE!$"

AstralCity_Gym_Text_DrakeAfter:
	.string "DRAKE: Feel GENESIS ENERGY crystallize.\n"
	.string "TERASTALLIZATION answers you now.\p"
	.string "Next desk: TIDYMOON CITY--LUNA.$"

AstralCity_Gym_Text_DrakeRematchAsk:
	.string "DRAKE: The dragons still circle the sky.\n"
	.string "Ready for a rematch?$"

AstralCity_Gym_Text_DrakeDone:
	.string "DRAKE: Astral's scopes still track you.\n"
	.string "Shape the battlefield as you will.$"

AstralCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to ASTRAL CITY GYM!\p"
	.string "DRAKE uses DRAGON-type POKéMON.\p"
	.string "They're tough against FIRE, WATER,\nELECTRIC and GRASS, but weak to\lICE, DRAGON, and FAIRY.\p"
	.string "Go get that ASTRAL BADGE!$"

AstralCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The ASTRAL BADGE is yours!\p"
	.string "Six more desks wait in EASTERN\nAURELIA HALL.$"

AstralCity_Gym_Text_GymStatue:
	.string "ASTRAL CITY POKéMON GYM$"

AstralCity_Gym_Text_GymStatueCertified:
	.string "ASTRAL CITY POKéMON GYM\p"
	.string "DRAKE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
