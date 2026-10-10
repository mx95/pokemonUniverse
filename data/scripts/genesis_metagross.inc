@ GENESIS: Rampage Shiny Mega Metagross — malicious AI side story (New Mauville)

Genesis_EventScript_MetagrossScientist::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_METAGROSS_CAUGHT, Genesis_EventScript_MetagrossScientistDone
	goto_if_set FLAG_GENESIS_METAGROSS_DEFEATED, Genesis_EventScript_MetagrossScientistAfterFight
	goto_if_set FLAG_GENESIS_METAGROSS_QUEST_INTRO, Genesis_EventScript_MetagrossScientistRemind
	setflag FLAG_GENESIS_METAGROSS_QUEST_INTRO
	msgbox Genesis_Text_MetagrossScientistIntro, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_MetagrossScientistRemind::
	msgbox Genesis_Text_MetagrossScientistRemind, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_MetagrossScientistAfterFight::
	msgbox Genesis_Text_MetagrossScientistAfter, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_MetagrossScientistDone::
	msgbox Genesis_Text_MetagrossScientistDone, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_RampageMetagross::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_METAGROSS_CAUGHT, Genesis_EventScript_RampageMetagrossGone
	goto_if_unset FLAG_GENESIS_METAGROSS_QUEST_INTRO, Genesis_EventScript_RampageMetagrossNoIntro
	goto_if_set FLAG_GENESIS_METAGROSS_DEFEATED, Genesis_EventScript_RampageMetagrossOfferCatch
	msgbox Genesis_Text_RampageMetagrossChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_RampageMetagrossDecline
	msgbox Genesis_Text_RampageMetagrossEngage, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_METAGROSS_MEGA, 50, ITEM_METAGROSSITE
	createmon B_SIDE_OPPONENT, 0, SPECIES_METAGROSS_MEGA, 50, item=ITEM_METAGROSSITE, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 0, 0, 2, 2
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_RampageMetagrossCaughtInBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_RampageMetagrossDefeated
	msgbox Genesis_Text_RampageMetagrossFled, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_RampageMetagrossNoIntro::
	msgbox Genesis_Text_RampageMetagrossHostile, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_RampageMetagrossDecline::
	msgbox Genesis_Text_RampageMetagrossDecline, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_RampageMetagrossDefeated::
	setflag FLAG_GENESIS_METAGROSS_DEFEATED
	msgbox Genesis_Text_RampageMetagrossDefeated, MSGBOX_DEFAULT
	goto Genesis_EventScript_RampageMetagrossOfferCatch
	end

Genesis_EventScript_RampageMetagrossOfferCatch::
	msgbox Genesis_Text_RampageMetagrossCatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_RampageMetagrossCatchLater
	msgbox Genesis_Text_RampageMetagrossCatching, MSGBOX_DEFAULT
	closemessage
	@ Softened catchable rematch — still shiny Mega form; reverts to Metagross on capture
	setwildbattle SPECIES_METAGROSS_MEGA, 50, ITEM_METAGROSSITE
	createmon B_SIDE_OPPONENT, 0, SPECIES_METAGROSS_MEGA, 50, item=ITEM_METAGROSSITE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_RampageMetagrossCaughtInBattle
	msgbox Genesis_Text_RampageMetagrossCatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_RampageMetagrossCatchLater::
	msgbox Genesis_Text_RampageMetagrossCatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_RampageMetagrossCaughtInBattle::
	setflag FLAG_GENESIS_METAGROSS_DEFEATED
	setflag FLAG_GENESIS_METAGROSS_CAUGHT
	setflag FLAG_GENESIS_ACHIEVEMENT_METAGROSS
	setflag FLAG_HIDE_GENESIS_RAMPAGE_METAGROSS
	msgbox Genesis_Text_RampageMetagrossCaught, MSGBOX_DEFAULT
	giveitem ITEM_METAGROSSITE
	call Genesis_EventScript_TryUnlockGenesisForm
	release
	end

Genesis_EventScript_RampageMetagrossGone::
	msgbox Genesis_Text_RampageMetagrossGone, MSGBOX_DEFAULT
	release
	end

Genesis_Text_MetagrossScientistIntro:
	.string "You're a TRAINER? Thank goodness!\p"
	.string "Deep in NEW MAUVILLE, a METAGROSS\n"
	.string "was wired into the old reactor AI.\p"
	.string "Something corrupted the code.\n"
	.string "It Mega Evolved on its own--and went\l"
	.string "on a rampage!\p"
	.string "It's still shining with offline power.\n"
	.string "Please… stop it before the grid blows.$"

Genesis_Text_MetagrossScientistRemind:
	.string "The rampaging Mega METAGROSS is still\n"
	.string "deeper inside. Totem-level pressure.\p"
	.string "Bring a strong team!$"

Genesis_Text_MetagrossScientistAfter:
	.string "You beat it back? Incredible!\n"
	.string "If it's calm enough… you might be able\l"
	.string "to catch it and free it from the AI.$"

Genesis_Text_MetagrossScientistDone:
	.string "The reactor reads clean again.\n"
	.string "That METAGROSS is lucky it found you.$"

Genesis_Text_RampageMetagrossHostile:
	.string "A Mega METAGROSS glares from the\n"
	.string "reactor housing…\p"
	.string "It seems locked behind some AI seal.\n"
	.string "Maybe a scientist nearby knows more.$"

Genesis_Text_RampageMetagrossChallenge:
	.string "Malicious code scrapes across its eyes.\n"
	.string "Shiny Mega METAGROSS is in a frenzy!\p"
	.string "Challenge the rampaging Totem?$"

Genesis_Text_RampageMetagrossEngage:
	.string "The AI howls through metal lungs!$"

Genesis_Text_RampageMetagrossDecline:
	.string "It thrashes, waiting…$"

Genesis_Text_RampageMetagrossFled:
	.string "The rampage continues.\n"
	.string "Come back when you're ready.$"

Genesis_Text_RampageMetagrossDefeated:
	.string "The corrupted AI shorts out!\n"
	.string "Mega METAGROSS collapses, panting…$"

Genesis_Text_RampageMetagrossCatchOffer:
	.string "It's exhausted--and free of the virus.\n"
	.string "Try to catch the Shiny METAGROSS?$"

Genesis_Text_RampageMetagrossCatching:
	.string "You approach carefully…$"

Genesis_Text_RampageMetagrossCatchLater:
	.string "It stays here for now.\n"
	.string "Talk to it again if you change your mind.$"

Genesis_Text_RampageMetagrossCatchFail:
	.string "It slipped free--but it won't flee.\n"
	.string "You can try again.$"

Genesis_Text_RampageMetagrossCaught:
	.string "The METAGROSS's eyes clear.\n"
	.string "Whatever malice drove it is gone.\p"
	.string "It trusts you now.\n"
	.string "Take this METAGROSSITE as well--for\l"
	.string "when Mega Evolution is truly yours.$"

Genesis_Text_RampageMetagrossGone:
	.string "Only quiet machinery remains.$"
