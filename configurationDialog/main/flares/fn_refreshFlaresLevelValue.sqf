#include "..\..\elementIds.hpp"

[] spawn {
    waitUntil {!isNull findDisplay MAIN_CONFIG_IDD};

    lbSetCurSel [MAIN_CONFIG_FLARE_FIELD_IDC, patrolCenter getVariable ["flaresLevel", 0]];
};