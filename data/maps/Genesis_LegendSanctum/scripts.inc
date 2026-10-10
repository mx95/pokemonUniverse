Genesis_LegendSanctum_MapScripts::
	.byte 0

Genesis_LegendSanctum_EventScript_Guide::
	lock
	faceplayer
	msgbox Genesis_LegendSanctum_Text_Guide, MSGBOX_DEFAULT
	release
	end

Genesis_LegendSanctum_EventScript_Aethernox::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_DEFEATED_AETHERNOX, Genesis_LegendSanctum_EventScript_Already
	msgbox Genesis_LegendSanctum_Text_Aethernox, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_LegendSanctum_EventScript_Decline
	setwildbattle SPECIES_AETHERNOX, 70
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_LegendSanctum_EventScript_CaughtAethernox
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_LegendSanctum_EventScript_CaughtAethernox
	release
	end

Genesis_LegendSanctum_EventScript_CaughtAethernox::
	setflag FLAG_GENESIS_DEFEATED_AETHERNOX
	msgbox Genesis_LegendSanctum_Text_Done, MSGBOX_DEFAULT
	call Genesis_LegendSanctum_EventScript_CheckComplete
	call Genesis_EventScript_TryUnlockGenesisForm
	release
	end

Genesis_LegendSanctum_EventScript_Solara::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_DEFEATED_SOLARA, Genesis_LegendSanctum_EventScript_Already
	msgbox Genesis_LegendSanctum_Text_Solara, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_LegendSanctum_EventScript_Decline
	setwildbattle SPECIES_SOLARA, 70
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_LegendSanctum_EventScript_CaughtSolara
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_LegendSanctum_EventScript_CaughtSolara
	release
	end

Genesis_LegendSanctum_EventScript_CaughtSolara::
	setflag FLAG_GENESIS_DEFEATED_SOLARA
	msgbox Genesis_LegendSanctum_Text_Done, MSGBOX_DEFAULT
	call Genesis_LegendSanctum_EventScript_CheckComplete
	call Genesis_EventScript_TryUnlockGenesisForm
	release
	end

Genesis_LegendSanctum_EventScript_Genesis::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_DEFEATED_GENESIS_MON, Genesis_LegendSanctum_EventScript_Already
	msgbox Genesis_LegendSanctum_Text_Genesis, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_LegendSanctum_EventScript_Decline
	setwildbattle SPECIES_GENESIS, 75
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_LegendSanctum_EventScript_CaughtGenesis
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_LegendSanctum_EventScript_CaughtGenesis
	release
	end

Genesis_LegendSanctum_EventScript_CaughtGenesis::
	setflag FLAG_GENESIS_DEFEATED_GENESIS_MON
	msgbox Genesis_LegendSanctum_Text_Done, MSGBOX_DEFAULT
	call Genesis_LegendSanctum_EventScript_CheckComplete
	call Genesis_EventScript_TryUnlockGenesisForm
	release
	end

Genesis_LegendSanctum_EventScript_CheckComplete::
	goto_if_unset FLAG_GENESIS_DEFEATED_AETHERNOX, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_DEFEATED_SOLARA, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_DEFEATED_GENESIS_MON, Common_EventScript_NopReturn
	setvar VAR_GENESIS_STORY_STATE, GENESIS_STORY_LEGENDS_DONE
	msgbox Genesis_LegendSanctum_Text_AllDone, MSGBOX_DEFAULT
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
	.string "Best them all to awaken GENESIS FORM.\n"
	.string "Touch a statue when you are ready.$"

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

Genesis_LegendSanctum_Text_Done:
	.string "The focus dims… for now.\n"
	.string "Its power has marked your journey.$"

Genesis_LegendSanctum_Text_Already:
	.string "That legend has already answered you.$"

Genesis_LegendSanctum_Text_Decline:
	.string "The sanctum waits.$"

Genesis_LegendSanctum_Text_AllDone:
	.string "All three legends answered.\n"
	.string "GENESIS FORM stirs in your partnership!\p"
	.string "When the bonded mon enters battle,\n"
	.string "potential itself may reshape it.$"
