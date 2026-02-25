private _pos = getPos patrolCenter;
private _radius = patrolCenter getVariable "patrolRadius";
private _rotation = patrolCenter getVariable ["rotation", 0];

if (!isMultiplayer || {hasInterface}) exitWith {
    "missionAreaMarker" setMarkerPosLocal _pos;
    "missionAreaMarker" setMarkerSizeLocal [_radius, _radius];
    "missionAreaMarker" setMarkerDirLocal _rotation;
    call Rimsiakas_fnc_createMarkersForSyncedObjects;
};

if (!isNil "Rimsiakas_loggedInAdmin") then {
    ["missionAreaMarker", _pos] remoteExec ["setMarkerPosLocal", Rimsiakas_loggedInAdmin];
    ["missionAreaMarker", [_radius, _radius]] remoteExec ["setMarkerSizeLocal", Rimsiakas_loggedInAdmin];
    ["missionAreaMarker", _rotation] remoteExec ["setMarkerDirLocal", Rimsiakas_loggedInAdmin];
    remoteExec ["Rimsiakas_fnc_createMarkersForSyncedObjects", Rimsiakas_loggedInAdmin];
};