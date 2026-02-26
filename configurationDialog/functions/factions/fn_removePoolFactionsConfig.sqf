#include "..\..\elementIds.hpp"

if (!(["Are you sure?", "Remove pool", true, true] call BIS_fnc_guiMessage)) exitWith {};

private _spawnersTree = displayCtrl FACTIONS_CONFIG_SPAWNERPOOLSTREE_IDC;

private _selected = [] call Rimsiakas_fnc_getSelectedSpawnerAndPoolFactionsConfig;

private _spawnerPools = ((_selected get "spawner") get "data") get "pools";

_spawnerPools deleteAt ((_selected get "pool") get "index");

_spawnersTree tvSetCurSel [(_selected get "spawner") get "index"];

[] call Rimsiakas_fnc_populateSpawnerTreeFactionsConfig;