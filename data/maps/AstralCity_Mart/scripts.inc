AstralCity_Mart_MapScripts::
	.byte 0

AstralCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart AstralCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
AstralCity_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

AstralCity_Mart_EventScript_Woman::
	msgbox AstralCity_Mart_Text_TypeSupplies, MSGBOX_NPC
	end

AstralCity_Mart_EventScript_Boy::
	msgbox AstralCity_Mart_Text_ExpensiveBalls, MSGBOX_NPC
	end

AstralCity_Mart_Text_TypeSupplies:
	.string "DRAKE's trainers stock up on\nFULL HEALS and REVIVES.\lDragon tails hit hard.$"

AstralCity_Mart_Text_ExpensiveBalls:
	.string "ASTRAL MART carries ULTRA BALLS!\nEastern AURELIA's wild POKéMON are\ltougher to catch.$"
