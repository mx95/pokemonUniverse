@ GENESIS: Per-gym-town lore Pokémon (non-legendary / pseudo-tier)

Genesis_EventScript_TownMon_Decline::
	msgbox Genesis_Text_TownMon_GenericDecline, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_GenericDecline:
	.string "Another time, then.$"

Genesis_Text_TownMon_CatchFail:
	.string "It broke free… Try again when ready.$"

Genesis_Text_TownMon_CatchLater:
	.string "It waits nearby. Return when prepared.$"

Genesis_EventScript_TownMon_Lumen::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Lumen_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Lumen_OfferCatch
	msgbox Genesis_Text_TownMon_Lumen_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Lumen_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_RILLABOOM, 30, ITEM_MIRACLE_SEED
	createmon B_SIDE_OPPONENT, 0, SPECIES_RILLABOOM, 30, item=ITEM_MIRACLE_SEED, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Lumen_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Lumen_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Lumen_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Lumen_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Lumen_OfferCatch
	end

Genesis_EventScript_TownMon_Lumen_OfferCatch::
	msgbox Genesis_Text_TownMon_Lumen_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Lumen_CatchLater
	closemessage
	setwildbattle SPECIES_RILLABOOM, 30, ITEM_MIRACLE_SEED
	createmon B_SIDE_OPPONENT, 0, SPECIES_RILLABOOM, 30, item=ITEM_MIRACLE_SEED, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Lumen_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Lumen_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Lumen_Caught::
	setvar VAR_0x8004, 0
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Lumen_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Lumen_Done::
	msgbox Genesis_Text_TownMon_Lumen_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Lumen_Lore:
	.string "LUMEN's drum circle woke a wild RILLABOOM--\nthe Drummer Pokémon of the forests.\pIts grassy beat keeps the meadow healthy.\nWill you face its rhythm?$"

Genesis_Text_TownMon_Lumen_Challenge:
	.string "Challenge the grove's RILLABOOM?$"

Genesis_Text_TownMon_Lumen_Defeat:
	.string "The drums fall quiet…$"

Genesis_Text_TownMon_Lumen_CatchOffer:
	.string "Invite RILLABOOM to your party?$"

Genesis_Text_TownMon_Lumen_Caught:
	.string "RILLABOOM taps a welcoming beat.$"

Genesis_Text_TownMon_Lumen_Done:
	.string "LUMEN's grove still echoes its drum.$"

Genesis_EventScript_TownMon_Ironridge::
	lock
	faceplayer
	setvar VAR_0x8004, 1
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Ironridge_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Ironridge_OfferCatch
	msgbox Genesis_Text_TownMon_Ironridge_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Ironridge_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_KOMMO_O, 28, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_KOMMO_O, 28, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Ironridge_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Ironridge_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Ironridge_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Ironridge_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Ironridge_OfferCatch
	end

Genesis_EventScript_TownMon_Ironridge_OfferCatch::
	msgbox Genesis_Text_TownMon_Ironridge_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Ironridge_CatchLater
	closemessage
	setwildbattle SPECIES_KOMMO_O, 28, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_KOMMO_O, 28, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Ironridge_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Ironridge_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Ironridge_Caught::
	setvar VAR_0x8004, 1
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Ironridge_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Ironridge_Done::
	msgbox Genesis_Text_TownMon_Ironridge_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Ironridge_Lore:
	.string "Ironridge caves temper more than ore.\nA KOMMO-O--Clangorous Pokémon--trains\pthere, scales ringing like iron fists.\nFIGHTING spirit in dragon armor.$"

Genesis_Text_TownMon_Ironridge_Challenge:
	.string "Spar with KOMMO-O?$"

Genesis_Text_TownMon_Ironridge_Defeat:
	.string "The clanging ceases…$"

Genesis_Text_TownMon_Ironridge_CatchOffer:
	.string "Travel with KOMMO-O?$"

Genesis_Text_TownMon_Ironridge_Caught:
	.string "KOMMO-O bows--scales still humming.$"

Genesis_Text_TownMon_Ironridge_Done:
	.string "Cave walls still ring at dawn.$"

