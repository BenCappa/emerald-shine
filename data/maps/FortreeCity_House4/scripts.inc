FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GARDEVOIRITE, FortreeCity_House4_EventScript_ICantBeAPrincess
	msgbox FortreeCity_House4_Text_ImFreakingOut, MSGBOX_DEFAULT
	giveitem ITEM_GARDEVOIRITE
	setflag FLAG_RECEIVED_GARDEVOIRITE
	msgbox FortreeCity_House4_Text_ICantBeAPrincess, MSGBOX_DEFAULT
	release
	end


FortreeCity_House4_EventScript_ICantBeAPrincess::
	msgbox FortreeCity_House4_Text_ICantBeAPrincess, MSGBOX_DEFAULT
	release
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_PelipperReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_PelipperOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applymovement LOCALID_FORTREE_HOUSE_WINGULL, FortreeCity_House4_Movement_PelipperExit
	waitmovement 0
	removeobject LOCALID_FORTREE_HOUSE_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_PelipperOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedPelipperToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_PelipperReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomePelipperTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToPelipper, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_PelipperExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Pelipper::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Pelipper, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_ImFreakingOut:
	.string "I'm freaking out!\p"
	.string "Imagine living for 15 years and then\n"
	.string "suddenly find out you're a princess!\p"
	.string "Then my grandmother gave me this\n"
	.string "precious Genovian stone as a bribe!\p"
	.string "You take it! I'm not ready for all this!$"

FortreeCity_House4_Text_ICantBeAPrincess:
	.string "I can't be a princess!\p"
	.string "I'm still waiting for normal body parts\n"
	.string "to arrive!$"

FortreeCity_House4_Text_GoBirdPokemon:
	.string "There!\n"
	.string "Go, Pelipper!$"

FortreeCity_House4_Text_AskedPelipperToRunErrand:
	.string "Heheh, I've trained my Pelipper to run\n"
	.string "errands for me.\p"
	.string "It seems more fun than getting\n"
	.string "involved in Mia's whole thing right now.$"

FortreeCity_House4_Text_WelcomePelipperTakeMentalHerb:
	.string "Awesome!\n"
	.string "Welcome back, Pelipper!\p"
	.string "Huh? What is this?\n"
	.string "What is it holding?\p"
	.string "A Mental Herb?\n"
	.string "It must have picked it up somewhere.\p"
	.string "But I'm not a Trainer, so you can\n"
	.string "have it.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToPelipper:
	.string "Thanks to my Pelipper, I'll be able to\n"
	.string "have friends who live places far away.\p"
	.string "Places like Genovia!$"

FortreeCity_House4_Text_Pelipper:
	.string "Pelipper: Pirryoh!$"

