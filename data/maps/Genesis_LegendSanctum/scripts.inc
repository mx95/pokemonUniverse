Genesis_LegendSanctum_MapScripts::
	.byte 0

Genesis_LegendSanctum_EventScript_Guide::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_FORM_UNLOCKED, Genesis_LegendSanctum_EventScript_GuideFormOpen
	msgbox Genesis_LegendSanctum_Text_Guide, MSGBOX_DEFAULT
	release
	end

Genesis_LegendSanctum_EventScript_GuideFormOpen::
	msgbox Genesis_LegendSanctum_Text_GuideFormOpen, MSGBOX_DEFAULT
	release
	end

Genesis_LegendSanctum_EventScript_PrepBattle::
	msgbox Genesis_LegendSanctum_Text_Prep, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	return

Genesis_LegendSanctum_EventScript_Aethernox::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_DEFEATED_AETHERNOX, Genesis_LegendSanctum_EventScript_RematchAethernox
	msgbox Genesis_LegendSanctum_Text_Aethernox, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_LegendSanctum_EventScript_Decline
	call Genesis_LegendSanctum_EventScript_PrepBattle
	setwildbattle SPECIES_AETHERNOX, 72, ITEM_LIFE_ORB
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_LegendSanctum_EventScript_CaughtAethernox
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_LegendSanctum_EventScript_CaughtAethernox
	release
	end

Genesis_LegendSanctum_EventScript_RematchAethernox::
	msgbox Genesis_LegendSanctum_Text_RematchAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_LegendSanctum_EventScript_Already
	call Genesis_LegendSanctum_EventScript_PrepBattle
	setwildbattle SPECIES_AETHERNOX, 75, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	release
	end

Genesis_LegendSanctum_EventScript_CaughtAethernox::
	setflag FLAG_GENESIS_DEFEATED_AETHERNOX
	playfanfare MUS_OBTAIN_ITEM
	msgbox Genesis_LegendSanctum_Text_DoneAethernox, MSGBOX_DEFAULT
	waitfanfare
	giveitem ITEM_BLACK_SLUDGE
	call Genesis_LegendSanctum_EventScript_CheckComplete
	call Genesis_EventScript_TryUnlockGenesisForm
	release
	end

Genesis_LegendSanctum_EventScript_Solara::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_DEFEATED_SOLARA, Genesis_LegendSanctum_EventScript_RematchSolara
	msgbox Genesis_LegendSanctum_Text_Solara, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_LegendSanctum_EventScript_Decline
	call Genesis_LegendSanctum_EventScript_PrepBattle
	setwildbattle SPECIES_SOLARA, 72, ITEM_HEAT_ROCK
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_LegendSanctum_EventScript_CaughtSolara
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_LegendSanctum_EventScript_CaughtSolara
	release
	end

Genesis_LegendSanctum_EventScript_RematchSolara::
	msgbox Genesis_LegendSanctum_Text_RematchAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_LegendSanctum_EventScript_Already
	call Genesis_LegendSanctum_EventScript_PrepBattle
	setwildbattle SPECIES_SOLARA, 75, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	release
	end

Genesis_LegendSanctum_EventScript_CaughtSolara::
	setflag FLAG_GENESIS_DEFEATED_SOLARA
	playfanfare MUS_OBTAIN_ITEM
	msgbox Genesis_LegendSanctum_Text_DoneSolara, MSGBOX_DEFAULT
	waitfanfare
	giveitem ITEM_CHARCOAL
	call Genesis_LegendSanctum_EventScript_CheckComplete
	call Genesis_EventScript_TryUnlockGenesisForm
	release
	end

Genesis_LegendSanctum_EventScript_Genesis::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_DEFEATED_GENESIS_MON, Genesis_LegendSanctum_EventScript_RematchGenesis
	msgbox Genesis_LegendSanctum_Text_Genesis, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_LegendSanctum_EventScript_Decline
	call Genesis_LegendSanctum_EventScript_PrepBattle
	setwildbattle SPECIES_GENESIS, 78, ITEM_LEFTOVERS
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_LegendSanctum_EventScript_CaughtGenesis
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_LegendSanctum_EventScript_CaughtGenesis
	release
	end

Genesis_LegendSanctum_EventScript_RematchGenesis::
	msgbox Genesis_LegendSanctum_Text_RematchAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_LegendSanctum_EventScript_Already
	call Genesis_LegendSanctum_EventScript_PrepBattle
	setwildbattle SPECIES_GENESIS, 80, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	release
	end

