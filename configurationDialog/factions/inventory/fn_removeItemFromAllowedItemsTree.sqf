#include "..\..\elementIds.hpp"

private _control = displayCtrl INVENTORY_ADJUSTMENT_ITEMS_ALLOWEDITEMSTREE_IDC;

{
    if (count _x != 2) then {
        continue;
    };

    _control tvDelete _x;
} forEachReversed (tvSelection _control);