@ GENESIS: Per-gym-town lore Pokémon (Metagross-style catch quests)

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
	setwildbattle SPECIES_SHAYMIN_LAND, 30, ITEM_LUM_BERRY
	createmon B_SIDE_OPPONENT, 0, SPECIES_SHAYMIN_LAND, 30, item=ITEM_LUM_BERRY, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_SHAYMIN_LAND, 30, ITEM_LUM_BERRY
	createmon B_SIDE_OPPONENT, 0, SPECIES_SHAYMIN_LAND, 30, item=ITEM_LUM_BERRY, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "They say a Gratitude Pokémon sleeps in\nthe flower beds when LUMEN is kind.\pSHAYMIN blooms where pure hearts gather.\nWill you greet it?$"

Genesis_Text_TownMon_Lumen_Challenge:
	.string "SHAYMIN's flowers stir… Challenge it?$"

Genesis_Text_TownMon_Lumen_Defeat:
	.string "The petals settle…$"

Genesis_Text_TownMon_Lumen_CatchOffer:
	.string "Offer a home to the Gratitude Pokémon?$"

Genesis_Text_TownMon_Lumen_Caught:
	.string "SHAYMIN trusts you now.$"

Genesis_Text_TownMon_Lumen_Done:
	.string "SHAYMIN's meadow remembers your kindness.$"

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
	setwildbattle SPECIES_KELDEO, 28, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_KELDEO, 28, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_KELDEO, 28, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_KELDEO, 28, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Ironridge forges more than steel--\nit forges will.\pA Colt Pokémon trains at the shore,\nseeking the Secret Sword of resolve.$"

Genesis_Text_TownMon_Ironridge_Challenge:
	.string "Face KELDEO's trial?$"

Genesis_Text_TownMon_Ironridge_Defeat:
	.string "Its blade of water stills…$"

Genesis_Text_TownMon_Ironridge_CatchOffer:
	.string "Invite KELDEO to travel with you?$"

Genesis_Text_TownMon_Ironridge_Caught:
	.string "KELDEO nods--your paths align.$"

Genesis_Text_TownMon_Ironridge_Done:
	.string "KELDEO still drills at dawn.$"

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
	setwildbattle SPECIES_MANAPHY, 35, ITEM_MYSTIC_WATER
	createmon B_SIDE_OPPONENT, 0, SPECIES_MANAPHY, 35, item=ITEM_MYSTIC_WATER, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_MANAPHY, 35, ITEM_MYSTIC_WATER
	createmon B_SIDE_OPPONENT, 0, SPECIES_MANAPHY, 35, item=ITEM_MYSTIC_WATER, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Port Azure tides once cradled a Seafaring\nPokémon--prince of the ocean.\pMANAPHY washes ashore when trainers\nprotect the bay.$"

Genesis_Text_TownMon_PortAzure_Challenge:
	.string "Answer MANAPHY's call?$"

Genesis_Text_TownMon_PortAzure_Defeat:
	.string "The sea grows calm…$"

Genesis_Text_TownMon_PortAzure_CatchOffer:
	.string "Take MANAPHY under your care?$"

Genesis_Text_TownMon_PortAzure_Caught:
	.string "MANAPHY sparkles with joy.$"

Genesis_Text_TownMon_PortAzure_Done:
	.string "The bay still sings for MANAPHY.$"

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
	setwildbattle SPECIES_REGICE, 40, ITEM_NEVER_MELT_ICE
	createmon B_SIDE_OPPONENT, 0, SPECIES_REGICE, 40, item=ITEM_NEVER_MELT_ICE, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_REGICE, 40, ITEM_NEVER_MELT_ICE
	createmon B_SIDE_OPPONENT, 0, SPECIES_REGICE, 40, item=ITEM_NEVER_MELT_ICE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Frostveil's springs hide a paradox--\nice sealed beneath heat.\pREGICE, the Iceberg Pokémon, waits in\na cold vault under the spa rocks.$"

Genesis_Text_TownMon_Frostveil_Challenge:
	.string "Wake REGICE?$"

Genesis_Text_TownMon_Frostveil_Defeat:
	.string "Ancient ice cracks… then stills.$"

