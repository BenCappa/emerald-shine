Route120_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route120_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route120_OnLoad
	.byte 0

Route120_OnLoad:
	call_if_unset FLAG_REGI_DOORS_OPENED, Route120_EventScript_CloseAncientTomb
	call_if_unset FLAG_HIDE_ROUTE_120_RIVAL_ON_BIKE, Route120_EventScript_HideRivalOnBike
	end

Route120_EventScript_HideRivalOnBike::
	removeobject LOCALID_ROUTE120_RIVAL_ON_BIKE
	setflag FLAG_HIDE_ROUTE_120_RIVAL_ON_BIKE
	return

Route120_EventScript_CloseAncientTomb::
	setmetatile 7, 54, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 7, 55, METATILE_General_RockWall_SandBase, TRUE
	return

Route120_OnTransition:
	call Common_EventScript_SetupRivalGfxId
@	call Common_EventScript_SetupRivalOnBikeGfxId
	call GabbyAndTy_EventScript_UpdateLocation
	call Route120_EventScript_SetWeather
	end

Route120_EventScript_SetWeather::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_le VAR_TEMP_1, 14, Route120_EventScript_SetSunnyWeather
	goto_if_le VAR_TEMP_1, 60, Route120_EventScript_TrySetRainyWeather
	goto_if_ge VAR_TEMP_1, 61, Route120_EventScript_SetCloudyWeather
	return

Route120_EventScript_SetCloudyWeather::
	setweather WEATHER_SUNNY_CLOUDS
	return

Route120_EventScript_SetSunnyWeather::
	setweather WEATHER_SUNNY
	return

Route120_EventScript_TrySetRainyWeather::
	goto_if_le VAR_TEMP_0, 7, Route120_EventScript_SetRainyWeather
	goto_if_le VAR_TEMP_0, 19, Route120_EventScript_SetSunnyWeather
	goto Route120_EventScript_SetRainyWeather
	end

Route120_EventScript_SetRainyWeather::
	setweather WEATHER_RAIN
	return

Route120_EventScript_BerryBeauty::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_ROUTE_120_RECEIVED_BERRY, Route120_EventScript_ReceivedBerry
	msgbox Route120_Text_BerriesExpressionOfLoveIsntIt, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route120_EventScript_BerryLove
	call_if_eq VAR_RESULT, NO, Route120_EventScript_BerryNotLove
	specialvar VAR_RESULT, GetPlayerTrainerIdOnesDigit
	switch VAR_RESULT
	case 0, Route120_EventScript_GiveFigyBerry
	case 5, Route120_EventScript_GiveFigyBerry
	case 1, Route120_EventScript_GiveWikiBerry
	case 6, Route120_EventScript_GiveWikiBerry
	case 2, Route120_EventScript_GiveMagoBerry
	case 7, Route120_EventScript_GiveMagoBerry
	case 3, Route120_EventScript_GiveAguavBerry
	case 8, Route120_EventScript_GiveAguavBerry
	case 4, Route120_EventScript_GiveIapapaBerry
	case 9, Route120_EventScript_GiveIapapaBerry
	end

Route120_EventScript_GiveFigyBerry::
	setvar VAR_0x8004, ITEM_FIGY_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveWikiBerry::
	setvar VAR_0x8004, ITEM_WIKI_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveMagoBerry::
	setvar VAR_0x8004, ITEM_MAGO_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveAguavBerry::
	setvar VAR_0x8004, ITEM_AGUAV_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveIapapaBerry::
	setvar VAR_0x8004, ITEM_IAPAPA_BERRY
	goto Route120_EventScript_GiveBerry
	end

Route120_EventScript_GiveBerry::
	giveitem VAR_0x8004
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_ROUTE_120_RECEIVED_BERRY
	msgbox Route120_Text_BerryIsRareRaiseItWithCare, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_ReceivedBerry::
	msgbox Route120_Text_IllGetMoreBerriesFromBerryMaster, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_BerryLove::
	msgbox Route120_Text_YesYouUnderstand, MSGBOX_DEFAULT
	return

