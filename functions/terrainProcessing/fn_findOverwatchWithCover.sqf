// Author:
//     Rimantas Galvonas

// Description:
//     Function to search an area for a position with cover from which a target location can be seen.

// Parameters:
//     0: ARRAY - _centerPos - the position around which the search is done
//     1: ARRAY - _targetPos - the target location (usually the enemy location)
//     2: NUMBER - _maxDistance - maximum search radius
//     3: (Optional) NUMBER - _minDistance - minimum search radius
//     4: (Optional) NUMBER - _requiredFlatness- maximum terrain gradient (hill steepness)
//     5: (Optional) BOOLEAN - _approachMode - approach mode
//         When set to true, this function will serach the locations in a semicircle around the _targetPos from the direction of _centerPos
//     6: (Optional) BOOLEAN - _precisionMode - increased precision mode
//         When set to true, an additional scan will be done around the selected position to find the position with the most cover more precisely.
//     7: (Optional) ARRAY - _positionsToAvoid - positions to avoid
//         Decrease the chance for positions to be selected that are nearby the provided positions. Note that a position nearby may still be chosen if its is by far the best option.
//         Positions are hashmaps containing keys "pos" and "weight"

// Returns:
//     HASHMAP - data of the position with cover from which the target location can be seen or nil if no such location could be found.
//     [
//         "pos" - result position
//         "nearbyCoveredPositions" - array of positions with cover 10m around this position
//         "score" - score calculated for this position
//         "heightDifference" - height advantage over the target
//     ]


params ["_centerPos", "_targetPos", "_maxDistance", ["_minDistance", 1], ["_requiredFlatness", nil], ["_approachMode", false], ["_precisionMode", true], ["_positionsToAvoid", []]];

private _intersectionCheckInterval = 10;
private _coverGroupingRadius = 30;

// Add a metre to the heights to measure visibility not straight from the ground
_targetPos set [2, (_targetPos select 2) + 1];

private _selectedPositions = [];

private _suitableCoverClasses = ["TREE", "SMALL TREE", "BUILDING", "HOUSE", "FOREST BORDER", "CHURCH", "CHAPEL", "CROSS", "BUNKER", "FORTRESS", "FOUNTAIN", "VIEW-TOWER", "LIGHTHOUSE", "FUELSTATION", "HOSPITAL", "WALL", "HIDE", "BUSSTOP", "FOREST", "TRANSMITTER", "STACK", "RUIN", "TOURISM", "WATERTOWER", "ROCK", "ROCKS", "POWERSOLAR", "POWERWIND", "SHIPWRECK"];

private _angleStart = 0;
private _angleEnd = 359;



// For when _approachMode == true
private _targetDirection = _centerPos getDir _targetPos;
private _attackerPosition = _centerPos;
private _approachConeAngle = 0;
if (_approachMode) then {
    _centerPos = _targetPos;
};



// Collect spots that have visibility to the target area,
for "_radius" from _minDistance to _maxDistance step _intersectionCheckInterval do {
    private _circumference = _radius * 2 * 3.14;
    private _pointsCount = _circumference / _intersectionCheckInterval;
    private _angleIncrement = 360 / _pointsCount;

    if (_approachMode) then {
        _approachConeAngle = 240 - 0.39 * _radius;
        _angleStart = 180 + _targetDirection - (_approachConeAngle / 2);
        _angleEnd = 180 + _targetDirection + (_approachConeAngle / 2);
    };

    for "_angle" from _angleStart to _angleEnd step _angleIncrement do {

        private _checkPos = _centerPos getPos [_radius, _angle];

        if (_approachMode && {!([_attackerPosition, _targetDirection, _approachConeAngle, _checkPos] call BIS_fnc_inAngleSector)}) then {
            continue;
        };

        _checkPos set [2, 1]; // Check from 1 meter above ground

        private _isFlat = (isNil "_requiredFlatness" || {!(_checkPos isFlatEmpty [-1, -1, _requiredFlatness, _intersectionCheckInterval / 2, 0] isEqualTo [])});

        if (!_isFlat) then {
            continue;
        };

        if (terrainIntersect [_targetPos, _checkPos]) then {
            continue;
        };

        if (count (nearestTerrainObjects [_checkPos, _suitableCoverClasses, _intersectionCheckInterval, false]) == 0) then {
            continue;
        };

        _selectedPositions append [_checkPos];
    };
};



