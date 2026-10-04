OldaleTown_Gym_MapScripts::
	.byte 0

OldaleTown_Gym_EventScript_Flora::
	trainerbattle_single TRAINER_ROXANNE_1, OldaleTown_Gym_Text_FloraIntro, OldaleTown_Gym_Text_FloraDefeat, OldaleTown_Gym_EventScript_FloraDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, OldaleTown_Gym_EventScript_FloraRematch
	goto_if_unset FLAG_RECEIVED_TM_BULLET_SEED, OldaleTown_Gym_EventScript_GiveBulletSeed
	msgbox OldaleTown_Gym_Text_FloraPostBattle, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_EventScript_FloraDefeated::
	message OldaleTown_Gym_Text_ReceivedVerdantBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox OldaleTown_Gym_Text_VerdantBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_GENESIS_STORY_STATE, GENESIS_STORY_GYM1_DONE
	call Genesis_EventScript_UpdateLevelCap
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	goto OldaleTown_Gym_EventScript_GiveBulletSeed
	end

OldaleTown_Gym_EventScript_GiveBulletSeed::
	giveitem ITEM_TM_BULLET_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_BULLET_SEED
	msgbox OldaleTown_Gym_Text_ExplainBulletSeed, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_EventScript_FloraRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, OldaleTown_Gym_Text_FloraPreRematch, OldaleTown_Gym_Text_FloraRematchDefeat, OldaleTown_Gym_Text_FloraRematchNeedTwoMons
	msgbox OldaleTown_Gym_Text_FloraPostRematch, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, OldaleTown_Gym_Text_JoshIntro, OldaleTown_Gym_Text_JoshDefeat
	msgbox OldaleTown_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, OldaleTown_Gym_Text_TommyIntro, OldaleTown_Gym_Text_TommyDefeat
	msgbox OldaleTown_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, OldaleTown_Gym_Text_MarcIntro, OldaleTown_Gym_Text_MarcDefeat
	msgbox OldaleTown_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

OldaleTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, OldaleTown_Gym_EventScript_GymGuidePostVictory
	msgbox OldaleTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_EventScript_GymGuidePostVictory::
	msgbox OldaleTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

OldaleTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, OldaleTown_Gym_EventScript_GymStatueCertified
	goto OldaleTown_Gym_EventScript_GymStatue
	end

OldaleTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, OldaleTown_Gym_EventScript_GymStatueCertified
	goto OldaleTown_Gym_EventScript_GymStatue
	end

OldaleTown_Gym_EventScript_GymStatueCertified::
	msgbox OldaleTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_Gym_EventScript_GymStatue::
	msgbox OldaleTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to LUMEN CITY GYM!\p"
	.string "FLORA uses GRASS-type POKéMON.\p"
	.string "They're tough against WATER and\n"
	.string "GROUND, but weak to FIRE, FLYING,\l"
	.string "BUG, POISON, and ICE.\p"
	.string "Go get that VERDANT BADGE!$"

OldaleTown_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The VERDANT BADGE is yours!\p"
	.string "AURELIA's waiting for TRAINERS like you.$"

OldaleTown_Gym_Text_JoshIntro:
	.string "Don't take LUMEN's GYM TRAINERS\n"
	.string "lightly!$"

OldaleTown_Gym_Text_JoshDefeat:
	.string "You were too good for me…$"

OldaleTown_Gym_Text_JoshPostBattle:
	.string "FLORA's GRASS team is something else.\n"
	.string "Stay sharp!$"

OldaleTown_Gym_Text_TommyIntro:
	.string "If you can't beat me, you won't stand\n"
	.string "a chance against FLORA!$"

OldaleTown_Gym_Text_TommyDefeat:
	.string "Wow! You've got some potential!$"

OldaleTown_Gym_Text_TommyPostBattle:
	.string "FLORA is way stronger than me.\n"
	.string "Be ready!$"

OldaleTown_Gym_Text_MarcIntro:
	.string "My CAMPER instincts say you're\n"
	.string "trouble… Let's battle!$"

OldaleTown_Gym_Text_MarcDefeat:
	.string "Oh, man!\n"
	.string "You're one feisty challenger!$"

OldaleTown_Gym_Text_MarcPostBattle:
	.string "Our LEADER picked GRASS for a reason.\n"
	.string "Growth, patience, and power!$"

OldaleTown_Gym_Text_FloraIntro:
	.string "Hello! I'm FLORA, GYM LEADER of\n"
	.string "LUMEN CITY.\p"
	.string "I nurture GRASS POKéMON the way\n"
	.string "AURELIA nurtures new TRAINERS.\p"
	.string "Show me how brightly you can grow!$"

OldaleTown_Gym_Text_FloraDefeat:
	.string "So… I lost…\p"
	.string "Your bond with your POKéMON is\n"
	.string "already blooming.\p"
	.string "Please accept the VERDANT BADGE.$"

OldaleTown_Gym_Text_ReceivedVerdantBadge:
	.string "{PLAYER} received the VERDANT BADGE\n"
	.string "from FLORA.$"

OldaleTown_Gym_Text_VerdantBadgeInfoTakeThis:
	.string "The VERDANT BADGE allows your\n"
	.string "POKéMON to use CUT in the field.\p"
	.string "Please take this TM, too.$"

OldaleTown_Gym_Text_ExplainBulletSeed:
	.string "TM09 contains BULLET SEED.\p"
	.string "It hits two to five times in a row--\n"
	.string "perfect for a growing GRASS team.\p"
	.string "Use it wisely!$"

OldaleTown_Gym_Text_FloraPostBattle:
	.string "Keep challenging other GYM LEADERS.\n"
	.string "AURELIA--and TEAM ECLIPSE--are both\l"
	.string "watching TRAINERS rise.$"

OldaleTown_Gym_Text_GymStatue:
	.string "LUMEN CITY POKéMON GYM$"

OldaleTown_Gym_Text_GymStatueCertified:
	.string "LUMEN CITY POKéMON GYM\p"
	.string "FLORA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

OldaleTown_Gym_Text_FloraPreRematch:
	.string "FLORA: Welcome back!\n"
	.string "Let's see how much you've grown!$"

OldaleTown_Gym_Text_FloraRematchDefeat:
	.string "Still blooming faster than me…$"

OldaleTown_Gym_Text_FloraPostRematch:
	.string "FLORA: Keep nurturing your team.\n"
	.string "That's the LUMEN way!$"

OldaleTown_Gym_Text_FloraRematchNeedTwoMons:
	.string "FLORA: Oh--you only have one POKéMON.\n"
	.string "Please return with at least two.$"