Route120_EventScript_BerryNotLove::
	msgbox Route120_Text_MakeYourOwnImpressions, MSGBOX_DEFAULT
	return

Route120_EventScript_Rival::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, Route120_EventScript_RivalFaceTheGym
	msgbox Route120_Text_RivalExplanation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE120_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	releaseall
	end

Route120_EventScript_RivalFaceTheGym::
	msgbox Route120_Text_RivalFaceTheGym, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE120_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	releaseall
	end

Route120_EventScript_Siblings::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_FORTREE_GYM, Route120_EventScript_SiblingsFaceTheGym
	goto Route120_EventScript_SiblingsAskReadyForBattle
	end

Route120_EventScript_SiblingsFaceTheGym::
	msgbox Route120_Text_SiblingsFaceTheGym, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Route120_EventScript_SiblingsAskReadyForBattle::
	msgbox Route120_Text_SiblingsReadyToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route120_EventScript_ChoosePartyForMultiBattle
	applymovement LOCALID_ROUTE120_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox Route120_Text_RivalNotReady, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE120_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	releaseall
	end

Route120_EventScript_ChoosePartyForMultiBattle::
	special SavePlayerParty
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_ne VAR_RESULT, 0, Route120_EventScript_DetermineRivalMultiBattle
	special LoadPlayerParty
	goto Route120_EventScript_SiblingsAskReadyForBattle

Route120_EventScript_DetermineRivalMultiBattle::
	msgbox Route120_Text_SiblingsGonnaBeatYa, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route120_EventScript_RivalMultiBattleBulbasaur
	case 1, Route120_EventScript_RivalMultiBattleFennekin
	case 2, Route120_EventScript_RivalMultiBattlePiplup
	end

Route120_EventScript_RivalMultiBattleBulbasaur::
	multi_2_vs_2 TRAINER_CECE, Route120_Text_CeceDefeat, TRAINER_KIT, Route120_Text_KitDefeat, PARTNER_BEN_BULBASAUR
	switch VAR_RESULT
	case 1, Route120_EventScript_DefeatedSiblings
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

Route120_EventScript_RivalMultiBattleFennekin::
	multi_2_vs_2 TRAINER_CECE, Route120_Text_CeceDefeat, TRAINER_KIT, Route120_Text_KitDefeat, PARTNER_BEN_FENNEKIN
	switch VAR_RESULT
	case 1, Route120_EventScript_DefeatedSiblings
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

Route120_EventScript_RivalMultiBattlePiplup::
	multi_2_vs_2 TRAINER_CECE, Route120_Text_CeceDefeat, TRAINER_KIT, Route120_Text_KitDefeat, PARTNER_BEN_PIPLUP
	switch VAR_RESULT
	case 1, Route120_EventScript_DefeatedSiblings
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate

Route120_EventScript_DefeatedSiblings::
	msgbox Route120_Text_SiblingsDefeat, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_ROUTE120_STEVEN, Route120_Movement_StevenApproachSiblings
	waitmovement 0
	turnobject LOCALID_ROUTE120_CECE, DIR_WEST
	turnobject LOCALID_ROUTE120_KIT, DIR_WEST
	waitmovement 0
	msgbox Route120_Text_StevenThatWillBeAll, MSGBOX_DEFAULT
	applymovement LOCALID_ROUTE120_CECE, Route120_Movement_CeceHop
	msgbox Route120_Text_CeceOhRight, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE120_CECE, DIR_EAST
	turnobject LOCALID_ROUTE120_KIT, DIR_EAST
	delay 15
	msgbox Route120_Text_SiblingsByeGuys, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE120_STEVEN, DIR_SOUTH
	applymovement LOCALID_ROUTE120_CECE, Route120_Movement_CeceExit
	applymovement LOCALID_ROUTE120_KIT, Route120_Movement_KitExit
	delay 48
	turnobject LOCALID_ROUTE120_STEVEN, DIR_WEST
	waitmovement 0
	applymovement LOCALID_ROUTE120_STEVEN, Route120_Movement_StevenApproachRival
	waitmovement 0
	msgbox Route120_Text_StevenSorryToPutYouThroughThat, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE120_STEVEN, Route120_Movement_StevenApproachPlayer
	waitmovement 0
	msgbox Route120_Text_StevenHaveAGift, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route120_EventScript_StevenGiveVenusaurite
	case 1, Route120_EventScript_StevenGiveDelphoxite
	case 2, Route120_EventScript_StevenGiveEmpoleonite
	end

