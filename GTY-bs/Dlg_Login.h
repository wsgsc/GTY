#pragma once
#include "afxwin.h"


// CDlg_Login 对话框

class CDlg_Login : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_Login)

public:
	CDlg_Login(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg_Login();

// 对话框数据
	enum { IDD = IDD_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit et_user;
	CEdit et_pass;
	CString m_user;
	CString m_pass;
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedCancel();
};