Genesis_LegendSanctum_EventScript_CaughtGenesis::
	setflag FLAG_GENESIS_DEFEATED_GENESIS_MON
	playfanfare MUS_OBTAIN_ITEM
	msgbox Genesis_LegendSanctum_Text_DoneGenesis, MSGBOX_DEFAULT
	waitfanfare
	giveitem ITEM_ABILITY_CAPSULE
	call Genesis_LegendSanctum_EventScript_CheckComplete
	call Genesis_EventScript_TryUnlockGenesisForm
	release
	end

Genesis_LegendSanctum_EventScript_CheckComplete::
	goto_if_unset FLAG_GENESIS_DEFEATED_AETHERNOX, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_DEFEATED_SOLARA, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_DEFEATED_GENESIS_MON, Common_EventScript_NopReturn
	setvar VAR_GENESIS_STORY_STATE, GENESIS_STORY_LEGENDS_DONE
	setflag FLAG_GENESIS_ACHIEVEMENT_LEGENDS
	playfanfare MUS_OBTAIN_ITEM
	msgbox Genesis_LegendSanctum_Text_AllDone, MSGBOX_DEFAULT
	waitfanfare
	giveitem ITEM_GOLD_BOTTLE_CAP
	return

Genesis_LegendSanctum_EventScript_Already::
	msgbox Genesis_LegendSanctum_Text_Already, MSGBOX_DEFAULT
	release
	end

Genesis_LegendSanctum_EventScript_Decline::
	msgbox Genesis_LegendSanctum_Text_Decline, MSGBOX_DEFAULT
	release
	end

Genesis_LegendSanctum_Text_Guide:
	.string "This is the LEGEND SANCTUM.\n"
	.string "Three foci answer CHAMPIONS only.\p"
	.string "AETHERNOX--chaos after fracture.\n"
	.string "SOLARA--creation's first dawn.\l"
	.string "GENESIS--potential unbound.\p"
	.string "The sanctum heals your party before\n"
	.string "each trial. Best all three to awaken\l"
	.string "GENESIS FORM on the bonded mon.$"

Genesis_LegendSanctum_Text_GuideFormOpen:
	.string "GENESIS FORM already answers you.\n"
	.string "The foci keep their silence--unless\l"
	.string "you seek rematches in memory alone.\p"
	.string "Mix gimmicks freely if CHAOS BATTLES\n"
	.string "are on at Eastern AURELIA HALL.$"

Genesis_LegendSanctum_Text_Prep:
	.string "The sanctum steadies your party…$"

Genesis_LegendSanctum_Text_Aethernox:
	.string "Chaos coils in the dark stone…\n"
	.string "Wings of broken worlds stir.\p"
	.string "Call AETHERNOX?$"

Genesis_LegendSanctum_Text_Solara:
	.string "Creation light gathers…\n"
	.string "A sun that remembers the first day.\p"
	.string "Call SOLARA?$"

Genesis_LegendSanctum_Text_Genesis:
	.string "Potential itself awakens…\n"
	.string "Every possible form waits in the stone.\p"
	.string "Call GENESIS?$"

Genesis_LegendSanctum_Text_DoneAethernox:
	.string "AETHERNOX yields. Fracture becomes\n"
	.string "focus. A dark residue remains for you.$"

Genesis_LegendSanctum_Text_DoneSolara:
	.string "SOLARA yields. Dawn settles into\n"
	.string "ember. Take this charcoal of first fire.$"

Genesis_LegendSanctum_Text_DoneGenesis:
	.string "GENESIS yields. Potential names you.\n"
	.string "Rewrite what a partner can become.$"

Genesis_LegendSanctum_Text_Already:
	.string "That legend has already answered you.$"

Genesis_LegendSanctum_Text_RematchAsk:
	.string "The focus still hums with that legend.\n"
	.string "Call it again for a rematch?$"

Genesis_LegendSanctum_Text_Decline:
	.string "The sanctum waits.$"

Genesis_LegendSanctum_Text_AllDone:
	.string "All three legends answered.\n"
	.string "GENESIS FORM stirs in your partnership!\p"
	.string "Send GENESIS into battle and watch:\n"
	.string "types, ability, and stats rewrite on entry.\p"
	.string "A Gold Bottle Cap crystallizes as proof.\n"
	.string "Potential unbound--fight wisely.$"
