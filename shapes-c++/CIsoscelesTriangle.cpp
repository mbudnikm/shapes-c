#include "CIsoscelesTriangle.h"
#include "Utils.h"

void CIsoscelesTriangle::updateVertices()
{
    mVertices[0].x = mBoundingRect.left;
    mVertices[0].y = mBoundingRect.bottom;
    mVertices[1].x = (mBoundingRect.left + mBoundingRect.right) / 2;
    mVertices[1].y = mBoundingRect.top;
    mVertices[2].x = mBoundingRect.right;
    mVertices[2].y = mBoundingRect.bottom;
}

void CIsoscelesTriangle::doPaint(HDC hdc)
{
    Polygon(hdc, mVertices, 3);
}

void CIsoscelesTriangle::afterBoundingRectChange()
{
    updateVertices();
}

//Konstruktor i destruktor
CIsoscelesTriangle::CIsoscelesTriangle()
{
    updateVertices();
}
