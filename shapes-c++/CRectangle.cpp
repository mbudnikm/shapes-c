#include "CRectangle.h"
#include "Utils.h"

void CRectangle::doPaint(HDC hdc)
{
    Rectangle(hdc,
              mBoundingRect.left,
              mBoundingRect.top,
              mBoundingRect.right,
              mBoundingRect.bottom);
}
