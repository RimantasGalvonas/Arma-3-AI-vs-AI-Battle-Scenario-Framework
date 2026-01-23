while {patrolCenter getVariable ["aiConfigShootFlares", false]} do {
    if (sunOrMoon < 1) then {
        {
            private _group = _x;
            private _flareReleaseDelay = random [30, 45, 60];
            private _elapsedTime = time;
            private _nextFlareRelease = _group getVariable ["nextTimeForFlareRelease", nil];

            if (isNil "_nextFlareRelease") then {
                _nextFlareRelease = random [-30, 0, 30];
                _group setVariable ["nextTimeForFlareRelease", _elapsedTime + _nextFlareRelease];
            };

            if (_nextFlareRelease <= _elapsedTime) then {
                _group setVariable ["nextTimeForFlareRelease", _elapsedTime + _flareReleaseDelay];

                private  _waypointPosition = waypointPosition [_group, currentWaypoint _group];
                private _dir = 0;
                private _leader = leader _group;

                if (_waypointPosition isEqualTo [0,0,0]) then {
                    _dir = getDir _leader;
                } else {
                    _dir = _leader getDir _waypointPosition;
                };

                _flareCoords = _leader getPos [200, _dir];
                _flareCoords set [2, 300];
                private _flare = "F_40mm_White_Illumination" createVehicle _flareCoords;
                _flare setVelocity [1, 1, 1];
            };
        } forEach allGroups;
    };


    sleep 2;
};