titleCut ["", "BLACK IN", 1];
_actionId = player addAction ["Select mission area", {call Rimsiakas_fnc_openMissionConfigurationDialog}, nil, 10, false, true, "", "_target == _this"];
call Rimsiakas_fnc_openMissionConfigurationDialog;
waitUntil {!isNil "Rimsiakas_missionConfigured"};
player removeAction _actionId;
titleCut ["Initializing...", "BLACK FADED", 999, false];

publicVariable "Rimsiakas_missionConfigured";