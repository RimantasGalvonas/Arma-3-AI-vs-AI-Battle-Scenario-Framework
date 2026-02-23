private _presetListControl = displayCtrl 500002;
private _presetNameControl = displayCtrl 500003;
private _saveButton = displayCtrl 500004;
private _deleteButton = displayCtrl 509002;

private _presetName = _presetListControl lbText (lbCurSel _presetListControl);

private _presetData = (missionProfileNamespace getVariable ["Rimsiakas_factionPresets", createHashMap]) get _presetName;

if (isNil "_presetData") exitWith {
    _saveButton ctrlEnable true;
    _deleteButton ctrlEnable true;
};

_presetNameControl ctrlSetText _presetName;

_saveButton ctrlEnable !(_presetData get "readonly");
_deleteButton ctrlEnable !(_presetData get "readonly");