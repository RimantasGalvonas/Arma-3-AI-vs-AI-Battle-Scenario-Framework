#define RIGHT_SIDE_X (31)

class Rimsiakas_MainConfigDialog
{
    idd = MAIN_CONFIG_DIALOG_IDD;
    movingEnabled = false;
    enableSimulation = true;
    onLoad = "call Rimsiakas_fnc_populateEnvConfigFields; call Rimsiakas_fnc_refreshIntelGridValue";

    controlsBackground[]=
    {
        Rimsiakas_MainConfigDialog_MainBackground,
        Rimsiakas_MainConfigDialog_Heading,
        Rimsiakas_MainConfigDialog_IntelGrid_Frame, // Frames are in here rather than in control groups because otherwise the appearance gets messed up somehow
        Rimsiakas_MainConfigDialog_Flare_Frame,
        Rimsiakas_MainConfigDialog_Env_Frame
    };
    controls[]=
    {
        Rimsiakas_MainConfigDialog_Map,
        Rimsiakas_MainConfigDialog_IntelGrid_ControlGroup,
        Rimsiakas_MainConfigDialog_Flare_ControlGroup,
        Rimsiakas_MainConfigDialog_Env_ControlGroup,
        Rimsiakas_MainConfigDialog_Buttons_ControlGroup
    };

    class Rimsiakas_MainConfigDialog_MainBackground: Rimsiakas_MainBackground
    {
         idc = MAIN_CONFIG_DIALOG_BACKGROUND_IDC;
    };

    class Rimsiakas_MainConfigDialog_Heading: Rimsiakas_Heading
    {
        idc = MAIN_CONFIG_DIALOG_HEADING_IDC;
        text = "Click on the map to select the mission area";
    };

