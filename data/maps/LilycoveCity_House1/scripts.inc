LilycoveCity_House1_MapScripts::
	.byte 0

LilycoveCity_House1_EventScript_ExpertM::
	msgbox LilycoveCity_House1_Text_PokemonPartnersNotTools, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_Magnemite::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGNEMITE, CRY_MODE_NORMAL
	msgbox LilycoveCity_House1_Text_Magnemite, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_House1_Text_PokemonPartnersNotTools:
	.string "Pokémon are partners to people.\n"
	.string "They aren't our tools.\p"
	.string "Unfortunately, there are some people\n"
	.string "who fail to understand that…$"

LilycoveCity_House1_Text_Magnemite:
	.string "Magnemite: Bzroro?$"

