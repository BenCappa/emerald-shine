RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_PICHU, RustboroCity_House1_Text_IllTradeIfYouWant, RustboroCity_House1_EventScript_DeclineTrade, RustboroCity_House1_EventScript_NotRequestedMon, RustboroCity_House1_Text_PleaseBeGoodToMyPokemon
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "We had a {STR_VAR_1} at my old place that\n"
	.string "would cuddle in bed with me every night.\l"
	.string "Now that we moved, I can't fall asleep.\p"
	.string "Hey! You wouldn't happen to have a\n"
	.string "{STR_VAR_1}, would you?\p"
	.string "I'll trade you this funny-looking Pichu!$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Now I'm too excited to go to sleep!\n"
	.string "Show them lots of love for me, okay?$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Oh, if you don't want to, that's okay.\n"
	.string "This is a pretty cool Pokémon though…$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Mincinno and I are gonna eat a bunch of\n"
	.string "marshmallows and then die our hair pink!$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "When we moved here, I found a rather\n"
	.string "unique Pichu wandering around lost.\p"
	.string "I thought she'd like it as a partner,\n"
	.string "but I guess she's just too homesick.$"

