.set LOCALID_SHAYMIN, 5

Route130_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route130_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route130_MirageIsland_OnResume
	.byte 0

Route130_OnTransition:
	call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, Route130_EventScript_CheckSetAbnormalWeather
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, Route130_EventScript_SetMirageIslandLayout
@ Mirage Island isn't currently visible, hide any objects on the island. Only the first flag is actually associated with anything.
	call Route130_MirageIsland_EventScript_HideShaymin
	setflag FLAG_TEMP_HIDE_MIRAGE_ISLAND_BERRY_TREE
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_18
	setflag FLAG_TEMP_19
	setflag FLAG_TEMP_1A
	setflag FLAG_TEMP_1B
	setflag FLAG_TEMP_1C
	setflag FLAG_TEMP_1D
	setflag FLAG_TEMP_1E
	setflag FLAG_TEMP_1F
	setmaplayoutindex LAYOUT_ROUTE130
	end

Route130_EventScript_SetMirageIslandLayout::
	call_if_set FLAG_CAUGHT_SHAYMIN, Route130_MirageIsland_EventScript_HideShaymin
	call_if_set FLAG_DAILY_BATTLED_SHAYMIN, Route130_MirageIsland_EventScript_HideShaymin
	setmaplayoutindex LAYOUT_ROUTE130_MIRAGE_ISLAND
	end

Route130_EventScript_CheckSetAbnormalWeather::
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	return

Route130_EventScript_Rodney::
	trainerbattle_single TRAINER_RODNEY, Route130_Text_RodneyIntro, Route130_Text_RodneyDefeat
	msgbox Route130_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Katie::
	trainerbattle_single TRAINER_KATIE, Route130_Text_KatieIntro, Route130_Text_KatieDefeat
	msgbox Route130_Text_KatiePostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Santiago::
	trainerbattle_single TRAINER_SANTIAGO, Route130_Text_SantiagoIntro, Route130_Text_SantiagoDefeat
	msgbox Route130_Text_SantiagoPostBattle, MSGBOX_AUTOCLOSE
	end

Route130_MirageIsland_EventScript_HideShaymin::
	setflag FLAG_TEMP_HIDE_MIRAGE_ISLAND_SHAYMIN
	return

Route130_MirageIsland_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route130_MirageIsland_TryRemoveShaymin
	end

Route130_MirageIsland_TryRemoveShaymin::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_SHAYMIN
	return

Route130_MirageIsland_EventScript_Shaymin::
	lock
	faceplayer
	playmoncry SPECIES_SHAYMIN, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_SHAYMIN, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route130_MirageIsland_EventScript_DefeatedShaymin
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Route130_MirageIsland_EventScript_CaughtShaymin
	release
	end

Route130_MirageIsland_EventScript_DefeatedShaymin::
	setflag FLAG_DAILY_BATTLED_SHAYMIN
	setvar VAR_0x8004, SPECIES_SHAYMIN
	goto Common_EventScript_LegendaryFlewAway
	end

Route130_MirageIsland_EventScript_CaughtShaymin::
	setflag FLAG_CAUGHT_SHAYMIN
	release
	end
