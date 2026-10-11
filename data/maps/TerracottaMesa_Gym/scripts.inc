@ TERRACOTTA MESA GYM -- Ground / TERRA / Badge 18 (moved from EasternAurelia_Hall desk).
@ Needs the previous badge (VESPER).

TerracottaMesa_Gym_MapScripts::
	.byte 0

TerracottaMesa_Gym_EventScript_Terra::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_17_GET, TerracottaMesa_Gym_EventScript_NeedPrev
	goto_if_set FLAG_GENESIS_BADGE_18_GET, TerracottaMesa_Gym_EventScript_TerraDone
	msgbox TerracottaMesa_Gym_Text_TerraIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TerracottaMesa_Gym_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_TERRA, TerracottaMesa_Gym_Text_TerraDefeat
	message TerracottaMesa_Gym_Text_GotTerraBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_18_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox TerracottaMesa_Gym_Text_TerraAfter, MSGBOX_DEFAULT
	release
	end

TerracottaMesa_Gym_EventScript_TerraDone::
	msgbox TerracottaMesa_Gym_Text_TerraRematchAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TerracottaMesa_Gym_EventScript_TerraDoneEnd
	trainerbattle_no_intro TRAINER_GENESIS_TERRA, TerracottaMesa_Gym_Text_TerraDefeat
TerracottaMesa_Gym_EventScript_TerraDoneEnd::
	msgbox TerracottaMesa_Gym_Text_TerraDone, MSGBOX_DEFAULT
	release
	end

TerracottaMesa_Gym_EventScript_NeedPrev::
	msgbox TerracottaMesa_Gym_Text_NeedPrev, MSGBOX_DEFAULT
	release
	end

TerracottaMesa_Gym_EventScript_Decline::
	msgbox TerracottaMesa_Gym_Text_Decline, MSGBOX_DEFAULT
	release
	end

TerracottaMesa_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_18_GET, TerracottaMesa_Gym_EventScript_GymGuidePostVictory
	msgbox TerracottaMesa_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

TerracottaMesa_Gym_EventScript_GymGuidePostVictory::
	msgbox TerracottaMesa_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

TerracottaMesa_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_18_GET, TerracottaMesa_Gym_EventScript_GymStatueCertified
	goto TerracottaMesa_Gym_EventScript_GymStatue
	end

TerracottaMesa_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_18_GET, TerracottaMesa_Gym_EventScript_GymStatueCertified
	goto TerracottaMesa_Gym_EventScript_GymStatue
	end

TerracottaMesa_Gym_EventScript_GymStatueCertified::
	msgbox TerracottaMesa_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

TerracottaMesa_Gym_EventScript_GymStatue::
	msgbox TerracottaMesa_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

TerracottaMesa_Gym_Text_Decline:
	.string "Return when the tide of battle calls.$"

TerracottaMesa_Gym_Text_NeedPrev:
	.string "TERRA: Earn VESPER's VENOM BADGE\n"
	.string "before the mesa will shift for you.$"

TerracottaMesa_Gym_Text_TerraIntro:
	.string "TERRA: TERRACOTTA MESA GYM.\n"
	.string "GROUND endures when empires fall.\p"
	.string "Stand firm--or be buried!$"

TerracottaMesa_Gym_Text_TerraDefeat:
	.string "The land… accepts you.$"

TerracottaMesa_Gym_Text_GotTerraBadge:
	.string "{PLAYER} received the TERRA BADGE!$"

TerracottaMesa_Gym_Text_TerraAfter:
	.string "TERRA: All eighteen types answered.\n"
	.string "AURELIA's gym circuit is complete!\p"
	.string "GARCHOMP still patrols the mesa dunes.$"

TerracottaMesa_Gym_Text_TerraRematchAsk:
	.string "TERRA: The mesa still shifts underfoot.\n"
	.string "Care for a rematch?$"

TerracottaMesa_Gym_Text_TerraDone:
	.string "TERRA: Eighteen badges. Full spectrum.\n"
	.string "Ask the mesa plaque of GARCHOMP.$"

TerracottaMesa_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to TERRACOTTA MESA GYM!\p"
	.string "TERRA uses GROUND-type POKéMON.\p"
	.string "They're tough against POISON and ROCK,\nand ELECTRIC can't touch them.\lThey're weak to WATER, GRASS and ICE.\p"
	.string "Go get that TERRA BADGE!$"

TerracottaMesa_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The TERRA BADGE is yours!\p"
	.string "All eighteen badges are yours!\nThe EASTERN AURELIA HALL clerk\lhas a reward for you.$"

TerracottaMesa_Gym_Text_GymStatue:
	.string "TERRACOTTA MESA POKéMON GYM$"

TerracottaMesa_Gym_Text_GymStatueCertified:
	.string "TERRACOTTA MESA POKéMON GYM\p"
	.string "TERRA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
