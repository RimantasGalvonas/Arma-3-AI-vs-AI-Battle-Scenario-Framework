#include "..\..\elementIds.hpp"

[] spawn {
    waitUntil {!isNull findDisplay MAIN_CONFIG_DIALOG_IDD};

    private _resolution = patrolCenter getVariable ["intelGridResolution", 1];
    _resolution = floor _resolution;

    if (_resolution <= 1) exitWith {
        ctrlSetText [MAIN_CONFIG_DIALOG_INTEL_GRID_VALUE_IDC, "Disabled"];
    };

    ctrlSetText [MAIN_CONFIG_DIALOG_INTEL_GRID_VALUE_IDC, (str _resolution) + " x " + (str _resolution)];
};

