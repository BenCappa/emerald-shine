RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Oriana::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_OrianaIntro, RustboroCity_Gym_Text_OrianaDefeat, RustboroCity_Gym_EventScript_OrianaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_OrianaRematch
	goto_if_unset FLAG_RECEIVED_TM_FALSE_SWIPE, RustboroCity_Gym_EventScript_GiveFalseSwipe
	msgbox RustboroCity_Gym_Text_OrianaPostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_OrianaDefeated::
	message RustboroCity_Gym_Text_ReceivedBalanceBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_BalanceBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveFalseSwipe
	end

RustboroCity_Gym_EventScript_GiveFalseSwipe::
	giveitem ITEM_TM_FALSE_SWIPE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_FALSE_SWIPE
	msgbox RustboroCity_Gym_Text_ExplainFalseSwipe, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_OrianaRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_OrianaPreRematch, RustboroCity_Gym_Text_OrianaRematchDefeat, RustboroCity_Gym_Text_OrianaRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_OrianaPostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterOriana::
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Yo, how's it going?\p"
	.string "Listen, my friend!\n"
	.string "Would you like to become the Champion?\p"
	.string "I'm no Trainer, not me, but I can\n"
	.string "sure give you winning advice.\p"
	.string "That's settled, then! We'll aim for the\n"
	.string "Pokémon Championship together!\p"
	.string "It's your job as a Trainer to collect\n"
	.string "Gym Badges, am I right?\p"
	.string "But Gym Leaders aren't pushovers!\p"
	.string "And that's where I come in!\n"
	.string "I'm here to provide expert advice!\p"
	.string "Oriana, the Gym Leader, uses both\n"
	.string "Normal and Fairy-type Pokémon.\p"
	.string "But that's not all!\n"
	.string "Everyone in here uses Baby Pokémon!\p"
	.string "Don't judge a book by its cover here!\n"
	.string "A lot of newcomers fail to take these\l"
	.string "teams seriously and walk away losers.\p"
	.string "Come see me afterwards, if you manage\n"
	.string "to defeat the Gym Leader.\p"
	.string "Well, go for it!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Whoa! What a breathtaking victory!\n"
	.string "My cheering must've worked!\p"
	.string "Great!\n"
	.string "Check your Trainer Card.\p"
	.string "The Balance Badge you got should be\n"
	.string "properly recorded on it.\p"
	.string "In other words…\p"
	.string "You've climbed the first step on\n"
	.string "the stairs to the Championship!\p"
	.string "That's got to feel awesome!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Don't take us Gym Trainers lightly!\n"
	.string "I'll show you why we're better!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "You were too good for me…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Baby Pokémon are full of untapped\n"
	.string "potential!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "If you can't beat me, you won't stand\n"
	.string "a chance against Oriana!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wow! You've got some potential!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "Oriana is stronger than me by\n"
	.string "several times.\p"
	.string "You'd better be on your guard!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "We might be new to our adventure,\n"
	.string "but so what?\p"
	.string "My Baby Pokémon need room to\n"
	.string "rampage!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Oh, man oh man!\n"
	.string "Our challenger is one feisty customer!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "I have to hand it to our Leader.\p"
	.string "It took smarts and sense for her to\n"
	.string "make a Gym out of Baby Pokémon.$"

RustboroCity_Gym_Text_OrianaIntro:
	.string "Oreo: Hey Ash-Ash! Welcome to my Gym!\p"
	.string "Were you surprised to hear that I was\n"
	.string "already a Gym Leader?\p"
	.string "You see, I joined the Trainer School and\n"
	.string "became their top student right away."
	.string "I mean, the city was practically\n"
	.string "begging me to take over the gym."
	.string "Wanna see why?$"

RustboroCity_Gym_Text_OrianaDefeat:
	.string "Oreo: Urgh…\n"
	.string "I can't believe I lost…\p"
	.string "Ah, whatever.\n"
	.string "I'm not gonna lose so easily next time!\p"
	.string "The Pokémon League's rules state\n"
	.string "that Trainers are to be given this\l"
	.string "if they defeat a Gym Leader.\p"
	.string "Please accept the official Pokémon\n"
	.string "League Balance Badge.$"

RustboroCity_Gym_Text_ReceivedBalanceBadge:
	.string "{PLAYER} received the Balance Badge\n"
	.string "from Oriana.$"

RustboroCity_Gym_Text_BalanceBadgeInfoTakeThis:
	.string "Oreo: I'm sure you've noticed by now\n"
	.string "that your Pokémon can't level up\l"
	.string "naturally past a certain level.\p"
	.string "This is called the Level Cap, and the\n"
	.string "Balance Badge raises it to Level 19!\p"
	.string "It also raises your Pokémon's Attack\n"
	.string "and enable them to use the HM move Cut\l"
	.string "outside of battle.\p"
	.string "Please take this with you, too.$"

RustboroCity_Gym_Text_ExplainFalseSwipe:
	.string "Oreo: That Technical Machine, TM01,\n"
	.string "contains False Swipe.\p"
	.string "You use a TM to instantly teach a move\n"
	.string "to a Pokémon, in this case: False Swipe.\p"
	.string "It'll only ever bring a Pokémon down to\n"
	.string "1 HP no matter how much damage it does.\p"
	.string "That makes it super useful for\n"
	.string "capturing wild Pokémon!\p"
	.string "And don't worry about wasting it,\n"
	.string "a TM can be used over and over again!$"

RustboroCity_Gym_Text_OrianaPostBattle:
	.string "Since you are so strong, you should\n"
	.string "challenge the other Gym Leaders.\p"
	.string "Mom knows who you're facing next.\n"
	.string "Go talk to her if you need advice.$"

RustboroCity_Gym_Text_GymStatue:
	.string "RUSTBORO CITY POKéMON GYM$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "RUSTBORO CITY POKéMON GYM\p"
	.string "ORIANA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_OrianaPreRematch:
	.string "Oreo: I'm so glad to see you again.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become. Let's battle!$"

RustboroCity_Gym_Text_OrianaRematchDefeat:
	.string "Grr…\n"
	.string "I can't believe I lost again…$"

RustboroCity_Gym_Text_OrianaPostRematch:
	.string "Oreo: I still have much to learn\n"
	.string "when it comes to battling Pokémon.\p"
	.string "That awareness makes me love battling\n"
	.string "all that much more!$"

RustboroCity_Gym_Text_OrianaRematchNeedTwoMons:
	.string "Oreo: I'm so glad to see you again.\n"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become…\p"
	.string "Oh, no…\n"
	.string "You only have one Pokémon with you?\p"
	.string "You're gonna need at least one more\n"
	.string "Pokémon for this battle.$"
