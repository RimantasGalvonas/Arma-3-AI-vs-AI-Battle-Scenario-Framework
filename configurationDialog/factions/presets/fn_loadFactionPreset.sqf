#include "..\..\elementIds.hpp"

private _presetListControl = displayCtrl FACTION_PRESETS_PRESETLIST_IDC;

private _presetName = _presetListControl lbText (lbCurSel _presetListControl);

private _savedPresets = missionProfileNamespace getVariable ["Rimsiakas_factionPresets", createHashMap];

private _savedPresetData = _savedPresets get _presetName;

if (isNil {_savedPresetData}) exitWith {
    hint "Failed to load the preset.";
};

Rimsiakas_workingSpawnersData = +(_savedPresetData get "preset");

[] call Rimsiakas_fnc_confirmFactionsConfig;

[] spawn {
    waitUntil {isNull findDisplay FACTION_PRESETS_IDD}; // Need to wait until closed, couldn't find any other way to get the faction config dialog to update
    [] call Rimsiakas_fnc_openFactionsConfig;
};

