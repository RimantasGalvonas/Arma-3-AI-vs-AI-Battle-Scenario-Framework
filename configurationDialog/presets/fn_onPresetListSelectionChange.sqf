#include "..\elementIds.hpp"

private _presetListControl = displayCtrl CONFIGURATION_PRESETS_PRESETLIST_IDC;
private _presetNameControl = displayCtrl CONFIGURATION_PRESETS_PRESETNAME_IDC;
private _saveButton = displayCtrl CONFIGURATION_PRESETS_SAVEBUTTON_IDC;
private _deleteButton = displayCtrl CONFIGURATION_PRESETS_DELETEBUTTON_IDC;

private _presetName = _presetListControl lbText (lbCurSel _presetListControl);

private _presetData = (missionProfileNamespace getVariable ["Rimsiakas_configurationPresets", createHashMap]) get _presetName;

if (isNil "_presetData") exitWith {
    _saveButton ctrlEnable true;
    _deleteButton ctrlEnable true;
};

_presetNameControl ctrlSetText _presetName;

_saveButton ctrlEnable !(_presetData get "readonly");
_deleteButton ctrlEnable !(_presetData get "readonly");