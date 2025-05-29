Route110_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
	.byte 0

Route110_OnResume:
	special UpdateCyclingRoadState
	end

Route110_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_SaveCyclingMusic
	end

Route110_EventScript_SaveCyclingMusic::
	savebgm MUS_CYCLING
	return

Route110_OnFrame:
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
	.2byte 0

Route110_EventScript_BeginCylcingRoadChallenge::
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
	return

Route110_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_Boy1::
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
	end

Route110_EventScript_CyclingGirl1::
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy1::
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
	end

Route110_EventScript_OldMan::
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
	end

Route110_EventScript_OldWoman::
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy2::
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
	end

Route110_EventScript_Boy2::
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
	end

Route110_EventScript_SlateportCitySign::
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadSign::
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route110_EventScript_VandalizedSign::
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
	end

Route110_EventScript_Route103Sign::
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
	end

Route110_EventScript_SeasideParkingSign::
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
	end

Route110_EventScript_MauvilleCitySign::
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsPrlzSleep::
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsRegisterItems::
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
	end

Route110_EventScript_TrickHouseSign::
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadResultsSign::
	lockall
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
	goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_NoRecordSet::
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_ChallengeGuy::
	lock
	faceplayer
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0, Route110_EventScript_PlayerNotRidingBike
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerNotRidingBike::
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerRidingAcroBike::
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_Edward::
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jaclyn::
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Edwin::
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_EdwinRematch::
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Dale::
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jacob::
	trainerbattle_single TRAINER_JACOB, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Benjamin::
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_BenjaminRematch::
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jasmine::
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Abigail::
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_AbigailRematch::
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Isabel::
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_IsabelRematch::
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Timmy::
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Unused::
	end

Route110_EventScript_Kaleb::
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Joseph::
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Alyssa::
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_CyclingChallengeEnd::
	lockall
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call Route110_EventScript_CyclingChallengeResults
	releaseall
	end

Route110_EventScript_CyclingChallengeResults::
	special FinishCyclingRoadChallenge
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
	switch VAR_RESULT
	case 10, Route110_EventScript_ChallengeReactionBest
	case 9, Route110_EventScript_ChallengeReactionGood
	case 8, Route110_EventScript_ChallengeReactionGood
	case 7, Route110_EventScript_ChallengeReactionGood
	case 6, Route110_EventScript_ChallengeReactionOk
	case 5, Route110_EventScript_ChallengeReactionOk
	case 4, Route110_EventScript_ChallengeReactionOk
	case 3, Route110_EventScript_ChallengeReactionBad
	case 2, Route110_EventScript_ChallengeReactionBad
	case 1, Route110_EventScript_ChallengeReactionBad
	case 0, Route110_EventScript_ChallengeReactionWorst
	end

Route110_EventScript_ChallengeReactionBest::
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionGood::
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionOk::
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionBad::
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionWorst::
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_EndChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route110_EventScript_RivalTrigger1::
	setvar VAR_0x8008, 1
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger2::
	setvar VAR_0x8008, 2
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger3::
	setvar VAR_0x8008, 3
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalScene::
	lockall
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_ROUTE110_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_ROUTE110_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE110_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
	goto Route110_EventScript_BenBattle
	releaseall
	end

Route110_EventScript_BenBattle::
	msgbox Route110_Text_BenLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_BenBattleBulbasaur
	case 1, Route110_EventScript_BenBattleFennekin
	case 2, Route110_EventScript_BenBattlePiplup
	end

Route110_EventScript_BenBattleBulbasaur::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_BULBASAUR, Route110_Text_BenDefeated
	goto Route110_EventScript_BenDefeated
	end

Route110_EventScript_BenBattleFennekin::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_FENNEKIN, Route110_Text_BenDefeated
	goto Route110_EventScript_BenDefeated
	end

Route110_EventScript_BenBattlePiplup::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_PIPLUP, Route110_Text_BenDefeated
	goto Route110_EventScript_BenDefeated
	end

