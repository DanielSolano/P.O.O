
// MFCApp.h: archivo de encabezado principal para la aplicación MFCApp
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'pch.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"       // Símbolos principales


// CMFCAppApp:
// Consulte MFCApp.cpp para obtener información sobre la implementación de esta clase
//

class CMFCAppApp : public CWinApp
{
public:
	CMFCAppApp() noexcept;


// Reemplazos
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementación

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCAppApp theApp;
