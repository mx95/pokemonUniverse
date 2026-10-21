GenesisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GenesisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

GenesisCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_GENESIS_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

GenesisCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_GENESIS_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

GenesisCity_PokemonCenter_1F_EventScript_Girl::
	msgbox GenesisCity_PokemonCenter_1F_Text_Girl, MSGBOX_NPC
	end

GenesisCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox GenesisCity_PokemonCenter_1F_Text_ExpertM, MSGBOX_NPC
	end

GenesisCity_PokemonCenter_1F_Text_Girl:
	.string "Heal up before COLLEAGUE.\n"
	.string "GENESIS CITY doesn't go easy.$"

GenesisCity_PokemonCenter_1F_Text_ExpertM:
	.string "The Hall attendant outside will send\n"
	.string "you back when you're done.$"
