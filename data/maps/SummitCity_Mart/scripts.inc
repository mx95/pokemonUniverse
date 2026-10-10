SummitCity_Mart_MapScripts::
	.byte 0

SummitCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SummitCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SummitCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

SummitCity_Mart_EventScript_Woman::
	msgbox SummitCity_Mart_Text_TypeSupplies, MSGBOX_NPC
	end

SummitCity_Mart_EventScript_Boy::
	msgbox SummitCity_Mart_Text_ExpensiveBalls, MSGBOX_NPC
	end

SummitCity_Mart_Text_TypeSupplies:
	.string "The MENTOR's trainers stock up on\nSUPER REPELS and HYPER POTIONS.\lThe climb is long.$"

SummitCity_Mart_Text_ExpensiveBalls:
	.string "SUMMIT MART carries ULTRA BALLS!\nEastern AURELIA's wild POKéMON are\ltougher to catch.$"
