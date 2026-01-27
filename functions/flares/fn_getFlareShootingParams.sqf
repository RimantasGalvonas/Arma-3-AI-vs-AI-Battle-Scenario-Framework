params ["_pos"];

// if (!isNil "flareShootingParams") exitWith { // This is here to override things with a public variable in the console for testing
//     flareShootingParams;
// };

// TODO: might need to check if values don't need to be adjusted according to the weather.

// Default values, adjusted for Livonia/Normandy/Mortain/Gabreta in open areas
private _flareShootingParams = createHashMap;
_flareShootingParams set ["flareDistanceAhead", 150];
_flareShootingParams set ["flareProximityLimit", 195];
_flareShootingParams set ["flareHeight", 200];
_flareShootingParams set ["flareStaleTime", 38];
_flareShootingParams set ["flareShootDelay", random [30, 35, 40]];

private _worldName = toLower worldName;

if (!([_pos, false] call Rimsiakas_fnc_isPositionInForest)) then {
    if (_worldName in ["altis", "malden", "gm_weferlingen_summer", "sefrouramal"]) then { // Light spreads much further for some reason
        _flareShootingParams set ["flareDistanceAhead", 200];
        _flareShootingParams set ["flareProximityLimit", 300];
        _flareShootingParams set ["flareHeight", 250];
    };

    if (_worldName == "tanoa") then {
        _flareShootingParams set ["flareProximityLimit", 250];
        _flareShootingParams set ["flareHeight", 250];
    };
} else {
    // Default values, adjusted for Tanoa/Livonia/Normandy/Mortain/Gabreta
    _flareShootingParams set ["flareDistanceAhead", 50];
    _flareShootingParams set ["flareProximityLimit", 200];
    _flareShootingParams set ["flareHeight", linearConversion [0.4, 0.6, overcast, 215, 205, true]];
    _flareShootingParams set ["flareStaleTime", linearConversion [0.4, 0.6, overcast, 35, 25, true]];
    _flareShootingParams set ["flareShootDelay", random [20, 25, 30]];

    if (worldName in ["altis", "malden", "gm_weferlingen_summer"]) then {
        _flareShootingParams set ["flareHeight", 250];
        _flareShootingParams set ["flareStaleTime", 38];
    };
};

if (_worldName in ["cam_lao_nam", "vn_the_bra"]) then { // Light spreads much less for some reason, same in open areas as in forests.
    _flareShootingParams set ["flareDistanceAhead", 50];
    _flareShootingParams set ["flareProximityLimit", 150];
    _flareShootingParams set ["flareStaleTime", linearConversion [0.4, 0.6, overcast, 30, 20, true]];
    _flareShootingParams set ["flareShootDelay", random [20, 25, 30]];
};

if (_worldName == "vn_khe_sanh") then { // Light spreads much further for some reason and forests absorb no light. Same settings as for Altis/Malden/Weferlingen in the open.
    _flareShootingParams set ["flareDistanceAhead", 200];
    _flareShootingParams set ["flareProximityLimit", 300];
    _flareShootingParams set ["flareHeight", 250];
    _flareShootingParams set ["flareStaleTime", 38];
    _flareShootingParams set ["flareShootDelay", random [30, 35, 40]];

};

_flareShootingParams;