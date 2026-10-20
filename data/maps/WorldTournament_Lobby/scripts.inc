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
	msgbox WorldTournament_Lobby_Text_Round1, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_MENTOR, WorldTournament_Lobby_Text_RoundLose
	msgbox WorldTournament_Lobby_Text_Round2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, WorldTournament_Lobby_Text_RoundLose
	msgbox WorldTournament_Lobby_Text_Semis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, WorldTournament_Lobby_Text_RoundLose
	msgbox WorldTournament_Lobby_Text_Final, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_WT_CHAMP, WorldTournament_Lobby_Text_Defeat
	setflag FLAG_GENESIS_WT_CLEARED
	msgbox WorldTournament_Lobby_Text_BP, MSGBOX_DEFAULT
	msgbox WorldTournament_Lobby_Text_After, MSGBOX_DEFAULT
	release
	end

WorldTournament_Lobby_EventScript_Rematch::
	msgbox WorldTournament_Lobby_Text_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, WorldTournament_Lobby_EventScript_Decline
	msgbox WorldTournament_Lobby_Text_Final, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_WT_CHAMP, WorldTournament_Lobby_Text_Defeat
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
	.string "Four-round bracket for Battle Points.\\p"
	.string "Enter the WORLD TOURNAMENT?$"

WorldTournament_Lobby_Text_Round1:
	.string "Round 1--MENTOR opens the bracket!$"

WorldTournament_Lobby_Text_Round2:
	.string "Round 2--ASTRA steps forward!$"

WorldTournament_Lobby_Text_Semis:
	.string "Semifinal--a Frontier legend awaits!$"

WorldTournament_Lobby_Text_Final:
	.string "Final--VICTOR of the WORLD TOURNAMENT!$"

WorldTournament_Lobby_Text_RoundLose:
	.string "The bracket ends here… Try again!$"

WorldTournament_Lobby_Text_Defeat:
	.string "The WORLD TOURNAMENT crown is yours!$"

WorldTournament_Lobby_Text_After:
	.string "Return any time for rematches.\\n"
	.string "The lobby stays open post-Champion.$"

WorldTournament_Lobby_Text_Rematch:
	.string "Rematch VICTOR for Battle Points?$"

WorldTournament_Lobby_Text_BP:
	.string "Battle Points credited--check the\\n"
	.string "Exchange Service Corner outside.$"

WorldTournament_Lobby_Text_NotChamp:
	.string "The WORLD TOURNAMENT opens after you\\n"
	.string "become CHAMPION of Aurelia.$"

WorldTournament_Lobby_Text_Decline:
	.string "When you're ready, the bracket waits.$"

WorldTournament_Lobby_Text_Fan:
	.string "I came from the Battle Tower just for\\n"
	.string "this lobby. The energy is different!$"

WorldTournament_Lobby_Text_Rules:
	.string "Four rounds. No healing between.\\n"
	.string "Bring your best six.$"

WorldTournament_Lobby_Text_Banner:
	.string "WORLD TOURNAMENT LOBBY\\n"
	.string "Eastern Aurelia's postgame bracket$"
