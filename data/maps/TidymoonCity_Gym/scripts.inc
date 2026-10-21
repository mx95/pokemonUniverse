TidymoonCity_Gym_MapScripts::
	.byte 0

TidymoonCity_Gym_EventScript_Luna::
	trainerbattle_single TRAINER_GENESIS_LUNA, TidymoonCity_Gym_Text_LunaIntro, TidymoonCity_Gym_Text_LunaDefeat, TidymoonCity_Gym_EventScript_LunaDefeated, NO_MUSIC
	goto_if_set FLAG_GENESIS_BADGE_13_GET, TidymoonCity_Gym_EventScript_LunaPostBadge
	release
	end

TidymoonCity_Gym_EventScript_LunaDefeated::
	message TidymoonCity_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox TidymoonCity_Gym_Text_BadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_GENESIS_BADGE_13_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox TidymoonCity_Gym_Text_LunaAfter, MSGBOX_DEFAULT
	release
	end

TidymoonCity_Gym_EventScript_LunaPostBadge::
	msgbox TidymoonCity_Gym_Text_LunaDone, MSGBOX_DEFAULT
	release
	end

TidymoonCity_Gym_EventScript_TrainerA::
	trainerbattle_single TRAINER_GENESIS_TIDYMOON_A, TidymoonCity_Gym_Text_TrainerAIntro, TidymoonCity_Gym_Text_TrainerADefeat
	msgbox TidymoonCity_Gym_Text_TrainerAPost, MSGBOX_AUTOCLOSE
	end

TidymoonCity_Gym_EventScript_TrainerB::
	trainerbattle_single TRAINER_GENESIS_TIDYMOON_B, TidymoonCity_Gym_Text_TrainerBIntro, TidymoonCity_Gym_Text_TrainerBDefeat
	msgbox TidymoonCity_Gym_Text_TrainerBPost, MSGBOX_AUTOCLOSE
	end

TidymoonCity_Gym_EventScript_TrainerC::
	trainerbattle_single TRAINER_GENESIS_TIDYMOON_C, TidymoonCity_Gym_Text_TrainerCIntro, TidymoonCity_Gym_Text_TrainerCDefeat
	msgbox TidymoonCity_Gym_Text_TrainerCPost, MSGBOX_AUTOCLOSE
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

TidymoonCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to TIDYMOON CITY GYM!\p"
	.string "LUNA uses FAIRY-type POKéMON.\pThey're strong against FIGHTING,\nDRAGON, and DARK, but watch for\nPOISON and STEEL moves.\p"
	.string "Claim the MOON BADGE!$"

TidymoonCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The MOON BADGE is yours!$"

TidymoonCity_Gym_Text_TrainerAIntro:
	.string "This GYM tests your resolve!$"

TidymoonCity_Gym_Text_TrainerADefeat:
	.string "You broke through…$"

TidymoonCity_Gym_Text_TrainerAPost:
	.string "LUNA is still ahead.$"

TidymoonCity_Gym_Text_TrainerBIntro:
	.string "Don't underestimate us!$"

TidymoonCity_Gym_Text_TrainerBDefeat:
	.string "Sharp work…$"

TidymoonCity_Gym_Text_TrainerBPost:
	.string "Trust your team.$"

TidymoonCity_Gym_Text_TrainerCIntro:
	.string "Pressure incoming!$"

TidymoonCity_Gym_Text_TrainerCDefeat:
	.string "My plan broke…$"

TidymoonCity_Gym_Text_TrainerCPost:
	.string "The MOON BADGE opens the path ahead.$"

TidymoonCity_Gym_Text_LunaIntro:
	.string "LUNA: Welcome to TIDYMOON CITY GYM.\n"
	.string "I am the FAIRY LEADER.\p"
	.string "Show me your strength--shall we begin?$"

TidymoonCity_Gym_Text_LunaDefeat:
	.string "Well fought… The city is yours to stamp.$"

TidymoonCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the MOON BADGE\n"
	.string "from LUNA!$"

TidymoonCity_Gym_Text_BadgeInfo:
	.string "LUNA: With the MOON BADGE, your\n"
	.string "Eastern Aurelia journey deepens.\p"
	.string "Return to the Hall when you're ready\n"
	.string "for the next city.$"

TidymoonCity_Gym_Text_LunaAfter:
	.string "LUNA: TIDYMOON CITY stamps your path.\n"
	.string "Carry what you learned.$"

TidymoonCity_Gym_Text_LunaDone:
	.string "LUNA: The teleport net still hums.\n"
	.string "Walk tall, Champion.$"

TidymoonCity_Gym_Text_GymStatue:
	.string "TIDYMOON CITY POKéMON GYM$"

TidymoonCity_Gym_Text_GymStatueCertified:
	.string "TIDYMOON CITY POKéMON GYM\p"
	.string "LUNA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
