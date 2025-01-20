LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ROOM_SERVICE, LilycoveCity_CoveLilyMotel_2F_EventScript_FeelSoEntitled
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImOnMyBreak, MSGBOX_DEFAULT
	giveitem ITEM_ROOM_SERVICE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_ROOM_SERVICE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FeelSoEntitled::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_FeelSoEntitled
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "I'm the GAME DESIGNER.\p"
	.string "Oh, is that right?\n"
	.string "You're working on a POKéDEX?\p"
	.string "It's tough trying to complete it,\n"
	.string "but don't give up.\p"
	.string "If you do complete it, please come\n"
	.string "show me.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Wow! That's awesome!\n"
	.string "Yep, it's totally awesome!\p"
	.string "This POKéDEX is completely filled!\n"
	.string "You really must love POKéMON!\p"
	.string "I'm so impressed!\p"
	.string "Let me give you something in\n"
	.string "recognition of your feat!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Me? You're talking to me?\n"
	.string "I'm the PROGRAMMER.\p"
	.string "I wonder what the SLOTS are\n"
	.string "like here.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "I'm the GRAPHIC ARTIST! Aren't the\n"
	.string "POKéMON of HOENN interesting?$"

LilycoveCity_CoveLilyMotel_2F_Text_ImOnMyBreak:
	.string "What? Can't you see I'm on my break?\p"
	.string "Are you waiting on your Room Service\n"
	.string "or something?\p"
	.string "Here, just take it!$"

LilycoveCity_CoveLilyMotel_2F_Text_FeelSoEntitled:
	.string "Why do people these days feel so\n"
	.string "entitled to the services they pay for?$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "The sea breeze tickles my heart.\n"
	.string "It feels wonderful here!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "You never know when and where\n"
	.string "people will challenge you.\p"
	.string "That's why I never leave home without\n"
	.string "my GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Huh?!\n"
	.string "Oh, sorry, sorry! I was snoozing!\p"
	.string "I came to check out this POKéMON\n"
	.string "CONTEST thing.\p"
	.string "I have to admit, it does look quite\n"
	.string "entertaining, but…\p"
	.string "Consider me a purist--I prefer\n"
	.string "battles and tough TRAINERS.\p"
	.string "But that's just me.\p"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
	.string "like the GYMS, CONTESTS, BATTLE TENT,\l"
	.string "the whole works!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT: I think it does take strategy\n"
	.string "to win a CONTEST.\p"
	.string "Devising CONTEST strategies is one way\n"
	.string "of becoming a better TRAINER, I'd say.$"

