params ["_netId"];

private _unit = _netId call BIS_fnc_objectFromNetId;

[group _unit, _unit] remoteExec ["selectLeader", groupOwner group _unit];