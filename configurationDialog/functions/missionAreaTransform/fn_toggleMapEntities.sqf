#include "..\..\elementIds.hpp";

if (isNil "Rimsiakas_showMapEntities") then {
    Rimsiakas_showMapEntities = true;
} else {
    Rimsiakas_showMapEntities = !Rimsiakas_showMapEntities;
};

if (Rimsiakas_showMapEntities) then {
    if (isServer) then {
        [] call Rimsiakas_fnc_createMarkersForSyncedObjects;
    } else {
        // This script is running on a client which sends mission location changes to the dedicated server.
        // There's no way to know when the server has received and processed the mission location changes so this needs to be refreshed constantly.
        [] spawn {
            while {Rimsiakas_showMapEntities && {!isNull (findDisplay MAIN_CONFIG_DIALOG_IDD)}} do {
                call Rimsiakas_fnc_createMarkersForSyncedObjects;
                sleep 0.3;
            };
        };
    };
} else {
    [] call Rimsiakas_fnc_deleteMarkersForSyncedObjects;
};