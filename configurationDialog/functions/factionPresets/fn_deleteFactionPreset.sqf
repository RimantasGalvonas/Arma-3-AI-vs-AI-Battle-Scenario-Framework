private _presetListControl = displayCtrl 500002;

private _presetName = _presetListControl lbText (lbCurSel _presetListControl);

private _savedPresets = missionProfileNamespace getVariable ["Rimsiakas_factionPresets", createHashMap];

private _savedPresetData = _savedPresets get _presetName;

if (isNil {_savedPresetData} || {_savedPresetData getOrDefault ["readonly", false]}) exitWith {
    hint "Can't delete this preset";
};

private _order = _savedPresetData getOrDefault ["order", (count _savedPresets) * 10];

_savedPresetData set ["order", _order];
_savedPresetData set ["preset", Rimsiakas_workingSpawnersData];

_savedPresets deleteAt _presetName;
missionProfileNamespace setVariable ["Rimsiakas_factionPresets", _savedPresets];
saveMissionProfileNamespace;

[] call Rimsiakas_fnc_openFactionPresets;