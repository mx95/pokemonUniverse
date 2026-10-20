EonCity_MapScripts::
	.byte 0

EonCity_EventScript_Girl::
	msgbox EonCity_Text_Girl, MSGBOX_NPC
	end

EonCity_EventScript_ExpertM::
	msgbox EonCity_Text_ExpertM, MSGBOX_NPC
	end

EonCity_EventScript_Gentleman::
	msgbox EonCity_Text_Gentleman, MSGBOX_NPC
	end

EonCity_EventScript_HallAttendant::
	lock
	faceplayer
	msgbox EonCity_Text_HallAttendant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EonCity_EventScript_HallAttendantStay
	msgbox EonCity_Text_HallAttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 2, 6
	waitstate
	release
	end

EonCity_EventScript_HallAttendantStay::
	msgbox EonCity_Text_HallAttendantStay, MSGBOX_DEFAULT
	release
	end

EonCity_EventScript_CitySign::
	msgbox EonCity_Text_CitySign, MSGBOX_SIGN
	end

EonCity_EventScript_GymSign::
	msgbox EonCity_Text_GymSign, MSGBOX_SIGN
	end

EonCity_EventScript_TeleportSign::
	msgbox EonCity_Text_TeleportSign, MSGBOX_SIGN
	end

EonCity_Text_Girl:
	.string "Welcome to EON CITY!\n"
	.string "The Hall teleport net hums nearby.$"

EonCity_Text_ExpertM:
	.string "MORRIGAN keeps the GHOST GYM honest.\n"
	.string "Challenge the GYM when you're ready.$"

EonCity_Text_Gentleman:
	.string "Eastern Aurelia Hall links the cities.\n"
	.string "Our attendant can send you back.$"

EonCity_Text_HallAttendant:
	.string "Return to EASTERN AURELIA HALL?$"

EonCity_Text_HallAttendantWarp:
	.string "Safe travels through the net.$"

EonCity_Text_HallAttendantStay:
	.string "Explore at your own pace.$"

EonCity_Text_CitySign:
	.string "EON CITY\n"
	.string "“Where spirits linger between eras.”$"

EonCity_Text_GymSign:
	.string "EON CITY POKéMON GYM\n"
	.string "LEADER: MORRIGAN\l"
	.string "“The GHOST trial!”$"

EonCity_Text_TeleportSign:
	.string "EON CITY TELEPORT NET\n"
	.string "Gateways link Hall and city.$"
