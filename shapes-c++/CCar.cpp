#include "CCar.h"

void CCar::afterBoundingRectChange()
{
    RECT tmpRect;
    int width, height;

    width = mBoundingRect.right - mBoundingRect.left;
    height = mBoundingRect.bottom - mBoundingRect.top;

    tmpRect.left = mBoundingRect.left + width/4;
    tmpRect.right = mBoundingRect.right - width/4;
    tmpRect.top = mBoundingRect.top;
    tmpRect.bottom = mBoundingRect.top + height/3;

    mRoof.setBoundingRect(tmpRect);

    tmpRect.left = mBoundingRect.left;
    tmpRect.right = mBoundingRect.right;
    tmpRect.top = mBoundingRect.top + height/3;
    tmpRect.bottom = mBoundingRect.bottom - height/3;

    mBody.setBoundingRect(tmpRect);

    tmpRect.left = mBoundingRect.left;
    tmpRect.right = mBoundingRect.left + width/2;
    tmpRect.top = mBoundingRect.bottom - height/3;
    tmpRect.bottom = mBoundingRect.bottom;

    mLeftWheel.setBoundingRect(tmpRect);

    tmpRect.left = mBoundingRect.left + width/2;
    tmpRect.right = mBoundingRect.right;

    mRightWheel.setBoundingRect(tmpRect);
}

void CCar::Paint(HDC hdc)
{
    mRoof.Paint(hdc);
    mBody.Paint(hdc);
    mLeftWheel.Paint(hdc);
    mRightWheel.Paint(hdc);
}

CCar::CCar()
{
    mRoof.setFillColor(RGB(255,0,0));
    mBody.setFillColor(RGB(0,255,255));
    mLeftWheel.setFillColor(RGB(128,128,128));
    mRightWheel.setFillColor(RGB(128,128,128));
}