    class Rimsiakas_MainConfigDialog_Map: RscMapControl
    {
        idc = MAIN_CONFIG_DIALOG_MAP_IDC;
        x = 0.5 * GUI_GRID_W + GUI_GRID_X;
        y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 30 * GUI_GRID_W;
        h = 20 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_IntelGrid_Frame: RscFrame
    {
        idc = MAIN_CONFIG_DIALOG_INTEL_GRID_FRAME_IDC;
        x = RIGHT_SIDE_X * GUI_GRID_W + GUI_GRID_X;
        y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 3.5 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_IntelGrid_ControlGroup: RscControlsGroup
    {
        idc = MAIN_CONFIG_DIALOG_INTEL_GRID_CONTROLGROUP_IDC;
        x = RIGHT_SIDE_X * GUI_GRID_W + GUI_GRID_X;
        y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 3.5 * GUI_GRID_H;
        
        class Controls
        {
            class Rimsiakas_MainConfigDialog_IntelGrid_Label: RscText
            {
                idc = MAIN_CONFIG_DIALOG_INTEL_GRID_LABEL_IDC;
                text = "Intel Grid:";
                tooltip = "The resolution of colored squares on the map hinting the enemy locations.";
                x = 0.5 * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 7.5 * GUI_GRID_W;
                h = 0.5 * GUI_GRID_H;
            };
        
            class Rimsiakas_MainConfigDialog_IntelGrid_Decrease: Rimsiakas_Button
            {
                idc = MAIN_CONFIG_DIALOG_INTEL_GRID_DECREASE_IDC;
                text = "-";
                action = "['down'] call Rimsiakas_fnc_handleIntelGridButton;";
                x = 1 * GUI_GRID_W + GUI_GRID_X;
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 1 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            }
        
            class Rimsiakas_MainConfigDialog_IntelGrid_Value: RscText
            {
                idc = MAIN_CONFIG_DIALOG_INTEL_GRID_VALUE_IDC;
                text = "";
                tooltip = "The size of colored squares on the map hinting the enemy locations.";
                style = ST_CENTER;
                x = 2 * GUI_GRID_W + GUI_GRID_X;
                y = 1.7 * GUI_GRID_H + GUI_GRID_Y;
                w = 2.7 * GUI_GRID_H + GUI_GRID_Y;
                h = 1 * GUI_GRID_W;
            }
        
            class Rimsiakas_MainConfigDialog_IntelGrid_Increase: Rimsiakas_Button
            {
                idc = MAIN_CONFIG_DIALOG_INTEL_GRID_INCREASE_IDC;
                text = "+";
                action = "['up'] call Rimsiakas_fnc_handleIntelGridButton;";
                x = 6.5 * GUI_GRID_W + GUI_GRID_X;
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 1 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            }        
        };
    };

    class Rimsiakas_MainConfigDialog_Flare_Frame: RscFrame
    {
        idc = MAIN_CONFIG_DIALOG_FLARE_FRAME_IDC;
        x = RIGHT_SIDE_X * GUI_GRID_W + GUI_GRID_X;
        y = 7 * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 3.5 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Flare_ControlGroup: RscControlsGroup
    {
        idc = MAIN_CONFIG_DIALOG_FLARE_CONTROLGROUP_IDC;
        x = RIGHT_SIDE_X * GUI_GRID_W + GUI_GRID_X;
        y = 7 * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 3.5 * GUI_GRID_H;
        
        class Controls
        {
            class Rimsiakas_MainConfigDialog_Flare_Label: RscText
            {
                idc = MAIN_CONFIG_DIALOG_FLARE_LABEL_IDC;
                text = "Flare Illumination:";
                x = 0.5 * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 7.5 * GUI_GRID_W;
                h = 0.5 * GUI_GRID_H;
            };
        
            class Rimsiakas_MainConfigDialog_Flare_Field: RscCombo
            {
                idc = MAIN_CONFIG_DIALOG_FLARE_FIELD_IDC;
                tooltip = "How strongly to illuminate the battlefield at night.";
                class Items
                {
                    class Disabled
                    {
                        text = "Disabled";
                        data = 0;
                        default = 1;
                    };
                    class Low
                    {
                        text = "Low";
                        data = 1;
                    };
                    class Medium
                    {
                        text = "Medium";
                        data = 2;
                    };
                    class High
                    {
                        text = "High";
                        data = 3;
                    };
        
                };
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                x = 0.5 * GUI_GRID_W + GUI_GRID_X;
                w = 7.5 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };
        };
    };

    class Rimsiakas_MainConfigDialog_Env_Frame: RscFrame
    {
        idc = MAIN_CONFIG_DIALOG_ENV_FRAME_IDC;
        x = RIGHT_SIDE_X * GUI_GRID_W + GUI_GRID_X;
        y = 11.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 11 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Env_ControlGroup: RscControlsGroup
    {
        idc = MAIN_CONFIG_DIALOG_ENV_CONTROLGROUP_IDC;
        x = RIGHT_SIDE_X * GUI_GRID_W + GUI_GRID_X;
        y = 11.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 11 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_MainConfigDialog_Env_DateLabel: RscText
            {
                idc = MAIN_CONFIG_DIALOG_ENV_DATELABEL_IDC;
                text = "Date:";
                x = 0.5 * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 3.5 * GUI_GRID_W;
                h = 0.5 * GUI_GRID_H;
            };
        
            class Rimsiakas_MainConfigDialog_Env_YearField: RscEdit
            {
                idc = MAIN_CONFIG_DIALOG_ENV_YEARFIELD_IDC;
                x = 1 * GUI_GRID_W + GUI_GRID_X;
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 2.3 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
                maxChars = 4;
            };
        
            class Rimsiakas_MainConfigDialog_Env_DateSeparator1: RscText
            {
                idc = MAIN_CONFIG_DIALOG_ENV_DATESEPARATOR1_IDC;
                text = "-";
                x = 3.1 * GUI_GRID_W + GUI_GRID_X;
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 1 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };
        
            class Rimsiakas_MainConfigDialog_Env_MonthField: RscEdit
            {
                idc = MAIN_CONFIG_DIALOG_ENV_MONTHFIELD_IDC;
                x = 3.9 * GUI_GRID_W + GUI_GRID_X;
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 1.5 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
                maxChars = 2;

            };
        
            class Rimsiakas_MainConfigDialog_Env_DateSeparator2: RscText
            {
                idc = MAIN_CONFIG_DIALOG_ENV_DATESEPARATOR2_IDC;
                text = "-";
                x = 5.2 * GUI_GRID_W + GUI_GRID_X;
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 1 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };
        
            class Rimsiakas_MainConfigDialog_Env_DayField: RscEdit
            {
                idc = MAIN_CONFIG_DIALOG_ENV_DAYFIELD_IDC;
                x = 6 * GUI_GRID_W + GUI_GRID_X;
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 1.5 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
                maxChars = 2;
            };
        
            class Rimsiakas_MainConfigDialog_Env_TimeLabel: RscText
            {
                idc = MAIN_CONFIG_DIALOG_ENV_TIMELABEL_IDC;
                text = "Time:";
                x = 0.5 * GUI_GRID_W + GUI_GRID_X;
                y = 3 * GUI_GRID_H + GUI_GRID_Y;
                w = 3.5 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };
        
            class Rimsiakas_MainConfigDialog_Env_HourField: RscEdit
            {
                idc = MAIN_CONFIG_DIALOG_ENV_HOURFIELD_IDC;
                x = 3.9 * GUI_GRID_W + GUI_GRID_X;
                y = 3 * GUI_GRID_H + GUI_GRID_Y;
                w = 1.5 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
                maxChars = 2;
            };
        
            class Rimsiakas_MainConfigDialog_Env_TimeSeparator: RscText
            {
                idc = MAIN_CONFIG_DIALOG_ENV_TIMESEPARATOR_IDC;
                text = ":";
                x = 5.2 * GUI_GRID_W + GUI_GRID_X;
                y = 3 * GUI_GRID_H + GUI_GRID_Y;
                w = 1 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };
        
            class Rimsiakas_MainConfigDialog_Env_MinuteField: RscEdit
            {
                idc = MAIN_CONFIG_DIALOG_ENV_MINUTEFIELD_IDC;
                x = 6 * GUI_GRID_W + GUI_GRID_X;
                y = 3 * GUI_GRID_H + GUI_GRID_Y;
                w = 1.5 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
                maxChars = 2;
            };
        
            class Rimsiakas_MainConfigDialog_Env_OvercastLabel: RscText
            {
                idc = MAIN_CONFIG_DIALOG_ENV_OVERCASTLABEL_IDC;
                text = "Overcast %:";
                x = 0.5 * GUI_GRID_W + GUI_GRID_X;
                y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 5 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };
        
            class Rimsiakas_MainConfigDialog_Env_OvercastField: RscEdit
            {
                idc = MAIN_CONFIG_DIALOG_ENV_OVERCASTFIELD_IDC;
                x = 5.5 * GUI_GRID_W + GUI_GRID_X;
                y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 2 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };
        
            class Rimsiakas_MainConfigDialog_Env_FogLabel: RscText
            {
                idc = MAIN_CONFIG_DIALOG_ENV_FOGLABEL_IDC;
                text = "Fog %:";
                x = 0.5 * GUI_GRID_W + GUI_GRID_X;
                y = 6 * GUI_GRID_H + GUI_GRID_Y;
                w = 4 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };
        
            class Rimsiakas_MainConfigDialog_Env_FogField: RscEdit
            {
                idc = MAIN_CONFIG_DIALOG_ENV_FOGFIELD_IDC;
                x = 5.5 * GUI_GRID_W + GUI_GRID_X;
                y = 6 * GUI_GRID_H + GUI_GRID_Y;
                w = 2 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };
        
            class Rimsiakas_MainConfigDialog_Env_ConfirmButton: Rimsiakas_Button
            {
                idc = MAIN_CONFIG_DIALOG_ENV_CONFIRMBUTTON_IDC;
                text = "Apply";
                action = "call Rimsiakas_fnc_confirmEnvConfig";
                x = 1 * GUI_GRID_W + GUI_GRID_X;
                y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 6.5 * GUI_GRID_W;
            };
        };
    }

    class Rimsiakas_MainConfigDialog_Buttons_ControlGroup: RscControlsGroup
    {
        idc = MAIN_CONFIG_DIALOG_BUTTONS_CONTROLGROUP_IDC;
        x = 0.5 * GUI_GRID_W + GUI_GRID_X;
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
        w = 40 * GUI_GRID_W;
        h = 2 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_MainConfigDialog_ConfirmButton: Rimsiakas_Button
            {
                idc = MAIN_CONFIG_DIALOG_BUTTONS_CONFIRM_IDC;
                action = "call Rimsiakas_fnc_confirmMissionAreaSelection";
                text = "Confirm";
                x = 0 * GUI_GRID_W + GUI_GRID_X;
                y = 0 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_MainConfigDialog_PreviewButton: Rimsiakas_Button
            {
                idc = MAIN_CONFIG_DIALOG_BUTTONS_PREVIEW_IDC;
                action = "[] call Rimsiakas_fnc_previewMissionArea";
                text = "Preview";
                x = 6 * GUI_GRID_W + GUI_GRID_X;
                y = 0 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_MainConfigDialog_AdvancedConfigButton: Rimsiakas_Button
            {
                idc = MAIN_CONFIG_DIALOG_BUTTONS_ADVANCEDCONFIG_IDC;
                action = "[] spawn {call Rimsiakas_fnc_openAdvancedConfig;};";
                text = "Advanced Config";
                x = 12 * GUI_GRID_W + GUI_GRID_X;
                y = 0 * GUI_GRID_H + GUI_GRID_Y;
                w = 7.5 * GUI_GRID_W;
            };

            class Rimsiakas_MainConfigDialog_AiConfigButton: Rimsiakas_Button
            {
                idc = MAIN_CONFIG_DIALOG_BUTTONS_AICONFIG_IDC;
                action = "[] spawn {createDialog 'Rimsiakas_AiConfigurationDialog';};"
                text = "AI Config";
                x = 20 * GUI_GRID_W + GUI_GRID_X;
                y = 0 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_MainConfigDialog_FactionConfigButton: Rimsiakas_Button
            {
                idc = MAIN_CONFIG_DIALOG_BUTTONS_FACTIONCONFIG_IDC;
                action = "[] spawn {createDialog 'Rimsiakas_FactionsConfigDialog';};"
                text = "Faction Config";
                x = 26 * GUI_GRID_W + GUI_GRID_X;
                y = 0 * GUI_GRID_H + GUI_GRID_Y;
                w = 6.5 * GUI_GRID_W;
            };
        };
    };
}