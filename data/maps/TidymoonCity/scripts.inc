@ TIDYMOON CITY -- Fairy / LUNA / Badge 13. Layout-clone stub (LAYOUT_MOSSDEEP_CITY).
@ Entered from the Eastern AURELIA HALL Tidymoon desk; the Transit Attendant warps back.

TidymoonCity_MapScripts::
	.byte 0

TidymoonCity_EventScript_TownSign::
	msgbox TidymoonCity_Text_TownSign, MSGBOX_SIGN
	end

TidymoonCity_EventScript_GymSign::
	msgbox TidymoonCity_Text_GymSign, MSGBOX_SIGN
	end

@ Town totem quest (TIDYMOON) -- unlocks once LUNA has granted the MOON BADGE
TidymoonCity_EventScript_Girl::
	goto_if_set FLAG_GENESIS_BADGE_13_GET, Genesis_EventScript_TownMon_Tidymoon
	lock
	faceplayer
	msgbox TidymoonCity_Text_GirlNoBadge, MSGBOX_DEFAULT
	release
	end

TidymoonCity_EventScript_TransitAttendant::
	lock
	faceplayer
	msgbox TidymoonCity_Text_AttendantAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TidymoonCity_EventScript_AttendantStay
	msgbox TidymoonCity_Text_AttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 1, 6
	waitstate
	release
	end

TidymoonCity_EventScript_AttendantStay::
	msgbox TidymoonCity_Text_AttendantStay, MSGBOX_DEFAULT
	release
	end

TidymoonCity_Text_TownSign:
	.string "TIDYMOON CITY\n"
	.string "“Wishes float in on the tide.”$"

TidymoonCity_Text_GymSign:
	.string "TIDYMOON CITY POKéMON GYM\n"
	.string "LEADER: LUNA\l"
	.string "“Soft power still wins wars.”$"

TidymoonCity_Text_GirlNoBadge:
	.string "LUNA dances with FAIRY POKéMON\nunder the moon.\pBeat her at the GYM first.\nThen ask me about the jubilee that\lblesses kind hearts.$"

TidymoonCity_Text_AttendantAsk:
	.string "EASTERN AURELIA transit desk.\nReturn to the EASTERN AURELIA HALL?$"

TidymoonCity_Text_AttendantWarp:
	.string "The moon-ferry glides in…\nStep aboard.$"

TidymoonCity_Text_AttendantStay:
	.string "Take your time in TIDYMOON CITY.\nThe moon-ferry will wait.$"
