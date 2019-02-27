#include "CShape.h"
#include "Utils.h"


//Atrybuty publiczne
void CShape::setBoundingRect(const RECT &aBoundingRect)
{
    RECT tmpBoundingRect = aBoundingRect;
    CorrectRect(&tmpBoundingRect);
    beforeBoundingRectChange(tmpBoundingRect);
    mBoundingRect = tmpBoundingRect;
    afterBoundingRectChange();
}

const RECT& CShape::getBoundingRect()
{
    return mBoundingRect;
}

void CShape::getBoundingRect(RECT* aBoundingRect)
{
    *aBoundingRect = mBoundingRect;
}

void CShape::Tick()
{
    mBoundingRect.left += RandRange(-5,5);
    mBoundingRect.top += RandRange(-5,5);
    mBoundingRect.right += RandRange(-5,5);
    mBoundingRect.bottom += RandRange(-5,5);
    setBoundingRect(mBoundingRect);
}

//Konstruktor i destruktor
CShape::CShape()
{
    SetRect(&mBoundingRect,0,0,0,0);
}

CShape::~CShape()
{
}
