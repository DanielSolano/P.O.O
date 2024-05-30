#pragma once
#include "Figura.h"
class Rectangulo :
    public Figura
{
protected:
    int alto;
    int ancho;
public:
    Rectangulo(CPoint pos = 0, COLORREF color = 0, COLORREF relleno = RGB(255,255,255), int alto = 0, int ancho = 0);
    virtual void Ajustar(CPoint p) override;
    virtual void Desplegar(CDC* pDC) override;
    virtual double GetArea() override;
};

