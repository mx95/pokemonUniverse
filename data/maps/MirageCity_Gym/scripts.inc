MirageCity_Gym_MapScripts::
	.byte 0

MirageCity_Gym_EventScript_Iris::
	trainerbattle_single TRAINER_GENESIS_IRIS, MirageCity_Gym_Text_IrisIntro, MirageCity_Gym_Text_IrisDefeat, MirageCity_Gym_EventScript_IrisDefeated, NO_MUSIC
	goto_if_set FLAG_GENESIS_BADGE_09_GET, MirageCity_Gym_EventScript_IrisPostBadge
	release
	end

MirageCity_Gym_EventScript_IrisDefeated::
	message MirageCity_Gym_Text_ReceivedMirageBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MirageCity_Gym_Text_MirageBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_GENESIS_BADGE_09_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox MirageCity_Gym_Text_IrisAfter, MSGBOX_DEFAULT
	release
	end

MirageCity_Gym_EventScript_IrisPostBadge::
	msgbox MirageCity_Gym_Text_IrisDone, MSGBOX_DEFAULT
	release
	end

MirageCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_GENESIS_MIRAGE_A, MirageCity_Gym_Text_JoshIntro, MirageCity_Gym_Text_JoshDefeat
	msgbox MirageCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

MirageCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_GENESIS_MIRAGE_B, MirageCity_Gym_Text_TommyIntro, MirageCity_Gym_Text_TommyDefeat
	msgbox MirageCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

MirageCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_GENESIS_MIRAGE_C, MirageCity_Gym_Text_MarcIntro, MirageCity_Gym_Text_MarcDefeat
	msgbox MirageCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

MirageCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_09_GET, MirageCity_Gym_EventScript_GymGuidePostVictory
	msgbox MirageCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MirageCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MirageCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MirageCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_09_GET, MirageCity_Gym_EventScript_GymStatueCertified
	goto MirageCity_Gym_EventScript_GymStatue
	end

MirageCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_09_GET, MirageCity_Gym_EventScript_GymStatueCertified
	goto MirageCity_Gym_EventScript_GymStatue
	end

MirageCity_Gym_EventScript_GymStatueCertified::
	msgbox MirageCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MirageCity_Gym_EventScript_GymStatue::
	msgbox MirageCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MirageCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to MIRAGE CITY GYM!\p"
	.string "IRIS uses PSYCHIC-type POKéMON.\p"
	.string "They're strong against FIGHTING and\n"
	.string "POISON, but watch for BUG, GHOST,\l"
	.string "and DARK moves.\p"
	.string "See through the veil--claim the\n"
	.string "MIRAGE BADGE!$"

MirageCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The MIRAGE BADGE is yours!\p"
	.string "Eastern Hall still holds desks for\n"
	.string "the cities beyond--CELIA's next.$"

MirageCity_Gym_Text_JoshIntro:
	.string "Mirage trainers test your focus.\n"
	.string "Don't blink!$"

MirageCity_Gym_Text_JoshDefeat:
	.string "You saw through me…$"

MirageCity_Gym_Text_JoshPostBattle:
	.string "IRIS's illusions run deeper than mine.$"

MirageCity_Gym_Text_TommyIntro:
	.string "If you can't beat me, IRIS will\n"
	.string "fold your mind like paper!$"

MirageCity_Gym_Text_TommyDefeat:
	.string "Sharp eyes…$"

MirageCity_Gym_Text_TommyPostBattle:
	.string "Trust your team more than the scenery.$"

MirageCity_Gym_Text_MarcIntro:
	.string "Psychic pressure incoming!$"

MirageCity_Gym_Text_MarcDefeat:
	.string "My concentration broke…$"

MirageCity_Gym_Text_MarcPostBattle:
	.string "The MIRAGE BADGE opens Verdantis next.$"

MirageCity_Gym_Text_IrisIntro:
	.string "IRIS: Welcome to MIRAGE CITY GYM.\n"
	.string "Our streets fold light into riddles.\p"
	.string "I am the PSYCHIC LEADER of Mirage.\n"
	.string "See through the veil--shall we begin?$"

MirageCity_Gym_Text_IrisDefeat:
	.string "The mirage clears… Well fought!$"

MirageCity_Gym_Text_ReceivedMirageBadge:
	.string "{PLAYER} received the MIRAGE BADGE\n"
	.string "from IRIS!$"

MirageCity_Gym_Text_MirageBadgeInfo:
	.string "IRIS: With the MIRAGE BADGE, your\n"
	.string "perception of Eastern Aurelia deepens.\p"
	.string "Return to the Hall when you're ready\n"
	.string "for VERDANTIS--CELIA awaits.$"

MirageCity_Gym_Text_IrisAfter:
	.string "IRIS: Mirage City stamps your path.\n"
	.string "Trust what you perceive.$"

MirageCity_Gym_Text_IrisDone:
	.string "IRIS: Mirage City's teleport net still\n"
	.string "hums for you. Trust what you perceive.$"

MirageCity_Gym_Text_GymStatue:
	.string "MIRAGE CITY POKéMON GYM$"

MirageCity_Gym_Text_GymStatueCertified:
	.string "MIRAGE CITY POKéMON GYM\p"
	.string "IRIS'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
