#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CFilledShape.h"
#include <windows.h>

class CRectangle : public CFilledShape
{
protected:
    virtual void doPaint(HDC hdc);
};


#endif // CRECTANGLE_H
