@ Local IDs are the same for both players houses
.set LOCALID_GRAM, 1
.set LOCALID_DAD, 5
.set LOCALID_GRAM_2F, 14

PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet::
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	return

PlayersHouse_1F_EventScript_EnterHouseMovingIn::
	msgbox PlayersHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	call_if_eq VAR_0x8005, MALE, PlayersHouse_1F_EventScript_MomFacePlayerMovingInMale
	call_if_eq VAR_0x8005, FEMALE, PlayersHouse_1F_EventScript_MomFacePlayerMovingInFemale
	msgbox PlayersHouse_1F_Text_MoversPokemonGoSetClock, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerWalkIn
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

PlayersHouse_1F_EventScript_MomFacePlayerMovingInMale::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomFacePlayerMovingInFemale::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PlayersHouse_1F_Movement_PlayerWalkIn:
	walk_up
	step_end

PlayersHouse_1F_EventScript_MomGoSeeRoom::
	msgbox PlayersHouse_1F_Text_ArentYouInterestedInRoom, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MovePlayerAwayFromDoor
	waitmovement 0
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_WallClock::
	lockall
	setvar VAR_0x8004, MALE
	goto PlayersHouse_2F_EventScript_WallClock
	end

LittlerootTown_MaysHouse_2F_EventScript_WallClock::
	lockall
	setvar VAR_0x8004, FEMALE
	goto PlayersHouse_2F_EventScript_WallClock
	end

PlayersHouse_2F_EventScript_WallClock::
	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	delay 30
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	setflag FLAG_SET_WALL_CLOCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PlayersHouse_2F_EventScript_MomComesUpstairsMale
	call_if_eq VAR_RESULT, FEMALE, PlayersHouse_2F_EventScript_MomComesUpstairsFemale
	playse SE_EXIT
	removeobject VAR_0x8008
	releaseall
	end

PlayersHouse_2F_EventScript_MomComesUpstairsMale::
	setvar VAR_0x8008, LOCALID_GRAM_2F
	addobject VAR_0x8008
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomEntersMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PlayersHouse_2F_Text_HowDoYouLikeYourRoom, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomExitsMale
	waitmovement 0
	return

PlayersHouse_2F_EventScript_MomComesUpstairsFemale::
	setvar VAR_0x8008, LOCALID_GRAM_2F
	addobject VAR_0x8008
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomEntersFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PlayersHouse_2F_Text_HowDoYouLikeYourRoom, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomExitsFemale
	waitmovement 0
	return

PlayersHouse_2F_EventScript_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_SetWallClock::
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	return

PlayersHouse_2F_Movement_MomEntersMale:
	delay_8
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_8
	walk_left
	step_end

PlayersHouse_2F_Movement_MomExitsMale:
	walk_right
	walk_up
	delay_8
	step_end

PlayersHouse_2F_Movement_MomEntersFemale:
	delay_8
	walk_down
	walk_in_place_faster_right
	delay_16
	delay_8
	walk_right
	step_end

PlayersHouse_2F_Movement_MomExitsFemale:
	walk_left
	walk_up
	delay_8
	step_end

PlayersHouse_1F_EventScript_SetWatchedBroadcast::
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	releaseall
	end

PlayersHouse_1F_EventScript_PetalburgGymReportMale::
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymMale
	waitmovement 0
	playbgm MUS_ENCOUNTER_INTERVIEWER, FALSE
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVMale
	waitmovement 0
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_1, 1
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatMale
	waitmovement 0
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
	end

PlayersHouse_1F_EventScript_PetalburgGymReportFemale::
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale
	waitmovement 0
	playbgm MUS_ENCOUNTER_INTERVIEWER, FALSE
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVFemale
	waitmovement 0
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_1, 1
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatFemale
	waitmovement 0
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
	end

PlayersHouse_1F_EventScript_MomNoticeGymBroadcast::
	playse SE_PIN
	applymovement VAR_0x8005, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8005, Common_Movement_Delay48
	waitmovement 0
	msgbox PlayersHouse_1F_Text_OhComeQuickly, MSGBOX_DEFAULT
	closemessage
	return

