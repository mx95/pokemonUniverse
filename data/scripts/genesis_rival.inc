@ GENESIS: Rival Kai story beats (no new trainer IDs)

Genesis_Rival_EventScript_AfterAct2::
	goto_if_set FLAG_GENESIS_RIVAL_BEAT_ACT2, Common_EventScript_NopReturn
	setflag FLAG_GENESIS_RIVAL_BEAT_ACT2
	msgbox Genesis_Rival_Text_AfterAct2, MSGBOX_DEFAULT
	return

Genesis_Rival_EventScript_AfterSeafloor::
	goto_if_set FLAG_GENESIS_RIVAL_BEAT_SEAFLOOR, Common_EventScript_NopReturn
	setflag FLAG_GENESIS_RIVAL_BEAT_SEAFLOOR
	msgbox Genesis_Rival_Text_AfterSeafloor, MSGBOX_DEFAULT
	return

Genesis_Rival_EventScript_BeforeLeague::
	goto_if_set FLAG_GENESIS_RIVAL_BEAT_LEAGUE, Common_EventScript_NopReturn
	setflag FLAG_GENESIS_RIVAL_BEAT_LEAGUE
	msgbox Genesis_Rival_Text_BeforeLeague, MSGBOX_DEFAULT
	return

Genesis_Rival_Text_AfterAct2:
	.string "…A call from KAI!\p"
	.string "KAI: {PLAYER}! I heard TEAM ECLIPSE\n"
	.string "hit the museum.\p"
	.string "I'm researching GENESIS ENERGY too--\n"
	.string "let's not race each other into danger.\l"
	.string "We can share what we learn!\p"
	.string "…Click!$"

Genesis_Rival_Text_AfterSeafloor:
	.string "…KAI's voice crackles through!\p"
	.string "KAI: You faced CAELUM under the sea?!\n"
	.string "I… I should have been there.\p"
	.string "From now on we work together.\n"
	.string "AURELIA needs both of us!\p"
	.string "…Click!$"

Genesis_Rival_Text_BeforeLeague:
	.string "KAI: {PLAYER}!\p"
	.string "Before you walk into the LEAGUE…\n"
	.string "thanks. You showed me rivalry isn't\l"
	.string "about winning alone.\p"
	.string "Go become CHAMPION--I'll cheer from\n"
	.string "the stands, partner!$"
