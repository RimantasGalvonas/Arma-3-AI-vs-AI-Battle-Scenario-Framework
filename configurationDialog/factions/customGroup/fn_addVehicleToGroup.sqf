#include "..\..\elementIds.hpp"

private _vehicleConfigTree = displayCtrl CUSTOM_GROUP_VEHICLECONFIGTREE_IDC;

private _selectionPaths = tvSelection _vehicleConfigTree;

private _groupUnitsList = displayCtrl CUSTOM_GROUP_GROUPUNITSLIST_IDC;

{
    private _selectionPath = _x;

    if (count _selectionPath != 4) then {
        continue;
    };

    private _vehicleName = _vehicleConfigTree tvText _selectionPath;
    private _vehicleClassName = _vehicleConfigTree tvData _selectionPath;

    private _addedIndex = _groupUnitsList lbAdd _vehicleName;
    _groupUnitsList lbSetData [_addedIndex, _vehicleClassName];
    _groupUnitsList lbSetTooltip [_addedIndex, _vehicleClassName];
} foreach _selectionPaths;