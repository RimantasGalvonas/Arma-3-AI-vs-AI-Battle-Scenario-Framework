params ["_pos"];

[_pos] call Rimsiakas_fnc_moveMissionArea;

[] call Rimsiakas_fnc_updateMissionAreaSelectionMarkerFromServer;