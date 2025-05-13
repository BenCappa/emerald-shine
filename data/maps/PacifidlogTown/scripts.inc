PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_NASTY_PLOT, PacifidlogTown_EventScript_TellThemOfMyWoes
	msgbox PacifidlogTown_Text_HowIMissMyHusband, MSGBOX_DEFAULT
	giveitem ITEM_TM_NASTY_PLOT
	setflag FLAG_RECEIVED_TM_NASTY_PLOT
	goto PacifidlogTown_EventScript_TellThemOfMyWoes
	end

PacifidlogTown_EventScript_TellThemOfMyWoes::
	msgbox PacifidlogTown_Text_TellThemOfMyWoes, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "The sea between Pacifidlog and\n"
	.string "Slateport has a fast-running tide.\p"
	.string "If you decide to Surf, you could end\n"
	.string "up swept away somewhere else.$"

PacifidlogTown_Text_HowIMissMyHusband:
	.string "Oh, how I miss my dear husband.\p"
	.string "Despite all his fabulous wealth,\n"
	.string "he never paid for swimming lessons.\p"
	.string "Oh, how I regret begging him to\n"
	.string "take me here for our honeymoon.\p"
	.string "Take this and learn from my mistakes,\n"
	.string "young one!$"

PacifidlogTown_Text_TellThemOfMyWoes:
	.string "If an officer asks, you'll tell them\n"
	.string "of my woes, won't you?$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "The Sky Pillar?\p"
	.string "…Oh, you must mean that tall, tall\n"
	.string "tower a little further out.\p"
	.string "If you asked me, I wouldn't climb it.\n"
	.string "It's too scary to get up that high.\p"
	.string "Life at sea level in Pacifidlog,\n"
	.string "that suits me fine.$"

PacifidlogTown_Text_TownSign:
	.string "PACIFIDLOG TOWN\p"
	.string "“Where the morning sun smiles upon\n"
	.string "the waters.”$"

