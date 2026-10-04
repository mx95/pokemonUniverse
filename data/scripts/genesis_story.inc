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
	msgbox Genesis_Text_QuestBoardHeader, MSGBOX_DEFAULT
	call Genesis_EventScript_QuestBoard_PrintActs
	call Genesis_EventScript_QuestBoard_PrintPuzzles
	call Genesis_EventScript_QuestBoard_PrintPostgame
	msgbox Genesis_Text_QuestBoardFooter, MSGBOX_DEFAULT
	release
	end

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
	goto_if_set FLAG_GENESIS_BADGE_16_GET, Genesis_EventScript_QuestBoard_EasternDone
	msgbox Genesis_Text_Quest_EasternOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_Legends
Genesis_EventScript_QuestBoard_EasternDone::
	msgbox Genesis_Text_Quest_EasternDone, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_Legends::
	goto_if_set FLAG_GENESIS_FORM_UNLOCKED, Genesis_EventScript_QuestBoard_LegendsDone
	msgbox Genesis_Text_Quest_LegendsOpen, MSGBOX_DEFAULT
	goto Genesis_EventScript_QuestBoard_WT
Genesis_EventScript_QuestBoard_LegendsDone::
	msgbox Genesis_Text_Quest_LegendsDone, MSGBOX_DEFAULT
Genesis_EventScript_QuestBoard_WT::
	goto_if_set FLAG_GENESIS_WT_CLEARED, Genesis_EventScript_QuestBoard_WTDone
	msgbox Genesis_Text_Quest_WTOpen, MSGBOX_DEFAULT
	return
Genesis_EventScript_QuestBoard_WTDone::
	msgbox Genesis_Text_Quest_WTDone, MSGBOX_DEFAULT
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

Genesis_Text_Quest_EasternOpen:
	.string "- Eastern Hall badges 9-16.$"

Genesis_Text_Quest_EasternDone:
	.string "- Eastern Hall badges: complete.$"

Genesis_Text_Quest_LegendsOpen:
	.string "- Legend Sanctum (Aethernox / Solara /\l"
	.string "  Genesis).$"

Genesis_Text_Quest_LegendsDone:
	.string "- Legend Sanctum + Genesis Form: done.$"

Genesis_Text_Quest_WTOpen:
	.string "- WORLD TOURNAMENT (Battle Tower lobby).$"

Genesis_Text_Quest_WTDone:
	.string "- WORLD TOURNAMENT bracket: cleared.$"

Genesis_Text_QuestBoardFooter:
	.string "Check back as your journey continues.$"
