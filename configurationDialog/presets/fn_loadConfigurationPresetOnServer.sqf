params ["_savedPresetData"];

_patrolCenterData = _savedPresetData get "patrolCenterData";
_patrolCenterVariables = _patrolCenterData get "variables";

_envData = _savedPresetData get "envData";

[
    _patrolCenterData get "pos",
    (_patrolCenterVariables getOrDefault ["rotation", 0]) - (patrolCenter getVariable ["rotation", 0])
] call Rimsiakas_fnc_moveMissionArea;

[(_patrolCenterVariables getOrDefault ["scaling", 0]) - (patrolCenter getVariable ["scaling", 0])] call Rimsiakas_fnc_scaleObjectPlacement;

{
    patrolCenter setVariable [_x, _y, true];
} forEach _patrolCenterVariables;

[_envData get "date"] remoteExecCall ["setDate"];
[0, _envData get "overcast"] remoteExecCall ["setOvercast"];
[0, _envData get "fog"] remoteExecCall ["setFog"];
remoteExecCall ["forceWeatherChange"];

[] call Rimsiakas_fnc_updateMissionAreaSelectionMarkerFromServer;

private _missionHostId = 2;

if (!isNil "Rimsiakas_loggedInAdmin") then { // Running on dedicated server
    _missionHostId = Rimsiakas_loggedInAdmin;
};

remoteExecCall ["Rimsiakas_fnc_populateEnvConfigFields", _missionHostId];
remoteExecCall ["Rimsiakas_fnc_refreshIntelGridValue", _missionHostId];
remoteExecCall ["Rimsiakas_fnc_refreshFlaresLevelValue", _missionHostId];
remoteExecCall ["Rimsiakas_fnc_centerMapOnPatrolCenter", _missionHostId];
remoteExecCall ["Rimsiakas_fnc_refreshMissionAreaSizeValue", _missionHostId];