PlayersHouse_1F_EventScript_WatchGymBroadcast::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PlayersHouse_1F_Text_ReportFromPetalburgGym, MSGBOX_DEFAULT
	fadedefaultbgm
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_HOME
	delay 35
	return

PlayersHouse_1F_Movement_MomApproachDadMale:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_MomApproachDadFemale:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerMale:
	walk_right
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerFemale:
	walk_left
	step_end

PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale:
	walk_in_place_faster_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_right
	delay_16
	delay_16
	step_end

PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale:
	walk_in_place_faster_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	delay_16
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale:
	walk_up
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale:
	walk_up
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale:
	walk_left
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale:
	walk_right
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_Movement_MomReturnToSeatMale:
	walk_left
	walk_down
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_MomReturnToSeatFemale:
	walk_right
	walk_down
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_eq VAR_LITTLEROOT_HOUSES_STATE_MAY, 4, PlayersHouse_1F_EventScript_DontPushYourselfTooHard
	goto_if_eq VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4, PlayersHouse_1F_EventScript_DontPushYourselfTooHard
	goto_if_set FLAG_BADGE05_GET, PlayersHouse_1F_EventScript_TryGiveAmuletCoin
	goto_if_set FLAG_RESCUED_BIRCH, PlayersHouse_1F_EventScript_MomHealsParty
	goto_if_eq VAR_TEMP_1, 1, PlayersHouse_1F_EventScript_SeeYouHoney
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 7, PlayersHouse_1F_EventScript_DidYouMeetProfBirch
	msgbox PlayersHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_DontPushYourselfTooHard::
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_TryGiveAmuletCoin::
	goto_if_set FLAG_RECEIVED_AMULET_COIN, PlayersHouse_1F_EventScript_MomHealsParty
	msgbox PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom, MSGBOX_DEFAULT
	giveitem ITEM_AMULET_COIN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_AMULET_COIN
	release
	end

PlayersHouse_1F_EventScript_MomHealsParty::
	msgbox PlayersHouse_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_HealParty
	end

PlayersHouse_1F_EventScript_SeeYouHoney::
	msgbox PlayersHouse_1F_Text_SeeYouHoney, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_HealParty::
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	msgbox PlayersHouse_1F_Text_TakeCareHoney, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_DidYouMeetProfBirch::
	msgbox PlayersHouse_1F_Text_DidYouMeetProfBirch, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_Vigoroth1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL
	msgbox PlayersHouse_1F_Text_Vigoroth1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PlayersHouse_1F_EventScript_Vigoroth2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, CRY_MODE_NORMAL
	msgbox PlayersHouse_1F_Text_Vigoroth2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PlayersHouse_1F_Movement_PlayerApproachTVForGymMale:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_PlayerMoveToTVMale:
	walk_left
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_PlayerMoveToTVFemale:
	walk_right
	step_end

PlayersHouse_1F_Movement_MovePlayerAwayFromDoor:
	walk_up
	step_end

PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale
	call_if_eq VAR_RESULT, FEMALE, PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_PlayerEnterRoomMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_PlayerEnterRoomFemale
	applymovement VAR_0x8009, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8009, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8009, Common_Movement_Delay48
	waitmovement 0
	delay 20
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_DadApproachPlayerMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_DadApproachPlayerFemale
	msgbox PlayersHouse_1F_Text_TicketFromBrineyCameForYou, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox PlayersHouse_1F_Text_PortsInSlateportLilycove, MSGBOX_DEFAULT
	closemessage
	delay 20
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachDadMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachDadFemale
	msgbox PlayersHouse_1F_Text_BetterGetBackToGym, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_DadExitsMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_DadExitsFemale
	playse SE_DOOR
	removeobject VAR_0x8009
	setflag FLAG_RECEIVED_SS_TICKET
	delay 30
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachPlayerMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachPlayerFemale
	delay 20
	msgbox PlayersHouse_1F_Text_DadShouldStayLonger, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_TV_LATIAS_LATIOS
	special TurnOnTVScreen
	delay 60
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale
	msgbox PlayersHouse_1F_Text_IsThatABreakingStory, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale
	msgbox PlayersHouse_1F_Text_LatiEmergencyNewsFlash, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special TurnOffTVScreen
	call_if_eq VAR_0x8008, MALE, PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale
	call_if_eq VAR_0x8008, FEMALE, PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale
	msgbox PlayersHouse_1F_Text_WhatColorDidTheySay, MSGBOX_DEFAULT
	multichoice 22, 8, MULTI_TV_LATI, TRUE
	copyvar VAR_0x8004, VAR_RESULT
	special InitRoamer
	copyvar VAR_ROAMER_POKEMON, VAR_RESULT
	msgbox PlayersHouse_1F_Text_StillUnknownPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
	releaseall
	end

