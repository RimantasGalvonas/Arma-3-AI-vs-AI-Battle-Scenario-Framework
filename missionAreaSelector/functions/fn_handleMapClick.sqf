params ["_pos", "_dialog"];

[_pos] call Rimsiakas_fnc_moveMissionArea;

[_dialog] call Rimsiakas_fnc_updateMissionAreaSelectionMarker;