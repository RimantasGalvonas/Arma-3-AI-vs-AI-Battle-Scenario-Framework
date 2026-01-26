while {patrolCenter getVariable ["aiConfigShootFlares", false]} do {

    if (call Rimsiakas_fnc_isDarkEnoughForFlares) then {
        {
            private _group = _x;
            private _leader = leader _group;
            private _leaderPos = getPos _leader;
            private _elapsedTime = time;
            private _lastFlareShotTime = _group getVariable ["lastFlareShotTime", nil];
            private _flareShootingParams = [_leaderPos] call Rimsiakas_fnc_getFlareShootingParams;
            private _flareCoords = [0, 0, 0];


            if (isNil "_lastFlareShotTime") then {
                _lastFlareShotTime = _elapsedTime - random [-15, -5, 5];
                _group setVariable ["lastFlareShotTime", _lastFlareShotTime];
            };


            if ((_lastFlareShotTime + (_flareShootingParams get "flareShootDelay")) < _elapsedTime) then {
                continue;
            };



            private _waypointPosition = waypointPosition [_group, currentWaypoint _group];

            if (isPlayer _leader || {_waypointPosition isEqualTo [0,0,0]}) then {
                _flareCoords = _leader getPos [_flareShootingParams get "flareDistanceAhead", getDir _leader];
            } else {
                _flareCoords = _leader getPos [_flareShootingParams get "flareDistanceAhead", _leaderPos getDir _waypointPosition];
            };

            _flareCoords set [2, (_flareCoords select 2) + (_flareShootingParams get "flareHeight")];


            private _nonStaleFlares = (nearestObjects [_flareCoords, ["F_40mm_White_Illumination"], (_flareShootingParams get "flareProximityLimit"), true]) select { _x getVariable ["staleAt", _elapsedTime + 45] > _elapsedTime; };

            if (count (_nonStaleFlares) > 0) then {
                _group setVariable ["lastFlareShotTime", _elapsedTime + random [4, 8, 12]];

                continue;
            };


            _group setVariable ["lastFlareShotTime", _elapsedTime];

            private _flare = "F_40mm_White_Illumination" createVehicle _flareCoords;
            _flare setVelocity [1, 1, 1];
            _flare setVariable ["staleAt", _elapsedTime + (_flareShootingParams get "flareStaleTime")];
        } forEach allGroups;
    };

    sleep 2;
};