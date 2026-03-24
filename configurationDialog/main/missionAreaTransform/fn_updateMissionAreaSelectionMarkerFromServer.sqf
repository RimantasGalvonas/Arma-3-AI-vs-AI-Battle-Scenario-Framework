// This function has to be executed on the server side because otherwise the client might not have received the new position yet when configuring on dedicated server

private _pos = getPos patrolCenter;
private _radius = patrolCenter getVariable "patrolRadius";
private _rotation = patrolCenter getVariable ["rotation", 0];

private _missionHostId = 2;

if (!isNil "Rimsiakas_loggedInAdmin") then { // Running on dedicated server
    _missionHostId = Rimsiakas_loggedInAdmin;
};

["missionAreaMarker", _pos] remoteExec ["setMarkerPosLocal", _missionHostId];
["missionAreaMarker", [_radius, _radius]] remoteExec ["setMarkerSizeLocal", _missionHostId];
["missionAreaMarker", _rotation] remoteExec ["setMarkerDirLocal", _missionHostId];
remoteExec ["Rimsiakas_fnc_createMarkersForSyncedObjects", _missionHostId];