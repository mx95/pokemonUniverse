@ GENESIS: Shared story helpers (level cap, save, quest board)

Genesis_EventScript_UpdateLevelCap::
	callnative Genesis_UpdateLevelCap
	return

Genesis_EventScript_InitSave::
	callnative Genesis_InitSave
	return

Genesis_EventScript_TryUnlockGenesisForm::
	callnative Genesis_TryUnlockGenesisForm
	return

Genesis_EventScript_QuestBoard::
	lock
	faceplayer
	setflag FLAG_GENESIS_QUEST_BOARD_SEEN
	setflag FLAG_GENESIS_ACHIEVEMENT_QUEST_BOARD
	msgbox Genesis_Text_QuestBoardHeader, MSGBOX_DEFAULT
	call Genesis_EventScript_QuestBoard_PrintActs
	call Genesis_EventScript_QuestBoard_PrintPuzzles
	call Genesis_EventScript_QuestBoard_PrintSide
	call Genesis_EventScript_QuestBoard_PrintPostgame
	msgbox Genesis_Text_QuestBoardFooter, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_QuestBoard_PrintSide::
	goto_if_set FLAG_GENESIS_METAGROSS_QUEST_INTRO, Genesis_EventScript_QuestBoard_SideShow
	goto_if_set FLAG_GENESIS_WEATHER_GUIDE_SEEN, Genesis_EventScript_QuestBoard_SideShow
	goto_if_set FLAG_GENESIS_ECLIPSE_ARCHIVE_OPEN, Genesis_EventScript_QuestBoard_SideShow
	goto_if_set FLAG_GENESIS_RIVAL_BEAT_ACT2, Genesis_EventScript_QuestBoard_SideShow
	return
Genesis_EventScript_QuestBoard_SideShow::
	msgbox Genesis_Text_Quest_SideHeader, MSGBOX_DEFAULT
	goto_if_unset FLAG_GENESIS_METAGROSS_QUEST_INTRO, Genesis_EventScript_QuestBoard_KaiLine
	goto_if_set FLAG_GENESIS_METAGROSS_CAUGHT, Genesis_EventScript_QuestBoard_MetagrossDoneLine
	msgbox Genesis_Text_Quest_MetagrossOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_KaiLine
Genesis_EventScript_QuestBoard_MetagrossDoneLine::
	msgbox Genesis_Text_Quest_MetagrossDone, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_KaiLine::
	goto_if_unset FLAG_GENESIS_RIVAL_BEAT_ACT2, Genesis_EventScript_QuestBoard_WeatherLine
	goto_if_set FLAG_GENESIS_RIVAL_BEAT_LEAGUE, Genesis_EventScript_QuestBoard_KaiDone
	msgbox Genesis_Text_Quest_KaiOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_WeatherLine
Genesis_EventScript_QuestBoard_KaiDone::
	msgbox Genesis_Text_Quest_KaiDone, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_WeatherLine::
	goto_if_unset FLAG_GENESIS_WEATHER_GUIDE_SEEN, Genesis_EventScript_QuestBoard_ArchiveLine
	goto_if_set FLAG_GENESIS_WEATHER_RARE_DONE, Genesis_EventScript_QuestBoard_WeatherDone
	msgbox Genesis_Text_Quest_WeatherOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_ArchiveLine
Genesis_EventScript_QuestBoard_WeatherDone::
	msgbox Genesis_Text_Quest_WeatherDone, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_ArchiveLine::
	goto_if_unset FLAG_GENESIS_ECLIPSE_ARCHIVE_OPEN, Genesis_EventScript_QuestBoard_SideReturn
	goto_if_set FLAG_GENESIS_ECLIPSE_ARCHIVE_READ, Genesis_EventScript_QuestBoard_ArchiveDone
	msgbox Genesis_Text_Quest_ArchiveOpen, MSGBOX_DEFAULT
	return
