#pragma once
#include "afxdialogex.h"


// Диалоговое окно CDeterm

class CDeterm : public CDialogEx
{
	DECLARE_DYNAMIC(CDeterm)

public:
	CDeterm(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CDeterm();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
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
};
