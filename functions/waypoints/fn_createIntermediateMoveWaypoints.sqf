params ["_group", "_destination"];

private _waypointStepDistance = 100;

private _startingPos = getPos (leader _group);

private _distance = _startingPos distance2D _destination;

if (_distance > 2000) then {
    _waypointStepDistance = _distance / 10;
};

private _lastPos = _startingPos;
while {_distance > (_waypointStepDistance * 1.5)} do {
    private _dir = _lastPos getDir _destination;

    // Infantry should prefer moving between high ground, trees and buildings
    private _intermediatePosition = _lastPos getPos [_waypointStepDistance, _dir];
    private _preferablePosition = selectBestPlaces [_intermediatePosition, (_waypointStepDistance / 2), "houses + trees + hills + (waterDepth interpolate [1.1, 1.5, 0, -500])", 5, 1];
    _preferablePosition = (_preferablePosition select 0) select 0;

    // Skip creating the waypoint at this step if the most suitable position was in deep water
    private _preferablePositionIsDeepWater = (((selectBestPlaces [_preferablePosition, 0.2, "waterDepth", 0.1, 1]) select 0) select 1) > 1.3;

    if (!_preferablePositionIsDeepWater) then {
        _preferablePosition = [_preferablePosition, 0, 10, 1, 0, -1, 0, [], [_preferablePosition, _preferablePosition]] call BIS_fnc_findSafePos; // To avoid placing waypoints inside houses. Makes the units get stuck

        private _intermediateWaypoint = _group addWayPoint [_preferablePosition, 5];
        
        _intermediateWaypoint setWaypointType "MOVE";

        if (!isPlayer leader _group) then {
            _intermediateWaypoint setWaypointFormation (patrolCenter getVariable ["aiConfigPatrolFormation", "WEDGE"]);
        };
    };

    _distance = _preferablePosition distance2D _destination;

    _lastPos = _preferablePosition;
};