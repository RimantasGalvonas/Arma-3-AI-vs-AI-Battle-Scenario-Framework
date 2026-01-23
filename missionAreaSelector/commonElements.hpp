class Rimsiakas_Button: RscButton
{
    h = 1.5 * GUI_GRID_H;
    colorBackground[] = {0.1,0.1,0.1,1};
    colorShadow[] = {0,0,0,1};
    offsetX = 1 * pixelW;
    offsetY = 1 * pixelH;
}

class Rimsiakas_MainBackground: RscText
{
    x = 0;
    y = 0;
    w = 40 * GUI_GRID_W;
    h = 25 * GUI_GRID_H;
    colorBackground[] = {0.15,0.15,0.15,0.9};
}

class Rimsiakas_Heading: RscText
{
    x = 0.5 * GUI_GRID_W + GUI_GRID_X;
    y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
    w = 39 * GUI_GRID_W;
    h = 1.5 * GUI_GRID_H;
    sizeEx = 0.05;
}