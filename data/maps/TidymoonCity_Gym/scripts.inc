@ TIDYMOON CITY GYM -- Fairy / LUNA / Badge 13 (moved from EasternAurelia_Hall desk).
@ Needs the previous badge (DRAKE).

TidymoonCity_Gym_MapScripts::
	.byte 0

TidymoonCity_Gym_EventScript_Luna::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_12_GET, TidymoonCity_Gym_EventScript_NeedPrev
	goto_if_set FLAG_GENESIS_BADGE_13_GET, TidymoonCity_Gym_EventScript_LunaDone
	msgbox TidymoonCity_Gym_Text_LunaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TidymoonCity_Gym_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_LUNA, TidymoonCity_Gym_Text_LunaDefeat
	message TidymoonCity_Gym_Text_GotMoonBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_13_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox TidymoonCity_Gym_Text_LunaAfter, MSGBOX_DEFAULT
	release
	end

TidymoonCity_Gym_EventScript_LunaDone::
	msgbox TidymoonCity_Gym_Text_LunaRematchAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TidymoonCity_Gym_EventScript_LunaDoneEnd
	trainerbattle_no_intro TRAINER_GENESIS_LUNA, TidymoonCity_Gym_Text_LunaDefeat
TidymoonCity_Gym_EventScript_LunaDoneEnd::
	msgbox TidymoonCity_Gym_Text_LunaDone, MSGBOX_DEFAULT
	release
	end

TidymoonCity_Gym_EventScript_NeedPrev::
	msgbox TidymoonCity_Gym_Text_NeedPrev, MSGBOX_DEFAULT
	release
	end

TidymoonCity_Gym_EventScript_Decline::
	msgbox TidymoonCity_Gym_Text_Decline, MSGBOX_DEFAULT
	release
	end

TidymoonCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_13_GET, TidymoonCity_Gym_EventScript_GymGuidePostVictory
	msgbox TidymoonCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

TidymoonCity_Gym_EventScript_GymGuidePostVictory::
	msgbox TidymoonCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

TidymoonCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_13_GET, TidymoonCity_Gym_EventScript_GymStatueCertified
	goto TidymoonCity_Gym_EventScript_GymStatue
	end

TidymoonCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_13_GET, TidymoonCity_Gym_EventScript_GymStatueCertified
	goto TidymoonCity_Gym_EventScript_GymStatue
	end

TidymoonCity_Gym_EventScript_GymStatueCertified::
	msgbox TidymoonCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

TidymoonCity_Gym_EventScript_GymStatue::
	msgbox TidymoonCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

TidymoonCity_Gym_Text_Decline:
	.string "Return when the tide of battle calls.$"

TidymoonCity_Gym_Text_NeedPrev:
	.string "LUNA: Tidymoon's tide follows the stars.\n"
	.string "Challenge DRAKE for the ASTRAL BADGE.$"

TidymoonCity_Gym_Text_LunaIntro:
	.string "LUNA: TIDYMOON CITY GYM--tide pools,\n"
	.string "island lights, soft FAIRY glow.\p"
	.string "Dance with me under the moon?$"

TidymoonCity_Gym_Text_LunaDefeat:
	.string "The moon sets… Beautiful battle.$"

TidymoonCity_Gym_Text_GotMoonBadge:
	.string "{PLAYER} received the MOON BADGE!$"

TidymoonCity_Gym_Text_LunaAfter:
	.string "LUNA: Soft power still wins wars.\n"
	.string "EON CITY's desk--MORRIGAN--is next.$"

TidymoonCity_Gym_Text_LunaRematchAsk:
	.string "LUNA: Moonlight still favors bold trainers.\n"
	.string "Fight me again?$"

TidymoonCity_Gym_Text_LunaDone:
	.string "LUNA: Tidymoon's waves remember you.\n"
	.string "Kindness is not weakness, Champion.$"

TidymoonCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to TIDYMOON CITY GYM!\p"
	.string "LUNA uses FAIRY-type POKéMON.\p"
	.string "They're tough against FIGHTING, BUG\nand DARK, and DRAGON moves can't\ltouch them. But POISON and STEEL\lhit them hard.\p"
	.string "Go get that MOON BADGE!$"

TidymoonCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The MOON BADGE is yours!\p"
	.string "Five more desks wait in EASTERN\nAURELIA HALL.$"

TidymoonCity_Gym_Text_GymStatue:
	.string "TIDYMOON CITY POKéMON GYM$"

TidymoonCity_Gym_Text_GymStatueCertified:
	.string "TIDYMOON CITY POKéMON GYM\p"
	.string "LUNA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
