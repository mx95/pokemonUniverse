@ OBSIDIAN CITY -- Dark / NOCTIS / Badge 11. Layout-clone stub (LAYOUT_LAVARIDGE_TOWN).
@ Entered from the Eastern AURELIA HALL Obsidian desk; the Transit Attendant warps back.

ObsidianCity_MapScripts::
	.byte 0

ObsidianCity_EventScript_TownSign::
	msgbox ObsidianCity_Text_TownSign, MSGBOX_SIGN
	end

ObsidianCity_EventScript_GymSign::
	msgbox ObsidianCity_Text_GymSign, MSGBOX_SIGN
	end

@ Town totem quest (HYDREIGON) -- unlocks once NOCTIS has granted the OBSIDIAN BADGE
ObsidianCity_EventScript_Girl::
	goto_if_set FLAG_GENESIS_BADGE_11_GET, Genesis_EventScript_TownMon_Obsidian
	lock
	faceplayer
	msgbox ObsidianCity_Text_GirlNoBadge, MSGBOX_DEFAULT
	release
	end

ObsidianCity_EventScript_TransitAttendant::
	lock
	faceplayer
	msgbox ObsidianCity_Text_AttendantAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ObsidianCity_EventScript_AttendantStay
	msgbox ObsidianCity_Text_AttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 1, 6
	waitstate
	release
	end

ObsidianCity_EventScript_AttendantStay::
	msgbox ObsidianCity_Text_AttendantStay, MSGBOX_DEFAULT
	release
	end

ObsidianCity_Text_TownSign:
	.string "OBSIDIAN CITY\n"
	.string "“Honest deals prefer the dark.”$"

ObsidianCity_Text_GymSign:
	.string "OBSIDIAN CITY POKéMON GYM\n"
	.string "LEADER: NOCTIS\l"
	.string "“Walk unafraid of your shadow.”$"

ObsidianCity_Text_GirlNoBadge:
	.string "NOCTIS fights in near-total dark.\pBeat him at the GYM first.\nThen ask me about the three-headed\lshadow that haunts the vents.$"

ObsidianCity_Text_AttendantAsk:
	.string "EASTERN AURELIA transit desk.\nReturn to the EASTERN AURELIA HALL?$"

ObsidianCity_Text_AttendantWarp:
	.string "The ash-gate opens…\nStep through the dark.$"

ObsidianCity_Text_AttendantStay:
	.string "Take your time in OBSIDIAN CITY.\nThe gate will wait.$"
