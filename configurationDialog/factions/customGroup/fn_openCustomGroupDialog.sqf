#include "..\..\elementIds.hpp"

waitUntil {!isNull findDisplay CUSTOM_GROUP_IDD};

if ((uiNamespace getVariable ["Rimsiakas_customGroupEditingMode", false])) then {
    private _selectedPoolGroups = (([] call Rimsiakas_fnc_getSelectedSpawnerAndPool get "pool") get "data") get "groups";

    private _groupUnitsList = displayCtrl CUSTOM_GROUP_GROUPUNITSLIST_IDC;
    private _factionConfigDialog = findDisplay FACTIONS_CONFIG_IDD;
    private _poolGroupsList = _factionConfigDialog displayCtrl FACTIONS_CONFIG_SPAWNERPOOLGROUPS_IDC;
    private _selectedGroupIndex = lbCurSel _poolGroupsList;

    {
        private _vehicleName = getText (configFile >> "cfgVehicles" >> _x >> "displayName");
        private _addedIndex = _groupUnitsList lbAdd (_vehicleName);
        _groupUnitsList lbSetData [_addedIndex, _x];
        _groupUnitsList lbSetTooltip [_addedIndex, _x];
    } forEach (_selectedPoolGroups select _selectedGroupIndex);
};

[] call Rimsiakas_fnc_populateVehiclesConfigTree;