Route110_EventScript_BenDefeated::
	msgbox Route110_Text_BenTakeThis, MSGBOX_DEFAULT
	givemon SPECIES_LUVDISC, 20, ITEM_HEART_SCALE, ITEM_LOVE_BALL, abilityNum=2, gender=FEMALE, isShiny=TRUE
	showmonpic SPECIES_LUVDISC, 10, 3, TRUE
	bufferspeciesname STR_VAR_1, SPECIES_LUVDISC
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LUVDISC
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route110_EventScript_ReceiveParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route110_EventScript_ReceivePC
	end

Route110_EventScript_ReceiveParty::
	call Route110_EventScript_ReceivedPokemonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Route110_EventScript_BenExplainLuvdisc
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route110_EventScript_BenExplainLuvdisc
	end

Route110_EventScript_ReceivePC::
	call Route110_EventScript_ReceivedPokemonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, Route110_EventScript_SentPokemonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route110_EventScript_BenExplainLuvdisc
	end

Route110_EventScript_SentPokemonToPC::
	call Common_EventScript_TransferredToPC
	goto Route110_EventScript_BenExplainLuvdisc
	end

Route110_EventScript_ReceivedPokemonFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route110_Text_PlayerReceivedPokemon
	waitmessage
	waitfanfare
	return

Route110_EventScript_BenExplainLuvdisc::
	closemessage
	delay 20
	applymovement LOCALID_ROUTE110_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox Route110_Text_BenExplainLuvdisc, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_ROUTE110_RIVAL, Common_Movement_WalkInPlaceFasterUp
	delay 60
	waitbuttonpress
	applymovement LOCALID_ROUTE110_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	msgbox Route110_Text_BenOffToLookForNewPokemon, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_RivalExit::
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
	setobjectmovementtype LOCALID_ROUTE110_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_ROUTE110_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
	removeobject LOCALID_ROUTE110_RIVAL
	addobject LOCALID_ROUTE110_RIVAL_ON_BIKE
	delay 45
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
	removeobject LOCALID_ROUTE110_RIVAL_ON_BIKE
	setvar VAR_ROUTE110_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer3::
	applymovement LOCALID_ROUTE110_RIVAL, Route110_Movement_RivalApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_RivalExit1::
	applymovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
	waitmovement 0
	return

Route110_EventScript_RivalExit2::
	applymovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
	waitmovement 0
	return

Route110_EventScript_RivalExit3::
	applymovement LOCALID_ROUTE110_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
	waitmovement 0
	return

Route110_EventScript_MoveRival1::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 33, 55
	return

Route110_EventScript_MoveRival2::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 34, 55
	return

Route110_EventScript_MoveRival3::
	setobjectxyperm LOCALID_ROUTE110_RIVAL_ON_BIKE, 35, 55
	return

Route110_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalApproachPlayer2:
	walk_down
	step_end

Route110_Movement_RivalApproachPlayer3:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalExit1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_RivalExit2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_down
	step_end

Route110_Movement_RivalExit3:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_EventScript_CeceScene1::
	lock
	setvar VAR_0x8008, 1
	goto Route110_EventScript_CeceScene

Route110_EventScript_CeceScene2::
	lock
	setvar VAR_0x8008, 2
	goto Route110_EventScript_CeceScene

Route110_EventScript_CeceScene3::
	lock
	setvar VAR_0x8008, 3
	goto Route110_EventScript_CeceScene

Route110_EventScript_CeceScene4::
	lock
	setvar VAR_0x8008, 4
	goto Route110_EventScript_CeceScene

Route110_EventScript_CeceScene::
	addobject LOCALID_ROUTE110_CECE
	addobject LOCALID_ROUTE110_MINCCINO
	applymovement LOCALID_ROUTE110_CECE, Route110_Movement_CeceEntrance
	applymovement LOCALID_ROUTE110_MINCCINO, Route110_Movement_CeceEntrance
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_ROUTE110_CECE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE110_CECE, Route110_Movement_CeceHop
	waitmovement 0
	call_if_eq VAR_0x8008, 1, Route110_EventScript_CeceApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_CeceApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_CeceApproachPlayer3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_CeceApproachPlayer4
	msgbox Route110_Text_ConvenientSeeingYouHere, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_ROUTE110_CECE, Common_Movement_WalkInPlaceFasterUp
	delay 60
	applymovement LOCALID_ROUTE110_CECE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	msgbox Route110_Text_BePrepared, MSGBOX_DEFAULT
	giveitem ITEM_DOWSING_MACHINE
	msgbox Route110_Text_ExplainDowsingMachine, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_CeceExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_CeceExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_CeceExit3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_CeceExit4
	removeobject LOCALID_ROUTE110_CECE
	removeobject LOCALID_ROUTE110_MINCCINO
	setvar VAR_REGISTER_BIRCH_STATE, 2
	releaseall
	end

