#define MARGIN (0.5)
#define WIDTH (18.5)

class Rimsiakas_ConfigurationPresetsDialog
{
    idd = CONFIGURATION_PRESETS_IDD;
    movingEnabled = false;
    enableSimulation = true;
    onLoad = "call Rimsiakas_fnc_openConfigurationPresets";

    controlsBackground[]=
    {
        Rimsiakas_ConfigurationPresetsDialog_Background
    };

    controls[]=
    {
        Rimsiakas_ConfigurationPresetsDialog_MainControlGroup
    };

    class Rimsiakas_ConfigurationPresetsDialog_BottomButton: Rimsiakas_Button
    {
        y = 16.5 * GUI_GRID_H + GUI_GRID_Y;
    }

    class Rimsiakas_ConfigurationPresetsDialog_Background: RscText
    {
        idc = CONFIGURATION_PRESETS_BACKGROUND_IDC;
        x = 9.5 * GUI_GRID_W + GUI_GRID_X;
        y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
        w = WIDTH * GUI_GRID_W;
        h = WIDTH * GUI_GRID_H;
        colorBackground[] = {0.15,0.15,0.15,0.9};
    };

    class Rimsiakas_ConfigurationPresetsDialog_MainControlGroup: RscControlsGroup
    {
        idc = CONFIGURATION_PRESETS_MAINCONTROLGROUP_IDC;
        x = 9.5 * GUI_GRID_W + GUI_GRID_X;
        y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
        w = WIDTH * GUI_GRID_W;
        h = WIDTH * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_ConfigurationPresetsDialog_PresetList: RscListBox
            {
                idc = CONFIGURATION_PRESETS_PRESETLIST_IDC;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = MARGIN * GUI_GRID_H + GUI_GRID_Y;
                w = (WIDTH - MARGIN * 2) * GUI_GRID_W;
                h = 13.5 * GUI_GRID_H;
                onLBSelChanged = "[] call Rimsiakas_fnc_onPresetListSelectionChange;";
            };

            class Rimsiakas_ConfigurationPresetsDialog_PresetName: RscEdit
            {
                idc = CONFIGURATION_PRESETS_PRESETNAME_IDC;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 14.5 * GUI_GRID_H + GUI_GRID_Y;
                w = (WIDTH - MARGIN * 3 - 5.5) * GUI_GRID_W;
                h = 1.5 * GUI_GRID_H;
            };

            class Rimsiakas_ConfigurationPresetsDialog_SaveButton: Rimsiakas_ConfigurationPresetsDialog_BottomButton
            {
                idc = CONFIGURATION_PRESETS_SAVEBUTTON_IDC;
                action = "[] spawn Rimsiakas_fnc_saveConfigurationPreset;";
                text = "Save";
                x = 12.5 * GUI_GRID_W + GUI_GRID_X;
                y = 14.5 * GUI_GRID_H + GUI_GRID_Y;
            }

            class Rimsiakas_ConfigurationPresetsDialog_LoadButton: Rimsiakas_ConfigurationPresetsDialog_BottomButton
            {
                idc = CONFIGURATION_PRESETS_LOADBUTTON_IDC;
                action = "[] call Rimsiakas_fnc_loadConfigurationPreset; closeDialog 1;";
                text = "Load";
                x = 0.5 * GUI_GRID_W + GUI_GRID_X;
            };

            class Rimsiakas_ConfigurationPresetsDialog_CancelButton: Rimsiakas_ConfigurationPresetsDialog_BottomButton
            {
                idc = CONFIGURATION_PRESETS_CANCELBUTTON_IDC;
                action = "closeDialog 2;";
                text = "Close";
                x = 6.5 * GUI_GRID_W + GUI_GRID_X;
            };

            class Rimsiakas_ConfigurationPresetsDialog_DeleteButton: Rimsiakas_ConfigurationPresetsDialog_BottomButton
            {
                idc = CONFIGURATION_PRESETS_DELETEBUTTON_IDC;
                action = "[] spawn Rimsiakas_fnc_deleteConfigurationPreset;";
                text = "Delete";
                x = 12.5 * GUI_GRID_W + GUI_GRID_X;
            };
        };
    };
}