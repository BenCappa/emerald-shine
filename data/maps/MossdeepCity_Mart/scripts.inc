MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Mart_EventScript_BattleClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartbattle 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_RepelKeepsWeakPokemonAway, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "Revives are fantastic!\p"
	.string "Give it to a fainted Pokémon,\n"
	.string "and they'll be healthy again.\p"
	.string "But be careful, Revives don't restore\n"
	.string "the used-up PP of moves.$"

MossdeepCity_Mart_Text_RepelKeepsWeakPokemonAway:
	.string "Repel keeps all the weak Pokémon away.\p"
	.string "Only Pokémon leveled higher than your\n"
	.string "lead Pokémon will jump out at you.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "The Net and Dive Balls are rare Poké\n"
	.string "Balls that are perfect for Mossdeep.\p"
	.string "A Net Ball is effective against\n"
	.string "Bug-type and Water-type Pokémon.\p"
	.string "A Dive Ball works best on Pokémon\n"
	.string "at the bottom of the sea.$"

