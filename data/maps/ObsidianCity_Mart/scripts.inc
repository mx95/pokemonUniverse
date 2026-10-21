ObsidianCity_Mart_MapScripts::
	.byte 0

ObsidianCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart ObsidianCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
ObsidianCity_Mart_Pokemart:
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

ObsidianCity_Mart_EventScript_Woman::
	msgbox ObsidianCity_Mart_Text_Woman, MSGBOX_NPC
	end

ObsidianCity_Mart_EventScript_PokefanM::
	msgbox ObsidianCity_Mart_Text_PokefanM, MSGBOX_NPC
	end

ObsidianCity_Mart_Text_Woman:
	.string "Stock up before NOCTIS.\n"
	.string "DARK pressure hits hard.$"

ObsidianCity_Mart_Text_PokefanM:
	.string "Escape Ropes are a habit of mine.\n"
	.string "Eastern caves can surprise you.$"
