#include "..\..\elementIds.hpp"

private _groupUnitsList = displayCtrl CUSTOM_GROUP_GROUPUNITSLIST_IDC;

private _vehicleClasses = [];

for "_i" from 0 to (lbSize _groupUnitsList - 1) do {
    _vehicleClasses append [(_groupUnitsList lbData _i)];
};

if (count _vehicleClasses == 0) exitWith {
    hint "No vehicles added";
    closeDialog 2;
};

private _pool = ([] call Rimsiakas_fnc_getSelectedSpawnerAndPool) get "pool";
private _selectedPoolData = _pool get "data";
private _groups = _selectedPoolData get "groups";

if (!(uiNamespace getVariable ["Rimsiakas_customGroupEditingMode", false])) then {
    _groups append [_vehicleClasses];
} else {
    private _factionConfigDialog = findDisplay FACTIONS_CONFIG_IDD;
    private _poolGroupsList = _factionConfigDialog displayCtrl FACTIONS_CONFIG_SPAWNERPOOLGROUPS_IDC;
    private _selectedGroupIndex = lbCurSel _poolGroupsList;

    _groups set [_selectedGroupIndex, _vehicleClasses];
};

[_selectedPoolData] call Rimsiakas_fnc_populatePoolGroupsList;

closeDialog 1;