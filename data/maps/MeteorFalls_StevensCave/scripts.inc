MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "Steven: Oh, wow, {PLAYER}{KUN}.\n"
	.string "I'm amazed you knew where to find me.\p"
	.string "I assume you've realized by now that\n"
	.string "I am the Hoenn region's true Champion.\p"
	.string "And now you want that title…\p"
	.string "We battled alongside each other at\n"
	.string "the Sootopolis Space Center.\p"
	.string "You should have a rough estimate\n"
	.string "of what I am capable of.\p"
	.string "Fine then, {PLAYER}{KUN}…\n"
	.string "If what you're approaching me with now\n"
	.string "is a serious challenge…\l"
	.string "… … … … … …\p"
	.string "Expect the worst.$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "You…\n"
	.string "I had no idea you'd become so strong…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "Steven: Come to think of it, ever since\n"
	.string "our paths first crossed in Granite\l"
	.string "Cave in Dewford, I had this feeling.\p"
	.string "I thought that you would eventually\n"
	.string "become the Champion.\p"
	.string "You make your family proud.\p"
	.string "And where will you go from here?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, even I couldn't tell you that.$"