Genesis_EventScript_TownMon_PortAzure::
	lock
	faceplayer
	setvar VAR_0x8004, 2
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_PortAzure_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_PortAzure_OfferCatch
	msgbox Genesis_Text_TownMon_PortAzure_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_PortAzure_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_MILOTIC, 35, ITEM_MYSTIC_WATER
	createmon B_SIDE_OPPONENT, 0, SPECIES_MILOTIC, 35, item=ITEM_MYSTIC_WATER, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_PortAzure_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_PortAzure_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_PortAzure_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_PortAzure_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_PortAzure_OfferCatch
	end

Genesis_EventScript_TownMon_PortAzure_OfferCatch::
	msgbox Genesis_Text_TownMon_PortAzure_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_PortAzure_CatchLater
	closemessage
	setwildbattle SPECIES_MILOTIC, 35, ITEM_MYSTIC_WATER
	createmon B_SIDE_OPPONENT, 0, SPECIES_MILOTIC, 35, item=ITEM_MYSTIC_WATER, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_PortAzure_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_PortAzure_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_PortAzure_Caught::
	setvar VAR_0x8004, 2
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_PortAzure_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_PortAzure_Done::
	msgbox Genesis_Text_TownMon_PortAzure_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_PortAzure_Lore:
	.string "Port Azure fishers speak of a Tender\nPokémon born from an ugly FEEBAS.\pMILOTIC calms furious seas with beauty\nand stubborn grace.$"

Genesis_Text_TownMon_PortAzure_Challenge:
	.string "Face MILOTIC on the pier?$"

Genesis_Text_TownMon_PortAzure_Defeat:
	.string "The tide goes glass-smooth…$"

Genesis_Text_TownMon_PortAzure_CatchOffer:
	.string "Ask MILOTIC to sail with you?$"

Genesis_Text_TownMon_PortAzure_Caught:
	.string "MILOTIC coils beside you, serene.$"

Genesis_Text_TownMon_PortAzure_Done:
	.string "Harbor waters stay kinder now.$"

Genesis_EventScript_TownMon_Frostveil::
	lock
	faceplayer
	setvar VAR_0x8004, 4
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Frostveil_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Frostveil_OfferCatch
	msgbox Genesis_Text_TownMon_Frostveil_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Frostveil_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_BAXCALIBUR, 40, ITEM_NEVER_MELT_ICE
	createmon B_SIDE_OPPONENT, 0, SPECIES_BAXCALIBUR, 40, item=ITEM_NEVER_MELT_ICE, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Frostveil_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Frostveil_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Frostveil_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Frostveil_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Frostveil_OfferCatch
	end

Genesis_EventScript_TownMon_Frostveil_OfferCatch::
	msgbox Genesis_Text_TownMon_Frostveil_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Frostveil_CatchLater
	closemessage
	setwildbattle SPECIES_BAXCALIBUR, 40, ITEM_NEVER_MELT_ICE
	createmon B_SIDE_OPPONENT, 0, SPECIES_BAXCALIBUR, 40, item=ITEM_NEVER_MELT_ICE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Frostveil_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Frostveil_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Frostveil_Caught::
	setvar VAR_0x8004, 4
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Frostveil_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Frostveil_Done::
	msgbox Genesis_Text_TownMon_Frostveil_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Frostveil_Lore:
	.string "Frostveil's paradox springs hid a nest.\nBAXCALIBUR--Ice Dragon Pokémon--guards\pthe cold vault under the hot rocks,\na true pseudo-legend of ice and fang.$"

Genesis_Text_TownMon_Frostveil_Challenge:
	.string "Challenge BAXCALIBUR?$"

Genesis_Text_TownMon_Frostveil_Defeat:
	.string "Frost settles on the stone…$"

Genesis_Text_TownMon_Frostveil_CatchOffer:
	.string "Partner with BAXCALIBUR?$"

Genesis_Text_TownMon_Frostveil_Caught:
	.string "BAXCALIBUR sheaths its blade-crest.$"

Genesis_Text_TownMon_Frostveil_Done:
	.string "The vault ice stays unbroken.$"

