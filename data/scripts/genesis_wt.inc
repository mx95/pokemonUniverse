@ GENESIS: World Tournament bracket (facility + shared helpers)

Genesis_EventScript_AnnounceWTRules::
	callnative Genesis_GetWTRuleIndex
	goto_if_eq VAR_RESULT, 0, Genesis_EventScript_AnnounceWTMorning
	goto_if_eq VAR_RESULT, 1, Genesis_EventScript_AnnounceWTDay
	msgbox Genesis_Text_WTRuleNight, MSGBOX_DEFAULT
	return
Genesis_EventScript_AnnounceWTMorning::
	msgbox Genesis_Text_WTRuleMorning, MSGBOX_DEFAULT
	return
Genesis_EventScript_AnnounceWTDay::
	msgbox Genesis_Text_WTRuleDay, MSGBOX_DEFAULT
	return

Genesis_EventScript_WorldTournament::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, Genesis_EventScript_WTNotChampion
	goto_if_set FLAG_GENESIS_WT_CLEARED, Genesis_EventScript_WTRematch
	msgbox Genesis_Text_WTOffer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_WTDecline
	setflag FLAG_GENESIS_WT_INTRO
	call Genesis_EventScript_AnnounceWTRules
	msgbox Genesis_Text_WTRound1, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_MENTOR, Genesis_Text_WTRoundLose
	msgbox Genesis_Text_WTRound2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, Genesis_Text_WTRoundLose
	msgbox Genesis_Text_WTSemis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, Genesis_Text_WTRoundLose
	msgbox Genesis_Text_WTFinal, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_WT_CHAMP, Genesis_Text_WTDefeat
	setflag FLAG_GENESIS_WT_CLEARED
	setflag FLAG_GENESIS_ACHIEVEMENT_WT
	setvar VAR_0x8004, 30
	special GiveFrontierBattlePoints
	msgbox Genesis_Text_WTBP, MSGBOX_DEFAULT
	msgbox Genesis_Text_WTAfter, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_WTNotChampion::
	msgbox Genesis_Text_WTNotChampion, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_WTDecline::
	msgbox Genesis_Text_WTDecline, MSGBOX_DEFAULT
	release
	end

Genesis_EventScript_WTRematch::
	msgbox Genesis_Text_WTRematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_EventScript_WTDecline
	call Genesis_EventScript_AnnounceWTRules
	callnative Genesis_GetWTRuleIndex
	goto_if_eq VAR_RESULT, 0, Genesis_EventScript_WTRematchMentor
	goto_if_eq VAR_RESULT, 1, Genesis_EventScript_WTRematchSteven
	msgbox Genesis_Text_WTFinal, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_WT_CHAMP, Genesis_Text_WTDefeat
	goto Genesis_EventScript_WTRematchReward

Genesis_EventScript_WTRematchMentor::
	msgbox Genesis_Text_WTRound1, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_MENTOR, Genesis_Text_WTRoundLose
	goto Genesis_EventScript_WTRematchReward

Genesis_EventScript_WTRematchSteven::
	msgbox Genesis_Text_WTRound2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, Genesis_Text_WTRoundLose
	goto Genesis_EventScript_WTRematchReward

Genesis_EventScript_WTRematchReward::
	setvar VAR_0x8004, 12
	special GiveFrontierBattlePoints
	msgbox Genesis_Text_WTBP, MSGBOX_DEFAULT
	release
	end

Genesis_Text_WTOffer:
	.string "WORLD TOURNAMENT registration.\n"
	.string "Four-round Champions bracket.\p"
	.string "Enter the WORLD TOURNAMENT?$"

Genesis_Text_WTNotChampion:
	.string "WORLD TOURNAMENT is Champions only.\n"
	.string "Clear the POKéMON LEAGUE first.$"

Genesis_Text_WTDecline:
	.string "Come back when your team is ready.$"

Genesis_Text_WTRound1:
	.string "Round 1--your GENESIS MENTOR!$"

Genesis_Text_WTRound2:
	.string "Round 2--ASTRA of the Summit!$"

Genesis_Text_WTSemis:
	.string "Semifinal--WALLACE of the waves!$"

Genesis_Text_WTFinal:
	.string "Final--VICTOR claims the crown!$"

Genesis_Text_WTRoundLose:
	.string "The bracket ends here… Try again!$"

Genesis_Text_WTDefeat:
	.string "Incredible… The Tower crowns you!$"

Genesis_Text_WTAfter:
	.string "Bracket cleared! Rematches rotate\n"
	.string "daily--ask the attendant for rules.$"

Genesis_Text_WTRematch:
	.string "WORLD TOURNAMENT exhibition rematch?\n"
	.string "Today's challenger awaits!$"

Genesis_Text_WTBP:
	.string "{PLAYER} obtained Battle Points!$"

Genesis_Text_WTRuleMorning:
	.string "Rule--Dawn Bracket: open with your\n"
	.string "first slot. Mentors watch closely.$"

Genesis_Text_WTRuleDay:
	.string "Rule--Solar Bracket: expect aggressive\n"
	.string "leads and mid-round switches.$"

Genesis_Text_WTRuleNight:
	.string "Rule--Eclipse Bracket: pressure from\n"
	.string "status and late-game finishers.$"
