// Reset the chosen attack position to the next waypoint position if the original attack position has been passed already. This is used in making groups spread out.

params ["_group"];

private _selectedAttackPosition = _group getVariable ["attackingFromPos", nil];
if (isNil "_selectedAttackPosition") exitWith {};

private _lastKnownTargetPos = _group getVariable ["lastReportedTargetPosition", nil];
if (isNil "_lastKnownTargetPos") exitWith {};

if ((_lastKnownTargetPos distance2D leader _group) < (_lastKnownTargetPos distance2D _selectedAttackPosition) || {(_selectedAttackPosition distance2D leader _group) < 50}) then {
    private _waypointPos = waypointPosition [_group, (currentWaypoint _group) + 1];
    if ((_waypointPos select 0) == 0) then {
        _waypointPos = waypointPosition [_group, currentWaypoint _group];
    };
    _group setVariable ["attackingFromPos", _waypointPos];
};