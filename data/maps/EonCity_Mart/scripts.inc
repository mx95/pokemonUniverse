EonCity_Mart_MapScripts::
	.byte 0

EonCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EonCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EonCity_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

EonCity_Mart_EventScript_Woman::
	msgbox EonCity_Mart_Text_TypeSupplies, MSGBOX_NPC
	end

EonCity_Mart_EventScript_Boy::
	msgbox EonCity_Mart_Text_ExpensiveBalls, MSGBOX_NPC
	end

EonCity_Mart_Text_TypeSupplies:
	.string "MORRIGAN's trainers stock up on\nHYPER POTIONS and ULTRA BALLS.\lSpirits slip away fast.$"

EonCity_Mart_Text_ExpensiveBalls:
	.string "EON MART carries ULTRA BALLS!\nEastern AURELIA's wild POKéMON are\ltougher to catch.$"
