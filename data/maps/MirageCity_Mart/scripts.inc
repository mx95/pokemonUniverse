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
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_DEFENSE
	pokemartlistend

MirageCity_Mart_EventScript_Woman::
	msgbox MirageCity_Mart_Text_Woman, MSGBOX_NPC
	end

MirageCity_Mart_EventScript_PokefanM::
	msgbox MirageCity_Mart_Text_PokefanM, MSGBOX_NPC
	end

MirageCity_Mart_Text_Woman:
	.string "Stock X SP. ATK before IRIS.\n"
	.string "Her team hits hard with special moves.$"

MirageCity_Mart_Text_PokefanM:
	.string "I bought Escape Ropes “just in case.”\n"
	.string "Mirage caves aren't real… I think.$"
