EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement LOCALID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachSteven
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Steven
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachSteven:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Steven::
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	delay 60
	addobject LOCALID_CHAMPIONS_ROOM_CECE
	addobject LOCALID_CHAMPIONS_ROOM_KIT
	applymovement LOCALID_CHAMPIONS_ROOM_STEVEN, EverGrandeCity_ChampionsRoom_Movement_StevenStepAside
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_CHAMPIONS_ROOM_CECE, EverGrandeCity_ChampionsRoom_Movement_CeceArrives
	applymovement LOCALID_CHAMPIONS_ROOM_KIT, EverGrandeCity_ChampionsRoom_Movement_KitArrives
	waitmovement 0
	delay 30
	msgbox EverGrandeCity_ChampionsRoom_Text_KidsFakeOut, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_CECE, EverGrandeCity_ChampionsRoom_Movement_CeceUpToLeft
	applymovement LOCALID_CHAMPIONS_ROOM_KIT, EverGrandeCity_ChampionsRoom_Movement_KitUpToRight
	applymovement LOCALID_CHAMPIONS_ROOM_STEVEN, EverGrandeCity_ChampionsRoom_Movement_WatchCeceGoUp
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_WatchKitGoUp
	waitmovement 0
	delay 30
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	waitse
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	delay 120
	addobject LOCALID_CHAMPIONS_ROOM_RIVAL
	delay 60
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BenIntroSpeech, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, EverGrandeCity_ChampionsRoom_EventScript_BattleChampionBulbasaur
	case 1, EverGrandeCity_ChampionsRoom_EventScript_BattleChampionFennekin
	case 2, EverGrandeCity_ChampionsRoom_EventScript_BattleChampionPiplup
	end

EverGrandeCity_ChampionsRoom_EventScript_BattleChampionBulbasaur:
	trainerbattle_no_intro TRAINER_BEN_CHAMPION_BULBASAUR, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_BattleChampionFennekin:
	trainerbattle_no_intro TRAINER_BEN_CHAMPION_FENNEKIN, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_BattleChampionPiplup:
	trainerbattle_no_intro TRAINER_BEN_CHAMPION_PIPLUP, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_STEVEN, Common_Movement_FacePlayer
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	delay 10
	applymovement LOCALID_CHAMPIONS_ROOM_STEVEN, EverGrandeCity_ChampionsRoom_Movement_StevenApproachRival
	msgbox EverGrandeCity_ChampionsRoom_Text_StevenComeWithMe, MSGBOX_DEFAULT
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox EverGrandeCity_ChampionsRoom_Text_LetsGo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_PlayerRivalExitStart
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerRivalExitStart
	applymovement LOCALID_CHAMPIONS_ROOM_STEVEN, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_CECE, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_CHAMPIONS_ROOM_KIT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_GumpWait, MSGBOX_DEFAULT
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_CHAMPIONS_ROOM_CECE, Common_Movement_ExclamationMark
	applymovement LOCALID_CHAMPIONS_ROOM_KIT, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_CHAMPIONS_ROOM_STEVEN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_CHAMPIONS_ROOM_CECE, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_CHAMPIONS_ROOM_KIT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_RivalDad, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_CHAMPIONS_ROOM_BIRCH
	applymovement LOCALID_CHAMPIONS_ROOM_BIRCH, EverGrandeCity_ChampionsRoom_Movement_GumpArrives
	waitmovement 0
	applymovement LOCALID_CHAMPIONS_ROOM_STEVEN, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_CHAMPIONS_ROOM_CECE, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_CHAMPIONS_ROOM_KIT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_GumpRatePokedex, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_AreYouSerious, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_GumpCongratulations, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_CHAMPIONS_ROOM_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalExit
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	applymovement LOCALID_CHAMPIONS_ROOM_STEVEN, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_CHAMPIONS_ROOM_CECE, EverGrandeCity_ChampionsRoom_Movement_WatchPlayerExit
	applymovement LOCALID_CHAMPIONS_ROOM_KIT, EverGrandeCity_ChampionsRoom_Movement_WatchPlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_StevenStepAside:
	walk_left
	walk_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_CeceArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_KitArrives:
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_CeceUpToLeft:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_16
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_KitUpToRight:
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	delay_16
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WatchCeceGoUp:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WatchKitGoUp:
	delay_16
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_StevenApproachRival:
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerRivalExitStart:
	face_up
	delay_16
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_GumpArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_down
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_WatchPlayerExit:
	delay_16
	walk_in_place_faster_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "Steven: Welcome, {PLAYER}{KUN}.\p"
	.string "You've done well to get to this point.\p"
	.string "I'm not solely referring to your victory\n"
	.string "over the Elite Four, either.\p"
	.string "You've done many incredible things\n"
	.string "during your time in this world.\p"
	.string "I also have it on good authority you've\n"
	.string "done even more so in your own world.\p"
	.string "I, truly, am impressed with you.\p"
	.string "As it stands, only one battle stands\n"
	.string "between you and the Champion title.\p"
	.string "Ordinarily, that honor would fall to me.\p"
	.string "But your journey is far from ordinary,\n"
	.string "wouldn't you say?\p"
	.string "Yes, some changes have been made so\n"
	.string "that your deciding battle may be\l"
	.string "against a very special opponent…$"

