DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LUCKY_EGG, DewfordTown_House2_EventScript_ExplainLuckyEgg
	msgbox DewfordTown_House2_Text_WantYouToHaveLuckyEgg, MSGBOX_DEFAULT
	giveitem ITEM_LUCKY_EGG
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForEgg
	setflag FLAG_RECEIVED_LUCKY_EGG
	release
	end

DewfordTown_House2_EventScript_NoRoomForEgg::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainLuckyEgg::
	msgbox DewfordTown_House2_Text_ExplainLuckyEgg, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveLuckyEgg:
	.string "Gorge your eyes on this!\p"
	.string "It's a Lucky Egg, the must-have\n"
	.string "accessory for training Pokémon!\p"
	.string "Oh, I can see your eyes twinkling!\n"
	.string "You could probably use one of these!\p"
	.string "Aren't you in luck then?\n"
	.string "Here you go. I want you to have it!$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, you don't have room?\n"
	.string "How unfotunate.\p"
	.string "Now, listen tight, this Egg is a must-\n"
	.string "have! Why, I would sell all my items\l"
	.string "in order to get it!$"

DewfordTown_House2_Text_ExplainLuckyEgg:
	.string "A Lucky Egg is full of happiness!\p"
	.string "Whenever a Pokémon holds one they'll\n"
	.string "gain extra Experience Points!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Wow, you bothered to cross the sea\n"
	.string "to visit Dewford?\p"
	.string "Did you maybe come here because you\n"
	.string "wanna battle Niles?\p"
	.string "Wait… you're his sister?\n"
	.string "How many does he have?$"

