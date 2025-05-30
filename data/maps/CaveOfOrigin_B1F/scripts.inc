CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Steven::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_GoodYoureHere, MSGBOX_DEFAULT
	applymovement LOCALID_CAVE_OF_ORIGIN_STEVEN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox CaveOfOrigin_B1F_Text_StevenPause, MSGBOX_DEFAULT
	delay 30
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_StevenStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_STEVEN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_STEVEN, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_STEVEN
	clearflag FLAG_HIDE_SKY_PILLAR_STEVEN
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_GoodYoureHere:
	.string "Good, you're here {PLAYER}{KUN}.\p"
	.string "I should tell you, my interest in stones\n"
	.string "didn't come from my family name.\p"
	.string "No, you see stones, rocks, terra firma…\n"
	.string "They all preserve ancient history.\p"
	.string "What better way to make a lasting\n"
	.string "record than to set it in stone?$"

CaveOfOrigin_B1F_Text_StevenPause:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Within the stones of this cave are the\n"
	.string "records that reveal a long-forgotten\l"
	.string "solution our current problem.$"

CaveOfOrigin_B1F_Text_StevenStory:
	.string "Groudon and Kyogre, the two Pokémon\n"
	.string "wreaking havoc here, are considered\l"
	.string "to be super-ancient Pokémon.\p"
	.string "But there aren't just two super-\n"
	.string "ancient Pokémon.\p"
	.string "There is one more somewhere.\p"
	.string "Somewhere, there is a super-\n"
	.string "ancient Pokémon named Rayquaza.\p"
	.string "It's said that it was Rayquaza that\n"
	.string "becalmed the two combatants in\l"
	.string "the distant past.\p"
	.string "But even I have no clue as to\n"
	.string "Rayquaza's whereabouts…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "Steven: {PLAYER}{KUN}, do you perhaps\n"
	.string "know where Rayquaza is now?\p"
	.string "If you do, please tell me.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "Steven: The Cave of Origin?\p"
	.string "No, that's where we are now.\n"
	.string "I need you to think carefully!\p"
	.string "Can you remember anything at all during\n"
	.string "your journey that might hint at where\l"
	.string "Rayquaza might be right now?$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "Steven: Mt. Pyre?\p"
	.string "But when I met the old lady there\n"
	.string "earlier, she made no mention of it.\p"
	.string "I very much doubt that the old lady\n"
	.string "would try to hide something from me…\p"
	.string "{PLAYER}{KUN}, could you think about this\n"
	.string "more carefully for me?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "Steven: Huh? You don't remember?\n"
	.string "Hmm… That's a problem…\p"
	.string "Can't you remember somehow?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "Steven: The Sky Pillar?\p"
	.string "That's it! Of course!\n"
	.string "It must be the Sky Pillar!\p"
	.string "{PLAYER}{KUN}, there's not a moment to lose!\n"
	.string "We'll head to the Sky Pillar right away!$"

