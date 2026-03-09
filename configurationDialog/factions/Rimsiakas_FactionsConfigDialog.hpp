#define COLUMN_WIDTH (12.666666)
#define MARGIN (0.5)

class Rimsiakas_FactionsConfigDialog
{
    idd = FACTIONS_CONFIG_IDD;
    movingEnabled = false;
    enableSimulation = true;
    onLoad = "call Rimsiakas_fnc_openFactionsConfig";

    controlsBackground[]=
    {
        Rimsiakas_FactionsConfigDialog_MainBackground,
        Rimsiakas_FactionsConfigDialog_Heading,
        Rimsiakas_FactionsConfigDialog_GreenforLineFrame, // Frames are in here rather than in control groups because otherwise the appearance gets messed up somehow
        Rimsiakas_FactionsConfigDialog_FirstColumnFrame,
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
        Rimsiakas_FactionsConfigDialog_Buttons_ControlGroup
    };

    class Rimsiakas_FactionsConfigDialog_TextInput: RscEdit
    {
        sizeEx = 0.03;
        colorBackground[] = {0,0,0,0.3};
        x = (COLUMN_WIDTH - MARGIN - 2) * GUI_GRID_W;
        w = 2 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        onEditChanged = "_this call Rimsiakas_fnc_onFactionsConfigTextInputChange;";
    };

    class Rimsiakas_FactionsConfigDialog_MainBackground: Rimsiakas_MainBackground
    {
         idc = FACTIONS_CONFIG_MAINBACKGROUND_IDC;
    };

    class Rimsiakas_FactionsConfigDialog_Heading: Rimsiakas_Heading
    {
        idc = FACTIONS_CONFIG_HEADING_IDC;
        text = "Faction config";
    };

    class Rimsiakas_FactionsConfigDialog_GreenforLineFrame: RscFrame
    {
        idc = FACTIONS_CONFIG_GREENFORLINEFRAME_IDC;

        x = MARGIN * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H;
        w = 39 * GUI_GRID_W;
        h = 1.5 * GUI_GRID_H;
        sizeEx = 0.03;
    }

    class Rimsiakas_FactionsConfigDialog_GreenforControlGroup: RscControlsGroup
    {
        idc = FACTIONS_CONFIG_GREENFORCONTROLGROUP_IDC;

        x = MARGIN * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H;
        w = 39 * GUI_GRID_W;
        h = 1.5 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionsConfigDialog_GreenforAlliesLabel: RscText
            {
                idc = FACTIONS_CONFIG_GREENFORALLIESLABEL_IDC;
                text = "GREENFOR allied with:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.25 * GUI_GRID_H + GUI_GRID_Y;
                w = 8.5 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_GreenforAllies: RscXListBox
            {
                idc = FACTIONS_CONFIG_GREENFORALLIES_IDC;
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
        idc = FACTIONS_CONFIG_FIRSTCOLUMNFRAME_IDC;
        x = MARGIN * GUI_GRID_W;
        y = 4.5 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 18 * GUI_GRID_H;
        sizeEx = 0.03;
    };

    class Rimsiakas_FactionsConfigDialog_Map: RscMapControl // Can't be put in the controlsGroup according to the docs
    {
        idc = FACTIONS_CONFIG_MAP_IDC; // Different ID than the other ones because this map is not responsible for moving things around
        x = 1 * GUI_GRID_W + GUI_GRID_X;
        y = 15 * GUI_GRID_H + GUI_GRID_Y;
        w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
        h = 7 * GUI_GRID_H;
    };

    class Rimsiakas_FactionsConfigDialog_SpawnerPoolsControlGroup: RscControlsGroup
    {
        idc = FACTIONS_CONFIG_SPAWNERPOOLSCONTROLGROUP_IDC;
        x = MARGIN * GUI_GRID_W + GUI_GRID_X;
        y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 10.5 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionsConfigDialog_SpawnerPoolsTree: RscTreeSearch
            {
                idc = FACTIONS_CONFIG_SPAWNERPOOLSTREE_IDC;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                h = 9.5 * GUI_GRID_H;
                onTreeSelChanged = "_this call Rimsiakas_fnc_onSpawnerPoolsTreeSelectionChange;";
            };
        };
    }