Genesis_EventScript_QuestBoard_ArchiveDone::
	msgbox Genesis_Text_Quest_ArchiveDone, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_SideReturn::
	return

Genesis_EventScript_AchievementBoard::
	lock
	faceplayer
	call Genesis_EventScript_SyncAchievements
	msgbox Genesis_Text_AchievementHeader, MSGBOX_DEFAULT
	goto_if_set FLAG_GENESIS_ACHIEVEMENT_QUEST_BOARD, Genesis_EventScript_Ach_QuestDone
	msgbox Genesis_Text_Ach_QuestOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_Ach_Ace
Genesis_EventScript_Ach_QuestDone::
	msgbox Genesis_Text_Ach_QuestDone, MSGBOX_DEFAULT
Genesis_EventScript_Ach_Ace::
	goto_if_set FLAG_GENESIS_ACHIEVEMENT_VERDANT_ACE, Genesis_EventScript_Ach_AceDone
	msgbox Genesis_Text_Ach_AceOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_Ach_Eclipse
Genesis_EventScript_Ach_AceDone::
	msgbox Genesis_Text_Ach_AceDone, MSGBOX_DEFAULT
Genesis_EventScript_Ach_Eclipse::
	goto_if_set FLAG_GENESIS_ACHIEVEMENT_ECLIPSE, Genesis_EventScript_Ach_EclipseDone
	msgbox Genesis_Text_Ach_EclipseOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_Ach_Champion
Genesis_EventScript_Ach_EclipseDone::
	msgbox Genesis_Text_Ach_EclipseDone, MSGBOX_DEFAULT
Genesis_EventScript_Ach_Champion::
	goto_if_set FLAG_GENESIS_ACHIEVEMENT_CHAMPION, Genesis_EventScript_Ach_ChampionDone
	msgbox Genesis_Text_Ach_ChampionOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_Ach_WT
Genesis_EventScript_Ach_ChampionDone::
	msgbox Genesis_Text_Ach_ChampionDone, MSGBOX_DEFAULT
Genesis_EventScript_Ach_WT::
	goto_if_set FLAG_GENESIS_ACHIEVEMENT_WT, Genesis_EventScript_Ach_WTDone
	msgbox Genesis_Text_Ach_WTOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_Ach_Legends
Genesis_EventScript_Ach_WTDone::
	msgbox Genesis_Text_Ach_WTDone, MSGBOX_DEFAULT
Genesis_EventScript_Ach_Legends::
	goto_if_set FLAG_GENESIS_ACHIEVEMENT_LEGENDS, Genesis_EventScript_Ach_LegendsDone
	msgbox Genesis_Text_Ach_LegendsOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_Ach_Metagross
Genesis_EventScript_Ach_LegendsDone::
	msgbox Genesis_Text_Ach_LegendsDone, MSGBOX_DEFAULT
Genesis_EventScript_Ach_Metagross::
	goto_if_set FLAG_GENESIS_ACHIEVEMENT_METAGROSS, Genesis_EventScript_Ach_MetagrossDone
	msgbox Genesis_Text_Ach_MetagrossOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_Ach_Puzzles
Genesis_EventScript_Ach_MetagrossDone::
	msgbox Genesis_Text_Ach_MetagrossDone, MSGBOX_DEFAULT
Genesis_EventScript_Ach_Puzzles::
	goto_if_set FLAG_GENESIS_ACHIEVEMENT_PUZZLES, Genesis_EventScript_Ach_PuzzlesDone
	msgbox Genesis_Text_Ach_PuzzlesOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_Ach_TypeMaster
Genesis_EventScript_Ach_PuzzlesDone::
	msgbox Genesis_Text_Ach_PuzzlesDone, MSGBOX_DEFAULT
Genesis_EventScript_Ach_TypeMaster::
	goto_if_set FLAG_GENESIS_ACHIEVEMENT_TYPE_MASTER, Genesis_EventScript_Ach_TypeMasterDone
	msgbox Genesis_Text_Ach_TypeMasterOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_Ach_Footer
