#include "..\elementIds.hpp"

patrolCenter setVariable ['flaresLevel', parseNumber lbData [MAIN_CONFIG_DIALOG_INTEL_FLARE_FIELD_IDC, lbCurSel MAIN_CONFIG_DIALOG_INTEL_FLARE_FIELD_IDC]];
closeDialog 1;
deleteMarkerLocal 'missionAreaMarker';
Rimsiakas_missionConfigured = true;