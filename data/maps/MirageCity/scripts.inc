@ MIRAGE CITY -- Psychic / IRIS / Badge 9. Layout-clone stub of LUMEN CITY (LAYOUT_OLDALE_TOWN).
@ Entered from the Eastern AURELIA HALL Mirage desk; the Transit Attendant warps back.

MirageCity_MapScripts::
	.byte 0

MirageCity_EventScript_TownSign::
	msgbox MirageCity_Text_TownSign, MSGBOX_SIGN
	end

MirageCity_EventScript_GymSign::
	msgbox MirageCity_Text_GymSign, MSGBOX_SIGN
	end

@ Town totem quest (GARDEVOIR) -- unlocks once IRIS has granted the MIRAGE BADGE
MirageCity_EventScript_Girl::
	goto_if_set FLAG_GENESIS_BADGE_09_GET, Genesis_EventScript_TownMon_Mirage
	lock
	faceplayer
	msgbox MirageCity_Text_GirlNoBadge, MSGBOX_DEFAULT
	release
	end

MirageCity_EventScript_TransitAttendant::
	lock
	faceplayer
	msgbox MirageCity_Text_AttendantAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageCity_EventScript_AttendantStay
	msgbox MirageCity_Text_AttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 1, 6
	waitstate
	release
	end

MirageCity_EventScript_AttendantStay::
	msgbox MirageCity_Text_AttendantStay, MSGBOX_DEFAULT
	release
	end

MirageCity_Text_TownSign:
	.string "MIRAGE CITY\n"
	.string "“Thought bends like heat-haze glass.”$"

MirageCity_Text_GymSign:
	.string "MIRAGE CITY POKéMON GYM\n"
	.string "LEADER: IRIS\l"
	.string "“See through the veil.”$"

MirageCity_Text_GirlNoBadge:
	.string "IRIS reads minds as easily as maps.\p"
	.string "Beat her at the GYM first.\n"
	.string "Then ask me about the mirage that\l"
	.string "keeps whispering around town.$"

MirageCity_Text_AttendantAsk:
	.string "EASTERN AURELIA transit desk.\n"
	.string "Return to the EASTERN AURELIA HALL?$"

MirageCity_Text_AttendantWarp:
	.string "Hold still--the teleport net will\n"
	.string "fold you home.$"

MirageCity_Text_AttendantStay:
	.string "Take your time in MIRAGE CITY.\n"
	.string "The net will wait.$"