Genesis_Text_TownMon_Frostveil_CatchOffer:
	.string "Bind REGICE to your team?$"

Genesis_Text_TownMon_Frostveil_Caught:
	.string "REGICE's frost accepts you.$"

Genesis_Text_TownMon_Frostveil_Done:
	.string "The ice vault stays quiet.$"

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
	setwildbattle SPECIES_ENTEI, 42, ITEM_CHARCOAL
	createmon B_SIDE_OPPONENT, 0, SPECIES_ENTEI, 42, item=ITEM_CHARCOAL, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_ENTEI, 42, ITEM_CHARCOAL
	createmon B_SIDE_OPPONENT, 0, SPECIES_ENTEI, 42, item=ITEM_CHARCOAL, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Solaris worships the sun.\nWhen volcanoes birthed legends,\pENTEI--Volcano Pokémon--raced the\nridges, leaving ash-flowers in its wake.$"

Genesis_Text_TownMon_Solaris_Challenge:
	.string "Race ENTEI's flame?$"

Genesis_Text_TownMon_Solaris_Defeat:
	.string "The ridge cools…$"

Genesis_Text_TownMon_Solaris_CatchOffer:
	.string "Walk beside ENTEI?$"

Genesis_Text_TownMon_Solaris_Caught:
	.string "ENTEI's roar becomes your beacon.$"

Genesis_Text_TownMon_Solaris_Done:
	.string "Ash-flowers still mark its path.$"

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
	setwildbattle SPECIES_TORNADUS, 48, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_TORNADUS, 48, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_TORNADUS, 48, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_TORNADUS, 48, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Stormbreak cliffs call the Gale Pokémon.\nTORNADUS whips sea and sky into fury\pwhen respect for the wind is forgotten.$"

Genesis_Text_TownMon_Stormbreak_Challenge:
	.string "Stand against TORNADUS?$"

Genesis_Text_TownMon_Stormbreak_Defeat:
	.string "The gale softens…$"

Genesis_Text_TownMon_Stormbreak_CatchOffer:
	.string "Partner with TORNADUS?$"

Genesis_Text_TownMon_Stormbreak_Caught:
	.string "TORNADUS circles you once--accepted.$"

Genesis_Text_TownMon_Stormbreak_Done:
	.string "Winds still bow at Stormbreak.$"

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
	setwildbattle SPECIES_JIRACHI, 50, ITEM_STAR_PIECE
	createmon B_SIDE_OPPONENT, 0, SPECIES_JIRACHI, 50, item=ITEM_STAR_PIECE, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_JIRACHI, 50, ITEM_STAR_PIECE
	createmon B_SIDE_OPPONENT, 0, SPECIES_JIRACHI, 50, item=ITEM_STAR_PIECE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Titania's steel mirrors catch falling\nstars. Myths say JIRACHI--Wish Pokémon--\psleeps a thousand years, waking for a\nweek of wishes in a meteor cradle.$"

Genesis_Text_TownMon_Titania_Challenge:
	.string "Wake JIRACHI's dream?$"

Genesis_Text_TownMon_Titania_Defeat:
	.string "Starlight fades gently…$"

Genesis_Text_TownMon_Titania_CatchOffer:
	.string "Will you grant JIRACHI a journey?$"

Genesis_Text_TownMon_Titania_Caught:
	.string "JIRACHI's tags flutter--wish shared.$"

Genesis_Text_TownMon_Titania_Done:
	.string "The meteor cradle glimmers softly.$"

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
	setwildbattle SPECIES_CRESSELIA, 55, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_CRESSELIA, 55, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_CRESSELIA, 55, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_CRESSELIA, 55, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Mirage City bends light and dream.\nCRESSELIA, the Lunar Pokémon, soothes\pnightmares--its crescent veil steadies\nminds lost in illusion.$"

Genesis_Text_TownMon_Mirage_Challenge:
	.string "Call CRESSELIA?$"

Genesis_Text_TownMon_Mirage_Defeat:
	.string "Moonlight settles…$"

Genesis_Text_TownMon_Mirage_CatchOffer:
	.string "Travel with CRESSELIA?$"

Genesis_Text_TownMon_Mirage_Caught:
	.string "CRESSELIA's veil wraps your team.$"