@ Never called.
PlayersHouse_1F_EventScript_AirLatiBroadcast::
	setflag FLAG_SYS_TV_LATIAS_LATIOS
	return

PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale::
	setvar VAR_0x8008, MALE
	setvar VAR_0x8009, LOCALID_DAD
	setvar VAR_0x800A, LOCALID_GRAM
	return

PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale::
	setvar VAR_0x8008, FEMALE
	setvar VAR_0x8009, LOCALID_DAD
	setvar VAR_0x800A, LOCALID_GRAM
	return

PlayersHouse_1F_EventScript_DadApproachPlayerMale::
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_DadApproachPlayerFemale::
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachDadMale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadMale
	waitmovement 0
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachDadFemale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadFemale
	waitmovement 0
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_DadExitsMale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_DadExitsFemale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerEnterRoomMale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerEnterRoomFemale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale
	waitmovement 0
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale::
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale
	waitmovement 0
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerMale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerFemale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale::
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PlayersHouse_1F_Movement_DadApproachPlayerMale:
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_DadApproachPlayerFemale:
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_DadFaceMomMale:
	face_left
	step_end

PlayersHouse_1F_Movement_DadFaceMomFemale:
	face_right
	step_end

PlayersHouse_1F_Movement_DadExitsMale:
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

PlayersHouse_1F_Movement_DadExitsFemale:
	walk_down
	walk_left
	walk_down
	delay_8
	step_end

PlayersHouse_1F_Movement_PlayerEnterRoomMale:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit:
	delay_8
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

PlayersHouse_1F_Movement_PlayerEnterRoomFemale:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

EventScript_RunningShoesManual::
	msgbox PlayersHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
	end

PlayersHouse_1F_EventScript_MomConversations::
	lock
	faceplayer
	goto_if_unset FLAG_ADVENTURE_STARTED, PlayersHouse_1F_EventScript_BeginningDialogue
	random 2
	goto_if_eq VAR_RESULT, 0, PlayersHouse_1F_EventScript_BadgeDialogue
	goto_if_eq VAR_RESULT, 1, PlayersHouse_1F_EventScript_RandomDialogue
	return

PlayersHouse_1F_EventScript_BeginningDialogue::
	msgbox PlayersHouse_1F_Text_MomMissedYou, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_BadgeDialogue::
	goto_if_set FLAG_IS_CHAMPION, PlayersHouse_1F_EventScript_MomChampion
	goto_if_set FLAG_BADGE08_GET, PlayersHouse_1F_EventScript_MomRainBadge
	goto_if_set FLAG_BADGE07_GET, PlayersHouse_1F_EventScript_MomMindBadge
	goto_if_set FLAG_BADGE06_GET, PlayersHouse_1F_EventScript_MomFeatherBadge
	goto_if_set FLAG_BADGE05_GET, PlayersHouse_1F_EventScript_MomKnuckleBadge
	goto_if_set FLAG_BADGE04_GET, PlayersHouse_1F_EventScript_MomHeatBadge
	goto_if_set FLAG_BADGE03_GET, PlayersHouse_1F_EventScript_MomDynamoBadge
	goto_if_set FLAG_BADGE02_GET, PlayersHouse_1F_EventScript_MomStoneBadge
	goto_if_set FLAG_BADGE01_GET, PlayersHouse_1F_EventScript_MomBalanceBadge
	return

