#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "CFilledShape.h"
#include <windows.h>

class CEllipse : public CFilledShape
{
protected:
    virtual void doPaint(HDC hdc);
};


#endif // CELLIPSE_H
