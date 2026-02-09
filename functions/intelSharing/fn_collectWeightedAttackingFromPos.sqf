params ["_group", ["_effectDistance", 250], ["_minWeight", 0.6]];



private _friendlyGroups = allGroups select {_x != _group && {[side _group, side _x] call BIS_fnc_sideIsFriendly}};

_occupiedVantagePoints = [];
{
    _friendlyAttackPosition = _x getVariable ["attackingFromPos", nil];
    if (isNil "_friendlyAttackPosition") then {
        continue;
    };

    _occupiedVantagePoints append [_friendlyAttackPosition];
} forEach _friendlyGroups;



private _maxPenalty = 1 / _minWeight;

_occupiedVantagePointsWeighted = [];
{
    private _avoidedPosition1 = _x;
    private _weightPenalty = 0;

    {
        private _avoidedPosition2 = _x;
        private _distance = _avoidedPosition1 distance2D _avoidedPosition2;

        if (_distance > _effectDistance) then {
            continue;
        };

        _weightPenalty = _weightPenalty + 1 - (_distance / _effectDistance);

        if (_weightPenalty > _maxPenalty) then {
            break;
        };
    } forEach _occupiedVantagePoints;

    private _weight = (1 / _weightPenalty) max _minWeight;

    _occupiedVantagePointsWeighted append [createHashMapFromArray [["pos", _avoidedPosition1], ["weight", _weight]]];
} forEach _occupiedVantagePoints;



_occupiedVantagePointsWeighted;