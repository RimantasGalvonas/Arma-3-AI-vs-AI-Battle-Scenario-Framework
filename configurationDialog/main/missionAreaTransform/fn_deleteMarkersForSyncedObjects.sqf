if (isNil "Rimsiakas_syncedObjectsMarkers") exitWith {};

{
    deleteMarkerLocal _x;
} forEach Rimsiakas_syncedObjectsMarkers;