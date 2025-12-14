AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Ships of this sort are rare, so I'm\n"
	.string "taking a look around.\p"
	.string "However, it seems my presence bothers\n"
	.string "the others for some reason…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Why are there so many people here?\n"
	.string "I thought I'd finally be alone!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "I just want to be left alone…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "The man next door…\p"
	.string "He says he's just sightseeing,\n"
	.string "but I know he's following me.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "You're such a tough Trainer!\n"
	.string "Let me register you for my safety!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Please have a battle with me so that\n"
	.string "old man will stop harassing me!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Are we good? Is he gone?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Nothing has happened yet but I know\n"
	.string "what's going on in that old man's head!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Waaah!\n"
	.string "I've been found! …Huh?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Oh, you're not the creepy guy.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "I know all about “Stranger Danger” so\n"
	.string "that old creep better not mess with me!$"

