#include "..\..\elementIds.hpp"

params ["_selectedPool"];

private _factionConfigDialog = findDisplay FACTIONS_CONFIG_IDD;

private _poolGroupsList = _factionConfigDialog displayCtrl FACTIONS_CONFIG_SPAWNERPOOLGROUPS_IDC;

lbClear _poolGroupsList;

{
    private _group = _x;
    private "_name";
    private "_tooltip";

    if (typeName _x == "ARRAY") then {
        private _units = [];
        {
            _units append [format ["%1 (%2)", getText (configFile >> "cfgVehicles" >> _x >> "displayName"), str _x]];
        } forEach _group;

        _name = format ["Custom group (%1)", (_units joinString ", ")];
        _tooltip = _units joinString "\n";
    } else {
        private _hierarchy = (configHierarchy (_group) apply {getText (_x >> "name")}) - [""];
        _name = format ["%1 (%2 / %3)", _hierarchy select -1, _hierarchy select 1, _hierarchy select 2];
        _tooltip = ((configHierarchy (_group) apply {getText (_x >> "name")}) - [""]) joinString " / ";
    };

    private _index = _poolGroupsList lbAdd _name;
    _poolGroupsList lbSetTooltip [_index, _tooltip];
} forEach (_selectedPool getOrDefault ["groups", []]);