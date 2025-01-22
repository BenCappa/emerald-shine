.set LOCALID_TRICK_MASTER, 1

Route110_TrickHouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
	.byte 0

Route110_TrickHouseEnd_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	end

Route110_TrickHouseEnd_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseNuggetFlag
	end

Route110_TrickHouseEnd_OnWarp:
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
	.2byte 0

Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
	addobject LOCALID_TRICK_MASTER
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	end

Route110_TrickHouseEnd_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
	.2byte 0

Route110_TrickHouseEnd_EventScript_CloseDoor::
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
	return

Route110_TrickHouseEnd_EventScript_TrickMaster::
	lock
	faceplayer
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_PP_UP
	goto_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	goto Route110_TrickHouseEnd_EventScript_NewTricksOrLeaving
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_GRIP_CLAW
	goto_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	goto Route110_TrickHouseEnd_EventScript_NewTricksOrLeaving
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_FLOAT_STONE
	goto_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	goto Route110_TrickHouseEnd_EventScript_NewTricksOrLeaving
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_SPORT_BALL
	goto_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	goto Route110_TrickHouseEnd_EventScript_NewTricksOrLeaving
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TM_TAUNT
	goto_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	goto Route110_TrickHouseEnd_EventScript_NewTricksOrLeaving
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	switch VAR_STARTER_MON
	case 0, Route110_TrickHouseEnd_EventScript_GivePiplup
	case 1, Route110_TrickHouseEnd_EventScript_GiveBulbasaur
	case 2, Route110_TrickHouseEnd_EventScript_GiveFennekin
	end

Route110_TrickHouseEnd_EventScript_GiveBulbasaur::
	givemon SPECIES_BULBASAUR, 5, ITEM_ABILITY_PATCH, ITEM_CHERISH_BALL
	showmonpic SPECIES_BULBASAUR, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BULBASAUR
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route110_TrickHouseEnd_EventScript_ReceiveParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route110_TrickHouseEnd_EventScript_ReceivePC
	goto Route110_TrickHouseEnd_EventScript_NoMoreRoomForPokemon
	end

Route110_TrickHouseEnd_EventScript_GiveFennekin::
	givemon SPECIES_FENNEKIN, 5, ITEM_ABILITY_PATCH, ITEM_CHERISH_BALL
	showmonpic SPECIES_FENNEKIN, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_FENNEKIN
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_FENNEKIN
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route110_TrickHouseEnd_EventScript_ReceiveParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route110_TrickHouseEnd_EventScript_ReceivePC
	goto Route110_TrickHouseEnd_EventScript_NoMoreRoomForPokemon
	end

Route110_TrickHouseEnd_EventScript_GivePiplup::
	givemon SPECIES_PIPLUP, 5, ITEM_ABILITY_PATCH, ITEM_CHERISH_BALL
	showmonpic SPECIES_PIPLUP, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_PIPLUP
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PIPLUP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route110_TrickHouseEnd_EventScript_ReceiveParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route110_TrickHouseEnd_EventScript_ReceivePC
	goto Route110_TrickHouseEnd_EventScript_NoMoreRoomForPokemon
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	switch VAR_STARTER_MON
	case 0, Route110_TrickHouseEnd_EventScript_GiveEmpoleonite
	case 1, Route110_TrickHouseEnd_EventScript_GiveVenusaurite
	case 2, Route110_TrickHouseEnd_EventScript_GiveDelphoxite
	end

Route110_TrickHouseEnd_EventScript_GiveVenusaurite::
	giveitem ITEM_VENUSAURITE
	goto_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	goto Route110_TrickHouseEnd_EventScript_NewTricksOrLeaving
	end

Route110_TrickHouseEnd_EventScript_GiveDelphoxite::
	giveitem ITEM_DELPHOXITE
	goto_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	goto Route110_TrickHouseEnd_EventScript_NewTricksOrLeaving
	end

Route110_TrickHouseEnd_EventScript_GiveEmpoleonite::
	giveitem ITEM_EMPOLEONITE
	goto_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	goto Route110_TrickHouseEnd_EventScript_NewTricksOrLeaving
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
	delay 30
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	delay 30
	msgbox Route110_TrickHouseEnd_Text_DefeatedMe, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	switch VAR_STARTER_MON
	case 0, Route110_TrickHouseEnd_EventScript_GiveFennekinAndStone
	case 1, Route110_TrickHouseEnd_EventScript_GivePiplupAndStone
	case 2, Route110_TrickHouseEnd_EventScript_GiveBulbasaurAndStone
	end

Route110_TrickHouseEnd_EventScript_GiveBulbasaurAndStone::
	givemon SPECIES_BULBASAUR, 5, ITEM_VENUSAURITE, ITEM_CHERISH_BALL, abilityNum=2
	showmonpic SPECIES_BULBASAUR, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BULBASAUR
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route110_TrickHouseEnd_EventScript_ReceiveParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route110_TrickHouseEnd_EventScript_ReceivePC
	goto Route110_TrickHouseEnd_EventScript_NoMoreRoomForPokemon
	end

Route110_TrickHouseEnd_EventScript_GiveFennekinAndStone::
	givemon SPECIES_FENNEKIN, 5, ITEM_DELPHOXITE, ITEM_CHERISH_BALL, abilityNum=2
	showmonpic SPECIES_FENNEKIN, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_FENNEKIN
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_FENNEKIN
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route110_TrickHouseEnd_EventScript_ReceiveParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route110_TrickHouseEnd_EventScript_ReceivePC
	goto Route110_TrickHouseEnd_EventScript_NoMoreRoomForPokemon
	end

