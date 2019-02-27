#ifndef CHOUSE_H
#define CHOUSE_H

#include "CShape.h"
#include "CSquare.h"
#include "CRectangle.h"
#include "CEquilateralTriangle.h"
#include "CIsoscelesTriangle.h"


class CHouse : public CShape
{
private:
    CRectangle Body;
    CIsoscelesTriangle Roof;
    CSquare Window;
    CRectangle Door;
    CRectangle Chimney;

protected:
    virtual void beforeBoundingRectChange(RECT &newBoundingRect);

public:
    //Metody publiczne
    virtual void Paint(HDC hdc);

    CHouse();
};

#endif // CHOUSE_H
