VenomHollow_Mart_MapScripts::
	.byte 0

VenomHollow_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VenomHollow_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VenomHollow_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

VenomHollow_Mart_EventScript_Woman::
	msgbox VenomHollow_Mart_Text_TypeSupplies, MSGBOX_NPC
	end

VenomHollow_Mart_EventScript_Boy::
	msgbox VenomHollow_Mart_Text_ExpensiveBalls, MSGBOX_NPC
	end

VenomHollow_Mart_Text_TypeSupplies:
	.string "VESPER's trainers stock up on\nANTIDOTES and FULL HEALS.\lEveryone leaves here immune.$"

VenomHollow_Mart_Text_ExpensiveBalls:
	.string "VENOM HOLLOW MART carries ULTRA BALLS!\nEastern AURELIA's wild POKéMON are\ltougher to catch.$"
