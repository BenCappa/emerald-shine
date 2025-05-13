FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_AmnesiaGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_AMNESIA, FortreeCity_House2_EventScript_ExplainAmnesia
	call_if_unset FLAG_MET_AMNESIA_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_GiveAmnesia, MSGBOX_DEFAULT
	giveitem ITEM_TM_AMNESIA
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_AMNESIA
	msgbox FortreeCity_House2_Text_ExplainAmnesia, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox AmnesiaFortreeCity_House2_Text_MemoriesAreMorePowerful, MSGBOX_DEFAULT
	setflag FLAG_MET_AMNESIA_GIVER
	return

FortreeCity_House2_EventScript_ExplainAmnesia::
	msgbox FortreeCity_House2_Text_ExplainAmnesia, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

AmnesiaFortreeCity_House2_Text_MemoriesAreMorePowerful:
	.string "People… Pokémon…\p"
	.string "Our memories are more powerful than\n"
	.string "we often realize…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Let this old woman see how strong your\n"
	.string "memory is…\p"
	.string "I hold a coin in my hand.\p"
	.string "Now, tell me, have I palmed it in\n"
	.string "the right hand? Or in the left?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Correct!\p"
	.string "Once more.\p"
	.string "In which hand have I palmed the coin?\n"
	.string "The right or left?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Yes, correct!\p"
	.string "One last time.\p"
	.string "In which hand have I palmed the coin?\n"
	.string "The right or left?$"

FortreeCity_House2_Text_GiveAmnesia:
	.string "Oh! Splendid!\n"
	.string "You wield memory with aplomb!\p"
	.string "Here, take this so your Pokémon may\n"
	.string "wield that same power in battle.$"

FortreeCity_House2_Text_ExplainAmnesia:
	.string "Amnesia allows the user to empty its\n"
	.string "mind and forget its concerns.\p"
	.string "Doing so boosts their Sp. Def stat.\p"
	.string "Wait, did I already tell you that?$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "You guessed wrong, but don't fret.\n"
	.string "Remember the pattern and try again.$"
