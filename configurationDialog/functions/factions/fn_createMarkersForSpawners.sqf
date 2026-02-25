if (isNil "Rimsiakas_markersForSpawners") then {
    Rimsiakas_markersForSpawners = [];
};

private _spawners = entities "LOGIC" select {_x getVariable ["logicType", ""] == "spawner"};

{
    _markerName = "spawnerMarker" + (str _x);
    createMarkerLocal [_markerName, getPos _x];
    _markerName setMarkerPosLocal (getPos _x);
    _markerName setMarkerColorLocal "ColorRed";
    _markerName setMarkerAlphaLocal 1;
    _markerName setMarkerTypeLocal "hd_objective";
    _markerName setMarkerSizeLocal [0.5, 0.5];
    Rimsiakas_markersForSpawners append [_markerName];
} forEach _spawners;