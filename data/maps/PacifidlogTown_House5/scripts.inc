PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_GracideaNotInBloom, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_GracideaInBloom, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnGracidea, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_GracideaNotInBloom:
	.string "Why don't my Gracidea flowers bloom?$"

PacifidlogTown_House5_Text_GracideaInBloom:
	.string "Ah, beautiful.\n"
	.string "My Gracidea flowers are in bloom!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnGracidea:
	.string "Mirage Island…\p"
	.string "There are rumors of an island appearing\n"
	.string "on Route 130 to certain Trainers who\l"
	.string "carry a Gracidea flower in bloom.p"
	.string "I think it's just a fun folktale used to\n"
	.string "sell flowers.\p"
	.string "Such a place couldn't exist… right?$"

