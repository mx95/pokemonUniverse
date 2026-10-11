EasternAurelia_Hall_MapScripts::
	.byte 0

@ City desks (stand-in for Mirage→Summit east). Leaders unlock in badge order 9-16.

@ Badge 9 battle lives in MirageCity_Gym; the Hall NPC + desk just warp there.
EasternAurelia_Hall_EventScript_Iris::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_09_GET, EasternAurelia_Hall_EventScript_IrisDone
	msgbox EasternAurelia_Hall_Text_IrisRedirect, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_MirageWarpAsk
	end

EasternAurelia_Hall_EventScript_MirageWarpAsk::
	msgbox EasternAurelia_Hall_Text_MirageWarpAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_MirageStay
	msgbox EasternAurelia_Hall_Text_MirageWarp, MSGBOX_DEFAULT
	warpsilent MAP_MIRAGE_CITY, 6, 17
	waitstate
	releaseall
	end

EasternAurelia_Hall_EventScript_MirageStay::
	msgbox EasternAurelia_Hall_Text_MirageStay, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_IrisDone::
	msgbox EasternAurelia_Hall_Text_IrisDone, MSGBOX_DEFAULT
	release
	end

@ Badge 10 battle lives in VerdantisCity_Gym; the Hall NPC + desk just warp there.
EasternAurelia_Hall_EventScript_Celia::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_09_GET, EasternAurelia_Hall_EventScript_NeedIris
	goto_if_set FLAG_GENESIS_BADGE_10_GET, EasternAurelia_Hall_EventScript_CeliaDone
	msgbox EasternAurelia_Hall_Text_CeliaRedirect, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_VerdantisWarpAsk
	end

EasternAurelia_Hall_EventScript_VerdantisWarpAsk::
	msgbox EasternAurelia_Hall_Text_VerdantisWarpAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_VerdantisStay
	msgbox EasternAurelia_Hall_Text_VerdantisWarp, MSGBOX_DEFAULT
	warpsilent MAP_VERDANTIS_CITY, 5, 7
	waitstate
	releaseall
	end

EasternAurelia_Hall_EventScript_VerdantisStay::
	msgbox EasternAurelia_Hall_Text_VerdantisStay, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_CeliaDone::
	msgbox EasternAurelia_Hall_Text_CeliaDone, MSGBOX_DEFAULT
	release
	end

@ Badge 11 battle lives in ObsidianCity_Gym; the Hall NPC + desk just warp there.
EasternAurelia_Hall_EventScript_Noctis::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_10_GET, EasternAurelia_Hall_EventScript_NeedCelia
	goto_if_set FLAG_GENESIS_BADGE_11_GET, EasternAurelia_Hall_EventScript_NoctisDone
	msgbox EasternAurelia_Hall_Text_NoctisRedirect, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_ObsidianWarpAsk
	end

EasternAurelia_Hall_EventScript_ObsidianWarpAsk::
	msgbox EasternAurelia_Hall_Text_ObsidianWarpAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_ObsidianStay
	msgbox EasternAurelia_Hall_Text_ObsidianWarp, MSGBOX_DEFAULT
	warpsilent MAP_OBSIDIAN_CITY, 9, 7
	waitstate
	releaseall
	end

EasternAurelia_Hall_EventScript_ObsidianStay::
	msgbox EasternAurelia_Hall_Text_ObsidianStay, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_NoctisDone::
	msgbox EasternAurelia_Hall_Text_NoctisDone, MSGBOX_DEFAULT
	release
	end

@ Badge 12 battle lives in AstralCity_Gym; the Hall NPC + desk just warp there.
EasternAurelia_Hall_EventScript_Drake::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_11_GET, EasternAurelia_Hall_EventScript_NeedNoctis
	goto_if_set FLAG_GENESIS_BADGE_12_GET, EasternAurelia_Hall_EventScript_DrakeDone
	msgbox EasternAurelia_Hall_Text_DrakeRedirect, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_AstralWarpAsk
	end

EasternAurelia_Hall_EventScript_AstralWarpAsk::
	msgbox EasternAurelia_Hall_Text_AstralWarpAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_AstralStay
	msgbox EasternAurelia_Hall_Text_AstralWarp, MSGBOX_DEFAULT
	warpsilent MAP_ASTRAL_CITY, 19, 20
	waitstate
	releaseall
	end

EasternAurelia_Hall_EventScript_AstralStay::
	msgbox EasternAurelia_Hall_Text_AstralStay, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_DrakeDone::
	msgbox EasternAurelia_Hall_Text_DrakeDone, MSGBOX_DEFAULT
	release
	end

@ Badge 13 battle lives in TidymoonCity_Gym; the Hall NPC + desk just warp there.
EasternAurelia_Hall_EventScript_Luna::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_12_GET, EasternAurelia_Hall_EventScript_NeedDrake
	goto_if_set FLAG_GENESIS_BADGE_13_GET, EasternAurelia_Hall_EventScript_LunaDone
	msgbox EasternAurelia_Hall_Text_LunaRedirect, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_TidymoonWarpAsk
	end

