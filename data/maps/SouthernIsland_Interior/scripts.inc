.set LOCALID_STEED, 2

SouthernIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SouthernIsland_Interior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Interior_OnTransition
	.byte 0

SouthernIsland_Interior_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SouthernIsland_Interior_EventScript_TryRemoveSteed
	end

SouthernIsland_Interior_EventScript_TryRemoveSteed::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_STEED
	return

SouthernIsland_Interior_OnTransition:
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpSpectrier
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpGlastrier
	call SouthernIsland_Interior_EventScript_SetUpPlayerGfx
	end

SouthernIsland_Interior_EventScript_SetUpSpectrier::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES(SPECTRIER)
	setvar VAR_TEMP_4, SPECIES_SPECTRIER
	return

SouthernIsland_Interior_EventScript_SetUpGlastrier::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES(GLASTRIER)
	setvar VAR_TEMP_4, SPECIES_GLASTRIER
	return

SouthernIsland_Interior_EventScript_SetUpPlayerGfx::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SouthernIsland_Interior_EventScript_SetBrendanGfx
	goto_if_eq VAR_RESULT, FEMALE, SouthernIsland_Interior_EventScript_SetMayGfx
	end

SouthernIsland_Interior_EventScript_SetBrendanGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

SouthernIsland_Interior_EventScript_SetMayGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

SouthernIsland_Interior_EventScript_TrySteedEncounter::
	lockall
	setvar VAR_0x8008, 12  @ Player's Y coordinate. Not read
	goto SouthernIsland_Interior_EventScript_Steed
	end

SouthernIsland_Interior_EventScript_Steed::
	goto_if_set FLAG_TEMP_2, SouthernIsland_Interior_EventScript_Sign
	goto_if_set FLAG_DAILY_BATTLED_NOBLE_STEED, SouthernIsland_Interior_EventScript_Sign
	goto_if_set FLAG_CAUGHT_NOBLE_STEED, SouthernIsland_Interior_EventScript_Sign
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, SouthernIsland_Interior_EventScript_Sign
	setflag FLAG_ENCOUNTERED_NOBLE_STEED
	setflag FLAG_TEMP_2
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanUp
	waitmovement 0
	delay 50
	waitse
	playmoncry VAR_TEMP_4, CRY_MODE_NORMAL
	delay 30
	waitmoncry
	addobject LOCALID_STEED
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanDown
	applymovement LOCALID_STEED, SouthernIsland_Interior_Movement_SteedApproach
	waitmovement 0
	delay 50
	special RemoveCameraObject
	setvar VAR_LAST_TALKED, LOCALID_STEED
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetSpectrierBattleVars
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetGlastrierBattleVars
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	setflag FLAG_NO_RUNNING
	special BattleSetup_StartLatiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	clearflag FLAG_NO_RUNNING
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SouthernIsland_Interior_EventScript_DefeatedSteed
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SouthernIsland_Interior_EventScript_CaughtSteed
	releaseall
	end

SouthernIsland_Interior_EventScript_DefeatedSteed::
	setflag FLAG_DAILY_BATTLED_NOBLE_STEED
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_EventScript_CaughtSteed::
	setflag FLAG_CAUGHT_NOBLE_STEED
	releaseall
	end

SouthernIsland_Interior_EventScript_Sign::
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_DEFAULT
	releaseall
	end

SouthernIsland_Interior_EventScript_SetSpectrierBattleVars::
	seteventmon SPECIES_SPECTRIER, 50
	return

SouthernIsland_Interior_EventScript_SetGlastrierBattleVars::
	seteventmon SPECIES_GLASTRIER, 50
	return

SouthernIsland_Interior_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

SouthernIsland_Interior_Movement_CameraPanDown:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end

SouthernIsland_Interior_Movement_SteedApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
