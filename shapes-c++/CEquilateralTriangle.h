#ifndef CEQUILATERALTRIANGLE_H
#define CEQUILATERALTRIANGLE_H

#include "CIsoscelesTriangle.h"
#include <windows.h>

class CEquilateralTriangle : public CIsoscelesTriangle
{
protected:
    virtual void beforeBoundingRectChange(RECT &newBoundingRect);

public:
    virtual void Tick();
};


#endif // CEQUILATERALTRIANGLE_H