Route120_EventScript_StevenGiveVenusaurite::
	giveitem ITEM_VENUSAURITE
	setflag FLAG_RECEIVED_STARTER_MEGA_STONE
	goto Route120_EventScript_StevenExit
	end

Route120_EventScript_StevenGiveDelphoxite::
	giveitem ITEM_DELPHOXITE
	setflag FLAG_RECEIVED_STARTER_MEGA_STONE
	goto Route120_EventScript_StevenExit
	end

Route120_EventScript_StevenGiveEmpoleonite::
	giveitem ITEM_EMPOLEONITE
	setflag FLAG_RECEIVED_STARTER_MEGA_STONE
	goto Route120_EventScript_StevenExit
	end

Route120_EventScript_StevenExit::
	msgbox Route120_Text_StevenThePowerOfMegaStones, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE120_STEVEN, Route120_Movement_StevenWalkAway
	waitmovement 0
	delay 90
	msgbox Route120_Text_StevenSomethingIsComing, MSGBOX_DEFAULT
	closemessage
	delay 15
	turnobject LOCALID_ROUTE120_STEVEN, DIR_EAST
	waitmovement 0
	msgbox Route120_Text_StevenRiseToTheOccasion, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE120_STEVEN, DIR_SOUTH
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject LOCALID_ROUTE120_STEVEN
	waitfieldeffect FLDEFF_NPCFLY_OUT
	delay 60
	goto Route120_EventScript_RivalExit
	end

Route120_EventScript_RivalExit::
	turnobject LOCALID_ROUTE120_RIVAL, DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	waitmovement 0
	msgbox Route120_Text_RivalHaveAnyIdea, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE120_RIVAL, DIR_WEST
	waitmovement 0
	delay 24
	msgbox Route120_Text_RivalFamiliar, MSGBOX_DEFAULT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	closemessage
	delay 120
	waitbuttonpress
	turnobject LOCALID_ROUTE120_RIVAL, DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	waitmovement 0
	msgbox Route120_Text_RivalHeadedToLilycove, MSGBOX_DEFAULT
	closemessage
	removeobject LOCALID_ROUTE120_RIVAL
	addobject LOCALID_ROUTE120_RIVAL_ON_BIKE
	setobjectxy LOCALID_ROUTE120_RIVAL_ON_BIKE, 17, 15
	delay 24
	applymovement LOCALID_ROUTE120_RIVAL_ON_BIKE, Route120_Movement_RivalExit
	delay 24
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	waitmovement 0
	removeobject LOCALID_ROUTE120_RIVAL_ON_BIKE
	setflag FLAG_HIDE_ROUTE_120_BRIDGE_ENCOUNTERS
	releaseall
	end

Route120_Movement_StevenApproachSiblings:
	walk_right
	walk_right
	step_end

Route120_Movement_StevenApproachRival:
	walk_right
	step_end

Route120_Movement_StevenApproachPlayer:
	walk_down
	face_player
	step_end

Route120_Movement_StevenWalkAway:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

Route120_Movement_CeceHop:
	jump_in_place_left
	step_end

Route120_Movement_CeceExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route120_Movement_KitExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route120_Movement_RivalExit:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route120_EventScript_RouteSignFortree::
	msgbox Route120_Text_RouteSignFortree, MSGBOX_SIGN
	end

