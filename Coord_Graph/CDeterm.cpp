// CDeterm.cpp: файл реализации
//

#include "pch.h"
#include "Coord_Graph.h"
#include "afxdialogex.h"
#include "CDeterm.h"


// Диалоговое окно CDeterm

IMPLEMENT_DYNAMIC(CDeterm, CDialogEx)

CDeterm::CDeterm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_func(0)
	, m_crit(0)
	, m_start_x(L"0.5")
	, m_start_y(L"0.5")
	, m_left_x(L"0")
	, m_left_y(L"0")
	, m_right_x(L"1")
	, m_right_y(L"1")
{

}

CDeterm::~CDeterm()
{
}

void CDeterm::DoDataExchange(CDataExchange* pDX)
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
}


BEGIN_MESSAGE_MAP(CDeterm, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDeterm::OnBnClickedOk)
	ON_EN_KILLFOCUS(SX, &CDeterm::OnEnKillfocusSx)
	ON_EN_KILLFOCUS(SY, &CDeterm::OnEnKillfocusSy)
	ON_EN_KILLFOCUS(LX, &CDeterm::OnEnKillfocusLx)
	ON_EN_KILLFOCUS(LY, &CDeterm::OnEnKillfocusLy)
	ON_EN_KILLFOCUS(RX, &CDeterm::OnEnKillfocusRx)
	ON_EN_KILLFOCUS(RY, &CDeterm::OnEnKillfocusRy)
END_MESSAGE_MAP()


// Обработчики сообщений CDeterm


void CDeterm::OnBnClickedOk()
{
	CDialogEx::OnOK();
}




void CDeterm::OnEnKillfocusSx()
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


void CDeterm::OnEnKillfocusSy()
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


void CDeterm::OnEnKillfocusLx()
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


void CDeterm::OnEnKillfocusLy()
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


void CDeterm::OnEnKillfocusRx()
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


void CDeterm::OnEnKillfocusRy()
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


