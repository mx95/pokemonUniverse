Genesis_Laboratory_MapScripts::
	.byte 0

Genesis_Laboratory_EventScript_Director::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Genesis_Laboratory_EventScript_DirectorEarly
	msgbox Genesis_Laboratory_Text_Director, MSGBOX_DEFAULT
	release
	end

Genesis_Laboratory_EventScript_DirectorEarly::
	msgbox Genesis_Laboratory_Text_DirectorEarly, MSGBOX_DEFAULT
	release
	end

Genesis_Laboratory_EventScript_Aide::
	msgbox Genesis_Laboratory_Text_Aide, MSGBOX_NPC
	end

Genesis_Laboratory_EventScript_Visitor::
	msgbox Genesis_Laboratory_Text_Visitor, MSGBOX_NPC
	end

Genesis_Laboratory_EventScript_Board::
	msgbox Genesis_Laboratory_Text_Board, MSGBOX_SIGN
	end

Genesis_Laboratory_Text_Director:
	.string "DIRECTOR: Welcome to GENESIS LAB.\n"
	.string "We archive Eastern Aurelia's field data.\p"
	.string "Hyper Train and supply shops live in\n"
	.string "LUMEN CITY's Center--Gentleman's desk.\p"
	.string "Legend foci stay in the SANCTUM.\n"
	.string "This wing is for research notes only.$"

Genesis_Laboratory_Text_DirectorEarly:
	.string "DIRECTOR: Return when you are CHAMPION.\n"
	.string "Our archives open with Eastern Aurelia.$"

Genesis_Laboratory_Text_Aide:
	.string "We're correlating MIRAGE through SUMMIT\n"
	.string "badge energy with Genesis Form overlays.$"

Genesis_Laboratory_Text_Visitor:
	.string "I Hyper Trained in Lumen, then came here\n"
	.string "to study Eastern team comps. Ambitious!$"

Genesis_Laboratory_Text_Board:
	.string "GENESIS LABORATORY\n"
	.string "Eastern archive · Champion access$"
