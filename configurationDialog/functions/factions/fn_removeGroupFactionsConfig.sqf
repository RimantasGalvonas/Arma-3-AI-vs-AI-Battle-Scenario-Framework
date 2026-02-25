#include "..\..\elementIds.hpp"

private _control = displayCtrl FACTIONS_CONFIG_DIALOG_SPAWNERPOOLGROUPS_IDC;
private _selectedIndex = lbSelection _control;
private _pool = ([] call Rimsiakas_fnc_getSelectedSpawnerAndPoolFactionsConfig) get "pool";
private _selectedPoolData = _pool get "data";
private _groups = _selectedPoolData get "groups";

_groups deleteAt _selectedIndex;

[_selectedPoolData] call Rimsiakas_fnc_populatePoolGroupsFactionsConfig;