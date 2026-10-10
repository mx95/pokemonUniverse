@ VERDANTIS CITY -- Bug / CELIA / Badge 10. Layout-clone stub (LAYOUT_FORTREE_CITY).
@ Entered from the Eastern AURELIA HALL Verdantis desk; the Transit Attendant warps back.

VerdantisCity_MapScripts::
	.byte 0

VerdantisCity_EventScript_TownSign::
	msgbox VerdantisCity_Text_TownSign, MSGBOX_SIGN
	end

VerdantisCity_EventScript_GymSign::
	msgbox VerdantisCity_Text_GymSign, MSGBOX_SIGN
	end

@ Town totem quest (VOLCARONA) -- unlocks once CELIA has granted the JUNGLE BADGE
VerdantisCity_EventScript_Girl::
	goto_if_set FLAG_GENESIS_BADGE_10_GET, Genesis_EventScript_TownMon_Verdantis
	lock
	faceplayer
	msgbox VerdantisCity_Text_GirlNoBadge, MSGBOX_DEFAULT
	release
	end

VerdantisCity_EventScript_TransitAttendant::
	lock
	faceplayer
	msgbox VerdantisCity_Text_AttendantAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VerdantisCity_EventScript_AttendantStay
	msgbox VerdantisCity_Text_AttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 1, 6
	waitstate
	release
	end

VerdantisCity_EventScript_AttendantStay::
	msgbox VerdantisCity_Text_AttendantStay, MSGBOX_DEFAULT
	release
	end

VerdantisCity_Text_TownSign:
	.string "VERDANTIS CITY\n"
	.string "“Canopy light, a thousand wings.”$"

VerdantisCity_Text_GymSign:
	.string "VERDANTIS CITY POKéMON GYM\n"
	.string "LEADER: CELIA\l"
	.string "“Swarm the canopy.”$"

VerdantisCity_Text_GirlNoBadge:
	.string "CELIA keeps a whole jungle of BUG\nPOKéMON in her GYM.\pBeat her at the GYM first.\nThen ask me about the sun-moth that\lkeeps circling the treetops.$"

VerdantisCity_Text_AttendantAsk:
	.string "EASTERN AURELIA transit desk.\nReturn to the EASTERN AURELIA HALL?$"

VerdantisCity_Text_AttendantWarp:
	.string "The canopy lift hums…\nHold on to the rail.$"

VerdantisCity_Text_AttendantStay:
	.string "Take your time in VERDANTIS CITY.\nThe lift will wait.$"