EasternAurelia_Hall_EventScript_TidymoonWarpAsk::
	msgbox EasternAurelia_Hall_Text_TidymoonWarpAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_TidymoonStay
	msgbox EasternAurelia_Hall_Text_TidymoonWarp, MSGBOX_DEFAULT
	warpsilent MAP_TIDYMOON_CITY, 28, 17
	waitstate
	releaseall
	end

EasternAurelia_Hall_EventScript_TidymoonStay::
	msgbox EasternAurelia_Hall_Text_TidymoonStay, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_LunaDone::
	msgbox EasternAurelia_Hall_Text_LunaDone, MSGBOX_DEFAULT
	release
	end

@ Badge 14 battle lives in EonCity_Gym; the Hall NPC + desk just warp there.
EasternAurelia_Hall_EventScript_Morrigan::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_13_GET, EasternAurelia_Hall_EventScript_NeedLuna
	goto_if_set FLAG_GENESIS_BADGE_14_GET, EasternAurelia_Hall_EventScript_MorriganDone
	msgbox EasternAurelia_Hall_Text_MorriganRedirect, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_EonWarpAsk
	end

EasternAurelia_Hall_EventScript_EonWarpAsk::
	msgbox EasternAurelia_Hall_Text_EonWarpAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_EonStay
	msgbox EasternAurelia_Hall_Text_EonWarp, MSGBOX_DEFAULT
	warpsilent MAP_EON_CITY, 22, 6
	waitstate
	releaseall
	end

EasternAurelia_Hall_EventScript_EonStay::
	msgbox EasternAurelia_Hall_Text_EonStay, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_MorriganDone::
	msgbox EasternAurelia_Hall_Text_MorriganDone, MSGBOX_DEFAULT
	release
	end

@ Badge 15 battle lives in GenesisCity_Gym; the Hall NPC + desk just warp there.
EasternAurelia_Hall_EventScript_Colleague::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_14_GET, EasternAurelia_Hall_EventScript_NeedMorrigan
	goto_if_set FLAG_GENESIS_BADGE_15_GET, EasternAurelia_Hall_EventScript_ColleagueDone
	msgbox EasternAurelia_Hall_Text_ColleagueRedirect, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_GenesisWarpAsk
	end

EasternAurelia_Hall_EventScript_GenesisWarpAsk::
	msgbox EasternAurelia_Hall_Text_GenesisWarpAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_GenesisStay
	msgbox EasternAurelia_Hall_Text_GenesisWarp, MSGBOX_DEFAULT
	warpsilent MAP_GENESIS_CITY, 20, 17
	waitstate
	releaseall
	end

EasternAurelia_Hall_EventScript_GenesisStay::
	msgbox EasternAurelia_Hall_Text_GenesisStay, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_ColleagueDone::
	msgbox EasternAurelia_Hall_Text_ColleagueDone, MSGBOX_DEFAULT
	release
	end

@ Badge 16 battle lives in SummitCity_Gym; the Hall NPC + desk just warp there.
EasternAurelia_Hall_EventScript_Mentor::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_15_GET, EasternAurelia_Hall_EventScript_NeedColleague
	goto_if_set FLAG_GENESIS_BADGE_16_GET, EasternAurelia_Hall_EventScript_MentorDone
	msgbox EasternAurelia_Hall_Text_MentorRedirect, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_SummitWarpAsk
	end

EasternAurelia_Hall_EventScript_SummitWarpAsk::
	msgbox EasternAurelia_Hall_Text_SummitWarpAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_SummitStay
	msgbox EasternAurelia_Hall_Text_SummitWarp, MSGBOX_DEFAULT
	warpsilent MAP_SUMMIT_CITY, 16, 39
	waitstate
	releaseall
	end

EasternAurelia_Hall_EventScript_SummitStay::
	msgbox EasternAurelia_Hall_Text_SummitStay, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_MentorDone::
	msgbox EasternAurelia_Hall_Text_MentorDone, MSGBOX_DEFAULT
	release
	end

@ Badge 17 battle lives in VenomHollow_Gym; the Hall NPC + desk just warp there.
EasternAurelia_Hall_EventScript_Vesper::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_16_GET, EasternAurelia_Hall_EventScript_NeedMentor
	goto_if_set FLAG_GENESIS_BADGE_17_GET, EasternAurelia_Hall_EventScript_VesperDone
	msgbox EasternAurelia_Hall_Text_VesperRedirect, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_VenomWarpAsk
	end

EasternAurelia_Hall_EventScript_VenomWarpAsk::
	msgbox EasternAurelia_Hall_Text_VenomWarpAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_VenomStay
	msgbox EasternAurelia_Hall_Text_VenomWarp, MSGBOX_DEFAULT
	warpsilent MAP_VENOM_HOLLOW, 14, 8
	waitstate
	releaseall
	end

EasternAurelia_Hall_EventScript_VenomStay::
	msgbox EasternAurelia_Hall_Text_VenomStay, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_VesperDone::
	msgbox EasternAurelia_Hall_Text_VesperDone, MSGBOX_DEFAULT
	release
	end

@ Badge 18 battle lives in TerracottaMesa_Gym; the Hall NPC + desk just warp there.
EasternAurelia_Hall_EventScript_Terra::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_17_GET, EasternAurelia_Hall_EventScript_NeedVesper
	goto_if_set FLAG_GENESIS_BADGE_18_GET, EasternAurelia_Hall_EventScript_TerraDone
	msgbox EasternAurelia_Hall_Text_TerraRedirect, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_TerracottaWarpAsk
	end

