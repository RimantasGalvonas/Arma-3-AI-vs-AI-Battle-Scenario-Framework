params ["_data"];

_data params ["_control", "_path"];


private _secondColumnFrame = displayCtrl 402000;
private _spawnerPropertiesControlGroup = displayCtrl 402001;
private _poolPropertiesControlGroup = displayCtrl 403001;

private _spawnerData = Rimsiakas_workingSpawnersData get (_control tvText [_path select 0]);

if (count _path == 1) then {
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
};

if (count _path == 2) then {
    private _poolGroupsList = displayCtrl 403003;
    private _poolWeightField = displayCtrl 403005;

    lbClear _poolGroupsList;

    private _poolIndex = _path select 1;
    private _pool = (_spawnerData getOrDefault ["pools", []]) select _poolIndex;

    {
        private _hierarchy = (configHierarchy (_x) apply {getText (_x >> "name")}) - [""];
        private _name = format ["%1 (%2 / %3)", _hierarchy select -1, _hierarchy select 1, _hierarchy select 2];
        private _index = _poolGroupsList lbAdd _name;
        private _tooltip = ((configHierarchy (_x) apply {getText (_x >> "name")}) - [""]) joinString " / ";

        _poolGroupsList lbSetTooltip [_index, _tooltip];

    } forEach (_pool getOrDefault ["groups", []]);

    private _weight = _pool getOrdEfault ["weight", 0];
    _poolWeightField ctrlSetText (str _weight);

    _secondColumnFrame ctrlSetText "Groups pool properties";
    _poolPropertiesControlGroup ctrlShow true;
    _spawnerPropertiesControlGroup ctrlShow false;
};