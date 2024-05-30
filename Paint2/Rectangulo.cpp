#include "pch.h"
#include "Rectangulo.h"

Rectangulo::Rectangulo(CPoint pos, COLORREF color, COLORREF relleno, int alto, int ancho)
	: Figura(pos, color, relleno)
{
	this->alto = alto;
	this->ancho = ancho;
}

void Rectangulo::Ajustar(CPoint p)
{
	CPoint d = p - pos;
	ancho = d.x;
	alto = d.y;
}

void Rectangulo::Desplegar(CDC* pDC)
{
	Figura::Desplegar(pDC);
	pDC->Rectangle(pos.x, pos.y, pos.x + ancho, pos.y + alto);
}

double Rectangulo::GetArea()
{
	return abs(ancho) * abs(alto);
}
