params ["_group"];

// For initialy spawned units. Handled in initPlayerServer.sqf
Rimsiakas_highCommandSubordinates append [_group];


// For when units are spawned mid-mission and can be assigned immediately.
if (!isNil "Rimsiakas_missionInitialized" && {Rimsiakas_missionInitialized == true}) then {
    {
        private _playerUnit = _x;

        private _syncedHighCommandModules = (synchronizedObjects _playerUnit) select {typeOf _x == "HighCommand"};

        if (count _syncedHighCommandModules == 0) then {
            continue;
        };

        if (side _group != side _playerUnit) then {
            continue;
        };

        (hcLeader _group) hcRemoveGroup _group; // Unset previous commander (don't know why, but it's recommended)
        _playerUnit hcSetGroup [_group];

        // delete all waypoints
        for "_i" from count (waypoints _group) - 1 to 0 step -1 do {
            deleteWaypoint [_group, _i];
        };

        // Make them stop at their current position
        _group setVariable ["respondingToIntelPriority", 0];
        _waypoint = _group addWaypoint [(getPos leader _group), 0];
        _waypoint setWaypointType "MOVE";

        break;
    } forEach allPlayers;
};