EasternAurelia_Hall_EventScript_TerracottaWarpAsk::
	msgbox EasternAurelia_Hall_Text_TerracottaWarpAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_TerracottaStay
	msgbox EasternAurelia_Hall_Text_TerracottaWarp, MSGBOX_DEFAULT
	warpsilent MAP_TERRACOTTA_MESA, 16, 4
	waitstate
	releaseall
	end

EasternAurelia_Hall_EventScript_TerracottaStay::
	msgbox EasternAurelia_Hall_Text_TerracottaStay, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_TerraDone::
	msgbox EasternAurelia_Hall_Text_TerraDone, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedIris::
	msgbox EasternAurelia_Hall_Text_NeedIris, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedCelia::
	msgbox EasternAurelia_Hall_Text_NeedCelia, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedNoctis::
	msgbox EasternAurelia_Hall_Text_NeedNoctis, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedDrake::
	msgbox EasternAurelia_Hall_Text_NeedDrake, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedLuna::
	msgbox EasternAurelia_Hall_Text_NeedLuna, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedMorrigan::
	msgbox EasternAurelia_Hall_Text_NeedMorrigan, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedColleague::
	msgbox EasternAurelia_Hall_Text_NeedColleague, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedMentor::
	msgbox EasternAurelia_Hall_Text_NeedMentor, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_NeedVesper::
	msgbox EasternAurelia_Hall_Text_NeedVesper, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_Decline::
	msgbox EasternAurelia_Hall_Text_Decline, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_LegendSeeker::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, EasternAurelia_Hall_EventScript_LegendSeekerEarly
	goto_if_unset FLAG_GENESIS_ECLIPSE_DEFEATED, EasternAurelia_Hall_EventScript_LegendSeekerEclipseGate
	setflag FLAG_GENESIS_LEGEND_QUEST_HINT
	setflag FLAG_GENESIS_ECLIPSE_ARCHIVE_OPEN
	msgbox EasternAurelia_Hall_Text_SanctumOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_SanctumWarp, MSGBOX_DEFAULT
	warpsilent MAP_GENESIS_LEGEND_SANCTUM, 4, 6
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_LegendSeekerEarly::
	msgbox EasternAurelia_Hall_Text_LegendEarly, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_LegendSeekerEclipseGate::
	msgbox EasternAurelia_Hall_Text_EclipseGate, MSGBOX_DEFAULT
	release
	end

@ Hall clerk: desk directory + return warp to Reception Gate (Fly QoL companion)
EasternAurelia_Hall_EventScript_HallClerk::
	lock
	faceplayer
	call EasternAurelia_Hall_EventScript_TryTypeMasterGift
	msgbox EasternAurelia_Hall_Text_ClerkWelcome, MSGBOX_DEFAULT
	message EasternAurelia_Hall_Text_ClerkAsk
	waitmessage
	multichoice 0, 0, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, EasternAurelia_Hall_EventScript_ClerkReturn
	case 1, EasternAurelia_Hall_EventScript_ClerkStay
	case 2, EasternAurelia_Hall_EventScript_ClerkDirectory
	case MULTI_B_PRESSED, EasternAurelia_Hall_EventScript_ClerkStay
	end

EasternAurelia_Hall_EventScript_TryTypeMasterGift::
	goto_if_set FLAG_GENESIS_TYPE_MASTER_REWARD, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_BADGE_09_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_BADGE_10_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_BADGE_11_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_BADGE_12_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_BADGE_13_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_BADGE_14_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_BADGE_15_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_BADGE_16_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_BADGE_17_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_BADGE_18_GET, Common_EventScript_NopReturn
	setflag FLAG_GENESIS_TYPE_MASTER_REWARD
	setflag FLAG_GENESIS_ACHIEVEMENT_TYPE_MASTER
	msgbox EasternAurelia_Hall_Text_TypeMaster, MSGBOX_DEFAULT
	giveitem ITEM_GOLD_BOTTLE_CAP
	giveitem ITEM_ABILITY_CAPSULE
	return

EasternAurelia_Hall_EventScript_ClerkReturn::
	msgbox EasternAurelia_Hall_Text_ClerkWarpOut, MSGBOX_DEFAULT
	warpsilent MAP_BATTLE_FRONTIER_RECEPTION_GATE, 4, 11
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_ClerkStay::
	msgbox EasternAurelia_Hall_Text_ClerkStay, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_ClerkDirectory::
	msgbox EasternAurelia_Hall_Text_ClerkDirectory, MSGBOX_DEFAULT
	msgbox EasternAurelia_Hall_Text_JukeboxAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EasternAurelia_Hall_EventScript_Jukebox
	goto EasternAurelia_Hall_EventScript_ChaosGate
	end

