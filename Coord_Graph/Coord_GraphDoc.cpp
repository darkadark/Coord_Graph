
// Coord_GraphDoc.cpp: реализация класса CCoordGraphDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Coord_Graph.h"
#endif

#include "Coord_GraphDoc.h"

#include <propkey.h>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCoordGraphDoc

IMPLEMENT_DYNCREATE(CCoordGraphDoc, CDocument)

BEGIN_MESSAGE_MAP(CCoordGraphDoc, CDocument)
	ON_COMMAND(ID_COORDINATEDESCENT, &CCoordGraphDoc::OnCoordinatedescent)
	ON_COMMAND(ID_RANDOMSEARCH, &CCoordGraphDoc::OnRandomsearch)
END_MESSAGE_MAP()


// Создание или уничтожение CCoordGraphDoc

CCoordGraphDoc::CCoordGraphDoc() noexcept
	:i(0), res(NULL), l(NULL), r(NULL), path(NULL), f(nullptr), multdim_opt(nullptr), stop_crit(nullptr)
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CCoordGraphDoc::~CCoordGraphDoc()
{
	if (res.size() > 0)
		res.clear();
	if (l.size() > 0)
		l.clear();
	if (r.size() > 0)
		r.clear();
	if (path.size() > 0)
		path.clear();

	if (stop_crit != nullptr) {
		delete stop_crit;
	}

	if (multdim_opt != nullptr) {
		delete multdim_opt;
	}
}

BOOL CCoordGraphDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	i = 0;
	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}


int CCoordGraphDoc::GetI() {
	return i;
}

std::vector<double> CCoordGraphDoc::GetRes() {
	return res;
}

std::vector<double> CCoordGraphDoc::GetLB() {
	return l;
}

std::vector<double> CCoordGraphDoc::GetRB() {
	return r;
}

std::vector<std::vector<double>> CCoordGraphDoc::GetPATH() {
	return path;
}

func* CCoordGraphDoc::GetF() {
	return f.get();
}

// Сериализация CCoordGraphDoc

void CCoordGraphDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CCoordGraphDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CCoordGraphDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CCoordGraphDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CCoordGraphDoc

#ifdef _DEBUG
void CCoordGraphDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCoordGraphDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CCoordGraphDoc


void CCoordGraphDoc::OnCoordinatedescent()
{
	i = 1;
	if (det.DoModal() == IDOK) {
		
		switch (det.m_func) {
		case 0:
			f = std::make_unique<f1>();
			break;
		case 1:
			f = std::make_unique<f2>();
			break;
		}

		CStringA sx_str(det.m_start_x);
		const char* sx = sx_str;

		CStringA sy_str(det.m_start_y);
		const char* sy = sy_str;

		std::vector<double> x_0(2);
		x_0[0] = atof(sx);
		x_0[1] = atof(sy);

		if (l.size() > 0)
			l.clear();
		if (r.size() > 0)
			r.clear();


		CStringA lx_str(det.m_left_x);
		const char* lx = lx_str;

		CStringA ly_str(det.m_left_y);
		const char* ly = ly_str;
	
		l.push_back(atof(lx));
		l.push_back(atof(ly));

		CStringA rx_str(det.m_right_x);
		const char* rx = rx_str;

		CStringA ry_str(det.m_right_y);
		const char* ry = ry_str;
		r.push_back(atof(rx));
		r.push_back(atof(ry));

		if (stop_crit != nullptr) {
			delete stop_crit;
		}
		switch (det.m_crit)
		{
		case 0:
			stop_crit = new StopCriterionByYEps(0.0001);
			break;
		case 1:
			stop_crit = new StopCriterionByXEps(0.0001);
			break;
		case 2: {
			stop_crit = new StopCriterionByN(1000);
			break;}
		}
		
		if (multdim_opt != nullptr) {
			delete multdim_opt;
		}
		if (path.size() > 0)
			path.clear();

		multdim_opt = new DetermineSearch(*f, r, l, *stop_crit, new TernarySearch(0.0001));
		res = multdim_opt->Optimize(x_0, path);
		
		UpdateAllViews(0);
	}
}




void CCoordGraphDoc::OnRandomsearch()
{
	i = 2;
	if (rand.DoModal() == IDOK) {

		CStringA p_str(rand.m_p);
		const char* p = p_str;

		CStringA delta_str(rand.m_start_x);
		const char* delta = delta_str;

		switch (rand.m_func) {
		case 0:
			f = std::make_unique<f1>();
			break;
		case 1:
			f = std::make_unique<f2>();
			break;
		}

		CStringA sx_str(rand.m_start_x);
		const char* sx = sx_str;

		CStringA sy_str(rand.m_start_y);
		const char* sy = sy_str;

		std::vector<double> x_0(2);
		x_0[0] = atof(sx);
		x_0[1] = atof(sy);

		if (l.size() > 0)
			l.clear();
		if (r.size() > 0)
			r.clear();


		CStringA lx_str(rand.m_left_x);
		const char* lx = lx_str;

		CStringA ly_str(rand.m_left_y);
		const char* ly = ly_str;

		l.push_back(atof(lx));
		l.push_back(atof(ly));

		CStringA rx_str(rand.m_right_x);
		const char* rx = rx_str;

		CStringA ry_str(rand.m_right_y);
		const char* ry = ry_str;
		r.push_back(atof(rx));
		r.push_back(atof(ry));


		if (stop_crit != nullptr) {
			delete stop_crit;
		}
		switch (rand.m_crit)
		{
		case 0:
			stop_crit = new StopCriterionByYEps(0.0001);
			break;
		case 1:
			stop_crit = new StopCriterionByXEps(0.0001);
			break;
		case 2: {
			stop_crit = new StopCriterionByN(1000);
			break;}
		}

		if (path.size() > 0)
			path.clear();

		if (multdim_opt != nullptr) {
			delete multdim_opt;
		}

		multdim_opt = new RandomSearch(*f, r, l, atof(p), atof(delta), *stop_crit);
		res = multdim_opt->Optimize(x_0, path);
		
		

		UpdateAllViews(0);
	}
	

}
