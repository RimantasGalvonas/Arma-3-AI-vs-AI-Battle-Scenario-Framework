params [["_groupConfig", []], "_spawner", "_placer"];

if (count _groupConfig == 0) exitWith {
    ["Something misconfigured: Spawner %1 tried spawning a group with 0 units.", str _spawner] call BIS_fnc_error;
};

private _vehicleConfig = configFile >> "cfgVehicles" >> (_groupConfig select 0);
private _sideId = getNumber (_vehicleConfig >> "side");
private _side = _sideId call BIS_fnc_sideType;

private _group = createGroup [_side, true];

private _spawnedUnits = [];

{
    private _tempUnitPosition = (getPos _spawner) findEmptyPosition [2, 200, _x]; // Simple starting position. The full placement logic happens in Rimsiakas_fnc_teleportSquadToRandomPosition

    private "_spawnedUnit";

    if ((getPos _placer select 2) < 50) then {
        _tempUnitPosition set [2, [10000, 30000] call BIS_fnc_randomInt]; // Spawn very high above the ground to avoid collisions
        _spawnedUnit = [_tempUnitPosition, 0, _x, _group] call Rimsiakas_fnc_spawnVehicleNoFly;
    } else {
        _spawnedUnit = [_tempUnitPosition, 0, _x, _group] call BIS_fnc_spawnVehicle;

        private _spawnedVehicle = _spawnedUnit select 0;
        _spawnedVehicle setVariable ["Rimsiakas_originalSpawnVelocity", velocityModelSpace _spawnedVehicle];
        _spawnedVehicle setVariable ["Rimsiakas_originalSpawnHeight", (getPos _spawnedVehicle) select 2];
    };

    (_spawnedUnit select 0) allowDamage false;
    {
        _x allowDamage false;
        (_spawnedUnit select 0) disableAI "all"; // Temporarily disabled to avoid firefights breaking out while mission is initializing
    } foreach (_spawnedUnit select 1);

    _spawnedUnits append [_spawnedUnit];
} foreach _groupConfig;

[_group, _placer] call Rimsiakas_fnc_teleportSquadToRandomPosition;

if ("Support" in ([_group] call Rimsiakas_fnc_getVehicleClassesInGroup)) then {
    _group setVariable ["ignoreIntel", true];
    private _waypoint = _group addWaypoint [(getPos leader _group), 0];
    _waypoint setWaypointType "SUPPORT";
} else {
    [_group, _spawner] call Rimsiakas_fnc_adjustInventoryForSpawnedGroup;
    [_group] call Rimsiakas_fnc_searchForEnemies;
    [_group] call Rimsiakas_fnc_orientGroupTowardsWaypoint;

    if (_placer getVariable ["highCommandSubordinates", false]) then {
        [_group] call Rimsiakas_fnc_assignHighCommanderToSpawnedGroup;
    };
};


private _callback = _spawner getVariable ["callback", {}];

[_group, _spawner, _placer] call _callback;

[_group, _spawnedUnits];