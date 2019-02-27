#ifndef CCAR_H
#define CCAR_H

#include "CShape.h"
#include "CRectangle.h"
#include "CCircle.h"


class CCar : public CShape
{
private:
    CRectangle mRoof;
    CRectangle mBody;
    CCircle mLeftWheel;
    CCircle mRightWheel;

protected:
    virtual void afterBoundingRectChange();

public:
    //Metody publiczne
    virtual void Paint(HDC hdc);

    CCar();
};

#endif // CCAR_H
