params ["_spawner", "_placer"];

if (isNil "Rimsiakas_spawnerProcesses") then {
    Rimsiakas_spawnerProcesses = createHashMap;
};

if (!isNil {Rimsiakas_spawnerProcesses get (str _spawner)} && {!isNull (Rimsiakas_spawnerProcesses get (str _spawner))}) exitWith {};

private _syncedUnits = [];
{
    if (count (["Vehicle", "VehicleAutonomous"] arrayIntersect (_x call BIS_fnc_objectType)) > 0) then {
        _syncedUnits append (crew _x); // TODO: didn't check this, assumed it's right, but gotta check actually lol.
    };

    if (_x isKindOf "man") then {
        _syncedUnits append [_x];
    };
} forEach synchronizedObjects _spawner;

_spawner setVariable ["spawnedUnits", _syncedUnits];

private _spawnerProcess = [_spawner, _placer] spawn Rimsiakas_fnc_spawner;

Rimsiakas_spawnerProcesses set [str _spawner, _spawnerProcess];