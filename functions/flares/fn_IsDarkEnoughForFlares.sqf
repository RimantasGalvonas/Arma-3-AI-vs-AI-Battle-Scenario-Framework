if (sunOrMoon < 1) exitWith {
    true;
};


private _sunRiseSunSetTimes = date call BIS_fnc_sunriseSunsetTime;
private _sunRise = _sunRiseSunSetTimes select 0;
private _sunSet = _sunRiseSunSetTimes select 1;
private _delay = linearConversion [0.4, 0.6, overcast, 0.38, -0.16, true]; // Start shooting flares ~23 min after sunset when clear, ~10 min before sunset when overcast.

if (patrolCenter getVariable ["flaresLevel", 0] > 2) then { // On some maps this might seem like a very early start, but it can get dark really very fast on others, such as The Bra
    _delay = linearConversion [0.4, 0.6, overcast, 0.135, -0.135, true]; // Start shooting flares ~8 min after sunset when clear, ~8 min before sunset when overcast.
};

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