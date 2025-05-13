MauvilleCity_GameCorner_MapScripts::
	.byte 0

    @ Game Corner prices
	.set LOADED_DICE_COINS, 1500
	.set CHOICE_BAND_COINS, 3500
	.set CHOICE_SPECS_COINS, 4000
	.set CHOICE_SCARF_COINS, 4000

	.set PP_UP_COINS, 1000
	.set LINKING_CORD_COINS, 4000
	.set AUSPICIOUS_ARMOR_COINS, 4000
	.set MALICIOUS_ARMOR_COINS, 4000

	.set DITTO_COINS, 6500
	.set WONDER_TRADE_COINS, 1000

	.set COINS_PRICE_50,  1000
	.set COINS_PRICE_500, 10000

	.set MONEY_PRICE_1000,  50
	.set MONEY_PRICE_10000, 500

MauvilleCity_GameCorner_EventScript_MoneyExchangeMachine::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_MoneyExchangeMachine, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
	message MauvilleCity_GameCorner_Text_ExchangeForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto MauvilleCity_GameCorner_EventScript_ChooseCoins

MauvilleCity_GameCorner_EventScript_CoinExchangeMachine::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_CoinExchangeMachine, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NeedCoinCase
	message MauvilleCity_GameCorner_Text_ExchangeForMoney
	waitmessage
	showcoinsbox 0, 0
	showmoneybox 1, 6
	goto MauvilleCity_GameCorner_EventScript_ChooseMoney

MauvilleCity_GameCorner_EventScript_ChooseCoins::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy50Coins
	case 1, MauvilleCity_GameCorner_EventScript_Buy500Coins
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_ChooseMoney::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_Buy1000Money
	case 1, MauvilleCity_GameCorner_EventScript_Buy10000Money
	goto MauvilleCity_GameCorner_EventScript_CancelBuyCoins
	end

MauvilleCity_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_Buy1000Money::
	checkcoins VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, MONEY_PRICE_1000, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addmoney 1000
	removecoins MONEY_PRICE_1000
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), MauvilleCity_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_Buy10000Money::
	checkcoins VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, MONEY_PRICE_10000, MauvilleCity_GameCorner_EventScript_NotEnoughMoney
	addmoney 10000
	removecoins MONEY_PRICE_10000
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NeedCoinCase::
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_NotEnoughMoney::
	msgbox MauvilleCity_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_CancelBuyCoins::
	msgbox MauvilleCity_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomForCoins::
	msgbox MauvilleCity_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_NoRoomForMoney::
	msgbox MauvilleCity_GameCorner_Text_MoneyCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

@ Held Items Prize Corner
MauvilleCity_GameCorner_EventScript_PrizeCornerHeldItems::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseHeldItemPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseHeldItemPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseHeldItemPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseHeldItemPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseHeldItemPrize

MauvilleCity_GameCorner_EventScript_ChooseHeldItemPrize::
	dynmultichoice 12, 0, FALSE, 5, FALSE, DYN_MULTICHOICE_CB_NONE, MauvilleCity_GameCorner_Text_LoadedDicePrice, MauvilleCity_GameCorner_Text_ChoiceBandPrice, MauvilleCity_GameCorner_Text_ChoiceSpecsPrice, MauvilleCity_GameCorner_Text_ChoiceScarfPrice, MauvilleCity_GameCorner_Text_Exit
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_LoadedDice
	case 1, MauvilleCity_GameCorner_EventScript_ChoiceBand
	case 2, MauvilleCity_GameCorner_EventScript_ChoiceSpecs
	case 3, MauvilleCity_GameCorner_EventScript_ChoiceScarf
	case 4, MauvilleCity_GameCorner_EventScript_Exit
	goto MauvilleCity_GameCorner_EventScript_Exit
	end

MauvilleCity_GameCorner_EventScript_LoadedDice::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_LOADED_DICE
	goto MauvilleCity_GameCorner_EventScript_ConfirmHeldItemPrize

MauvilleCity_GameCorner_EventScript_ChoiceBand::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_CHOICE_BAND
	goto MauvilleCity_GameCorner_EventScript_ConfirmHeldItemPrize