PlayersHouse_1F_EventScript_RandomDialogue::
	random 4
	goto_if_eq VAR_RESULT, 0, PlayersHouse_1F_EventScript_MomFollowHeart
	goto_if_eq VAR_RESULT, 1, PlayersHouse_1F_EventScript_MomBelieveInYou
	goto_if_eq VAR_RESULT, 2, PlayersHouse_1F_EventScript_MomEnjoyJourney
	goto_if_eq VAR_RESULT, 3, PlayersHouse_1F_EventScript_MomGrowSoFast
	return

PlayersHouse_1F_EventScript_MomBalanceBadge::
	msgbox PlayersHouse_1F_Text_MomBalanceBadge, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_MomStoneBadge::
	msgbox PlayersHouse_1F_Text_MomStoneBadge, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_MomDynamoBadge::
	msgbox PlayersHouse_1F_Text_MomDynamoBadge, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_MomHeatBadge::
	msgbox PlayersHouse_1F_Text_MomHeatBadge, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_MomKnuckleBadge::
	msgbox PlayersHouse_1F_Text_MomKnuckleBadge, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_MomFeatherBadge::
	msgbox PlayersHouse_1F_Text_MomFeatherBadge, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_MomMindBadge::
	msgbox PlayersHouse_1F_Text_MomMindBadge, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_MomRainBadge::
	msgbox PlayersHouse_1F_Text_MomRainBadge, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_MomChampion::
	msgbox PlayersHouse_1F_Text_MomChampion, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_MomFollowHeart::
	msgbox PlayersHouse_1F_Text_MomFollowHeart, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_MomBelieveInYou::
	msgbox PlayersHouse_1F_Text_MomBelieveInYou, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_MomEnjoyJourney::
	msgbox PlayersHouse_1F_Text_MomEnjoyJourney, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_MomGrowSoFast::
	msgbox PlayersHouse_1F_Text_MomGrowSoFast, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_EndMomConversation
	return

PlayersHouse_1F_EventScript_EndMomConversation::
	msgbox PlayersHouse_1F_Text_MomLoveYou, MSGBOX_DEFAULT
	closemessage
	face_right
	release
	end

PlayersHouse_1F_Text_MomLoveYou:
	.string "I love you!$"

PlayersHouse_1F_Text_MomBalanceBadge:
	.string "Congratulations on your first gym\n"
	.string "badge, Asha!\p"
	.string "Oreo's Pokémon sure were cute,\n"
	.string "don't you think?\p"
	.string "T is up next, and you know how he is\n"
	.string "when it comes to Rock-type Pokémon.\p"
	.string "I suggest you bring something to deal\n"
	.string "with sandstorms and entry hazards.$"

PlayersHouse_1F_Text_MomStoneBadge:
	.string "Nice job beating Niles, Asha!\n"
	.string "I'm sure he didn't go easy on you.\p"
	.string "Up next is Wattson, the Electric-type\n"
	.string "Gym Leader.\p"
	.string "Watch out for his ace, Manetric.\n"
	.string "It's incredibly strong.\p"
	.string "Bring a Ground-type Pokémon since they\n"
	.string "are immune to Electric type attacks.$"

PlayersHouse_1F_Text_MomDynamoBadge:
	.string "Look at your Dynamo Badge! So pretty!\p"
	.string "You've gotta face May May next, and\n"
	.string "she trains Fire-type Pokémon to match\l"
	.string "her red-hot temper!\p"
	.string "Be prepared for any Harsh Sunlight.\n"
	.string "It weakens Water-type attacks but\l"
	.string "strenghtens Fire-type attacks.$"

