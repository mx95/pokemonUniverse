SummitCity_MapScripts::
	.byte 0

SummitCity_EventScript_Girl::
	msgbox SummitCity_Text_Girl, MSGBOX_NPC
	end

SummitCity_EventScript_ExpertM::
	msgbox SummitCity_Text_ExpertM, MSGBOX_NPC
	end

SummitCity_EventScript_Gentleman::
	msgbox SummitCity_Text_Gentleman, MSGBOX_NPC
	end

SummitCity_EventScript_HallAttendant::
	lock
	faceplayer
	msgbox SummitCity_Text_HallAttendant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SummitCity_EventScript_HallAttendantStay
	msgbox SummitCity_Text_HallAttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 2, 6
	waitstate
	release
	end

SummitCity_EventScript_HallAttendantStay::
	msgbox SummitCity_Text_HallAttendantStay, MSGBOX_DEFAULT
	release
	end

SummitCity_EventScript_CitySign::
	msgbox SummitCity_Text_CitySign, MSGBOX_SIGN
	end

SummitCity_EventScript_GymSign::
	msgbox SummitCity_Text_GymSign, MSGBOX_SIGN
	end

SummitCity_EventScript_TeleportSign::
	msgbox SummitCity_Text_TeleportSign, MSGBOX_SIGN
	end

SummitCity_Text_Girl:
	.string "Welcome to AURELIA SUMMIT!\n"
	.string "The Hall teleport net hums nearby.$"

SummitCity_Text_ExpertM:
	.string "MENTOR keeps the MIXED GYM honest.\n"
	.string "Challenge the GYM when you're ready.$"

SummitCity_Text_Gentleman:
	.string "Eastern Aurelia Hall links the cities.\n"
	.string "Our attendant can send you back.$"

SummitCity_Text_HallAttendant:
	.string "Return to EASTERN AURELIA HALL?$"

SummitCity_Text_HallAttendantWarp:
	.string "Safe travels through the net.$"

SummitCity_Text_HallAttendantStay:
	.string "Explore at your own pace.$"

SummitCity_Text_CitySign:
	.string "AURELIA SUMMIT\n"
	.string "“Not a throne. A threshold.”$"

SummitCity_Text_GymSign:
	.string "AURELIA SUMMIT POKéMON GYM\n"
	.string "LEADER: MENTOR\l"
	.string "“The MIXED trial!”$"

SummitCity_Text_TeleportSign:
	.string "AURELIA SUMMIT TELEPORT NET\n"
	.string "Gateways link Hall and city.$"
