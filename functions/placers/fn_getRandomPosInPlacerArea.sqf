params ["_placer"];

private _areaTriggers = _placer getVariable ["areaTriggers", []];
private _whitelistedSearchAreas = [];
private _blackListedSearchAreas = ["water"];

if (count _areaTriggers > 0) then {
    _whitelistedSearchAreas = _areaTriggers;
} else {
    _whitelistedSearchAreas = [[getPos _placer, _placer getVariable "maxSpawnRadius"]];
    _blackListedSearchAreas append [[getPos _placer, _placer getVariable "minSpawnRadius"]];
};

[_whitelistedSearchAreas, _blackListedSearchAreas] call BIS_fnc_randomPos;