#include "..\..\elementIds.hpp"

params ["_selectedPool"];

private _poolGroupsList = displayCtrl FACTIONS_CONFIG_DIALOG_SPAWNERPOOLGROUPS_IDC;

lbClear _poolGroupsList;

{
    private _hierarchy = (configHierarchy (_x) apply {getText (_x >> "name")}) - [""];
    private _name = format ["%1 (%2 / %3)", _hierarchy select -1, _hierarchy select 1, _hierarchy select 2];
    private _index = _poolGroupsList lbAdd _name;
    private _tooltip = ((configHierarchy (_x) apply {getText (_x >> "name")}) - [""]) joinString " / ";
    _poolGroupsList lbSetTooltip [_index, _tooltip];
} forEach (_selectedPool getOrDefault ["groups", []]);