Genesis_EventScript_Ach_TypeMasterDone::
	msgbox Genesis_Text_Ach_TypeMasterDone, MSGBOX_DEFAULT
Genesis_EventScript_Ach_Footer::
	msgbox Genesis_Text_AchievementFooter, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_SyncAchievements::
	goto_if_set FLAG_GENESIS_QUEST_BOARD_SEEN, Genesis_EventScript_SyncAch_Quest
	goto Genesis_EventScript_SyncAch_Eclipse
Genesis_EventScript_SyncAch_Quest::
	setflag FLAG_GENESIS_ACHIEVEMENT_QUEST_BOARD
Genesis_EventScript_SyncAch_Eclipse::
	goto_if_unset FLAG_GENESIS_ECLIPSE_DEFEATED, Genesis_EventScript_SyncAch_Champion
	setflag FLAG_GENESIS_ACHIEVEMENT_ECLIPSE
Genesis_EventScript_SyncAch_Champion::
	goto_if_unset FLAG_SYS_GAME_CLEAR, Genesis_EventScript_SyncAch_WT
	setflag FLAG_GENESIS_ACHIEVEMENT_CHAMPION
Genesis_EventScript_SyncAch_WT::
	goto_if_unset FLAG_GENESIS_WT_CLEARED, Genesis_EventScript_SyncAch_Legends
	setflag FLAG_GENESIS_ACHIEVEMENT_WT
Genesis_EventScript_SyncAch_Legends::
	goto_if_unset FLAG_GENESIS_FORM_UNLOCKED, Genesis_EventScript_SyncAch_Metagross
	setflag FLAG_GENESIS_ACHIEVEMENT_LEGENDS
Genesis_EventScript_SyncAch_Metagross::
	goto_if_unset FLAG_GENESIS_METAGROSS_CAUGHT, Genesis_EventScript_SyncAch_Puzzles
	setflag FLAG_GENESIS_ACHIEVEMENT_METAGROSS
Genesis_EventScript_SyncAch_Puzzles::
	goto_if_unset FLAG_GENESIS_PUZZLE_CRYSTAL_RELAY, Genesis_EventScript_SyncAch_TypeMaster
	goto_if_unset FLAG_GENESIS_PUZZLE_ECHO_SEALED, Genesis_EventScript_SyncAch_TypeMaster
	goto_if_unset FLAG_GENESIS_PUZZLE_PHENOMENA, Genesis_EventScript_SyncAch_TypeMaster
	goto_if_unset FLAG_GENESIS_PUZZLE_ECLIPSE_CIPHER, Genesis_EventScript_SyncAch_TypeMaster
	setflag FLAG_GENESIS_ACHIEVEMENT_PUZZLES
Genesis_EventScript_SyncAch_TypeMaster::
	goto_if_unset FLAG_GENESIS_BADGE_18_GET, Genesis_EventScript_SyncAch_Return
	goto_if_unset FLAG_GENESIS_BADGE_17_GET, Genesis_EventScript_SyncAch_Return
	goto_if_unset FLAG_GENESIS_BADGE_16_GET, Genesis_EventScript_SyncAch_Return
	goto_if_unset FLAG_GENESIS_BADGE_15_GET, Genesis_EventScript_SyncAch_Return
	goto_if_unset FLAG_GENESIS_BADGE_14_GET, Genesis_EventScript_SyncAch_Return
	goto_if_unset FLAG_GENESIS_BADGE_13_GET, Genesis_EventScript_SyncAch_Return
	goto_if_unset FLAG_GENESIS_BADGE_12_GET, Genesis_EventScript_SyncAch_Return
	goto_if_unset FLAG_GENESIS_BADGE_11_GET, Genesis_EventScript_SyncAch_Return
	goto_if_unset FLAG_GENESIS_BADGE_10_GET, Genesis_EventScript_SyncAch_Return
	goto_if_unset FLAG_GENESIS_BADGE_09_GET, Genesis_EventScript_SyncAch_Return
	setflag FLAG_GENESIS_ACHIEVEMENT_TYPE_MASTER
