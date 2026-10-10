GenesisCity_Mart_MapScripts::
	.byte 0

GenesisCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart GenesisCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
GenesisCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

GenesisCity_Mart_EventScript_Woman::
	msgbox GenesisCity_Mart_Text_TypeSupplies, MSGBOX_NPC
	end

GenesisCity_Mart_EventScript_Boy::
	msgbox GenesisCity_Mart_Text_ExpensiveBalls, MSGBOX_NPC
	end

GenesisCity_Mart_Text_TypeSupplies:
	.string "The COLLEAGUE's trainers stock up on\nMAX POTIONS and FULL HEALS.\lAdaptability is our creed.$"

GenesisCity_Mart_Text_ExpensiveBalls:
	.string "GENESIS MART carries ULTRA BALLS!\nEastern AURELIA's wild POKéMON are\ltougher to catch.$"
