
// Coord_GraphView.cpp: реализация класса CCoordGraphView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Coord_Graph.h"
#endif

#include "Coord_GraphDoc.h"
#include "Coord_GraphView.h"
#include "afxdrawmanager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCoordGraphView

IMPLEMENT_DYNCREATE(CCoordGraphView, CView)

BEGIN_MESSAGE_MAP(CCoordGraphView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CCoordGraphView

CCoordGraphView::CCoordGraphView() noexcept
{
	// TODO: добавьте код создания

}

CCoordGraphView::~CCoordGraphView()
{
}

BOOL CCoordGraphView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CCoordGraphView

void CCoordGraphView::OnDraw(CDC* pdc)
{
	CCoordGraphDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	
	CRect rc;
	GetClientRect(&rc);


	CBitmap bit;
	CDC pDC;
	bit.CreateCompatibleBitmap(pdc, rc.Width(), rc.Height());
	pDC.CreateCompatibleDC(pdc);
	pDC.SelectObject(&bit);
	pDC.FillSolidRect(rc, RGB(255, 255, 255));
	//CDrawingManager dm(*pDC);
	//dm.FillGradient2(rc, RGB(102, 200, 238), RGB(0, 129, 185), 45);
	
	
	int j = pDoc->GetI();

	if (j == 1 || j == 2) {
		
		std::vector<double> res = pDoc->GetRes();
		std::vector<double> l = pDoc->GetLB();
		std::vector<double> r = pDoc->GetRB();
		std::vector<std::vector<double>> path = pDoc->GetPATH();
		func* f = pDoc->GetF();
		std::vector<std::vector<double>> matrix;
		
		
		if (f != nullptr) {
			double h0 = (r[0] - l[0]) * 2/ (rc.Width() * 0.8);
			double h1 = (r[1] - l[1]) * 2/ (rc.Height() * 0.8);
			double fmin = 100;
			double fmax = -100;
			for (double k = l[0]; k < r[0]; k += h0) {
				matrix.push_back(std::vector<double>());
				for (double t = l[1]; t < r[1]; t += h1) {
					double f_val = f->operator()({ k, t });
					matrix.back().push_back(f_val);
					fmax = f_val > fmax ? f_val : fmax;
					fmin = f_val < fmin ? f_val : fmin;
				}

			}

			for (int k = 0; k < matrix.size(); ++k) {
				for (int t = 0; t < matrix[k].size(); ++t) {
					int x = rc.Width() / 10 + k*2;
					int y = rc.Height() * 0.9 - t*2;
					//pDC.SetPixel(x, y, RGB(0, 0, matrix[k][t] * 255 / (fmax - fmin)));
					pDC.FillSolidRect(x, y, 2,2, RGB(0, 0, matrix[k][t] * 255 / (fmax - fmin)));
				}
			}

		}

		

		CPen penBlack;
		penBlack.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
		CPen* pOldPen = (CPen*)pDC.SelectObject(&penBlack);

		pDC.MoveTo(rc.Width() / 10, rc.Height() / 10);
		pDC.LineTo(rc.Width() / 10, rc.Height() - rc.Height() / 10);
		pDC.MoveTo(rc.Width() / 10, rc.Height() - rc.Height() / 10);
		pDC.LineTo(rc.Width() - rc.Width() / 10, rc.Height() - rc.Height() / 10);
		
		pDC.SetBkColor(RGB(255, 255, 255));
		CString t;
		t.Format(L"(%.2f, %.2f)", l[0], l[1]);
		pDC.TextOut(rc.Width() / 10, rc.Height() - rc.Height() / 10, t);
		CString t1;
		t1.Format(L"%.2f", r[1]);
		pDC.TextOut(rc.Width() / 10, rc.Height() / 10, t1);
		CString t2;
		t2.Format(L"%.2f", r[0]);
		pDC.TextOut(rc.Width() - rc.Width() / 10, rc.Height() - rc.Height() / 10, t2);

		CString res1;
		res1.Format(L"(%.2f, %.2f)", res[0], res[1]);
		pDC.TextOut(rc.Width() / 10 + rc.Width() * 0.8 * (res[0] - l[0])/ (r[0]-l[0]), rc.Height() * 0.9 - rc.Height() * 0.8 * (res[1] - l[1]) / (r[1] - l[1]), res1);
		
		//CString size;
		//size.Format(L"%d", path.size());
		//pDC.TextOut(rc.Width() / 2, rc.Height() /2, size);

		CPen penB;
		penB.CreatePen(PS_SOLID, 2, RGB(0, 128, 0));//RGB(i*2+75, i*3+55, i*5+55));
		CPen* pOld = (CPen*)pDC.SelectObject(&penB);
		for (int i = 0; i < path.size() - 1; ++i) {
			
			pDC.MoveTo(rc.Width() / 10 + rc.Width() * 0.8 * (path[i][0] - l[0]) / (r[0] - l[0]), rc.Height() * 0.9 - rc.Height() * 0.8 * (path[i][1] - l[1]) / (r[1] - l[1]));
			pDC.LineTo(rc.Width() / 10 + rc.Width() * 0.8 * (path[i + 1][0] - l[0]) / (r[0] - l[0]), rc.Height() * 0.9 - rc.Height() * 0.8 * (path[i + 1][1] - l[1]) / (r[1] - l[1]));
			//pDC->MoveTo(rc.Width() / 10, rc.Height() / 10);
		}

		
		CString res11;
		
		if( j == 1){ pDC.TextOut(rc.Width() / 4, rc.Height() * 0.05, L" METHOD COORDINATE DESCENT"); }
		if (j == 2) { pDC.TextOut(rc.Width() / 4, rc.Height() * 0.05, L" METHOD RANDOM SEARCH"); }
		res11.Format(L"x_0 = (%.2f, %.2f)", path[0][0], path[0][1]);
		pDC.TextOut(rc.Width() /2, rc.Height() * 0.05, res11);
		pdc->BitBlt(0, 0, rc.Width(), rc.Height(), &pDC, 0, 0, SRCCOPY);
	}
	// TODO: добавьте здесь код отрисовки для собственных данных
}

void CCoordGraphView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCoordGraphView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CCoordGraphView

#ifdef _DEBUG
void CCoordGraphView::AssertValid() const
{
	CView::AssertValid();
}

void CCoordGraphView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCoordGraphDoc* CCoordGraphView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCoordGraphDoc)));
	return (CCoordGraphDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CCoordGraphView
