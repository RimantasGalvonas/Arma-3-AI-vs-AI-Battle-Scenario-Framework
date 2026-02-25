#include "..\..\elementIds.hpp"

private _inputField = displayCtrl CUSTOM_GROUP_FORM_INPUT_IDC;

private _group = fromJSON (ctrlText _inputField);

if (isNil "_group") exitWith {
	hint "Invalid JSON";
};

if (count _group == 0) exitWith {};

private _pool = ([] call Rimsiakas_fnc_getSelectedSpawnerAndPoolFactionsConfig) get "pool";
private _selectedPoolData = _pool get "data";
private _groups = _selectedPoolData get "groups";

_groups append [_group];

[_selectedPoolData] call Rimsiakas_fnc_populatePoolGroupsFactionsConfig;

closeDialog 1;