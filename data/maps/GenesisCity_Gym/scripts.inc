GenesisCity_Gym_MapScripts::
	.byte 0

GenesisCity_Gym_EventScript_Colleague::
	trainerbattle_single TRAINER_GENESIS_COLLEAGUE, GenesisCity_Gym_Text_ColleagueIntro, GenesisCity_Gym_Text_ColleagueDefeat, GenesisCity_Gym_EventScript_ColleagueDefeated, NO_MUSIC
	goto_if_set FLAG_GENESIS_BADGE_15_GET, GenesisCity_Gym_EventScript_ColleaguePostBadge
	release
	end

GenesisCity_Gym_EventScript_ColleagueDefeated::
	message GenesisCity_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GenesisCity_Gym_Text_BadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_GENESIS_BADGE_15_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox GenesisCity_Gym_Text_ColleagueAfter, MSGBOX_DEFAULT
	release
	end

GenesisCity_Gym_EventScript_ColleaguePostBadge::
	msgbox GenesisCity_Gym_Text_ColleagueDone, MSGBOX_DEFAULT
	release
	end

GenesisCity_Gym_EventScript_TrainerA::
	trainerbattle_single TRAINER_GENESIS_GENESISCITY_A, GenesisCity_Gym_Text_TrainerAIntro, GenesisCity_Gym_Text_TrainerADefeat
	msgbox GenesisCity_Gym_Text_TrainerAPost, MSGBOX_AUTOCLOSE
	end

GenesisCity_Gym_EventScript_TrainerB::
	trainerbattle_single TRAINER_GENESIS_GENESISCITY_B, GenesisCity_Gym_Text_TrainerBIntro, GenesisCity_Gym_Text_TrainerBDefeat
	msgbox GenesisCity_Gym_Text_TrainerBPost, MSGBOX_AUTOCLOSE
	end

GenesisCity_Gym_EventScript_TrainerC::
	trainerbattle_single TRAINER_GENESIS_GENESISCITY_C, GenesisCity_Gym_Text_TrainerCIntro, GenesisCity_Gym_Text_TrainerCDefeat
	msgbox GenesisCity_Gym_Text_TrainerCPost, MSGBOX_AUTOCLOSE
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

GenesisCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to GENESIS CITY GYM!\p"
	.string "COLLEAGUE uses mixed teams--no single type owns\nthis city. Bring coverage and\nstatus answers.\p"
	.string "Claim the GENESIS BADGE!$"

GenesisCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The GENESIS BADGE is yours!$"

GenesisCity_Gym_Text_TrainerAIntro:
	.string "This GYM tests your resolve!$"

GenesisCity_Gym_Text_TrainerADefeat:
	.string "You broke through…$"

GenesisCity_Gym_Text_TrainerAPost:
	.string "COLLEAGUE is still ahead.$"

GenesisCity_Gym_Text_TrainerBIntro:
	.string "Don't underestimate us!$"

GenesisCity_Gym_Text_TrainerBDefeat:
	.string "Sharp work…$"

GenesisCity_Gym_Text_TrainerBPost:
	.string "Trust your team.$"

GenesisCity_Gym_Text_TrainerCIntro:
	.string "Pressure incoming!$"

GenesisCity_Gym_Text_TrainerCDefeat:
	.string "My plan broke…$"

GenesisCity_Gym_Text_TrainerCPost:
	.string "The GENESIS BADGE opens the path ahead.$"

GenesisCity_Gym_Text_ColleagueIntro:
	.string "COLLEAGUE: Welcome to GENESIS CITY GYM.\n"
	.string "I am the MIXED LEADER.\p"
	.string "Show me your strength--shall we begin?$"

GenesisCity_Gym_Text_ColleagueDefeat:
	.string "Well fought… The city is yours to stamp.$"

GenesisCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the GENESIS BADGE\n"
	.string "from COLLEAGUE!$"

GenesisCity_Gym_Text_BadgeInfo:
	.string "COLLEAGUE: With the GENESIS BADGE, your\n"
	.string "Eastern Aurelia journey deepens.\p"
	.string "Return to the Hall when you're ready\n"
	.string "for the next city.$"

GenesisCity_Gym_Text_ColleagueAfter:
	.string "COLLEAGUE: GENESIS CITY stamps your path.\n"
	.string "Carry what you learned.$"

GenesisCity_Gym_Text_ColleagueDone:
	.string "COLLEAGUE: The teleport net still hums.\n"
	.string "Walk tall, Champion.$"

GenesisCity_Gym_Text_GymStatue:
	.string "GENESIS CITY POKéMON GYM$"

GenesisCity_Gym_Text_GymStatueCertified:
	.string "GENESIS CITY POKéMON GYM\p"
	.string "COLLEAGUE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