EasternAurelia_Hall_EventScript_Jukebox::
	message EasternAurelia_Hall_Text_JukeboxPick
	waitmessage
	dynmultipush EasternAurelia_Hall_Text_TrackVerdant, 0
	dynmultipush EasternAurelia_Hall_Text_TrackLumen, 1
	dynmultipush EasternAurelia_Hall_Text_TrackPort, 2
	dynmultipush EasternAurelia_Hall_Text_TrackCelestia, 3
	dynmultipush EasternAurelia_Hall_Text_TrackLeague, 4
	dynmultipush EasternAurelia_Hall_Text_TrackCancel, 5
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, EasternAurelia_Hall_EventScript_PlayVerdant
	case 1, EasternAurelia_Hall_EventScript_PlayLumen
	case 2, EasternAurelia_Hall_EventScript_PlayPort
	case 3, EasternAurelia_Hall_EventScript_PlayCelestia
	case 4, EasternAurelia_Hall_EventScript_PlayLeague
	case 5, EasternAurelia_Hall_EventScript_ChaosGate
	case MULTI_B_PRESSED, EasternAurelia_Hall_EventScript_ChaosGate
	end

EasternAurelia_Hall_EventScript_PlayVerdant::
	playbgm MUS_LITTLEROOT, FALSE
	msgbox EasternAurelia_Hall_Text_JukeboxPlaying, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_ChaosGate
	end

EasternAurelia_Hall_EventScript_PlayLumen::
	playbgm MUS_OLDALE, FALSE
	msgbox EasternAurelia_Hall_Text_JukeboxPlaying, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_ChaosGate
	end

EasternAurelia_Hall_EventScript_PlayPort::
	playbgm MUS_PETALBURG, FALSE
	msgbox EasternAurelia_Hall_Text_JukeboxPlaying, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_ChaosGate
	end

EasternAurelia_Hall_EventScript_PlayCelestia::
	playbgm MUS_RG_CELADON, FALSE
	msgbox EasternAurelia_Hall_Text_JukeboxPlaying, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_ChaosGate
	end

EasternAurelia_Hall_EventScript_PlayLeague::
	playbgm MUS_VICTORY_ROAD, FALSE
	msgbox EasternAurelia_Hall_Text_JukeboxPlaying, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_ChaosGate
	end

EasternAurelia_Hall_EventScript_ChaosGate::
	goto_if_unset FLAG_SYS_GAME_CLEAR, EasternAurelia_Hall_EventScript_ClerkStayQuiet
	goto_if_set FLAG_GENESIS_CHAOS_BATTLES, EasternAurelia_Hall_EventScript_ChaosIsOn
	msgbox EasternAurelia_Hall_Text_ChaosOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_ChaosDeclined
	setflag FLAG_GENESIS_CHAOS_BATTLES
	msgbox EasternAurelia_Hall_Text_ChaosEnabled, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_ChaosIsOn::
	msgbox EasternAurelia_Hall_Text_ChaosDisableAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_ChaosDeclined
	clearflag FLAG_GENESIS_CHAOS_BATTLES
	msgbox EasternAurelia_Hall_Text_ChaosDisabled, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_ChaosDeclined::
	msgbox EasternAurelia_Hall_Text_ChaosKept, MSGBOX_DEFAULT
	release
	end

EasternAurelia_Hall_EventScript_ClerkStayQuiet::
	release
	end

@ Desk plaques (bg signs) — read the blurb, then offer the warp once the previous badge is held.
EasternAurelia_Hall_EventScript_DeskMirage::
	lockall
	msgbox EasternAurelia_Hall_Text_DeskMirage, MSGBOX_DEFAULT
	goto EasternAurelia_Hall_EventScript_MirageWarpAsk
	end

@ Verdantis / Obsidian plaques: read the blurb, then offer the warp once the previous badge is held.
@ (Town totems live in the cities themselves now, like Mirage.)
EasternAurelia_Hall_EventScript_DeskVerdantis::
	lockall
	msgbox EasternAurelia_Hall_Text_DeskVerdantis, MSGBOX_DEFAULT
	goto_if_unset FLAG_GENESIS_BADGE_09_GET, EasternAurelia_Hall_EventScript_DeskNeedIris
	goto EasternAurelia_Hall_EventScript_VerdantisWarpAsk
	end

EasternAurelia_Hall_EventScript_DeskObsidian::
	lockall
	msgbox EasternAurelia_Hall_Text_DeskObsidian, MSGBOX_DEFAULT
	goto_if_unset FLAG_GENESIS_BADGE_10_GET, EasternAurelia_Hall_EventScript_DeskNeedCelia
	goto EasternAurelia_Hall_EventScript_ObsidianWarpAsk
	end

EasternAurelia_Hall_EventScript_DeskNeedIris::
	msgbox EasternAurelia_Hall_Text_NeedIris, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_DeskNeedCelia::
	msgbox EasternAurelia_Hall_Text_NeedCelia, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_DeskNeedNoctis::
	msgbox EasternAurelia_Hall_Text_NeedNoctis, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_DeskNeedDrake::
	msgbox EasternAurelia_Hall_Text_NeedDrake, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_DeskNeedLuna::
	msgbox EasternAurelia_Hall_Text_NeedLuna, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_DeskNeedMorrigan::
	msgbox EasternAurelia_Hall_Text_NeedMorrigan, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_DeskNeedColleague::
	msgbox EasternAurelia_Hall_Text_NeedColleague, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_DeskNeedMentor::
	msgbox EasternAurelia_Hall_Text_NeedMentor, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_DeskNeedVesper::
	msgbox EasternAurelia_Hall_Text_NeedVesper, MSGBOX_DEFAULT
	releaseall
	end

