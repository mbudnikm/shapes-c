#ifndef CINSCRIBED_H
#define CINSCRIBED_H

#include "CShape.h"
#include "CSquare.h"
#include "CCircle.h"
#include "CEquilateralTriangle.h"


class CInscribed : public CShape
{
private:
    CCircle outCircle;
    CCircle inCircle;
    CSquare outSquare;
    CEquilateralTriangle inEquilateralTriangle;

protected:
    virtual void beforeBoundingRectChange(RECT &newBoundingRect);

public:
    //Metody publiczne
    virtual void Paint(HDC hdc);

    CInscribed();
};

#endif // CInscribed_H
