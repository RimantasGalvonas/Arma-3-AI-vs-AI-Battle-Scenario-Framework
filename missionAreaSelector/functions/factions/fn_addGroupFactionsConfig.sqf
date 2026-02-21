private _control = displayCtrl 404004;

private _selectionPaths = tvSelection _control;

private _pool = ([] call Rimsiakas_fnc_getSelectedSpawnerAndPoolFactionsConfig) get "pool";
private _selectedPoolData = _pool get "data";
private _groups = _selectedPoolData get "groups";

{
    private _selectionPath = _x;

    if (count _selectionPath != 4) then {
        continue;
    };

    private _groupConfigPath = _control tvData _selectionPath;

    _groupConfigPath = fromJSON _groupConfigPath;
    _groupConfigPath set [0, configFile];
    private _config = _groupConfigPath call BIS_fnc_getCfg;

    _groups append [_config];
} foreach _selectionPaths;

[_selectedPoolData] call Rimsiakas_fnc_populatePoolGroupsFactionsConfig;