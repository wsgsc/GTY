#pragma once
#include "afxwin.h"


// CDlg_Login �Ի���

class CDlg_Login : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_Login)

public:
	CDlg_Login(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlg_Login();

// �Ի�������
	enum { IDD = IDD_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
