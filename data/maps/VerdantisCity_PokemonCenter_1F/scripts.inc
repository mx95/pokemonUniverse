VerdantisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdantisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdantisCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTIS_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

VerdantisCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTIS_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdantisCity_PokemonCenter_1F_EventScript_Girl::
	msgbox VerdantisCity_PokemonCenter_1F_Text_Girl, MSGBOX_NPC
	end

VerdantisCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdantisCity_PokemonCenter_1F_Text_ExpertM, MSGBOX_NPC
	end

VerdantisCity_PokemonCenter_1F_Text_Girl:
	.string "Heal up before CELIA.\n"
	.string "VERDANTIS CITY doesn't go easy.$"

VerdantisCity_PokemonCenter_1F_Text_ExpertM:
	.string "The Hall attendant outside will send\n"
	.string "you back when you're done.$"
