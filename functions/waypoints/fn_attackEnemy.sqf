params ["_group", "_target", ["_targetPriority", 1], ["_additionalWaypointStatements", ""], ["_additionalWaypointCondition", "true"]];



private _previousTargetGroup = _group getVariable ["currentTargetGroup", false];

_group setVariable ["lastReportedTargetPosition", getPos _target];
_group setVariable ["respondingToIntelPriority", _targetPriority];
_group setVariable ["currentTargetGroup", group _target];
_group setVariable ["currentTarget", _target];

[_group, _previousTargetGroup, group _target] call Rimsiakas_fnc_afterTargetChange;



for "_i" from count (waypoints _group) - 1 to 0 step -1 do {
    deleteWaypoint [_group, _i];
};



private _groupHasVehicles = false;

{
    if ((vehicle _x) != _x) exitWith {_groupHasVehicles = true};
} forEach units _group;



if (_groupHasVehicles == true) then {
    private _waypointCondition = _additionalWaypointCondition;

    private _waypointStatements = "
        %1
        private _group = group this;
        private _target = _group getVariable ['currentTarget', nil];
        if (!isNil '_target' && {!alive _target}) then {
            [_group] call Rimsiakas_fnc_searchForEnemies;
        };
    ";
    _waypointStatements = format [_waypointStatements, _additionalWaypointStatements];



    private _finalWaypoint = _group addWayPoint [getPos (vehicle _target), -1];
    _finalWaypoint waypointAttachVehicle (vehicle _target);
    _finalWaypoint setWaypointType "DESTROY";
    _finalWaypoint setWaypointStatements [_waypointCondition, _waypointStatements];
} else {
    private ["_vantagePoint", "_targetPos", "_distance", "_maxFlankingDistance", "_minFlankingDistance", "_vantagePointWPCondition", "_vantagePointWP"];
    _targetPos = getPos _target;

    _distance = (leader _group) distance _targetPos;

    _maxFlankingDistance = 500;
    _minFlankingDistance = 250;

    if ([_targetPos] call Rimsiakas_fnc_isPositionInForest || {[_targetPos] call Rimsiakas_fnc_isPositionAmongBuildings}) then {
        _maxFlankingDistance = 300;
        _minFlankingDistance = 100;
    };

    if (_distance > _minFlankingDistance) then {
        // Collect attack positions already chosen by friendlies - used to prevent groups clumping together in one place
        _friendlyGroups = allGroups select {_x != _group && {[side _group, side _x] call BIS_fnc_sideIsFriendly}};
        _occupiedVantagePoints = [];
        {
            _friendlyAttackPosition = _x getVariable ["attackingFromPos", nil];
            if (isNil "_friendlyAttackPosition") then {
                continue;
            };

            _occupiedVantagePoints append [_friendlyAttackPosition];
        } forEach _friendlyGroups;


        // Find a good place to attack from and advance onto the enemy from that position
        _vantagePointData = [getPos (leader _group), _targetPos, (_maxFlankingDistance min _distance), _minFlankingDistance, nil, true, true, _occupiedVantagePoints] call Rimsiakas_fnc_findOverwatchWithCover;

        if (!isNil "_vantagePointData") then {
            _vantagePoint = _vantagePointData get "pos";
        } else {
            _vantagePoint = getPos (leader _group);
        };

        _group setVariable ["attackingFromPos", _vantagePoint];


        [_group, getPos (leader _group), _vantagePoint, _targetPos] call Rimsiakas_fnc_createIntermediateCombatMoveWaypoints;


        _vantagePointWPCondition = "
            private _group = group this;
            [_group] call Rimsiakas_fnc_temporaryCombatMode;
            ([_group, 15] call Rimsiakas_fnc_waypointPreConditionTimeout) && {!([_group] call Rimsiakas_fnc_hasGroupSeenItsTargetRecently) && {%1}};
        ";
        _vantagePointWPCondition = format [_vantagePointWPCondition, _additionalWaypointCondition];

        _vantagePointWPStatement = "%1 [group this] call Rimsiakas_fnc_updateAttackingFromPos;";
        _vantagePointWPStatement = format [_vantagePointWPStatement, _additionalWaypointStatements];

        _vantagePointWP = _group addWayPoint [_vantagePoint, 1];
        _vantagePointWP setWaypointType "MOVE";
        _vantagePointWP setWaypointStatements [_vantagePointWPCondition, _vantagePointWPStatement];


        [_group, _vantagePoint, _targetPos, _targetPos, false] call Rimsiakas_fnc_createIntermediateCombatMoveWaypoints;
    } else {
        // Enemy is nearby so advance onto their position directly
        _group setVariable ["attackingFromPos", getPos (leader _group)];
        [_group, getPos (leader _group), _targetPos, _targetPos] call Rimsiakas_fnc_createIntermediateCombatMoveWaypoints;
    };



    private _waypointStatements = "%1 [group this] call Rimsiakas_fnc_searchForEnemies;";
    _waypointStatements = format [_waypointStatements, _additionalWaypointStatements];

    private _waypointCondition = "(!([group this] call Rimsiakas_fnc_hasGroupSeenItsTargetRecently) && {%1});";
    _waypointCondition = format [_waypointCondition, _additionalWaypointCondition];



    private _finalWaypoint = _group addWayPoint [getPos _target, 5];
    _finalWaypoint setWaypointType "SAD";
    _finalWaypoint setWaypointStatements [_waypointCondition, _waypointStatements];
    _finalWaypoint setWaypointFormation (patrolCenter getVariable ["aiConfigAttackFormation", "WEDGE"]);
};