Genesis_EventScript_SyncAch_Return::
	return

Genesis_EventScript_QuestBoard_PrintActs::
	goto_if_set FLAG_GENESIS_ACT1_FOREST_DONE, Genesis_EventScript_QuestBoard_Act1Done
	msgbox Genesis_Text_Quest_Act1Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_Act2
Genesis_EventScript_QuestBoard_Act1Done::
	msgbox Genesis_Text_Quest_Act1Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_Act2::
	goto_if_set FLAG_GENESIS_ACT2_DONE, Genesis_EventScript_QuestBoard_Act2Done
	msgbox Genesis_Text_Quest_Act2Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_Act3
Genesis_EventScript_QuestBoard_Act2Done::
	msgbox Genesis_Text_Quest_Act2Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_Act3::
	goto_if_set FLAG_GENESIS_ACT3_DONE, Genesis_EventScript_QuestBoard_Act3Done
	msgbox Genesis_Text_Quest_Act3Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_Act4
Genesis_EventScript_QuestBoard_Act3Done::
	msgbox Genesis_Text_Quest_Act3Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_Act4::
	goto_if_set FLAG_GENESIS_ACT4_DONE, Genesis_EventScript_QuestBoard_Act4Done
	msgbox Genesis_Text_Quest_Act4Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_Eclipse
Genesis_EventScript_QuestBoard_Act4Done::
	msgbox Genesis_Text_Quest_Act4Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_Eclipse::
	goto_if_set FLAG_GENESIS_ECLIPSE_DEFEATED, Genesis_EventScript_QuestBoard_EclipseDone
	msgbox Genesis_Text_Quest_EclipseOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_Act5
Genesis_EventScript_QuestBoard_EclipseDone::
	msgbox Genesis_Text_Quest_EclipseDone, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_Act5::
	goto_if_set FLAG_GENESIS_ACT5_DONE, Genesis_EventScript_QuestBoard_Act5Done
	msgbox Genesis_Text_Quest_Act5Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_Act6
Genesis_EventScript_QuestBoard_Act5Done::
	msgbox Genesis_Text_Quest_Act5Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_Act6::
	goto_if_set FLAG_GENESIS_ACT6_DONE, Genesis_EventScript_QuestBoard_Act6Done
	msgbox Genesis_Text_Quest_Act6Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_Act7
Genesis_EventScript_QuestBoard_Act6Done::
	msgbox Genesis_Text_Quest_Act6Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_Act7::
	goto_if_set FLAG_GENESIS_ACT7_DONE, Genesis_EventScript_QuestBoard_Act7Done
	msgbox Genesis_Text_Quest_Act7Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_League
Genesis_EventScript_QuestBoard_Act7Done::
	msgbox Genesis_Text_Quest_Act7Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_League::
	goto_if_set FLAG_SYS_GAME_CLEAR, Genesis_EventScript_QuestBoard_LeagueDone
	msgbox Genesis_Text_Quest_LeagueOpen, MSGBOX_DEFAULT
	return
Genesis_EventScript_QuestBoard_LeagueDone::
	msgbox Genesis_Text_Quest_LeagueDone, MSGBOX_DEFAULT
	return

Genesis_EventScript_QuestBoard_PrintPuzzles::
	goto_if_unset FLAG_GENESIS_ACT2_DONE, Genesis_EventScript_QuestBoard_PuzzlesSkip
	msgbox Genesis_Text_Quest_PuzzlesHeader, MSGBOX_DEFAULT
	goto_if_set FLAG_GENESIS_PUZZLE_CRYSTAL_RELAY, Genesis_EventScript_QuestBoard_Puzzle1Done
	msgbox Genesis_Text_Quest_Puzzle1Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_Puzzle2
