#include "..\..\elementIds.hpp"

private _patrolFormation = lbData [AI_CONFIG_PATROLFORMATION_IDC, lbCurSel AI_CONFIG_PATROLFORMATION_IDC];
patrolCenter setVariable ["aiConfigPatrolFormation", _patrolFormation, true];

private _attackFormation = lbData [AI_CONFIG_ATTACKFORMATION_IDC, lbCurSel AI_CONFIG_ATTACKFORMATION_IDC];
patrolCenter setVariable ["aiConfigAttackFormation", _attackFormation, true];

private _speedMode = lbData [AI_CONFIG_MOVEMENTSPEEDMODE_IDC, lbCurSel AI_CONFIG_MOVEMENTSPEEDMODE_IDC];
patrolCenter setVariable ["aiConfigSpeedMode", _speedMode, true];

private _attackSpeedOverride = cbChecked (displayCtrl AI_CONFIG_ATTACKSPEEDOVERRIDE_IDC);
patrolCenter setVariable ["aiConfigAttackSpeedOverride", _attackSpeedOverride, true];

private _allowJoinGroup = cbChecked (displayCtrl AI_CONFIG_ALLOWGROUPJOINING_IDC);
patrolCenter setVariable ["aiConfigAllowLastManToJoinNewGroup", _allowJoinGroup, true];

private _forceFormation = cbChecked (displayCtrl AI_CONFIG_FORCEKEEPFORMATION_IDC);
patrolCenter setVariable ["aiConfigForceFormation", _forceFormation, true];

closeDialog 1;