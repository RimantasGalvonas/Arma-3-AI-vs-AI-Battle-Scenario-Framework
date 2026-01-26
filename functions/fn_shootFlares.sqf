while {patrolCenter getVariable ["aiConfigShootFlares", false]} do {
    private _shouldShootFlares = sunOrMoon < 1;

    if (!_shouldShootFlares) then {
        private _sunRiseSunSetTimes = date call BIS_fnc_sunriseSunsetTime;
        private _sunRise = _sunRiseSunSetTimes select 0;
        private _sunSet = _sunRiseSunSetTimes select 1;
        private _delay = linearConversion [0.4, 0.6, overcast, 0.42, -0.16, true]; // Start shooting flares ~25 min after sunset when clear, ~10 min before sunset when overcast.

        if (_sunRise == -1) then {
            _shouldShootFlares = true;
        } else {
            if (_sunSet != -1) then {
                if (dayTime < ((_sunRise - _delay + 24) mod 24) || {dayTime > ((_sunSet + _delay) mod 24)}) then {
                    _shouldShootFlares = true;
                };
            };
        };
    };

    if (_shouldShootFlares) then {
        {
            private _group = _x;
            private _elapsedTime = time;
            private _nextFlareRelease = _group getVariable ["nextTimeForFlareRelease", nil];

            if (isNil "_nextFlareRelease") then {
                _nextFlareRelease = _elapsedTime + random [-10, 0, 10];
                _group setVariable ["nextTimeForFlareRelease", _nextFlareRelease];
            };

            if (_nextFlareRelease <= _elapsedTime) then {
                private _leader = leader _group;

                if (count (nearestObjects [getPos _leader, ["F_40mm_White_Illumination"], 350, true]) > 1) then {
                    _group setVariable ["nextTimeForFlareRelease", _elapsedTime + random [4, 8, 12]];

                    continue;
                };

                _group setVariable ["nextTimeForFlareRelease", _elapsedTime + random [30, 45, 60]];

                private  _waypointPosition = waypointPosition [_group, currentWaypoint _group];
                private _dir = 0;

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