#include "CEquilateralTriangle.h"
#include "Utils.h"
#include <math.h>

const float SQRT3DIV2 = sqrt(3.0) / 2.0;

void CEquilateralTriangle::beforeBoundingRectChange(RECT &newBoundingRect)
{
    int rectWidth, rectHeight, trnglHeight, trnglWidth, center;

    //zak�adam, �e prostok�t jest ju� skorygowany
    rectWidth = newBoundingRect.right - newBoundingRect.left;
    rectHeight = newBoundingRect.bottom - newBoundingRect.top;

    //obliczam wysoko�� tr�jk�ta na podstawie szeroko�ci prostok�ta
    trnglHeight = rectWidth * SQRT3DIV2;

    if(trnglHeight > rectHeight)
    {
        trnglWidth = rectHeight / SQRT3DIV2;
        center = (newBoundingRect.right + newBoundingRect.left) / 2;
        newBoundingRect.right = center + trnglWidth / 2;
        newBoundingRect.left = center - trnglWidth / 2;
    }
    else
    {
        center = (newBoundingRect.bottom + newBoundingRect.top) / 2;
        newBoundingRect.top = center - trnglHeight / 2;
        newBoundingRect.bottom = center + trnglHeight / 2;
    }
}

void CEquilateralTriangle::Tick()
{
    mBoundingRect.left += RandRange(-7,4);
    mBoundingRect.top += RandRange(-7,4);
    mBoundingRect.right += RandRange(-4,7);
    mBoundingRect.bottom += RandRange(-4,7);

    setBoundingRect(mBoundingRect);
}

