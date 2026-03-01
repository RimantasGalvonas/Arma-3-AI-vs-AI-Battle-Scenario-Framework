#include "..\..\..\elementIds.hpp"

private _control = displayCtrl FACTIONS_CONFIG_SPAWNERPOOLGROUPS_IDC;
private _lbCurSel = lbCurSel _control; // Can't use event params because this function gets also called manually
private _removeGroupButton = displayCtrl FACTIONS_CONFIG_REMOVEGROUPBUTTON_IDC;
private _customGroupButtonControlGroup = displayCtrl FACTIONS_CONFIG_CUSTOMGROUPBUTTONSCONTROLGROUP_IDC;

if ((_control lbData _lbCurSel) == "custom") then {
    _removeGroupButton ctrlShow false;
    _customGroupButtonControlGroup ctrlShow true;
} else {
    _removeGroupButton ctrlShow true;
    _customGroupButtonControlGroup ctrlShow false;
};