Genesis_Text_TownMon_Mirage_Done:
	.string "Dreams in Mirage stay gentle.$"

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
	setwildbattle SPECIES_GENESECT, 56, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_GENESECT, 56, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_GENESECT, 56, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_GENESECT, 56, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Verdantis insect labs restored an ancient\nUltra weapon--GENESECT, the Paleozoic\pPokémon, cannon and all. It seeks a\ntrainer, not a cage.$"

Genesis_Text_TownMon_Verdantis_Challenge:
	.string "Challenge GENESECT?$"

Genesis_Text_TownMon_Verdantis_Defeat:
	.string "The cannon powers down…$"

Genesis_Text_TownMon_Verdantis_CatchOffer:
	.string "Free GENESECT as a partner?$"

Genesis_Text_TownMon_Verdantis_Caught:
	.string "GENESECT's drive hums in sync.$"

Genesis_Text_TownMon_Verdantis_Done:
	.string "The lab monitors stay green.$"

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
	setwildbattle SPECIES_DARKRAI, 58, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_DARKRAI, 58, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_DARKRAI, 58, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_DARKRAI, 58, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Obsidian's vents birth bad dreams.\nDARKRAI, the Pitch-Black Pokémon, was\pblamed for every nightmare--yet it only\nseeks a place without fear.$"

Genesis_Text_TownMon_Obsidian_Challenge:
	.string "Confront DARKRAI?$"

Genesis_Text_TownMon_Obsidian_Defeat:
	.string "The nightmares thin…$"

Genesis_Text_TownMon_Obsidian_CatchOffer:
	.string "Offer DARKRAI sanctuary?$"

Genesis_Text_TownMon_Obsidian_Caught:
	.string "DARKRAI fades into your shadow--ally.$"

Genesis_Text_TownMon_Obsidian_Done:
	.string "Night in Obsidian grows quieter.$"

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
	setwildbattle SPECIES_LATIOS, 60, ITEM_SOUL_DEW
	createmon B_SIDE_OPPONENT, 0, SPECIES_LATIOS, 60, item=ITEM_SOUL_DEW, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_LATIOS, 60, ITEM_SOUL_DEW
	createmon B_SIDE_OPPONENT, 0, SPECIES_LATIOS, 60, item=ITEM_SOUL_DEW, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Astral's observatory tracks Eon Pokémon.\nLATIOS shares compassion across distance,\pguiding those who chart the sky with\ncare, not conquest.$"

Genesis_Text_TownMon_Astral_Challenge:
	.string "Meet LATIOS in battle?$"

Genesis_Text_TownMon_Astral_Defeat:
	.string "The sky-blue aura dims…$"

Genesis_Text_TownMon_Astral_CatchOffer:
	.string "Fly with LATIOS?$"

Genesis_Text_TownMon_Astral_Caught:
	.string "LATIOS opens a telepathic bond.$"

Genesis_Text_TownMon_Astral_Done:
	.string "Astral scopes still track your friend.$"

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
	setwildbattle SPECIES_ENAMORUS, 62, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_ENAMORUS, 62, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_ENAMORUS, 62, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_ENAMORUS, 62, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Tidymoon tides swell with Love-Hate\nenergy. ENAMORUS arrives when hearts\pand seasons turn--fairy force of spring\noff the moonlit coast.$"

Genesis_Text_TownMon_Tidymoon_Challenge:
	.string "Dance with ENAMORUS?$"

Genesis_Text_TownMon_Tidymoon_Defeat:
	.string "Petals of foam settle…$"

Genesis_Text_TownMon_Tidymoon_CatchOffer:
	.string "Journey with ENAMORUS?$"

Genesis_Text_TownMon_Tidymoon_Caught:
	.string "ENAMORUS smiles--spring follows you.$"

Genesis_Text_TownMon_Tidymoon_Done:
	.string "Tide pools still glow at night.$"

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
	setwildbattle SPECIES_MARSHADOW, 63, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_MARSHADOW, 63, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_MARSHADOW, 63, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_MARSHADOW, 63, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Eon City's bells hide a Gloomdweller.\nMARSHADOW lives in shadows, copying the\pmoves of warriors it respects.$"

Genesis_Text_TownMon_Eon_Challenge:
	.string "Draw MARSHADOW out?$"

