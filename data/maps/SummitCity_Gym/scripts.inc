SummitCity_Gym_MapScripts::
	.byte 0

SummitCity_Gym_EventScript_Mentor::
	trainerbattle_single TRAINER_GENESIS_MENTOR, SummitCity_Gym_Text_MentorIntro, SummitCity_Gym_Text_MentorDefeat, SummitCity_Gym_EventScript_MentorDefeated, NO_MUSIC
	goto_if_set FLAG_GENESIS_BADGE_16_GET, SummitCity_Gym_EventScript_MentorPostBadge
	release
	end

SummitCity_Gym_EventScript_MentorDefeated::
	message SummitCity_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SummitCity_Gym_Text_BadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_GENESIS_BADGE_16_GET
	setvar VAR_GENESIS_STORY_STATE, GENESIS_STORY_EASTERN_DONE
	call Genesis_EventScript_UpdateLevelCap
	msgbox SummitCity_Gym_Text_MentorAfter, MSGBOX_DEFAULT
	release
	end

SummitCity_Gym_EventScript_MentorPostBadge::
	msgbox SummitCity_Gym_Text_MentorDone, MSGBOX_DEFAULT
	release
	end

SummitCity_Gym_EventScript_TrainerA::
	trainerbattle_single TRAINER_GENESIS_SUMMIT_A, SummitCity_Gym_Text_TrainerAIntro, SummitCity_Gym_Text_TrainerADefeat
	msgbox SummitCity_Gym_Text_TrainerAPost, MSGBOX_AUTOCLOSE
	end

SummitCity_Gym_EventScript_TrainerB::
	trainerbattle_single TRAINER_GENESIS_SUMMIT_B, SummitCity_Gym_Text_TrainerBIntro, SummitCity_Gym_Text_TrainerBDefeat
	msgbox SummitCity_Gym_Text_TrainerBPost, MSGBOX_AUTOCLOSE
	end

SummitCity_Gym_EventScript_TrainerC::
	trainerbattle_single TRAINER_GENESIS_SUMMIT_C, SummitCity_Gym_Text_TrainerCIntro, SummitCity_Gym_Text_TrainerCDefeat
	msgbox SummitCity_Gym_Text_TrainerCPost, MSGBOX_AUTOCLOSE
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

SummitCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to AURELIA SUMMIT GYM!\p"
	.string "MENTOR uses the full toolkit you've forged\nacross Aurelia. Bring everything.\p"
	.string "Claim the ASCENSION BADGE!$"

SummitCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The ASCENSION BADGE is yours!$"

SummitCity_Gym_Text_TrainerAIntro:
	.string "This GYM tests your resolve!$"

SummitCity_Gym_Text_TrainerADefeat:
	.string "You broke through…$"

SummitCity_Gym_Text_TrainerAPost:
	.string "MENTOR is still ahead.$"

SummitCity_Gym_Text_TrainerBIntro:
	.string "Don't underestimate us!$"

SummitCity_Gym_Text_TrainerBDefeat:
	.string "Sharp work…$"

SummitCity_Gym_Text_TrainerBPost:
	.string "Trust your team.$"

SummitCity_Gym_Text_TrainerCIntro:
	.string "Pressure incoming!$"

SummitCity_Gym_Text_TrainerCDefeat:
	.string "My plan broke…$"

SummitCity_Gym_Text_TrainerCPost:
	.string "The ASCENSION BADGE opens the path ahead.$"

SummitCity_Gym_Text_MentorIntro:
	.string "MENTOR: Welcome to AURELIA SUMMIT GYM.\n"
	.string "I am the MIXED LEADER.\p"
	.string "Show me your strength--shall we begin?$"

SummitCity_Gym_Text_MentorDefeat:
	.string "Well fought… The city is yours to stamp.$"

SummitCity_Gym_Text_ReceivedBadge:
	.string "{PLAYER} received the ASCENSION BADGE\n"
	.string "from MENTOR!$"

SummitCity_Gym_Text_BadgeInfo:
	.string "MENTOR: With the ASCENSION BADGE, your\n"
	.string "Eastern Aurelia journey deepens.\p"
	.string "Return to the Hall when you're ready\n"
	.string "for the next city.$"

SummitCity_Gym_Text_MentorAfter:
	.string "MENTOR: AURELIA SUMMIT stamps your path.\n"
	.string "Carry what you learned.$"

SummitCity_Gym_Text_MentorDone:
	.string "MENTOR: The teleport net still hums.\n"
	.string "Walk tall, Champion.$"

SummitCity_Gym_Text_GymStatue:
	.string "AURELIA SUMMIT POKéMON GYM$"

SummitCity_Gym_Text_GymStatueCertified:
	.string "AURELIA SUMMIT POKéMON GYM\p"
	.string "MENTOR'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
