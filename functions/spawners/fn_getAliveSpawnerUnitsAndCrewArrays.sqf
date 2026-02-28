params ["_spawner"];

private _alive = [];

{
    if (typeName _x != "ARRAY" && {alive _x}) then {
        _alive append [_x];

        continue;
    };

    if (typeName _x == "ARRAY" && {count (_x select {alive _x;}) > 0}) then {
        _alive append [_x];
    };
} forEach (_spawner getVariable ["spawnedUnitsAndCrewArrays", []]);

_alive;