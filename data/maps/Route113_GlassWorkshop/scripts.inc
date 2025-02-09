Route113_GlassWorkshop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route113_GlassWorkshop_OnTransition
	.byte 0

	.set ABILITY_CAPSULE_PRICE,	200
	.set FLAME_ORB_PRICE,		350
	.set TOXIC_ORB_PRICE,		350
	.set LIFE_ORB_PRICE,		500
	.set ABILITY_PATCH_PRICE,	750
	.set PRETTY_CHAIR_PRICE,	1000
	.set PRETTY_DESK_PRICE,		2000
	.set LOWEST_ASH_PRICE,		ABILITY_CAPSULE_PRICE

Route113_GlassWorkshop_OnTransition:
	setflag FLAG_LANDMARK_GLASS_WORKSHOP
	call_if_eq VAR_GLASS_WORKSHOP_STATE, 1, Route113_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack
	end

Route113_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack::
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	return

Route113_GlassWorkshop_EventScript_GlassWorker::
	lock
	faceplayer
	goto_if_ge VAR_GLASS_WORKSHOP_STATE, 10, Route113_GlassWorkshop_EventScript_GiveItemAfterNoRoom
	goto_if_eq VAR_GLASS_WORKSHOP_STATE, 2, Route113_GlassWorkshop_EventScript_CheckCollectedAsh
	goto_if_eq VAR_GLASS_WORKSHOP_STATE, 1, Route113_GlassWorkshop_EventScript_ExplainSootSack
	msgbox Route113_GlassWorkshop_Text_GoCollectAshWithThis, MSGBOX_DEFAULT
	giveitem ITEM_SOOT_SACK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_GLASS_WORKSHOP_STATE, 1
	msgbox Route113_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_ExplainSootSack::
	msgbox Route113_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_CheckCollectedAsh::
	checkitem ITEM_SOOT_SACK
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_SootSackNotInBag
	msgbox Route113_GlassWorkshop_Text_LetsSeeCollectedAshes, MSGBOX_DEFAULT
	goto_if_lt VAR_ASH_GATHER_COUNT, LOWEST_ASH_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAsh
	message Route113_GlassWorkshop_Text_WhichGlassItemWoudYouLike
	waitmessage
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
	end

Route113_GlassWorkshop_EventScript_SootSackNotInBag::
	msgbox Route113_GlassWorkshop_Text_HaventGotYourSootSack, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_ChooseGlassItem::
	setvar VAR_0x8009, 0
	setvar VAR_0x8004, SCROLL_MULTI_GLASS_WORKSHOP_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, Route113_GlassWorkshop_EventScript_AbilityCapsule
	case 1, Route113_GlassWorkshop_EventScript_FlameOrb
	case 2, Route113_GlassWorkshop_EventScript_ToxicOrb
	case 3, Route113_GlassWorkshop_EventScript_LifeOrb
	case 4, Route113_GlassWorkshop_EventScript_AbilityPatch
	case 5, Route113_GlassWorkshop_EventScript_PrettyChair
	case 6, Route113_GlassWorkshop_EventScript_PrettyDesk
	case 7, Route113_GlassWorkshop_EventScript_CancelGlassItemSelect
	case MULTI_B_PRESSED, Route113_GlassWorkshop_EventScript_CancelGlassItemSelect
	end

