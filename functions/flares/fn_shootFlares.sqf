while {patrolCenter getVariable ["flaresLevel", 0] > 0} do {
    if ((getLighting select 1) < 150) then {
        {
            private _group = _x;


            private _groupHasVehicles = false;
            {
                if ((vehicle _x) != _x) exitWith {_groupHasVehicles = true};
            } forEach units _group;

            if (_groupHasVehicles == true) then {
                continue;
            };

            private _elapsedTime = time;
            private _leader = leader _group;
            private _leaderPos = getPos _leader;
            private _flareShootingParams = [_leaderPos] call Rimsiakas_fnc_getFlareShootingParams;
            private _flareCoords = [0, 0, 0];
            private _flareCooldown = _flareShootingParams get "flareShootCooldown";
            private _lastFlareShotTime = _group getVariable ["lastFlareShotTime", -_flareCooldown];



            if ((_lastFlareShotTime + _flareCooldown) > _elapsedTime) then {
                continue;
            };

            if (!([] call Rimsiakas_fnc_isDarkEnoughForFlares)) then {
                _group setVariable ["lastFlareShotTime", _elapsedTime]; // Use the flareShootCooldown to skip this group for a while

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
                continue;
            };


            _group setVariable ["lastFlareShotTime", _elapsedTime];

            // Note: yes, this is supposed to be adjusted here just before launching and not before it checks for proximity, because this adjustment is meant to make sure the flare is where it needs to be mid-burn
            _wind = wind;
            _windSpeed = sqrt (((wind select 0) ^ 2) + ((wind select 1) ^ 2));
            _windAdjustedFlareCoords = [
                (_flareCoords select 0) - ((_wind select 0) * 6.25),
                (_flareCoords select 1) - ((_wind select 1) * 6.25),
                (_flareCoords select 2) - (140 - 140/(1 + 0.002 * (_windSpeed ^ 2)))
            ];

            private _flare = "F_40mm_White_Illumination" createVehicle _windAdjustedFlareCoords;
            _flare setVelocity [1, 1, 1];
            _flare setVariable ["staleAt", _elapsedTime + (_flareShootingParams get "flareStaleTime")];

            playSound3d ["a3\missions_f_beta\data\sounds\showcase_night\flaregun_shoot.wss", _leader];
            playSound3d ["a3\missions_f_beta\data\sounds\showcase_night\flaregun_1.wss", _leader];
        } forEach allGroups;
    };

    sleep 2;
};