Genesis_EventScript_TownMon_Solaris::
	lock
	faceplayer
	setvar VAR_0x8004, 5
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Solaris_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Solaris_OfferCatch
	msgbox Genesis_Text_TownMon_Solaris_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Solaris_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_BLAZIKEN, 42, ITEM_CHARCOAL
	createmon B_SIDE_OPPONENT, 0, SPECIES_BLAZIKEN, 42, item=ITEM_CHARCOAL, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Solaris_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Solaris_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Solaris_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Solaris_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Solaris_OfferCatch
	end

Genesis_EventScript_TownMon_Solaris_OfferCatch::
	msgbox Genesis_Text_TownMon_Solaris_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Solaris_CatchLater
	closemessage
	setwildbattle SPECIES_BLAZIKEN, 42, ITEM_CHARCOAL
	createmon B_SIDE_OPPONENT, 0, SPECIES_BLAZIKEN, 42, item=ITEM_CHARCOAL, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Solaris_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Solaris_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Solaris_Caught::
	setvar VAR_0x8004, 5
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Solaris_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Solaris_Done::
	msgbox Genesis_Text_TownMon_Solaris_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Solaris_Lore:
	.string "Solaris sun-dojos raised a BLAZIKEN\nwhose kicks scorch training posts.\pThe Blaze Pokémon of this city fights\nwith solar heat in every strike.$"

Genesis_Text_TownMon_Solaris_Challenge:
	.string "Trade blows with BLAZIKEN?$"

Genesis_Text_TownMon_Solaris_Defeat:
	.string "Embers cool on the wood…$"

Genesis_Text_TownMon_Solaris_CatchOffer:
	.string "Train under BLAZIKEN's wing?$"

Genesis_Text_TownMon_Solaris_Caught:
	.string "BLAZIKEN nods through the haze.$"

Genesis_Text_TownMon_Solaris_Done:
	.string "Dojo ash still marks its stance.$"

Genesis_EventScript_TownMon_Stormbreak::
	lock
	faceplayer
	setvar VAR_0x8004, 6
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Stormbreak_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Stormbreak_OfferCatch
	msgbox Genesis_Text_TownMon_Stormbreak_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Stormbreak_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_SALAMENCE, 48, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_SALAMENCE, 48, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Stormbreak_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Stormbreak_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Stormbreak_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Stormbreak_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Stormbreak_OfferCatch
	end

Genesis_EventScript_TownMon_Stormbreak_OfferCatch::
	msgbox Genesis_Text_TownMon_Stormbreak_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Stormbreak_CatchLater
	closemessage
	setwildbattle SPECIES_SALAMENCE, 48, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_SALAMENCE, 48, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Stormbreak_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Stormbreak_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Stormbreak_Caught::
	setvar VAR_0x8004, 6
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Stormbreak_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Stormbreak_Done::
	msgbox Genesis_Text_TownMon_Stormbreak_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Stormbreak_Lore:
	.string "Stormbreak cliffs hatch dreamers.\nSALAMENCE--Dragon Pokémon--finally\pearned its wings here. Wind and fang\nrival any gale legend.$"

Genesis_Text_TownMon_Stormbreak_Challenge:
	.string "Race SALAMENCE in the sky?$"

Genesis_Text_TownMon_Stormbreak_Defeat:
	.string "Wingtips fold at last…$"

Genesis_Text_TownMon_Stormbreak_CatchOffer:
	.string "Fly with SALAMENCE?$"

Genesis_Text_TownMon_Stormbreak_Caught:
	.string "SALAMENCE opens a wing for you.$"

Genesis_Text_TownMon_Stormbreak_Done:
	.string "Clifftop nests stay watched.$"

Genesis_EventScript_TownMon_Titania::
	lock
	faceplayer
	setvar VAR_0x8004, 7
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Titania_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Titania_OfferCatch
	msgbox Genesis_Text_TownMon_Titania_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Titania_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_ARCHALUDON, 50, ITEM_METAL_COAT
	createmon B_SIDE_OPPONENT, 0, SPECIES_ARCHALUDON, 50, item=ITEM_METAL_COAT, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Titania_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Titania_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Titania_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Titania_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Titania_OfferCatch
	end

