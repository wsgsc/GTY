
// GTY-bsDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CGTYbsDlg 对话框
class CGTYbsDlg : public CDialogEx
{
// 构造
public:
	CGTYbsDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GTYBS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
