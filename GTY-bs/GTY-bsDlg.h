
// GTY-bsDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CGTYbsDlg �Ի���
class CGTYbsDlg : public CDialogEx
{
// ����
public:
	CGTYbsDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GTYBS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();


	
	CEdit et_name;
	CEdit et_hight;
	CEdit et_old;
	CEdit et_weight;
	CEdit et_work;
	float m_hight;
	int m_old;
	float m_weight;
	afx_msg void OnBnClickedButton1();
};