Genesis_EventScript_TownMon_Titania_OfferCatch::
	msgbox Genesis_Text_TownMon_Titania_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Titania_CatchLater
	closemessage
	setwildbattle SPECIES_ARCHALUDON, 50, ITEM_METAL_COAT
	createmon B_SIDE_OPPONENT, 0, SPECIES_ARCHALUDON, 50, item=ITEM_METAL_COAT, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Titania_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Titania_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Titania_Caught::
	setvar VAR_0x8004, 7
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Titania_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Titania_Done::
	msgbox Genesis_Text_TownMon_Titania_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Titania_Lore:
	.string "Titania's bridgeworks woke an ARCHALUDON--\nAlloy Pokémon of living steel.\pIt braces the city like a walking\nfortress. Pseudo-tier bulk, pure STEEL.$"

Genesis_Text_TownMon_Titania_Challenge:
	.string "Test ARCHALUDON's girders?$"

Genesis_Text_TownMon_Titania_Defeat:
	.string "Metal stress-lines ease…$"

Genesis_Text_TownMon_Titania_CatchOffer:
	.string "Command ARCHALUDON?$"

Genesis_Text_TownMon_Titania_Caught:
	.string "ARCHALUDON locks in beside you.$"

Genesis_Text_TownMon_Titania_Done:
	.string "Bridge cables hum softer now.$"

Genesis_EventScript_TownMon_Mirage::
	lock
	faceplayer
	setvar VAR_0x8004, 8
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Mirage_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Mirage_OfferCatch
	msgbox Genesis_Text_TownMon_Mirage_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Mirage_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_GARDEVOIR, 55, ITEM_TWISTED_SPOON
	createmon B_SIDE_OPPONENT, 0, SPECIES_GARDEVOIR, 55, item=ITEM_TWISTED_SPOON, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Mirage_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Mirage_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Mirage_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Mirage_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Mirage_OfferCatch
	end

Genesis_EventScript_TownMon_Mirage_OfferCatch::
	msgbox Genesis_Text_TownMon_Mirage_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Mirage_CatchLater
	closemessage
	setwildbattle SPECIES_GARDEVOIR, 55, ITEM_TWISTED_SPOON
	createmon B_SIDE_OPPONENT, 0, SPECIES_GARDEVOIR, 55, item=ITEM_TWISTED_SPOON, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Mirage_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Mirage_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Mirage_Caught::
	setvar VAR_0x8004, 8
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Mirage_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Mirage_Done::
	msgbox Genesis_Text_TownMon_Mirage_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Mirage_Lore:
	.string "Mirage psychics bond with GARDEVOIR--\nthe Embrace Pokémon that protects\ptrainers with its life. Illusion and\nempathy are its battlefield.$"

Genesis_Text_TownMon_Mirage_Challenge:
	.string "Duel MIRAGE's GARDEVOIR?$"

Genesis_Text_TownMon_Mirage_Defeat:
	.string "The mind-fog lifts…$"

Genesis_Text_TownMon_Mirage_CatchOffer:
	.string "Bond with GARDEVOIR?$"

Genesis_Text_TownMon_Mirage_Caught:
	.string "GARDEVOIR's aura steadies yours.$"

Genesis_Text_TownMon_Mirage_Done:
	.string "Mirage minds sleep easier.$"

Genesis_EventScript_TownMon_Verdantis::
	lock
	faceplayer
	setvar VAR_0x8004, 9
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Verdantis_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Verdantis_OfferCatch
	msgbox Genesis_Text_TownMon_Verdantis_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Verdantis_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_VOLCARONA, 56, ITEM_SILVER_POWDER
	createmon B_SIDE_OPPONENT, 0, SPECIES_VOLCARONA, 56, item=ITEM_SILVER_POWDER, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Verdantis_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Verdantis_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Verdantis_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Verdantis_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Verdantis_OfferCatch
	end