EverGrandeCity_ChampionsRoom_Text_KidsFakeOut:
	.string "Cece: Sorry, Mom! It's not us either!\n"
	.string "Kit: We just wanted to cheer you on!$"

EverGrandeCity_ChampionsRoom_Text_BenIntroSpeech:
	.string "Hey, Sunshine.\p"
	.string "You know, a little bit ago I realized\n"
	.string "something.\p"
	.string "I think getting us both here at the\n"
	.string "same time is a labor of love.\p"
	.string "I learned that this world was created\n"
	.string "for you and for some reason I have this\l"
	.string "feeling that I had a big part in that.\p"
	.string "And the fact you're standing here now\n"
	.string "means you've actually engaged with it.\p"
	.string "That means more to me than you know.\p"
	.string "Alright. Anyways…\p"
	.string "There's one last thing to do.\p"
	.string "For the final battle and any\n"
	.string "adventures that follow it…\p"
	.string "Ashley, I choose you!$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Look at that. You won.\n"
	.string "You really won.\p"
	.string "I'm realizing something else right now,\n"
	.string "{PLAYER}{KUN}.\p"
	.string "That I'm in love with you.$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "Steven: What a terrific battle!\p"
	.string "You and your Pokémon displayed a real\n"
	.string "mastery of your skills.\p"
	.string "We all stand before you at the\n"
	.string "peak of the Pokémon League.\p"
	.string "{PLAYER}{KUN}…\p"
	.string "You are now the new Hoenn Champion!$"

EverGrandeCity_ChampionsRoom_Text_StevenComeWithMe:
	.string "Steven: Ben, would you please escort\n"
	.string "our new Champion to the next room?\p"
	.string "Ben: It would be my pleasure.$"

EverGrandeCity_ChampionsRoom_Text_LetsGo:
	.string "Ben: Let's go, Champion.$"

EverGrandeCity_ChampionsRoom_Text_GumpWait:
	.string "WAAAAAAAIT!!!!!!$"

EverGrandeCity_ChampionsRoom_Text_RivalDad:
	.string "Ben: Dad?!\p"
	.string "Cece: Gump?!\n"
	.string "Kit: Gump?!$"

EverGrandeCity_ChampionsRoom_Text_GumpRatePokedex:
	.string "Gump: Wait! I'm sorry, but…\p"
	.string "Can I rate your Pokédex real quick?$"

EverGrandeCity_ChampionsRoom_Text_AreYouSerious:
	.string "Ben: Are you serious?!\n"
	.string "Can't it wait?\p"
	.string "Gump: Hey, I deserve it since all this\n"
	.string "pretty much happened because of me!\p"
	.string "I'm just messing with ya sweetie\n"
	.string "but we really should take a look.\p"
	.string "The progress of your Pokédex is a\n"
	.string "milestone that shouldn't go ignored!$"

EverGrandeCity_ChampionsRoom_Text_GumpCongratulations:
	.string "Gump: Alright. Anyways…\n"
	.string "congratulations!\p"
	.string "Now, go proudly into the final room!$"

