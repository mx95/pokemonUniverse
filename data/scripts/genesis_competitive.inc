@ GENESIS: Postgame competitive prep desk (Hyper Train + supply mart).
@ Wired from Lumen City Pokémon Center Gentleman.

Genesis_EventScript_CompetitiveDesk::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Genesis_EventScript_CompetitivePreChamp
	goto_if_unset FLAG_GENESIS_TUTOR_INTRO, Genesis_EventScript_CompetitiveIntroKit
	goto Genesis_EventScript_CompetitiveMenu
	end

Genesis_EventScript_CompetitivePreChamp::
	msgbox Genesis_Text_CompetitivePreChamp, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_CompetitiveIntroKit::
	msgbox Genesis_Text_CompetitiveIntroOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_CompetitiveIntroDecline
	giveitem ITEM_BOTTLE_CAP
	giveitem ITEM_ABILITY_CAPSULE
	setflag FLAG_GENESIS_TUTOR_INTRO
	msgbox Genesis_Text_CompetitiveIntroAfter, MSGBOX_DEFAULT
	goto Genesis_EventScript_CompetitiveMenu
	end

Genesis_EventScript_CompetitiveIntroDecline::
	msgbox Genesis_Text_CompetitiveIntroDecline, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_CompetitiveMenu::
	message Genesis_Text_CompetitiveMenuPrompt
	waitmessage
	dynmultipush Genesis_Text_CompetitiveOptHyper, 0
	dynmultipush Genesis_Text_CompetitiveOptGold, 1
	dynmultipush Genesis_Text_CompetitiveOptShop, 2
	dynmultipush Genesis_Text_CompetitiveOptAdvice, 3
	dynmultipush Genesis_Text_CompetitiveOptLeave, 4
	dynmultistack 0, 0, FALSE, 5, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, Genesis_EventScript_CompetitiveHyperTrain
	case 1, Genesis_EventScript_CompetitiveGoldTrain
	case 2, Genesis_EventScript_CompetitiveShop
	case 3, Genesis_EventScript_CompetitiveAdvice
	case 4, Genesis_EventScript_CompetitiveLeave
	case MULTI_B_PRESSED, Genesis_EventScript_CompetitiveLeave
	goto Genesis_EventScript_CompetitiveLeave
	end

Genesis_EventScript_CompetitiveLeave::
	msgbox Genesis_Text_CompetitiveLeave, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_CompetitiveAdvice::
	msgbox Genesis_Text_CompetitiveAdvice, MSGBOX_DEFAULT
	goto Genesis_EventScript_CompetitiveMenu
	end

Genesis_EventScript_CompetitiveShop::
	message gText_HowMayIServeYou
	waitmessage
	pokemart Genesis_Pokemart_Competitive
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	goto Genesis_EventScript_CompetitiveMenu
	end

	.align 2
Genesis_Pokemart_Competitive:
	.2byte ITEM_BOTTLE_CAP
	.2byte ITEM_GOLD_BOTTLE_CAP
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_TIMID_MINT
	pokemartlistend

Genesis_EventScript_CompetitiveHyperTrain::
	checkitem ITEM_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, Genesis_EventScript_CompetitiveNoBottleCap
	msgbox Genesis_Text_CompetitiveChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Genesis_EventScript_CompetitiveMenu
	goto_if_ge VAR_0x8004, PARTY_SIZE, Genesis_EventScript_CompetitiveMenu
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveCantEgg
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	msgbox Genesis_Text_CompetitiveWhichStat, MSGBOX_DEFAULT
	goto Genesis_EventScript_CompetitiveStatMenu
	end

