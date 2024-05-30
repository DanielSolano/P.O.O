
// ChildView.h: interfaz de la clase CChildView
//


#pragma once
#include "Dibujo.h"
#include "Rectangulo.h"


// Ventana de CChildView

class CChildView : public CWnd
{
// Construcción
public:
	CChildView();
	Dibujo dib;

// Atributos
public: 
	Figura* fig = nullptr; // Captura y modificacion
// Operaciones
public:

// Reemplazos
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementación
public:
	virtual ~CChildView();

	// Funciones de asignación de mensajes generadas
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

