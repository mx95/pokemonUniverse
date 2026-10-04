OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_TUTOR_INTRO, OldaleTown_PokemonCenter_1F_EventScript_TutorDone
	msgbox OldaleTown_PokemonCenter_1F_Text_TutorOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OldaleTown_PokemonCenter_1F_EventScript_TutorNo
	giveitem ITEM_BOTTLE_CAP
	giveitem ITEM_ABILITY_CAPSULE
	setflag FLAG_GENESIS_TUTOR_INTRO
	msgbox OldaleTown_PokemonCenter_1F_Text_TutorAfter, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_TutorDone::
	msgbox OldaleTown_PokemonCenter_1F_Text_TutorDone, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_TutorNo::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	goto Genesis_EventScript_QuestBoard
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_TutorOffer:
	.string "I help CHAMPIONS polish their teams.\n"
	.string "Take a BOTTLE CAP and ABILITY CAPSULE?$"

OldaleTown_PokemonCenter_1F_Text_TutorAfter:
	.string "Hyper Train and tweak Abilities at\n"
	.string "the facilities that support them.\p"
	.string "The Frontier has more for veterans.$"

OldaleTown_PokemonCenter_1F_Text_TutorDone:
	.string "Train smart. GENESIS ENERGY favors\n"
	.string "prepared TRAINERS.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"

