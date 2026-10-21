VerdantisCity_MapScripts::
	.byte 0

VerdantisCity_EventScript_Girl::
	msgbox VerdantisCity_Text_Girl, MSGBOX_NPC
	end

VerdantisCity_EventScript_ExpertM::
	msgbox VerdantisCity_Text_ExpertM, MSGBOX_NPC
	end

VerdantisCity_EventScript_Gentleman::
	msgbox VerdantisCity_Text_Gentleman, MSGBOX_NPC
	end

VerdantisCity_EventScript_HallAttendant::
	lock
	faceplayer
	msgbox VerdantisCity_Text_HallAttendant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VerdantisCity_EventScript_HallAttendantStay
	msgbox VerdantisCity_Text_HallAttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 2, 6
	waitstate
	release
	end

VerdantisCity_EventScript_HallAttendantStay::
	msgbox VerdantisCity_Text_HallAttendantStay, MSGBOX_DEFAULT
	release
	end

VerdantisCity_EventScript_CitySign::
	msgbox VerdantisCity_Text_CitySign, MSGBOX_SIGN
	end

VerdantisCity_EventScript_GymSign::
	msgbox VerdantisCity_Text_GymSign, MSGBOX_SIGN
	end

VerdantisCity_EventScript_TeleportSign::
	msgbox VerdantisCity_Text_TeleportSign, MSGBOX_SIGN
	end

VerdantisCity_Text_Girl:
	.string "Welcome to VERDANTIS CITY!\n"
	.string "The Hall teleport net hums nearby.$"

VerdantisCity_Text_ExpertM:
	.string "CELIA keeps the BUG GYM honest.\n"
	.string "Challenge the GYM when you're ready.$"

VerdantisCity_Text_Gentleman:
	.string "Eastern Aurelia Hall links the cities.\n"
	.string "Our attendant can send you back.$"

VerdantisCity_Text_HallAttendant:
	.string "Return to EASTERN AURELIA HALL?$"

VerdantisCity_Text_HallAttendantWarp:
	.string "Safe travels through the net.$"

VerdantisCity_Text_HallAttendantStay:
	.string "Explore at your own pace.$"

VerdantisCity_Text_CitySign:
	.string "VERDANTIS CITY\n"
	.string "“Canopy and buzz.”$"

VerdantisCity_Text_GymSign:
	.string "VERDANTIS CITY POKéMON GYM\n"
	.string "LEADER: CELIA\l"
	.string "“The BUG trial!”$"

VerdantisCity_Text_TeleportSign:
	.string "VERDANTIS CITY TELEPORT NET\n"
	.string "Gateways link Hall and city.$"
