
// ChildView.h: interfaz de la clase CChildView
//


#pragma once


// Ventana de CChildView

class CChildView : public CWnd
{
// Construcción
public:
	CChildView();

// Atributos
public:
	CPoint ph = { 200, 200 };
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
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