Genesis_EventScript_TownMon_Verdantis_OfferCatch::
	msgbox Genesis_Text_TownMon_Verdantis_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Verdantis_CatchLater
	closemessage
	setwildbattle SPECIES_VOLCARONA, 56, ITEM_SILVER_POWDER
	createmon B_SIDE_OPPONENT, 0, SPECIES_VOLCARONA, 56, item=ITEM_SILVER_POWDER, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Verdantis_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Verdantis_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Verdantis_Caught::
	setvar VAR_0x8004, 9
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Verdantis_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Verdantis_Done::
	msgbox Genesis_Text_TownMon_Verdantis_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Verdantis_Lore:
	.string "Verdantis bug labs reared a VOLCARONA\nfrom a LARVESTA cocoon--Sun Pokémon\pwhose scales once warmed continents.\nBug power at near-pseudo strength.$"

Genesis_Text_TownMon_Verdantis_Challenge:
	.string "Face VOLCARONA's heat?$"

Genesis_Text_TownMon_Verdantis_Defeat:
	.string "Solar dust drifts down…$"

Genesis_Text_TownMon_Verdantis_CatchOffer:
	.string "Raise VOLCARONA yourself?$"

Genesis_Text_TownMon_Verdantis_Caught:
	.string "VOLCARONA's wings shield you.$"

Genesis_Text_TownMon_Verdantis_Done:
	.string "Lab lamps glow amber since then.$"

Genesis_EventScript_TownMon_Obsidian::
	lock
	faceplayer
	setvar VAR_0x8004, 10
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Obsidian_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Obsidian_OfferCatch
	msgbox Genesis_Text_TownMon_Obsidian_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Obsidian_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_HYDREIGON, 58, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_HYDREIGON, 58, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Obsidian_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Obsidian_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Obsidian_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Obsidian_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Obsidian_OfferCatch
	end

Genesis_EventScript_TownMon_Obsidian_OfferCatch::
	msgbox Genesis_Text_TownMon_Obsidian_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Obsidian_CatchLater
	closemessage
	setwildbattle SPECIES_HYDREIGON, 58, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_HYDREIGON, 58, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Obsidian_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Obsidian_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Obsidian_Caught::
	setvar VAR_0x8004, 10
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Obsidian_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Obsidian_Done::
	msgbox Genesis_Text_TownMon_Obsidian_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Obsidian_Lore:
	.string "Obsidian vents raised a brutal HYDREIGON--\nBrutal Pokémon, three heads of DARK.\pA classic pseudo-legend that learned\nto hunt in volcanic night.$"

Genesis_Text_TownMon_Obsidian_Challenge:
	.string "Stare down HYDREIGON?$"

Genesis_Text_TownMon_Obsidian_Defeat:
	.string "All three heads lower…$"

Genesis_Text_TownMon_Obsidian_CatchOffer:
	.string "Claim HYDREIGON as an ally?$"

Genesis_Text_TownMon_Obsidian_Caught:
	.string "HYDREIGON's rage focuses for you.$"

Genesis_Text_TownMon_Obsidian_Done:
	.string "Vent shadows feel less hungry.$"

Genesis_EventScript_TownMon_Astral::
	lock
	faceplayer
	setvar VAR_0x8004, 11
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Astral_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Astral_OfferCatch
	msgbox Genesis_Text_TownMon_Astral_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Astral_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_DRAGONITE, 60, ITEM_DRAGON_FANG
	createmon B_SIDE_OPPONENT, 0, SPECIES_DRAGONITE, 60, item=ITEM_DRAGON_FANG, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Astral_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Astral_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Astral_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Astral_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Astral_OfferCatch
	end

Genesis_EventScript_TownMon_Astral_OfferCatch::
	msgbox Genesis_Text_TownMon_Astral_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Astral_CatchLater
	closemessage
	setwildbattle SPECIES_DRAGONITE, 60, ITEM_DRAGON_FANG
	createmon B_SIDE_OPPONENT, 0, SPECIES_DRAGONITE, 60, item=ITEM_DRAGON_FANG, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Astral_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Astral_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Astral_Caught::
	setvar VAR_0x8004, 11
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Astral_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Astral_Done::
	msgbox Genesis_Text_TownMon_Astral_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Astral_Lore:
	.string "Astral scopes track a DRAGONITE ferrying\nstorm-lost ships--the Dragon Pokémon\pevery trainer names as the first\npseudo-legend of the skies.$"

