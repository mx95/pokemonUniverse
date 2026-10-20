TidymoonCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TidymoonCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

TidymoonCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_TIDYMOON_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

TidymoonCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TIDYMOON_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TidymoonCity_PokemonCenter_1F_EventScript_Girl::
	msgbox TidymoonCity_PokemonCenter_1F_Text_Girl, MSGBOX_NPC
	end

TidymoonCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox TidymoonCity_PokemonCenter_1F_Text_ExpertM, MSGBOX_NPC
	end

TidymoonCity_PokemonCenter_1F_Text_Girl:
	.string "Heal up before LUNA.\n"
	.string "TIDYMOON CITY doesn't go easy.$"

TidymoonCity_PokemonCenter_1F_Text_ExpertM:
	.string "The Hall attendant outside will send\n"
	.string "you back when you're done.$"
