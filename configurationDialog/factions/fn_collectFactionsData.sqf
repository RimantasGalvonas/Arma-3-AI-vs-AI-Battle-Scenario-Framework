
Rimsiakas_lastSavedFactionsData = createHashMap;
private _collectedSpawners = createHashMap;
Rimsiakas_lastSavedFactionsData set ["spawners", _collectedSpawners];



private _independentRelation = 0;

if ([independent, west] call BIS_fnc_sideIsFriendly) then {
    _independentRelation = _independentRelation + 1;
};

if ([independent, east] call BIS_fnc_sideIsFriendly) then {
    _independentRelation = _independentRelation + 2;
};

Rimsiakas_lastSavedFactionsData set ["independentRelation", _independentRelation];



private _spawners = entities "LOGIC" select {_x getVariable ["logicType", ""] == "spawner"};

{
    private _spawner = _x;

    private _spawnerData = createHashMapFromArray [
        ["maxUnitsPerGroup", _spawner getVariable ["maxUnitsPerGroup", 0]],
        ["maxUnits", _spawner getVariable ["maxUnits", 0]],
        ["spawnRate", _spawner getVariable ["spawnRate", 0]],
        ["inventoryAdjustments", _spawner getVariable ["inventoryAdjustments", createHashMap]],
        ["pools", _spawner getVariable ["pools", []]]
    ];

    _collectedSpawners set [str _spawner, _spawnerData];
} forEach _spawners;

Rimsiakas_workingFactionsData = +Rimsiakas_lastSavedFactionsData;

if (isNil "Rimsiakas_initialFactionsData") then {
    Rimsiakas_initialFactionsData = +Rimsiakas_lastSavedFactionsData;
};