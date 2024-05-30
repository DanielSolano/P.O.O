#pragma once
class Figura
{
protected:
	CPoint pos; // Posicion de la figura
	COLORREF color = 0; // Color de la figura	
	COLORREF relleno = RGB(255, 255, 255); // Color de la figura
	bool bloqueado = false;
public:
	Figura(CPoint pos, COLORREF color, COLORREF relleno = RGB(255, 255, 255));
	virtual void Mover(CPoint np) { pos = np; };
	virtual void Desplegar(CDC* pDC);
	virtual void Ajustar(CPoint p) = 0;
	virtual void Bloquear() { bloqueado = true; };
	virtual double GetArea() = 0;
	CPoint GetPos() { return pos; };
	COLORREF GetColor() { return color; };
	COLORREF GetRelleno() { return relleno; };
	bool IsBlock() { return bloqueado; };

};

