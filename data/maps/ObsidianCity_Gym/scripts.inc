@ OBSIDIAN CITY GYM -- Dark / NOCTIS / Badge 11 (moved from EasternAurelia_Hall desk).
@ Needs the previous badge (CELIA); Tera unlock stays with DRAKE (Badge 12) in the Eastern Hall.

ObsidianCity_Gym_MapScripts::
	.byte 0

ObsidianCity_Gym_EventScript_Noctis::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_10_GET, ObsidianCity_Gym_EventScript_NeedPrev
	goto_if_set FLAG_GENESIS_BADGE_11_GET, ObsidianCity_Gym_EventScript_NoctisDone
	msgbox ObsidianCity_Gym_Text_NoctisIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ObsidianCity_Gym_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_NOCTIS, ObsidianCity_Gym_Text_NoctisDefeat
	message ObsidianCity_Gym_Text_GotObsidianBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_11_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox ObsidianCity_Gym_Text_NoctisAfter, MSGBOX_DEFAULT
	release
	end

ObsidianCity_Gym_EventScript_NoctisDone::
	msgbox ObsidianCity_Gym_Text_NoctisDone, MSGBOX_DEFAULT
	release
	end

ObsidianCity_Gym_EventScript_NeedPrev::
	msgbox ObsidianCity_Gym_Text_NeedPrev, MSGBOX_DEFAULT
	release
	end

ObsidianCity_Gym_EventScript_Decline::
	msgbox ObsidianCity_Gym_Text_Decline, MSGBOX_DEFAULT
	release
	end

ObsidianCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_11_GET, ObsidianCity_Gym_EventScript_GymGuidePostVictory
	msgbox ObsidianCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

ObsidianCity_Gym_EventScript_GymGuidePostVictory::
	msgbox ObsidianCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

ObsidianCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_11_GET, ObsidianCity_Gym_EventScript_GymStatueCertified
	goto ObsidianCity_Gym_EventScript_GymStatue
	end

ObsidianCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_11_GET, ObsidianCity_Gym_EventScript_GymStatueCertified
	goto ObsidianCity_Gym_EventScript_GymStatue
	end

ObsidianCity_Gym_EventScript_GymStatueCertified::
	msgbox ObsidianCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

ObsidianCity_Gym_EventScript_GymStatue::
	msgbox ObsidianCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

ObsidianCity_Gym_Text_Decline:
	.string "Return when you can face the dark.$"

ObsidianCity_Gym_Text_NeedPrev:
	.string "NOCTIS: Obsidian stays sealed until\nyou earn CELIA's JUNGLE BADGE.$"

ObsidianCity_Gym_Text_NoctisIntro:
	.string "NOCTIS: OBSIDIAN CITY GYM.\nVolcanic glass. Quiet streets. Night.\pDARK POKéMON answer only the bold.\nStep into the ash--or walk away.$"

ObsidianCity_Gym_Text_NoctisDefeat:
	.string "The night yields…$"

ObsidianCity_Gym_Text_GotObsidianBadge:
	.string "{PLAYER} received the OBSIDIAN BADGE!$"

ObsidianCity_Gym_Text_NoctisAfter:
	.string "NOCTIS: Carry Obsidian's calm into light.\nASTRAL CITY--DRAKE--is next.$"

ObsidianCity_Gym_Text_NoctisDone:
	.string "NOCTIS: Obsidian's vents still glow.\nWalk unafraid of your own shadow.$"

ObsidianCity_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to OBSIDIAN CITY GYM!\pNOCTIS uses DARK-type POKéMON.\pThey're tough against PSYCHIC and\nGHOST, but weak to FIGHTING, BUG,\land FAIRY.\pGo get that OBSIDIAN BADGE!$"

ObsidianCity_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\nThe OBSIDIAN BADGE is yours!\pSeven more desks wait in EASTERN\nAURELIA HALL.$"

ObsidianCity_Gym_Text_GymStatue:
	.string "OBSIDIAN CITY POKéMON GYM$"

ObsidianCity_Gym_Text_GymStatueCertified:
	.string "OBSIDIAN CITY POKéMON GYM\p"
	.string "NOCTIS'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
