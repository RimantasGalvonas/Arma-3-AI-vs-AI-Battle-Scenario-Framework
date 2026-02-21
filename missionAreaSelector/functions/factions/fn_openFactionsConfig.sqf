[] spawn {
    private _spawners = entities "LOGIC" select {_x getVariable ["logicType", ""] == "spawner"};

    waitUntil {!isNull findDisplay 46423};

    private _spawnerPropertiesControlGroup = displayCtrl 402001;
    private _poolPropertiesControlGroup = displayCtrl 403001;
    private _groupsConfigControlGroup = displayCtrl 404001;
    private _addGroupButton = displayCtrl 404005;
    private _greenforAlliesField = displayCtrl 400503;
    _spawnerPropertiesControlGroup ctrlShow false;
    _poolPropertiesControlGroup ctrlShow false;
    _groupsConfigControlGroup ctrlShow false;
    _addGroupButton ctrlEnable false;



    _map = displayCtrl 409999;
    _map ctrlMapAnimAdd [0, 0.5, getMarkerPos "missionAreaMarker"];
    // TODO: markers on map
    ctrlMapAnimCommit _map;



    private _spawnersTree = displayCtrl 401002;

    Rimsiakas_lastSavedSpawnersData = createHashMap;
    private _collectedSpawners = createHashMap;
    Rimsiakas_lastSavedSpawnersData set ["spawners", _collectedSpawners];



    private _independentRelation = 0;

    if ([independent, west] call BIS_fnc_sideIsFriendly) then {
        _independentRelation = _independentRelation + 1;
    };

    if ([independent, east] call BIS_fnc_sideIsFriendly) then {
        _independentRelation = _independentRelation + 2;
    };

    _greenforAlliesField lbSetCurSel _independentRelation;

    Rimsiakas_lastSavedSpawnersData set ["independentRelation", _independentRelation];



    {
        private _spawner = _x;

        private _poolsConfig = _spawner getVariable ["groupPools", []];

        private _spawnerData = createHashMapFromArray [
            ["maxUnitsPerGroup", _spawner getVariable ["maxUnitsPerGroup", 0]],
            ["maxUnits", _spawner getVariable ["maxUnits", 0]],
            ["spawnRate", _spawner getVariable ["spawnRate", 0]]
        ];

        private _pools = [];

        {
            if (typeName _x != "ARRAY") then {
                continue;
            };

            _poolData = createHashMapFromArray [
                ["groups", _x],
                ["weight", _poolsConfig select (_forEachIndex + 1)]
            ];

            _pools append [_poolData];
        } forEach _poolsConfig;

        _spawnerData set ["pools", _pools];

        _collectedSpawners set [str _spawner, _spawnerData];
    } forEach _spawners;



    if (isNil "Rimsiakas_initialSpawnersData") then {
        Rimsiakas_initialSpawnersData = +Rimsiakas_lastSavedSpawnersData;
    };

    Rimsiakas_workingSpawnersData = +Rimsiakas_lastSavedSpawnersData;



    [] call Rimsiakas_fnc_populateSpawnerTreeFactionsConfig;
    [] call Rimsiakas_fnc_populateGroupsConfigTreeGroupsFactionsConfig;
};