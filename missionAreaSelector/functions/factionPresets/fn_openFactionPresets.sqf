[] spawn {
    waitUntil {!isNull findDisplay 46426};

    private _presets = missionProfileNamespace getVariable ["Rimsiakas_factionPresets", createHashMap];

    private _sortedPresetKeys = [keys _presets, [_presets], {(_input0 get _x) get "order"}, "ASCEND"] call BIS_fnc_sortBy;

    private _presetsList = displayCtrl 500002;

    lbClear _presetsList;

    _presetsList lbAdd "<< New >>";

    {
        _presetsList lbAdd _x;
    } forEach _sortedPresetKeys;
};