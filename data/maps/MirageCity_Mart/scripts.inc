MirageCity_Mart_MapScripts::
	.byte 0

MirageCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MirageCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MirageCity_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	pokemartlistend

MirageCity_Mart_EventScript_Woman::
	msgbox MirageCity_Mart_Text_PsychicSupplies, MSGBOX_NPC
	end

MirageCity_Mart_EventScript_Boy::
	msgbox MirageCity_Mart_Text_ExpensiveBalls, MSGBOX_NPC
	end

MirageCity_Mart_Text_PsychicSupplies:
	.string "IRIS's trainers stock up on FULL HEALS.\n"
	.string "Confusion and sleep are no joke\l"
	.string "against a PSYCHIC team.$"

MirageCity_Mart_Text_ExpensiveBalls:
	.string "MIRAGE MART carries ULTRA BALLS!\n"
	.string "Eastern AURELIA's wild POKéMON are\l"
	.string "tougher to catch.$"
