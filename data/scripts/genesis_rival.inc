@ GENESIS: Rival Kai story battles

Genesis_Rival_EventScript_AfterAct2::
	goto_if_set FLAG_GENESIS_RIVAL_BEAT_ACT2, Common_EventScript_NopReturn
	msgbox Genesis_Rival_Text_AfterAct2Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_KAI_ACT2, Genesis_Rival_Text_AfterAct2Defeat
	setflag FLAG_GENESIS_RIVAL_BEAT_ACT2
	msgbox Genesis_Rival_Text_AfterAct2, MSGBOX_DEFAULT
	return

Genesis_Rival_EventScript_AfterSeafloor::
	goto_if_set FLAG_GENESIS_RIVAL_BEAT_SEAFLOOR, Common_EventScript_NopReturn
	msgbox Genesis_Rival_Text_AfterSeafloorIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_KAI_SEAFLOOR, Genesis_Rival_Text_AfterSeafloorDefeat
	setflag FLAG_GENESIS_RIVAL_BEAT_SEAFLOOR
	msgbox Genesis_Rival_Text_AfterSeafloor, MSGBOX_DEFAULT
	return

Genesis_Rival_EventScript_BeforeLeague::
	goto_if_set FLAG_GENESIS_RIVAL_BEAT_LEAGUE, Common_EventScript_NopReturn
	msgbox Genesis_Rival_Text_BeforeLeagueIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_KAI_LEAGUE, Genesis_Rival_Text_BeforeLeagueDefeat
	setflag FLAG_GENESIS_RIVAL_BEAT_LEAGUE
	msgbox Genesis_Rival_Text_BeforeLeague, MSGBOX_DEFAULT
	return

Genesis_Rival_Text_AfterAct2Intro:
	.string "KAI: {PLAYER}!\n"
	.string "I caught up after the museum mess.\p"
	.string "TEAM ECLIPSE is hunting GENESIS ENERGY.\n"
	.string "Show me how far you've come!$"

Genesis_Rival_Text_AfterAct2Defeat:
	.string "You're already sharper than me…$"

Genesis_Rival_Text_AfterAct2:
	.string "KAI: Okay--lesson learned.\n"
	.string "I'll research; you keep pushing ahead.\p"
	.string "Share what you find. AURELIA needs\n"
	.string "both of us, partner!$"

Genesis_Rival_Text_AfterSeafloorIntro:
	.string "KAI: You faced CAELUM under the sea?!\n"
	.string "I should have been there…\p"
	.string "No more sitting on the sidelines.\n"
	.string "Battle me--prove we're ready together!$"

Genesis_Rival_Text_AfterSeafloorDefeat:
	.string "Still a step behind… Fine!$"

Genesis_Rival_Text_AfterSeafloor:
	.string "KAI: From now on we work in tandem.\n"
	.string "You take the front line; I'll cover\l"
	.string "the archives and the science.\p"
	.string "AURELIA needs both of us!$"

Genesis_Rival_Text_BeforeLeagueIntro:
	.string "KAI: {PLAYER}!\p"
	.string "Before you walk into the LEAGUE…\n"
	.string "one last friendly match.\p"
	.string "Show me the Champion you'll become!$"

Genesis_Rival_Text_BeforeLeagueDefeat:
	.string "That's the partner I believe in…$"

Genesis_Rival_Text_BeforeLeague:
	.string "KAI: Thanks. You showed me rivalry\n"
	.string "isn't about winning alone.\p"
	.string "Go become CHAMPION--I'll cheer from\n"
	.string "the stands, partner!$"