Genesis_Text_TownMon_Astral_Challenge:
	.string "Challenge DRAGONITE?$"

Genesis_Text_TownMon_Astral_Defeat:
	.string "Gale and wingbeat still…$"

Genesis_Text_TownMon_Astral_CatchOffer:
	.string "Journey with DRAGONITE?$"

Genesis_Text_TownMon_Astral_Caught:
	.string "DRAGONITE rumbles warmly.$"

Genesis_Text_TownMon_Astral_Done:
	.string "Astral logs keep its flight path.$"

Genesis_EventScript_TownMon_Tidymoon::
	lock
	faceplayer
	setvar VAR_0x8004, 12
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Tidymoon_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Tidymoon_OfferCatch
	msgbox Genesis_Text_TownMon_Tidymoon_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Tidymoon_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_TOGEKISS, 62, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_TOGEKISS, 62, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Tidymoon_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Tidymoon_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Tidymoon_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Tidymoon_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Tidymoon_OfferCatch
	end

Genesis_EventScript_TownMon_Tidymoon_OfferCatch::
	msgbox Genesis_Text_TownMon_Tidymoon_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Tidymoon_CatchLater
	closemessage
	setwildbattle SPECIES_TOGEKISS, 62, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_TOGEKISS, 62, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Tidymoon_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Tidymoon_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Tidymoon_Caught::
	setvar VAR_0x8004, 12
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Tidymoon_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Tidymoon_Done::
	msgbox Genesis_Text_TownMon_Tidymoon_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Tidymoon_Lore:
	.string "Tidymoon tides bless kind hearts.\nTOGEKISS--Jubilee Pokémon--appears\pwhere peace is kept. Fairy grace\nwithout needing a mythical seal.$"

Genesis_Text_TownMon_Tidymoon_Challenge:
	.string "Dance against TOGEKISS?$"

Genesis_Text_TownMon_Tidymoon_Defeat:
	.string "Moonlit feathers settle…$"

Genesis_Text_TownMon_Tidymoon_CatchOffer:
	.string "Travel with TOGEKISS?$"

Genesis_Text_TownMon_Tidymoon_Caught:
	.string "TOGEKISS circles you once, joyful.$"

Genesis_Text_TownMon_Tidymoon_Done:
	.string "Tide shrines stay flowered.$"

Genesis_EventScript_TownMon_Eon::
	lock
	faceplayer
	setvar VAR_0x8004, 13
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Eon_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Eon_OfferCatch
	msgbox Genesis_Text_TownMon_Eon_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Eon_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_DRAGAPULT, 63, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_DRAGAPULT, 63, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Eon_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Eon_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Eon_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Eon_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Eon_OfferCatch
	end

Genesis_EventScript_TownMon_Eon_OfferCatch::
	msgbox Genesis_Text_TownMon_Eon_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Eon_CatchLater
	closemessage
	setwildbattle SPECIES_DRAGAPULT, 63, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_DRAGAPULT, 63, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Eon_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Eon_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Eon_Caught::
	setvar VAR_0x8004, 13
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Eon_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Eon_Done::
	msgbox Genesis_Text_TownMon_Eon_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Eon_Lore:
	.string "Eon City's bells hid a DRAGAPULT nest--\nStealth Pokémon that launches DREEPY\plike living missiles. Ghost-dragon\npseudo power in the belfry dark.$"

Genesis_Text_TownMon_Eon_Challenge:
	.string "Intercept DRAGAPULT?$"

Genesis_Text_TownMon_Eon_Defeat:
	.string "The belfry goes still…$"

Genesis_Text_TownMon_Eon_CatchOffer:
	.string "Crew up with DRAGAPULT?$"

Genesis_Text_TownMon_Eon_Caught:
	.string "DRAGAPULT stows its DREEPY for you.$"

