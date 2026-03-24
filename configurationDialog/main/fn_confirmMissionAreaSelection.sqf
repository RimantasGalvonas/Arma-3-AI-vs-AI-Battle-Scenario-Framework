#include "..\elementIds.hpp"

closeDialog 1;

deleteMarkerLocal 'missionAreaMarker';

Rimsiakas_showMapEntities = false;
[] call Rimsiakas_fnc_deleteMarkersForSyncedObjects;

Rimsiakas_missionConfigured = true;