    class Rimsiakas_FactionsConfigDialog_SecondColumnFrame: RscFrame
    {
        idc = FACTIONS_CONFIG_SECONDCOLUMNFRAME_IDC;
        x = (MARGIN * 2 + COLUMN_WIDTH) * GUI_GRID_W;
        y = 4.15 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 18.35 * GUI_GRID_H;
        sizeEx = 0.03;
        text = "Properties";
    };

    class Rimsiakas_FactionsConfigDialog_SpawnerDetailsControlGroup: RscControlsGroup
    {
        idc = FACTIONS_CONFIG_SPAWNERDETAILSCONTROLGROUP_IDC;
        x = (MARGIN * 2 + COLUMN_WIDTH) * GUI_GRID_W;
        y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 18 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionsConfigDialog_MaxUnitsPerGroupLabel: RscText
            {
                idc = FACTIONS_CONFIG_MAXUNITSPERGROUPLABEL_IDC;
                text = "Max units per group:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_MaxUnitsPerGroup: Rimsiakas_FactionsConfigDialog_TextInput
            {
                idc = FACTIONS_CONFIG_MAXUNITSPERGROUP_IDC;
                tooltip = "Groups with the amount of soldiers exceeding this number are trimmed down to the desired size.";
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionsConfigDialog_MaxUnitsLabel: RscText
            {
                idc = FACTIONS_CONFIG_MAXUNITSLABEL_IDC;
                text = "Max units:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_MaxUnits: Rimsiakas_FactionsConfigDialog_TextInput
            {
                idc = FACTIONS_CONFIG_MAXUNITS_IDC;
                tooltip = "Spawner will pause when it has this number of alive spawned units.";
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionsConfigDialog_SpawnRateLabel: RscText
            {
                idc = FACTIONS_CONFIG_SPAWNRATELABEL_IDC;
                text = "Spawn Rate:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_SpawnRate: Rimsiakas_FactionsConfigDialog_TextInput
            {
                idc = FACTIONS_CONFIG_SPAWNRATE_IDC;
                tooltip = "Time delay (seconds) between spawns.";
                y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionsConfigDialog_AddPoolButton: Rimsiakas_ButtonSmall
            {
                idc = FACTIONS_CONFIG_ADDPOOLBUTTON_IDC;
                text = "Add pool";
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 4 * GUI_GRID_H + GUI_GRID_Y;
                action = "[] call Rimsiakas_fnc_addPoolToSpawner;";
            }

            class Rimsiakas_FactionsConfigDialog_ClearPoolsButton: Rimsiakas_ButtonSmall
            {
                idc = FACTIONS_CONFIG_CLEARPOOLSBUTTON_IDC;
                text = "Clear all pools";
                x = (MARGIN + 3.5) * GUI_GRID_W + GUI_GRID_X;
                y = 4 * GUI_GRID_H + GUI_GRID_Y;
                w = 4 * GUI_GRID_W;
                action = "[] spawn Rimsiakas_fnc_clearAllPoolsInSpawner;";
            }

            class Rimsiakas_FactionsConfigDialog_ChanceToAdjustLabel: RscText
            {
                idc = -1; // TODO
                text = "Chance to add/remove (%):";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 5.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 10 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_ChanceToAdjustNVGsLabel: RscText
            {
                idc = -1; // TODO
                text = "NVGs:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_ChanceToAdjustNVGs: Rimsiakas_FactionsConfigDialog_TextInput
            {
                idc = -1; // TODO
                tooltip = "-100 to always remove, 100 to always add, 0 for no adjustment.";
                y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionsConfigDialog_ChanceToAdjustSuppressorsLabel: RscText
            {
                idc = -1; // TODO
                text = "Suppressors:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 7.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_ChanceToAdjustSuppressors: Rimsiakas_FactionsConfigDialog_TextInput
            {
                idc = -1; // TODO
                tooltip = "-100 to always remove, 100 to always add, 0 for no adjustment.";
                y = 7.5 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionsConfigDialog_ChanceToAdjustOpticsLabel: RscText
            {
                idc = -1; // TODO
                text = "Optics:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_ChanceToAdjustOptics: Rimsiakas_FactionsConfigDialog_TextInput
            {
                idc = -1; // TODO
                tooltip = "-100 to always remove, 100 to always add, 0 for no adjustment.";
                y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionsConfigDialog_RemoveGroupButton: Rimsiakas_ButtonSmall
            {
                idc = -1; // TODO
                text = "Adjust allowed items";
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 10 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                action = "createDialog 'Rimsiakas_AllowedInventoryAdjustmentItemsDialog';";
            }
        };
    };

    class Rimsiakas_FactionsConfigDialog_PoolDetailsControlGroup: RscControlsGroup
    {
        idc = FACTIONS_CONFIG_POOLDETAILSCONTROLGROUP_IDC;
        x = (MARGIN * 2 + COLUMN_WIDTH) * GUI_GRID_W;
        y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 18 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionsConfigDialog_SpawnerPoolWeightLabel: RscText
            {
                idc = FACTIONS_CONFIG_SPAWNERPOOLWEIGHTLABEL_IDC;
                text = "Pool selection weight:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_SpawnerPoolWeight: Rimsiakas_FactionsConfigDialog_TextInput
            {
                idc = FACTIONS_CONFIG_SPAWNERPOOLWEIGHT_IDC;
                tooltip = "Relative likelihood of spawning a group from this pool. A higher value means the spawner will pick groups to spawn from this pool more frequently.";
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionsConfigDialog_VehicleCrewGroupingLabel: RscText
            {
                idc = FACTIONS_CONFIG_POOLVEHICLECREWGROUPINGLABEL_IDC;
                sizeEx = 0.035;
                text = "Count vehicle crew as one:";
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8.5 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_VehicleCrewGrouping: RscCheckBox
            {
                idc = FACTIONS_CONFIG_POOLVEHICLECREWGROUPING_IDC;
                x = (COLUMN_WIDTH - MARGIN - 2) * GUI_GRID_W;
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 1 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
                tooltip = "Whether to count the entire vehicle crew as a single unit for the spawner's max units limit.";
                checked = 0;
                onCheckedChanged = "_this call Rimsiakas_fnc_onFactionsConfigCheckboxCheck;";
            };

            class Rimsiakas_FactionsConfigDialog_SpawnerPoolGroups: RscListBox
            {
                idc = FACTIONS_CONFIG_SPAWNERPOOLGROUPS_IDC;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                h = 12 * GUI_GRID_H;
                onLBSelChanged = "_this call Rimsiakas_fnc_onPoolGroupListSelectionChange";
                onLBDblClick = "[] call Rimsiakas_fnc_removeGroupFromPool";
            };

            class Rimsiakas_FactionsConfigDialog_CopyPasteButtonsControlGroup: RscControlsGroup
            {
                idc = FACTIONS_CONFIG_COPYPASTEBUTTONSCONTROLGROUP_IDC;
                x = 0;
                y = 15 * GUI_GRID_H + GUI_GRID_Y;
                w = COLUMN_WIDTH * GUI_GRID_W;
                h = 1 * GUI_GRID_W;

                class Controls
                {
                    class Rimsiakas_FactionsConfigDialog_CopyButton: Rimsiakas_ButtonSmall
                    {
                        idc = FACTIONS_CONFIG_COPYPASTEBUTTONS_COPY_IDC;
                        text = "Copy";
                        x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                        y = 0 * GUI_GRID_H + GUI_GRID_Y;
                        w = (COLUMN_WIDTH / 2 - MARGIN * 1.5) * GUI_GRID_W;
                        action = "[] call Rimsiakas_fnc_copyPoolGroups;";
                    }

                    class Rimsiakas_FactionsConfigDialog_PasteButton: Rimsiakas_ButtonSmall
                    {
                        idc = FACTIONS_CONFIG_COPYPASTEBUTTONS_PASTE_IDC;
                        text = "Paste";
                        x = (COLUMN_WIDTH / 2 + MARGIN * 0.5) * GUI_GRID_W + GUI_GRID_X;
                        y = 0 * GUI_GRID_H + GUI_GRID_Y;
                        w = (COLUMN_WIDTH / 2 - MARGIN * 1.5) * GUI_GRID_W;
                        action = "[] call Rimsiakas_fnc_pasteGroupsIntoPool;";
                    }
                }
            };

            class Rimsiakas_FactionsConfigDialog_RemoveGroupButton: Rimsiakas_ButtonSmall
            {
                idc = FACTIONS_CONFIG_REMOVEGROUPBUTTON_IDC;
                text = "Remove selected";
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 16 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                tooltip = "Can also double-click an entry";
                action = "[] call Rimsiakas_fnc_removeGroupFromPool;";
            }

            class Rimsiakas_FactionsConfigDialog_CustomGroupButtonsControlGroup: RscControlsGroup
            {
                idc = FACTIONS_CONFIG_CUSTOMGROUPBUTTONSCONTROLGROUP_IDC;
                x = 0;
                y = 16 * GUI_GRID_H + GUI_GRID_Y;
                w = COLUMN_WIDTH * GUI_GRID_W;
                h = 1 * GUI_GRID_W;

                class Controls
                {
                    class Rimsiakas_FactionsConfigDialog_EditCustomGroupButton: Rimsiakas_ButtonSmall
                    {
                        idc = FACTIONS_CONFIG_EDITCUSTOMGROUPBUTTON_IDC;
                        text = "Edit custom";
                        x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                        y = 0 * GUI_GRID_H + GUI_GRID_Y;
                        w = (COLUMN_WIDTH / 2 - MARGIN * 1.5) * GUI_GRID_W;
                        action = "uiNamespace setVariable [""Rimsiakas_customGroupEditingMode"", true]; createDialog 'Rimsiakas_CustomGroupDialog';";
                    }

                    class Rimsiakas_FactionsConfigDialog_RemoveCustomGroupButton: Rimsiakas_ButtonSmall
                    {
                        idc = FACTIONS_CONFIG_REMOVECUSTOMGROUPBUTTON_IDC;
                        text = "Remove selected";
                        x = (COLUMN_WIDTH / 2 + MARGIN * 0.5) * GUI_GRID_W + GUI_GRID_X;
                        y = 0 * GUI_GRID_H + GUI_GRID_Y;
                        w = (COLUMN_WIDTH / 2 - MARGIN * 1.5) * GUI_GRID_W;
                        tooltip = "Can also double-click an entry";
                        action = "[] call Rimsiakas_fnc_removeGroupFromPool;";
                    }
                }
            };

            class Rimsiakas_FactionsConfigDialog_RemovePoolButton: Rimsiakas_ButtonSmall
            {
                idc = FACTIONS_CONFIG_REMOVEPOOLBUTTON_IDC;
                text = "Remove pool";
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 17 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                action = "[] spawn Rimsiakas_fnc_removePoolFromSpawner;";
            }
        };
    };

    class Rimsiakas_FactionsConfigDialog_ThirdColumnFrame: RscFrame
    {
        idc = FACTIONS_CONFIG_THIRDCOLUMNFRAME_IDC;
        x = (MARGIN * 3 + COLUMN_WIDTH * 2) * GUI_GRID_W;
        y = 4.5 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 18 * GUI_GRID_H;
    };

    class Rimsiakas_FactionsConfigDialog_GroupsConfigControlGroup: RscControlsGroup
    {
        idc = FACTIONS_CONFIG_GROUPSCONFIGCONTROLGROUP_IDC;
        x = (MARGIN * 3 + COLUMN_WIDTH * 2) * GUI_GRID_W;
        y = 4.5 * GUI_GRID_H + GUI_GRID_Y;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 18 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionsConfigDialog_GroupsConfigSearch: RscEdit
            {
                idc = FACTIONS_CONFIG_GROUPSCONFIGSEARCH_IDC;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - 2 - MARGIN * 1) * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionsConfigDialog_GroupsConfigSearchIcon: RscPictureKeepAspect
            {
                idc = FACTIONS_CONFIG_GROUPSCONFIGSEARCHICON_IDC;
                x = (COLUMN_WIDTH - MARGIN - 1) * GUI_GRID_W;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 1 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
                text = "\A3\ui_f\data\gui\rsccommon\rscbuttonsearch\search_start_ca.paa";
            };

            class Rimsiakas_FactionsConfigDialog_GroupsConfigTree: RscTreeSearch
            {
                idc = FACTIONS_CONFIG_GROUPSCONFIGTREE_IDC;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 2 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                h = 13.5 * GUI_GRID_H;
                multiselectEnabled = 1;
                onTreeSelChanged = "_this call Rimsiakas_fnc_onGroupConfigTreeSelectionChange;";
                onTreeDblClick = "[] call Rimsiakas_fnc_addGroupToPool;";
                idcSearch = FACTIONS_CONFIG_GROUPSCONFIGSEARCH_IDC;
            };

            class Rimsiakas_FactionsConfigDialog_AddGroupButton: Rimsiakas_ButtonSmall
            {
                idc = FACTIONS_CONFIG_ADDGROUPBUTTON_IDC;
                text = "Add selected";
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 16 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                action = "[] call Rimsiakas_fnc_addGroupToPool;";
            }

            class Rimsiakas_FactionsConfigDialog_AddCustomGroupButton: Rimsiakas_ButtonSmall
            {
                idc = FACTIONS_CONFIG_ADDCUSTOMGROUPBUTTON_IDC;
                text = "Add custom";
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 17 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                action = "uiNamespace setVariable [""Rimsiakas_customGroupEditingMode"", false]; createDialog 'Rimsiakas_CustomGroupDialog';";
            }
        };
    };
    
    class Rimsiakas_FactionsConfigDialog_Buttons_ControlGroup: RscControlsGroup
    {
        idc = FACTIONS_CONFIG_BUTTONS_CONTROLGROUP_IDC;
        x = 0.5 * GUI_GRID_W;
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
        w = 40 * COLUMN_WIDTH * GUI_GRID_W;
        h = 2 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionsConfigDialog_ConfirmButton: Rimsiakas_Button
            {
                idc = FACTIONS_CONFIG_BUTTONS_CONFIRM_IDC;
                action = "[] call Rimsiakas_fnc_confirmFactionsConfig; closeDialog 1;";
                text = "Confirm";
                x = 0 * GUI_GRID_W + GUI_GRID_X;
                y = 0 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionsConfigDialog_CancelButton: Rimsiakas_Button
            {
                idc = FACTIONS_CONFIG_BUTTONS_CANCEL_IDC;
                action = "Rimsiakas_workingSpawnersData = +Rimsiakas_lastSavedSpawnersData; closeDialog 2;";
                text = "Cancel";
                x = 6 * GUI_GRID_W + GUI_GRID_X;
                y = 0 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionsConfigDialog_FactionPresetsButton: Rimsiakas_Button
            {
                idc = FACTIONS_CONFIG_BUTTONS_FACTIONPRESETS_IDC;
                action = "[] spawn {createDialog 'Rimsiakas_FactionPresetsDialog';};";
                text = "Presets";
                x = 12 * GUI_GRID_W + GUI_GRID_X;
                y = 0 * GUI_GRID_H + GUI_GRID_Y;
                w = 5.5 * GUI_GRID_W;
            };
        }
    }
}