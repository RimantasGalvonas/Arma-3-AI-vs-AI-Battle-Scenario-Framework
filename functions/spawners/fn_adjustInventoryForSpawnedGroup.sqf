params ["_group", "_spawner"];

private _inventoryAdjustments = _spawner getVariable "inventoryAdjustments";

if (isNil "_inventoryAdjustments") exitWith {};

private _maxUnitLoad = (_inventoryAdjustments getOrDefault ["maxUnitLoad", 0]) / 100;
private _maxExtraMags = _inventoryAdjustments getOrDefault ["maxExtraMags", 0];

{
    private _unit = _x;

    private _loadedAmmo = primaryWeaponMagazine _unit;

    if (count _loadedAmmo == 0) then {
        continue;
    };

    private _magazinesAdded = 0;

    while {load _unit < _maxUnitLoad && {_magazinesAdded < _maxExtraMags}} do {
        _unit addMagazines [_loadedAmmo select 0, 1];
        _magazinesAdded = _magazinesAdded + 1;

        if (count _loadedAmmo == 2) then {
            _unit addMagazines [_loadedAmmo select 1, 1];
            _magazinesAdded = _magazinesAdded + 1;
        };
    };
} foreach (units _group);