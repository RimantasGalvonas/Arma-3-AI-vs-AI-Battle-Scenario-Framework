params ["_spawner"];

private _maxUnitsPerGroup = _spawner getVariable ["maxUnitsPerGroup", 0];

private _poolsAndWeights = [];

{
    _poolsAndWeights append [_x, _x get "weight"];
} forEach (_spawner getVariable ["pools", []]);

private _pool = selectRandomWeighted _poolsAndWeights;

private _groupConfig = selectRandom (_pool get "groups");

if (isNil "_groupConfig" || {count _groupConfig == 0}) exitWith {
    [[], _pool];
};

// Convert from group config to units array
if (typeName _groupConfig == "CONFIG") then {
    private _newGroupArray = [];
    private _units = [_groupConfig] call Bis_fnc_getCfgSubClasses;
    {
        private _unitConfig = _groupConfig >> _x;
        private _vehicle = getText (_unitConfig >> "vehicle");
        private _unitClassName = configName (configFile >> "cfgVehicles" >> _vehicle);
        _newGroupArray append [_unitClassName];
    } foreach _units;

    _groupConfig = _newGroupArray;
};


if (typeName _groupConfig != "ARRAY") exitWith {
    ["Spawner %1 is misconfigured.", str _spawner] call BIS_fnc_error;

    [[], _pool];
};

if (count _groupConfig == 0) exitWith {
    [[], _pool];
};


if (_maxUnitsPerGroup > 0 && {count _groupConfig > _maxUnitsPerGroup}) then {
    private _leader = _groupConfig select 0;
    _groupConfig deleteAt 0;
    _groupConfig = (_groupConfig call BIS_fnc_arrayShuffle);
    _groupConfig = [_leader] + _groupConfig;
    _groupConfig resize _maxUnitsPerGroup;
};

[_groupConfig, _pool];