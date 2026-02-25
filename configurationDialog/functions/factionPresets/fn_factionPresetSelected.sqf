#include "..\..\elementIds.hpp"

private _presetListControl = displayCtrl FACTION_PRESETS_DIALOG_PRESETLIST_IDC;
private _presetNameControl = displayCtrl FACTION_PRESETS_DIALOG_PRESETNAME_IDC;
private _saveButton = displayCtrl FACTION_PRESETS_DIALOG_SAVEBUTTON_IDC;
private _deleteButton = displayCtrl FACTION_PRESETS_DIALOG_DELETEBUTTON_IDC;

private _presetName = _presetListControl lbText (lbCurSel _presetListControl);

private _presetData = (missionProfileNamespace getVariable ["Rimsiakas_factionPresets", createHashMap]) get _presetName;

if (isNil "_presetData") exitWith {
    _saveButton ctrlEnable true;
    _deleteButton ctrlEnable true;
};

_presetNameControl ctrlSetText _presetName;

_saveButton ctrlEnable !(_presetData get "readonly");
_deleteButton ctrlEnable !(_presetData get "readonly");