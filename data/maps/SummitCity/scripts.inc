@ SUMMIT CITY -- Rock / MENTOR / Badge 16. Layout-clone stub (LAYOUT_RUSTBORO_CITY).
@ Entered from the Eastern AURELIA HALL Summit desk; the Transit Attendant warps back.

SummitCity_MapScripts::
	.byte 0

SummitCity_EventScript_TownSign::
	msgbox SummitCity_Text_TownSign, MSGBOX_SIGN
	end

SummitCity_EventScript_GymSign::
	msgbox SummitCity_Text_GymSign, MSGBOX_SIGN
	end

@ Town totem quest (SUMMIT) -- unlocks once MENTOR has granted the ASCENSION BADGE
SummitCity_EventScript_Girl::
	goto_if_set FLAG_GENESIS_BADGE_16_GET, Genesis_EventScript_TownMon_Summit
	lock
	faceplayer
	msgbox SummitCity_Text_GirlNoBadge, MSGBOX_DEFAULT
	release
	end

SummitCity_EventScript_TransitAttendant::
	lock
	faceplayer
	msgbox SummitCity_Text_AttendantAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SummitCity_EventScript_AttendantStay
	msgbox SummitCity_Text_AttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 1, 6
	waitstate
	release
	end

SummitCity_EventScript_AttendantStay::
	msgbox SummitCity_Text_AttendantStay, MSGBOX_DEFAULT
	release
	end

SummitCity_Text_TownSign:
	.string "SUMMIT CITY\n"
	.string "“Stone remembers every ascent.”$"

SummitCity_Text_GymSign:
	.string "SUMMIT CITY POKéMON GYM\n"
	.string "LEADER: MENTOR\l"
	.string "“Build on bedrock.”$"

SummitCity_Text_GirlNoBadge:
	.string "The MENTOR guards the eastern peak\nwith ROCK POKéMON.\pBeat him at the GYM first.\nThen ask me about the armored\lmountain that woke below.$"

SummitCity_Text_AttendantAsk:
	.string "EASTERN AURELIA transit desk.\nReturn to the EASTERN AURELIA HALL?$"

SummitCity_Text_AttendantWarp:
	.string "The cliff-lift grinds upward…\nHold fast.$"

SummitCity_Text_AttendantStay:
	.string "Take your time in SUMMIT CITY.\nThe cliff-lift will wait.$"
