#include "CInscribed.h"

void CInscribed::beforeBoundingRectChange(RECT &newBoundingRect)
{
    int width, height, center;
    width = newBoundingRect.right - newBoundingRect.left;
    height = newBoundingRect.bottom - newBoundingRect.top;

    if(width > height)
    {
        center = (newBoundingRect.right + newBoundingRect.left) / 2;
        newBoundingRect.right = center + height / 2;
        newBoundingRect.left = center - height / 2;
    }
    else if(width < height)
    {
        center = (newBoundingRect.bottom + newBoundingRect.top) / 2;
        newBoundingRect.top = center - width / 2;
        newBoundingRect.bottom = center + width / 2;
    }

    RECT tmp;
    tmp = newBoundingRect;
    outSquare.setBoundingRect(tmp);
    outCircle.setBoundingRect(tmp);
    tmp = outSquare.getBoundingRect();
    tmp.bottom = tmp.bottom - (tmp.bottom - tmp.top)/4;
    inEquilateralTriangle.setBoundingRect(tmp);
    tmp.top = tmp.top + (tmp.bottom - tmp.top)/3;
    inCircle.setBoundingRect(tmp);
}

void CInscribed::Paint(HDC hdc)
{
    outSquare.Paint(hdc);
    outCircle.Paint(hdc);
    inEquilateralTriangle.Paint(hdc);
    inCircle.Paint(hdc);
}

CInscribed::CInscribed()
{
    outSquare.setFillColor(RGB(111,111,111));
    outCircle.setFillColor(RGB(0,255,255));
    inEquilateralTriangle.setFillColor(RGB(153,102,204));
    inCircle.setFillColor(RGB(255,128,128));
}