Genesis_EventScript_CompetitiveStatMenu::
	message Genesis_Text_CompetitiveStatPrompt
	waitmessage
	dynmultipush Genesis_Text_StatHP, 0
	dynmultipush Genesis_Text_StatAtk, 1
	dynmultipush Genesis_Text_StatDef, 2
	dynmultipush Genesis_Text_StatSpeed, 3
	dynmultipush Genesis_Text_StatSpAtk, 4
	dynmultipush Genesis_Text_StatSpDef, 5
	dynmultipush Genesis_Text_CompetitiveOptCancel, 6
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, Genesis_EventScript_CompetitiveTrainHP
	case 1, Genesis_EventScript_CompetitiveTrainAtk
	case 2, Genesis_EventScript_CompetitiveTrainDef
	case 3, Genesis_EventScript_CompetitiveTrainSpeed
	case 4, Genesis_EventScript_CompetitiveTrainSpAtk
	case 5, Genesis_EventScript_CompetitiveTrainSpDef
	case 6, Genesis_EventScript_CompetitiveMenu
	case MULTI_B_PRESSED, Genesis_EventScript_CompetitiveMenu
	goto Genesis_EventScript_CompetitiveMenu
	end

Genesis_EventScript_CompetitiveTrainHP::
	setvar VAR_0x8005, STAT_HP
	bufferstring STR_VAR_2, Genesis_Text_StatHP
	goto Genesis_EventScript_CompetitiveDoSingleTrain
	end

Genesis_EventScript_CompetitiveTrainAtk::
	setvar VAR_0x8005, STAT_ATK
	bufferstring STR_VAR_2, Genesis_Text_StatAtk
	goto Genesis_EventScript_CompetitiveDoSingleTrain
	end

Genesis_EventScript_CompetitiveTrainDef::
	setvar VAR_0x8005, STAT_DEF
	bufferstring STR_VAR_2, Genesis_Text_StatDef
	goto Genesis_EventScript_CompetitiveDoSingleTrain
	end

Genesis_EventScript_CompetitiveTrainSpeed::
	setvar VAR_0x8005, STAT_SPEED
	bufferstring STR_VAR_2, Genesis_Text_StatSpeed
	goto Genesis_EventScript_CompetitiveDoSingleTrain
	end

Genesis_EventScript_CompetitiveTrainSpAtk::
	setvar VAR_0x8005, STAT_SPATK
	bufferstring STR_VAR_2, Genesis_Text_StatSpAtk
	goto Genesis_EventScript_CompetitiveDoSingleTrain
	end

Genesis_EventScript_CompetitiveTrainSpDef::
	setvar VAR_0x8005, STAT_SPDEF
	bufferstring STR_VAR_2, Genesis_Text_StatSpDef
	goto Genesis_EventScript_CompetitiveDoSingleTrain
	end

@ canhypertrain/hypertrain take a literal stat byte; branch per VAR_0x8005.
Genesis_EventScript_CompetitiveDoSingleTrain::
	goto_if_eq VAR_0x8005, STAT_HP, Genesis_EventScript_CompetitiveCanHP
	goto_if_eq VAR_0x8005, STAT_ATK, Genesis_EventScript_CompetitiveCanAtk
	goto_if_eq VAR_0x8005, STAT_DEF, Genesis_EventScript_CompetitiveCanDef
	goto_if_eq VAR_0x8005, STAT_SPEED, Genesis_EventScript_CompetitiveCanSpeed
	goto_if_eq VAR_0x8005, STAT_SPATK, Genesis_EventScript_CompetitiveCanSpAtk
	goto Genesis_EventScript_CompetitiveCanSpDef
	end

Genesis_EventScript_CompetitiveCanHP::
	canhypertrain STAT_HP, VAR_0x8004
	goto Genesis_EventScript_CompetitiveAfterCanCheck
	end

Genesis_EventScript_CompetitiveCanAtk::
	canhypertrain STAT_ATK, VAR_0x8004
	goto Genesis_EventScript_CompetitiveAfterCanCheck
	end

Genesis_EventScript_CompetitiveCanDef::
	canhypertrain STAT_DEF, VAR_0x8004
	goto Genesis_EventScript_CompetitiveAfterCanCheck
	end

