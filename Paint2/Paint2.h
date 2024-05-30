
// Paint2.h: archivo de encabezado principal para la aplicación Paint2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'pch.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"       // Símbolos principales


// CPaint2App:
// Consulte Paint2.cpp para obtener información sobre la implementación de esta clase
//

class CPaint2App : public CWinApp
{
public:
	CPaint2App() noexcept;


// Reemplazos
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementación

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPaint2App theApp;
