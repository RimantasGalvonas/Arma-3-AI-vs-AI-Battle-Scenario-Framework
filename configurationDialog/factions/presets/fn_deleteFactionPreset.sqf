#include "..\..\elementIds.hpp"

private _presetListControl = displayCtrl FACTION_PRESETS_PRESETLIST_IDC;
private _presetNameControl = displayCtrl FACTION_PRESETS_PRESETNAME_IDC;

private _presetName = _presetListControl lbText (lbCurSel _presetListControl);

if (!(["Are you sure?", "Delete " + _presetName, true, true] call BIS_fnc_guiMessage)) exitWith {};

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

_presetNameControl ctrlSetText "";

[] call Rimsiakas_fnc_openFactionPresets;