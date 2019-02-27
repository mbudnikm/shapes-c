#include "CEllipse.h"
#include "Utils.h"

void CEllipse::doPaint(HDC hdc)
{
    Ellipse(hdc,
            mBoundingRect.left,
            mBoundingRect.top,
            mBoundingRect.right,
            mBoundingRect.bottom);
}
