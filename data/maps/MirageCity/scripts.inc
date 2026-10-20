MirageCity_MapScripts::
	.byte 0

MirageCity_EventScript_Girl::
	msgbox MirageCity_Text_Girl, MSGBOX_NPC
	end

MirageCity_EventScript_ExpertM::
	msgbox MirageCity_Text_ExpertM, MSGBOX_NPC
	end

MirageCity_EventScript_Gentleman::
	msgbox MirageCity_Text_Gentleman, MSGBOX_NPC
	end

MirageCity_EventScript_HallAttendant::
	lock
	faceplayer
	msgbox MirageCity_Text_HallAttendant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageCity_EventScript_HallAttendantStay
	msgbox MirageCity_Text_HallAttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 2, 6
	waitstate
	release
	end

MirageCity_EventScript_HallAttendantStay::
	msgbox MirageCity_Text_HallAttendantStay, MSGBOX_DEFAULT
	release
	end

MirageCity_EventScript_CitySign::
	msgbox MirageCity_Text_CitySign, MSGBOX_SIGN
	end

MirageCity_EventScript_GymSign::
	msgbox MirageCity_Text_GymSign, MSGBOX_SIGN
	end

MirageCity_EventScript_TeleportSign::
	msgbox MirageCity_Text_TeleportSign, MSGBOX_SIGN
	end

MirageCity_Text_Girl:
	.string "The streets shimmer when the sun hits\n"
	.string "just right. Don't trust every doorway!$"

MirageCity_Text_ExpertM:
	.string "IRIS keeps Mirage's illusions honest.\n"
	.string "Challenge her GYM when you're ready.$"

MirageCity_Text_Gentleman:
	.string "Eastern Aurelia Hall links the eastern\n"
	.string "cities. Our attendant can send you back.$"

MirageCity_Text_HallAttendant:
	.string "Return to EASTERN AURELIA HALL?$"

MirageCity_Text_HallAttendantWarp:
	.string "Safe travels through the veil.$"

MirageCity_Text_HallAttendantStay:
	.string "Explore at your own pace.$"

MirageCity_Text_CitySign:
	.string "MIRAGE CITY\n"
	.string "“Where sight and truth diverge.”$"

MirageCity_Text_GymSign:
	.string "MIRAGE CITY POKéMON GYM\n"
	.string "LEADER: IRIS\l"
	.string "“The Psychic Veil!”$"

MirageCity_Text_TeleportSign:
	.string "MIRAGE TELEPORT NET\n"
	.string "Gateways link Hall and city.$"
