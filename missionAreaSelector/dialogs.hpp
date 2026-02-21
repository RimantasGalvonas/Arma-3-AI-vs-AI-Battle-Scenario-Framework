import RscButton;
import RscMapControl;
import RscText;
import RscEdit;
import RscSlider;
import RscCombo;
import RscCheckBox;
import RscFrame;
import RscControlsGroup;
import RscListBox;
import RscTreeSearch;


#include "\a3\ui_f\hpp\definecommoncolors.inc"
#include "\a3\ui_f\hpp\defineresincl.inc"
#include "commonElements.hpp"
#include "dialogs\Rimsiakas_AdvancedConfigDialog.hpp"
#include "dialogs\Rimsiakas_AiConfigurationDialog.hpp"
#include "dialogs\Rimsiakas_MissionAreaPreviewDialog.hpp"
#include "dialogs\Rimsiakas_MissionAreaSelectorDialog.hpp"
#include "dialogs\Rimsiakas_FactionConfigDialog.hpp"

// Control id rules:
// Mission area map has a reserved 9999 id
// Everything in the MissionAreaSelectorDialog is 10YYXX where YY is a section
// Everything in the AdvancedConfigDialog is 20YYXX where YY is a section
// Everything in the AiConfigurationDialog is 30XXXX