WorldTournament_Lobby_MapScripts::
	.byte 0

WorldTournament_Lobby_EventScript_Attendant::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, WorldTournament_Lobby_EventScript_NotChamp
	goto_if_set FLAG_GENESIS_WT_CLEARED, WorldTournament_Lobby_EventScript_Rematch
	msgbox WorldTournament_Lobby_Text_Offer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, WorldTournament_Lobby_EventScript_Decline
	setflag FLAG_GENESIS_WT_INTRO
	call WorldTournament_Lobby_EventScript_AnnounceRules
	msgbox WorldTournament_Lobby_Text_Round1, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_MENTOR, WorldTournament_Lobby_Text_RoundLose
	msgbox WorldTournament_Lobby_Text_Round2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, WorldTournament_Lobby_Text_RoundLose
	msgbox WorldTournament_Lobby_Text_Semis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, WorldTournament_Lobby_Text_RoundLose
	msgbox WorldTournament_Lobby_Text_Final, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_WT_CHAMP, WorldTournament_Lobby_Text_Defeat
	setflag FLAG_GENESIS_WT_CLEARED
	setflag FLAG_GENESIS_ACHIEVEMENT_WT
	setvar VAR_0x8004, 30
	special GiveFrontierBattlePoints
	msgbox WorldTournament_Lobby_Text_BP, MSGBOX_DEFAULT
	msgbox WorldTournament_Lobby_Text_After, MSGBOX_DEFAULT
	release
	end

WorldTournament_Lobby_EventScript_AnnounceRules::
	callnative Genesis_GetWTRuleIndex
	goto_if_eq VAR_RESULT, 0, WorldTournament_Lobby_EventScript_AnnounceMorning
	goto_if_eq VAR_RESULT, 1, WorldTournament_Lobby_EventScript_AnnounceDay
	msgbox WorldTournament_Lobby_Text_RuleNight, MSGBOX_DEFAULT
	return

WorldTournament_Lobby_EventScript_AnnounceMorning::
	msgbox WorldTournament_Lobby_Text_RuleMorning, MSGBOX_DEFAULT
	return

WorldTournament_Lobby_EventScript_AnnounceDay::
	msgbox WorldTournament_Lobby_Text_RuleDay, MSGBOX_DEFAULT
	return

WorldTournament_Lobby_EventScript_Rematch::
	msgbox WorldTournament_Lobby_Text_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, WorldTournament_Lobby_EventScript_Decline
	call WorldTournament_Lobby_EventScript_AnnounceRules
	callnative Genesis_GetWTRuleIndex
	goto_if_eq VAR_RESULT, 0, WorldTournament_Lobby_EventScript_RematchMentor
	goto_if_eq VAR_RESULT, 1, WorldTournament_Lobby_EventScript_RematchSteven
	goto_if_eq VAR_RESULT, 2, WorldTournament_Lobby_EventScript_RematchWallace
	msgbox WorldTournament_Lobby_Text_Final, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_WT_CHAMP, WorldTournament_Lobby_Text_Defeat
	goto WorldTournament_Lobby_EventScript_RematchReward

WorldTournament_Lobby_EventScript_RematchMentor::
	msgbox WorldTournament_Lobby_Text_Round1, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_MENTOR, WorldTournament_Lobby_Text_RoundLose
	goto WorldTournament_Lobby_EventScript_RematchReward

WorldTournament_Lobby_EventScript_RematchSteven::
	msgbox WorldTournament_Lobby_Text_Round2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, WorldTournament_Lobby_Text_RoundLose
	goto WorldTournament_Lobby_EventScript_RematchReward

WorldTournament_Lobby_EventScript_RematchWallace::
	msgbox WorldTournament_Lobby_Text_Semis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, WorldTournament_Lobby_Text_RoundLose
	goto WorldTournament_Lobby_EventScript_RematchReward

WorldTournament_Lobby_EventScript_RematchReward::
	setvar VAR_0x8004, 12
	special GiveFrontierBattlePoints
	msgbox WorldTournament_Lobby_Text_BP, MSGBOX_DEFAULT
	release
	end

WorldTournament_Lobby_EventScript_NotChamp::
	msgbox WorldTournament_Lobby_Text_NotChamp, MSGBOX_DEFAULT
	release
	end

WorldTournament_Lobby_EventScript_Decline::
	msgbox WorldTournament_Lobby_Text_Decline, MSGBOX_DEFAULT
	release
	end

WorldTournament_Lobby_EventScript_Fan::
	msgbox WorldTournament_Lobby_Text_Fan, MSGBOX_NPC
	end

WorldTournament_Lobby_EventScript_Rules::
	msgbox WorldTournament_Lobby_Text_Rules, MSGBOX_NPC
	end

WorldTournament_Lobby_EventScript_Banner::
	msgbox WorldTournament_Lobby_Text_Banner, MSGBOX_SIGN
	end

WorldTournament_Lobby_Text_Offer:
	.string "WORLD TOURNAMENT attendant.\\n"
	.string "Four rounds: Mentor, ASTRA, ASTRA rematch,\l"
	.string "VICTOR--Battle Points on clear.\\p"
	.string "Enter the WORLD TOURNAMENT?$"

WorldTournament_Lobby_Text_Round1:
	.string "Round 1--the Mentor's trial!$"

WorldTournament_Lobby_Text_Round2:
	.string "Round 2--CHAMPION ASTRA steps in!$"

WorldTournament_Lobby_Text_Semis:
	.string "Semifinal--ASTRA returns for a rematch!$"

WorldTournament_Lobby_Text_Final:
	.string "Final--VICTOR of the WORLD TOURNAMENT!$"

WorldTournament_Lobby_Text_RoundLose:
	.string "The bracket ends here… Try again!$"

WorldTournament_Lobby_Text_Defeat:
	.string "The WORLD TOURNAMENT crown is yours!$"

WorldTournament_Lobby_Text_After:
	.string "Bracket cleared! Return for day-rotating\n"
	.string "exhibition rematches anytime.$"

WorldTournament_Lobby_Text_Rematch:
	.string "WORLD TOURNAMENT exhibition?\n"
	.string "Today's rotating opponent awaits!$"

WorldTournament_Lobby_Text_BP:
	.string "{PLAYER} obtained Battle Points!$"

WorldTournament_Lobby_Text_NotChamp:
	.string "The WORLD TOURNAMENT opens after you\n"
	.string "become CHAMPION of Aurelia.$"

WorldTournament_Lobby_Text_Decline:
	.string "When you're ready, the bracket waits.$"

WorldTournament_Lobby_Text_Fan:
	.string "I came from the Battle Tower just for\n"
	.string "this lobby. Hyper Train in Lumen first!$"

WorldTournament_Lobby_Text_Rules:
	.string "Four rounds. No healing between.\n"
	.string "Bring your best six.\p"
	.string "Rematches rotate by the day--Mentor,\n"
	.string "ASTRA, ASTRA rematch, or VICTOR.$"

WorldTournament_Lobby_Text_Banner:
	.string "WORLD TOURNAMENT LOBBY\n"
	.string "Eastern Aurelia's postgame bracket$"

WorldTournament_Lobby_Text_RuleMorning:
	.string "Rule--Dawn Bracket: open with your\n"
	.string "first slot. Mentors watch closely.$"

WorldTournament_Lobby_Text_RuleDay:
	.string "Rule--Solar Bracket: expect aggressive\n"
	.string "leads and mid-round switches.$"

WorldTournament_Lobby_Text_RuleNight:
	.string "Rule--Eclipse Bracket: pressure from\n"
	.string "status and late-game finishers.$"
