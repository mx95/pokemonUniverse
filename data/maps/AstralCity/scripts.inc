AstralCity_MapScripts::
	.byte 0

AstralCity_EventScript_Girl::
	msgbox AstralCity_Text_Girl, MSGBOX_NPC
	end

AstralCity_EventScript_ExpertM::
	msgbox AstralCity_Text_ExpertM, MSGBOX_NPC
	end

AstralCity_EventScript_Gentleman::
	msgbox AstralCity_Text_Gentleman, MSGBOX_NPC
	end

AstralCity_EventScript_HallAttendant::
	lock
	faceplayer
	msgbox AstralCity_Text_HallAttendant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, AstralCity_EventScript_HallAttendantStay
	msgbox AstralCity_Text_HallAttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 2, 6
	waitstate
	release
	end

AstralCity_EventScript_HallAttendantStay::
	msgbox AstralCity_Text_HallAttendantStay, MSGBOX_DEFAULT
	release
	end

AstralCity_EventScript_CitySign::
	msgbox AstralCity_Text_CitySign, MSGBOX_SIGN
	end

AstralCity_EventScript_GymSign::
	msgbox AstralCity_Text_GymSign, MSGBOX_SIGN
	end

AstralCity_EventScript_TeleportSign::
	msgbox AstralCity_Text_TeleportSign, MSGBOX_SIGN
	end

AstralCity_Text_Girl:
	.string "Welcome to ASTRAL CITY!\n"
	.string "The Hall teleport net hums nearby.$"

AstralCity_Text_ExpertM:
	.string "DRAKE keeps the DRAGON GYM honest.\n"
	.string "Challenge the GYM when you're ready.$"

AstralCity_Text_Gentleman:
	.string "Eastern Aurelia Hall links the cities.\n"
	.string "Our attendant can send you back.$"

AstralCity_Text_HallAttendant:
	.string "Return to EASTERN AURELIA HALL?$"

AstralCity_Text_HallAttendantWarp:
	.string "Safe travels through the net.$"

AstralCity_Text_HallAttendantStay:
	.string "Explore at your own pace.$"

AstralCity_Text_CitySign:
	.string "ASTRAL CITY\n"
	.string "“Where dragons chart the sky.”$"

AstralCity_Text_GymSign:
	.string "ASTRAL CITY POKéMON GYM\n"
	.string "LEADER: DRAKE\l"
	.string "“The DRAGON trial!”$"

AstralCity_Text_TeleportSign:
	.string "ASTRAL CITY TELEPORT NET\n"
	.string "Gateways link Hall and city.$"
