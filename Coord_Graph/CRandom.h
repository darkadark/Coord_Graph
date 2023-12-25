#pragma once
#include "afxdialogex.h"


// Диалоговое окно CRandom

class CRandom : public CDialogEx
{
	DECLARE_DYNAMIC(CRandom)

public:
	CRandom(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CRandom();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()

public:
	int m_func;
	int m_crit;
	CString m_start_x;
	CString m_start_y;
	CString m_left_x;
	CString m_left_y;
	CString m_right_x;
	CString m_right_y;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnKillfocusSx();
	afx_msg void OnEnKillfocusSy();
	afx_msg void OnEnKillfocusLx();
	afx_msg void OnEnKillfocusLy();
	afx_msg void OnEnKillfocusRx();
	afx_msg void OnEnKillfocusRy();
	CString m_p;
	CString m_delta;
	afx_msg void OnEnKillfocusP();
	afx_msg void OnEnKillfocusDelta();
};
