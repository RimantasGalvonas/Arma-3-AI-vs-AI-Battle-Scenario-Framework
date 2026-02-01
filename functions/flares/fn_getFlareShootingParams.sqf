params ["_pos"];

private _densityMode = patrolCenter getVariable ["flaresLevel", 2];
private _flareHeight = [200, 220] call BIS_fnc_randomInt; // Wiki says that the M583A1 flares deploy at 150-210m, but seems like in Arma they always deploy at ~170m when shot straight up. When spawned like this they always light up ~50 meters lower than told. They probably fall before the parachute deploys.
private _flareShootCooldown = 20;
private "_flareDistanceAhead";
private "_flareProximityLimit";
private "_flareStaleTime";


private _inForest = [_pos, false] call Rimsiakas_fnc_isPositionInForest;
if ((toLower worldName) == "vn_khe_sanh") then {
    _inForest = false; // Khe Sanh forests are somehow transparent to light or something
};
if ((toLower worldName) in ["cam_lao_nam", "vn_the_bra"]) then {
    _inForest = true;
};


if (_inForest) then {
    _flareDistanceAhead = [50, 85] call BIS_fnc_randomInt;

    switch (_densityMode) do
    {
        case 1: {
            _flareProximityLimit = 175;
            _flareStaleTime = [38, 42] call BIS_fnc_randomInt;
        };
        case 2: {
            _flareProximityLimit = 150;
            _flareStaleTime = [26, 34] call BIS_fnc_randomNum;
        };
        case 3: {
            _flareProximityLimit = 125;
            _flareStaleTime = 20;
        };
    };
} else {
    _flareStaleTime = [38, 42] call BIS_fnc_randomInt;

    switch (_densityMode) do
    {
        case 1: {
            _flareDistanceAhead = [200, 250] call BIS_fnc_randomInt;
            _flareProximityLimit = 300;
        };
        case 2: {
            _flareDistanceAhead = [150, 200] call BIS_fnc_randomInt;
            _flareProximityLimit = 225;
        };
        case 3: {
            _flareDistanceAhead = [100, 150] call BIS_fnc_randomInt;
            _flareProximityLimit = 150;
        };
    }
};


private _flareShootingParams = createHashMap;
_flareShootingParams set ["flareDistanceAhead", _flareDistanceAhead];
_flareShootingParams set ["flareProximityLimit", _flareProximityLimit];
_flareShootingParams set ["flareHeight", _flareHeight];
_flareShootingParams set ["flareStaleTime", _flareStaleTime];
_flareShootingParams set ["flareShootCooldown", _flareShootCooldown];


if (!isNil "overridenflareShootingParams") then { // This is here to override things with a public variable in the console for testing
    _flareShootingParams merge [overridenflareShootingParams, true];
};

_flareShootingParams;