#include "..\..\elementIds.hpp"

params ["_selectedPool"];

private _factionConfigDialog = findDisplay FACTIONS_CONFIG_IDD;

private _poolGroupsList = _factionConfigDialog displayCtrl FACTIONS_CONFIG_SPAWNERPOOLGROUPS_IDC;

lbClear _poolGroupsList;

private _invalidEntries = [];

{
    private _group = _x;
    private "_name";
    private "_tooltip";
    private _data = "";

    if (typeName _x == "ARRAY") then {
        private _units = [];
        {
            private _name = getText (configFile >> "cfgVehicles" >> _x >> "displayName");

            if (_name == "") then {
                _invalidEntries append [_x];
            };

            _units append [format ["%1 (%2)", _name, str _x]];
        } forEach _group;

        _name = format ["Custom group (%1)", (_units joinString ", ")];
        _tooltip = _units joinString "\n";
        _data = "custom";
    } else {
        private _hierarchy = (configHierarchy (_group) apply {getText (_x >> "name")}) - [""]; // The - [""] removes some unneeded layers of config that don't have a name
        _name = format ["%1 (%2 / %3)", _hierarchy select -1, _hierarchy select 1, _hierarchy select 2];
        _tooltip = ((configHierarchy (_group) apply {getText (_x >> "name")}) - [""]) joinString " / ";
    };

    private _index = _poolGroupsList lbAdd _name;
    _poolGroupsList lbSetTooltip [_index, _tooltip];
    _poolGroupsList lbSetData [_index, _data];
} forEach (_selectedPool getOrDefault ["groups", []]);

if (count _invalidEntries > 0) then {
    ["Class names %1 from custom groups not found in the config. Fix these class names to avoid breaking the mission.", _invalidEntries joinString ", "] call BIS_fnc_error;
};