params ["_spawner", "_placer"];

while {true} do {
    private _maxUnitsPerSpawner = _spawner getVariable ["maxUnits", 0];
    private _spawnerUnits = (_spawner getVariable ["spawnedUnits", []]) select {alive _x};
    private _spawnRate = _spawner getVariable ["spawnRate", 0];

    if (_spawnRate > 0 && {_maxUnitsPerSpawner > 0 && {count (_spawnerUnits) >= _maxUnitsPerSpawner}}) then {
        sleep _spawnRate;

        continue;
    };

    _groupConfig = [_spawner] call Rimsiakas_fnc_selectGroupToSpawn;

    if (count _groupConfig == 0) then {
        continue;
    };

    private _group = [_groupConfig, _spawner, _placer] call Rimsiakas_fnc_spawnGroup;

    _spawnerUnits append (units _group);
    _spawner setVariable ["spawnedUnits", _spawnerUnits];


    waitUntil {(!isNil "Rimsiakas_missionInitialized" && {Rimsiakas_missionInitialized == true})};

    [_spawnerUnits] call Rimsiakas_fnc_reenableAI;

    if (_spawnRate == 0) exitWith {};

    sleep _spawnRate;
};