MauvilleCity_GameCorner_EventScript_ChoiceSpecs::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_CHOICE_SPECS
	goto MauvilleCity_GameCorner_EventScript_ConfirmHeldItemPrize

MauvilleCity_GameCorner_EventScript_ChoiceScarf::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_CHOICE_SCARF
	goto MauvilleCity_GameCorner_EventScript_ConfirmHeldItemPrize

MauvilleCity_GameCorner_EventScript_ConfirmHeldItemPrize::
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_Exit
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyLoadedDice
	case 2, MauvilleCity_GameCorner_EventScript_BuyChoiceBand
	case 3, MauvilleCity_GameCorner_EventScript_BuyChoiceSpecs
	case 4, MauvilleCity_GameCorner_EventScript_BuyChoiceScarf
	end

MauvilleCity_GameCorner_EventScript_BuyLoadedDice::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, LOADED_DICE_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForHeldItem
	bufferitemname STR_VAR_2, ITEM_LOADED_DICE
	checkitemspace ITEM_LOADED_DICE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForHeldItem
	removecoins LOADED_DICE_COINS
	additem ITEM_LOADED_DICE
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseHeldItemPrize
	end

MauvilleCity_GameCorner_EventScript_BuyChoiceBand::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, CHOICE_BAND_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForHeldItem
	bufferitemname STR_VAR_2, ITEM_CHOICE_BAND
	checkitemspace ITEM_CHOICE_BAND
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForHeldItem
	removecoins CHOICE_BAND_COINS
	additem ITEM_CHOICE_BAND
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseHeldItemPrize
	end

MauvilleCity_GameCorner_EventScript_BuyChoiceSpecs::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, CHOICE_SPECS_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForHeldItem
	bufferitemname STR_VAR_2, ITEM_CHOICE_SPECS
	checkitemspace ITEM_CHOICE_SPECS
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForHeldItem
	removecoins CHOICE_SPECS_COINS
	additem ITEM_CHOICE_SPECS
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseHeldItemPrize
	end

MauvilleCity_GameCorner_EventScript_BuyChoiceScarf::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, CHOICE_SCARF_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForHeldItem
	bufferitemname STR_VAR_2, ITEM_CHOICE_SCARF
	checkitemspace ITEM_CHOICE_SCARF
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForHeldItem
	removecoins CHOICE_SCARF_COINS
	additem ITEM_CHOICE_SCARF
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseHeldItemPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForHeldItem::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseHeldItemPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForHeldItem::
	call Common_EventScript_BagIsFull
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseHeldItemPrize
	end

@ Evolution Items Prize Corner
MauvilleCity_GameCorner_EventScript_PrizeCornerEvoItems::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_ChooseEvoItemPrizeMessage
	release
	end

MauvilleCity_GameCorner_EventScript_ChooseEvoItemPrizeMessage::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto MauvilleCity_GameCorner_EventScript_ChooseEvoItemPrize

MauvilleCity_GameCorner_EventScript_ReturnToChooseEvoItemPrize::
	message MauvilleCity_GameCorner_Text_WhichPrize
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_ChooseEvoItemPrize

MauvilleCity_GameCorner_EventScript_ChooseEvoItemPrize::
	dynmultichoice 12, 0, FALSE, 5, FALSE, DYN_MULTICHOICE_CB_NONE, MauvilleCity_GameCorner_Text_PPUpPrice, MauvilleCity_GameCorner_Text_LinkingCordPrice, MauvilleCity_GameCorner_Text_AuspiciousArmorPrice, MauvilleCity_GameCorner_Text_MaliciousArmorPrice, MauvilleCity_GameCorner_Text_Exit
	switch VAR_RESULT
	case 0, MauvilleCity_GameCorner_EventScript_PPUp
	case 1, MauvilleCity_GameCorner_EventScript_LinkingCord
	case 2, MauvilleCity_GameCorner_EventScript_AuspiciousArmor
	case 3, MauvilleCity_GameCorner_EventScript_MaliciousArmor
	case 4, MauvilleCity_GameCorner_EventScript_Exit
	goto MauvilleCity_GameCorner_EventScript_Exit
	end

