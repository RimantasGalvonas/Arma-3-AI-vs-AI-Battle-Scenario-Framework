params ["_group", "_startingPos", "_destination", "_enemyPos", ["_checkStartingPos", true]];

private _waypointStepDistance = 100;

private _distance = _startingPos distance2D _destination;

if (_distance > 2000) then {
    _waypointStepDistance = _distance / 10;
};

private _lastPos = _startingPos;

_intermediatePositions = [];

while {_distance > (_waypointStepDistance * 1.5)} do {
    private _preferablePosition = nil;
    private _intermediatePosition = nil;
    private _dir = _lastPos getDir _destination;
    private _waypointCondition = "true";
    private _startingPosCheck = false;
    private _waitAtThisPos = false;


    if (_checkStartingPos && {_lastPos isEqualTo _startingPos}) then {
        // Create the first waypoint at the current position so after receiving intel it checks if the current position is good to attack the target from.
        _intermediatePosition = _startingPos getPos [3, _dir];
        _startingPosCheck = true;
    } else {
        _intermediatePosition = _lastPos getPos [_waypointStepDistance, _dir];
    };


    private _maxEngagementDistance = (([_enemyPos] call Rimsiakas_fnc_getMinMaxFlankingDistance) select 1) min (([_intermediatePosition] call Rimsiakas_fnc_getMinMaxFlankingDistance) select 1);

    private _withinEngangementDistance = (_intermediatePosition distance _enemyPos) < _maxEngagementDistance;

    // If within engagement distance, try to find a position from which the target is visible, preferably with cover
    if (_withinEngangementDistance) then {
        private "_vantagePointData";

        if (!_startingPosCheck) then {
            _vantagePointData = [_intermediatePosition, _destination, _waypointStepDistance / 1.5] call Rimsiakas_fnc_findOverwatchWithCover;
        } else {
            _vantagePointData = [_intermediatePosition, _destination, 30] call Rimsiakas_fnc_findOverwatchWithCover;
        };


        if (!isNil "_vantagePointData") then {
            _preferablePosition = _vantagePointData get "pos";

            if ((count (_vantagePointData get "nearbyCoveredPositions")) > ((count units _group) * 0.75)) then {
                _waitAtThisPos = true;

                // This position has good cover so stay there until the target is dealt with or can't be seen anymore
                // Do the check every 15 seconds to give time for the group to notice the enemy upon arriving to the waypoint
                _waypointCondition = "
                    private _group = group this;
                    [_group] call Rimsiakas_fnc_temporaryCombatMode;
                    ([_group, 15] call Rimsiakas_fnc_waypointPreConditionTimeout) && {!([_group] call Rimsiakas_fnc_hasGroupSeenItsTargetRecently)};
                ";
            };
        };
    };



    if (_startingPosCheck && {!_waitAtThisPos}) then {
        _lastPos = _intermediatePosition;

        continue;
    };



    if (isNil "_preferablePosition") then {
        _preferablePosition = selectBestPlaces[_intermediatePosition, (_waypointStepDistance / 2), "houses + trees + hills + (waterDepth interpolate [1.1, 1.5, 0, -500])", 5, 1];
        _preferablePosition = (_preferablePosition select 0) select 0;
    };



    // Skip creating the waypoint at this step if the most suitable position was in deep water
    private _preferablePositionIsDeepWater = (((selectBestPlaces [_preferablePosition, 0.2, "waterDepth", 0.1, 1]) select 0) select 1) > 1.3;

    if (!_preferablePositionIsDeepWater) then {
        private _backupPreferablePosition = _preferablePosition;
        _preferablePosition = _preferablePosition findEmptyPosition [2, (_waypointStepDistance / 3), typeOf (leader _group)]; // To avoid placing waypoints inside houses. Makes the units get stuck
        if ((count _preferablePosition) == 0) then {
            _preferablePosition = _backupPreferablePosition;
        };

        _preferablePosition set [2, 0]; // AGLToASL requires height, one of these cases produces a position without one.

        _waypointStatement = "[group this] call Rimsiakas_fnc_updateAttackingFromPos;";

        private _intermediateWaypoint = _group addWayPoint [AGLToASL _preferablePosition, -1];
        _intermediateWaypoint setWaypointType "MOVE";
        _intermediateWaypoint setWaypointStatements [_waypointCondition, _waypointStatement];

        if (_withinEngangementDistance && {!isPlayer leader _group}) then {
            _intermediateWaypoint setWaypointFormation (patrolCenter getVariable ["aiConfigAttackFormation", "WEDGE"]);
        };
    };

    _distance = _preferablePosition distance2D _destination;

    _lastPos = _preferablePosition;
};