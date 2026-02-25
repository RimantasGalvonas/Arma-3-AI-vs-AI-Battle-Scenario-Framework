#define COLUMN_WIDTH (12.666666)
#define MARGIN (0.5)

class Rimsiakas_FactionsConfigDialog
{
    idd = 46423;
    movingEnabled = false;
    enableSimulation = true;
    onLoad = "call Rimsiakas_fnc_openFactionsConfig";

    controlsBackground[]=
    {
        Rimsiakas_FactionsConfigDialog_MainBackground,
        Rimsiakas_FactionsConfigDialog_Heading,
        Rimsiakas_FactionsConfigDialog_GreenforLineFrame,
        Rimsiakas_FactionsConfigDialog_FirstColumnFrame, // Frames are in here rather than in control groups because otherwise the appearance gets messed up somehow
        Rimsiakas_FactionsConfigDialog_SecondColumnFrame,
        Rimsiakas_FactionsConfigDialog_ThirdColumnFrame
    };
    controls[]=
    {
        Rimsiakas_FactionsConfigDialog_GreenforControlGroup,
        Rimsiakas_FactionsConfigDialog_SpawnerPoolsControlGroup,
        Rimsiakas_FactionsConfigDialog_Map,
        Rimsiakas_FactionsConfigDialog_SpawnerDetailsControlGroup,
        Rimsiakas_FactionsConfigDialog_PoolDetailsControlGroup,
        Rimsiakas_FactionsConfigDialog_GroupsConfigControlGroup,
        Rimsiakas_FactionsConfigDialog_ConfirmButton,
        Rimsiakas_FactionsConfigDialog_CancelButton,
        Rimsiakas_FactionsConfigDialog_FactionPresetsButton
    };

    class Rimsiakas_FactionsConfigDialog_TextInput: RscEdit
    {
        sizeEx = 0.03;
        colorBackground[] = {0,0,0,0.3};
        x = (COLUMN_WIDTH - MARGIN - 2) * GUI_GRID_W;
        w = 2 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        onEditChanged = "_this call Rimsiakas_fnc_inputChangedFactionsConfig"
    };

    class Rimsiakas_FactionsConfigDialog_BottomButton: Rimsiakas_Button
    {
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
    }

    class Rimsiakas_FactionsConfigDialog_MainBackground: Rimsiakas_MainBackground
    {
         idc = 400000;
    };

    class Rimsiakas_FactionsConfigDialog_Heading: Rimsiakas_Heading
    {
        idc = 400001;
        text = "Faction config";
    };

    class Rimsiakas_FactionsConfigDialog_GreenforLineFrame: RscFrame
    {
        idc = 400500;

        x = MARGIN * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H;
        w = 39 * GUI_GRID_W;
        h = 1.5 * GUI_GRID_H;
        sizeEx = 0.03;
    }

    class Rimsiakas_FactionsConfigDialog_GreenforControlGroup: RscControlsGroup
    {
        idc = 400501;

        x = MARGIN * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H;
        w = 39 * GUI_GRID_W;
        h = 1.5 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionsConfigDialog_GreenforAlliesLabel: RscText
            {
                idc = 400502;
                text = "GREENFOR allied with:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.25 * GUI_GRID_H + GUI_GRID_Y;
                w = 8.5 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_GreenforAllies: RscXListBox
            {
                idc = 400503;
                sizeEx = 0.035;
                x = MARGIN * 2 * GUI_GRID_W * 8.5 + GUI_GRID_X;
                y = 0.25 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
                style = ST_CENTER + LB_TEXTURES + SL_HORZ;
                class Items
                {
                    class None
                    {
                        text = "None";
                    };
                    class Blufor
                    {
                        text = "BLUFOR";
                    };
                    class Opfor
                    {
                        text = "OPFOR";
                    };
                    class Both
                    {
                        text = "Both";
                    };
                };
                onLBSelChanged = "Rimsiakas_workingSpawnersData set [""independentRelation"", _this select 1];";
            };
        };
    }

