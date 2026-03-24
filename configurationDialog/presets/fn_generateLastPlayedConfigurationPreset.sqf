if (isNil "Rimsiakas_workingFactionsData") exitWith {};

private _presets = missionProfileNamespace getVariable ["Rimsiakas_configurationPresets", createHashMap];

private _lastPlayedPreset = createHashMap;
_lastPlayedPreset set ["readonly", true];
_lastPlayedPreset set ["order", 5];
_lastPlayedPreset set ["factionsData", Rimsiakas_workingFactionsData];
_lastPlayedPreset set ["patrolCenterData", [] call Rimsiakas_fnc_collectPatrolCenterDataForPreset];
_lastPlayedPreset set ["envData", [] call Rimsiakas_fnc_collectEnvDataForPreset];

_presets set ["Last played", _lastPlayedPreset];

missionProfileNamespace setVariable ["Rimsiakas_configurationPresets", _presets];
saveMissionProfileNamespace;