EasternAurelia_Hall_EventScript_DeskAstral::
	lockall
	msgbox EasternAurelia_Hall_Text_DeskAstral, MSGBOX_DEFAULT
	goto_if_unset FLAG_GENESIS_BADGE_11_GET, EasternAurelia_Hall_EventScript_DeskNeedNoctis
	goto EasternAurelia_Hall_EventScript_AstralWarpAsk
	end

EasternAurelia_Hall_EventScript_DeskTidymoon::
	lockall
	msgbox EasternAurelia_Hall_Text_DeskTidymoon, MSGBOX_DEFAULT
	goto_if_unset FLAG_GENESIS_BADGE_12_GET, EasternAurelia_Hall_EventScript_DeskNeedDrake
	goto EasternAurelia_Hall_EventScript_TidymoonWarpAsk
	end

EasternAurelia_Hall_EventScript_DeskEon::
	lockall
	msgbox EasternAurelia_Hall_Text_DeskEon, MSGBOX_DEFAULT
	goto_if_unset FLAG_GENESIS_BADGE_13_GET, EasternAurelia_Hall_EventScript_DeskNeedLuna
	goto EasternAurelia_Hall_EventScript_EonWarpAsk
	end

EasternAurelia_Hall_EventScript_DeskGenesis::
	lockall
	msgbox EasternAurelia_Hall_Text_DeskGenesis, MSGBOX_DEFAULT
	goto_if_unset FLAG_GENESIS_BADGE_14_GET, EasternAurelia_Hall_EventScript_DeskNeedMorrigan
	goto EasternAurelia_Hall_EventScript_GenesisWarpAsk
	end

EasternAurelia_Hall_EventScript_DeskSummit::
	lockall
	msgbox EasternAurelia_Hall_Text_DeskSummit, MSGBOX_DEFAULT
	goto_if_unset FLAG_GENESIS_BADGE_15_GET, EasternAurelia_Hall_EventScript_DeskNeedColleague
	goto EasternAurelia_Hall_EventScript_SummitWarpAsk
	end

EasternAurelia_Hall_EventScript_DeskVenom::
	lockall
	msgbox EasternAurelia_Hall_Text_DeskVenom, MSGBOX_DEFAULT
	goto_if_unset FLAG_GENESIS_BADGE_16_GET, EasternAurelia_Hall_EventScript_DeskNeedMentor
	goto EasternAurelia_Hall_EventScript_VenomWarpAsk
	end

EasternAurelia_Hall_EventScript_DeskTerracotta::
	lockall
	msgbox EasternAurelia_Hall_Text_DeskTerracotta, MSGBOX_DEFAULT
	goto_if_unset FLAG_GENESIS_BADGE_17_GET, EasternAurelia_Hall_EventScript_DeskNeedVesper
	goto EasternAurelia_Hall_EventScript_TerracottaWarpAsk
	end

EasternAurelia_Hall_EventScript_HallDirectory::
	msgbox EasternAurelia_Hall_Text_HallDirectory, MSGBOX_SIGN
	end

EasternAurelia_Hall_Text_Decline:
	.string "Return when the tide of battle calls.$"

EasternAurelia_Hall_Text_NeedIris:
	.string "CELIA: Verdantis waits its turn.\n"
	.string "Clear IRIS's MIRAGE CITY gym first.$"

EasternAurelia_Hall_Text_NeedCelia:
	.string "NOCTIS: Obsidian stays sealed until\n"
	.string "you earn CELIA's JUNGLE BADGE.$"

EasternAurelia_Hall_Text_NeedNoctis:
	.string "DRAKE: Astral City's stars won't turn\n"
	.string "until NOCTIS yields the OBSIDIAN BADGE.$"

EasternAurelia_Hall_Text_NeedDrake:
	.string "LUNA: Tidymoon's tide follows the stars.\n"
	.string "Challenge DRAKE for the ASTRAL BADGE.$"

EasternAurelia_Hall_Text_NeedLuna:
	.string "MORRIGAN: Eon's spirits keep to order.\n"
	.string "Bring LUNA's MOON BADGE first.$"

EasternAurelia_Hall_Text_NeedMorrigan:
	.string "COLLEAGUE: Genesis City only hosts\n"
	.string "those who hold MORRIGAN's EON BADGE.$"

EasternAurelia_Hall_Text_NeedColleague:
	.string "MENTOR: The Summit desk opens after\n"
	.string "you claim the GENESIS BADGE.$"

EasternAurelia_Hall_Text_IrisRedirect:
	.string "IRIS: My GYM stands in MIRAGE CITY.\n"
	.string "Our streets fold light into riddles.\p"
	.string "The teleport net can take you there.$"

EasternAurelia_Hall_Text_MirageWarpAsk:
	.string "Travel to MIRAGE CITY?$"

EasternAurelia_Hall_Text_MirageWarp:
	.string "The teleport net hums…\n"
	.string "Step into the haze.$"

EasternAurelia_Hall_Text_MirageStay:
	.string "The mirage will keep.\n"
	.string "Return when you're ready.$"

