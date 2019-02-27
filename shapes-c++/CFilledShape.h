#ifndef CFILLEDSHAPE_H
#define CFILLEDSHAPE_H

#include "CShape.h"
#include <windows.h>

class CFilledShape : public CShape
{
private:
    int mLineWidth;
    COLORREF mLineColor;
    COLORREF mFillColor;
    HPEN mPen;
    HBRUSH mBrush;

protected:
    virtual void doPaint(HDC hdc) = 0;

public:
    //Atrybuty publiczne
    void setLineWidth(int aLineWidth);
    int getLineWidth();

    void setLineColor(COLORREF aLineColor);
    COLORREF getLineColor();

    void setFillColor(COLORREF aFillColor);
    COLORREF getFillColor();

    //Metody publiczne

    void Paint(HDC hdc);

    //Konstruktor i destruktor
    CFilledShape();
    virtual ~CFilledShape();
};


#endif // CFILLEDSHAPE_H
