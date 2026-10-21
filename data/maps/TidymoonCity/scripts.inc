TidymoonCity_MapScripts::
	.byte 0

TidymoonCity_EventScript_Girl::
	msgbox TidymoonCity_Text_Girl, MSGBOX_NPC
	end

TidymoonCity_EventScript_ExpertM::
	msgbox TidymoonCity_Text_ExpertM, MSGBOX_NPC
	end

TidymoonCity_EventScript_Gentleman::
	msgbox TidymoonCity_Text_Gentleman, MSGBOX_NPC
	end

TidymoonCity_EventScript_HallAttendant::
	lock
	faceplayer
	msgbox TidymoonCity_Text_HallAttendant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TidymoonCity_EventScript_HallAttendantStay
	msgbox TidymoonCity_Text_HallAttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 2, 6
	waitstate
	release
	end

TidymoonCity_EventScript_HallAttendantStay::
	msgbox TidymoonCity_Text_HallAttendantStay, MSGBOX_DEFAULT
	release
	end

TidymoonCity_EventScript_CitySign::
	msgbox TidymoonCity_Text_CitySign, MSGBOX_SIGN
	end

TidymoonCity_EventScript_GymSign::
	msgbox TidymoonCity_Text_GymSign, MSGBOX_SIGN
	end

TidymoonCity_EventScript_TeleportSign::
	msgbox TidymoonCity_Text_TeleportSign, MSGBOX_SIGN
	end

TidymoonCity_Text_Girl:
	.string "Welcome to TIDYMOON CITY!\n"
	.string "The Hall teleport net hums nearby.$"

TidymoonCity_Text_ExpertM:
	.string "LUNA keeps the FAIRY GYM honest.\n"
	.string "Challenge the GYM when you're ready.$"

TidymoonCity_Text_Gentleman:
	.string "Eastern Aurelia Hall links the cities.\n"
	.string "Our attendant can send you back.$"

TidymoonCity_Text_HallAttendant:
	.string "Return to EASTERN AURELIA HALL?$"

TidymoonCity_Text_HallAttendantWarp:
	.string "Safe travels through the net.$"

TidymoonCity_Text_HallAttendantStay:
	.string "Explore at your own pace.$"

TidymoonCity_Text_CitySign:
	.string "TIDYMOON CITY\n"
	.string "“Tide pools under soft light.”$"

TidymoonCity_Text_GymSign:
	.string "TIDYMOON CITY POKéMON GYM\n"
	.string "LEADER: LUNA\l"
	.string "“The FAIRY trial!”$"

TidymoonCity_Text_TeleportSign:
	.string "TIDYMOON CITY TELEPORT NET\n"
	.string "Gateways link Hall and city.$"