    class Rimsiakas_FactionsConfigDialog_FirstColumnFrame: RscFrame
    {
        idc = 401000;
        x = MARGIN * GUI_GRID_W;
        y = 4.5 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 18 * GUI_GRID_H;
        sizeEx = 0.03;
    };

    class Rimsiakas_FactionsConfigDialog_Map: RscMapControl // Can't be put in the controlsGroup according to the docs
    {
        idc = 409999; // Different ID than the other ones because this map is not responsible for moving things around
        x = 1 * GUI_GRID_W + GUI_GRID_X;
        y = 15 * GUI_GRID_H + GUI_GRID_Y;
        w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
        h = 7 * GUI_GRID_H;
    };

    class Rimsiakas_FactionsConfigDialog_SpawnerPoolsControlGroup: RscControlsGroup
    {
        idc = 401001;
        x = MARGIN * GUI_GRID_W + GUI_GRID_X;
        y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 10.5 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionsConfigDialog_SpawnerPoolsTree: RscTreeSearch
            {
                idc = 401002;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                h = 9.5 * GUI_GRID_H;
                onTreeSelChanged = "_this call Rimsiakas_fnc_spawnerSelectedFactionsConfig";
            };
        };
    }

    class Rimsiakas_FactionsConfigDialog_SecondColumnFrame: RscFrame
    {
        idc = 402000;
        x = (MARGIN * 2 + COLUMN_WIDTH) * GUI_GRID_W;
        y = 4.15 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 18.35 * GUI_GRID_H;
        sizeEx = 0.03;
        text = "Properties";
    };

    class Rimsiakas_FactionsConfigDialog_SpawnerDetailsControlGroup: RscControlsGroup
    {
        idc = 402001;
        x = (MARGIN * 2 + COLUMN_WIDTH) * GUI_GRID_W;
        y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 18 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionsConfigDialog_MaxUnitsPerGroupLabel: RscText
            {
                idc = 402002;
                text = "Max units per group:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_MaxUnitsPerGroup: Rimsiakas_FactionsConfigDialog_TextInput
            {
                idc = 402003;
                tooltip = "Groups with the amount of soldiers exceeding this number are trimmed down to the desired size.";
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionsConfigDialog_MaxUnitsLabel: RscText
            {
                idc = 402004;
                text = "Max units:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_MaxUnits: Rimsiakas_FactionsConfigDialog_TextInput
            {
                idc = 402005;
                tooltip = "Spawner will pause when it has this number of alive spawned units.";
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionsConfigDialog_SpawnRateLabel: RscText
            {
                idc = 402006;
                text = "Spawn Rate:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_SpawnRate: Rimsiakas_FactionsConfigDialog_TextInput
            {
                idc = 402007;
                tooltip = "Time delay (seconds) between spawns.";
                y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionsConfig_AddPoolButton: Rimsiakas_ButtonSmall
            {
                idc = 402008;
                text = "Add pool";
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 4 * GUI_GRID_H + GUI_GRID_Y;
                action = "[] call Rimsiakas_fnc_addPoolFactionsConfig;"
            }

            class Rimsiakas_FactionsConfig_ClearPoolsButton: Rimsiakas_ButtonSmall
            {
                idc = 402008;
                text = "Clear all pools";
                x = (MARGIN + 3.5) * GUI_GRID_W + GUI_GRID_X;
                y = 4 * GUI_GRID_H + GUI_GRID_Y;
                w = 4 * GUI_GRID_W;
                action = "[] call Rimsiakas_fnc_clearAllPoolsFactionsConfig;"
            }
        };
    };

    class Rimsiakas_FactionsConfigDialog_PoolDetailsControlGroup: RscControlsGroup
    {
        idc = 403001;
        x = (MARGIN * 2 + COLUMN_WIDTH) * GUI_GRID_W;
        y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 18 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionsConfigDialog_SpawnerPoolWeightLabel: RscText
            {
                idc = 403002;
                text = "Pool selection weight:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_SpawnerPoolWeight: Rimsiakas_FactionsConfigDialog_TextInput
            {
                idc = 403003;
                tooltip = "Relative likelihood of spawning a group from this pool. A higher value means the spawner will pick groups to spawn from this pool more frequently.";
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionsConfigDialog_PoolDetailsLabel: RscText
            {
                idc = 403004;
                sizeEx = 0.035;
                text = "Groups in pool:";
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 11 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_SpawnerPoolGroups: RscListBox
            {
                idc = 403005;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                h = 14 * GUI_GRID_H;
                onLBDblClick = "[] call Rimsiakas_fnc_removeGroupFactionsConfig";
            };

            class Rimsiakas_FactionsConfig_RemoveGroupButton: Rimsiakas_ButtonSmall
            {
                idc = 403006;
                text = "Remove selected";
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 17 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                tooltip = "Can also double-click an entry";
                action = "[] call Rimsiakas_fnc_removeGroupFactionsConfig;"
            }
        };
    };

    class Rimsiakas_FactionsConfigDialog_ThirdColumnFrame: RscFrame
    {
        idc = 404000;
        x = (MARGIN * 3 + COLUMN_WIDTH * 2) * GUI_GRID_W;
        y = 4.5 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 18 * GUI_GRID_H;
    };

    class Rimsiakas_FactionsConfigDialog_GroupsConfigControlGroup: RscControlsGroup
    {
        idc = 404001;
        x = (MARGIN * 3 + COLUMN_WIDTH * 2) * GUI_GRID_W;
        y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 18 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionsConfigDialog_GroupsConfigSearch: RscEdit
            {
                idc = 404002;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - 2 - MARGIN * 1) * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_GroupsConfigSearchIcon: RscPictureKeepAspect
            {
                idc = 404003;
                x = (COLUMN_WIDTH - MARGIN - 1) * GUI_GRID_W;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 1 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
                text = "\A3\ui_f\data\gui\rsccommon\rscbuttonsearch\search_start_ca.paa";
            };

            class Rimsiakas_FactionsConfigDialog_GroupsConfigTree: RscTreeSearch
            {
                idc = 404004;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 2 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                h = 14.5 * GUI_GRID_H;
                multiselectEnabled = 1;
                onTreeSelChanged = "private _addButton = displayCtrl 404005; if (count (_this select 1) != 4) then { _addButton ctrlEnable false; } else { _addButton ctrlEnable true; };"
                onTreeDblClick = "[] call Rimsiakas_fnc_addGroupFactionsConfig;";
                idcSearch = 404002;
            };

            class Rimsiakas_FactionsConfig_RemoveGroupButton: Rimsiakas_ButtonSmall
            {
                idc = 404005;
                text = "Add selected";
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 17 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                action = "[] call Rimsiakas_fnc_addGroupFactionsConfig;";
            }
        };
    };

    class Rimsiakas_FactionsConfigDialog_ConfirmButton: Rimsiakas_FactionsConfigDialog_BottomButton
    {
        idc = 409000;
        action = "[] call Rimsiakas_fnc_confirmFactionsConfig; closeDialog 1;";
        text = "Confirm";
        x = 0.5 * GUI_GRID_W + GUI_GRID_X;
    };

    class Rimsiakas_FactionsConfigDialog_CancelButton: Rimsiakas_FactionsConfigDialog_BottomButton
    {
        idc = 409001;
        action = "Rimsiakas_workingSpawnersData = +Rimsiakas_lastSavedSpawnersData; closeDialog 2;";
        text = "Cancel";
        x = 6.5 * GUI_GRID_W + GUI_GRID_X;
    };

    class Rimsiakas_FactionsConfigDialog_FactionPresetsButton: Rimsiakas_FactionsConfigDialog_BottomButton
    {
        idc = 409002;
        action = "[] spawn {createDialog 'Rimsiakas_FactionPresetsDialog';};"
        text = "Presets";
        x = 12.5 * GUI_GRID_W + GUI_GRID_X;
        w = 5.5 * GUI_GRID_W;
    };
}