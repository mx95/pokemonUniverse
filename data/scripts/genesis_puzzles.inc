@ GENESIS: Multi-mechanic story puzzles

@ --- Crystal Relay (New Mauville): Blue -> Green -> Red with Crystal ---
Genesis_Puzzle_CrystalRelay_OnBlue::
	goto_if_set FLAG_GENESIS_PUZZLE_CRYSTAL_RELAY, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_CRYSTAL_GOT, Common_EventScript_NopReturn
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_RELAY_BLUE
	return

Genesis_Puzzle_CrystalRelay_OnGreen::
	goto_if_set FLAG_GENESIS_PUZZLE_CRYSTAL_RELAY, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_CRYSTAL_GOT, Common_EventScript_NopReturn
	goto_if_eq VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_RELAY_BLUE, Genesis_Puzzle_CrystalRelay_GreenOk
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_RELAY_NONE
	return
Genesis_Puzzle_CrystalRelay_GreenOk::
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_RELAY_GREEN
	return

Genesis_Puzzle_CrystalRelay_OnRed::
	goto_if_set FLAG_GENESIS_PUZZLE_CRYSTAL_RELAY, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_CRYSTAL_GOT, Common_EventScript_NopReturn
	goto_if_eq VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_RELAY_GREEN, Genesis_Puzzle_CrystalRelay_Complete
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_RELAY_NONE
	msgbox Genesis_Puzzle_Text_RelayReset, MSGBOX_DEFAULT
	return
Genesis_Puzzle_CrystalRelay_Complete::
	setflag FLAG_GENESIS_PUZZLE_CRYSTAL_RELAY
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_RELAY_NONE
	playfanfare MUS_OBTAIN_ITEM
	msgbox Genesis_Puzzle_Text_RelayComplete, MSGBOX_DEFAULT
	waitfanfare
	giveitem ITEM_ABILITY_CAPSULE
	call Genesis_Puzzle_TryMasterReward
	return

@ --- Echo Sealed (Sealed Chamber): braille dig + riddle ---
Genesis_Puzzle_EchoSealed::
	lockall
	goto_if_set FLAG_GENESIS_PUZZLE_ECHO_SEALED, Genesis_Puzzle_EchoSealed_Done
	goto_if_unset FLAG_SYS_BRAILLE_DIG, Genesis_Puzzle_EchoSealed_NeedDig
	goto_if_unset FLAG_GENESIS_ACT3_DONE, Genesis_Puzzle_EchoSealed_NeedAct
	msgbox Genesis_Puzzle_Text_EchoAsk, MSGBOX_DEFAULT
	msgbox Genesis_Puzzle_Text_EchoRiddle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Genesis_Puzzle_EchoSealed_Wrong
	msgbox Genesis_Puzzle_Text_EchoRiddle2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_Puzzle_EchoSealed_Wrong
	msgbox Genesis_Puzzle_Text_EchoPressure, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_M_STRENGTH
	waitse
	setflag FLAG_GENESIS_PUZZLE_ECHO_SEALED
	playfanfare MUS_OBTAIN_ITEM
	msgbox Genesis_Puzzle_Text_EchoComplete, MSGBOX_DEFAULT
	waitfanfare
	giveitem ITEM_LIFE_ORB
	call Genesis_Puzzle_TryMasterReward
	releaseall
	end
Genesis_Puzzle_EchoSealed_Wrong::
	msgbox Genesis_Puzzle_Text_EchoWrong, MSGBOX_DEFAULT
	releaseall
	end
Genesis_Puzzle_EchoSealed_NeedDig::
	msgbox Genesis_Puzzle_Text_EchoNeedDig, MSGBOX_DEFAULT
	releaseall
	end
Genesis_Puzzle_EchoSealed_NeedAct::
	msgbox Genesis_Puzzle_Text_EchoNeedAct, MSGBOX_DEFAULT
	releaseall
	end
Genesis_Puzzle_EchoSealed_Done::
	msgbox Genesis_Puzzle_Text_EchoAlready, MSGBOX_DEFAULT
	releaseall
	end

@ --- Phenomena Lock (Sky Pillar 1F): Grass -> Water -> Fire pylons ---
Genesis_Puzzle_Phenomena_Grass::
	lockall
	goto_if_set FLAG_GENESIS_PUZZLE_PHENOMENA, Genesis_Puzzle_Phenomena_Done
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_PHENOMENA_GRASS
	msgbox Genesis_Puzzle_Text_PylonGrass, MSGBOX_DEFAULT
	releaseall
	end

Genesis_Puzzle_Phenomena_Water::
	lockall
	goto_if_set FLAG_GENESIS_PUZZLE_PHENOMENA, Genesis_Puzzle_Phenomena_Done
	goto_if_eq VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_PHENOMENA_GRASS, Genesis_Puzzle_Phenomena_WaterOk
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_PHENOMENA_NONE
	msgbox Genesis_Puzzle_Text_PylonReset, MSGBOX_DEFAULT
	releaseall
	end
