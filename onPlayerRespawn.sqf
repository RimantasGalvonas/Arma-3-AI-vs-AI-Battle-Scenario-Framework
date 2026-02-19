#if __has_include("mission\onPlayerRespawn_pre.sqf")
    #include "mission\onPlayerRespawn_pre.sqf"
#endif

#if __has_include("mission\onPlayerRespawn_pre.sqf")
    #include "mission\onPlayerRespawn_pre.sqf"
#else

params ["_newUnit", "_oldUnit", "_respawn", "_respawnDelay"];



[_newUnit] call Rimsiakas_fnc_revealFriendlyGroupsOnMap;
[] call Rimsiakas_fnc_addGroupActions;


{
    _x synchronizeObjectsAdd [_newUnit]; // For some reason the synchronization breaks after respawn, but only in one way.
} forEach (synchronizedObjects _newUnit select {_x getVariable ["logicType", ""] == "placer"});



if (!(_newUnit getVariable ["CHVD_initialized", false])) then {
    call CHVD_fnc_init;
    _newUnit setVariable ["CHVD_initialized", true];
};

#endif

#if __has_include("mission\onPlayerRespawn_post.sqf")
    #include "mission\onPlayerRespawn_post.sqf"
#endif