Genesis_EventScript_QuestBoard_Puzzle1Done::
	msgbox Genesis_Text_Quest_Puzzle1Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_Puzzle2::
	goto_if_set FLAG_GENESIS_PUZZLE_ECHO_SEALED, Genesis_EventScript_QuestBoard_Puzzle2Done
	msgbox Genesis_Text_Quest_Puzzle2Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_Puzzle3
Genesis_EventScript_QuestBoard_Puzzle2Done::
	msgbox Genesis_Text_Quest_Puzzle2Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_Puzzle3::
	goto_if_set FLAG_GENESIS_PUZZLE_PHENOMENA, Genesis_EventScript_QuestBoard_Puzzle3Done
	msgbox Genesis_Text_Quest_Puzzle3Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_Puzzle4
Genesis_EventScript_QuestBoard_Puzzle3Done::
	msgbox Genesis_Text_Quest_Puzzle3Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_Puzzle4::
	goto_if_set FLAG_GENESIS_PUZZLE_ECLIPSE_CIPHER, Genesis_EventScript_QuestBoard_Puzzle4Done
	msgbox Genesis_Text_Quest_Puzzle4Open, MSGBOX_DEFAULT
	return
Genesis_EventScript_QuestBoard_Puzzle4Done::
	msgbox Genesis_Text_Quest_Puzzle4Done, MSGBOX_DEFAULT
	return
Genesis_EventScript_QuestBoard_PuzzlesSkip::
	return

Genesis_EventScript_QuestBoard_PrintPostgame::
	goto_if_unset FLAG_SYS_GAME_CLEAR, Genesis_EventScript_QuestBoard_PostSkip
	msgbox Genesis_Text_Quest_PostHeader, MSGBOX_DEFAULT
	call Genesis_EventScript_QuestBoard_PrintEasternBadges
	goto Genesis_EventScript_QuestBoard_Legends

Genesis_EventScript_QuestBoard_PrintEasternBadges::
	goto_if_set FLAG_GENESIS_BADGE_09_GET, Genesis_EventScript_QuestBoard_B09Done
	msgbox Genesis_Text_Quest_B09Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_B10
Genesis_EventScript_QuestBoard_B09Done::
	msgbox Genesis_Text_Quest_B09Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_B10::
	goto_if_set FLAG_GENESIS_BADGE_10_GET, Genesis_EventScript_QuestBoard_B10Done
	msgbox Genesis_Text_Quest_B10Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_B11
Genesis_EventScript_QuestBoard_B10Done::
	msgbox Genesis_Text_Quest_B10Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_B11::
	goto_if_set FLAG_GENESIS_BADGE_11_GET, Genesis_EventScript_QuestBoard_B11Done
	msgbox Genesis_Text_Quest_B11Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_B12
Genesis_EventScript_QuestBoard_B11Done::
	msgbox Genesis_Text_Quest_B11Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_B12::
	goto_if_set FLAG_GENESIS_BADGE_12_GET, Genesis_EventScript_QuestBoard_B12Done
	msgbox Genesis_Text_Quest_B12Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_B13
Genesis_EventScript_QuestBoard_B12Done::
	msgbox Genesis_Text_Quest_B12Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_B13::
	goto_if_set FLAG_GENESIS_BADGE_13_GET, Genesis_EventScript_QuestBoard_B13Done
	msgbox Genesis_Text_Quest_B13Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_B14
Genesis_EventScript_QuestBoard_B13Done::
	msgbox Genesis_Text_Quest_B13Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_B14::
	goto_if_set FLAG_GENESIS_BADGE_14_GET, Genesis_EventScript_QuestBoard_B14Done
	msgbox Genesis_Text_Quest_B14Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_B15
Genesis_EventScript_QuestBoard_B14Done::
	msgbox Genesis_Text_Quest_B14Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_B15::
	goto_if_set FLAG_GENESIS_BADGE_15_GET, Genesis_EventScript_QuestBoard_B15Done
	msgbox Genesis_Text_Quest_B15Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_B16
