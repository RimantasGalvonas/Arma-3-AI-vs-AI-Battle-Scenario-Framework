#include "..\..\elementIds.hpp"

params ["_control", "_selectedIndex"];

if ((_control lbData _selectedIndex) == "custom") then {
    uiNamespace setVariable ["Rimsiakas_customGroupEditingMode", true];
    createDialog 'Rimsiakas_CustomGroupDialog';
} else {
    [] call Rimsiakas_fnc_removeSelectedGroupFromPool;
};