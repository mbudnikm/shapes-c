#ifndef CSQUARE_H
#define CSQUARE_H

#include "CRectangle.h"
#include <windows.h>

class CSquare : public CRectangle
{
protected:
    virtual void beforeBoundingRectChange(RECT &newBoundingRect);

public:
    void Tick();
};


#endif // CSQUARE_H
