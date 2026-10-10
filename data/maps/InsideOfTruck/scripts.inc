InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, InsideOfTruck_OnFrame
	.byte 0

InsideOfTruck_OnLoad:
	@ GENESIS: Corviknight taxi cabin (no truck bounce / STEP_CB_TRUCK)
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end

InsideOfTruck_OnFrame:
	map_script_2 VAR_TEMP_0, 0, InsideOfTruck_EventScript_TaxiArrive
	.2byte 0

InsideOfTruck_EventScript_TaxiArrive::
	lockall
	setvar VAR_TEMP_0, 1
	setflag FLAG_HIDE_MAP_NAME_POPUP
	playbgm MUS_RG_SURF, FALSE
	msgbox InsideOfTruck_Text_PilotWelcome, MSGBOX_DEFAULT
	msgbox InsideOfTruck_Text_PilotTouchDown, MSGBOX_DEFAULT
	closemessage
	playse SE_M_FLY
	waitse
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_SetIntroFlagsMale
	goto InsideOfTruck_EventScript_SetIntroFlagsFemale

InsideOfTruck_EventScript_SetIntroFlagsMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	warpsilent MAP_LITTLEROOT_TOWN, 3, 10
	waitstate
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	warpsilent MAP_LITTLEROOT_TOWN, 12, 10
	waitstate
	releaseall
	end

InsideOfTruck_EventScript_MovingBox::
	msgbox InsideOfTruck_Text_CargoTagged, MSGBOX_SIGN
	end

InsideOfTruck_Text_PilotWelcome:
	.string "CORVIKNIGHT PILOT: Welcome aboard\n"
	.string "AURELIA AIR TAXI!\p"
	.string "Your family's move to VERDANT TOWN\n"
	.string "is right on schedule.\p"
	.string "Please keep luggage stowed while we\n"
	.string "descend through the cloud layer.$"

InsideOfTruck_Text_PilotTouchDown:
	.string "CORVIKNIGHT PILOT: Touchdown!\n"
	.string "VERDANT TOWN, dead ahead.\p"
	.string "Thank you for flying with CORVIKNIGHT\n"
	.string "SERVICE. Watch your step on exit!$"

InsideOfTruck_Text_CargoTagged:
	.string "Luggage tags read:\n"
	.string "“AURELIA AIR - CORVIKNIGHT CARGO.”\p"
	.string "Your family's boxes made the flight.$"
