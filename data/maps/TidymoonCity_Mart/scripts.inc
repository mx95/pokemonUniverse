TidymoonCity_Mart_MapScripts::
	.byte 0

TidymoonCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart TidymoonCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TidymoonCity_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

TidymoonCity_Mart_EventScript_Woman::
	msgbox TidymoonCity_Mart_Text_TypeSupplies, MSGBOX_NPC
	end

TidymoonCity_Mart_EventScript_Boy::
	msgbox TidymoonCity_Mart_Text_ExpensiveBalls, MSGBOX_NPC
	end

TidymoonCity_Mart_Text_TypeSupplies:
	.string "LUNA's trainers stock up on\nANTIDOTES and FULL HEALS.\lSteel and poison bite fairies.$"

TidymoonCity_Mart_Text_ExpensiveBalls:
	.string "TIDYMOON MART carries ULTRA BALLS!\nEastern AURELIA's wild POKéMON are\ltougher to catch.$"
