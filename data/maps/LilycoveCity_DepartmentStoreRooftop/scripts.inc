LilycoveCity_DepartmentStoreRooftop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_DepartmentStoreRooftop_OnTransition
	.byte 0

LilycoveCity_DepartmentStoreRooftop_OnTransition:
	getpokenewsactive POKENEWS_LILYCOVE
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman::
	clearflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman::
	setflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale:
	.2byte DECOR_MUD_BALL
	.2byte DECOR_FENCE_LENGTH
	.2byte DECOR_FENCE_WIDTH
	.2byte DECOR_TIRE
	.2byte DECOR_BREAKABLE_DOOR
	.2byte DECOR_SOLID_BOARD
	.2byte DECOR_SAND_ORNAMENT
	.2byte DECOR_STAND
	.2byte DECOR_SLIDE
	.2byte DECOR_TV
	.2byte DECOR_ROUND_TV
	.2byte DECOR_CUTE_TV
	.2byte DECOR_WAILMER_DOLL
	.2byte DECOR_RHYDON_DOLL
	.2byte 0
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Man::
	lock
	faceplayer
	getpokenewsactive POKENEWS_LILYCOVE
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LEFTOVERS, LilycoveCity_DepartmentStoreRooftop_EventScript_Burp
	goto_if_set FLAG_GAVE_SODA_POP, LilycoveCity_DepartmentStoreRooftop_EventScript_OfferLeftovers
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty, MSGBOX_DEFAULT
	checkitem ITEM_SODA_POP, 1
	compare VAR_RESULT, 1
	goto_if_ge LilycoveCity_DepartmentStoreRooftop_EventScript_GiveManSoda
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_GiveManSoda::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_GiveManSoda, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_RefusedManSoda
	removeitem ITEM_SODA_POP, 1
	setflag FLAG_GAVE_SODA_POP
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_OfferLeftovers
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_RefusedManSoda::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_RefuseManSoda, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_OfferLeftovers::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_HitsTheSpot, MSGBOX_DEFAULT
	checkitemspace ITEM_LEFTOVERS, 1
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_YoureStuffedToo
	giveitem ITEM_LEFTOVERS, 1
	setflag FLAG_RECEIVED_LEFTOVERS
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_YoureStuffedToo::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_YoureStuffedToo, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Burp::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_Burp, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_VendingMachine::
	lockall
	goto_if_unset FLAG_RECEIVED_GENGARITE, LilycoveCity_DepartmentStoreRooftop_EventScript_SomethingUnderneath
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SomethingUnderneath::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_SomethingUnderneath, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_DepartmentStoreRooftop_EventScript_IgnoredGengarite
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_PulledOutGengarite, MSGBOX_DEFAULT
	giveitem ITEM_GENGARITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_GENGARITE
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_VendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_IgnoredGengarite::
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater
	case 1, LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop
	case 2, LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater::
	checkmoney 200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop::
	checkmoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade::
	checkmoney 350
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink::
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 chance of an additional drink dropping
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink::
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
	waitmessage
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales:
	.string "Don't they have set dates for their\n"
	.string "clear-out sales?\p"
	.string "I watch TV, but they never show any\n"
	.string "commercials.$"

LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale:
	.string "Yes! I've been waiting a long time for\n"
	.string "this clear-out sale.\p"
	.string "They have items that you can only get\n"
	.string "here. I'm going to load up, that I am!$"

LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty:
	.string "Ohh… I'm bone-dry thirsty!\p"
	.string "I bought too much food and didn't have\n"
	.string "enough money left over for a soda!$"

LilycoveCity_DepartmentStoreRooftop_Text_GiveManSoda:
	.string "Will you give the man a Soda Pop?$"

LilycoveCity_DepartmentStoreRooftop_Text_RefuseManSoda:
	.string "Your Pokémon need it more.$"

LilycoveCity_DepartmentStoreRooftop_Text_HitsTheSpot:
	.string "Ah, that hits the spot.\p"
	.string "I'm completely satisfied, you should\n"
	.string "have my Leftovers.$"

LilycoveCity_DepartmentStoreRooftop_Text_YoureStuffedToo:
	.string "Woah, looks like you're stuffed too.\n"
	.string "You have no room for these Leftovers.$"

LilycoveCity_DepartmentStoreRooftop_Text_Burp:
	.string "BUUUURP!$"

LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike:
	.string "It's a Vending Machine.\n"
	.string "Which drink would you like?$"

LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "A can of {STR_VAR_1} dropped down.$"

LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra can of {STR_VAR_1}\n"
	.string "dropped down!$"

LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney:
	.string "Not enough money…$"

LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink:
	.string "Decided against buying a drink.$"

LilycoveCity_DepartmentStoreRooftop_Text_SomethingUnderneath:
	.string "Something is glinting from the shadow\n"
	.string "underneath the vending machine.\p"
	.string "Would you like to pick it up?$"

LilycoveCity_DepartmentStoreRooftop_Text_PulledOutGengarite:
	.string "You reached under and picked up the\n"
	.string "sparkling stone.$"
