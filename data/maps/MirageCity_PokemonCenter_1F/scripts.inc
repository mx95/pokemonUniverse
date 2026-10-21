MirageCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MirageCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MirageCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MIRAGE_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

MirageCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_MIRAGE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MirageCity_PokemonCenter_1F_EventScript_Girl::
	msgbox MirageCity_PokemonCenter_1F_Text_Girl, MSGBOX_NPC
	end

MirageCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox MirageCity_PokemonCenter_1F_Text_ExpertM, MSGBOX_NPC
	end

MirageCity_PokemonCenter_1F_Text_Girl:
	.string "I thought I walked into the Mart, but\n"
	.string "it was the Center. Classic Mirage!$"

MirageCity_PokemonCenter_1F_Text_ExpertM:
	.string "Heal here before IRIS. Illusions hit\n"
	.string "harder when you're tired.$"
