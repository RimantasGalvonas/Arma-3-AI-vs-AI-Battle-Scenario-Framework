if (isNil "Rimsiakas_workingSpawnersData") exitWith {};

private _presets = missionProfileNamespace getVariable ["Rimsiakas_factionPresets", createHashMap];

private _defaultPreset = createHashMap;
_defaultPreset set ["readonly", true];
_defaultPreset set ["order", 5];
_defaultPreset set ["preset", Rimsiakas_workingSpawnersData];

_presets set ["Last played", _defaultPreset];

missionProfileNamespace setVariable ["Rimsiakas_factionPresets", _presets];
saveMissionProfileNamespace;