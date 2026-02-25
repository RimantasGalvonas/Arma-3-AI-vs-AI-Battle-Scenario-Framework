[] spawn {
    waitUntil {!isNull findDisplay 46421};

    _now = date;

    ctrlSetText [102002, str (_now select 0)];
    ctrlSetText [102004, str (_now select 1)];
    ctrlSetText [102006, str (_now select 2)];
    ctrlSetText [102008, str (_now select 3)];
    ctrlSetText [102010, str (_now select 4)];
    ctrlSetText [102012, str (round (overcast * 100))];
    ctrlSetText [102014, str (round (fog * 100))];
};