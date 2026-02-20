params ["_placer"];

private _vehicleSpawnRadius = 50;
private _whitelistedSearchAreas = [];
private _blackListedSearchAreas = ["water"];

private _areaTriggers = _placer getVariable ["areaTriggers", []];

if (count _areaTriggers > 0) then {
    _whitelistedSearchAreas = _areaTriggers;
} else {
    private _minimumDistance = _placer getVariable "minSpawnRadius";
    private _maximumDistance = _placer getVariable "maxSpawnRadius";

    _vehicleSpawnRadius = (_maximumDistance - _minimumDistance) / 2;
    _whitelistedSearchAreas = [[getPos _placer, _minimumDistance + _vehicleSpawnRadius]];
    _blackListedSearchAreas append [[getPos _placer, _minimumDistance]];
};

private "_road";
private _maxRoadFindTryAttempts = 10;
private _roadFindAttemptsCount = 0;



while {isNil "_road" && _roadFindAttemptsCount < _maxRoadFindTryAttempts} do {
    private _randomPositionForRoadSearch = [_whitelistedSearchAreas, _blackListedSearchAreas] call BIS_fnc_randomPos;
    _blackListedSearchAreas append [[_randomPositionForRoadSearch, _vehicleSpawnRadius]];

    private _nearRoads = _randomPositionForRoadSearch nearRoads (_vehicleSpawnRadius);
    {
        if (((getRoadInfo _x) select 2) == false) exitWith {_road = _x};
    } foreach _nearRoads;

    _roadFindAttemptsCount = _roadFindAttemptsCount + 1;
};

if (!isNil "_road") then {
    _road;
};