Genesis_Text_TownMon_Eon_Done:
	.string "Bells toll cleaner at dusk.$"

Genesis_EventScript_TownMon_GenesisCity::
	lock
	faceplayer
	setvar VAR_0x8004, 14
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_GenesisCity_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_GenesisCity_OfferCatch
	msgbox Genesis_Text_TownMon_GenesisCity_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_GenesisCity_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_SLAKING, 64, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_SLAKING, 64, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_GenesisCity_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_GenesisCity_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_GenesisCity_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_GenesisCity_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_GenesisCity_OfferCatch
	end

Genesis_EventScript_TownMon_GenesisCity_OfferCatch::
	msgbox Genesis_Text_TownMon_GenesisCity_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_GenesisCity_CatchLater
	closemessage
	setwildbattle SPECIES_SLAKING, 64, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_SLAKING, 64, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_GenesisCity_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_GenesisCity_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_GenesisCity_Caught::
	setvar VAR_0x8004, 14
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_GenesisCity_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_GenesisCity_Done::
	msgbox Genesis_Text_TownMon_GenesisCity_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_GenesisCity_Lore:
	.string "Genesis City's training yards host a\nSLAKING--Lazy Pokémon with monstrous\pNORMAL power that outclasses most\nlegends… when it bothers to move.$"

Genesis_Text_TownMon_GenesisCity_Challenge:
	.string "Rouse SLAKING to battle?$"

Genesis_Text_TownMon_GenesisCity_Defeat:
	.string "It yawns… then yields.$"

Genesis_Text_TownMon_GenesisCity_CatchOffer:
	.string "Can you keep SLAKING motivated?$"

Genesis_Text_TownMon_GenesisCity_Caught:
	.string "SLAKING shuffles into your care.$"

Genesis_Text_TownMon_GenesisCity_Done:
	.string "Yard trainers still tip-toe past it.$"

Genesis_EventScript_TownMon_Summit::
	lock
	faceplayer
	setvar VAR_0x8004, 15
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Summit_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Summit_OfferCatch
	msgbox Genesis_Text_TownMon_Summit_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Summit_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_TYRANITAR, 65, ITEM_HARD_STONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_TYRANITAR, 65, item=ITEM_HARD_STONE, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Summit_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Summit_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Summit_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Summit_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Summit_OfferCatch
	end

Genesis_EventScript_TownMon_Summit_OfferCatch::
	msgbox Genesis_Text_TownMon_Summit_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Summit_CatchLater
	closemessage
	setwildbattle SPECIES_TYRANITAR, 65, ITEM_HARD_STONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_TYRANITAR, 65, item=ITEM_HARD_STONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Summit_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Summit_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Summit_Caught::
	setvar VAR_0x8004, 15
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Summit_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Summit_Done::
	msgbox Genesis_Text_TownMon_Summit_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Summit_Lore:
	.string "The Summit's fault line woke a TYRANITAR--\nArmor Pokémon, ROCK and DARK pseudo.\pSandstorms answer its roar. Mentor\ncalls it the mountain's true trial.$"

Genesis_Text_TownMon_Summit_Challenge:
	.string "Stand against TYRANITAR?$"

Genesis_Text_TownMon_Summit_Defeat:
	.string "The sandstorm breaks…$"

Genesis_Text_TownMon_Summit_CatchOffer:
	.string "Command TYRANITAR?$"

Genesis_Text_TownMon_Summit_Caught:
	.string "TYRANITAR's armor accepts you.$"

Genesis_Text_TownMon_Summit_Done:
	.string "Summit stone still bears its claw.$"

Genesis_EventScript_TownMon_Venom::
	lock
	faceplayer
	setvar VAR_0x8004, 16
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Venom_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Venom_OfferCatch
	msgbox Genesis_Text_TownMon_Venom_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Venom_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_GENGAR, 66, ITEM_POISON_BARB
	createmon B_SIDE_OPPONENT, 0, SPECIES_GENGAR, 66, item=ITEM_POISON_BARB, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Venom_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Venom_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Venom_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Venom_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Venom_OfferCatch
	end

