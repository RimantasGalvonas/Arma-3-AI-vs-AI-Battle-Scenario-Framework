_newDate = [];

_newDate append [parseNumber (ctrlText 102002)];
_newDate append [parseNumber (ctrlText 102004)];
_newDate append [parseNumber (ctrlText 102006)];
_newDate append [parseNumber (ctrlText 102008)];
_newDate append [parseNumber (ctrlText 102010)];

[_newDate] remoteExecCall ["setDate", 2];

[0, parseNumber (ctrlText 102012) / 100] remoteExecCall ["setOvercast", 2];
[0, parseNumber (ctrlText 102014) / 100] remoteExecCall ["setFog", 2];
remoteExecCall ["forceWeatherChange", 2];

[] call Rimsiakas_fnc_updateFlareTooltips;