Route120_EventScript_RouteSign121::
	msgbox Route120_Text_RouteSign121, MSGBOX_SIGN
	end

Route120_EventScript_Colin::
	trainerbattle_single TRAINER_COLIN, Route120_Text_ColinIntro, Route120_Text_ColinDefeat
	msgbox Route120_Text_ColinPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Robert::
	trainerbattle_single TRAINER_ROBERT_1, Route120_Text_RobertIntro, Route120_Text_RobertDefeat, Route120_EventScript_RegisterRobert
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route120_EventScript_RematchRobert
	msgbox Route120_Text_RobertPostBattle, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_RegisterRobert::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route120_Text_RobertRegister, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_RematchRobert::
	trainerbattle_rematch TRAINER_ROBERT_1, Route120_Text_RobertRematchIntro, Route120_Text_RobertRematchDefeat
	msgbox Route120_Text_RobertPostRematch, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Lorenzo::
	trainerbattle_single TRAINER_LORENZO, Route120_Text_LorenzoIntro, Route120_Text_LorenzoDefeat
	msgbox Route120_Text_LorenzoPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Jenna::
	trainerbattle_single TRAINER_JENNA, Route120_Text_JennaIntro, Route120_Text_JennaDefeat
	msgbox Route120_Text_JennaPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY_1, Route120_Text_JeffreyIntro, Route120_Text_JeffreyDefeat, Route120_EventScript_RegisterJeffrey
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route120_EventScript_RematchJeffrey
	msgbox Route120_Text_JeffreyPostBattle, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_RegisterJeffrey::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route120_Text_JeffreyRegister, MSGBOX_DEFAULT
	release
	end

Route120_EventScript_RematchJeffrey::
	trainerbattle_rematch TRAINER_JEFFREY_1, Route120_Text_JeffreyRematchIntro, Route120_Text_JeffreyRematchDefeat
	msgbox Route120_Text_JeffreyPostRematch, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Jennifer::
	trainerbattle_single TRAINER_JENNIFER, Route120_Text_JenniferIntro, Route120_Text_JenniferDefeat
	msgbox Route120_Text_JenniferPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Chip::
	trainerbattle_single TRAINER_CHIP, Route120_Text_ChipIntro, Route120_Text_ChipDefeat
	msgbox Route120_Text_ChipPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA, Route120_Text_ClarissaIntro, Route120_Text_ClarissaDefeat
	msgbox Route120_Text_ClarissaPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Angelica::
	trainerbattle_single TRAINER_ANGELICA, Route120_Text_AngelicaIntro, Route120_Text_AngelicaDefeat
	msgbox Route120_Text_AngelicaPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Keigo::
	trainerbattle_single TRAINER_KEIGO, Route120_Text_KeigoIntro, Route120_Text_KeigoDefeat
	msgbox Route120_Text_KeigoPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Riley::
	trainerbattle_single TRAINER_RILEY, Route120_Text_RileyIntro, Route120_Text_RileyDefeat
	msgbox Route120_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Leonel::
	trainerbattle_single TRAINER_LEONEL, Route120_Text_LeonelIntro, Route120_Text_LeonelDefeat
	msgbox Route120_Text_LeonelPostBattle, MSGBOX_AUTOCLOSE
	end

Route120_EventScript_Callie::
	trainerbattle_single TRAINER_CALLIE, Route120_Text_CallieIntro, Route120_Text_CallieDefeat
	msgbox Route120_Text_CalliePostBattle, MSGBOX_AUTOCLOSE
	end

Route120_Text_RivalFaceTheGym:
	.string "Ben: Hey, {PLAYER}. I guess these two\n"
	.string "are gonna block the way forward for us\l"
	.string "until we beat them in a battle?\p"
	.string "I'm not sure what's going on but they\n"
	.string "say you need to beat the gym first,\l"
	.string "so you should probably do that.$"

