GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Cece::
	msgbox GraniteCave_StevensRoom_Text_Cece, MSGBOX_NPC
	end

GraniteCave_StevensRoom_EventScript_Kit::
	msgbox GraniteCave_StevensRoom_Text_Kit, MSGBOX_NPC
	end

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SMART_STRIKE
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRANITE_CAVE_CECE, GraniteCave_StevensRoom_Movement_CeceMoveToLeft
	applymovement LOCALID_GRANITE_CAVE_KIT, GraniteCave_StevensRoom_Movement_KitMoveToRight
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_StevensRoom_EventScript_StevenExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_StevensRoom_EventScript_StevenExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_StevensRoom_EventScript_StevenExitWestEast
	playse SE_EXIT
	removeobject LOCALID_GRANITE_CAVE_STEVEN
	applymovement LOCALID_GRANITE_CAVE_CECE, GraniteCave_StevensRoom_Movement_CeceExit
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GRANITE_CAVE_CECE
	applymovement LOCALID_GRANITE_CAVE_KIT, GraniteCave_StevensRoom_Movement_KitExit
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GRANITE_CAVE_KIT
	release
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement LOCALID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_CeceMoveToLeft:
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

GraniteCave_StevensRoom_Movement_KitMoveToRight:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

GraniteCave_StevensRoom_Movement_CeceExit:
	walk_right
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_KitExit:
	walk_left
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "My name is Steven.\p"
	.string "I'm interested in rare stones,\n"
	.string "so I travel here and there.\p"
	.string "Oh?\n"
	.string "A Letter for me?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "Steven: Okay, thank you.\p"
	.string "You went through all this trouble to\n"
	.string "deliver that. I need to thank you.\p"
	.string "Let me see…\n"
	.string "I'll give you this TM.\p"
	.string "It contains my favorite move,\n"
	.string "Smart Strike.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "Steven: Your Pokémon appear quite\n"
	.string "capable.\p"
	.string "If you keep training, you could even\n"
	.string "become the Champion of the Pokémon\l"
	.string "League one day. That's what I think.\p"
	.string "I know, since we've gotten to know each\n"
	.string "other, let's register one another in\l"
	.string "our PokéNavs.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "Registered STEVEN\n"
	.string "in the POKéNAV.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "Now, I've got to hurry along.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Oh, your Bag is full…\n"
	.string "That's too bad, then.$"

GraniteCave_StevensRoom_Text_Cece:
	.string "???: My brother and I are assistants to\n"
	.string "Steven. It's been a lot of fun so far!$"

GraniteCave_StevensRoom_Text_Kit:
	.string "???: I'm honestly just here because I'll\n"
	.string "do whatever my sister is doing.$"

