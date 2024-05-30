#include "pch.h"
#include "Figura.h"

Figura::Figura(CPoint pos, COLORREF color, COLORREF relleno)
{
	this->pos = pos;
	this->color = color;
	this->relleno = relleno;
}

void Figura::Desplegar(CDC* pDC)
{
	// A este nivel de generalizacion no sabemos como desplegar la figura
	pDC->SelectStockObject(DC_PEN);
	pDC->SetDCPenColor(color); 
	pDC->SelectStockObject(DC_BRUSH);
	pDC->SetDCBrushColor(relleno);
}