Genesis_EventScript_CompetitiveCanSpeed::
	canhypertrain STAT_SPEED, VAR_0x8004
	goto Genesis_EventScript_CompetitiveAfterCanCheck
	end

Genesis_EventScript_CompetitiveCanSpAtk::
	canhypertrain STAT_SPATK, VAR_0x8004
	goto Genesis_EventScript_CompetitiveAfterCanCheck
	end

Genesis_EventScript_CompetitiveCanSpDef::
	canhypertrain STAT_SPDEF, VAR_0x8004
	goto Genesis_EventScript_CompetitiveAfterCanCheck
	end

Genesis_EventScript_CompetitiveAfterCanCheck::
	goto_if_eq VAR_RESULT, FALSE, Genesis_EventScript_CompetitiveCantTrainStat
	msgbox Genesis_Text_CompetitiveConfirmStat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_CompetitiveStatMenu
	removeitem ITEM_BOTTLE_CAP
	goto_if_eq VAR_0x8005, STAT_HP, Genesis_EventScript_CompetitiveApplyHP
	goto_if_eq VAR_0x8005, STAT_ATK, Genesis_EventScript_CompetitiveApplyAtk
	goto_if_eq VAR_0x8005, STAT_DEF, Genesis_EventScript_CompetitiveApplyDef
	goto_if_eq VAR_0x8005, STAT_SPEED, Genesis_EventScript_CompetitiveApplySpeed
	goto_if_eq VAR_0x8005, STAT_SPATK, Genesis_EventScript_CompetitiveApplySpAtk
	goto Genesis_EventScript_CompetitiveApplySpDef
	end

Genesis_EventScript_CompetitiveApplyHP::
	hypertrain STAT_HP, VAR_0x8004
	goto Genesis_EventScript_CompetitiveTrainSuccess
	end

Genesis_EventScript_CompetitiveApplyAtk::
	hypertrain STAT_ATK, VAR_0x8004
	goto Genesis_EventScript_CompetitiveTrainSuccess
	end

Genesis_EventScript_CompetitiveApplyDef::
	hypertrain STAT_DEF, VAR_0x8004
	goto Genesis_EventScript_CompetitiveTrainSuccess
	end

Genesis_EventScript_CompetitiveApplySpeed::
	hypertrain STAT_SPEED, VAR_0x8004
	goto Genesis_EventScript_CompetitiveTrainSuccess
	end

Genesis_EventScript_CompetitiveApplySpAtk::
	hypertrain STAT_SPATK, VAR_0x8004
	goto Genesis_EventScript_CompetitiveTrainSuccess
	end

Genesis_EventScript_CompetitiveApplySpDef::
	hypertrain STAT_SPDEF, VAR_0x8004
	goto Genesis_EventScript_CompetitiveTrainSuccess
	end

Genesis_EventScript_CompetitiveTrainSuccess::
	playse SE_SHOP
	msgbox Genesis_Text_CompetitiveTrainDone, MSGBOX_DEFAULT
	goto Genesis_EventScript_CompetitiveMenu
	end

Genesis_EventScript_CompetitiveCantTrainStat::
	msgbox Genesis_Text_CompetitiveCantStat, MSGBOX_DEFAULT
	goto Genesis_EventScript_CompetitiveStatMenu
	end

