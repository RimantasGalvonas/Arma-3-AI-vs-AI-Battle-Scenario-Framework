if (isPlayer (leader group player)) then {
    hint "You can only take over the group if the leader is not a player.";
} else {
    (player call BIS_fnc_netId) remoteExecCall ["Rimsiakas_fnc_serverHandleGroupTakeOverRequest"];
};