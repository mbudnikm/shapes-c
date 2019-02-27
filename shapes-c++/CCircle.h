#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CEllipse.h"
#include <windows.h>

class CCircle : public CEllipse
{
protected:
    virtual void beforeBoundingRectChange(RECT &newBoundingRect);

public:
    void Tick();
};


#endif // CCIRCLE_H
