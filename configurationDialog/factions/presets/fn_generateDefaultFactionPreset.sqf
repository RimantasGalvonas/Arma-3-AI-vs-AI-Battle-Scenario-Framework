private _presets = missionProfileNamespace getVariable ["Rimsiakas_factionPresets", createHashMap];

private _defaultPreset = createHashMap;
_defaultPreset set ["readonly", true];
_defaultPreset set ["order", 0];
_defaultPreset set ["preset", Rimsiakas_initialSpawnersData];

_presets set ["Default", _defaultPreset];

missionProfileNamespace setVariable ["Rimsiakas_factionPresets", _presets];
saveMissionProfileNamespace;