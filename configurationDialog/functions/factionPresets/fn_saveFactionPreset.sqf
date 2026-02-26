#include "..\..\elementIds.hpp"

private _presetListControl = displayCtrl FACTION_PRESETS_PRESETLIST_IDC;
private _presetNameControl = displayCtrl FACTION_PRESETS_PRESETNAME_IDC;

private _selectedPresetName = _presetListControl lbText (lbCurSel _presetListControl);
private _enteredPresetName = ctrlText _presetNameControl;

private _savedPresets = missionProfileNamespace getVariable ["Rimsiakas_factionPresets", createHashMap];
private _savedPresetData = _savedPresets getOrDefault [_selectedPresetName, createHashMap];
private _highestOrderKey = ([keys _savedPresets, [_savedPresets], {(_input0 get _x) get "order"}, "DESCEND"] call BIS_fnc_sortBy) select 0;

if (_savedPresetData getOrDefault ["readonly", false]) exitWith {
    hint "Can't overwrite this preset";
};

if (_selectedPresetName != _enteredPresetName && {!isNil {_savedPresets get _enteredPresetName}}) exitWith {
    hint "Preset with this name already exists";
};

private _order = _savedPresetData getOrDefault ["order", ((_savedPresets get _highestOrderKey) get "order") + 10];

if (!isNil {_savedPresetData get "preset"} && {!(["Are you sure?", "Overwrite " + _selectedPresetName, true, true] call BIS_fnc_guiMessage)}) exitWith {};

_savedPresetData set ["order", _order];
_savedPresetData set ["preset", +Rimsiakas_workingSpawnersData];
_savedPresetData set ["readonly", false];


_savedPresets deleteAt _selectedPresetName;
_savedPresets set [_enteredPresetName, _savedPresetData];
missionProfileNamespace setVariable ["Rimsiakas_factionPresets", _savedPresets];
saveMissionProfileNamespace;

[] call Rimsiakas_fnc_openFactionPresets;