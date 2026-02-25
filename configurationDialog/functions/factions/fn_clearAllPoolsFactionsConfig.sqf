private _selected = [] call Rimsiakas_fnc_getSelectedSpawnerAndPoolFactionsConfig;

_pool = createHashMapFromArray [
    ["groups", []],
    ["weight", 1]
];

((_selected get "spawner") get "data") set ["pools", [_pool]];

[] call Rimsiakas_fnc_populateSpawnerTreeFactionsConfig;