// CRandom.cpp: файл реализации
//

#include "pch.h"
#include "Coord_Graph.h"
#include "afxdialogex.h"
#include "CRandom.h"


// Диалоговое окно CRandom

IMPLEMENT_DYNAMIC(CRandom, CDialogEx)

CRandom::CRandom(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_func(0)
	, m_crit(2)
	, m_start_x(L"0.5")
	, m_start_y(L"0.5")
	, m_left_x(L"0")
	, m_left_y(L"0")
	, m_right_x(L"1")
	, m_right_y(L"1")
	, m_p(L"0")
	, m_delta(L"0.001")
{

}

CRandom::~CRandom()
{
}

void CRandom::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, F1, m_func);
	DDX_Radio(pDX, CR1, m_crit);
	DDX_Text(pDX, SX, m_start_x);
	DDX_Text(pDX, SY, m_start_y);
	DDX_Text(pDX, LX, m_left_x);
	DDX_Text(pDX, LY, m_left_y);
	DDX_Text(pDX, RX, m_right_x);
	DDX_Text(pDX, RY, m_right_y);
	DDX_Text(pDX, P, m_p);
	DDX_Text(pDX, DELTA, m_delta);
	
}


BEGIN_MESSAGE_MAP(CRandom, CDialogEx)
	ON_BN_CLICKED(IDOK, &CRandom::OnBnClickedOk)
//	ON_EN_KILLFOCUS(SX, &CRandom::OnEnKillfocusSx)
//	ON_EN_KILLFOCUS(SY, &CRandom::OnEnKillfocusSy)
	ON_EN_KILLFOCUS(LX, &CRandom::OnEnKillfocusLx)
	ON_EN_KILLFOCUS(LY, &CRandom::OnEnKillfocusLy)
	ON_EN_KILLFOCUS(RX, &CRandom::OnEnKillfocusRx)
	ON_EN_KILLFOCUS(RY, &CRandom::OnEnKillfocusRy)
	ON_EN_KILLFOCUS(P, &CRandom::OnEnKillfocusP)
	ON_EN_KILLFOCUS(DELTA, &CRandom::OnEnKillfocusDelta)
	ON_EN_KILLFOCUS(SX, &CRandom::OnEnKillfocusSx)
	ON_EN_KILLFOCUS(SY, &CRandom::OnEnKillfocusSy)
END_MESSAGE_MAP()

void CRandom::OnBnClickedOk()
{
	CDialogEx::OnOK();
}


/*
void CRandom::OnEnKillfocusSx()
{
	UpdateData(1);
	CStringA s(m_start_x);
	const char* p = s;
	if (!atof(p)) {
		MessageBox(L"Incorrect value!", MB_OK);
		m_start_x = L"0";
		UpdateData(0);
		return;
	}
}


void CRandom::OnEnKillfocusSy()
{
	UpdateData(1);
	CStringA s(m_start_y);
	const char* p = s;
	if (!atof(p)) {
		MessageBox(L"Incorrect value!", MB_OK);
		m_start_y = L"0";
		UpdateData(0);
		return;
	}
}

*/

void CRandom::OnEnKillfocusLx()
{
	UpdateData(1);
	CStringA s(m_left_x);
	const char* p = s;
	if (!atof(p) && s != "0") {
		MessageBox(L"Incorrect value!", MB_OK);
		m_left_x = L"0";
		UpdateData(0);
		return;
	}
}


void CRandom::OnEnKillfocusLy()
{
	UpdateData(1);
	CStringA s(m_left_y);
	const char* p = s;
	if (!atof(p) && s != "0") {
		MessageBox(L"Incorrect value!", MB_OK);
		m_left_y = L"0";
		UpdateData(0);
		return;
	}
}


void CRandom::OnEnKillfocusRx()
{
	UpdateData(1);
	CStringA s(m_right_x);
	const char* p = s;
	if (!atof(p) && s != "0") {
		MessageBox(L"Incorrect value!", MB_OK);
		m_right_x = L"1";
		UpdateData(0);
		return;
	}
}


void CRandom::OnEnKillfocusRy()
{
	UpdateData(1);
	CStringA s(m_right_y);
	const char* p = s;
	if (!atof(p) && s != "0") {
		MessageBox(L"Incorrect value!", MB_OK);
		m_right_y = L"1";
		UpdateData(0);
		return;
	}
}



// Обработчики сообщений CRandom


void CRandom::OnEnKillfocusP()
{
	UpdateData(1);
	CStringA s(m_p);
	const char* p = s;
	if (!atof(p) && s != "0") {
		MessageBox(L"Enter a number from 0 to 1", L"Incorrect value!", MB_OK);
		m_p = L"0.5";
		UpdateData(0);
		return;
	}
	else if (atof(p) < 0 || atof(p) > 1) {
		MessageBox(L"Enter a number from 0 to 1", L"Incorrect value!", MB_OK);
		m_p = L"0.5";
		UpdateData(0);
		return;
	}

}


void CRandom::OnEnKillfocusDelta()
{
	UpdateData(1);
	CStringA s(m_delta);
	const char* p = s;
	if (!atof(p) && s != "0") {
		MessageBox(L"Incorrect value!", MB_OK);
		m_delta = L"0.001";
		UpdateData(0);
		return;
	}
	else if (atof(p) < 0 ) {
		MessageBox(L"Enter a number > 0", L"Incorrect value!", MB_OK);
		m_delta = L"0.001";
		UpdateData(0);
		return;
	}
}


void CRandom::OnEnKillfocusSx()
{
	UpdateData(1);
	CStringA s(m_start_x);
	const char* p = s;
	if (!atof(p) && s != "0") {
		MessageBox(L"Incorrect value!", MB_OK);
		m_start_x = L"0.5";
		UpdateData(0);
		return;
	}
}


void CRandom::OnEnKillfocusSy()
{
	UpdateData(1);
	CStringA s(m_start_y);
	const char* p = s;
	if (!atof(p) && s != "0") {
		MessageBox(L"Incorrect value!", MB_OK);
		m_start_y = L"0.5";
		UpdateData(0);
		return;
	}
}
