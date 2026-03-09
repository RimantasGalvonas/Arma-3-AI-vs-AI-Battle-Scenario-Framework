#include "..\..\elementIds.hpp"

[] spawn {
    waitUntil {!isNull findDisplay FACTION_PRESETS_IDD};

    private _presets = missionProfileNamespace getVariable ["Rimsiakas_factionPresets", createHashMap];

    private _sortedPresetKeys = [keys _presets, [_presets], {(_input0 get _x) get "order"}, "ASCEND"] call BIS_fnc_sortBy;

    private _presetsList = displayCtrl FACTION_PRESETS_PRESETLIST_IDC;

    lbClear _presetsList;

    _presetsList lbAdd "<< New >>";

    {
        _presetsList lbAdd _x;
    } forEach _sortedPresetKeys;
};