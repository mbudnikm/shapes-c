#include "MsgHandlers.h"
#include "Utils.h"
#include <time.h>
#include <math.h>
#include "CEllipse.h"
#include "CRectangle.h"
#include "CIsoscelesTriangle.h"
#include "CCircle.h"
#include "CSquare.h"
#include "CEquilateralTriangle.h"
#include "CCar.h"
#include "CInscribed.h"
#include "CHouse.h"

/************************ Zmienne globalne ************************/

int ClientWidth, ClientHeight;
BOOL EraseBkgnd = TRUE;

RECT MouseRect;
bool InDrawState = false;

const int MyShapesCount = 3;
CShape* MyShapes[MyShapesCount];

int CurrDrawnShapeIdx = 0;
enum TShapeType {stUnknown, stEllipse, stRectangle, stIsoscelesTriangle,
                 stCircle, stSquare, stEquilateralTriangle, stCar, stInscribed, stHouse};

/******************** Procedury obs³ugi zdarzeñ ********************/

//Procedura wywo³ywana przed pokazaniem okna (na pocz¹tku dzia³ania programu).
//Tutaj mo¿na przeprowadziæ pocz¹tkow¹ inicjalizacjê zmiennych, obiektów itp.
void OnCreate(HWND hwnd)
{
    int i;
    TShapeType shapeType;
    bool isFilledShape;

    srand(time(NULL));

    for(i = 0; i < MyShapesCount; i++)
    {
        isFilledShape = true;
        shapeType = (TShapeType)RandRange(stInscribed,stHouse);// (TShapeType)RandRange(stEllipse,stEquilateralTriangle);

        switch(shapeType)
        {
        case stEllipse:
            MyShapes[i] = new CEllipse;
            break;
        case stRectangle:
            MyShapes[i] = new CRectangle;
            break;
        case stIsoscelesTriangle:
            MyShapes[i] = new CIsoscelesTriangle;
            break;
        case stCircle:
            MyShapes[i] = new CCircle;
            break;
        case stSquare:
            MyShapes[i] = new CSquare;
            break;
        case stEquilateralTriangle:
            MyShapes[i] = new CEquilateralTriangle;
            break;
        case stCar:
            MyShapes[i] = new CCar;
            isFilledShape = false;
            break;
        case stInscribed:
            MyShapes[i] = new CInscribed;
            isFilledShape = false;
            break;
        case stHouse:
            MyShapes[i] = new CHouse;
            isFilledShape = false;
            break;
        case stUnknown:
            isFilledShape = false;
            continue;
            break;
        }

        if(isFilledShape)
        {
//            static_cast<CFilledShape*>(MyShapes[i])->setLineWidth(RandRange(2,6));
//            static_cast<CFilledShape*>(MyShapes[i])->setLineColor(RGB(RandRange(0,255),RandRange(0,255),RandRange(0,255)));
//            static_cast<CFilledShape*>(MyShapes[i])->setFillColor(RGB(RandRange(0,255),RandRange(0,255),RandRange(0,255)));
//            ((CFilledShape*)(MyShapes[i]))->setLineWidth(RandRange(2,6));
//            ((CFilledShape*)(MyShapes[i]))->setLineColor(RGB(RandRange(0,255),RandRange(0,255),RandRange(0,255)));
//            ((CFilledShape*)(MyShapes[i]))->setFillColor(RGB(RandRange(0,255),RandRange(0,255),RandRange(0,255)));
            dynamic_cast<CFilledShape*>(MyShapes[i])->setLineWidth(RandRange(2,6));
            dynamic_cast<CFilledShape*>(MyShapes[i])->setLineColor(RGB(RandRange(0,255),RandRange(0,255),RandRange(0,255)));
            dynamic_cast<CFilledShape*>(MyShapes[i])->setFillColor(RGB(RandRange(0,255),RandRange(0,255),RandRange(0,255)));
        }
    }

    SetTimer(hwnd, 1, 25, NULL);
}