Route110_EventScript_CeceApproachPlayer1::
	applymovement LOCALID_ROUTE110_CECE, Route110_Movement_CeceApproachPlayer1
	applymovement LOCALID_ROUTE110_MINCCINO, Route110_Movement_MinccinoApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_CeceApproachPlayer2::
	applymovement LOCALID_ROUTE110_CECE, Route110_Movement_CeceApproachPlayer2
	applymovement LOCALID_ROUTE110_MINCCINO, Route110_Movement_MinccinoApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_CeceApproachPlayer3::
	applymovement LOCALID_ROUTE110_CECE, Route110_Movement_CeceApproachPlayer3
	applymovement LOCALID_ROUTE110_MINCCINO, Route110_Movement_MinccinoApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_CeceApproachPlayer4::
	applymovement LOCALID_ROUTE110_CECE, Route110_Movement_CeceApproachPlayer4
	applymovement LOCALID_ROUTE110_MINCCINO, Route110_Movement_MinccinoApproachPlayer4
	waitmovement 0
	return

Route110_EventScript_CeceExit1::
	applymovement LOCALID_ROUTE110_CECE, Route110_Movement_CeceExit1
	applymovement LOCALID_ROUTE110_MINCCINO, Route110_Movement_MinccinoExit1
	waitmovement 0
	return

Route110_EventScript_CeceExit2::
	applymovement LOCALID_ROUTE110_CECE, Route110_Movement_CeceExit2
	applymovement LOCALID_ROUTE110_MINCCINO, Route110_Movement_MinccinoExit2
	waitmovement 0
	return

Route110_EventScript_CeceExit3::
	applymovement LOCALID_ROUTE110_CECE, Route110_Movement_CeceExit3
	applymovement LOCALID_ROUTE110_MINCCINO, Route110_Movement_MinccinoExit3
	waitmovement 0
	return

Route110_EventScript_CeceExit4::
	applymovement LOCALID_ROUTE110_CECE, Route110_Movement_CeceExit4
	applymovement LOCALID_ROUTE110_MINCCINO, Route110_Movement_MinccinoExit4
	waitmovement 0
	return

Route110_Movement_CeceEntrance:
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_CeceHop:
	delay_16
	delay_16
	delay_16
	jump_in_place_down
	step_end

Route110_Movement_CeceApproachPlayer1:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_down
	step_end

Route110_Movement_MinccinoApproachPlayer1:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	face_down
	enter_pokeball
	walk_fast_down
	step_end

Route110_Movement_CeceApproachPlayer2:
	walk_fast_down
	walk_fast_left
	walk_fast_down
	step_end

Route110_Movement_MinccinoApproachPlayer2:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	face_down
	enter_pokeball
	walk_fast_down
	step_end

Route110_Movement_CeceApproachPlayer3:
	walk_fast_down
	walk_fast_down
	step_end

Route110_Movement_MinccinoApproachPlayer3:
	walk_fast_down
	walk_fast_down
	enter_pokeball
	walk_fast_down
	step_end

Route110_Movement_CeceApproachPlayer4:
	walk_fast_down
	walk_fast_right
	walk_fast_down
	step_end

Route110_Movement_MinccinoApproachPlayer4:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	face_down
	enter_pokeball
	walk_fast_down
	step_end

Route110_Movement_CeceExit1:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_MinccinoExit1:
	exit_pokeball
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_CeceExit2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_MinccinoExit2:
	exit_pokeball
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_CeceExit3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_MinccinoExit3:
	exit_pokeball
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_CeceExit4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_MinccinoExit4:
	exit_pokeball
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Text_WeCantTalkAboutAquaActivities:
	.string "Team Aqua's activities…\n"
	.string "We can't talk about them yet.$"