Genesis_EventScript_CompetitiveGoldTrain::
	checkitem ITEM_GOLD_BOTTLE_CAP
	goto_if_eq VAR_RESULT, FALSE, Genesis_EventScript_CompetitiveNoGoldCap
	msgbox Genesis_Text_CompetitiveChooseMonGold, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Genesis_EventScript_CompetitiveMenu
	goto_if_ge VAR_0x8004, PARTY_SIZE, Genesis_EventScript_CompetitiveMenu
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveCantEgg
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	setvar VAR_TEMP_1, 0
	canhypertrain STAT_HP, VAR_0x8004
	call_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveMarkTrainable
	canhypertrain STAT_ATK, VAR_0x8004
	call_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveMarkTrainable
	canhypertrain STAT_DEF, VAR_0x8004
	call_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveMarkTrainable
	canhypertrain STAT_SPEED, VAR_0x8004
	call_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveMarkTrainable
	canhypertrain STAT_SPATK, VAR_0x8004
	call_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveMarkTrainable
	canhypertrain STAT_SPDEF, VAR_0x8004
	call_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveMarkTrainable
	goto_if_eq VAR_TEMP_1, 0, Genesis_EventScript_CompetitiveAlreadyPerfect
	msgbox Genesis_Text_CompetitiveConfirmGold, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_CompetitiveMenu
	removeitem ITEM_GOLD_BOTTLE_CAP
	canhypertrain STAT_HP, VAR_0x8004
	call_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveGoldApplyHP
	canhypertrain STAT_ATK, VAR_0x8004
	call_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveGoldApplyAtk
	canhypertrain STAT_DEF, VAR_0x8004
	call_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveGoldApplyDef
	canhypertrain STAT_SPEED, VAR_0x8004
	call_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveGoldApplySpeed
	canhypertrain STAT_SPATK, VAR_0x8004
	call_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveGoldApplySpAtk
	canhypertrain STAT_SPDEF, VAR_0x8004
	call_if_eq VAR_RESULT, TRUE, Genesis_EventScript_CompetitiveGoldApplySpDef
	playse SE_SHOP
	msgbox Genesis_Text_CompetitiveGoldDone, MSGBOX_DEFAULT
	goto Genesis_EventScript_CompetitiveMenu
	end

Genesis_EventScript_CompetitiveMarkTrainable::
	setvar VAR_TEMP_1, 1
	return

Genesis_EventScript_CompetitiveGoldApplyHP::
	hypertrain STAT_HP, VAR_0x8004
	return

Genesis_EventScript_CompetitiveGoldApplyAtk::
	hypertrain STAT_ATK, VAR_0x8004
	return

Genesis_EventScript_CompetitiveGoldApplyDef::
	hypertrain STAT_DEF, VAR_0x8004
	return

Genesis_EventScript_CompetitiveGoldApplySpeed::
	hypertrain STAT_SPEED, VAR_0x8004
	return

Genesis_EventScript_CompetitiveGoldApplySpAtk::
	hypertrain STAT_SPATK, VAR_0x8004
	return

Genesis_EventScript_CompetitiveGoldApplySpDef::
	hypertrain STAT_SPDEF, VAR_0x8004
	return

Genesis_EventScript_CompetitiveNoBottleCap::
	msgbox Genesis_Text_CompetitiveNoBottleCap, MSGBOX_DEFAULT
	goto Genesis_EventScript_CompetitiveMenu
	end

Genesis_EventScript_CompetitiveNoGoldCap::
	msgbox Genesis_Text_CompetitiveNoGoldCap, MSGBOX_DEFAULT
	goto Genesis_EventScript_CompetitiveMenu
	end

Genesis_EventScript_CompetitiveCantEgg::
	msgbox Genesis_Text_CompetitiveCantEgg, MSGBOX_DEFAULT
	goto Genesis_EventScript_CompetitiveMenu
	end

Genesis_EventScript_CompetitiveAlreadyPerfect::
	msgbox Genesis_Text_CompetitiveAlreadyPerfect, MSGBOX_DEFAULT
	goto Genesis_EventScript_CompetitiveMenu
	end

Genesis_Text_CompetitivePreChamp:
	.string "I polish CHAMPION teams for the Frontier.\n"
	.string "Claim the League title, then see me.$"

Genesis_Text_CompetitiveIntroOffer:
	.string "CHAMPION! Lumen's competitive desk is open.\n"
	.string "Take a starter BOTTLE CAP and ABILITY\l"
	.string "CAPSULE to begin Hyper Training?$"

