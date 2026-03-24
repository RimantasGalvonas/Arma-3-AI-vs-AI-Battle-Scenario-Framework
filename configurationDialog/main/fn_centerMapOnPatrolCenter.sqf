#include "..\elementIds.hpp"

_dialog = findDisplay MAIN_CONFIG_IDD;

_map = _dialog displayCtrl MAIN_CONFIG_MAP_IDC;

_map ctrlMapAnimAdd [0, 0.5, getMarkerPos "missionAreaMarker"]; // using marker pos instead of actual patrol center because it gets updated more reliably when configuring on dedicated server
ctrlMapAnimCommit _map;