if (!(["Are you sure?", "Clear all pools", true, true] call BIS_fnc_guiMessage)) exitWith {};

private _selected = [] call Rimsiakas_fnc_getSelectedSpawnerAndPool;

_pool = createHashMapFromArray [
    ["groups", []],
    ["weight", 1]
];

((_selected get "spawner") get "data") set ["pools", [_pool]];

[] call Rimsiakas_fnc_populateSpawnerTree;