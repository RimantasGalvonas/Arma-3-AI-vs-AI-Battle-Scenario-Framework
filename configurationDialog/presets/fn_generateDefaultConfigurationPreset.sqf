private _presets = missionProfileNamespace getVariable ["Rimsiakas_configurationPresets", createHashMap];

private _defaultPreset = createHashMap;

_defaultPreset set ["readonly", true];
_defaultPreset set ["order", 0];
_defaultPreset set ["factionsData", Rimsiakas_initialFactionsData];
_defaultPreset set ["patrolCenterData", [] call Rimsiakas_fnc_collectPatrolCenterDataForPreset];
_defaultPreset set ["envData", [] call Rimsiakas_fnc_collectEnvDataForPreset];

_presets set ["Default", _defaultPreset];

missionProfileNamespace setVariable ["Rimsiakas_configurationPresets", _presets];
saveMissionProfileNamespace;

Rimsiakas_defaultPresetGenerated = true;