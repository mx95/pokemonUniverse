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

EonCity_PokemonCenter_1F_EventScript_Boy::
	goto Genesis_EventScript_QuestBoard
	end

EonCity_PokemonCenter_1F_EventScript_Girl::
	goto Genesis_EventScript_AchievementBoard
	end
