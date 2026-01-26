if (sunOrMoon < 1) exitWith {
    true;
};


private _sunRiseSunSetTimes = date call BIS_fnc_sunriseSunsetTime;
private _sunRise = _sunRiseSunSetTimes select 0;
private _sunSet = _sunRiseSunSetTimes select 1;
private _delay = linearConversion [0.4, 0.6, overcast, 0.42, -0.16, true]; // Start shooting flares ~25 min after sunset when clear, ~10 min before sunset when overcast.

if (_sunRise == -1) exitWith {
    true;
};

if (_sunSet == -1) exitWith {
    false;
};

if (dayTime < ((_sunRise - _delay + 24) mod 24) || {dayTime > ((_sunSet + _delay) mod 24)}) exitWith {
    true;
};

false;