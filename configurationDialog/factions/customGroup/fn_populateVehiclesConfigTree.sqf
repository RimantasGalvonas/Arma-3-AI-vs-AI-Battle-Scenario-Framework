#include "..\..\elementIds.hpp"

private _vehicleConfigTree = displayCtrl CUSTOM_GROUP_VEHICLECONFIGTREE_IDC;

if (_vehicleConfigTree tvCount [0] > 0) exitWith {};


private _vehicleClasses = "
    getNumber (_x >> ""scope"") == 2 &&
    {getText (_x >> ""faction"") != ""Default"" &&
    {getNumber (_x >> ""side"") < 3 &&
    {!(getText (_x >> ""vehicleClass"") in [""Objects"", ""Sounds"", ""mines""])}}}
" configClasses (configFile >> "cfgVehicles");

private _groupedConfigs = [createHashMap, createHashMap, createHashMap];

{
    private _side = _groupedConfigs select (getNumber (_x >> "side"));
    private _faction = _side getOrDefault [getText (_x >> "faction"), createHashMap, true];
    private _category = _faction getOrDefault [getText (_x >> "editorSubcategory"), [], true];
    _category append [configName _x];
} forEach _vehicleClasses;


{
    private _sideIndex = _forEachIndex;
    private _faction = _x;

    _vehicleConfigTree tvAdd [[], [_sideIndex] call BIS_fnc_sideName];

    {
        private _factionIndex = _forEachIndex;
        private _factionId = _x;
        private _category = _y;

        _vehicleConfigTree tvAdd [[_sideIndex], getText (configfile >> "CfgFactionClasses" >> _factionId >> "displayName")];

        {
            private _categoryIndex = _forEachIndex;
            private _categoryId = _x;
            private _vehicles = _y;

            _vehicleConfigTree tvAdd [[_sideIndex, _factionIndex], getText (configfile >> "CfgEditorSubcategories" >> _categoryId >> "displayName")];

            {
                private _vehicleId = _x;
                private _vehicleName = format [ // Lots of whitespace to hide the class name, but keep it searchable
                    "%1                                                                                             %2",
                    getText (configfile >> "cfgVehicles" >> _vehicleId >> "displayName"),
                    _vehicleId
                ];

                private _vehicleIndex = _vehicleConfigTree tvAdd [[_sideIndex, _factionIndex, _categoryIndex], _vehicleName];
                _vehicleConfigTree tvSetData [[_sideIndex, _factionIndex, _categoryIndex, _vehicleIndex], _x];
                _vehicleConfigTree tvSetTooltip [[_sideIndex, _factionIndex, _categoryIndex, _vehicleIndex], _x];
            } forEach _vehicles;
        } forEach _category;
    } forEach _faction;
} forEach _groupedConfigs;

_vehicleConfigTree tvSortAll [[], false];