EasternAurelia_Hall_Text_IrisDone:
	.string "IRIS: Mirage City's teleport net still\n"
	.string "hums for you. Trust what you perceive.$"

EasternAurelia_Hall_Text_CeliaRedirect:
	.string "CELIA: My GYM stands in VERDANTIS CITY.\n"
	.string "Rainforest canopies, buzzing trails…\p"
	.string "The canopy lift can take you there.$"

EasternAurelia_Hall_Text_VerdantisWarpAsk:
	.string "Travel to VERDANTIS CITY?$"

EasternAurelia_Hall_Text_VerdantisWarp:
	.string "The canopy lift hums…\n"
	.string "Hold on to the rail.$"

EasternAurelia_Hall_Text_VerdantisStay:
	.string "The jungle will keep.\n"
	.string "Return when you're ready.$"

EasternAurelia_Hall_Text_CeliaDone:
	.string "CELIA: Verdantis keeps blooming.\n"
	.string "Come back when you need green noise.$"

EasternAurelia_Hall_Text_NoctisRedirect:
	.string "NOCTIS: My GYM stands in OBSIDIAN CITY.\n"
	.string "Volcanic glass. Quiet streets. Night.\p"
	.string "The ash-gate can take you there.$"

EasternAurelia_Hall_Text_ObsidianWarpAsk:
	.string "Travel to OBSIDIAN CITY?$"

EasternAurelia_Hall_Text_ObsidianWarp:
	.string "The ash-gate opens…\n"
	.string "Step through the dark.$"

EasternAurelia_Hall_Text_ObsidianStay:
	.string "The night will keep.\n"
	.string "Return when you're ready.$"

EasternAurelia_Hall_Text_NoctisDone:
	.string "NOCTIS: Obsidian's vents still glow.\n"
	.string "Walk unafraid of your own shadow.$"

EasternAurelia_Hall_Text_DrakeRedirect:
	.string "DRAKE: My GYM is in ASTRAL CITY.\n"
	.string "Cliff spires under aurora fire.\p"
	.string "The star-lift can take you there.$"

EasternAurelia_Hall_Text_AstralWarpAsk:
	.string "Travel to ASTRAL CITY?$"

EasternAurelia_Hall_Text_AstralWarp:
	.string "The star-lift hums…\n"
	.string "Rise toward the aurora.$"

EasternAurelia_Hall_Text_AstralStay:
	.string "The stars will keep.\n"
	.string "Return when you're ready.$"

EasternAurelia_Hall_Text_DrakeDone:
	.string "DRAKE: Astral's scopes still track you.\n"
	.string "Shape the battlefield as you will.$"

EasternAurelia_Hall_Text_LunaRedirect:
	.string "LUNA: My GYM is in TIDYMOON CITY.\n"
	.string "Tide gardens lit by pale moons.\p"
	.string "The moon-ferry can take you there.$"

EasternAurelia_Hall_Text_TidymoonWarpAsk:
	.string "Travel to TIDYMOON CITY?$"

EasternAurelia_Hall_Text_TidymoonWarp:
	.string "The moon-ferry glides in…\n"
	.string "Step aboard.$"

EasternAurelia_Hall_Text_TidymoonStay:
	.string "The tide will wait.\n"
	.string "Return when you're ready.$"

EasternAurelia_Hall_Text_LunaDone:
	.string "LUNA: Tidymoon's waves remember you.\n"
	.string "Kindness is not weakness, Champion.$"

EasternAurelia_Hall_Text_MorriganRedirect:
	.string "MORRIGAN: My GYM is in EON CITY.\n"
	.string "Clocktower streets between eras.\p"
	.string "The echo-gate can take you there.$"

EasternAurelia_Hall_Text_EonWarpAsk:
	.string "Travel to EON CITY?$"

EasternAurelia_Hall_Text_EonWarp:
	.string "The echo-gate chimes…\n"
	.string "Step between the hours.$"

EasternAurelia_Hall_Text_EonStay:
	.string "The past will keep.\n"
	.string "Return when you're ready.$"

EasternAurelia_Hall_Text_MorriganDone:
	.string "MORRIGAN: Eon's bells still toll for you.\n"
	.string "Listen when the past whispers.$"

EasternAurelia_Hall_Text_ColleagueRedirect:
	.string "COLLEAGUE: My GYM is in GENESIS CITY.\n"
	.string "The Colleague's lab-city hub.\p"
	.string "The hub shuttle can take you there.$"

EasternAurelia_Hall_Text_GenesisWarpAsk:
	.string "Travel to GENESIS CITY?$"

EasternAurelia_Hall_Text_GenesisWarp:
	.string "The hub shuttle spins up…\n"
	.string "Mind the gap.$"

EasternAurelia_Hall_Text_GenesisStay:
	.string "The lab will keep.\n"
	.string "Return when you're ready.$"

EasternAurelia_Hall_Text_ColleagueDone:
	.string "COLLEAGUE: Ask our plaque about\n"
	.string "SLAKING--lazy power, NORMAL force.$"

EasternAurelia_Hall_Text_MentorRedirect:
	.string "MENTOR: My GYM is in SUMMIT CITY.\n"
	.string "Eastern peak of the old road.\p"
	.string "The cliff-lift can take you there.$"

