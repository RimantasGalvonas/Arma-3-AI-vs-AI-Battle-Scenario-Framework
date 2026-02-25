#include "..\..\elementIds.hpp"

call Rimsiakas_fnc_createMarkersForSyncedObjects;

[] spawn {
    waitUntil {!isNull findDisplay ADVANCED_CONFIG_DIALOG_IDD};

    ctrlSetText [ADVANCED_CONFIG_DIALOG_PATROLRADIUSVALUE_IDC, str (patrolCenter getVariable "patrolRadius")];
    ctrlSetText [ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCEINFANTRYVALUE_IDC, str (patrolCenter getVariable "maxInfantryResponseDistance")];
    ctrlSetText [ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCEVEHICLESVALUE_IDC, str (patrolCenter getVariable "maxVehicleResponseDistance")];
    ctrlSetText [ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCEAIRVALUE_IDC, str (patrolCenter getVariable "maxAirResponseDistance")];
};