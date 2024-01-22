.set LOCALID_FOSSIL, 1

DesertUnderpass_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	.byte 0

DesertUnderpass_OnTransition:
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	end

DesertUnderpass_EventScript_Fossil::
	lock
	faceplayer
	goto_if_set FLAG_CHOSE_SKULL_FOSSIL, DesertUnderpass_EventScript_GiveSailFossil
	goto_if_set FLAG_CHOSE_SAIL_FOSSIL, DesertUnderpass_EventScript_GiveSkullFossil
	release
	end

DesertUnderpass_EventScript_GiveSailFossil::
	giveitem ITEM_SAIL_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeobject LOCALID_FOSSIL
	release
	end

DesertUnderpass_EventScript_GiveSkullFossil::
	giveitem ITEM_SKULL_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeobject LOCALID_FOSSIL
	release
	end

@ Unused
DesertUnderpass_Text_FoundSkullFossil::
	.string "{PLAYER} found the Skull FOSSIL.$"

@ Unused
DesertUnderpass_Text_FoundSailFossil::
	.string "{PLAYER} found the Sail FOSSIL.$"

