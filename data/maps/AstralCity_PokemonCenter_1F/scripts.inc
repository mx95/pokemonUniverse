AstralCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AstralCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

AstralCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_ASTRAL_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

AstralCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_ASTRAL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

AstralCity_PokemonCenter_1F_EventScript_Girl::
	msgbox AstralCity_PokemonCenter_1F_Text_Girl, MSGBOX_NPC
	end

AstralCity_PokemonCenter_1F_EventScript_ExpertM::
	msgbox AstralCity_PokemonCenter_1F_Text_ExpertM, MSGBOX_NPC
	end

AstralCity_PokemonCenter_1F_Text_Girl:
	.string "Heal up before DRAKE.\n"
	.string "ASTRAL CITY doesn't go easy.$"

AstralCity_PokemonCenter_1F_Text_ExpertM:
	.string "The Hall attendant outside will send\n"
	.string "you back when you're done.$"
