#include "CFilledShape.h"
#include "Utils.h"


//Atrybuty publiczne
void CFilledShape::setLineWidth(int aLineWidth)
{
    if(aLineWidth >= 0 && aLineWidth != mLineWidth)
    {
        mLineWidth = aLineWidth;
        DeleteObject(mPen);
        mPen = CreatePen(PS_SOLID, mLineWidth, mLineColor);
    }
}

int CFilledShape::getLineWidth()
{
    return mLineWidth;
}

void CFilledShape::setLineColor(COLORREF aLineColor)
{
    if(aLineColor != mLineColor)
    {
        mLineColor = aLineColor;
        DeleteObject(mPen);
        mPen = CreatePen(PS_SOLID, mLineWidth, mLineColor);
    }
}

COLORREF CFilledShape::getLineColor()
{
    return mLineColor;
}

void CFilledShape::setFillColor(COLORREF aFillColor)
{
    if(aFillColor != mFillColor)
    {
        mFillColor = aFillColor;
        DeleteObject(mBrush);
        mBrush = CreateSolidBrush(mFillColor);
    }
}

COLORREF CFilledShape::getFillColor()
{
    return mFillColor;
}

//Metody publiczne

void CFilledShape::Paint(HDC hdc)
{
    HPEN oldPen;
    HBRUSH oldBrush;

    oldPen = (HPEN)SelectObject(hdc, mPen);
    oldBrush = (HBRUSH)SelectObject(hdc, mBrush);

    doPaint(hdc);

    SelectObject(hdc, oldPen);
    SelectObject(hdc, oldBrush);
}

//Konstruktor i destruktor
CFilledShape::CFilledShape()
{
    mLineWidth = 0;
    mLineColor = RGB(0,0,0);
    mFillColor = RGB(255,255,255);
    mPen = CreatePen(PS_SOLID, mLineWidth, mLineColor);
    mBrush = CreateSolidBrush(mFillColor);
}

CFilledShape::~CFilledShape()
{
    DeleteObject(mPen);
    DeleteObject(mBrush);
}
