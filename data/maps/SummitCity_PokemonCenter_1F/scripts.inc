SummitCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SummitCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SummitCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SUMMIT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SummitCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SUMMIT_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SummitCity_PokemonCenter_1F_EventScript_Girl::
	msgbox SummitCity_PokemonCenter_1F_Text_Girl, MSGBOX_NPC
	end

SummitCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox SummitCity_PokemonCenter_1F_Text_ExpertM, MSGBOX_NPC
	end

SummitCity_PokemonCenter_1F_Text_Girl:
	.string "Heal up before MENTOR.\n"
	.string "AURELIA SUMMIT doesn't go easy.$"

SummitCity_PokemonCenter_1F_Text_ExpertM:
	.string "The Hall attendant outside will send\n"
	.string "you back when you're done.$"
