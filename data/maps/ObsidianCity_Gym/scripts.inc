ObsidianCity_Gym_MapScripts::
	.byte 0

ObsidianCity_Gym_EventScript_Noctis::
	trainerbattle_single TRAINER_GENESIS_NOCTIS, ObsidianCity_Gym_Text_NoctisIntro, ObsidianCity_Gym_Text_NoctisDefeat, ObsidianCity_Gym_EventScript_NoctisDefeated, NO_MUSIC
	goto_if_set FLAG_GENESIS_BADGE_11_GET, ObsidianCity_Gym_EventScript_NoctisPostBadge
	release
	end

ObsidianCity_Gym_EventScript_NoctisDefeated::
	message ObsidianCity_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox ObsidianCity_Gym_Text_BadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_GENESIS_BADGE_11_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox ObsidianCity_Gym_Text_NoctisAfter, MSGBOX_DEFAULT
	release
	end

ObsidianCity_Gym_EventScript_NoctisPostBadge::
	msgbox ObsidianCity_Gym_Text_NoctisDone, MSGBOX_DEFAULT
	release
	end

ObsidianCity_Gym_EventScript_TrainerA::
	trainerbattle_single TRAINER_GENESIS_OBSIDIAN_A, ObsidianCity_Gym_Text_TrainerAIntro, ObsidianCity_Gym_Text_TrainerADefeat
	msgbox ObsidianCity_Gym_Text_TrainerAPost, MSGBOX_AUTOCLOSE
	end

ObsidianCity_Gym_EventScript_TrainerB::
	trainerbattle_single TRAINER_GENESIS_OBSIDIAN_B, ObsidianCity_Gym_Text_TrainerBIntro, ObsidianCity_Gym_Text_TrainerBDefeat
	msgbox ObsidianCity_Gym_Text_TrainerBPost, MSGBOX_AUTOCLOSE
	end

ObsidianCity_Gym_EventScript_TrainerC::
	trainerbattle_single TRAINER_GENESIS_OBSIDIAN_C, ObsidianCity_Gym_Text_TrainerCIntro, ObsidianCity_Gym_Text_TrainerCDefeat
	msgbox ObsidianCity_Gym_Text_TrainerCPost, MSGBOX_AUTOCLOSE
	end

ObsidianCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_11_GET, ObsidianCity_Gym_EventScript_GymGuidePostVictory
	msgbox ObsidianCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

ObsidianCity_Gym_EventScript_GymGuidePostVictory::
	msgbox ObsidianCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

ObsidianCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_11_GET, ObsidianCity_Gym_EventScript_GymStatueCertified
	goto ObsidianCity_Gym_EventScript_GymStatue
	end

ObsidianCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_11_GET, ObsidianCity_Gym_EventScript_GymStatueCertified
	goto ObsidianCity_Gym_EventScript_GymStatue
	end

ObsidianCity_Gym_EventScript_GymStatueCertified::
	msgbox ObsidianCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

ObsidianCity_Gym_EventScript_GymStatue::
	msgbox ObsidianCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

ObsidianCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to OBSIDIAN CITY GYM!\p"
	.string "NOCTIS uses DARK-type POKéMON.\pThey're strong against PSYCHIC and\nGHOST, but watch for FIGHTING, BUG,\land FAIRY moves.\p"
	.string "Claim the OBSIDIAN BADGE!$"

ObsidianCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The OBSIDIAN BADGE is yours!$"

ObsidianCity_Gym_Text_TrainerAIntro:
	.string "This GYM tests your resolve!$"

ObsidianCity_Gym_Text_TrainerADefeat:
	.string "You broke through…$"

ObsidianCity_Gym_Text_TrainerAPost:
	.string "NOCTIS is still ahead.$"

ObsidianCity_Gym_Text_TrainerBIntro:
	.string "Don't underestimate us!$"

ObsidianCity_Gym_Text_TrainerBDefeat:
	.string "Sharp work…$"

ObsidianCity_Gym_Text_TrainerBPost:
	.string "Trust your team.$"

ObsidianCity_Gym_Text_TrainerCIntro:
	.string "Pressure incoming!$"

ObsidianCity_Gym_Text_TrainerCDefeat:
	.string "My plan broke…$"

ObsidianCity_Gym_Text_TrainerCPost:
	.string "The OBSIDIAN BADGE opens the path ahead.$"

ObsidianCity_Gym_Text_NoctisIntro:
	.string "NOCTIS: Welcome to OBSIDIAN CITY GYM.\n"
	.string "I am the DARK LEADER.\p"
	.string "Show me your strength--shall we begin?$"

ObsidianCity_Gym_Text_NoctisDefeat:
	.string "Well fought… The city is yours to stamp.$"

ObsidianCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the OBSIDIAN BADGE\n"
	.string "from NOCTIS!$"

ObsidianCity_Gym_Text_BadgeInfo:
	.string "NOCTIS: With the OBSIDIAN BADGE, your\n"
	.string "Eastern Aurelia journey deepens.\p"
	.string "Return to the Hall when you're ready\n"
	.string "for the next city.$"

ObsidianCity_Gym_Text_NoctisAfter:
	.string "NOCTIS: OBSIDIAN CITY stamps your path.\n"
	.string "Carry what you learned.$"

ObsidianCity_Gym_Text_NoctisDone:
	.string "NOCTIS: The teleport net still hums.\n"
	.string "Walk tall, Champion.$"

ObsidianCity_Gym_Text_GymStatue:
	.string "OBSIDIAN CITY POKéMON GYM$"

ObsidianCity_Gym_Text_GymStatueCertified:
	.string "OBSIDIAN CITY POKéMON GYM\p"
	.string "NOCTIS'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
