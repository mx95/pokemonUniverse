Genesis_WorldTournament_MapScripts::
	.byte 0

Genesis_WorldTournament_EventScript_Registrar::
	goto Genesis_EventScript_WorldTournament
	end

Genesis_WorldTournament_EventScript_Attendant::
	lock
	faceplayer
	msgbox Genesis_WorldTournament_Text_AttendantIntro, MSGBOX_DEFAULT
	call Genesis_EventScript_AnnounceWTRules
	release
	end

Genesis_WorldTournament_EventScript_Fan::
	msgbox Genesis_WorldTournament_Text_Fan, MSGBOX_NPC
	end

Genesis_WorldTournament_EventScript_Analyst::
	msgbox Genesis_WorldTournament_Text_Analyst, MSGBOX_NPC
	end

Genesis_WorldTournament_EventScript_Nurse::
	lock
	faceplayer
	msgbox Genesis_WorldTournament_Text_Nurse, MSGBOX_DEFAULT
	special HealPlayerParty
	msgbox Genesis_WorldTournament_Text_NurseDone, MSGBOX_DEFAULT
	release
	end

Genesis_WorldTournament_EventScript_RulesBoard::
	lockall
	msgbox Genesis_WorldTournament_Text_RulesBoard, MSGBOX_DEFAULT
	call Genesis_EventScript_AnnounceWTRules
	releaseall
	end

Genesis_WorldTournament_EventScript_ExitClerk::
	lock
	faceplayer
	msgbox Genesis_WorldTournament_Text_ExitOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_WorldTournament_EventScript_ExitStay
	warpsilent MAP_BATTLE_FRONTIER_RECEPTION_GATE, 4, 11
	waitstate
	release
	end

Genesis_WorldTournament_EventScript_ExitStay::
	msgbox Genesis_WorldTournament_Text_ExitStay, MSGBOX_DEFAULT
	release
	end

Genesis_WorldTournament_Text_AttendantIntro:
	.string "WORLD TOURNAMENT desk.\n"
	.string "Today's exhibition rule:$"

Genesis_WorldTournament_Text_Fan:
	.string "Four rounds! Mentor, Astra, Wallace,\n"
	.string "then VICTOR… My pulse is racing!$"

Genesis_WorldTournament_Text_Analyst:
	.string "Rematch challengers rotate by the day.\n"
	.string "Dawn, Solar, or Eclipse brackets…$"

Genesis_WorldTournament_Text_Nurse:
	.string "Tournament nurse. I'll heal your team\n"
	.string "between brackets--no charge.$"

Genesis_WorldTournament_Text_NurseDone:
	.string "Your POKéMON are fighting fit.\n"
	.string "Good luck!$"

Genesis_WorldTournament_Text_RulesBoard:
	.string "WORLD TOURNAMENT RULES\n"
	.string "Champions only. Four-round bracket.\p"
	.string "Battle Points awarded on clear.\n"
	.string "Daily rematch opponents rotate.$"

Genesis_WorldTournament_Text_ExitOffer:
	.string "Return to the Reception Gate?$"

Genesis_WorldTournament_Text_ExitStay:
	.string "The brackets await.$"