EasternAurelia_Hall_Text_SummitWarpAsk:
	.string "Travel to SUMMIT CITY?$"

EasternAurelia_Hall_Text_SummitWarp:
	.string "The cliff-lift grinds upward…\n"
	.string "Hold fast.$"

EasternAurelia_Hall_Text_SummitStay:
	.string "The mountain will keep.\n"
	.string "Return when you're ready.$"

EasternAurelia_Hall_Text_MentorDone:
	.string "MENTOR: The Summit watches your path.\n"
	.string "VENOM HOLLOW and TERRACOTTA await.\p"
	.string "Also seek TYRANITAR at our plaque.$"

EasternAurelia_Hall_Text_VesperRedirect:
	.string "VESPER: My GYM is in VENOM HOLLOW.\n"
	.string "Marsh lanterns over toxic bloom.\p"
	.string "The lantern-boat can take you there.$"

EasternAurelia_Hall_Text_VenomWarpAsk:
	.string "Travel to VENOM HOLLOW?$"

EasternAurelia_Hall_Text_VenomWarp:
	.string "The lantern-boat drifts in…\n"
	.string "Mind the fumes.$"

EasternAurelia_Hall_Text_VenomStay:
	.string "The mist will keep.\n"
	.string "Return when you're ready.$"

EasternAurelia_Hall_Text_VesperDone:
	.string "VESPER: Read the Venom plaque for\n"
	.string "GENGAR's story, Champion.$"

EasternAurelia_Hall_Text_TerraRedirect:
	.string "TERRA: My GYM is in TERRACOTTA MESA.\n"
	.string "Red clay mesas and buried ruins.\p"
	.string "The dune-runner can take you there.$"

EasternAurelia_Hall_Text_TerracottaWarpAsk:
	.string "Travel to TERRACOTTA MESA?$"

EasternAurelia_Hall_Text_TerracottaWarp:
	.string "The dune-runner kicks up dust…\n"
	.string "Hold your hat.$"

EasternAurelia_Hall_Text_TerracottaStay:
	.string "The mesa will keep.\n"
	.string "Return when you're ready.$"

EasternAurelia_Hall_Text_TerraDone:
	.string "TERRA: Eighteen badges. Full spectrum.\n"
	.string "Ask the mesa plaque of GARCHOMP.$"

EasternAurelia_Hall_Text_NeedMentor:
	.string "VESPER: Clear MENTOR's ROCK desk\n"
	.string "before Venom Hollow opens.$"

EasternAurelia_Hall_Text_NeedVesper:
	.string "TERRA: Earn VESPER's VENOM BADGE\n"
	.string "before the mesa will shift for you.$"

EasternAurelia_Hall_Text_LegendEarly:
	.string "Return when you are CHAMPION.\n"
	.string "The legends will answer then.$"

EasternAurelia_Hall_Text_EclipseGate:
	.string "The LEGEND SANCTUM stays sealed while\n"
	.string "TEAM ECLIPSE's residue lingers.\p"
	.string "Defeat them completely, then return.$"

EasternAurelia_Hall_Text_SanctumOffer:
	.string "The LEGEND SANCTUM is open to you.\n"
	.string "Shall I show you the three foci?$"

EasternAurelia_Hall_Text_SanctumWarp:
	.string "This way--tread carefully.$"

EasternAurelia_Hall_Text_TypeMaster:
	.string "Every Eastern desk answered you.\n"
	.string "Eighteen types… a TYPE MASTER!\p"
	.string "Take this Gold Bottle Cap and capsule\n"
	.string "from the Hall's competitive vault.$"

EasternAurelia_Hall_Text_ClerkWelcome:
	.string "Eastern AURELIA HALL clerk.\n"
	.string "City desks for every type--for now.$"

EasternAurelia_Hall_Text_ClerkAsk:
	.string "Return to the Reception Gate?\n"
	.string "(YES / NO / INFO: desks, CHAOS)$"

EasternAurelia_Hall_Text_ClerkWarpOut:
	.string "Fly back to the BATTLE FRONTIER any\n"
	.string "time, then speak with the greeter.\p"
	.string "I'll send you to the Reception Gate.$"

EasternAurelia_Hall_Text_ClerkStay:
	.string "Browse the desks when you're ready.\n"
	.string "Plaques name each Eastern city.$"

EasternAurelia_Hall_Text_JukeboxAsk:
	.string "Want to sample AURELIA town themes\n"
	.string "on the Hall jukebox first?$"

EasternAurelia_Hall_Text_JukeboxPick:
	.string "Pick a theme:$"

EasternAurelia_Hall_Text_TrackVerdant:
	.string "Verdant Town$"

EasternAurelia_Hall_Text_TrackLumen:
	.string "Lumen City$"

EasternAurelia_Hall_Text_TrackPort:
	.string "Port Azure$"

EasternAurelia_Hall_Text_TrackCelestia:
	.string "Celestia City$"

EasternAurelia_Hall_Text_TrackLeague:
	.string "Aurelia Summit$"

EasternAurelia_Hall_Text_TrackCancel:
	.string "Cancel$"

