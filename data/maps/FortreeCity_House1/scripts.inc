FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	lock
	faceplayer
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "I'm accompanying my queen as we meet\n"
	.string "with Her Majesty's granddaughter.\p"
	.string "I bred many {STR_VAR_2} eggs in hopes\n"
	.string "a female would hatch and, just my luck,\l"
	.string "two females ended up hatching!\p"
	.string "Having heard that, would you be willing\n"
	.string "to trade my extra {STR_VAR_2} for,\l"
	.string "let's say, a {STR_VAR_1}?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "My sincerest gratitude.\p"
	.string "Welcome to the royal service, {STR_VAR_1}.\n"
	.string "Treat {STR_VAR_2} like royalty!$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Oh, no, I don't think that's right.\n"
	.string "That isn't a {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "No? You won't trade for my Pokémon?\n"
	.string "Even though it's technically royalty?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "I think Mothim suits an old man like me,\n"
	.string "don't you agree?$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "A queen does not fret, but Amelia must\n"
	.string "understand that if she refuses to\l"
	.string "accept the throne, then Genovia will\l"
	.string "cease to exist as we know it.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "Zigzagoon: Gumomoh?$"

