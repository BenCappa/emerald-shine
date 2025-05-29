DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Pyukumuku::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PYUKUMUKU, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Pyukumuku, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "There's a lot to be said for living on\n"
	.string "a small island like this in harmony with\l"
	.string "Pokémon and without property taxes.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "I left the major port of Slateport\n"
	.string "City when I married my husband here.\p"
	.string "Life goes by slowly on this little\n"
	.string "island. But being surrounded by the\l"
	.string "beautiful sea--that's happiness, too.\p"
	.string "At least, that's what he tells me.$"

DewfordTown_House1_Text_Pyukumuku:
	.string "Pyukumuku: Gugugugugah!$"

