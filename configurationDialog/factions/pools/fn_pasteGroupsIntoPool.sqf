private _selectedPoolData = (([] call Rimsiakas_fnc_getSelectedSpawnerAndPool) get "pool") get "data";

private _clipboardGroups = uiNamespace getVariable ["Rimsiakas_poolClipboard", []];

if (count _clipboardGroups == 0) exitWith {
	hint "No groups in clipboard";
};

(_selectedPoolData get "groups") append _clipboardGroups;

[_selectedPoolData] call Rimsiakas_fnc_populatePoolGroupsList;