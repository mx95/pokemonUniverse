@ GENESIS CITY -- Normal / COLLEAGUE / Badge 15. Layout-clone stub (LAYOUT_PETALBURG_CITY).
@ Entered from the Eastern AURELIA HALL GenesisCity desk; the Transit Attendant warps back.

GenesisCity_MapScripts::
	.byte 0

GenesisCity_EventScript_TownSign::
	msgbox GenesisCity_Text_TownSign, MSGBOX_SIGN
	end

GenesisCity_EventScript_GymSign::
	msgbox GenesisCity_Text_GymSign, MSGBOX_SIGN
	end

@ Town totem quest (GENESISCITY) -- unlocks once COLLEAGUE has granted the GENESIS BADGE
GenesisCity_EventScript_Girl::
	goto_if_set FLAG_GENESIS_BADGE_15_GET, Genesis_EventScript_TownMon_GenesisCity
	lock
	faceplayer
	msgbox GenesisCity_Text_GirlNoBadge, MSGBOX_DEFAULT
	release
	end

GenesisCity_EventScript_TransitAttendant::
	lock
	faceplayer
	msgbox GenesisCity_Text_AttendantAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, GenesisCity_EventScript_AttendantStay
	msgbox GenesisCity_Text_AttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 1, 6
	waitstate
	release
	end

GenesisCity_EventScript_AttendantStay::
	msgbox GenesisCity_Text_AttendantStay, MSGBOX_DEFAULT
	release
	end

GenesisCity_Text_TownSign:
	.string "GENESIS CITY\n"
	.string "“Potential is measured in battle.”$"

GenesisCity_Text_GymSign:
	.string "GENESIS CITY POKéMON GYM\n"
	.string "LEADER: COLLEAGUE\l"
	.string "“Adapt. Prepare. Prevail.”$"

GenesisCity_Text_GirlNoBadge:
	.string "The COLLEAGUE favors NORMAL types--\nplain, but never simple.\pBeat them at the GYM first.\nThen ask me about the lazy giant in\lthe training yards.$"

GenesisCity_Text_AttendantAsk:
	.string "EASTERN AURELIA transit desk.\nReturn to the EASTERN AURELIA HALL?$"

GenesisCity_Text_AttendantWarp:
	.string "The hub shuttle spins up…\nMind the gap.$"

GenesisCity_Text_AttendantStay:
	.string "Take your time in GENESIS CITY.\nThe hub shuttle will wait.$"
