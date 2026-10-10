@ VENOM HOLLOW -- Poison / VESPER / Badge 17. Layout-clone stub (LAYOUT_FALLARBOR_TOWN).
@ Entered from the Eastern AURELIA HALL Venom desk; the Transit Attendant warps back.

VenomHollow_MapScripts::
	.byte 0

VenomHollow_EventScript_TownSign::
	msgbox VenomHollow_Text_TownSign, MSGBOX_SIGN
	end

VenomHollow_EventScript_GymSign::
	msgbox VenomHollow_Text_GymSign, MSGBOX_SIGN
	end

@ Town totem quest (VENOM) -- unlocks once VESPER has granted the VENOM BADGE
VenomHollow_EventScript_Girl::
	goto_if_set FLAG_GENESIS_BADGE_17_GET, Genesis_EventScript_TownMon_Venom
	lock
	faceplayer
	msgbox VenomHollow_Text_GirlNoBadge, MSGBOX_DEFAULT
	release
	end

VenomHollow_EventScript_TransitAttendant::
	lock
	faceplayer
	msgbox VenomHollow_Text_AttendantAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VenomHollow_EventScript_AttendantStay
	msgbox VenomHollow_Text_AttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 1, 6
	waitstate
	release
	end

VenomHollow_EventScript_AttendantStay::
	msgbox VenomHollow_Text_AttendantStay, MSGBOX_DEFAULT
	release
	end

VenomHollow_Text_TownSign:
	.string "VENOM HOLLOW\n"
	.string "“Antidotes sell better than gold.”$"

VenomHollow_Text_GymSign:
	.string "VENOM HOLLOW POKéMON GYM\n"
	.string "LEADER: VESPER\l"
	.string "“Poison is honesty.”$"

VenomHollow_Text_GirlNoBadge:
	.string "VESPER brews POISON like others\npour tea.\pBeat her at the GYM first.\nThen ask me about the trickster\lthat haunts the vapor vents.$"

VenomHollow_Text_AttendantAsk:
	.string "EASTERN AURELIA transit desk.\nReturn to the EASTERN AURELIA HALL?$"

VenomHollow_Text_AttendantWarp:
	.string "The lantern-boat drifts in…\nMind the fumes.$"

VenomHollow_Text_AttendantStay:
	.string "Take your time in VENOM HOLLOW.\nThe lantern-boat will wait.$"
