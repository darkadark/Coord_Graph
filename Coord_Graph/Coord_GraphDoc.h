
// Coord_GraphDoc.h: интерфейс класса CCoordGraphDoc 
//


#pragma once
#include "CDeterm.h"
#include "CRandom.h"
#include <vector>
#include "Optimization.h"
#include "Functions.h"
#include <iostream>

class CCoordGraphDoc : public CDocument
{
protected: // создать только из сериализации
	CCoordGraphDoc() noexcept;
	DECLARE_DYNCREATE(CCoordGraphDoc)

// Атрибуты
public:

// Операции
public:
	virtual int GetI();
	virtual std::vector<double> CCoordGraphDoc::GetRes();
	virtual std::vector<double> CCoordGraphDoc::GetLB();
	virtual std::vector<double> CCoordGraphDoc::GetRB();
	std::vector<std::vector<double>> CCoordGraphDoc::GetPATH();
	func* CCoordGraphDoc::GetF();

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CCoordGraphDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int i;
	CDeterm det;
	CRandom rand;
	std::vector<double> res;
	std::vector<double> l;
	std::vector<double> r;
	std::vector<std::vector<double>> path;
	std::unique_ptr<func> f;
	MultdimOpt* multdim_opt;
	StopCriterion* stop_crit;
// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnCoordinatedescent();
	afx_msg void OnRandomsearch();
};
