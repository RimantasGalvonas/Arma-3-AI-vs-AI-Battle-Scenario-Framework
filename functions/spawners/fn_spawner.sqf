params ["_spawner", "_placer"];

while {true} do {
    private _maxUnitsPerSpawner = _spawner getVariable ["maxUnits", 0];
    private _allSpawnerUnits = [_spawner] call Rimsiakas_fnc_getAliveSpawnerUnitsAndCrewArrays;
    private _spawnRate = _spawner getVariable ["spawnRate", 0];

    if (_spawnRate > 0 && {_maxUnitsPerSpawner > 0 && {count (_allSpawnerUnits) >= _maxUnitsPerSpawner}}) then {
        sleep _spawnRate;
        continue;
    };

    ([_spawner] call Rimsiakas_fnc_selectGroupToSpawn) params ["_groupConfig", "_pool"];

    if (isNil "_groupConfig" || {count _groupConfig == 0}) then {
        sleep _spawnRate;
        continue;
    };

    ([_groupConfig, _spawner, _placer] call Rimsiakas_fnc_spawnGroup) params ["_group", "_spawnedUnits"];

    if (_pool getOrDefault ["vehicleCrewGrouping", false]) then {
        {
            private _vehicleCrew = _x select 1;

            if (count _vehicleCrew > 1) then {
                _allSpawnerUnits append [_vehicleCrew];
            } else {
                _allSpawnerUnits append [_vehicleCrew select 0];
            };
        } forEach _spawnedUnits;
    } else {
        _allSpawnerUnits append (units _group);
    };

    _spawner setVariable ["spawnedUnitsAndCrewArrays", _allSpawnerUnits];

    waitUntil {(!isNil "Rimsiakas_missionInitialized" && {Rimsiakas_missionInitialized == true})};

    [(units _group) + ([_group, true] call BIS_fnc_groupVehicles)] call Rimsiakas_fnc_reenableAIAndDamage;

    if (_spawnRate == 0) exitWith {};

    sleep _spawnRate;
};