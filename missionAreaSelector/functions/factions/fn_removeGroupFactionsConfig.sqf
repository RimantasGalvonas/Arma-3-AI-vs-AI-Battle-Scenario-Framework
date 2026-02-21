private _control = displayCtrl 403005;
private _selectedIndex = lbSelection _control;
private _pool = ([] call Rimsiakas_fnc_getSelectedSpawnerAndPoolFactionsConfig) get "pool";
private _selectedPoolData = _pool get "data";
private _groups = _selectedPoolData get "groups";

_groups deleteAt _selectedIndex;

[_selectedPoolData] call Rimsiakas_fnc_populatePoolGroupsFactionsConfig;