MauvilleCity_GameCorner_EventScript_PPUp::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_PP_UP
	goto MauvilleCity_GameCorner_EventScript_ConfirmEvoItemPrize

MauvilleCity_GameCorner_EventScript_LinkingCord::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_LINKING_CORD
	goto MauvilleCity_GameCorner_EventScript_ConfirmEvoItemPrize

MauvilleCity_GameCorner_EventScript_AuspiciousArmor::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_AUSPICIOUS_ARMOR
	goto MauvilleCity_GameCorner_EventScript_ConfirmEvoItemPrize

MauvilleCity_GameCorner_EventScript_MaliciousArmor::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_MALICIOUS_ARMOR
	goto MauvilleCity_GameCorner_EventScript_ConfirmEvoItemPrize

MauvilleCity_GameCorner_EventScript_ConfirmEvoItemPrize::
	msgbox MauvilleCity_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_Exit
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_BuyPPUp
	case 2, MauvilleCity_GameCorner_EventScript_BuyLinkingCord
	case 3, MauvilleCity_GameCorner_EventScript_BuyAuspiciousArmor
	case 4, MauvilleCity_GameCorner_EventScript_BuyMaliciousArmor
	end

MauvilleCity_GameCorner_EventScript_BuyPPUp::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, PP_UP_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForEvoItem
	bufferitemname STR_VAR_2, ITEM_PP_UP
	checkitemspace ITEM_PP_UP
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForEvoItem
	removecoins PP_UP_COINS
	additem ITEM_PP_UP
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseHeldItemPrize
	end

MauvilleCity_GameCorner_EventScript_BuyLinkingCord::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, LINKING_CORD_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForEvoItem
	bufferitemname STR_VAR_2, ITEM_LINKING_CORD
	checkitemspace ITEM_LINKING_CORD
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForEvoItem
	removecoins LINKING_CORD_COINS
	additem ITEM_LINKING_CORD
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseHeldItemPrize
	end

MauvilleCity_GameCorner_EventScript_BuyAuspiciousArmor::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, AUSPICIOUS_ARMOR_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForEvoItem
	bufferitemname STR_VAR_2, ITEM_AUSPICIOUS_ARMOR
	checkitemspace ITEM_AUSPICIOUS_ARMOR
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForEvoItem
	removecoins AUSPICIOUS_ARMOR_COINS
	additem ITEM_AUSPICIOUS_ARMOR
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseHeldItemPrize
	end

MauvilleCity_GameCorner_EventScript_BuyMaliciousArmor::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, MALICIOUS_ARMOR_COINS, MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForEvoItem
	bufferitemname STR_VAR_2, ITEM_MALICIOUS_ARMOR
	checkitemspace ITEM_MALICIOUS_ARMOR
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForEvoItem
	removecoins MALICIOUS_ARMOR_COINS
	additem ITEM_MALICIOUS_ARMOR
	updatecoinsbox 1, 1
	playse SE_SHOP
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseHeldItemPrize
	end

MauvilleCity_GameCorner_EventScript_NotEnoughCoinsForEvoItem::
	msgbox MauvilleCity_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseEvoItemPrize
	end

MauvilleCity_GameCorner_EventScript_NoRoomForEvoItem::
	call Common_EventScript_BagIsFull
	goto MauvilleCity_GameCorner_EventScript_ReturnToChooseEvoItemPrize
	end

MauvilleCity_GameCorner_EventScript_Exit::
	msgbox MauvilleCity_GameCorner_Text_ThankYouForPlaying, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_PrizeCornerTMs::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_WouldYouLikeToBuyATM, MSGBOX_DEFAULT
	waitmessage
	pokemart MauvilleCity_GameCorner_TMs
	msgbox MauvilleCity_GameCorner_Text_ThankYouForPlaying, MSGBOX_DEFAULT
	release
	end

