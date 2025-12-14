SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SilcoonBrother::
	special GetSilcoonSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSilcoon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSilcoon
	special CompareSilcoonSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSilcoon
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSilcoon
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSilcoon
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSilcoon::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSilcoon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSilcoon::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSilcoon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSilcoon::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSilcoon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSilcoon::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanCascoon, MSGBOX_DEFAULT
	giveitem ITEM_PP_UP
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForPPUp1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForPPUp1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CascoonBrother::
	special GetCascoonSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigCascoon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowCascoon
	special CompareCascoonSize
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotCascoon
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallCascoon
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigCascoon
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowCascoon::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigCascoon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotCascoon::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotCascoon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallCascoon::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerCascoon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigCascoon::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSilcoon, MSGBOX_DEFAULT
	giveitem ITEM_PP_UP
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForPPUp2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForPPUp2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SilcoonSizeRecord::
	special GetSilcoonSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSilcoonInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CascoonSizeRecord::
	special GetCascoonSizeRecordInfo
	lockall
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestCascoonInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSilcoon:
	.string "Do you know the Pokémon Silcoon?\n"
	.string "It's hardly ever seen in Sootopolis.\p"
	.string "Anyway, I love big Silcoon.\n"
	.string "The bigger the better.\p"
	.string "But my younger brother, he says that\n"
	.string "Cascoon is bigger.\p"
	.string "That's silly.\n"
	.string "Silcoon has to be bigger than that!\p"
	.string "Huh? Do you have a Silcoon with you?\n"
	.string "P-p-please, show me!$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanCascoon:
	.string "{STR_VAR_2}!\n"
	.string "Oh, my gosh, this is a big one!\p"
	.string "It might even beat the big Cascoon\n"
	.string "my younger brother saw!\p"
	.string "Thanks for showing me.\n"
	.string "This is my thanks!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} received a Potion.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "Hunh?\n"
	.string "Your Bag is crammed full.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSilcoon:
	.string "{STR_VAR_2}, is it?\p"
	.string "Hmm… I've seen a bigger Silcoon\n"
	.string "than this one.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSilcoon:
	.string "Oh, now this is quite something…\n"
	.string "But it's not a Silcoon!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSilcoon:
	.string "You don't have a big Silcoon?\n"
	.string "That's too bad…\p"
	.string "If you get a big Silcoon, please\n"
	.string "come show me.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSilcoonInHistory:
	.string "The biggest Silcoon in history!\n"
	.string "{STR_VAR_2}'s {STR_VAR_3} giant!\p"
	.string "A Silcoon bigger than a Cascoon\n"
	.string "always wanted!$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigCascoon:
	.string "Do you know the Pokémon Cascoon?\n"
	.string "It's rarely seen in Sootopolis.\p"
	.string "I love, I mean love, big Cascoon!\p"
	.string "My big brother says that Silcoon is\n"
	.string "bigger.\p"
	.string "But that's wrong! Everyone knows that\n"
	.string "Cascoon is a lot bigger.\p"
	.string "Hunh? Do you have a Cascoon?\n"
	.string "P-p-please show me!$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSilcoon:
	.string "{STR_VAR_2}!\n"
	.string "Wow, that is big!\p"
	.string "It might be even bigger than the huge\n"
	.string "Silcoon my big brother saw.\p"
	.string "Thanks for showing me!\n"
	.string "This is my thanks!$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} received a Potion.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "Hunh?\n"
	.string "Your Bag is crammed full.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerCascoon:
	.string "{STR_VAR_2}?\p"
	.string "Hmm… I've seen a bigger Cascoon\n"
	.string "than this one here.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotCascoon:
	.string "Well, isn't this something!\n"
	.string "But it's no Cascoon!$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigCascoon:
	.string "Don't you have a big Cascoon?\n"
	.string "How disappointing…\p"
	.string "If you get a big Cascoon, please\n"
	.string "come show me!$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestCascoonInHistory:
	.string "The biggest Cascoon in history!\n"
	.string "{STR_VAR_2}'s {STR_VAR_3} colossus!\p"
	.string "A Cascoon bigger than a Silcoon\n"
	.string "always wanted!$"

