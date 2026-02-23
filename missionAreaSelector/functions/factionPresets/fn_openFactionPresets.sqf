[] spawn {
    waitUntil {!isNull findDisplay 46426};

    private _presets = missionProfileNamespace getVariable ["Rimsiakas_factionPresets", createHashMap];

    if (count _presets == 0) then {
        private _defaultPreset = createHashMap;
        _defaultPreset set ["readonly", true];
        _defaultPreset set ["order", 0];
        _defaultPreset set ["preset", Rimsiakas_lastSavedSpawnersData];

        _presets set ["Default", _defaultPreset];

        missionProfileNamespace setVariable ["Rimsiakas_factionPresets", _presets];
        saveMissionProfileNamespace;
    };

    private _sortedPresetKeys = [keys _presets, [_presets], {(_input0 get _x) get "order"}, "ASCEND"] call BIS_fnc_sortBy;

    private _presetsList = displayCtrl 500002;

    lbClear _presetsList;

    _presetsList lbAdd "<< New >>";

    {
        _presetsList lbAdd _x;
    } forEach _sortedPresetKeys;
};