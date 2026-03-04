private _poolGroups = ((([] call Rimsiakas_fnc_getSelectedSpawnerAndPool) get "pool") get "data") get "groups";

uiNamespace setVariable ["Rimsiakas_poolClipboard", +_poolGroups];