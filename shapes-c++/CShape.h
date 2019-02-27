#ifndef CSHAPE_H
#define CSHAPE_H

#include <windows.h>

class CShape
{
protected:
    RECT mBoundingRect;
    virtual void beforeBoundingRectChange(RECT &newBoundingRect) {}
    virtual void afterBoundingRectChange() {}

public:
    //Atrybuty publiczne
    void setBoundingRect(const RECT &aBoundingRect);
    const RECT& getBoundingRect();
    void getBoundingRect(RECT* aBoundingRect);

    //Metody publiczne
    virtual void Paint(HDC hdc) = 0;
    virtual void Tick();

    //Konstruktor i destruktor
    CShape();
    virtual ~CShape();
};


#endif // CSHAPE_H