Genesis_Puzzle_Phenomena_WaterOk::
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_PHENOMENA_WATER
	msgbox Genesis_Puzzle_Text_PylonWater, MSGBOX_DEFAULT
	releaseall
	end

Genesis_Puzzle_Phenomena_Fire::
	lockall
	goto_if_set FLAG_GENESIS_PUZZLE_PHENOMENA, Genesis_Puzzle_Phenomena_Done
	goto_if_eq VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_PHENOMENA_WATER, Genesis_Puzzle_Phenomena_Complete
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_PHENOMENA_NONE
	msgbox Genesis_Puzzle_Text_PylonReset, MSGBOX_DEFAULT
	releaseall
	end
Genesis_Puzzle_Phenomena_Complete::
	setflag FLAG_GENESIS_PUZZLE_PHENOMENA
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_PHENOMENA_NONE
	playfanfare MUS_OBTAIN_ITEM
	msgbox Genesis_Puzzle_Text_PhenomenaComplete, MSGBOX_DEFAULT
	waitfanfare
	giveitem ITEM_EXPERT_BELT
	call Genesis_Puzzle_TryMasterReward
	releaseall
	end
Genesis_Puzzle_Phenomena_Done::
	msgbox Genesis_Puzzle_Text_PhenomenaAlready, MSGBOX_DEFAULT
	releaseall
	end

Genesis_Puzzle_Phenomena_ResetNpc::
	lock
	faceplayer
	goto_if_set FLAG_GENESIS_PUZZLE_PHENOMENA, Genesis_Puzzle_Phenomena_Done
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_PHENOMENA_NONE
	msgbox Genesis_Puzzle_Text_PylonHint, MSGBOX_DEFAULT
	release
	end

@ --- Eclipse Cipher (Magma Hideout): riddle + switch A then B ---
Genesis_Puzzle_EclipseCipher_Console::
	lockall
	goto_if_set FLAG_GENESIS_PUZZLE_ECLIPSE_CIPHER, Genesis_Puzzle_Cipher_Done
	msgbox Genesis_Puzzle_Text_CipherAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Genesis_Puzzle_Cipher_Wrong
	msgbox Genesis_Puzzle_Text_CipherAsk2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Genesis_Puzzle_Cipher_Wrong
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_CIPHER_Q1
	msgbox Genesis_Puzzle_Text_CipherAccepted, MSGBOX_DEFAULT
	releaseall
	end
Genesis_Puzzle_Cipher_Wrong::
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_CIPHER_NONE
	msgbox Genesis_Puzzle_Text_CipherWrong, MSGBOX_DEFAULT
	releaseall
	end

Genesis_Puzzle_EclipseCipher_SwitchA::
	lockall
	goto_if_set FLAG_GENESIS_PUZZLE_ECLIPSE_CIPHER, Genesis_Puzzle_Cipher_Done
	goto_if_eq VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_CIPHER_Q1, Genesis_Puzzle_Cipher_AOk
	goto_if_eq VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_CIPHER_SWITCH_A, Genesis_Puzzle_Cipher_AOk
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_CIPHER_NONE
	msgbox Genesis_Puzzle_Text_CipherSwitchEarly, MSGBOX_DEFAULT
	releaseall
	end
Genesis_Puzzle_Cipher_AOk::
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_CIPHER_SWITCH_A
	playse SE_CLICK
	msgbox Genesis_Puzzle_Text_CipherSwitchA, MSGBOX_DEFAULT
	releaseall
	end

Genesis_Puzzle_EclipseCipher_SwitchB::
	lockall
	goto_if_set FLAG_GENESIS_PUZZLE_ECLIPSE_CIPHER, Genesis_Puzzle_Cipher_Done
	goto_if_eq VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_CIPHER_SWITCH_A, Genesis_Puzzle_Cipher_Complete
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_CIPHER_NONE
	msgbox Genesis_Puzzle_Text_CipherSwitchEarly, MSGBOX_DEFAULT
	releaseall
	end
Genesis_Puzzle_Cipher_Complete::
	setflag FLAG_GENESIS_PUZZLE_ECLIPSE_CIPHER
	setvar VAR_GENESIS_PUZZLE_STATE, GENESIS_PUZZLE_CIPHER_NONE
	playfanfare MUS_OBTAIN_ITEM
	msgbox Genesis_Puzzle_Text_CipherComplete, MSGBOX_DEFAULT
	waitfanfare
	giveitem ITEM_SCOPE_LENS
	call Genesis_Puzzle_TryMasterReward
	releaseall
	end
Genesis_Puzzle_Cipher_Done::
	msgbox Genesis_Puzzle_Text_CipherAlready, MSGBOX_DEFAULT
	releaseall
	end

