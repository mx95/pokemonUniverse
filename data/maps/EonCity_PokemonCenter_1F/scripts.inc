EonCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EonCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EonCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_EON_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

EonCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_EON_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EonCity_PokemonCenter_1F_EventScript_Girl::
	msgbox EonCity_PokemonCenter_1F_Text_Girl, MSGBOX_NPC
	end

EonCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox EonCity_PokemonCenter_1F_Text_ExpertM, MSGBOX_NPC
	end

EonCity_PokemonCenter_1F_Text_Girl:
	.string "Heal up before MORRIGAN.\n"
	.string "EON CITY doesn't go easy.$"

EonCity_PokemonCenter_1F_Text_ExpertM:
	.string "The Hall attendant outside will send\n"
	.string "you back when you're done.$"
