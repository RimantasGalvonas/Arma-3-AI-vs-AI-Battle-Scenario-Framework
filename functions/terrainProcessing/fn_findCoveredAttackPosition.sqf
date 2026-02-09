// Author:
//     Rimantas Galvonas

// Description:
//     Simplified version of the findOverwatchWithCover function, used to find covered areas further from other group's attacking positions.

// Parameters:
//     0: ARRAY - _attackerPosition - the position around which the search is done
//     1: ARRAY - _targetPos - the target location (usually the enemy location)
//     2: NUMBER - _maxDistance - maximum search radius
//     3: (Optional) NUMBER - _minDistance - minimum search radius
//     4: (Optional) ARRAY - _positionsToAvoid - positions to avoid
//         Decrease the chance for positions to be selected that are nearby the provided positions. Note that a position nearby may still be chosen if its is by far the best option.
//         Positions are hashmaps containing keys "pos" and "weight"

// Returns:
//     HASHMAP - data of the position with cover from which the target location can be seen or nil if no such location could be found.
//     [
//         "pos" - result position
//         "nearestTerrainObjects" - nearvy terrain object suitable for cover
//         "score" - score calculated for this position
//     ]


params ["_attackerPosition", "_targetPos", "_maxDistance", ["_minDistance", 1], ["_positionsToAvoid", []]];

private _checkInterval = 30;
private _targetDirection = _attackerPosition getDir _targetPos;

private _suitableCoverClasses = ["TREE", "SMALL TREE", "BUILDING", "HOUSE", "FOREST BORDER", "CHURCH", "CHAPEL", "CROSS", "BUNKER", "FORTRESS", "FOUNTAIN", "VIEW-TOWER", "LIGHTHOUSE", "FUELSTATION", "HOSPITAL", "WALL", "HIDE", "BUSSTOP", "FOREST", "TRANSMITTER", "STACK", "RUIN", "TOURISM", "WATERTOWER", "ROCK", "ROCKS", "POWERSOLAR", "POWERWIND", "SHIPWRECK"];

//Positions and their scores are put into a flat array to be used with selectRandomWeighted command
private _positionsAndScore = [];

for "_radius" from _minDistance to _maxDistance step _checkInterval do {
    private _circumference = _radius * 2 * 3.14;
    private _pointsCount = _circumference / _checkInterval;
    private _angleIncrement = 360 / _pointsCount;
    private _approachConeAngle = 240 - 0.39 * _radius;
    private _angleStart = 180 + _targetDirection - (_approachConeAngle / 2);
    private _angleEnd = 180 + _targetDirection + (_approachConeAngle / 2);


    for "_angle" from _angleStart to _angleEnd step _angleIncrement do {

        private _checkPos = _targetPos getPos [_radius, _angle];

        if (!([_attackerPosition, _targetDirection, _approachConeAngle, _checkPos] call BIS_fnc_inAngleSector)) then {
            continue;
        };

        private _nearestTerrainObjects = nearestTerrainObjects [_checkPos, _suitableCoverClasses, _checkInterval, false];
        private _score = (count (_nearestTerrainObjects) + 0.5) min 10;

        // Adjust score by distance to positions-to-avoid
        if ((count _positionsToAvoid) > 0) then {
            _proximityPenaltyDivisor = [_checkPos, _positionsToAvoid, 2.5] call Rimsiakas_fnc_getProximityToAvoidedPositionsPenaltyDivisor;

            if (_proximityPenaltyDivisor > 1) then {
                _score = _score / _proximityPenaltyDivisor;
            };
        };

        private _positionData = createHashMap;
        _positionData set ["pos", _checkPos];
        _positionData set ["nearestTerrainObjects", _nearestTerrainObjects];
        _positionData set ["score", _score];

        _positionsAndScore append [_positionData, _score];
    };
};

private _result = selectRandomWeighted _positionsAndScore;



if (isNil "_result") exitWith {};

private _nearestCover = (_result get "nearestTerrainObjects") apply {getPos _x};
if (count _nearestCover > 0) then {
    private _averagePositionOfCoveredAreas = [_nearestCover] call Rimsiakas_fnc_getAveragePosition;
    private _bestPosition = [_nearestCover, _averagePositionOfCoveredAreas] call BIS_fnc_nearestPosition;
    _result set ["pos", _bestPosition];
};

_result;