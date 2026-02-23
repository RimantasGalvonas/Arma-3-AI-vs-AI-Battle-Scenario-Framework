private _presetListControl = displayCtrl 500002;

private _presetName = _presetListControl lbText (lbCurSel _presetListControl);

private _savedPresets = missionProfileNamespace getVariable ["Rimsiakas_factionPresets", createHashMap];

private _savedPresetData = _savedPresets get _presetName;

if (isNil {_savedPresetData}) exitWith {
    hint "Failed to load the preset.";
};

Rimsiakas_workingSpawnersData = +(_savedPresetData get "preset");

[] call Rimsiakas_fnc_confirmFactionsConfig;

[] spawn {
    waitUntil {isNull findDisplay 46426}; // Need to wait until closed, couldn't find any other way to get the faction config dialog to update
    [] call Rimsiakas_fnc_openFactionsConfig;
};

