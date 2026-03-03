#include "..\..\elementIds.hpp"

[] spawn {
    waitUntil {!isNull findDisplay MAIN_CONFIG_IDD};

    [] call Rimsiakas_fnc_updateMissionAreaSelectionMarker;

    ctrlSetText [MAIN_CONFIG_PATROLRADIUSVALUE_IDC, str ((patrolCenter getVariable "patrolRadius") * 2)];
};