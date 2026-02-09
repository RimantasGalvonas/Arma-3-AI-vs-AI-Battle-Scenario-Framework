params ["_checkPos", "_positionsToAvoid", ["_maxPenalty", 2.5], ["_proximityPenaltyEffectRadius", 450]];

private _closestPositionToAvoid = ([_positionsToAvoid, [_checkPos], { (_x get "pos") distanceSqr _input0}, "ASCEND"] call BIS_fnc_sortBy) select 0;
private _distanceToClosest = (_closestPositionToAvoid get "pos") distance2D _checkPos;
private _proximityPenaltyDivisorForClosest = (_proximityPenaltyEffectRadius / _distanceToClosest) ^ 0.4;

private _proximityPenaltyDivisorWeighted = 1;

{
    private _positionToAvoidData = _x;
    private _distance = (_positionToAvoidData get "pos") distance2D _checkPos;

    if (_distance > _proximityPenaltyEffectRadius) then {
        continue;
    };

    _proximityPenaltyDivisorWeighted = _proximityPenaltyDivisorWeighted + (_positionToAvoidData get "weight") * ((_proximityPenaltyEffectRadius / _distance) ^ 0.4 - 1);
} forEach _positionsToAvoid;

_proximityPenaltyDivisorWeighted max _proximityPenaltyDivisorForClosest;