Route110_Text_KickUpARuckus:
	.string "I want to get going to Slateport and\n"
	.string "kick up a ruckus!$"

Route110_Text_MyFirstJobInAqua:
	.string "This is my first job after joining\n"
	.string "Team Aqua. It's a little scary.$"

Route110_Text_AquaActionsBringSmiles:
	.string "Team Aqua's actions should bring\n"
	.string "smiles to people's faces!$"

Route110_Text_BenLetsBattle:
	.string "Ben: Hey, {PLAYER}.\n"
	.string "How's it going?\p"
	.string "Have you been raising your Pokémon?\n"
	.string "I'll check for you.$"

Route110_Text_BenDefeated:
	.string "Hmm…\n"
	.string "You're pretty good.$"

Route110_Text_BenTakeThis:
	.string "Ben: {PLAYER}, you've trained\n"
	.string "your Pokémon pretty well…\p"
	.string "That settles it!\n"
	.string "You should take this.$"

Route110_Text_PlayerReceivedPokemon:
	.string "{PLAYER} received {STR_VAR_1}!$"

Route110_Text_BenExplainLuvdisc:
	.string "Ben: Pretty cool, right?\p"
	.string "I finally--uh, I mean--I happened to\n"
	.string "catch this one a little bit ago.\p"
	.string "Catching it made me think of you and\n"
	.string "that you'd maybe like it or something…$"

Route110_Text_BenOffToLookForNewPokemon:
	.string "Ben: Anyway!\p"
	.string "I'm off to look for new Pokémon.\n"
	.string "See ya around!$"

Route110_Text_RideBikeAtFullSpeed:
	.string "Wouldn't it be great to ride a Bike\n"
	.string "at full speed on Cycling Road?$"

Route110_Text_HairStreamsBehindMe:
	.string "How do you like the way my raven-\n"
	.string "colored hair streams behind me?\p"
	.string "I grew my hair out just for that.$"

Route110_Text_YouGotBikeFromRydel:
	.string "Oh, hey, you got that Bike from Rydel!\p"
	.string "Oh, it's glaringly obvious.\n"
	.string "It says right on your bike…\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL…\n"
	.string "That name's everywhere.\p"
	.string "You should ride it around all over\n"
	.string "the place--it's good advertising!$"

Route110_Text_TwoRoads:
	.string "The two roads, one above, one below…\p"
	.string "A road each for people and Pokémon.\n"
	.string "Perhaps that is right and fair.$"

Route110_Text_WalkOnTheLowRoad:
	.string "I don't have a Bike, so I'll take\n"
	.string "a leisurely walk on the low road.$"

Route110_Text_BikeTechniques:
	.string "Learning techniques will make Bike\n"
	.string "riding even more fun.\p"
	.string "There are some places that you can\n"
	.string "reach only by using a Bike technique.$"

Route110_Text_WhichShouldIChoose:
	.string "Which should I choose?\p"
	.string "Make a beeline for Mauville on\n"
	.string "Cycling Road, or take the low road\l"
	.string "and look for Pokémon?$"

Route110_Text_CyclingChallengeResultSummary:
	.string "Number of collisions:\n"
	.string "… … {STR_VAR_1}!\p"
	.string "Total time:\n"
	.string "… … {STR_VAR_2}!$"

Route110_Text_ChallengeReactionBest:
	.string "Bravo! Splendid showing!\p"
	.string "Your love of cycling comes from deep\n"
	.string "within your heart.\l"
	.string "You've shaken me to my very soul!$"

Route110_Text_ChallengeReactionGood:
	.string "Your technique is remarkable.\p"
	.string "I suggest you speed up a bit while\n"
	.string "still avoiding collisions.$"

Route110_Text_ChallengeReactionOk:
	.string "I would consider you a work in\n"
	.string "progress.\p"
	.string "Still, I hope you don't forget the\n"
	.string "sheer pleasure of cycling.$"