Route110_TrickHouseEnd_EventScript_GivePiplupAndStone::
	givemon SPECIES_PIPLUP, 5, ITEM_EMPOLEONITE, ITEM_CHERISH_BALL, abilityNum=2
	showmonpic SPECIES_PIPLUP, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_PIPLUP
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PIPLUP
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route110_TrickHouseEnd_EventScript_ReceiveParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route110_TrickHouseEnd_EventScript_ReceivePC
	goto Route110_TrickHouseEnd_EventScript_NoMoreRoomForPokemon
	end

Route110_TrickHouseEnd_EventScript_NewTricksOrLeaving::
	goto_if_lt VAR_TRICK_HOUSE_LEVEL, 7, Route110_TrickHouseEnd_EventScript_MakeNewTricksToStumpYou
	goto Route110_TrickHouseEnd_EventScript_LeavingOnJourney
	end

Route110_TrickHouseEnd_EventScript_MakeNewTricksToStumpYou::
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_LeavingOnJourney::
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	special ResetTrickHouseNuggetFlag
	release
	end

Route110_TrickHouseEnd_EventScript_TrickMasterExit::
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_ReceiveParty::
	call Route110_TrickHouseEnd_EventScript_ReceivedPokemonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Route110_TrickHouseEnd_EventScript_NewTricksOrLeaving
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route110_TrickHouseEnd_EventScript_NewTricksOrLeaving
	end

Route110_TrickHouseEnd_EventScript_ReceivePC::
	call Route110_TrickHouseEnd_EventScript_ReceivedPokemonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Route110_TrickHouseEnd_EventScript_SentPokemonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route110_TrickHouseEnd_EventScript_SentPokemonToPC
	end

Route110_TrickHouseEnd_EventScript_SentPokemonToPC::
	call Common_EventScript_TransferredToPC
	goto Route110_TrickHouseEnd_EventScript_NewTricksOrLeaving
	end

Route110_TrickHouseEnd_EventScript_ReceivedPokemonFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route110_TrickHouseEnd_Text_PlayerReceivedPokemon
	waitmessage
	waitfanfare
	return

Route110_TrickHouseEnd_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	closemessage
	release
	end

Route110_TrickHouseEnd_EventScript_NoMoreRoomForPokemon::
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	call Common_EventScript_NoMoreRoomForPokemon
	closemessage
	release
	end

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
	lockall
	turnobject LOCALID_TRICK_MASTER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
	waitmovement 0
	delay 4
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_YouveMadeItToMe:
	.string "Aak!\n"
	.string "You've made it to me?\l"
	.string "Hmmm… You're sharp!$"

Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
	.string "It took me all night to plant all those\n"
	.string "trees…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four, five, six places!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
	.string "It took me all night to make the maze…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four, five places!$"

Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
	.string "It took me all night to prepare\n"
	.string "the wall panels…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three, four places!$"

Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
	.string "It took me all night to shove in those\n"
	.string "boulders…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two, three places!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
	.string "It took me all night to think up a quiz\n"
	.string "and another to make the Mecha-Dolls…\p"
	.string "You're almost my equal in greatness by\n"
	.string "one, two places!$"

Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
	.string "It took me all night to install\n"
	.string "the doors…\p"
	.string "You're almost my equal in greatness!$"

Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
	.string "It took me all night setting up arrows…\p"
	.string "You're my equal in greatness!$"

Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
	.string "It took me all night polishing floors…\p"
	.string "You're above me in greatness!\n"
	.string "Possibly…$"

Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
	.string "Wh-what should I do?\n"
	.string "My fountain of ideas for tricks has\l"
	.string "run dry…\p"
	.string "Perhaps it is time I toured the country\n"
	.string "on a quest to devise new tricks…$"

Route110_TrickHouseEnd_Text_DefeatedMe:
	.string "I hate to admit defeat, but you have\n"
	.string "bested me!\p"
	.string "Still, you must have been reeled in by\n"
	.string "my charisma for you to visit me again\l"
	.string "and again. Yes, you must have!\p"
	.string "But that has nothing to do with my\n"
	.string "losing!\p"
	.string "In recognition of the friendship\n"
	.string "between you, the driven, and the genius\l"
	.string "that is myself, I demand that you take\l"
	.string "this final prize!$"

Route110_TrickHouseEnd_Text_NoRoomInPC:
	.string "What? No room in your PC?\n"
	.string "What am I to make of that?\p"
	.string "I wish I could say that, but I am much\n"
	.string "too kind and caring, so come back later!$"

Route110_TrickHouseEnd_Text_LeavingOnJourney:
	.string "… … … … … …\p"
	.string "I am leaving on a journey of discovery.\n"
	.string "A quest in search of new tricks.\p"
	.string "I wish that you will one day visit and\n"
	.string "entertain me again.\p"
	.string "And now, farewell!$"

Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
	.string "Fine!\n"
	.string "You have earned this reward!$"

Route110_TrickHouseEnd_Text_NoRoomForThis:
	.string "What? Have you no room for this?\n"
	.string "What manner of items do you carry?\p"
	.string "But fine, since you've reached me,\n"
	.string "your reward will be with me till later.$"

Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
	.string "Scrub that smug smirk from your face!\n"
	.string "It's much too early to think you've won!\p"
	.string "I'll make new tricks to stump you, I will.\n"
	.string "You may mock me only when you're done.\p"
	.string "Come back for the next exciting\n"
	.string "installment!$"

Route110_TrickHouseEnd_Text_YoureIgnoringMe:
	.string "Now, now! You're ignoring me now?\n"
	.string "Now that, I consider heartbreaking!$"

Route110_TrickHouseEnd_Text_PlayerReceivedPokemon:
	.string "{PLAYER} received {STR_VAR_1}!$"
