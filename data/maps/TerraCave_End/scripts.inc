.set LOCALID_GROUDON, 1

TerraCave_End_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TerraCave_End_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TerraCave_End_OnTransition
	.byte 0

TerraCave_End_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TerraCave_End_EventScript_TryRemoveGroudon
	end

TerraCave_End_EventScript_TryRemoveGroudon::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_GROUDON
	return

TerraCave_End_OnTransition:
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_CAUGHT_GROUDON, TerraCave_End_EventScript_HideGroudon
	goto_if_set FLAG_DAILY_BATTLED_GROUDON, TerraCave_End_EventScript_HideGroudon
	end

TerraCave_End_EventScript_HideGroudon::
	setflag FLAG_HIDE_TERRA_CAVE_GROUDON
	setvar VAR_TEMP_1, 0
	end

TerraCave_End_EventScript_Groudon::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_GROUDON, TerraCave_End_Movement_GroudonApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_GROUDON
	@ setwildbattle SPECIES_GROUDON, 60, ITEM_RED_ORB
	createmon 1, 0, SPECIES_GROUDON, 60, ITEM_RED_ORB, move1=MOVE_LAVA_PLUME, move2=MOVE_REST, move3=MOVE_FISSURE, move4=MOVE_PRECIPICE_BLADES
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_NO_RUNNING
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	clearflag FLAG_NO_RUNNING
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TerraCave_End_EventScript_DefeatedGroudon
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TerraCave_End_EventScript_CaughtGroudon
	setvar VAR_0x8004, SPECIES_GROUDON
	goto Common_EventScript_LegendaryFlewAway
	end

TerraCave_End_EventScript_DefeatedGroudon::
	setflag FLAG_DAILY_BATTLED_GROUDON
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setvar VAR_0x8004, SPECIES_GROUDON
	goto Common_EventScript_LegendaryFlewAway
	end

TerraCave_End_EventScript_CaughtGroudon::
	setflag FLAG_CAUGHT_GROUDON
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	releaseall
	end

TerraCave_End_Movement_GroudonApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

