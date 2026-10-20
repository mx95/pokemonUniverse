ObsidianCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ObsidianCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ObsidianCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OBSIDIAN_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

ObsidianCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OBSIDIAN_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

ObsidianCity_PokemonCenter_1F_EventScript_Girl::
	msgbox ObsidianCity_PokemonCenter_1F_Text_Girl, MSGBOX_NPC
	end

ObsidianCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox ObsidianCity_PokemonCenter_1F_Text_ExpertM, MSGBOX_NPC
	end

ObsidianCity_PokemonCenter_1F_Text_Girl:
	.string "Heal up before NOCTIS.\n"
	.string "OBSIDIAN CITY doesn't go easy.$"

ObsidianCity_PokemonCenter_1F_Text_ExpertM:
	.string "The Hall attendant outside will send\n"
	.string "you back when you're done.$"