Genesis_Text_TownMon_Eon_Defeat:
	.string "The shadow stills…$"

Genesis_Text_TownMon_Eon_CatchOffer:
	.string "Let MARSHADOW walk in your shade?$"

Genesis_Text_TownMon_Eon_Caught:
	.string "MARSHADOW bows--student of your style.$"

Genesis_Text_TownMon_Eon_Done:
	.string "Bells toll softer now.$"

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
	setwildbattle SPECIES_MELOETTA, 64, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_MELOETTA, 64, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_MELOETTA, 64, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_MELOETTA, 64, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Genesis City is AURELIA's hub of arts\nand prep. MELOETTA--Melody Pokémon--\panswers when many voices train as one.$"

Genesis_Text_TownMon_GenesisCity_Challenge:
	.string "Perform against MELOETTA?$"

Genesis_Text_TownMon_GenesisCity_Defeat:
	.string "The song resolves…$"

Genesis_Text_TownMon_GenesisCity_CatchOffer:
	.string "Invite MELOETTA on tour?$"

Genesis_Text_TownMon_GenesisCity_Caught:
	.string "MELOETTA's aria becomes your theme.$"

Genesis_Text_TownMon_GenesisCity_Done:
	.string "Street musicians still hum its tune.$"

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
	setwildbattle SPECIES_REGIROCK, 65, ITEM_HARD_STONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_REGIROCK, 65, item=ITEM_HARD_STONE, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_REGIROCK, 65, ITEM_HARD_STONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_REGIROCK, 65, item=ITEM_HARD_STONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "The eastern Summit keeps a Rock Peak\ngolem. REGIROCK's body is pure stone\pfrom every era--Mentor's trial beyond\nthe stone badges.$"

Genesis_Text_TownMon_Summit_Challenge:
	.string "Strike REGIROCK?$"

Genesis_Text_TownMon_Summit_Defeat:
	.string "Pebbles cease falling…$"

Genesis_Text_TownMon_Summit_CatchOffer:
	.string "Command REGIROCK?$"

Genesis_Text_TownMon_Summit_Caught:
	.string "REGIROCK's eyes glow acceptance.$"

Genesis_Text_TownMon_Summit_Done:
	.string "The peak stones remember you.$"

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
	setwildbattle SPECIES_PECHARUNT, 66, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_PECHARUNT, 66, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_PECHARUNT, 66, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_PECHARUNT, 66, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Venom Hollow's mochi myths were true.\nPECHARUNT binds with toxic hospitality--\pyet it can learn trust instead of chains.$"

Genesis_Text_TownMon_Venom_Challenge:
	.string "Break PECHARUNT's binding bout?$"

Genesis_Text_TownMon_Venom_Defeat:
	.string "The sweet scent fades…$"

Genesis_Text_TownMon_Venom_CatchOffer:
	.string "Reform PECHARUNT as an ally?$"

Genesis_Text_TownMon_Venom_Caught:
	.string "PECHARUNT offers a toxin-free pact.$"

Genesis_Text_TownMon_Venom_Done:
	.string "Hollow vapors smell cleaner.$"

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
	setwildbattle SPECIES_LANDORUS, 70, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_LANDORUS, 70, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS
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
	setwildbattle SPECIES_LANDORUS, 70, ITEM_NONE
	createmon B_SIDE_OPPONENT, 0, SPECIES_LANDORUS, 70, item=ITEM_NONE, shinyMode=SHINY_MODE_ALWAYS, hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0
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
	.string "Terracotta Mesa thrives when LANDORUS--\nAbundance Pokémon--blesses the soil.\pIt tests those who would till ground\nwithout greed.$"

Genesis_Text_TownMon_Terracotta_Challenge:
	.string "Earn LANDORUS's blessing?$"

Genesis_Text_TownMon_Terracotta_Defeat:
	.string "Dust settles into fertile quiet…$"

Genesis_Text_TownMon_Terracotta_CatchOffer:
	.string "Travel with LANDORUS?$"

Genesis_Text_TownMon_Terracotta_Caught:
	.string "LANDORUS crowns your journey.$"

Genesis_Text_TownMon_Terracotta_Done:
	.string "Mesa crops grow taller since then.$"

