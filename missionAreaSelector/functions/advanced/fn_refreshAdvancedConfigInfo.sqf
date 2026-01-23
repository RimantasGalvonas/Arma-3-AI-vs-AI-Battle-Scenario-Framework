call Rimsiakas_fnc_createMarkersForSyncedObjects;

[] spawn {
    waitUntil {!isNull findDisplay 46424};

    ctrlSetText [201002, str (patrolCenter getVariable "patrolRadius")];
    ctrlSetText [202003, str (patrolCenter getVariable "maxInfantryResponseDistance")];
    ctrlSetText [202005, str (patrolCenter getVariable "maxVehicleResponseDistance")];
    ctrlSetText [202007, str (patrolCenter getVariable "maxAirResponseDistance")];
};