ObsidianCity_MapScripts::
	.byte 0

ObsidianCity_EventScript_Girl::
	msgbox ObsidianCity_Text_Girl, MSGBOX_NPC
	end

ObsidianCity_EventScript_ExpertM::
	msgbox ObsidianCity_Text_ExpertM, MSGBOX_NPC
	end

ObsidianCity_EventScript_Gentleman::
	msgbox ObsidianCity_Text_Gentleman, MSGBOX_NPC
	end

ObsidianCity_EventScript_HallAttendant::
	lock
	faceplayer
	msgbox ObsidianCity_Text_HallAttendant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ObsidianCity_EventScript_HallAttendantStay
	msgbox ObsidianCity_Text_HallAttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 2, 6
	waitstate
	release
	end

ObsidianCity_EventScript_HallAttendantStay::
	msgbox ObsidianCity_Text_HallAttendantStay, MSGBOX_DEFAULT
	release
	end

ObsidianCity_EventScript_CitySign::
	msgbox ObsidianCity_Text_CitySign, MSGBOX_SIGN
	end

ObsidianCity_EventScript_GymSign::
	msgbox ObsidianCity_Text_GymSign, MSGBOX_SIGN
	end

ObsidianCity_EventScript_TeleportSign::
	msgbox ObsidianCity_Text_TeleportSign, MSGBOX_SIGN
	end

ObsidianCity_Text_Girl:
	.string "Welcome to OBSIDIAN CITY!\n"
	.string "The Hall teleport net hums nearby.$"

ObsidianCity_Text_ExpertM:
	.string "NOCTIS keeps the DARK GYM honest.\n"
	.string "Challenge the GYM when you're ready.$"

ObsidianCity_Text_Gentleman:
	.string "Eastern Aurelia Hall links the cities.\n"
	.string "Our attendant can send you back.$"

ObsidianCity_Text_HallAttendant:
	.string "Return to EASTERN AURELIA HALL?$"

ObsidianCity_Text_HallAttendantWarp:
	.string "Safe travels through the net.$"

ObsidianCity_Text_HallAttendantStay:
	.string "Explore at your own pace.$"

ObsidianCity_Text_CitySign:
	.string "OBSIDIAN CITY\n"
	.string "“Glass streets, quiet night.”$"

ObsidianCity_Text_GymSign:
	.string "OBSIDIAN CITY POKéMON GYM\n"
	.string "LEADER: NOCTIS\l"
	.string "“The DARK trial!”$"

ObsidianCity_Text_TeleportSign:
	.string "OBSIDIAN CITY TELEPORT NET\n"
	.string "Gateways link Hall and city.$"
