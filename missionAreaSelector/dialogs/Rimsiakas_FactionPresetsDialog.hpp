#define MARGIN (0.5)
#define WIDTH (18.5)

class Rimsiakas_FactionPresetsDialog
{
    idd = 46426;
    movingEnabled = false;
    enableSimulation = true;
    onLoad = "call Rimsiakas_fnc_openFactionPresets";

    controlsBackground[]=
    {
        Rimsiakas_FactionPresetsDialog_Background
    };

    controls[]=
    {
        Rimsiakas_FactionPresetsDialog_MainControlGroup
    };

    class Rimsiakas_FactionPresetsDialog_BottomButton: Rimsiakas_Button
    {
        y = 16.5 * GUI_GRID_H + GUI_GRID_Y;
    }

    class Rimsiakas_FactionPresetsDialog_Background: RscText
    {
        idc = 500000;
        x = 9.5 * GUI_GRID_W + GUI_GRID_X;
        y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
        w = WIDTH * GUI_GRID_W;
        h = WIDTH * GUI_GRID_H;
        colorBackground[] = {0.15,0.15,0.15,0.9};
    };

    class Rimsiakas_FactionPresetsDialog_MainControlGroup: RscControlsGroup
    {
        idc = 500001;
        x = 9.5 * GUI_GRID_W + GUI_GRID_X;
        y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
        w = WIDTH * GUI_GRID_W;
        h = WIDTH * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionPresetsDialog_PresetList: RscListBox
            {
                idc = 500002;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = MARGIN * GUI_GRID_H + GUI_GRID_Y;
                w = (WIDTH - MARGIN * 2) * GUI_GRID_W;
                h = 13.5 * GUI_GRID_H;
                onLBSelChanged = "[] call Rimsiakas_fnc_factionPresetSelected;";
            };

            class Rimsiakas_FactionPresetsDialog_PresetName: RscEdit
            {
                idc = 500003;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 14.5 * GUI_GRID_H + GUI_GRID_Y;
                w = (WIDTH - MARGIN * 3 - 5.5) * GUI_GRID_W;
                h = 1.5 * GUI_GRID_H;
            };

            class Rimsiakas_FactionPresetsDialog_SaveButton: Rimsiakas_FactionPresetsDialog_BottomButton
            {
                idc = 500004;
                action = "[] call Rimsiakas_fnc_saveFactionPreset;";
                text = "Save";
                x = 12.5 * GUI_GRID_W + GUI_GRID_X;
                y = 14.5 * GUI_GRID_H + GUI_GRID_Y;
            }

            class Rimsiakas_FactionPresetsDialog_LoadButton: Rimsiakas_FactionPresetsDialog_BottomButton
            {
                idc = 509000;
                action = "[] call Rimsiakas_fnc_loadFactionPreset; closeDialog 1;"; // TODO: Load the damn thing first
                text = "Load";
                x = 0.5 * GUI_GRID_W + GUI_GRID_X;
            };

            class Rimsiakas_FactionPresetsDialog_CancelButton: Rimsiakas_FactionPresetsDialog_BottomButton
            {
                idc = 509001;
                action = "closeDialog 2;";
                text = "Close";
                x = 6.5 * GUI_GRID_W + GUI_GRID_X;
            };

            class Rimsiakas_FactionPresetsDialog_DeleteButton: Rimsiakas_FactionPresetsDialog_BottomButton
            {
                idc = 509002;
                action = "[] call Rimsiakas_fnc_deleteFactionPreset;";
                text = "Delete";
                x = 12.5 * GUI_GRID_W + GUI_GRID_X;
            };
        };
    };
}