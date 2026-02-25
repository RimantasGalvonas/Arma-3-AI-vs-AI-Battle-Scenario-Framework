#include "..\..\elementIds.hpp"

_newDate = [];

_newDate append [parseNumber (ctrlText MAIN_CONFIG_ENV_YEARFIELD_IDC)];
_newDate append [parseNumber (ctrlText MAIN_CONFIG_ENV_MONTHFIELD_IDC)];
_newDate append [parseNumber (ctrlText MAIN_CONFIG_ENV_DAYFIELD_IDC)];
_newDate append [parseNumber (ctrlText MAIN_CONFIG_ENV_HOURFIELD_IDC)];
_newDate append [parseNumber (ctrlText MAIN_CONFIG_ENV_MINUTEFIELD_IDC)];

[_newDate] remoteExecCall ["setDate", 2];

[0, parseNumber (ctrlText MAIN_CONFIG_ENV_OVERCASTFIELD_IDC) / 100] remoteExecCall ["setOvercast", 2];
[0, parseNumber (ctrlText MAIN_CONFIG_ENV_FOGFIELD_IDC) / 100] remoteExecCall ["setFog", 2];
remoteExecCall ["forceWeatherChange", 2];