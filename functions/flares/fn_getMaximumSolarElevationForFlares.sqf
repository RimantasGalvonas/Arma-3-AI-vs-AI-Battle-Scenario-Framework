if (!isNil "customGetMaximumSolarElevationForFlaresFunction") exitWith {
    [] call customGetMaximumSolarElevationForFlaresFunction; // Option to override this behavior by placing a Game Logic entity with a custom function in the editor.
};

private _solarElevation = 0;

switch (toLower worldName) do
{
    case "altis": { // Tested on DEFAULT 2035-06-24
        _solarElevation = linearConversion [0.4, 0.6, overcast, -5.5, -5, true];
    };
    case "stratis": { // Tested on DEFAULT 2035-07-06
        _solarElevation = linearConversion [0.4, 0.6, overcast, -6.5, -5.5, true];
    };
    case "enoch": { // Tested on DEFAULT 2035-06-24
        _solarElevation = (3.77549 / (1 + exp(-29.7393 * (overcast - 0.468598)))) + -2.92822;
        _solarElevation = _solarElevation max -2.5;
        _solarElevation = _solarElevation min 0.8;
    };
    case "tanoa": { // REDO: USED WRONG DATA POINTS // Tested on DEFAULT 2035-06-06
        _solarElevation = (0.413574 / (1 + exp(-66 * (overcast - 0.484787)))) + -9.93165;
        _solarElevation = _solarElevation max -9.8;
        _solarElevation = _solarElevation min -9.55;
    };
    case "vn_the_bra"; // Tested on DEFAULT 1968-07-22
    case "cam_lao_nam": { // Tested on DEFAULT 1968-07-22
        _solarElevation = (3.16054 / (1 + exp(-24.0977 * (overcast - 0.472265)))) + -3.22578;
        _solarElevation = _solarElevation max -2.8;
        _solarElevation = _solarElevation min -0.2;
    };
    case "vn_khe_sanh": { // Tested on DEFAULT 1968-06-21. It's really weird
        _solarElevation = (5.12618 / (1 + exp(-70 * (overcast - 0.497656)))) + -4.65938;
        _solarElevation = _solarElevation max -4.5;
        _solarElevation = _solarElevation min 0.4;
    };
    default {
        _solarElevation = linearConversion [0.4, 0.6, overcast, -2, 0.8, true];
    };
};

_solarElevation;