// Group the separate positions into larger areas to calculate a score for each one taking available cover into account.
private _validPositions = [];
for "_radius" from _minDistance to _maxDistance step _coverGroupingRadius do {
    private _circumference = _radius * 2 * 3.14;
    private _pointsCount = _circumference / _coverGroupingRadius;
    private _angleIncrement = 360 / _pointsCount;

    if (_approachMode) then {
        _approachConeAngle = 240 - 0.39 * _radius;
        _angleStart = 180 + _targetDirection - (_approachConeAngle / 2);
        _angleEnd = 180 + _targetDirection + (_approachConeAngle / 2);
    };

    for "_angle" from _angleStart to _angleEnd step _angleIncrement do {
        private _checkPos = _centerPos getPos [_radius, _angle];

        if (_approachMode && {!([_attackerPosition, _targetDirection, _approachConeAngle, _checkPos] call BIS_fnc_inAngleSector)}) then {
            continue;
        };

        private _coverAroundThisPos = _selectedPositions inAreaArray [_checkPos, _coverGroupingRadius, _coverGroupingRadius, 0, false];

        if (count _coverAroundThisPos > 0) then {
            private _score = count _coverAroundThisPos;

            private _positionData = createHashMap;
            _positionData set ["pos", _checkPos];
            _positionData set ["nearbyCoveredPositions", _coverAroundThisPos];
            _positionData set ["score", _score];

            _validPositions append [_positionData];
        };
    };
};



// Adjust score by height advantage
{
    private _checkPos = _x get "pos";
    private _heightDifference = (getTerrainHeightASL _checkPos) - (getTerrainHeightASL _targetPos);

    private _heightMultiplier = 1;
    if (_heightDifference > 0) then {
        _heightMultiplier = 1 + (_heightDifference * 0.05); // Add 1 to multiplier with every 20 meters of height advantage
        _heightMultiplier = _heightMultiplier min 3;
    } else {
        if (_heightDifference < 0) then {
            _heightMultiplier = 1 / (1 + (abs _heightDifference * 0.05)); // Halve the multiplier with every 20 meters of height disadvantage
            _heightMultiplier = _heightMultiplier max 0.33;
        };
    };

    private _score = (_x get "score") * _heightMultiplier;

    _x set ["score", _score];
    _x set ["heightDifference", _heightDifference];

    _validPositions set [_forEachIndex, _x];
} forEach _validPositions;



// Adjust score by distance to positions-to-avoid
private _indicesToDelete = [];
private _maxProximityPenalty = 2.5;
if ((count _positionsToAvoid) > 0) then {
    {
        private _checkPos = _x get "pos";

        _proximityPenaltyDivisor = [_checkPos, _positionsToAvoid, _maxProximityPenalty] call Rimsiakas_fnc_getProximityToAvoidedPositionsPenaltyDivisor;

        if (_proximityPenaltyDivisor > _maxProximityPenalty) then {
            _indicesToDelete append [_forEachIndex]; // Can't just delete here, _forEachIndex gets messed up

            continue;
        };

        if (_proximityPenaltyDivisor > 1) then {
            private _score = (_x get "score") / _proximityPenaltyDivisor;
            _x set ["score", _score];
            _validPositions set [_forEachIndex, _x];
        };
    } forEach _validPositions;
};
_validPositions deleteAt _indicesToDelete;



//Positions and their scores are put into a flat array to be used with selectRandomWeighted command
private _positionsAndScore = [];
{
    _positionsAndScore append [_x, _x get "score"];
} forEach _validPositions;

// Don't always return the best position, but a bit randomized - otherwise nearby squads will be taking identical paths to the same target.
private _result = selectRandomWeighted _positionsAndScore;



if (isNil "_result") exitWith {};

if (!_precisionMode) then {
    private _averagePositionOfCoveredAreas = [_result get "nearbyCoveredPositions"] call Rimsiakas_fnc_getAveragePosition;
    private _bestPosition = [(_result get "nearbyCoveredPositions"), _averagePositionOfCoveredAreas] call BIS_fnc_nearestPosition;

    _result set ["pos", _bestPosition];
} else {
    // Additional scan around the selected position to find the position with the most cover more precisely.
    private _coveredPositions = _result get "nearbyCoveredPositions";
    private _preciseMostCoveredPosition = _result get "pos";
    private _preciseMostCoveredPositionCoverCount = 0;

    {
        private _coveredPosition = _x;
        private _coveredPositionsAroundHere = [];

        for "_radius" from 1 to 6.5 step 3 do {
            private _circumference = _radius * 2 * 3.14;
            private _pointsCount = _circumference / 3;
            private _angleIncrement = 360 / _pointsCount;

            for "_angle" from 0 to 359 step _angleIncrement do {

                private _checkPos = _coveredPosition getPos [_radius, _angle];

                if (count (nearestTerrainObjects [_checkPos, _suitableCoverClasses, 3, false]) > 0) then {
                    _coveredPositionsAroundHere append [_checkPos];
                };
            };
        };

        if (_preciseMostCoveredPositionCoverCount < count _coveredPositionsAroundHere) then {
            _preciseMostCoveredPosition = _coveredPosition;
            _preciseMostCoveredPositionCoverCount = count _coveredPositionsAroundHere;
        };
    } forEach _coveredPositions;

    _result set ["pos", _preciseMostCoveredPosition];
};

_result;