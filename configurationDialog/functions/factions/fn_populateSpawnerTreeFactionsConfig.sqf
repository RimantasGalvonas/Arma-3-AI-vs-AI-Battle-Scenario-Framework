_sortedSpawnerKeys = [keys (Rimsiakas_workingSpawnersData get "spawners"), [], {_x}, "ASCEND"] call BIS_fnc_sortBy;

private _spawnersTree = displayCtrl 401002;

private _lastSelection = (tvSelection _spawnersTree) select 0;

tvClear _spawnersTree;

{
    private _spawnerIndex = _forEachIndex;
    private _spawner = (Rimsiakas_workingSpawnersData get "spawners") get _x;
    private _poolsConfig = _spawner get "pools";

    _spawnersTree tvAdd [[], _x];

    private _pools = [];

    {
        _spawnersTree tvAdd [[_spawnerIndex], ("Pool " + str (_forEachIndex + 1))];
    } forEach _poolsConfig;
} forEach _sortedSpawnerKeys;


tvExpandAll _spawnersTree;

if (!isNil "_lastSelection") then {
    _spawnersTree tvSetCurSel _lastSelection;
};