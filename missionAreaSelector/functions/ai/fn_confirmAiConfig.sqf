private _patrolFormation = lbData [300002, lbCurSel 300002];
patrolCenter setVariable ["aiConfigPatrolFormation", _patrolFormation, true];

private _attackFormation = lbData [300004, lbCurSel 300004];
patrolCenter setVariable ["aiConfigAttackFormation", _attackFormation, true];

private _speedMode = lbData [300006, lbCurSel 300006];
patrolCenter setVariable ["aiConfigSpeedMode", _speedMode, true];

private _attackSpeedOverride = cbChecked (displayCtrl 300008);
patrolCenter setVariable ["aiConfigAttackSpeedOverride", _attackSpeedOverride, true];

private _allowJoinGroup = cbChecked (displayCtrl 300010);
patrolCenter setVariable ["aiConfigAllowLastManToJoinNewGroup", _allowJoinGroup, true];

private _forceFormation = cbChecked (displayCtrl 300012);
patrolCenter setVariable ["aiConfigForceFormation", _forceFormation, true];

private _shootFlares = cbChecked (displayCtrl 300014);
patrolCenter setVariable ["aiConfigShootFlares", _shootFlares, true];

closeDialog 1;