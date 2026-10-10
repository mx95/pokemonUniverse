@ ASTRAL CITY -- Dragon / DRAKE / Badge 12. Layout-clone stub (LAYOUT_SLATEPORT_CITY).
@ Entered from the Eastern AURELIA HALL Astral desk; the Transit Attendant warps back.

AstralCity_MapScripts::
	.byte 0

AstralCity_EventScript_TownSign::
	msgbox AstralCity_Text_TownSign, MSGBOX_SIGN
	end

AstralCity_EventScript_GymSign::
	msgbox AstralCity_Text_GymSign, MSGBOX_SIGN
	end

@ Town totem quest (ASTRAL) -- unlocks once DRAKE has granted the ASTRAL BADGE
AstralCity_EventScript_Girl::
	goto_if_set FLAG_GENESIS_BADGE_12_GET, Genesis_EventScript_TownMon_Astral
	lock
	faceplayer
	msgbox AstralCity_Text_GirlNoBadge, MSGBOX_DEFAULT
	release
	end

AstralCity_EventScript_TransitAttendant::
	lock
	faceplayer
	msgbox AstralCity_Text_AttendantAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, AstralCity_EventScript_AttendantStay
	msgbox AstralCity_Text_AttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 1, 6
	waitstate
	release
	end

AstralCity_EventScript_AttendantStay::
	msgbox AstralCity_Text_AttendantStay, MSGBOX_DEFAULT
	release
	end

AstralCity_Text_TownSign:
	.string "ASTRAL CITY\n"
	.string "“Where the stars land first.”$"

AstralCity_Text_GymSign:
	.string "ASTRAL CITY POKéMON GYM\n"
	.string "LEADER: DRAKE\l"
	.string "“Aim higher than the sky.”$"

AstralCity_Text_GirlNoBadge:
	.string "DRAKE charts the sky with his DRAGONS.\pBeat him at the GYM first.\nThen ask me about the DRAGON that\lferries storm-lost ships.$"

AstralCity_Text_AttendantAsk:
	.string "EASTERN AURELIA transit desk.\nReturn to the EASTERN AURELIA HALL?$"

AstralCity_Text_AttendantWarp:
	.string "The star-lift hums…\nRise toward the aurora.$"

AstralCity_Text_AttendantStay:
	.string "Take your time in ASTRAL CITY.\nThe star-lift will wait.$"
