RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "For my own Pokémon, I give them\n"
	.string "perfectly unique names!\p"
	.string "It's my expression of, uh…\n"
	.string "originality, yes, that's it!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "But naming your Pikachu “Peekachu”\n"
	.string "feels like being different for the\p"
	.string "sake of being different.\n"
	.string "I wonder if it even cares though…$"

RustboroCity_House3_Text_Pekachu:
	.string "Peekachu: Peeka!$"

