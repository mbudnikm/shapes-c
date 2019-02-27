#include "CHouse.h"

void CHouse::beforeBoundingRectChange(RECT &newBoundingRect)
{

    int width, height;
    width = newBoundingRect.right - newBoundingRect.left;
    height = newBoundingRect.bottom - newBoundingRect.top;

    RECT chimneyBoundingRect,roofBoundingRect,doorBoundingRect, windowBoundingRect;
    roofBoundingRect = newBoundingRect;
    chimneyBoundingRect = newBoundingRect;
    doorBoundingRect = newBoundingRect;
    windowBoundingRect = newBoundingRect;

    roofBoundingRect.bottom = roofBoundingRect.bottom - height/2;
    Roof.setBoundingRect(roofBoundingRect);

    chimneyBoundingRect.left = chimneyBoundingRect.left + width*3/4;
    chimneyBoundingRect.right = chimneyBoundingRect.right - width/6;
    chimneyBoundingRect.bottom = chimneyBoundingRect.bottom - height/2;
    chimneyBoundingRect.top = chimneyBoundingRect.top + height/6;
    Chimney.setBoundingRect(chimneyBoundingRect);

    roofBoundingRect.top = roofBoundingRect.top + height/2;
    roofBoundingRect.bottom = roofBoundingRect.bottom + height/2;
    Body.setBoundingRect(roofBoundingRect);

    doorBoundingRect.left = doorBoundingRect.left + width*3/5;
    doorBoundingRect.right = doorBoundingRect.right - width/6;
    doorBoundingRect.top = doorBoundingRect.top + height*3/4;
    Door.setBoundingRect(doorBoundingRect);

    windowBoundingRect.top = windowBoundingRect.top + height*3/5;
    windowBoundingRect.bottom = windowBoundingRect.bottom - height/6;
    windowBoundingRect.left = windowBoundingRect.left + width/6;
    windowBoundingRect.right = windowBoundingRect.right - width*3/5;
    Window.setBoundingRect(windowBoundingRect);


}

void CHouse::Paint(HDC hdc)
{
    Chimney.Paint(hdc);
    Roof.Paint(hdc);
    Body.Paint(hdc);
    Door.Paint(hdc);
    Window.Paint(hdc);
}

CHouse::CHouse()
{
    Roof.setFillColor(RGB(200,0,0));
    Body.setFillColor(RGB(249,224,75));
    Chimney.setFillColor(RGB(0,0,0));
    Door.setFillColor(RGB(96,2,1));
    Window.setFillColor(RGB(192,255,255));
}
