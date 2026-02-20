params ["_placer"];



if (surfaceIsWater (getPos _placer) && {_placer getVariable ["relocateToNearestLandIfOnWater", false]}) then {
    _placer setPos ([getPos _placer] call Rimsiakas_fnc_findNearestLand);
};



private _areaTriggers = _placer getVariable ["areaTriggers", []];
private _whitelistedSearchAreas = [];
private _blackListedSearchAreas = ["water"];

if (count _areaTriggers > 0) then {
    _whitelistedSearchAreas = _areaTriggers;
} else {
    _whitelistedSearchAreas = [[getPos _placer, _placer getVariable "maxSpawnRadius"]];
    _blackListedSearchAreas append [[getPos _placer, _placer getVariable "minSpawnRadius"]];
};


// Child placers
{
    if (_x getVariable "logicType" == "placer") then {
        private _randomPos = nil;

        if (_x getVariable ["preferRoad", false]) then {
            _road = [_placer] call Rimsiakas_fnc_findRoad;
            if (!(isNil "_road")) then {
                _randomPos = getPos _road;
            }
        };

        if (isNil "_randomPos") then {
            _randomPos = [_whitelistedSearchAreas, _blackListedSearchAreas] call BIS_fnc_randomPos;
        };

        _x setPos _randomPos;

        [_x] call Rimsiakas_fnc_placer;
    };
} forEach (_placer getVariable "childPlacers");



// Synchronized units
{
    private _syncedUnit = _x;
    private _syncedGroup = nil;

    if (count (["Vehicle", "VehicleAutonomous"] arrayIntersect (_syncedUnit call BIS_fnc_objectType)) > 0) then {
        _syncedUnit = (crew _x) select 0;
    };

    if (_syncedUnit isKindOf "man") then {
        _syncedGroup = group _syncedUnit;
    };

    if (!isNil {_syncedGroup}) then {
        [_syncedGroup, _placer] call Rimsiakas_fnc_teleportSquadToRandomPosition;

        (hcLeader _syncedGroup) hcRemoveGroup _syncedGroup;

        if ("Support" in ([_syncedGroup] call Rimsiakas_fnc_getVehicleClassesInGroup)) then {
            _syncedGroup setVariable ["ignoreIntel", true];
            _waypoint = _syncedGroup addWaypoint [(getPos leader _syncedGroup), 0];
            _waypoint setWaypointType "SUPPORT";
        } else {
            [_syncedGroup] call Rimsiakas_fnc_searchForEnemies;
            [_syncedGroup] call Rimsiakas_fnc_orientGroupTowardsWaypoint;

            if (_placer getVariable ["highCommandSubordinates", false]) then {
                Rimsiakas_highCommandSubordinates append [_syncedGroup];
            };
        };

        _syncedGroup deleteGroupWhenEmpty true;
    };
} foreach synchronizedObjects _placer;



// Spawners
{
    if (_x getVariable "logicType" == "spawner") then {
        _randomPos = [_whitelistedSearchAreas, _blackListedSearchAreas] call BIS_fnc_randomPos;
        _x setPos _randomPos;
        [_x, _placer] call Rimsiakas_fnc_initializeSpawner;
    };
} forEach (_placer getVariable "spawners");



// Units from groups variable
{
    [_placer, _x] call Rimsiakas_fnc_squadSpawner;
    {_x disableAI "all"} forEach allUnits; // Temporarily disabled to avoid firefights breaking out while mission is initializing
} forEach (_placer getVariable "groups");



// Camps
{
    [_x, _placer] call Rimsiakas_fnc_spawnCamp;
    {_x disableAI "all"} forEach allUnits; // Temporarily disabled to avoid firefights breaking out while mission is initializing
} forEach (_placer getVariable "camps");



// Synchronized respawn positions, AI spawn modules and objects
{
    private _randomPosition = [_placer, 10, 0, 0.3, 0, [], [[0,0],[0,0]]] call Rimsiakas_fnc_findSafePosWithTrigger;
    if ((_randomPosition select 0) == 0) then {
        // If no clear area can be found, try to find a flattish place
        _randomPosition = [_placer, 0.1, 0, 0.3, 0, [], [[0,0],[0,0]]] call Rimsiakas_fnc_findSafePosWithTrigger;

        if ((_randomPosition select 0) == 0) then {
            // If no flat area can be found, choose a random one
            _randomPosition = [_whitelistedSearchAreas, _blackListedSearchAreas] call BIS_fnc_randomPos;
        };

        // Clear the chosen area
        private _terrainObjects = nearestTerrainObjects [_randomPosition, [], 10, false];
        {
            _x hideObjectGlobal true;
        } forEach _terrainObjects;
    };

    _x setPos _randomPosition;

} foreach (synchronizedObjects _placer select {(typeOf _x) find "ModuleRespawnPosition" == 0 || {typeOf _x in ['ModuleSpawnAI_F', "ModuleSpawnAIPoint_F"] || {"Object" in (_x call BIS_fnc_objectType)}}});