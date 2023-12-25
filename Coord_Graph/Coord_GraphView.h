
// Coord_GraphView.h: интерфейс класса CCoordGraphView
//

#pragma once


class CCoordGraphView : public CView
{
protected: // создать только из сериализации
	CCoordGraphView() noexcept;
	DECLARE_DYNCREATE(CCoordGraphView)

// Атрибуты
public:
	CCoordGraphDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Реализация
public:
	virtual ~CCoordGraphView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в Coord_GraphView.cpp
inline CCoordGraphDoc* CCoordGraphView::GetDocument() const
   { return reinterpret_cast<CCoordGraphDoc*>(m_pDocument); }
#endif

