PacifidlogTown_House3_MapScripts::
	.byte 0

PacifidlogTown_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_DRATINI, PacifidlogTown_House3_Text_WillingToTradeIt, PacifidlogTown_House3_EventScript_DeclineTrade, PacifidlogTown_House3_EventScript_NotRequestedMon, PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

PacifidlogTown_House3_EventScript_DeclineTrade::
	msgbox PacifidlogTown_House3_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_TradeCompleted::
	msgbox PacifidlogTown_House3_Text_ReallyWantedToGetBagon, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House3_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, PacifidlogTown_House3_EventScript_YouveProvenYourself
	msgbox PacifidlogTown_House3_Text_NotReadyForMegaEvolution, MSGBOX_NPC
	release
	end

PacifidlogTown_House3_EventScript_YouveProvenYourself::
	goto_if_set FLAG_RECEIVED_GARCHOMPITE, PacifidlogTown_House3_EventScript_NotReadyForMegaEvolution
	msgbox PacifidlogTown_House3_Text_YouSeeTruePotential, MSGBOX_DEFAULT
	giveitem ITEM_GARCHOMPITE
	setflag FLAG_RECEIVED_GARCHOMPITE
	release
	end

PacifidlogTown_House3_EventScript_NotReadyForMegaEvolution::
	msgbox PacifidlogTown_House3_Text_NotReadyForMegaEvolution, MSGBOX_NPC
	release
	end

PacifidlogTown_House3_Text_WillingToTradeIt:
	.string "I was told this {STR_VAR_2} is supposed\n"
	.string "to evolve into a super strong Pokémon!\p"
	.string "I've been training it for what feels\n"
	.string "like forever but it hasn't evolved yet!\p"
	.string "What a waste of time!\n"
	.string "… … … … … … … … … Hey, do you want it?\p"
	.string "I might be willing to trade it for a\n"
	.string "super strong Dragon-type Pokémon\l"
	.string "like… … … {STR_VAR_1}!$"

PacifidlogTown_House3_Text_ItsSubtlyDifferentThankYou:
	.string "Oh, so this is a {STR_VAR_1}? Awesome!\p"
	.string "Now I get all the epic power without\n"
	.string "all the boring training!\p"
	.string "Hope that {STR_VAR_2} works out for ya!$"

PacifidlogTown_House3_Text_WontAcceptAnyLessThanRealMon:
	.string "No, no, no! I won't accept any less\n"
	.string "than a fully-evolved {STR_VAR_1}!$"

PacifidlogTown_House3_Text_NotDesperateOrAnything:
	.string "Oh, come on! It's not that bad!\p"
	.string "I even caught a girl-colored one by\n"
	.string "mistake, so you'd totally love it!$"

PacifidlogTown_House3_Text_ReallyWantedToGetBagon:
	.string "Seriously, what gives?\p"
	.string "Your Kingdra is seriously strong,\n"
	.string "but it won't listen to a word I say!\p"
	.string "I can't believe I still have to train…$"

PacifidlogTown_House3_Text_NotReadyForMegaEvolution:
	.string "My little brother over there wants to\n"
	.string "be a world-famous Dragon Tamer but\l"
	.string "he keeps cutting corners to get there.\p"
	.string "He's not ready for Mega Evolution.$"

PacifidlogTown_House3_Text_YouSeeTruePotential:
	.string "I see you accepted the trade my little\n"
	.string "brother was offering.\p"
	.string "You obviously see the true potential\n"
	.string "that Dragon Pokémon can achieve.\p"
	.string "Please, take this$"