.align 2
MauvilleCity_GameCorner_TMs::
	.2byte ITEM_TM_U_TURN
	.2byte ITEM_TM_FLAMETHROWER
	.2byte ITEM_TM_THUNDERBOLT
	.2byte ITEM_TM_ICE_BEAM
	.2byte ITEM_TM_SLUDGE_BOMB
	.2byte ITEM_TM_PSYSHOCK
	.2byte ITEM_TM_SUBSTITUTE
	.2byte ITEM_TM_ATTRACT
	pokemartlistend

MauvilleCity_GameCorner_EventScript_Woman2::
	msgbox MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Gentleman::
	msgbox MauvilleCity_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

MauvilleCity_GameCorner_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	msgbox MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_DeclineStarterDoll
	switch VAR_STARTER_MON
	case 0, MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll
	case 1, MauvilleCity_GameCorner_EventScript_GiveTorchicDoll
	case 2, MauvilleCity_GameCorner_EventScript_GiveMudkipDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTreeckoDoll::
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TREECKO_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveTorchicDoll::
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TORCHIC_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_GiveMudkipDoll::
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox MauvilleCity_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_MUDKIP_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll
	end

MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll::
	call Common_EventScript_NoRoomForDecor
	msgbox MauvilleCity_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_DeclineStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_ReceivedStarterDoll::
	msgbox MauvilleCity_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
	release
	end

MauvilleCity_GameCorner_EventScript_PokefanM::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_GameCorner_EventScript_OfferTrade
	msgbox MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_OfferTrade::
	goto_if_set FLAG_TRADED_DITTO, MauvilleCity_GameCorner_EventScript_PokefanMNormal
	showcoinsbox 1, 1
	msgbox MauvilleCity_GameCorner_Text_TradeDittoForCoins, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_YourLoss
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DITTO_COINS, MauvilleCity_GameCorner_EventScript_NiceTryKid
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_DITTO
	givemon SPECIES_DITTO, 15
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MauvilleCity_GameCorner_EventScript_ReceiveDittoParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MauvilleCity_GameCorner_EventScript_ReceiveDittoPC
	end

MauvilleCity_GameCorner_EventScript_ReceiveDittoParty::
	call MauvilleCity_GameCorner_EventScript_ReceivedDittoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_PleasureDoingBusiness
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MauvilleCity_GameCorner_EventScript_PleasureDoingBusiness
	end

MauvilleCity_GameCorner_EventScript_ReceiveDittoPC::
	call MauvilleCity_GameCorner_EventScript_ReceivedDittoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_GameCorner_EventScript_SentDittoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MauvilleCity_GameCorner_EventScript_PleasureDoingBusiness
	end

MauvilleCity_GameCorner_EventScript_SentDittoToPC::
	call Common_EventScript_TransferredToPC
	goto MauvilleCity_GameCorner_EventScript_PleasureDoingBusiness
	end

MauvilleCity_GameCorner_EventScript_ReceivedDittoFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message MauvilleCity_GameCorner_Text_PlayerReceivedDitto
	waitmessage
	waitfanfare
	return

MauvilleCity_GameCorner_EventScript_NiceTryKid::
	msgbox MauvilleCity_GameCorner_Text_NiceTryKid, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_YourLoss::
	hidecoinsbox 0, 0
	msgbox MauvilleCity_GameCorner_Text_YourLoss, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_PleasureDoingBusiness::
	hidecoinsbox 0, 0
	msgbox MauvilleCity_GameCorner_Text_PleasureDoingBusiness, MSGBOX_DEFAULT
	setflag FLAG_TRADED_DITTO
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_PokefanMNormal::
	msgbox MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_OldMan::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Cook::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Man::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_NPCReturnToSlots::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_EventScript_Maniac::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto MauvilleCity_GameCorner_EventScript_NPCReturnToSlots
	end

MauvilleCity_GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_NoCoinCase::
	msgbox MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_GameCorner_Text_MoneyExchangeMachine:
	.string "MAUVILLE GAME CORNER\n"
	.string "- MONEY EXCHANGE MACHINE$"

MauvilleCity_GameCorner_Text_CoinExchangeMachine:
	.string "MAUVILLE GAME CORNER\n"
	.string "- COIN EXCHANGE MACHINE$"

