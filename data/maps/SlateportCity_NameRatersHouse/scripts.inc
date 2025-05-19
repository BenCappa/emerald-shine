SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	goto_if_set FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, SlateportCity_NameRatersHouse_EventScript_ReuniteThePair
	goto_if_set FLAG_LATIOS_OR_LATIAS_ROAMING, SlateportCity_NameRatersHouse_EventScript_CheckSteed
	goto SlateportCity_NameRatersHouse_EventScript_BringMeASteed
	end

SlateportCity_NameRatersHouse_EventScript_CheckSteed::
	call SlateportCity_NameRatersHouse_EventScript_DetermineSteedToCheckFor
	checkspecies VAR_0x8004
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_GiveEonTicket
	goto SlateportCity_NameRatersHouse_EventScript_BringMeASteed
	end

SlateportCity_NameRatersHouse_EventScript_DetermineSteedToCheckFor::
	copyvar VAR_ROAMER_POKEMON, VAR_RESULT
	switch VAR_RESULT
	case 0, SlateportCity_NameRatersHouse_EventScript_CheckForGlastrier
	case 1, SlateportCity_NameRatersHouse_EventScript_CheckForSpectrier
	return

SlateportCity_NameRatersHouse_EventScript_CheckForGlastrier::
	setvar VAR_0x8004, SPECIES_GLASTRIER
	return

SlateportCity_NameRatersHouse_EventScript_CheckForSpectrier::
	setvar VAR_0x8004, SPECIES_SPECTRIER
	return

SlateportCity_NameRatersHouse_EventScript_BringMeASteed::
	msgbox SlateportCity_NameRatersHouse_Text_BringMeASteed, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_GiveEonTicket::
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox SlateportCity_NameRatersHouse_Text_GiveEonTicket, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	goto SlateportCity_NameRatersHouse_EventScript_ReuniteThePair
	end

SlateportCity_NameRatersHouse_EventScript_ReuniteThePair::
	msgbox SlateportCity_NameRatersHouse_Text_ReuniteThePair, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_BringMeASteed:
	.string "I find myself reminiscing in my old age\n"
	.string "of tales I heard from my youth.\p"
	.string "Legends tell us of these two brutal\n"
	.string "forces of famine that were tamed into\l"
	.string "noble steeds by an ancient king.\p"
	.string "However, as the years crept on, time\n"
	.string "made the king weak.\p"
	.string "Sensing his waning power, the steeds\n"
	.string "returned to the wild to roam free again.\p"
	.string "It may sound silly to entertain,\n"
	.string "but would you bring a steed to me\l"
	.string "should they ever appear again?\p"
	.string "It may just help this old man feel\n"
	.string "young again.$"

SlateportCity_NameRatersHouse_Text_GiveEonTicket:
	.string "Wait, could it be?\n"
	.string "That Pokémon with you… is it…\p"
	.string "It is!\n"
	.string "It's {STR_VAR_1}!\p"
	.string "Please, take this!\n"
	.string "It is important.$"

SlateportCity_NameRatersHouse_Text_ReuniteThePair:
	.string "I never thought I'd see them again…\p"
	.string "Knowing you possess the strength to\n"
	.string "tame them finally brings me peace.\p"
	.string "Please, venture to the Southern Island\n"
	.string "and reunite the pair.\p"
	.string "The responsibility lies with you now…$"
