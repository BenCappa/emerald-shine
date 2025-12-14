MauvilleCity_Mart_MapScripts::
	.byte 0

MauvilleCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Mart_EventScript_BattleClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartbattle 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Mart_EventScript_ExpertM::
	msgbox MauvilleCity_Mart_Text_PartyFullOfPickupPokemon, MSGBOX_NPC
	end

MauvilleCity_Mart_EventScript_Man::
	msgbox MauvilleCity_Mart_Text_DecisionsDetermineBattle, MSGBOX_NPC
	end

MauvilleCity_Mart_Text_PartyFullOfPickupPokemon:
	.string "I have a party full of Pokémon all\n"
	.string "with the Pickup Ability.\p"
	.string "Winning a battle gives each of them a\n"
	.string "10% chance to pick a random item up.\p"
	.string "They aren't high enough level to pick\n"
	.string "up anything too valuable though…$"

MauvilleCity_Mart_Text_DecisionsDetermineBattle:
	.string "Use an attacking move to deal damage,\n"
	.string "or use a status move to set up…\p"
	.string "The Trainer's decisions determine how\n"
	.string "battles turn out, I think.$"

