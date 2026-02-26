class Rimsiakas_CustomGroupDialog
{
    idd = CUSTOM_GROUP_FORM_IDD;
    movingEnabled = false;
    enableSimulation = true;

    controlsBackground[]=
    {
        Rimsiakas_CustomGroupDialog_Background,
    };

    controls[]=
    {
        Rimsiakas_CustomGroupDialog_ControlGroup
    };

    class Rimsiakas_CustomGroupDialog_Background: RscText
    {
        idc = CUSTOM_GROUP_FORM_BACKGROUND_IDC;
        x = 0 * GUI_GRID_W + GUI_GRID_X;
        y = 2 * GUI_GRID_H + GUI_GRID_Y;
        w = 40 * GUI_GRID_W;
        h = 18 * GUI_GRID_H;
        colorBackground[] = {0.15,0.15,0.15,0.9};
    };

    class Rimsiakas_CustomGroupDialog_ControlGroup: RscControlsGroup
    {
        idc = CUSTOM_GROUP_FORM_CONTROLGROUP_IDC;
        x = 0 * GUI_GRID_W + GUI_GRID_X;
        y = 2 * GUI_GRID_H + GUI_GRID_Y;
        w = 40 * GUI_GRID_W;
        h = 18 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_CustomGroupDialog_Instruction: RscStructuredText
            {
                idc = CUSTOM_GROUP_FORM_INSTRUCTION_IDC;
                text = "Paste an array of groups that you want to add.<br/>Groups are defined as JSON arrays containing the class names of units in the group.<br/>Example:<br/><t size=""0.66"" font=""EtelkaMonospacePro"">[<br/>  [""B_MRAP_01_F"",""B_MRAP_01_hmg_F""],                <t color=""#ff0000"">&lt;- Group 1</t><br/>  [""B_G_Offroad_01_armed_F"",""B_G_Offroad_01_AT_F""]  <t color=""#ff0000"">&lt;- Group 2</t><br/>]</t><br/>Vehicles will be spawned with crew.";
                x = 0.5 * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 39 * GUI_GRID_W;
                h = 6.5 * GUI_GRID_H;
                sizeEx = 0.03;
            };

            class Rimsiakas_CustomGroupDialog_Input: RscEdit
            {
                idc = CUSTOM_GROUP_FORM_INPUT_IDC;
                x = 0.5 * GUI_GRID_W + GUI_GRID_X;
                y = 7.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 39 * GUI_GRID_W;
                h = 8 * GUI_GRID_H;
                style = ST_MULTI;
                sizeEx = 0.03;
                font = "EtelkaMonospacePro";
            };

            class Rimsiakas_CustomGroupDialog_ConfirmButton: RscButton
            {
                idc = CUSTOM_GROUP_FORM_CONFIRMBUTTON_IDC;
                text = "Confirm";
                action = "[] call Rimsiakas_fnc_addCustomGroupFactionsConfig;";

                x = 0.5 * GUI_GRID_W + GUI_GRID_X;
                y = 16 * GUI_GRID_H + GUI_GRID_Y;
                w = 5 * GUI_GRID_W;
                h = 1.5 * GUI_GRID_H;
            };

            class Rimsiakas_CustomGroupDialog_CancelButton: RscButton
            {
                idc = CUSTOM_GROUP_FORM_CANCELBUTTON_IDC;
                text = "Cancel";
                action = "closeDialog 2;";

                x = 6 * GUI_GRID_W + GUI_GRID_X;
                y = 16 * GUI_GRID_H + GUI_GRID_Y;
                w = 5 * GUI_GRID_W;
                h = 1.5 * GUI_GRID_H;
            };
        };
    };
}