//Procedura wywo³ywana po ka¿dej zmianie rozmiaru okna
void OnSize(HWND hwnd, int width, int height, WPARAM wParam)
{
    int i;
    ClientWidth = width;
    ClientHeight = height;

    RECT tmpRect = {width/2-250, height/2-150, width/2+250, height/2+150};

    for(i = 0; i < MyShapesCount; i++)
        MyShapes[i]->setBoundingRect(tmpRect);

    InvalidateRect(hwnd, NULL, EraseBkgnd);
}


//Procedura wywo³ywana co 25 ms (czas ustawia siê trzecim argumentem
// funkcji SetTimer() wywo³ywanej w OnCreate).
void OnTimer(HWND hwnd, WPARAM timerID)
{
    int i;

    if(InDrawState) return;

    for(i = 0; i < MyShapesCount; i++)
        MyShapes[i]->Tick();

    InvalidateRect(hwnd, NULL, EraseBkgnd);
}


//Procedura wywo³ywana w celu odœwie¿enia zawartoœci okna.
//Wy³¹cznie tutaj powinno siê przeprowadzaæ rysowanie.
void OnPaint(HWND hwnd, HDC hdc)
{
	int i;

	if(InDrawState)
        Rectangle(hdc, MouseRect.left, MouseRect.top, MouseRect.right, MouseRect.bottom);

    for(i = 0; i < MyShapesCount; i++)
    {
        DrawFocusRect(hdc, &MyShapes[i]->getBoundingRect());
        MyShapes[i]->Paint(hdc);
    }

}


//Procedura wywo³ywana po naciœniêciu klawisza klawiatury.
void OnKeyDown(HWND hwnd, WPARAM keyCode)
{
    switch (keyCode)
    {
    case VK_LEFT:
        break;
    case VK_UP:
        break;
    case VK_RIGHT:
        break;
    case VK_DOWN:
        break;
    case 0x43: //klawisz C
        break;
    case 0x4F: //klawisz O
        EraseBkgnd ^= 0x00000001;
        break;
    case 0x52: //klawisz R
        break;
    case 0x53: //klawisz S
        break;
    }
    //InvalidateRect(hwnd, NULL, EraseBkgnd);
}


//Procedura wywo³ywana po poruszeniu wskaŸnika myszy.
void OnMouseMove(HWND hwnd, int x, int y, WPARAM wParam)
{
    if(InDrawState)
    {
        MouseRect.right = x;
        MouseRect.bottom = y;

        MyShapes[CurrDrawnShapeIdx]->setBoundingRect(MouseRect);

        InvalidateRect(hwnd, NULL, EraseBkgnd);
    }
}


//Procedura wywo³ywana po naciœniêciu lewego przycisku myszy.
void OnLButtonDown(HWND hwnd, int x, int y, WPARAM wParam)
{
    if(!InDrawState)
    {
        MouseRect.left = x;
        MouseRect.top = y;
        MouseRect.right = x;
        MouseRect.bottom = y;

        MyShapes[CurrDrawnShapeIdx]->setBoundingRect(MouseRect);

        InDrawState = true;
        SetCapture(hwnd);
    }
}


//Procedura wywo³ywana po zwolnieniu lewego przycisku myszy.
void OnLButtonUp(HWND hwnd, int x, int y, WPARAM wParam)
{
    if(InDrawState)
    {
        MouseRect.right = x;
        MouseRect.bottom = y;

        MyShapes[CurrDrawnShapeIdx]->setBoundingRect(MouseRect);
        CurrDrawnShapeIdx = (CurrDrawnShapeIdx+1) % MyShapesCount;

        InDrawState = false;
        ReleaseCapture();
        InvalidateRect(hwnd, NULL, EraseBkgnd);
    }
}


//Procedura wywo³ywana przed zniszczeniem okna (przed koñcem dzia³ania programu).
//Tutaj mo¿na zwolniæ zaalokowane zasoby.
void OnDestroy(HWND hwnd)
{
    int i;

    KillTimer(hwnd, 1);

    for(i = 0; i < MyShapesCount; i++)
        delete MyShapes[i];

}

