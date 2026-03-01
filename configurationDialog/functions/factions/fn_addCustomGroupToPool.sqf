#include "..\..\elementIds.hpp"

private _inputField = displayCtrl CUSTOM_GROUP_FORM_INPUT_IDC;

private _input = fromJSON (ctrlText _inputField);

if (isNil "_input") exitWith {
	hint "Invalid JSON";
};

private _pool = ([] call Rimsiakas_fnc_getSelectedSpawnerAndPool) get "pool";
private _selectedPoolData = _pool get "data";
private _groups = _selectedPoolData get "groups";

if (!(uiNamespace getVariable ["Rimsiakas_customGroupEditingMode", false])) then {
    _inputGroups = _input select {typename _x == "ARRAY"};

    if (count _inputGroups == 0) then {
        _inputGroups = [_input];
    };

    _groups append _inputGroups;
} else {
    private _factionConfigDialog = findDisplay FACTIONS_CONFIG_IDD;
    private _poolGroupsList = _factionConfigDialog displayCtrl FACTIONS_CONFIG_SPAWNERPOOLGROUPS_IDC;
    private _selectedGroupIndex = lbCurSel _poolGroupsList;

    _groups set [_selectedGroupIndex, _input];
};

[_selectedPoolData] call Rimsiakas_fnc_populatePoolGroupsList;

closeDialog 1;