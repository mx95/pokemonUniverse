GenesisCity_MapScripts::
	.byte 0

GenesisCity_EventScript_Girl::
	msgbox GenesisCity_Text_Girl, MSGBOX_NPC
	end

GenesisCity_EventScript_ExpertM::
	msgbox GenesisCity_Text_ExpertM, MSGBOX_NPC
	end

GenesisCity_EventScript_Gentleman::
	msgbox GenesisCity_Text_Gentleman, MSGBOX_NPC
	end

GenesisCity_EventScript_HallAttendant::
	lock
	faceplayer
	msgbox GenesisCity_Text_HallAttendant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GenesisCity_EventScript_HallAttendantStay
	msgbox GenesisCity_Text_HallAttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 2, 6
	waitstate
	release
	end

GenesisCity_EventScript_HallAttendantStay::
	msgbox GenesisCity_Text_HallAttendantStay, MSGBOX_DEFAULT
	release
	end

GenesisCity_EventScript_CitySign::
	msgbox GenesisCity_Text_CitySign, MSGBOX_SIGN
	end

GenesisCity_EventScript_GymSign::
	msgbox GenesisCity_Text_GymSign, MSGBOX_SIGN
	end

GenesisCity_EventScript_TeleportSign::
	msgbox GenesisCity_Text_TeleportSign, MSGBOX_SIGN
	end

GenesisCity_Text_Girl:
	.string "Welcome to GENESIS CITY!\n"
	.string "The Hall teleport net hums nearby.$"

GenesisCity_Text_ExpertM:
	.string "COLLEAGUE keeps the MIXED GYM honest.\n"
	.string "Challenge the GYM when you're ready.$"

GenesisCity_Text_Gentleman:
	.string "Eastern Aurelia Hall links the cities.\n"
	.string "Our attendant can send you back.$"

GenesisCity_Text_HallAttendant:
	.string "Return to EASTERN AURELIA HALL?$"

GenesisCity_Text_HallAttendantWarp:
	.string "Safe travels through the net.$"

GenesisCity_Text_HallAttendantStay:
	.string "Explore at your own pace.$"

GenesisCity_Text_CitySign:
	.string "GENESIS CITY\n"
	.string "“Prep hub of Eastern Aurelia.”$"

GenesisCity_Text_GymSign:
	.string "GENESIS CITY POKéMON GYM\n"
	.string "LEADER: COLLEAGUE\l"
	.string "“The MIXED trial!”$"

GenesisCity_Text_TeleportSign:
	.string "GENESIS CITY TELEPORT NET\n"
	.string "Gateways link Hall and city.$"
