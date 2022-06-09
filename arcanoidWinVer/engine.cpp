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
const int circlSize = 7;

int innerWidth = 21;

HPEN highlightPen, bluePen, redPen;
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


void penBrush(unsigned char r, unsigned char g, unsigned char b, HPEN &pen, HBRUSH &brush) {

    pen = CreatePen(PS_SOLID, 0, RGB(r, g, b));
    brush = CreateSolidBrush(RGB(r, g, b));

}

void init() {
    
    highlightPen = CreatePen(PS_SOLID, 0, RGB(255,255,255));


   penBrush(255, 85, 255, redPen, redBrush);

   penBrush(85, 255, 255, bluePen, blueBrush);

   /* bluePen = CreatePen(PS_SOLID, 0, RGB(255, 85, 255));
    blueBrush = CreateSolidBrush(RGB(255, 85, 255));

    redPen = CreatePen(PS_SOLID, 0, RGB(85, 255, 255));
    redBrush = CreateSolidBrush(RGB(85, 255, 255));*/

    penBrush(255, 85, 255, redPen, redBrush);

    penBrush(85, 255, 255, bluePen, blueBrush);
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


void drawPlatform(HDC hdc, int x, int y) {

    

    SelectObject(hdc, redPen);
    SelectObject(hdc, redBrush);

    Ellipse(hdc, x * globalScale, y * globalScale, (x + circlSize) * globalScale, (y + circlSize) * globalScale);
    Ellipse(hdc, (x+innerWidth) * globalScale, y * globalScale, (x + circlSize+innerWidth) * globalScale, (y + circlSize) * globalScale);

    SelectObject(hdc, highlightPen);
    Arc(hdc, (x+1)*globalScale, (y+1)*globalScale, (x+circlSize-1)*globalScale, (y+circlSize-1)*globalScale, (x+1+1)*globalScale, (y+1)*globalScale, (x+1)*globalScale, (y+1+2)*globalScale);

    SelectObject(hdc, bluePen);
    SelectObject(hdc, blueBrush);

    RoundRect(hdc, (x + 4) * globalScale, (y + 1) * globalScale, (x + 4 + innerWidth - 1) * globalScale, (y + 1 + 5) * globalScale, 4 * globalScale, 4 * globalScale);
}



void drawFrame(HDC hdc) {

    drawLevel1(hdc);
    drawPlatform(hdc, 50, 100);

}


