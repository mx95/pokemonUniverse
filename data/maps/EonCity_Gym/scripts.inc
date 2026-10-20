EonCity_Gym_MapScripts::
	.byte 0

EonCity_Gym_EventScript_Morrigan::
	trainerbattle_single TRAINER_GENESIS_MORRIGAN, EonCity_Gym_Text_MorriganIntro, EonCity_Gym_Text_MorriganDefeat, EonCity_Gym_EventScript_MorriganDefeated, NO_MUSIC
	goto_if_set FLAG_GENESIS_BADGE_14_GET, EonCity_Gym_EventScript_MorriganPostBadge
	release
	end

EonCity_Gym_EventScript_MorriganDefeated::
	message EonCity_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox EonCity_Gym_Text_BadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_GENESIS_BADGE_14_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox EonCity_Gym_Text_MorriganAfter, MSGBOX_DEFAULT
	release
	end

EonCity_Gym_EventScript_MorriganPostBadge::
	msgbox EonCity_Gym_Text_MorriganDone, MSGBOX_DEFAULT
	release
	end

EonCity_Gym_EventScript_TrainerA::
	trainerbattle_single TRAINER_GENESIS_EON_A, EonCity_Gym_Text_TrainerAIntro, EonCity_Gym_Text_TrainerADefeat
	msgbox EonCity_Gym_Text_TrainerAPost, MSGBOX_AUTOCLOSE
	end

EonCity_Gym_EventScript_TrainerB::
	trainerbattle_single TRAINER_GENESIS_EON_B, EonCity_Gym_Text_TrainerBIntro, EonCity_Gym_Text_TrainerBDefeat
	msgbox EonCity_Gym_Text_TrainerBPost, MSGBOX_AUTOCLOSE
	end

EonCity_Gym_EventScript_TrainerC::
	trainerbattle_single TRAINER_GENESIS_EON_C, EonCity_Gym_Text_TrainerCIntro, EonCity_Gym_Text_TrainerCDefeat
	msgbox EonCity_Gym_Text_TrainerCPost, MSGBOX_AUTOCLOSE
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

EonCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to EON CITY GYM!\p"
	.string "MORRIGAN uses GHOST-type POKéMON.\pThey're strong against PSYCHIC and\nGHOST, but watch for DARK and\nGHOST moves in return.\p"
	.string "Claim the EON BADGE!$"

EonCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The EON BADGE is yours!$"

EonCity_Gym_Text_TrainerAIntro:
	.string "This GYM tests your resolve!$"

EonCity_Gym_Text_TrainerADefeat:
	.string "You broke through…$"

EonCity_Gym_Text_TrainerAPost:
	.string "MORRIGAN is still ahead.$"

EonCity_Gym_Text_TrainerBIntro:
	.string "Don't underestimate us!$"

EonCity_Gym_Text_TrainerBDefeat:
	.string "Sharp work…$"

EonCity_Gym_Text_TrainerBPost:
	.string "Trust your team.$"

EonCity_Gym_Text_TrainerCIntro:
	.string "Pressure incoming!$"

EonCity_Gym_Text_TrainerCDefeat:
	.string "My plan broke…$"

EonCity_Gym_Text_TrainerCPost:
	.string "The EON BADGE opens the path ahead.$"

EonCity_Gym_Text_MorriganIntro:
	.string "MORRIGAN: Welcome to EON CITY GYM.\n"
	.string "I am the GHOST LEADER.\p"
	.string "Show me your strength--shall we begin?$"

EonCity_Gym_Text_MorriganDefeat:
	.string "Well fought… The city is yours to stamp.$"

EonCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the EON BADGE\n"
	.string "from MORRIGAN!$"

EonCity_Gym_Text_BadgeInfo:
	.string "MORRIGAN: With the EON BADGE, your\n"
	.string "Eastern Aurelia journey deepens.\p"
	.string "Return to the Hall when you're ready\n"
	.string "for the next city.$"

EonCity_Gym_Text_MorriganAfter:
	.string "MORRIGAN: EON CITY stamps your path.\n"
	.string "Carry what you learned.$"

EonCity_Gym_Text_MorriganDone:
	.string "MORRIGAN: The teleport net still hums.\n"
	.string "Walk tall, Champion.$"

EonCity_Gym_Text_GymStatue:
	.string "EON CITY POKéMON GYM$"

EonCity_Gym_Text_GymStatueCertified:
	.string "EON CITY POKéMON GYM\p"
	.string "MORRIGAN'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
