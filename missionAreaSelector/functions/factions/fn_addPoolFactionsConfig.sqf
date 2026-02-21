private _selected = [] call Rimsiakas_fnc_getSelectedSpawnerAndPoolFactionsConfig;
private _selectedSpawnerPools = ((_selected get "spawner") get "data") get "pools";

_pool = createHashMapFromArray [
    ["groups", []],
    ["weight", 1]
];

_selectedSpawnerPools append [_pool];

[] call Rimsiakas_fnc_populateSpawnerTreeFactionsConfig;