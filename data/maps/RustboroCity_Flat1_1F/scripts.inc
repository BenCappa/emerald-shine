RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man::
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility:
	.string "Every Pokémon has a special Ability\n"
	.string "that provides a passive effect in\l"
	.string "battles and the overworld.$"

RustboroCity_Flat1_1F_Text_PokemonStrange:
	.string "A Hidden Ability is an Ability that\n"
	.string "a Pokémon doesn't normally have.\p"
	.string "I hear DevCo is making an app that's\n"
	.string "good at finding Pokémon with them.$"

