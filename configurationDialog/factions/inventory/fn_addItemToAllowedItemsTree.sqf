#include "..\..\elementIds.hpp"

private _availableItemsTree = displayCtrl INVENTORY_ADJUSTMENT_ITEMS_AVAILABLEITEMSTREE_IDC;

private _selectionPaths = tvSelection _availableItemsTree;

private _allowedItemsTree = displayCtrl INVENTORY_ADJUSTMENT_ITEMS_ALLOWEDITEMSTREE_IDC;

{
    private _selectionPath = _x;

    if (count _selectionPath != 2) then {
        continue;
    };

    _categoryIndex = _selectionPath select 0;

    private _itemDisplayName = _availableItemsTree tvText _selectionPath;
    private _itemClassName = _availableItemsTree tvData _selectionPath;

    private _addedIndex = _allowedItemsTree tvAdd [[_categoryIndex], _itemDisplayName];
    _allowedItemsTree tvSetData [[_categoryIndex, _addedIndex], _itemClassName];
    _allowedItemsTree tvSetTooltip [[_categoryIndex, _addedIndex], _itemClassName];
} foreach _selectionPaths;