Route120_Text_RivalExplanation:
	.string "Ben: {PLAYER}! Good, you're here now.\p"
	.string "These two aren't gonna let us through\n"
	.string "until we both beat them in a battle.\p"
	.string "It seems Steven Stone over there\n"
	.string "wants to test us or something.\p"
	.string "I'm expecting a challenge of some sort,\n"
	.string "but I'm ready if you are.$"

Route120_Text_RivalNotReady:
	.string "Ben: Don't worry.\p"
	.string "I'll be right here until you are.$"

Route120_Text_SiblingsFaceTheGym:
	.string "???: Mr. Stone says we can't battle you\n"
	.string "until you've beaten the Fortree Gym.$"

Route120_Text_SiblingsReadyToBattle:
	.string "???: So, sure you're ready to take\n"
	.string "on the both of us?$"

Route120_Text_SiblingsGonnaBeatYa:
	.string "???: We're gonna beat ya, Ben!\n"
	.string "???: We're gonna beat ya, {PLAYER}!$"

Route120_Text_SiblingsDefeat:
	.string "Cece: How did you do that?\p"
	.string "Kit: I want to battle again!$"

Route120_Text_CeceDefeat:
	.string "Cece: You beat us? No fair!$"

Route120_Text_KitDefeat:
	.string "Kit: You made me upset!$"

Route120_Text_StevenThatWillBeAll:
	.string "Calliope, Christopher, thank you.\n"
	.string "That will be all for now.$"

Route120_Text_CeceOhRight:
	.string "Cece: Oh, right!$"

Route120_Text_SiblingsByeGuys:
	.string "Cece: Buh-bye guys!\n"
	.string "Kit: We'll see you later!$"

Route120_Text_StevenSorryToPutYouThroughThat:
	.string "Steven: I'm sorry for putting you two\n"
	.string "through that but those two were eager\l"
	.string "eager to have a battle you both.\p"
	.string "I hope you found it as entertaining\n"
	.string "as they did.$"

Route120_Text_StevenHaveAGift:
	.string "Steven: Incidentally, I had gifts\n"
	.string "I wanted to give the two of you.\p"
	.string "I just needed to see how strong you\n"
	.string "had gotten before I handed them over.$"

Route120_Text_StevenThePowerOfMegaStones:
	.string "Steven: Mega Stones are very powerful,\n"
	.string "as I'm sure you've learned by now.\p"
	.string "But remember: true power is only\n"
	.string "achieved by exceptional Pokémon\l"
	.string "and their trainers.$"

Route120_Text_StevenSomethingIsComing:
	.string "Steven: Something is coming…\p"
	.string "The people of this region will need\n"
	.string "someone exceptional.$"

Route120_Text_StevenRiseToTheOccasion:
	.string "Steven: I look forward to seeing you\n"
	.string "both rise to the occasion.$"

Route120_Text_RivalHaveAnyIdea:
	.string "Ben: … … … … … …\p"
	.string "Do you have any idea what all that was?\p"
	.string "And what was with those two?\p"
	.string "Something about them was oddly…$"

Route120_Text_RivalFamiliar:
	.string "… … …familiar.\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

Route120_Text_RivalHeadedToLilycove:
	.string "Ah, whatever. It's probably nothing.\p"
	.string "I'm heading over to Lilycove now,\n"
	.string "see you there?\p"
	.string "Maybe we can try out these new\n"
	.string "Mega Stones while we're there.\p"
	.string "… … … … … …\p"
	.string "Alright, see ya.$"

Kecleon_Text_SomethingUnseeable:
	.string "$"

Kecleon_Text_WantToUseDevonScope:
	.string "$"

Kecleon_Text_UseDevonScopeMonAttacked:
	.string "$"
	
Route120_Text_RouteSignFortree:
	.string "ROUTE 120\n"
	.string "{LEFT_ARROW} FORTREE CITY$"

Route120_Text_RouteSign121:
	.string "{RIGHT_ARROW} ROUTE 121\n"
	.string "{LEFT_ARROW} ROUTE 120$"