EasternAurelia_Hall_Text_JukeboxPlaying:
	.string "The Hall speakers hum that theme.$"

EasternAurelia_Hall_Text_ClerkDirectory:
	.string "Back: MIRAGE · VERDANTIS · OBSIDIAN ·\n"
	.string "ASTRAL · VENOM HOLLOW.\p"
	.string "Front: TIDYMOON · EON · GENESIS CITY ·\n"
	.string "SUMMIT · TERRACOTTA MESA.\p"
	.string "Types 9-18: Psychic Bug Dark Dragon\n"
	.string "Fairy Ghost Normal Rock Poison Ground.\p"
	.string "After the League, ask about CHAOS\n"
	.string "BATTLES (multi-gimmick rule).\p"
	.string "Plaques also start town legend quests.\n"
	.string "Reception Gate warps to WORLD TOURNAMENT.$"

EasternAurelia_Hall_Text_ChaosOffer:
	.string "CHAMPION-only rule: CHAOS BATTLES.\p"
	.string "Story battles allow one gimmick type\n"
	.string "per battle: MEGA, Z-MOVE, DYNAMAX\l"
	.string "or TERA. With CHAOS on, mix them all!\p"
	.string "Turn on CHAOS BATTLES?$"

EasternAurelia_Hall_Text_ChaosEnabled:
	.string "CHAOS BATTLES are ON.\n"
	.string "Every gimmick is yours in one battle.\p"
	.string "Ask me again to switch it off.$"

EasternAurelia_Hall_Text_ChaosDisableAsk:
	.string "CHAOS BATTLES are ON.\n"
	.string "Restore the one-gimmick story rule?$"

EasternAurelia_Hall_Text_ChaosDisabled:
	.string "CHAOS BATTLES are OFF.\n"
	.string "One gimmick type per battle again.$"

EasternAurelia_Hall_Text_ChaosKept:
	.string "Very well. Settings unchanged.$"

EasternAurelia_Hall_Text_DeskMirage:
	.string "MIRAGE CITY desk -- Badge 9\n"
	.string "LEADER IRIS · PSYCHIC · Mirage Badge\p"
	.string "Mirage floats on heat-haze plains.\n"
	.string "Thought itself bends like glass.$"

EasternAurelia_Hall_Text_DeskVerdantis:
	.string "VERDANTIS CITY desk -- Badge 10\n"
	.string "LEADER CELIA · BUG · Jungle Badge\p"
	.string "Canopy cities of living wood.\n"
	.string "Buzzing markets never sleep.$"

EasternAurelia_Hall_Text_DeskObsidian:
	.string "OBSIDIAN CITY desk -- Badge 11\n"
	.string "LEADER NOCTIS · DARK · Obsidian Badge\p"
	.string "Night markets carved in black glass.\n"
	.string "Honest deals prefer the dark.$"

EasternAurelia_Hall_Text_DeskAstral:
	.string "ASTRAL CITY desk -- Badge 12\n"
	.string "LEADER DRAKE · DRAGON · Astral / Tera\p"
	.string "Cliff spires under aurora fire.\n"
	.string "Tera crystal first sang here.$"

EasternAurelia_Hall_Text_DeskTidymoon:
	.string "TIDYMOON CITY desk -- Badge 13\n"
	.string "LEADER LUNA · FAIRY · Moon Badge\p"
	.string "Tide gardens lit by pale moons.\n"
	.string "Wish-makers leave ribbons at dusk.$"

EasternAurelia_Hall_Text_DeskEon:
	.string "EON CITY desk -- Badge 14\n"
	.string "LEADER MORRIGAN · GHOST · Eon Badge\p"
	.string "Clocktower streets between eras.\n"
	.string "Echoes train as partners here.$"

EasternAurelia_Hall_Text_DeskGenesis:
	.string "GENESIS CITY desk -- Badge 15\n"
	.string "COLLEAGUE · NORMAL · Genesis Badge\p"
	.string "The Colleague's lab-city hub.\n"
	.string "Potential is measured in battle.$"

EasternAurelia_Hall_Text_DeskSummit:
	.string "AURELIA SUMMIT (east) -- Badge 16\n"
	.string "MENTOR · ROCK · Ascension Badge\p"
	.string "Eastern peak of the old road.\n"
	.string "Stone remembers every ascent.$"

EasternAurelia_Hall_Text_DeskVenom:
	.string "VENOM HOLLOW desk -- Badge 17\n"
	.string "VESPER · POISON · Venom Badge\p"
	.string "Marsh lanterns over toxic bloom.\n"
	.string "Antidotes sell better than gold.$"

EasternAurelia_Hall_Text_DeskTerracotta:
	.string "TERRACOTTA MESA desk -- Badge 18\n"
	.string "TERRA · GROUND · Terra Badge\p"
	.string "Red clay mesas and buried ruins.\n"
	.string "The last type closes the circle.$"
EasternAurelia_Hall_Text_HallDirectory:
	.string "EASTERN AURELIA HALL\n"
	.string "City desks 9-18 · all remaining types\p"
	.string "Access: Fly to BATTLE FRONTIER, then\n"
	.string "ask the Reception Gate greeter.\p"
	.string "Same greeter warps to WORLD TOURNAMENT.$"