Route110_Text_ChallengeReactionBad:
	.string "My word… Your cycling skills border\n"
	.string "on terrifying.\p"
	.string "Most certainly, you need much more\n"
	.string "practice riding.$"

Route110_Text_ChallengeReactionWorst:
	.string "…I am aghast…\p"
	.string "You're perhaps not cut out for this\n"
	.string "unfortunate cycling business.\p"
	.string "You ought to give serious thought to\n"
	.string "returning that Bike to Rydel.$"

Route110_Text_RatedForNumberOfCollisions:
	.string "This is Cycling Road.\p"
	.string "If you were to ride from Mauville to\n"
	.string "Slateport on a Mach Bike, you would\l"
	.string "be rated for the number of collisions\l"
	.string "and your total time.$"

Route110_Text_AlwaysAimHigher:
	.string "Regardless of the results, I count on\n"
	.string "seeing more challenges from you.\l"
	.string "Always aim higher!$"

Route110_Text_AcroBikesDoNotQualify:
	.string "On this Cycling Road, those riding\n"
	.string "Mach Bikes are rated for their number\l"
	.string "of collisions and their total times.\p"
	.string "Acro Bikes do not qualify for rating.\n"
	.string "They are easy to turn, so it's not fair.$"

Route110_Text_SlateportCitySign:
	.string "ROUTE 110\n"
	.string "{DOWN_ARROW} SLATEPORT CITY$"

Route110_Text_CyclingRoadSign:
	.string "SEASIDE CYCLING ROAD$"

Route110_Text_AquaWasHere:
	.string "“Team Aqua wuz here!”\p"
	.string "Someone painted that onto this sign,\n"
	.string "but then someone else painted over it.\p"
	.string "“Team Magma roolz!” is what it\n"
	.string "says now.$"

Route110_Text_Route103Sign:
	.string "ROUTE 110\n"
	.string "{LEFT_ARROW} ROUTE 103$"

Route110_Text_SeasideParkingSign:
	.string "SEASIDE PARKING$"

Route110_Text_MauvilleCitySign:
	.string "ROUTE 110\n"
	.string "{UP_ARROW} MAUVILLE CITY$"

Route110_Text_TrainerTipsPrlzSleep:
	.string "TRAINER TIPS\p"
	.string "The foe can be made helpless by\n"
	.string "paralyzing it or causing it to sleep.\p"
	.string "It is an important technique for\n"
	.string "Pokémon battles.$"

Route110_Text_TrainerTipsRegisterItems:
	.string "TRAINER TIPS\p"
	.string "The items in the Bag can be reorganized\n"
	.string "by pressing Select.$"

Route110_Text_TrickHouseSign:
	.string "“Three steps {RIGHT_ARROW} and two steps {UP_ARROW}\n"
	.string "to reach the wondrous Trick House.”$"

Route110_Text_BestRecord:
	.string "THE BEST RECORD TO DATE…\p"
	.string "No. of collisions: {STR_VAR_1}\p"
	.string "Elapsed time: {STR_VAR_2}$"

Route110_Text_ThereIsNoRecord:
	.string "THE BEST RECORD TO DATE…\p"
	.string "No one seems to have taken the\n"
	.string "challenge. There is no record…$"

Route110_Text_ConvenientSeeingYouHere:
	.string "???: Oh, {PLAYER}{KUN}!\n"
	.string "How convenient seeing you here!\p"
	.string "{RIVAL} is looking for you as we speak.\n"
	.string "I just bumped into {RIVAL} up there.$"

Route110_Text_BePrepared:
	.string "???: He'd been fishing in Slateport\n"
	.string "for a while looking for something\l"
	.string "special but didn't tell me what…\p"
	.string "Anyway, I have something from Gump.\p"
	.string "Consider it a gift from the old man!$"

Route110_Text_ExplainDowsingMachine:
	.string "???: That's a Dowsing Machine.\p"
	.string "It'll point you in the direction of\n"
	.string "items hidden nearby.\p"
	.string "That's all for now.\p"
	.string "I've gotta go but I'm sure we'll\n"
	.string "meet up again soon, {PLAYER}{KUN}!\p"
	.string "Buh-bye!$"
