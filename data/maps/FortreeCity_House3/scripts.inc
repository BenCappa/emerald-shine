FortreeCity_House3_MapScripts::
	.byte 0

FortreeCity_House3_EventScript_Man::
	msgbox FortreeCity_House3_Text_RunningOutOfIdeas, MSGBOX_NPC
	end

FortreeCity_House3_EventScript_Youngster::
	lock
	goto_if_set FLAG_ITEM_FORTREE_CITY_HOUSE_3_TM_GRASS_KNOT, FortreeCity_House3_EventScript_CheckOnTheTM
	msgbox FortreeCity_House3_Text_PartOfMyNinjaTraining, MSGBOX_DEFAULT
	release
	end

FortreeCity_House3_EventScript_CheckOnTheTM::
	msgbox FortreeCity_House3_Text_CheckOnTheTM, MSGBOX_DEFAULT
	release
	end

FortreeCity_House3_Text_RunningOutOfIdeas:
	.string "My little brother convinced himself\n"
	.string "that I can teach him to be a ninja.\p"
	.string "I'm trying to keep him away from any\n"
	.string "swords but I've run out of ideas!\p"
	.string "At this point I have him guarding an\n"
	.string "extra TM that I was gonna throw away.\p"
	.string "Hopefully I can think of something\n"
	.string "else before he catches wise…$"

FortreeCity_House3_Text_PartOfMyNinjaTraining:
	.string "My big brother has me guarding this TM\n"
	.string "behind me as part of my ninja training!\p"
	.string "This apparently helps build my\n"
	.string "perception and spatial awareness…\l"
	.string "which are admittedly lacking.\p"
	.string "I won't move a muscle!$"

FortreeCity_House3_Text_CheckOnTheTM:
	.string "Can you check on the TM behind me?\p"
	.string "I heard something move but I can't\n"
	.string "look since I'm watching the door.$"

