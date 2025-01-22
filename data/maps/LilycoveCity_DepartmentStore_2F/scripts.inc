LilycoveCity_DepartmentStore_2F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_2F_EventScript_Cook::
	lock
	faceplayer
	msgbox LilycoveCity_DepartmentStore_2F_Text_CookGreeting, MSGBOX_NPC
	waitmessage
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart_Cook
	msgbox LilycoveCity_DepartmentStore_2F_Text_CookGoodbye, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_2F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_Sailor::
	msgbox LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_2F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartbattle 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_2F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_2F_Pokemart_Cook:
	.2byte ITEM_SYRUPY_APPLE
	.2byte ITEM_CRACKED_POT
	.2byte ITEM_CHIPPED_POT
	pokemartlistend

LilycoveCity_DepartmentStore_2F_Text_CookGreeting:
	.string "Ah, bonjour!\p"
	.string "I 'ave few rare delicacies for\n"
	.string "you an' your Pokémon!\p"
	.string "You will buy something, non?$"

LilycoveCity_DepartmentStore_2F_Text_CookGoodbye:
	.string "À plus tard!$"

LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband:
	.string "My husband is waiting at home.\n"
	.string "What would make a good gift for him?$"

LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems:
	.string "I'm leaving on a long journey soon.\n"
	.string "I need to stock up on items.$"

