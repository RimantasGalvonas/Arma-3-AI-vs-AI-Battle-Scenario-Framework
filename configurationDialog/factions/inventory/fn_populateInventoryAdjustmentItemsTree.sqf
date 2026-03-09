#include "..\..\elementIds.hpp"
#define SUPPRESSOR_TYPE (101)
#define OPTICS_TYPE (201)
#define NVG_TYPE (616)

params ["_control"];



private _itemConfigs = [];

if (ctrlIDC _control == INVENTORY_ADJUSTMENT_ITEMS_AVAILABLEITEMSTREE_IDC) then {
    _itemConfigs = 'getNumber (_x >> "itemInfo" >> "type") in [SUPPRESSOR_TYPE, OPTICS_TYPE, NVG_TYPE] && {getNumber (_x >> "scope") == 2}' configClasses (configfile >> "CfgWeapons");
} else {
};



_control tvAdd [[], "NVGs"];
_control tvAdd [[], "Optics"];
_control tvAdd [[], "Suppressors"];

{
    private _itemDisplayName = getText (_x >> "displayName");
    private "_categoryIndex";

    switch (getNumber (_x >> "itemInfo" >> "type")) do
    {
        case NVG_TYPE: {
            _categoryIndex = 0;
        };
        case OPTICS_TYPE: {
            _categoryIndex = 1;
        };
        case SUPPRESSOR_TYPE: {
            _categoryIndex = 2;
        };
    };

    private _itemIndex = _control tvAdd [[_categoryIndex], _itemDisplayName];
    _control tvSetData [[_categoryIndex, _itemIndex], configName _x];
    _control tvSetTooltip [[_categoryIndex, _itemIndex], configName _x];
} forEach _itemConfigs;



_control tvSortAll [[], false];