@ Bonus once all four story puzzles are cleared
Genesis_Puzzle_TryMasterReward::
	goto_if_unset FLAG_GENESIS_PUZZLE_CRYSTAL_RELAY, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_PUZZLE_ECHO_SEALED, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_PUZZLE_PHENOMENA, Common_EventScript_NopReturn
	goto_if_unset FLAG_GENESIS_PUZZLE_ECLIPSE_CIPHER, Common_EventScript_NopReturn
	goto_if_set FLAG_GENESIS_ACHIEVEMENT_PUZZLES, Common_EventScript_NopReturn
	setflag FLAG_GENESIS_ACHIEVEMENT_PUZZLES
	msgbox Genesis_Puzzle_Text_MasterReward, MSGBOX_DEFAULT
	giveitem ITEM_BOTTLE_CAP
	giveitem ITEM_BOTTLE_CAP
	return

Genesis_Puzzle_Text_RelayReset:
	.string "The crystal relay rejects the order…\n"
	.string "Blue, then Green, then Red.$"

Genesis_Puzzle_Text_RelayComplete:
	.string "CRYSTAL RELAY aligned!\n"
	.string "GENESIS ENERGY steadies in NEW MAUVILLE.\p"
	.string "A capsule of rewritten potential\n"
	.string "materializes from the circuit!$"

Genesis_Puzzle_Text_EchoAsk:
	.string "Ancient echoes stir behind the wall…$"

Genesis_Puzzle_Text_EchoRiddle:
	.string "Does GENESIS ENERGY awaken from silence\n"
	.string "alone--without a bond?$"

Genesis_Puzzle_Text_EchoRiddle2:
	.string "Must a TRAINER's will press the stone\n"
	.string "as Strength presses the world?$"

Genesis_Puzzle_Text_EchoPressure:
	.string "You brace against the sealed stone…\n"
	.string "It yields like a Strength boulder!$"

Genesis_Puzzle_Text_EchoComplete:
	.string "ECHO SEAL solved!\n"
	.string "The ancient path remembers you.\p"
	.string "An orb of living life force rests\n"
	.string "in the dust of the chamber.$"

Genesis_Puzzle_Text_EchoWrong:
	.string "The echo fades. Think again.$"

Genesis_Puzzle_Text_EchoNeedDig:
	.string "Braille here whispers: dig where marked.$"

Genesis_Puzzle_Text_EchoNeedAct:
	.string "Return after facing TEAM ECLIPSE\n"
	.string "at METEOR FALLS.$"

Genesis_Puzzle_Text_EchoAlready:
	.string "The sealed echo already answered you.$"

Genesis_Puzzle_Text_PylonGrass:
	.string "A GRASS pylon hums with life energy.$"

Genesis_Puzzle_Text_PylonWater:
	.string "A WATER pylon answers the grass tide.$"

Genesis_Puzzle_Text_PylonReset:
	.string "The pylons dim… Order broken.\n"
	.string "Try Grass, then Water, then Fire.$"

Genesis_Puzzle_Text_PhenomenaComplete:
	.string "PHENOMENA LOCK released!\n"
	.string "SKY PILLAR steadies against the cascade.\p"
	.string "An Expert Belt settles into your bag,\n"
	.string "warm from elemental resonance.$"

Genesis_Puzzle_Text_PhenomenaAlready:
	.string "The phenomena lock stays open.$"

Genesis_Puzzle_Text_PylonHint:
	.string "Three pylons. Three elements.\n"
	.string "Life, sea, then flame--in that order.\p"
	.string "Speak to me to reset if you err.$"

Genesis_Puzzle_Text_CipherAsk:
	.string "ECLIPSE CIPHER: Does CAELUM seek to\n"
	.string "control GENESIS ENERGY itself?$"

Genesis_Puzzle_Text_CipherAsk2:
	.string "Is drowning AURELIA the true goal--\n"
	.string "not rewriting battle potential?$"

Genesis_Puzzle_Text_CipherAccepted:
	.string "Cipher accepts. Arm Switch A, then B.$"

Genesis_Puzzle_Text_CipherWrong:
	.string "Cipher rejects. Console resets.$"

Genesis_Puzzle_Text_CipherSwitchEarly:
	.string "Nothing happens. Solve the console first,\n"
	.string "then Switch A before Switch B.$"

Genesis_Puzzle_Text_CipherSwitchA:
	.string "Switch A armed.$"

Genesis_Puzzle_Text_CipherComplete:
	.string "ECLIPSE CIPHER broken!\n"
	.string "Hideout security falters.\p"
	.string "A Scope Lens drops from a cracked\n"
	.string "console--Eclipse gear, reclaimed.$"

Genesis_Puzzle_Text_CipherAlready:
	.string "The cipher remains broken.$"

Genesis_Puzzle_Text_MasterReward:
	.string "All four GENESIS puzzle locks yield!\n"
	.string "Bottle Caps crystallize as a master's prize.$"
