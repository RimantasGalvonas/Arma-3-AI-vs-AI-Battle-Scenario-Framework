#include "..\..\elementIds.hpp"

[] spawn {
    waitUntil {!isNull findDisplay MAIN_CONFIG_DIALOG_IDD};

    [] call Rimsiakas_fnc_updateMissionAreaSelectionMarker;

    ctrlSetText [MAIN_CONFIG_DIALOG_PATROLRADIUSVALUE_IDC, str ((patrolCenter getVariable "patrolRadius") * 2)];
};