PlayersHouse_1F_Text_MomHeatBadge:
	.string "Great job getting the Heat Badge!\n"
	.string "Did Iliyah bring the heat herself?\p"
	.string "You know who's next: Micheal.\p"
	.string "He trains his Fighting-type Pokémon to\n"
	.string "hit hard and hit fast.\p"
	.string "You'll need to hit harder with Psychic\l"
	.string "or Flying-type attacks and hit faster"
	.string "before they get to land too many hits.$"

PlayersHouse_1F_Text_MomKnuckleBadge:
	.string "Congratulations on defeating Micheal,\n"
	.string "Asha!\p"
	.string "I know I don't need to tell you this, but\n"
	.string "he's lying if he says he let you win.\p"
	.string "You should be facing Winona next.\p"
	.string "Her team of Flying-type Pokémon are\n"
	.string "super fast and she utilizes Tailwind to\l"
	.string "make them even faster for a bit.\p"
	.string "So unless your defense is rock solid,\n"
	.string "you'll need to slow them down.$"

PlayersHouse_1F_Text_MomFeatherBadge:
	.string "Well done getting the Feather Badge,\n"
	.string "Asha!\p"
	.string "At the next gym, you're gonna be facing\n"
	.string "two gym leaders at once!\p"
	.string "They know how to use powerful moves\n"
	.string "that seriously damage everyone on the\l"
	.string "battlefield except their teammate.\p"
	.string "I'd bring a Dark-type Pokémon that's\n"
	.string "immune to their Psychic-type attacks.$"

PlayersHouse_1F_Text_MomMindBadge:
	.string "Very impressive defeating the twins,\n"
	.string "Asha! I'm proud of you as always.\p"
	.string "The only one in between you and your\n"
	.string "last badge is Rheannon! How exciting!\p"
	.string "Her strategy often uses Rain to boost\n"
	.string "the power of her Water-type Pokémon,\l"
	.string "so I'd say use that against her.\p"
	.string "Either change the weather or embrace\n"
	.string "it with a perfectly accurate Thunder.$"

PlayersHouse_1F_Text_MomRainBadge:
	.string "Asha, I'm so proud of you. You've\n"
	.string "collected all the badges in Hoenn!\p"
	.string "All that's left is the Elite 4…\p"
	.string "Sidney specializes in Dark-types,\n"
	.string "Juan specializes in Ghost-types,\l"
	.string "Glacia specializes in Ice-types,\l"
	.string "and Drake in Dragon-types.\p"
	.string "Of course, there is also the Champion:\n"
	.string "Wallace. He's a Water-type specialist.\p"
	.string "I can't help you much more than that.\p"
	.string "Trust yourself and use everything that\n"
	.string "you've learned up to this point.$"

PlayersHouse_1F_Text_MomChampion:
	.string "My Asha, a champion…\p"
	.string "Of course I already knew that. You've\n"
	.string "been a champion your whole life.\p"
	.string "I'm unbelievably proud of you. I can't\n"
	.string "wait to see what you do next.$"

PlayersHouse_1F_Text_MomMissedYou:
	.string "I've missed you so much, Asha!\p"
	.string "It's nice to be together again.\p"
	.string "I'm a bit tired from the move though,\n"
	.string "so why don't you finish getting settled\l"
	.string "in and meeting our new neighbors?\p"
	.string "I'll be here when you're done.$"

PlayersHouse_1F_Text_MomFollowHeart:
	.string "Remember, Asha…\n"
	.string "always follow your heart.\p"
	.string "If you do that, the rest will take\n"
	.string "care of itself.$"

PlayersHouse_1F_Text_MomBelieveInYou:
	.string "I believe in you, Asha.\p"
	.string "No matter what happens, know that\n"
	.string "I'll be here for you.$"

PlayersHouse_1F_Text_MomEnjoyJourney:
	.string "Don't forget to take breaks and enjoy\n"
	.string "the journey, Asha.\p"
	.string "Before you know it, you'll have a gallery\n"
	.string "of memories to reminisce.$"

PlayersHouse_1F_Text_MomGrowSoFast:
	.string "You're growing up so fast, Asha.\p"
	.string "Just remember to stay true to yourself\n"
	.string "and never give up on those dreams.$"
