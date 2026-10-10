@ TERRACOTTA MESA -- Ground / TERRA / Badge 18. Layout-clone stub (LAYOUT_VERDANTURF_TOWN).
@ Entered from the Eastern AURELIA HALL Terracotta desk; the Transit Attendant warps back.

TerracottaMesa_MapScripts::
	.byte 0

TerracottaMesa_EventScript_TownSign::
	msgbox TerracottaMesa_Text_TownSign, MSGBOX_SIGN
	end

TerracottaMesa_EventScript_GymSign::
	msgbox TerracottaMesa_Text_GymSign, MSGBOX_SIGN
	end

@ Town totem quest (TERRACOTTA) -- unlocks once TERRA has granted the TERRA BADGE
TerracottaMesa_EventScript_Girl::
	goto_if_set FLAG_GENESIS_BADGE_18_GET, Genesis_EventScript_TownMon_Terracotta
	lock
	faceplayer
	msgbox TerracottaMesa_Text_GirlNoBadge, MSGBOX_DEFAULT
	release
	end

TerracottaMesa_EventScript_TransitAttendant::
	lock
	faceplayer
	msgbox TerracottaMesa_Text_AttendantAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TerracottaMesa_EventScript_AttendantStay
	msgbox TerracottaMesa_Text_AttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 1, 6
	waitstate
	release
	end

TerracottaMesa_EventScript_AttendantStay::
	msgbox TerracottaMesa_Text_AttendantStay, MSGBOX_DEFAULT
	release
	end

TerracottaMesa_Text_TownSign:
	.string "TERRACOTTA MESA\n"
	.string "“The last type closes the circle.”$"

TerracottaMesa_Text_GymSign:
	.string "TERRACOTTA MESA POKéMON GYM\n"
	.string "LEADER: TERRA\l"
	.string "“Stand firm.”$"

TerracottaMesa_Text_GirlNoBadge:
	.string "TERRA's GROUND POKéMON never yield.\pBeat her at the GYM first.\nThen ask me about the land shark\lthat patrols the mesa dunes.$"

TerracottaMesa_Text_AttendantAsk:
	.string "EASTERN AURELIA transit desk.\nReturn to the EASTERN AURELIA HALL?$"

TerracottaMesa_Text_AttendantWarp:
	.string "The dune-runner kicks up dust…\nHold your hat.$"

TerracottaMesa_Text_AttendantStay:
	.string "Take your time in TERRACOTTA MESA.\nThe dune-runner will wait.$"
