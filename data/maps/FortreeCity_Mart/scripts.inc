FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

FortreeCity_Mart_EventScript_BattleClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartbattle 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_LuresAreTheBest, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_LuresAreTheBest:
	.string "Lures are the best if you're trying\n"
	.string "to fill out your Pokédex.\p"
	.string "I hear they even make Shiny Pokémon\n"
	.string "more likely to show up too!$"

FortreeCity_Mart_Text_StockUpOnItems:
	.string "I always stock up on more items than\n"
	.string "I'm sure I'll need.\p"
	.string "You never know what might happen.\n"
	.string "Better to be safe than sorry!$"

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.string "A Rare Candy can level up a Pokémon\n"
	.string "even past the current Level Cap.$"

