#include "..\elementIds.hpp"

private _presetListControl = displayCtrl CONFIGURATION_PRESETS_PRESETLIST_IDC;

private _presetName = _presetListControl lbText (lbCurSel _presetListControl);

private _savedPresets = missionProfileNamespace getVariable ["Rimsiakas_configurationPresets", createHashMap];

private _savedPresetData = _savedPresets get _presetName;

if (isNil {_savedPresetData}) exitWith {
    hint "Failed to load the preset.";
};

Rimsiakas_workingFactionsData = +(_savedPresetData get "factionsData");
[Rimsiakas_workingFactionsData] call Rimsiakas_fnc_confirmFactionsConfig;


[_savedPresetData] spawn {
    params ["_savedPresetData"];

    waitUntil {isNull findDisplay CONFIGURATION_PRESETS_IDD}; // Need to wait until closed, otherwise the mission area field may not be updated on dedicated server

    [_savedPresetData] remoteExecCall ["Rimsiakas_fnc_loadConfigurationPresetOnServer", 2];
};

