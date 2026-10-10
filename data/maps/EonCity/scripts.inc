@ EON CITY -- Ghost / MORRIGAN / Badge 14. Layout-clone stub (LAYOUT_MAUVILLE_CITY).
@ Entered from the Eastern AURELIA HALL Eon desk; the Transit Attendant warps back.

EonCity_MapScripts::
	.byte 0

EonCity_EventScript_TownSign::
	msgbox EonCity_Text_TownSign, MSGBOX_SIGN
	end

EonCity_EventScript_GymSign::
	msgbox EonCity_Text_GymSign, MSGBOX_SIGN
	end

@ Town totem quest (EON) -- unlocks once MORRIGAN has granted the EON BADGE
EonCity_EventScript_Girl::
	goto_if_set FLAG_GENESIS_BADGE_14_GET, Genesis_EventScript_TownMon_Eon
	lock
	faceplayer
	msgbox EonCity_Text_GirlNoBadge, MSGBOX_DEFAULT
	release
	end

EonCity_EventScript_TransitAttendant::
	lock
	faceplayer
	msgbox EonCity_Text_AttendantAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EonCity_EventScript_AttendantStay
	msgbox EonCity_Text_AttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 1, 6
	waitstate
	release
	end

EonCity_EventScript_AttendantStay::
	msgbox EonCity_Text_AttendantStay, MSGBOX_DEFAULT
	release
	end

EonCity_Text_TownSign:
	.string "EON CITY\n"
	.string "“Hear the bells between hours.”$"

EonCity_Text_GymSign:
	.string "EON CITY POKéMON GYM\n"
	.string "LEADER: MORRIGAN\l"
	.string "“Honor what lingers.”$"

EonCity_Text_GirlNoBadge:
	.string "MORRIGAN's GHOSTS drift between eras.\pBeat her at the GYM first.\nThen ask me about the nest in the\lbelfry dark.$"

EonCity_Text_AttendantAsk:
	.string "EASTERN AURELIA transit desk.\nReturn to the EASTERN AURELIA HALL?$"

EonCity_Text_AttendantWarp:
	.string "The echo-gate chimes…\nStep between the hours.$"

EonCity_Text_AttendantStay:
	.string "Take your time in EON CITY.\nThe echo-gate will wait.$"
