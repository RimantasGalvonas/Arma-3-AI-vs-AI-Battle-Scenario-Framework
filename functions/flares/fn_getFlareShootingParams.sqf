params ["_pos"];

// Default values, adjusted for Livonia/Normandy/Mortain/Gabreta in open areas
_flareDistanceAhead = [150, 250] call BIS_fnc_randomInt;
_flareProximityLimit = 225;
_flareHeight = [225, 275] call BIS_fnc_randomInt;
_flareStaleTime = [38, 42] call BIS_fnc_randomInt;
_flareShootDelay = [30, 40] call BIS_fnc_randomInt;

private _worldName = toLower worldName;

if (!([_pos, false] call Rimsiakas_fnc_isPositionInForest)) then {
    if (_worldName in ["altis", "malden", "gm_weferlingen_summer", "sefrouramal"]) then { // Light spreads much further for some reason
        _flareDistanceAhead = [200, 250] call BIS_fnc_randomInt;
        _flareHeight = [250, 300] call BIS_fnc_randomInt;
        _flareProximityLimit = 300;
    };

    if (_worldName == "tanoa") then {
        _flareProximityLimit = 250;
    };
} else {
    // Default values, adjusted for Tanoa/Livonia/Normandy/Mortain/Gabreta
    _flareDistanceAhead = [50, 85] call BIS_fnc_randomInt;
    _flareProximityLimit = 175;
    _flareHeight = [210, 225] call BIS_fnc_randomInt;
    _flareStaleTime = (linearConversion [0.4, 0.6, overcast, 33, 28, true]) * ([1, 1.1] call BIS_fnc_randomNum);
    _flareShootDelay = [23, 33] call BIS_fnc_randomInt;

    if (worldName in ["altis", "malden", "gm_weferlingen_summer"]) then {
        _flareHeight = 250;
        _flareStaleTime = [38, 42] call BIS_fnc_randomInt;
    };
};

if (_worldName in ["cam_lao_nam", "vn_the_bra"]) then { // Light spreads much less for some reason, same in open areas as in forests.
    _flareDistanceAhead = [40, 60] call BIS_fnc_randomInt;
    _flareProximityLimit = 150;
    _flareHeight = [210, 225] call BIS_fnc_randomInt;
    _flareStaleTime = (linearConversion [0.4, 0.6, overcast, 30, 20, true]) * ([1, 1.1] call BIS_fnc_randomNum);
    _flareShootDelay = [18, 28] call BIS_fnc_randomInt;
};

if (_worldName == "vn_khe_sanh") then { // Light spreads much further for some reason and forests absorb no light. Same settings as for Altis/Malden/Weferlingen in the open.
    _flareDistanceAhead = [200, 250] call BIS_fnc_randomInt;
    _flareProximityLimit = 300;
    _flareHeight = [225, 275] call BIS_fnc_randomInt;
    _flareStaleTime = [38, 42] call BIS_fnc_randomInt;
    _flareShootDelay = [30, 40] call BIS_fnc_randomInt;
};



private _flareShootingParams = createHashMap;
_flareShootingParams set ["flareDistanceAhead", _flareDistanceAhead];
_flareShootingParams set ["flareProximityLimit", _flareProximityLimit];
_flareShootingParams set ["flareHeight", _flareHeight];
_flareShootingParams set ["flareStaleTime", _flareStaleTime];
_flareShootingParams set ["flareShootDelay", _flareShootDelay];


if (!isNil "overridenflareShootingParams") then { // This is here to override things with a public variable in the console for testing
    _flareShootingParams merge [overridenflareShootingParams, true];

/*
    overridenflareShootingParams = createHashMap;
    overridenflareShootingParams set ["flareHeight", 300];
*/
};

_flareShootingParams;