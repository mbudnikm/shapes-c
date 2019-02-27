#ifndef CISOSCELESTRIANGLE_H
#define CISOSCELESTRIANGLE_H

#include "CFilledShape.h"
#include <windows.h>

class CIsoscelesTriangle : public CFilledShape
{
private:
    POINT mVertices[3];
    void updateVertices();

protected:
    virtual void doPaint(HDC hdc);
    virtual void afterBoundingRectChange();

public:
    //Konstruktor i destruktor
    CIsoscelesTriangle();
};


#endif // CISOSCELESTRIANGLE_H
