patrolCenter setVariable ["patrolRadius", ceil (parseNumber (ctrlText 201002)), true];
patrolCenter setVariable ["maxInfantryResponseDistance", floor (parseNumber (ctrlText 202003)), true];
patrolCenter setVariable ["maxVehicleResponseDistance", floor (parseNumber (ctrlText 202005)), true];
patrolCenter setVariable ["maxAirResponseDistance", floor (parseNumber (ctrlText 202007)), true];

_scale = patrolCenter getVariable ["scaling", 1];
patrolCenter setVariable ["maxInfantryResponseDistance_original", (patrolCenter getVariable "maxInfantryResponseDistance") / _scale, true];
patrolCenter setVariable ["maxVehicleResponseDistance_original", (patrolCenter getVariable "maxVehicleResponseDistance") / _scale, true];
patrolCenter setVariable ["maxAirResponseDistance_original", (patrolCenter getVariable "maxAirResponseDistance") / _scale, true];


call Rimsiakas_fnc_refreshAdvancedConfigInfo;