Genesis_EventScript_QuestBoard_B15Done::
	msgbox Genesis_Text_Quest_B15Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_B16::
	goto_if_set FLAG_GENESIS_BADGE_16_GET, Genesis_EventScript_QuestBoard_B16Done
	msgbox Genesis_Text_Quest_B16Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_B17
Genesis_EventScript_QuestBoard_B16Done::
	msgbox Genesis_Text_Quest_B16Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_B17::
	goto_if_set FLAG_GENESIS_BADGE_17_GET, Genesis_EventScript_QuestBoard_B17Done
	msgbox Genesis_Text_Quest_B17Open, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_B18
Genesis_EventScript_QuestBoard_B17Done::
	msgbox Genesis_Text_Quest_B17Done, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_B18::
	goto_if_set FLAG_GENESIS_BADGE_18_GET, Genesis_EventScript_QuestBoard_B18Done
	msgbox Genesis_Text_Quest_B18Open, MSGBOX_DEFAULT
	return
Genesis_EventScript_QuestBoard_B18Done::
	msgbox Genesis_Text_Quest_B18Done, MSGBOX_DEFAULT
	return

Genesis_EventScript_QuestBoard_Legends::
	goto_if_set FLAG_GENESIS_FORM_UNLOCKED, Genesis_EventScript_QuestBoard_LegendsDone
	msgbox Genesis_Text_Quest_LegendsOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_WT
Genesis_EventScript_QuestBoard_LegendsDone::
	msgbox Genesis_Text_Quest_LegendsDone, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_WT::
	goto_if_set FLAG_GENESIS_WT_CLEARED, Genesis_EventScript_QuestBoard_WTDone
	msgbox Genesis_Text_Quest_WTOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_Chaos
Genesis_EventScript_QuestBoard_WTDone::
	msgbox Genesis_Text_Quest_WTDone, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_Chaos::
	goto_if_set FLAG_GENESIS_CHAOS_BATTLES, Genesis_EventScript_QuestBoard_ChaosOn
	msgbox Genesis_Text_Quest_ChaosOff, MSGBOX_DEFAULT
	return
Genesis_EventScript_QuestBoard_ChaosOn::
	msgbox Genesis_Text_Quest_ChaosOn, MSGBOX_DEFAULT
	return
Genesis_EventScript_QuestBoard_PostSkip::
	return

Genesis_Text_QuestBoardHeader:
	.string "AURELIA QUEST BOARD\n"
	.string "Active missions:$"

Genesis_Text_Quest_Act1Open:
	.string "- Investigate Lumen Forest crystals.$"

Genesis_Text_Quest_Act1Done:
	.string "- Lumen Forest crystals: complete.$"

Genesis_Text_Quest_Act2Open:
	.string "- Stop TEAM ECLIPSE's crystal hunt.$"

Genesis_Text_Quest_Act2Done:
	.string "- Early Eclipse crystal hunt: complete.$"

Genesis_Text_Quest_Act3Open:
	.string "- Trace Eclipse through the ancient falls.$"

Genesis_Text_Quest_Act3Done:
	.string "- Ancient falls Eclipse beat: complete.$"

Genesis_Text_Quest_Act4Open:
	.string "- Confront Eclipse in the deep cavern.$"

Genesis_Text_Quest_Act4Done:
	.string "- Deep cavern Eclipse beat: complete.$"

Genesis_Text_Quest_EclipseOpen:
	.string "- End TEAM ECLIPSE's Genesis Engine plot.$"

Genesis_Text_Quest_EclipseDone:
	.string "- TEAM ECLIPSE defeated.$"

Genesis_Text_Quest_Act5Open:
	.string "- Investigate the Space Center anomaly.$"

Genesis_Text_Quest_Act5Done:
	.string "- Space Center anomaly: complete.$"

Genesis_Text_Quest_Act6Open:
	.string "- Climb Sky Pillar; stabilize phenomena.$"

Genesis_Text_Quest_Act6Done:
	.string "- Sky Pillar phenomena: complete.$"

