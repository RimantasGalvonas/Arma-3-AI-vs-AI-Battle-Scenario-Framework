#include "..\..\elementIds.hpp"

private _groupsConfigTree = displayCtrl FACTIONS_CONFIG_GROUPSCONFIGTREE_IDC;

if (_groupsConfigTree tvCount [0] > 0) exitWith {};

{
    if (configName _x == "Empty") then {
        continue;
    };

    private _side = _x;
    private _sideIndex = _forEachIndex;

    _groupsConfigTree tvAdd [[], getText (_side >> "name")];

    _groupsConfigTree tvExpand [_sideIndex];

    {
        private _faction = _x;
        private _factionIndex = _forEachIndex;

        _groupsConfigTree tvAdd [[_sideIndex], getText (_faction >> "name")];

        {
            private _category = _x;
            private _categoryIndex = _forEachIndex;

            _groupsConfigTree tvAdd [[_sideIndex, _factionIndex], getText (_category >> "name")];

            {
                private _group = _x;
                private _groupIndex = _forEachIndex;

                private _data = [_x] call BIS_fnc_configPath;
                _groupsConfigTree tvAdd [[_sideIndex, _factionIndex, _categoryIndex], getText (_group >> "name")];
                _groupsConfigTree tvSetData [[_sideIndex, _factionIndex, _categoryIndex, _groupIndex], toJSON _data];
            } forEach ("true" configClasses _category);
        } forEach ("true" configClasses _faction);
    } forEach ("true" configClasses _side);
} forEach ("true" configClasses (configFile >> "cfgGroups"));

_groupsConfigTree tvSortAll [[], false];