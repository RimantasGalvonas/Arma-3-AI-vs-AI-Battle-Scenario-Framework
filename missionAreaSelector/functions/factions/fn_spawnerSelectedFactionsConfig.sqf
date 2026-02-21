params ["_control", "_path"];

if (count _path == 0) exitWith {};

private _secondColumnFrame = displayCtrl 402000;
private _spawnerPropertiesControlGroup = displayCtrl 402001;
private _poolPropertiesControlGroup = displayCtrl 403001;
private _groupsConfigControlGroup = displayCtrl 404001;

private _selected = [] call Rimsiakas_fnc_getSelectedSpawnerAndPoolFactionsConfig;

if (isNil {_selected get "pool"}) then {
    private _spawnerData = (_selected get "spawner") get "data";
    private _maxUnitsPerGroupField = displayCtrl 402003;
    private _maxUnitsField = displayCtrl 402005;
    private _spawnRateField = displayCtrl 402007;

    private _maxUnitsPerGroup = _spawnerData getOrDefault ["maxUnitsPerGroup", []];
    private _maxUnits = _spawnerData getOrDefault ["maxUnits", []];
    private _spawnRate = _spawnerData getOrDefault ["spawnRate", []];

    _maxUnitsPerGroupField ctrlSetText (str _maxUnitsPerGroup);
    _maxUnitsField ctrlSetText (str _maxUnits);
    _spawnRateField ctrlSetText (str _spawnRate);

    _secondColumnFrame ctrlSetText "Spawner properties";
    _spawnerPropertiesControlGroup ctrlShow true;
    _poolPropertiesControlGroup ctrlShow false;
    _groupsConfigControlGroup ctrlShow false;
} else {
    private _poolWeightField = displayCtrl 403003;

    private _poolData = (_selected get "pool") get "data";

    [_poolData] call Rimsiakas_fnc_populatePoolGroupsFactionsConfig;

    private _weight = _poolData getOrdEfault ["weight", 0];
    _poolWeightField ctrlSetText (str _weight);

    _secondColumnFrame ctrlSetText "Groups pool properties";
    _poolPropertiesControlGroup ctrlShow true;
    _spawnerPropertiesControlGroup ctrlShow false;
    _groupsConfigControlGroup ctrlShow true;
};