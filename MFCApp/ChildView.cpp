
// ChildView.cpp: implementación de la clase CChildView
//

#include "pch.h"
#include "framework.h"
#include "MFCApp.h"
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
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
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
	
	// No llamar a CWnd::OnPaint() para dibujar mensajes
	
	// MessageBox(_T("Mostrar contenido"), _T("Mensaje"), MB_OK);

	dc.TextOutW(200, 200, _T("Hola Mundo"));
	for (int i = 0; i < 800; i+= 20) 
	{
		dc.MoveTo(0, 800 -i);
		dc.LineTo(i, 0);
	}
}





void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado

	switch (nChar)
	{
	case VK_LEFT: ph.x -= 10; RedrawWindow();  break;
	case VK_RIGHT: ph.x += 10; RedrawWindow();  break;
	case VK_UP: ph.x -= 10; RedrawWindow();  break;
	case VK_DOWN: ph.x += 10; RedrawWindow();  break;
	}
}



void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado
	if ((nFlags & MK_LBUTTON) != 0)
	{

	}

}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Agregue aquí su código de controlador de mensajes o llame al valor predeterminado
	// ph = point;
	// RedrawWindow();

	CDC* dc = GetDC();
	dc->SelectStockObject(BLACK_BRUSH);
	dc->Ellipse(point.x - 15, point.y - 15, point.x + 15, point.y + 15);
	ReleaseDC(dc);
}
