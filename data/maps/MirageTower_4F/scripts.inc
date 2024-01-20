.set LOCALID_SKULL_FOSSIL, 1
.set LOCALID_SAIL_FOSSIL, 2

MirageTower_4F_MapScripts::
	.byte 0

MirageTower_4F_EventScript_SkullFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeSkullFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveSkullFossil
	giveitem ITEM_SKULL_FOSSIL
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_SKULL_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_SAIL_FOSSIL
	removeobject LOCALID_SKULL_FOSSIL
	delay 30
	setflag FLAG_CHOSE_SKULL_FOSSIL
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveSkullFossil::
	msgbox MirageTower_4F_Text_LeftSkullFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_SailFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeSailFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveSailFossil
	giveitem ITEM_SAIL_FOSSIL
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_SAIL_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_SKULL_FOSSIL
	removeobject LOCALID_SAIL_FOSSIL
	delay 30
	setflag FLAG_CHOSE_SAIL_FOSSIL
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveSailFossil::
	msgbox MirageTower_4F_Text_LeaveSailFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_CollapseMirageTower::
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 32  @ num shakes
	setvar VAR_0x8007, 2   @ shake delay
	special ShakeCamera
	waitstate
	special DoMirageTowerCeilingCrumble
	waitstate
	setvar VAR_MIRAGE_TOWER_STATE, 1
	clearflag FLAG_LANDMARK_MIRAGE_TOWER
	warp MAP_ROUTE111, 19, 59
	waitstate
	release
	end

MirageTower_4F_Text_TakeSkullFossil:
	.string "You found the Skull FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the Skull FOSSIL anyway?$"

MirageTower_4F_Text_LeftSkullFossilAlone:
	.string "{PLAYER} left the Skull FOSSIL alone.$"

MirageTower_4F_Text_TakeSailFossil:
	.string "You found the Sail FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the Sail FOSSIL anyway?$"

MirageTower_4F_Text_LeaveSailFossilAlone:
	.string "{PLAYER} left the Sail FOSSIL alone.$"

