#include "..\elementIds.hpp"

private _factionConfigDialog = findDisplay FACTIONS_CONFIG_IDD;

private _spawnerList = _factionConfigDialog displayCtrl FACTIONS_CONFIG_SPAWNERPOOLSTREE_IDC;

private _spawnerSelectionPath = (tvSelection _spawnerList) select 0;
private _spawnerIndex = _spawnerSelectionPath select 0;
private _selectedSpawnerName = _spawnerList tvText [_spawnerIndex];
private _selectedSpawnerData = (Rimsiakas_workingSpawnersData get "spawners") get _selectedSpawnerName;

private _result = createHashMap;

_result set ["spawner", createHashMapFromArray [["index", _spawnerIndex], ["data", _selectedSpawnerData], ["name", _selectedSpawnerName]]];

if (count _spawnerSelectionPath == 2) then {
    private _poolIndex = _spawnerSelectionPath select 1;
    private _selectedPoolData = (_selectedSpawnerData get "pools") select _poolIndex;

    _result set ["pool", createHashMapFromArray [["index", _poolIndex], ["data", _selectedPoolData]]];
};

_result;