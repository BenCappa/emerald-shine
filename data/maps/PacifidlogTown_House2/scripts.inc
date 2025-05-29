PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_GRACIDEA, PacifidlogTown_House2_EventScript_ExplainGracidea
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveGracidea
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_GiveGracidea::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GRACIDEA
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_GRACIDEA
	msgbox PacifidlogTown_House2_Text_ExplainGracidea, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ExplainGracidea::
	msgbox PacifidlogTown_House2_Text_ExplainGracidea, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyZorua::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZORUA, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyZorua::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZORUA, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "Er-hem!\p"
	.string "I am the Pokémon Fan Club's most\n"
	.string "important person, the Chairman's\l"
	.string "younger brother.\p"
	.string "I'm here enjoying my vacation with\n"
	.string "Pokémon, yes, indeed.$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string "Ah!\n"
	.string "Your Pokémon…$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "This Pokémon clearly adores you!\p"
	.string "Pokémon fanatics like me are always so\n"
	.string "grateful to meet Trainers like you.\p"
	.string "Take this token of my appreciation,\n"
	.string "won't you?$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "Hmm…\n"
	.string "It's not bad, but it's also not good.\p"
	.string "You, as the Trainer, need to put in\n"
	.string "some more effort.$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "It has a vicious look to it.\p"
	.string "You need to take much better care of\n"
	.string "your Pokémon!$"

PacifidlogTown_House2_Text_ExplainGracidea:
	.string "Giving Gracidea flowers to someone you\n"
	.string "appreciate is a tradition from a region\l"
	.string "very far from here.\p"
	.string "The Trainer who taught me that said\n"
	.string "they have a special effect on a certain\l"
	.string "rare and mysterious Pokémon.\p"
	.string "I wish I could remember the name of it!$"

PacifidlogTown_House2_Text_Rurii:
	.string "Zorua: Rurii!$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "It appears to be very friendly with you.$"

PacifidlogTown_House2_Text_Rururi:
	.string "Zorua: Rururi…$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "It doesn't appear to like you very\n"
	.string "much.$"