MauvilleCity_GameCorner_Text_NeedCoinCaseForCoins:
	.string "The Exchange Machine needs a\n"
	.string "Coin Case in order to work.$"

MauvilleCity_GameCorner_Text_ExchangeForCoins:
	.string "THE RATE IS ¥1000 FOR 50 COINS.\n"
	.string "WOULD YOU LIKE TO EXCHANGE?$"

MauvilleCity_GameCorner_Text_ExchangeForMoney:
	.string "THE RATE IS 50 COINS FOR ¥1000.\n"
	.string "WOULD YOU LIKE TO EXCHANGE?$"

MauvilleCity_GameCorner_Text_ThankYouHereAreYourCoins:
	.string "THANK YOU FOR PLAYING!\n"
	.string "HERE ARE YOUR COINS!$"

MauvilleCity_GameCorner_Text_DontHaveEnoughMoney:
	.string "INSUFFICIENT FUNDS.\n"
	.string "THIS EXCHANGE CANNOT BE COMPLETED.$"

MauvilleCity_GameCorner_Text_CoinCaseIsFull:
	.string "NO ROOM FOR MORE COINS.\n"
	.string "THIS EXCHANGE CANNOT BE COMPLETED.$"

MauvilleCity_GameCorner_Text_MoneyCaseIsFull:
	.string "NO ROOM FOR MORE MONEY.\n"
	.string "THIS EXCHANGE CANNOT BE COMPLETED.$"

MauvilleCity_GameCorner_Text_DontNeedCoinsThen:
	.string "THANK YOU FOR PLAYING AT THE\n"
	.string "MAUVILLE GAME CORNER!$"

MauvilleCity_GameCorner_Text_ExchangeCoinsForPrizes:
	.string "Welcome.\p"
	.string "You can exchange your Coins for\n"
	.string "prizes here.$"

MauvilleCity_GameCorner_Text_WhichPrize:
	.string "Which prize would you like?$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsTheTMX:
	.string "So your choice is\n"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"

MauvilleCity_GameCorner_Text_WouldYouLikeToBuyATM:
	.string "Welcome.\p"
	.string "Would you like to purchase a\n"
	.string "Technical Machine?$"

MauvilleCity_GameCorner_Text_NotEnoughCoins:
	.string "You don't have enough Coins.$"

@ Unused
MauvilleCity_GameCorner_Text_NoRoomForPlacingDecor:
	.string "There isn't any room available for\n"
	.string "placing {STR_VAR_1}.$"

MauvilleCity_GameCorner_Text_ThankYouForPlaying:
	.string "Thank you for playing at the\n"
	.string "Mauville Game Corner!$"

MauvilleCity_GameCorner_Text_SoYourChoiceIsX:
	.string "So your choice is {STR_VAR_1}?$"

MauvilleCity_GameCorner_Text_HereYouGo:
	.string "Here you go!$"

@ Unused
MauvilleCity_GameCorner_Text_CantCarryAnyMore:
	.string "Oh, you can't carry any more than that.$"

MauvilleCity_GameCorner_Text_GotTwoOfSameDollWantOne:
	.string "I made a mistake and got two of\n"
	.string "the same Dolls.\p"
	.string "Would you like one of them?$"

MauvilleCity_GameCorner_Text_HereYouGo2:
	.string "Here you go!$"

MauvilleCity_GameCorner_Text_YouWantItButNotNow:
	.string "Huh?\n"
	.string "You want it, but not right now?$"

MauvilleCity_GameCorner_Text_DontBeNegative:
	.string "Oh, don't be so negative!\n"
	.string "You can have this!$"

MauvilleCity_GameCorner_Text_CantWinJackpot:
	.string "There's a prize I want, but I can't win\n"
	.string "the jackpot.$"

MauvilleCity_GameCorner_Text_NeedCoinCaseGoNextDoor:
	.string "Hey, kid, I'll trade some rare Pokémon\n"
	.string "with ya but only if ya got Coins!\p"
	.string "And ya need a Coin Case to get Coins.\p"
	.string "I think the annoying guy who lives\n"
	.string "next door had one. I'd go see him!$"

