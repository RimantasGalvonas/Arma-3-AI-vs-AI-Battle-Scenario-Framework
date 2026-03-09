#include "..\..\elementIds.hpp"

waitUntil {!isNull findDisplay INVENTORY_ADJUSTMENT_ITEMS_IDD};

private _allowedItemsTree = displayCtrl INVENTORY_ADJUSTMENT_ITEMS_ALLOWEDITEMSTREE_IDC;
private _availableItemsTree = displayCtrl INVENTORY_ADJUSTMENT_ITEMS_AVAILABLEITEMSTREE_IDC;

[_allowedItemsTree] call Rimsiakas_fnc_populateInventoryAdjustmentItemsTree;
[_availableItemsTree] call Rimsiakas_fnc_populateInventoryAdjustmentItemsTree;

tvExpandAll _allowedItemsTree;