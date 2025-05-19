MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForMoomooMilk
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForMoomooMilk::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	giveitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_MOOMOO_MILK
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "I'm so thirsty…\p"
	.string "Water's good and all I'm just dying for\n"
	.string "some Moomoo Milk right now.\p"
	.string "Like the kind they sell on the\n"
	.string "Slateport Beach…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "Oh! You have a some Moomoo Milk?\n"
	.string "Can I please have it? I'm desperate!\l"
	.string "How 'bout a trade for this Coin Case?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "Oh, what a relief!\n"
	.string "Here's that Coin Case I promised you.$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "That Moomoo Milk totally hit the spot.\n"
	.string "I am getting a bit hungry though…$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "Why not?! You're literally killing me!\p"
	.string "Plus, you'll need a Coin Case if you want\n"
	.string "to play at the Game Corner!$"