Genesis_EventScript_TownMon_Venom_OfferCatch::
	msgbox Genesis_Text_TownMon_Venom_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Venom_CatchLater
	closemessage
	setwildbattle SPECIES_GENGAR, 66, ITEM_POISON_BARB
	createmon B_SIDE_OPPONENT, 0, SPECIES_GENGAR, 66, item=ITEM_POISON_BARB, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Venom_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Venom_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Venom_Caught::
	setvar VAR_0x8004, 16
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Venom_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Venom_Done::
	msgbox Genesis_Text_TownMon_Venom_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Venom_Lore:
	.string "Venom Hollow's mist hides a GENGAR--\nShadow Pokémon steeped in toxins.\pNot a mythic binder, just a cunning\nPOISON trickster of the vapor vents.$"

Genesis_Text_TownMon_Venom_Challenge:
	.string "Outwit GENGAR?$"

Genesis_Text_TownMon_Venom_Defeat:
	.string "The grin fades into mist…$"

Genesis_Text_TownMon_Venom_CatchOffer:
	.string "Let GENGAR haunt your shadow?$"

Genesis_Text_TownMon_Venom_Caught:
	.string "GENGAR chuckles--deal struck.$"

Genesis_Text_TownMon_Venom_Done:
	.string "Hollow vapors feel less biting.$"

Genesis_EventScript_TownMon_Terracotta::
	lock
	faceplayer
	setvar VAR_0x8004, 17
	callnative Genesis_TownMonIsDone
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_TownMon_Terracotta_Done
	goto_if_set FLAG_TEMP_A, Genesis_EventScript_TownMon_Terracotta_OfferCatch
	msgbox Genesis_Text_TownMon_Terracotta_Lore, MSGBOX_DEFAULT
	msgbox Genesis_Text_TownMon_Terracotta_Challenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline
	closemessage
	setwildbattle SPECIES_GARCHOMP, 70, ITEM_SOFT_SAND
	createmon B_SIDE_OPPONENT, 0, SPECIES_GARCHOMP, 70, item=ITEM_SOFT_SAND, shinyMode=SHINY_MODE_ALWAYS
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Terracotta_Caught
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_TownMon_Terracotta_Won
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Terracotta_Won::
	setflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Terracotta_Defeat, MSGBOX_DEFAULT
	goto Genesis_EventScript_TownMon_Terracotta_OfferCatch
	end

Genesis_EventScript_TownMon_Terracotta_OfferCatch::
	msgbox Genesis_Text_TownMon_Terracotta_CatchOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Terracotta_CatchLater
	closemessage
	setwildbattle SPECIES_GARCHOMP, 70, ITEM_SOFT_SAND
	createmon B_SIDE_OPPONENT, 0, SPECIES_GARCHOMP, 70, item=ITEM_SOFT_SAND, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_TownMon_Terracotta_Caught
	msgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Terracotta_CatchLater::
	msgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Terracotta_Caught::
	setvar VAR_0x8004, 17
	callnative Genesis_TownMonSetDone
	clearflag FLAG_TEMP_A
	msgbox Genesis_Text_TownMon_Terracotta_Caught, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_TownMon_Terracotta_Done::
	msgbox Genesis_Text_TownMon_Terracotta_Done, MSGBOX_DEFAULT
	release
	end

Genesis_Text_TownMon_Terracotta_Lore:
	.string "Terracotta Mesa's dunes birthed a\nGARCHOMP--Mach Pokémon, land shark\pand GROUND-type pseudo-legend. Soil\nremembers every stride it takes.$"

Genesis_Text_TownMon_Terracotta_Challenge:
	.string "Race GARCHOMP across the mesa?$"

Genesis_Text_TownMon_Terracotta_Defeat:
	.string "Dust settles in its wake…$"

Genesis_Text_TownMon_Terracotta_CatchOffer:
	.string "Hunt alongside GARCHOMP?$"

Genesis_Text_TownMon_Terracotta_Caught:
	.string "GARCHOMP fins the air--accepted.$"

Genesis_Text_TownMon_Terracotta_Done:
	.string "Mesa crops root deeper since then.$"

