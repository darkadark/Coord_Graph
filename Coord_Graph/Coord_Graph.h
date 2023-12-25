
// Coord_Graph.h: основной файл заголовка для приложения Coord_Graph
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CCoordGraphApp:
// Сведения о реализации этого класса: Coord_Graph.cpp
//

class CCoordGraphApp : public CWinAppEx
{
public:
	CCoordGraphApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCoordGraphApp theApp;
