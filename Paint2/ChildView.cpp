
// ChildView.cpp: implementación de la clase CChildView
//

#include "pch.h"
#include "framework.h"
#include "Paint2.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// Controladores de mensajes de CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // Contexto de dispositivo para dibujo
	
	// TODO: agregue aquí su código de controlador de mensajes
	
	dib.Desplegar(&dc);
	// No llamar a CWnd::OnPaint() para dibujar mensajes
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado

	fig = new Rectangulo(point);
	dib.Agregar(fig);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado
	if ((nFlags & MK_LBUTTON) != 0)
	{
		fig->Ajustar(point);
		RedrawWindow();
	}	
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado
	fig = nullptr;
}
