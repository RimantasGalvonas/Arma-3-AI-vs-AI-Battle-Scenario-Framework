#include "..\..\elementIds.hpp"

params ["_control", "_selectionPath"];

private _addButton = displayCtrl FACTIONS_CONFIG_DIALOG_ADDGROUPBUTTON_IDC;

_addButton ctrlEnable false;

{
    if (count _x == 4) exitWith {
        _addButton ctrlEnable true;
    };
} forEach tvSelection _control;