Genesis_Text_CompetitiveIntroAfter:
	.string "Use BOTTLE CAPS here to Hyper Train.\n"
	.string "A GOLD BOTTLE CAP covers every stat.\p"
	.string "Stock up anytime--Fallarbor still handles\n"
	.string "move relearning.$"

Genesis_Text_CompetitiveIntroDecline:
	.string "Come back when you're ready to tune\n"
	.string "a serious team.$"

Genesis_Text_CompetitiveMenuPrompt:
	.string "Competitive prep desk.\n"
	.string "What do you need?$"

Genesis_Text_CompetitiveOptHyper:
	.string "Hyper Train (Bottle Cap)$"

Genesis_Text_CompetitiveOptGold:
	.string "Full Train (Gold Cap)$"

Genesis_Text_CompetitiveOptShop:
	.string "Buy supplies$"

Genesis_Text_CompetitiveOptAdvice:
	.string "Advice$"

Genesis_Text_CompetitiveOptLeave:
	.string "Never mind$"

Genesis_Text_CompetitiveOptCancel:
	.string "Cancel$"

Genesis_Text_CompetitiveLeave:
	.string "Train smart. GENESIS ENERGY favors\n"
	.string "prepared TRAINERS.$"

Genesis_Text_CompetitiveAdvice:
	.string "Hyper Training maxes a stat's potential\n"
	.string "without changing the IV number on paper.\p"
	.string "ABILITY CAPSULES and PATCHES work from\n"
	.string "your Bag. Mints shift Nature.\p"
	.string "Fallarbor's Move Maniac relearns moves.\n"
	.string "The Frontier Exchange spends Battle Points.$"

Genesis_Text_CompetitiveChooseMon:
	.string "Which POKéMON should Hyper Train?$"

Genesis_Text_CompetitiveChooseMonGold:
	.string "Which POKéMON gets a full Hyper Train?$"

Genesis_Text_CompetitiveWhichStat:
	.string "Hyper Train which of {STR_VAR_1}'s stats?$"

Genesis_Text_CompetitiveStatPrompt:
	.string "Choose a stat.$"

Genesis_Text_StatHP:
	.string "HP$"

Genesis_Text_StatAtk:
	.string "Attack$"

Genesis_Text_StatDef:
	.string "Defense$"

Genesis_Text_StatSpeed:
	.string "Speed$"

Genesis_Text_StatSpAtk:
	.string "Sp. Atk$"

Genesis_Text_StatSpDef:
	.string "Sp. Def$"

Genesis_Text_CompetitiveConfirmStat:
	.string "Hyper Train {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "One BOTTLE CAP will be used.$"

Genesis_Text_CompetitiveTrainDone:
	.string "{STR_VAR_1}'s {STR_VAR_2} was Hyper Trained!$"

Genesis_Text_CompetitiveCantStat:
	.string "That stat is already maximized.\n"
	.string "Pick another.$"

Genesis_Text_CompetitiveConfirmGold:
	.string "Fully Hyper Train {STR_VAR_1}?\n"
	.string "One GOLD BOTTLE CAP will be used.$"

Genesis_Text_CompetitiveGoldDone:
	.string "{STR_VAR_1} finished full Hyper Training!$"

Genesis_Text_CompetitiveNoBottleCap:
	.string "You need a BOTTLE CAP.\n"
	.string "Buy one from Buy supplies.$"

Genesis_Text_CompetitiveNoGoldCap:
	.string "You need a GOLD BOTTLE CAP.\n"
	.string "Buy one from Buy supplies.$"

Genesis_Text_CompetitiveCantEgg:
	.string "An EGG can't be Hyper Trained.$"

Genesis_Text_CompetitiveAlreadyPerfect:
	.string "{STR_VAR_1} has nothing left to Hyper Train.$"