Genesis_Text_Quest_Act7Open:
	.string "- Raid the Eclipse hideout climax.$"

Genesis_Text_Quest_Act7Done:
	.string "- Eclipse hideout climax: complete.$"

Genesis_Text_Quest_LeagueOpen:
	.string "- Challenge the POKéMON LEAGUE.$"

Genesis_Text_Quest_LeagueDone:
	.string "- POKéMON LEAGUE: Champion!$"

Genesis_Text_Quest_PuzzlesHeader:
	.string "Puzzle setpieces:$"

Genesis_Text_Quest_Puzzle1Open:
	.string "- Crystal Relay (New Mauville).$"

Genesis_Text_Quest_Puzzle1Done:
	.string "- Crystal Relay: complete.$"

Genesis_Text_Quest_Puzzle2Open:
	.string "- Echo Sealed (Sealed Chamber).$"

Genesis_Text_Quest_Puzzle2Done:
	.string "- Echo Sealed: complete.$"

Genesis_Text_Quest_Puzzle3Open:
	.string "- Phenomena Lock (Sky Pillar).$"

Genesis_Text_Quest_Puzzle3Done:
	.string "- Phenomena Lock: complete.$"

Genesis_Text_Quest_Puzzle4Open:
	.string "- Eclipse Cipher (Hideout).$"

Genesis_Text_Quest_Puzzle4Done:
	.string "- Eclipse Cipher: complete.$"

Genesis_Text_Quest_PostHeader:
	.string "Postgame:$"

Genesis_Text_Quest_B09Open:
	.string "- Mirage City: beat IRIS (badge 9).$"

Genesis_Text_Quest_B09Done:
	.string "- Mirage City (IRIS): complete.$"

Genesis_Text_Quest_B10Open:
	.string "- Verdantis City: beat CELIA (badge 10).$"

Genesis_Text_Quest_B10Done:
	.string "- Verdantis City (CELIA): complete.$"

Genesis_Text_Quest_B11Open:
	.string "- Obsidian City: beat NOCTIS (badge 11).$"

Genesis_Text_Quest_B11Done:
	.string "- Obsidian City (NOCTIS): complete.$"

Genesis_Text_Quest_B12Open:
	.string "- Astral City: beat DRAKE (badge 12 / Tera).$"

Genesis_Text_Quest_B12Done:
	.string "- Astral City (DRAKE): complete.$"

Genesis_Text_Quest_B13Open:
	.string "- Tidymoon City: beat LUNA (badge 13).$"

Genesis_Text_Quest_B13Done:
	.string "- Tidymoon City (LUNA): complete.$"

Genesis_Text_Quest_B14Open:
	.string "- Eon City: beat MORRIGAN (badge 14).$"

Genesis_Text_Quest_B14Done:
	.string "- Eon City (MORRIGAN): complete.$"

Genesis_Text_Quest_B15Open:
	.string "- Genesis City: beat COLLEAGUE (badge 15).$"

Genesis_Text_Quest_B15Done:
	.string "- Genesis City (COLLEAGUE): complete.$"

Genesis_Text_Quest_B16Open:
	.string "- Summit City: beat MENTOR (badge 16).$"

Genesis_Text_Quest_B16Done:
	.string "- Summit City (MENTOR): complete.$"

Genesis_Text_Quest_B17Open:
	.string "- Venom Hollow: beat VESPER (badge 17).$"

Genesis_Text_Quest_B17Done:
	.string "- Venom Hollow (VESPER): complete.$"

Genesis_Text_Quest_B18Open:
	.string "- Terracotta Mesa: beat TERRA (badge 18).$"

Genesis_Text_Quest_B18Done:
	.string "- Terracotta Mesa (TERRA): complete.$"

Genesis_Text_Quest_LegendsOpen:
	.string "- Legend Sanctum (Aethernox / Solara /\l"
	.string "  Genesis).$"

Genesis_Text_Quest_LegendsDone:
	.string "- Legend Sanctum + Genesis Form: done.$"

