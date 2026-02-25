#include "..\..\elementIds.hpp"

patrolCenter setVariable ["patrolRadius", ceil (parseNumber (ctrlText ADVANCED_CONFIG_DIALOG_PATROLRADIUSVALUE_IDC)), true];
patrolCenter setVariable ["maxInfantryResponseDistance", floor (parseNumber (ctrlText ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCEINFANTRYVALUE_IDC)), true];
patrolCenter setVariable ["maxVehicleResponseDistance", floor (parseNumber (ctrlText ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCEVEHICLESVALUE_IDC)), true];
patrolCenter setVariable ["maxAirResponseDistance", floor (parseNumber (ctrlText ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCEAIRVALUE_IDC)), true];

_scale = patrolCenter getVariable ["scaling", 1];
patrolCenter setVariable ["maxInfantryResponseDistance_original", (patrolCenter getVariable "maxInfantryResponseDistance") / _scale, true];
patrolCenter setVariable ["maxVehicleResponseDistance_original", (patrolCenter getVariable "maxVehicleResponseDistance") / _scale, true];
patrolCenter setVariable ["maxAirResponseDistance_original", (patrolCenter getVariable "maxAirResponseDistance") / _scale, true];


call Rimsiakas_fnc_refreshAdvancedConfigInfo;