Route113_GlassWorkshop_EventScript_AbilityCapsule::
	setvar VAR_0x8008, ITEM_ABILITY_CAPSULE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, ABILITY_CAPSULE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, ABILITY_CAPSULE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 10
	subvar VAR_ASH_GATHER_COUNT, ABILITY_CAPSULE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_FlameOrb::
	setvar VAR_0x8008, ITEM_FLAME_ORB
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, FLAME_ORB_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, FLAME_ORB_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 11
	subvar VAR_ASH_GATHER_COUNT, FLAME_ORB_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_ToxicOrb::
	setvar VAR_0x8008, ITEM_TOXIC_ORB
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, TOXIC_ORB_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, TOXIC_ORB_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 12
	subvar VAR_ASH_GATHER_COUNT, TOXIC_ORB_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_LifeOrb::
	setvar VAR_0x8008, ITEM_LIFE_ORB
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, LIFE_ORB_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, LIFE_ORB_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 13
	subvar VAR_ASH_GATHER_COUNT, LIFE_ORB_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_AbilityPatch::
	setvar VAR_0x8008, ITEM_ABILITY_PATCH
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, ABILITY_PATCH_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, ABILITY_PATCH_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 14
	subvar VAR_ASH_GATHER_COUNT, ABILITY_PATCH_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_PrettyChair::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
	bufferdecorationname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, PRETTY_CHAIR_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 15
	subvar VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_PrettyDesk::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_DESK
	bufferdecorationname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, PRETTY_DESK_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 16
	subvar VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_CancelGlassItemSelect::
	msgbox Route113_GlassWorkshop_Text_AllThatAshButDontWantAnything, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_NotEnoughAsh::
	setvar VAR_0x800A, LOWEST_ASH_PRICE
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
	buffernumberstring STR_VAR_1, VAR_0x800A
	msgbox Route113_GlassWorkshop_Text_NotEnoughAshNeedX, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_NotEnoughAshForItem::
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
	buffernumberstring STR_VAR_2, VAR_0x800A
	message Route113_GlassWorkshop_Text_NotEnoughAshToMakeItem
	waitmessage
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
	end

Route113_GlassWorkshop_EventScript_ChooseDifferentItem::
	message Route113_GlassWorkshop_Text_WhichWouldYouLike
	waitmessage
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
	end

Route113_GlassWorkshop_EventScript_MakeGlassItem::
	msgbox Route113_GlassWorkshop_Text_IllMakeItemForYou, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_SELECT
	delay 30
	fadescreen FADE_FROM_BLACK
	msgbox Route113_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
	call_if_eq VAR_0x8009, 0, Route113_GlassWorkshop_EventScript_GiveGlassFlute
	call_if_eq VAR_0x8009, 1, Route113_GlassWorkshop_EventScript_GiveGlassDecor
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	release
	end

Route113_GlassWorkshop_EventScript_GiveGlassFlute::
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_NoRoomForFlute
	return

Route113_GlassWorkshop_EventScript_GiveGlassDecor::
	givedecoration VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_NoRoomForDecor
	return

Route113_GlassWorkshop_EventScript_NoRoomForFlute::
	call Common_EventScript_BagIsFull
	msgbox Route113_GlassWorkshop_Text_NoRoomInBag, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_NoRoomForDecor::
	call Common_EventScript_NoRoomForDecor
	msgbox Route113_GlassWorkshop_Text_NoRoomInPC, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_GiveItemAfterNoRoom::
	switch VAR_GLASS_WORKSHOP_STATE
	case 10, Route113_GlassWorkshop_EventScript_GiveAbilityCapsule
	case 11, Route113_GlassWorkshop_EventScript_GiveFlameOrb
	case 12, Route113_GlassWorkshop_EventScript_GiveToxicOrb
	case 13, Route113_GlassWorkshop_EventScript_GiveLifeOrb
	case 14, Route113_GlassWorkshop_EventScript_GiveAbilityPatch
	case 15, Route113_GlassWorkshop_EventScript_GivePrettyChair
	case 16, Route113_GlassWorkshop_EventScript_GivePrettyDesk
	end

Route113_GlassWorkshop_EventScript_GiveAbilityCapsule::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_ABILITY_CAPSULE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveFlameOrb::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_FLAME_ORB
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveToxicOrb::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_TOXIC_ORB
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveLifeOrb::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_LIFE_ORB
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveAbilityPatch::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_ABILITY_PATCH
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GivePrettyChair::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
	bufferdecorationname STR_VAR_1, DECOR_PRETTY_CHAIR
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GivePrettyDesk::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_DESK
	bufferdecorationname STR_VAR_1, DECOR_PRETTY_DESK
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_TryGiveItemAgain::
	msgbox Route113_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
	call_if_eq VAR_0x8009, 0, Route113_GlassWorkshop_EventScript_GiveGlassFlute
	call_if_eq VAR_0x8009, 1, Route113_GlassWorkshop_EventScript_GiveGlassDecor
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	release
	end

