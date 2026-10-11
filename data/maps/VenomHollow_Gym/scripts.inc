@ VENOM HOLLOW GYM -- Poison / VESPER / Badge 17 (moved from EasternAurelia_Hall desk).
@ Needs the previous badge (MENTOR).

VenomHollow_Gym_MapScripts::
	.byte 0

VenomHollow_Gym_EventScript_Vesper::
	lock
	faceplayer
	goto_if_unset FLAG_GENESIS_BADGE_16_GET, VenomHollow_Gym_EventScript_NeedPrev
	goto_if_set FLAG_GENESIS_BADGE_17_GET, VenomHollow_Gym_EventScript_VesperDone
	msgbox VenomHollow_Gym_Text_VesperIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VenomHollow_Gym_EventScript_Decline
	trainerbattle_no_intro TRAINER_GENESIS_VESPER, VenomHollow_Gym_Text_VesperDefeat
	message VenomHollow_Gym_Text_GotVenomBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_GENESIS_BADGE_17_GET
	call Genesis_EventScript_UpdateLevelCap
	msgbox VenomHollow_Gym_Text_VesperAfter, MSGBOX_DEFAULT
	release
	end

VenomHollow_Gym_EventScript_VesperDone::
	msgbox VenomHollow_Gym_Text_VesperRematchAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VenomHollow_Gym_EventScript_VesperDoneEnd
	trainerbattle_no_intro TRAINER_GENESIS_VESPER, VenomHollow_Gym_Text_VesperDefeat
VenomHollow_Gym_EventScript_VesperDoneEnd::
	msgbox VenomHollow_Gym_Text_VesperDone, MSGBOX_DEFAULT
	release
	end

VenomHollow_Gym_EventScript_NeedPrev::
	msgbox VenomHollow_Gym_Text_NeedPrev, MSGBOX_DEFAULT
	release
	end

VenomHollow_Gym_EventScript_Decline::
	msgbox VenomHollow_Gym_Text_Decline, MSGBOX_DEFAULT
	release
	end

VenomHollow_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_BADGE_17_GET, VenomHollow_Gym_EventScript_GymGuidePostVictory
	msgbox VenomHollow_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

VenomHollow_Gym_EventScript_GymGuidePostVictory::
	msgbox VenomHollow_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

VenomHollow_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_17_GET, VenomHollow_Gym_EventScript_GymStatueCertified
	goto VenomHollow_Gym_EventScript_GymStatue
	end

VenomHollow_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_GENESIS_BADGE_17_GET, VenomHollow_Gym_EventScript_GymStatueCertified
	goto VenomHollow_Gym_EventScript_GymStatue
	end

VenomHollow_Gym_EventScript_GymStatueCertified::
	msgbox VenomHollow_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

VenomHollow_Gym_EventScript_GymStatue::
	msgbox VenomHollow_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

VenomHollow_Gym_Text_Decline:
	.string "Return when the tide of battle calls.$"

VenomHollow_Gym_Text_NeedPrev:
	.string "VESPER: Clear MENTOR's ROCK GYM\n"
	.string "before Venom Hollow opens.$"

VenomHollow_Gym_Text_VesperIntro:
	.string "VESPER: VENOM HOLLOW GYM.\n"
	.string "POISON is honesty--it shows the wound.\p"
	.string "Can you endure my toxins?$"

VenomHollow_Gym_Text_VesperDefeat:
	.string "Your immunity… impressive.$"

VenomHollow_Gym_Text_GotVenomBadge:
	.string "{PLAYER} received the VENOM BADGE!$"

VenomHollow_Gym_Text_VesperAfter:
	.string "VESPER: Hollow clears you.\n"
	.string "Final desk--TERRA of Terracotta Mesa.\p"
	.string "A cunning GENGAR still haunts the mist.$"

VenomHollow_Gym_Text_VesperRematchAsk:
	.string "VESPER: Venom Hollow never forgets a\n"
	.string "rival. Challenge me once more?$"

VenomHollow_Gym_Text_VesperDone:
	.string "VESPER: Read the Venom plaque for\n"
	.string "GENGAR's story, Champion.$"

VenomHollow_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to VENOM HOLLOW GYM!\p"
	.string "VESPER uses POISON-type POKéMON.\p"
	.string "They're tough against GRASS, FIGHTING,\nPOISON, BUG and FAIRY, but weak to\lGROUND and PSYCHIC.\p"
	.string "Go get that VENOM BADGE!$"

VenomHollow_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\n"
	.string "The VENOM BADGE is yours!\p"
	.string "One more desks wait in EASTERN\nAURELIA HALL.$"

VenomHollow_Gym_Text_GymStatue:
	.string "VENOM HOLLOW POKéMON GYM$"

VenomHollow_Gym_Text_GymStatueCertified:
	.string "VENOM HOLLOW POKéMON GYM\p"
	.string "VESPER'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