Genesis_Text_Quest_WTOpen:
	.string "- WORLD TOURNAMENT facility (Reception Gate).$"

Genesis_Text_Quest_WTDone:
	.string "- WORLD TOURNAMENT bracket: cleared.$"

Genesis_Text_Quest_ChaosOff:
	.string "- CHAOS BATTLES: ask Eastern Hall clerk (INFO).$"

Genesis_Text_Quest_ChaosOn:
	.string "- CHAOS BATTLES: ON (multi-gimmick).$"

Genesis_Text_Quest_SideHeader:
	.string "Side missions:$"

Genesis_Text_Quest_MetagrossOpen:
	.string "- New Mauville: stop the AI Mega METAGROSS.$"

Genesis_Text_Quest_MetagrossDone:
	.string "- AI Mega METAGROSS rampage: resolved.$"

Genesis_Text_Quest_WeatherOpen:
	.string "- Weather Institute: learn weather-rare tips.$"

Genesis_Text_Quest_WeatherDone:
	.string "- Weather Institute rare tips: collected.$"

Genesis_Text_Quest_KaiOpen:
	.string "- Rival KAI: finish your three story battles.$"

Genesis_Text_Quest_KaiDone:
	.string "- Rival KAI story battles: complete.$"

Genesis_Text_Quest_ArchiveOpen:
	.string "- Oceanic Museum: open the Eclipse Archive.$"

Genesis_Text_Quest_ArchiveDone:
	.string "- Eclipse Archive: read and sealed.$"

Genesis_Text_QuestBoardFooter:
	.string "Check back as your journey continues.$"

Genesis_Text_AchievementHeader:
	.string "AURELIA ACHIEVEMENT BOARD\n"
	.string "Titles unlocked:$"

Genesis_Text_Ach_QuestOpen:
	.string "- Quest Seeker: check the Quest Board.$"

Genesis_Text_Ach_QuestDone:
	.string "- Quest Seeker: unlocked.$"

Genesis_Text_Ach_AceOpen:
	.string "- Verdant Ace: win Ace doubles post-League.$"

Genesis_Text_Ach_AceDone:
	.string "- Verdant Ace: unlocked.$"

Genesis_Text_Ach_EclipseOpen:
	.string "- Eclipse Breaker: defeat TEAM ECLIPSE.$"

Genesis_Text_Ach_EclipseDone:
	.string "- Eclipse Breaker: unlocked.$"

Genesis_Text_Ach_ChampionOpen:
	.string "- Champion: clear the POKéMON LEAGUE.$"

Genesis_Text_Ach_ChampionDone:
	.string "- Champion: unlocked.$"

Genesis_Text_Ach_WTOpen:
	.string "- Tournament Victor: clear WORLD TOURNAMENT.$"

Genesis_Text_Ach_WTDone:
	.string "- Tournament Victor: unlocked.$"

Genesis_Text_Ach_LegendsOpen:
	.string "- Legend Keeper: finish Legend Sanctum.$"

Genesis_Text_Ach_LegendsDone:
	.string "- Legend Keeper: unlocked.$"

Genesis_Text_Ach_MetagrossOpen:
	.string "- AI Breaker: calm New Mauville METAGROSS.$"

Genesis_Text_Ach_MetagrossDone:
	.string "- AI Breaker: unlocked.$"

Genesis_Text_Ach_PuzzlesOpen:
	.string "- Puzzle Master: clear all four story locks.$"

Genesis_Text_Ach_PuzzlesDone:
	.string "- Puzzle Master: unlocked.$"

Genesis_Text_Ach_TypeMasterOpen:
	.string "- Type Master: claim every Eastern badge.$"

Genesis_Text_Ach_TypeMasterDone:
	.string "- Type Master: unlocked.$"

Genesis_Text_AchievementFooter:
	.string "More titles will appear as AURELIA\n"
	.string "opens its sealed roads.$"
