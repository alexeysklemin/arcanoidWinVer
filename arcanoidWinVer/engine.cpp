#include "engine.h"
enum eBrickType {
    brickNone,
    brickRed,
    brickBlue
};

const int globalScale = 3;
const int brickWidth = 15;
const int brickHeigt = 7;
const int cellWidth = 16;
const int cellHeigt = 8;
const int levelXOffset = 8;
const int levelYOffset = 6;

HPEN bluePen, redPen;
HBRUSH blueBrush, redBrush;

char level01[12][14] = { 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,
                        1,1,1, 1,1,1, 1,1,1, 1,1,1, 1,1,
                        1,1,1, 1,1,1, 1,1,1, 1,1,1, 1,1,
                        2,2,2, 2,2,2, 2,2,2, 2,2,2, 2,2,
                        2,2,2, 2,2,2, 2,2,2, 2,2,2, 2,2,
                        1,1,1, 1,1,1, 1,1,1, 1,1,1, 1,1,
                        1,1,1, 1,1,1, 1,1,1, 1,1,1, 1,1,
                        2,2,2, 2,2,2, 2,2,2, 2,2,2, 2,2,
                        2,2,2, 2,2,2, 2,2,2, 2,2,2, 2,2,
                        0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,
                        0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,
                        0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0 };


void init() {
    bluePen = CreatePen(PS_SOLID, 0, RGB(255, 85, 255));
    blueBrush = CreateSolidBrush(RGB(255, 85, 255));

    redPen = CreatePen(PS_SOLID, 0, RGB(85, 255, 255));
    redBrush = CreateSolidBrush(RGB(85, 255, 255));
}


void drawBrick(HDC hdc, int x, int y, eBrickType colorBric) {

    HPEN pen;
    HBRUSH brush;



    switch (colorBric) {


    case brickNone:
        return;
    case brickRed:
        pen = bluePen;
        brush = blueBrush;
        break;
    case brickBlue:
        pen = redPen;
        brush = redBrush;
        break;
    default:
        return;
    }

    //

    SelectObject(hdc, pen);
    SelectObject(hdc, brush);

    RoundRect(hdc, x * globalScale, y * globalScale, (x + brickWidth) * globalScale, (y + brickHeigt) * globalScale, 2 * globalScale, 2 * globalScale);
}


void drawLevel1(HDC hdc) {
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 12; ++j) {

            drawBrick(hdc, levelXOffset + j * cellWidth, levelYOffset + i * cellHeigt, (eBrickType)level01[i][j]);


        }
    }
}



void drawFrame(HDC hdc) {

    drawLevel1(hdc);


}


