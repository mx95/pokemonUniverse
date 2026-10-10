TerracottaMesa_Mart_MapScripts::
	.byte 0

TerracottaMesa_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart TerracottaMesa_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TerracottaMesa_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

TerracottaMesa_Mart_EventScript_Woman::
	msgbox TerracottaMesa_Mart_Text_TypeSupplies, MSGBOX_NPC
	end

TerracottaMesa_Mart_EventScript_Boy::
	msgbox TerracottaMesa_Mart_Text_ExpensiveBalls, MSGBOX_NPC
	end

TerracottaMesa_Mart_Text_TypeSupplies:
	.string "TERRA's trainers stock up on\nMAX POTIONS and REVIVES.\lClay dust gets everywhere.$"

TerracottaMesa_Mart_Text_ExpensiveBalls:
	.string "TERRACOTTA MESA MART carries ULTRA BALLS!\nEastern AURELIA's wild POKéMON are\ltougher to catch.$"
