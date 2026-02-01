private _nearUnits = nearestObjects [player, ["Man"], 200];

private _nearestFriendly = nil;

{
    if (side _x == side player && {_x != player}) exitWith {_nearestFriendly = _x;}
} forEach _nearUnits;

if (isNil "_nearestFriendly") then {
    hint "No friendlies within 200 meters."
} else {
    [player] join group _nearestFriendly;
};