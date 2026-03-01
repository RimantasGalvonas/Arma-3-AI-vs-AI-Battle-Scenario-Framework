#include "..\..\elementIds.hpp"

waitUntil {!isNull findDisplay CUSTOM_GROUP_FORM_IDD};

if (!(uiNamespace getVariable ["Rimsiakas_customGroupEditingMode", false])) exitWith {
    (displayCtrl CUSTOM_GROUP_FORM_EDITINSTRUCTION_IDC) ctrlShow false;
};

(displayCtrl CUSTOM_GROUP_FORM_ADDINSTRUCTION_IDC) ctrlShow false;

private _selectedPoolData = ([] call Rimsiakas_fnc_getSelectedSpawnerAndPool get "pool") get "data";

private _factionConfigDialog = findDisplay FACTIONS_CONFIG_IDD;
private _poolGroupsList = _factionConfigDialog displayCtrl FACTIONS_CONFIG_SPAWNERPOOLGROUPS_IDC;
private _selectedGroupIndex = lbCurSel _poolGroupsList;

private _inputField = displayCtrl CUSTOM_GROUP_FORM_INPUT_IDC;
_inputField ctrlSetText toJSON ((_selectedPoolData get "groups") select _selectedGroupIndex);