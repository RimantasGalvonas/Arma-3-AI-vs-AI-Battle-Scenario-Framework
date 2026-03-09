#include "..\..\elementIds.hpp"

params ["_control", "_selectionPath"];

private _itemClass = configFile >> "cfgWeapons" >> (_control tvData _selectionPath);

private _pictureCtrl = displayCtrl INVENTORY_ADJUSTMENT_ITEMS_ACTIONS_BUTTONS_SELECTEDITEMPICTURE_IDC;

if (isNull _itemClass) exitWith {
    _pictureCtrl ctrlSetText "";
};

_pictureCtrl ctrlSetText (getText (_itemClass >> "picture"));