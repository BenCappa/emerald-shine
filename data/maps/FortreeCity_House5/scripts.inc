FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Wiglett::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WIGLETT, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Wiglett, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "The tree houses of Fortree are great!\p"
	.string "I think it's the number one town for\n"
	.string "living together with Pokémon.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "Pokémon and people have adapted to\n"
	.string "nature for survival.\p"
	.string "There's no need to make nature\n"
	.string "conform to the way we want to live.$"

FortreeCity_House5_Text_Wiglett:
	.string "Wiglett: Squequeuu!\p"
	.string "The Wiglett looks stressed out.$"

