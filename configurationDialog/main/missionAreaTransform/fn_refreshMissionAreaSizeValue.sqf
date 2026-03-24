#include "..\..\elementIds.hpp"

[] spawn {
    waitUntil {!isNull findDisplay MAIN_CONFIG_IDD};

    ctrlSetText [MAIN_CONFIG_PATROLRADIUSVALUE_IDC, str ((patrolCenter getVariable "patrolRadius") * 2)];
};