MauvilleCity_GameCorner_Text_TradeDittoForCoins:
	.string "Ya think ya might be interested in\n"
	.string "trading a Ditto for, let's say,\l"
	.string "6,500 Coins?$"

MauvilleCity_GameCorner_Text_PlayerReceivedDitto:
	.string "{PLAYER} received Ditto!$"

MauvilleCity_GameCorner_Text_NiceTryKid:
	.string "Nice try, kid.\n"
	.string "Come back when ya got enough Coins.$"

MauvilleCity_GameCorner_Text_YourLoss:
	.string "Ah, whatever. Your loss, kid.$"

MauvilleCity_GameCorner_Text_PleasureDoingBusiness:
	.string "Pleasure doing business with ya.$"

MauvilleCity_GameCorner_Text_MauvilleSomethingForEveryone:
	.string "Mauville has something for\n"
	.string "everyone.\p"
	.string "For me, it's the Game Corner.$"

MauvilleCity_GameCorner_Text_RouletteTablesDifferentRates:
	.string "The Roulette tables have different\n"
	.string "rates.\p"
	.string "Check your Coins if you're going to\n"
	.string "pick a table.$"

MauvilleCity_GameCorner_Text_EasyToLoseTrackOfTime:
	.string "It's easy to lose track of time in here. \n"
	.string "I should get back to work.$"

MauvilleCity_GameCorner_Text_CoinsAreNeededToPlay:
	.string "Coins are needed to play here\n"
	.string "in the Game Corner.$"

MauvilleCity_GameCorner_Text_RouletteOnlyLuck:
	.string "This Roulette thing…\n"
	.string "It's rather demanding.\p"
	.string "Win or lose, it's only by luck.$"

MauvilleCity_GameCorner_Text_UpTo3CoinsCanBeUsed:
	.string "Up to three Coins can be used to play\n"
	.string "the Slots.$"

MauvilleCity_GameCorner_Text_DifficultToStopOn7:
	.string "It's very difficult to make it stop\n"
	.string "right on “7.”\p"
	.string "If it stops on “7” during the Reel Time\n"
	.string "bonus game, you'll receive extra Coins.$"

MauvilleCity_GameCorner_Text_HeresSomeSlotsInfo:
	.string "Here's some information for you\n"
	.string "about the Slots.\p"
	.string "The more lightning bolts you stock,\n"
	.string "the more Reel Time chances you get.\p"
	.string "In a game with the maximum five\n"
	.string "Reel Time chances…\p"
	.string "It is possible to receive four regular\n"
	.string "bonuses, then a big bonus.\p"
	.string "That would total 660 Coins, but it's\n"
	.string "very difficult to get.$"

MauvilleCity_GameCorner_Text_CantPlayWithNoCoinCase:
	.string "You can't play if you don't have\n"
	.string "a Coin Case.$"

MauvilleCity_GameCorner_Text_LoadedDicePrice:
	.string "Loaded Dice{CLEAR_TO 0x48}1,500 Coins$"

MauvilleCity_GameCorner_Text_ChoiceBandPrice:
	.string "Choice Band{CLEAR_TO 0x48}3,500 Coins$"

MauvilleCity_GameCorner_Text_ChoiceSpecsPrice:
	.string "Choice Specs{CLEAR_TO 0x48}4,000 Coins$"

MauvilleCity_GameCorner_Text_ChoiceScarfPrice:
	.string "Choice Scarf{CLEAR_TO 0x48}4,000 Coins$"

MauvilleCity_GameCorner_Text_PPUpPrice:
	.string "PP Up{CLEAR_TO 0x52}500 Coins$"

MauvilleCity_GameCorner_Text_LinkingCordPrice:
	.string "Linking Cord{CLEAR_TO 0x48}1,000 Coins$"

MauvilleCity_GameCorner_Text_AuspiciousArmorPrice:
	.string "Aus. Armor{CLEAR_TO 0x48}2,000 Coins$"

MauvilleCity_GameCorner_Text_MaliciousArmorPrice:
	.string "Mal. Armor{CLEAR_TO 0x48}2,000 Coins$"

MauvilleCity_GameCorner_Text_Exit:
	.string "Exit$"