Route113_GlassWorkshop_EventScript_NinjaBoy::
	msgbox Route113_GlassWorkshop_Text_FunToBlowGlassFlute, MSGBOX_NPC
	end

Route113_GlassWorkshop_Text_GoCollectAshWithThis:
	.string "This area is covered in volcanic ash,\n"
	.string "huff-puff!\p"
	.string "I'm specially gifted, huff-puff.\p"
	.string "I make glass out of volcanic ash\n"
	.string "and make items, huff-puff.\p"
	.string "Go collect ashes with this, huff-puff.$"

Route113_GlassWorkshop_Text_ExplainSootSack:
	.string "Just take that Soot Sack and walk\n"
	.string "through piles of ash, huff-puff.\p"
	.string "And it will fill up with the volcanic ash,\n"
	.string "huff-puff.\p"
	.string "Once you think you've collected a good\n"
	.string "amount, come see me, huff-puff.$"

Route113_GlassWorkshop_Text_LetsSeeCollectedAshes:
	.string "Have you collected ashes, huff-puff?\n"
	.string "Let me see, huff-puff.$"

Route113_GlassWorkshop_Text_NotEnoughAshNeedX:
	.string "Hmmm…\n"
	.string "There's not enough ash here, huff-puff.\l"
	.string "I can't make glass with this, huff-puff.\p"
	.string "Let's see… {STR_VAR_1} is the number of steps\n"
	.string "you'll need to walk for me to make you\l"
	.string "a Ability Capsule, huff-puff.$"

Route113_GlassWorkshop_Text_WhichGlassItemWoudYouLike:
	.string "Oh!\n"
	.string "You've got a lot of ashes, huff-puff!\p"
	.string "I'll make you a glass item, huff-puff!\n"
	.string "Which one would you like, huff-puff?$"

Route113_GlassWorkshop_Text_IsThatTheItemForYou:
	.string "A {STR_VAR_1}, huff-puff?\n"
	.string "Is that the one for you, huff-puff?$"

Route113_GlassWorkshop_Text_WhichWouldYouLike:
	.string "Which one would you like, huff-puff?$"

Route113_GlassWorkshop_Text_IllMakeItemForYou:
	.string "A {STR_VAR_1} it is, then, huff-puff!\p"
	.string "Okay! I'll make it for you, huff-puff.\n"
	.string "Just wait a little while, huff-puff.$"

Route113_GlassWorkshop_Text_NotEnoughAshToMakeItem:
	.string "A {STR_VAR_1}, huff-puff?\p"
	.string "There's not enough ash here to make\n"
	.string "that, though, huff-puff.\p"
	.string "Let's see… {STR_VAR_2} is the number of steps\n"
	.string "you'll need to walk through volcanic ash\l"
	.string "for me to make that item, huff-puff.\p"
	.string "Which item would you rather have me\n"
	.string "make instead, huff-puff?$"

Route113_GlassWorkshop_Text_AllThatAshButDontWantAnything:
	.string "You've collected all that ash, but you\n"
	.string "don't want anything, huff-puff?$"

Route113_GlassWorkshop_Text_IveFinishedGlassItem:
	.string "Ah, I've finished your {STR_VAR_1}.\n"
	.string "Take it, huff-puff.$"

Route113_GlassWorkshop_Text_NoRoomInBag:
	.string "Oh?\n"
	.string "You've no room in your Bag, huff-puff.\p"
	.string "I'll hold on to it, so come back later,\n"
	.string "huff-puff.$"

Route113_GlassWorkshop_Text_NoRoomInPC:
	.string "Oh?\n"
	.string "You've no room in your PC, huff-puff?\p"
	.string "I'll hold on to it, so come back later,\n"
	.string "huff-puff.$"

Route113_GlassWorkshop_Text_HaventGotYourSootSack:
	.string "Hah? You haven't got your Soot Sack\n"
	.string "with you, huff-puff.\p"
	.string "You have to keep it with you to collect\n"
	.string "volcanic ash, huff-puff.$"

Route113_GlassWorkshop_Text_FunToBlowGlassFlute:
	.string "It's fun to make TikToks of my boss\n"
	.string "at work.\p"
	.string "Huff-huff! Puff-puff!$"

