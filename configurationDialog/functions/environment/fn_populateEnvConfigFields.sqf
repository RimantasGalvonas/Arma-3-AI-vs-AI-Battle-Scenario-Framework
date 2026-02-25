#include "..\..\elementIds.hpp"

[] spawn {
    waitUntil {!isNull findDisplay MAIN_CONFIG_IDD};

    _now = date;

    ctrlSetText [MAIN_CONFIG_ENV_YEARFIELD_IDC, str (_now select 0)];
    ctrlSetText [MAIN_CONFIG_ENV_MONTHFIELD_IDC, str (_now select 1)];
    ctrlSetText [MAIN_CONFIG_ENV_DAYFIELD_IDC, str (_now select 2)];
    ctrlSetText [MAIN_CONFIG_ENV_HOURFIELD_IDC, str (_now select 3)];
    ctrlSetText [MAIN_CONFIG_ENV_MINUTEFIELD_IDC, str (_now select 4)];
    ctrlSetText [MAIN_CONFIG_ENV_OVERCASTFIELD_IDC, str (round (overcast * 100))];
    ctrlSetText [MAIN_CONFIG_ENV_FOGFIELD_IDC, str (round (fog * 100))];
};