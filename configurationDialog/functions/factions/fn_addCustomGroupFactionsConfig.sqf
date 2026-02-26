#include "..\..\elementIds.hpp"

private _inputField = displayCtrl CUSTOM_GROUP_FORM_INPUT_IDC;

private _inputGroups = fromJSON (ctrlText _inputField);

if (isNil "_inputGroups") exitWith {
	hint "Invalid JSON";
};

if (count _inputGroups == 0) exitWith {
    closeDialog 2;
};

private _pool = ([] call Rimsiakas_fnc_getSelectedSpawnerAndPoolFactionsConfig) get "pool";
private _selectedPoolData = _pool get "data";
private _groups = _selectedPoolData get "groups";

_groups append (_inputGroups select {typename _x == "ARRAY"});

[_selectedPoolData] call Rimsiakas_fnc_populatePoolGroupsFactionsConfig;

closeDialog 1;