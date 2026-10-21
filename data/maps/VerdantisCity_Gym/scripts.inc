VerdantisCity_Gym_MapScripts::
	.byte 0

VerdantisCity_Gym_EventScript_Celia::
	trainerbattle_single TRAINER_GENESIS_CELIA, VerdantisCity_Gym_Text_CeliaIntro, VerdantisCity_Gym_Text_CeliaDefeat, VerdantisCity_Gym_EventScript_CeliaDefeated, NO_MUSIC
	goto_if_set FLAG_GENESIS_BADGE_10_GET, VerdantisCity_Gym_EventScript_CeliaPostBadge
	release
	end

VerdantisCity_Gym_EventScript_CeliaDefeated::
	message VerdantisCity_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VerdantisCity_Gym_Text_BadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_GENESIS_BADGE_10_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox VerdantisCity_Gym_Text_CeliaAfter, MSGBOX_DEFAULT
	release
	end

VerdantisCity_Gym_EventScript_CeliaPostBadge::
	msgbox VerdantisCity_Gym_Text_CeliaDone, MSGBOX_DEFAULT
	release
	end

VerdantisCity_Gym_EventScript_TrainerA::
	trainerbattle_single TRAINER_GENESIS_VERDANTIS_A, VerdantisCity_Gym_Text_TrainerAIntro, VerdantisCity_Gym_Text_TrainerADefeat
	msgbox VerdantisCity_Gym_Text_TrainerAPost, MSGBOX_AUTOCLOSE
	end

VerdantisCity_Gym_EventScript_TrainerB::
	trainerbattle_single TRAINER_GENESIS_VERDANTIS_B, VerdantisCity_Gym_Text_TrainerBIntro, VerdantisCity_Gym_Text_TrainerBDefeat
	msgbox VerdantisCity_Gym_Text_TrainerBPost, MSGBOX_AUTOCLOSE
	end

VerdantisCity_Gym_EventScript_TrainerC::
	trainerbattle_single TRAINER_GENESIS_VERDANTIS_C, VerdantisCity_Gym_Text_TrainerCIntro, VerdantisCity_Gym_Text_TrainerCDefeat
	msgbox VerdantisCity_Gym_Text_TrainerCPost, MSGBOX_AUTOCLOSE
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

VerdantisCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to VERDANTIS CITY GYM!\p"
	.string "CELIA uses BUG-type POKéMON.\pThey're strong against GRASS, PSYCHIC,\nand DARK, but watch for FIRE, FLYING,\land ROCK moves.\p"
	.string "Claim the JUNGLE BADGE!$"

VerdantisCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The JUNGLE BADGE is yours!$"

VerdantisCity_Gym_Text_TrainerAIntro:
	.string "This GYM tests your resolve!$"

VerdantisCity_Gym_Text_TrainerADefeat:
	.string "You broke through…$"

VerdantisCity_Gym_Text_TrainerAPost:
	.string "CELIA is still ahead.$"

VerdantisCity_Gym_Text_TrainerBIntro:
	.string "Don't underestimate us!$"

VerdantisCity_Gym_Text_TrainerBDefeat:
	.string "Sharp work…$"

VerdantisCity_Gym_Text_TrainerBPost:
	.string "Trust your team.$"

VerdantisCity_Gym_Text_TrainerCIntro:
	.string "Pressure incoming!$"

VerdantisCity_Gym_Text_TrainerCDefeat:
	.string "My plan broke…$"

VerdantisCity_Gym_Text_TrainerCPost:
	.string "The JUNGLE BADGE opens the path ahead.$"

VerdantisCity_Gym_Text_CeliaIntro:
	.string "CELIA: Welcome to VERDANTIS CITY GYM.\n"
	.string "I am the BUG LEADER.\p"
	.string "Show me your strength--shall we begin?$"

VerdantisCity_Gym_Text_CeliaDefeat:
	.string "Well fought… The city is yours to stamp.$"

VerdantisCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the JUNGLE BADGE\n"
	.string "from CELIA!$"

VerdantisCity_Gym_Text_BadgeInfo:
	.string "CELIA: With the JUNGLE BADGE, your\n"
	.string "Eastern Aurelia journey deepens.\p"
	.string "Return to the Hall when you're ready\n"
	.string "for the next city.$"

VerdantisCity_Gym_Text_CeliaAfter:
	.string "CELIA: VERDANTIS CITY stamps your path.\n"
	.string "Carry what you learned.$"

VerdantisCity_Gym_Text_CeliaDone:
	.string "CELIA: The teleport net still hums.\n"
	.string "Walk tall, Champion.$"

VerdantisCity_Gym_Text_GymStatue:
	.string "VERDANTIS CITY POKéMON GYM$"

VerdantisCity_Gym_Text_GymStatueCertified:
	.string "VERDANTIS CITY POKéMON GYM\p"
	.string "CELIA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
