MarineCave_End_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MarineCave_End_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MarineCave_End_OnTransition
	.byte 0

MarineCave_End_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MarineCave_End_EventScript_TryRemoveKyogre
	end

MarineCave_End_EventScript_TryRemoveKyogre::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_MARINE_CAVE_KYOGRE
	return

MarineCave_End_OnTransition:
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_CAUGHT_KYOGRE, MarineCave_End_EventScript_HideKyogre
	goto_if_set FLAG_DAILY_BATTLED_KYOGRE, MarineCave_End_EventScript_HideKyogre
	end

MarineCave_End_EventScript_HideKyogre::
	setflag FLAG_HIDE_MARINE_CAVE_KYOGRE
	setvar VAR_TEMP_1, 0
	end

MarineCave_End_EventScript_Kyogre::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_MARINE_CAVE_KYOGRE, MarineCave_End_Movement_KyogreApproach
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_MARINE_CAVE_KYOGRE
	@ setwildbattle SPECIES_KYOGRE, 60, ITEM_BLUE_ORB
	createmon 1, 0, SPECIES_KYOGRE, 60, ITEM_BLUE_ORB, move1=MOVE_BODY_SLAM, move2=MOVE_AQUA_RING, move3=MOVE_SHEER_COLD, move4=MOVE_ORIGIN_PULSE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_NO_RUNNING
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	clearflag FLAG_NO_RUNNING
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MarineCave_End_EventScript_DefeatedKyogre
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MarineCave_End_EventScript_CaughtKyogre
	setvar VAR_0x8004, SPECIES_KYOGRE
	goto Common_EventScript_LegendaryFlewAway
	end

MarineCave_End_EventScript_DefeatedKyogre::
	setflag FLAG_DAILY_BATTLED_KYOGRE
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	setvar VAR_0x8004, SPECIES_KYOGRE
	goto Common_EventScript_LegendaryFlewAway
	end

MarineCave_End_EventScript_CaughtKyogre::
	setflag FLAG_CAUGHT_KYOGRE
	setvar VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	releaseall
	end

MarineCave_End_Movement_KyogreApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

