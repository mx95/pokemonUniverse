AstralCity_Gym_MapScripts::
	.byte 0

AstralCity_Gym_EventScript_Drake::
	trainerbattle_single TRAINER_GENESIS_DRAKE_GYM, AstralCity_Gym_Text_DrakeIntro, AstralCity_Gym_Text_DrakeDefeat, AstralCity_Gym_EventScript_DrakeDefeated, NO_MUSIC
	goto_if_set FLAG_GENESIS_BADGE_12_GET, AstralCity_Gym_EventScript_DrakePostBadge
	release
	end

AstralCity_Gym_EventScript_DrakeDefeated::
	message AstralCity_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox AstralCity_Gym_Text_BadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_GENESIS_BADGE_12_GET
	setflag FLAG_GENESIS_TERA_UNLOCKED
	setflag FLAG_SYS_TERA_ORB_CHARGED
	call Genesis_EventScript_UpdateLevelCap
	msgbox AstralCity_Gym_Text_DrakeAfter, MSGBOX_DEFAULT
	release
	end

AstralCity_Gym_EventScript_DrakePostBadge::
	msgbox AstralCity_Gym_Text_DrakeDone, MSGBOX_DEFAULT
	release
	end

AstralCity_Gym_EventScript_TrainerA::
	trainerbattle_single TRAINER_GENESIS_ASTRAL_A, AstralCity_Gym_Text_TrainerAIntro, AstralCity_Gym_Text_TrainerADefeat
	msgbox AstralCity_Gym_Text_TrainerAPost, MSGBOX_AUTOCLOSE
	end

AstralCity_Gym_EventScript_TrainerB::
	trainerbattle_single TRAINER_GENESIS_ASTRAL_B, AstralCity_Gym_Text_TrainerBIntro, AstralCity_Gym_Text_TrainerBDefeat
	msgbox AstralCity_Gym_Text_TrainerBPost, MSGBOX_AUTOCLOSE
	end

AstralCity_Gym_EventScript_TrainerC::
	trainerbattle_single TRAINER_GENESIS_ASTRAL_C, AstralCity_Gym_Text_TrainerCIntro, AstralCity_Gym_Text_TrainerCDefeat
	msgbox AstralCity_Gym_Text_TrainerCPost, MSGBOX_AUTOCLOSE
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

AstralCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to ASTRAL CITY GYM!\p"
	.string "DRAKE uses DRAGON-type POKéMON.\pThey're strong against other DRAGONS\nin a clash, but watch for ICE,\nDRAGON, and FAIRY moves.\pWin here to unlock TERASTALLIZATION!\p"
	.string "Claim the ASTRAL BADGE!$"

AstralCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The ASTRAL BADGE is yours!$"

AstralCity_Gym_Text_TrainerAIntro:
	.string "This GYM tests your resolve!$"

AstralCity_Gym_Text_TrainerADefeat:
	.string "You broke through…$"

AstralCity_Gym_Text_TrainerAPost:
	.string "DRAKE is still ahead.$"

AstralCity_Gym_Text_TrainerBIntro:
	.string "Don't underestimate us!$"

AstralCity_Gym_Text_TrainerBDefeat:
	.string "Sharp work…$"

AstralCity_Gym_Text_TrainerBPost:
	.string "Trust your team.$"

AstralCity_Gym_Text_TrainerCIntro:
	.string "Pressure incoming!$"

AstralCity_Gym_Text_TrainerCDefeat:
	.string "My plan broke…$"

AstralCity_Gym_Text_TrainerCPost:
	.string "The ASTRAL BADGE opens the path ahead.$"

AstralCity_Gym_Text_DrakeIntro:
	.string "DRAKE: Welcome to ASTRAL CITY GYM.\n"
	.string "I am the DRAGON LEADER.\p"
	.string "Show me your strength--shall we begin?$"

AstralCity_Gym_Text_DrakeDefeat:
	.string "Well fought… The city is yours to stamp.$"

AstralCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the ASTRAL BADGE\n"
	.string "from DRAKE!$"

AstralCity_Gym_Text_BadgeInfo:
	.string "DRAKE: With the ASTRAL BADGE, your\n"
	.string "Eastern Aurelia journey deepens.\p"
	.string "Return to the Hall when you're ready\n"
	.string "for the next city.$"

AstralCity_Gym_Text_DrakeAfter:
	.string "DRAKE: ASTRAL CITY stamps your path.\n"
	.string "Carry what you learned.$"

AstralCity_Gym_Text_DrakeDone:
	.string "DRAKE: The teleport net still hums.\n"
	.string "Walk tall, Champion.$"

AstralCity_Gym_Text_GymStatue:
	.string "ASTRAL CITY POKéMON GYM$"

AstralCity_Gym_Text_GymStatueCertified:
	.string "ASTRAL CITY POKéMON GYM\p"
	.string "DRAKE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
