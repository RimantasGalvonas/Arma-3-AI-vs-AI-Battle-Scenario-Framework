private _nearUnits = nearestObjects [player, ["Man"], 200];

private _nearestFriendly = nil;

{
    if (_x != player && { side _x != civilian && {[side _x, side player] call BIS_fnc_sideIsFriendly}}) exitWith {_nearestFriendly = _x;}
} forEach _nearUnits;

if (isNil "_nearestFriendly") then {
    hint "No friendlies within 200 meters."
} else {
    [player] join group _nearestFriendly;
};