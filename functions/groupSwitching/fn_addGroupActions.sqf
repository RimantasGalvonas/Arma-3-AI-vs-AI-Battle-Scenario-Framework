if (!(patrolCenter getVariable ["groupSwitching", false])) exitWith {};

private _actions = actionIDs player;

if ({(player actionParams _x) select 0 == "Join a nearby group"} count _actions != 0) exitWith {};

player addAction ["Join a nearby group", "call Rimsiakas_fnc_joinNearestGroup", nil, 0, false, true, "", "_target == _this"];
player addAction ["Take over as group leader", "call Rimsiakas_fnc_clientRequestGroupTakeOver", nil, 0, false, true, "", "_target == _this && {!isPlayer (leader group player)}"];