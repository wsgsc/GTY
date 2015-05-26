
// GTY-bsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GTY-bs.h"
#include "GTY-bsDlg.h"
#include "afxdialogex.h"
#include "Dlg_Login.h"
#include "AdoConn.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int INDEX;
CString USER;
int OLD;
double HIGHT;
double WEIGHT;
CString WORK;
CString NAME;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGTYbsDlg 对话框




CGTYbsDlg::CGTYbsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGTYbsDlg::IDD, pParent)
	, m_hight(0)
	, m_old(0)
	, m_weight(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGTYbsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, et_name);
	DDX_Control(pDX, IDC_EDIT4, et_hight);
	DDX_Control(pDX, IDC_EDIT2, et_old);
	DDX_Control(pDX, IDC_EDIT5, et_weight);
	DDX_Control(pDX, IDC_EDIT3, et_work);
	DDX_Text(pDX, IDC_EDIT4, m_hight);
	DDV_MinMaxFloat(pDX, m_hight, 1, 3);
	DDX_Text(pDX, IDC_EDIT2, m_old);
	DDV_MinMaxInt(pDX, m_old, 1, 120);
	DDX_Text(pDX, IDC_EDIT5, m_weight);
}

BEGIN_MESSAGE_MAP(CGTYbsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CGTYbsDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CGTYbsDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CGTYbsDlg 消息处理程序

BOOL CGTYbsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CString tmp;
	//启动登陆
	CDlg_Login dlg_login;
	dlg_login.DoModal();
	

	//登陆判断  INDEX
	switch(INDEX)
	{
	case 0: //系统管理员
		tmp.Format("热烈欢迎 系统管理员登陆!");
		break;

	case 1: //总经理
		tmp.Format("热烈欢迎 总经理登陆!");
		break;

	case 2: //普通员工
		tmp.Format("欢迎 %s-普通员工登陆!",USER);
		break;


	}
	SetWindowText(tmp);

	et_name.SetWindowTextA(NAME);
	et_work.SetWindowTextA(WORK);
	tmp.Format("%.1f",HIGHT);
	et_hight.SetWindowTextA(tmp);
	tmp.Format("%.1f",WEIGHT);
	et_weight.SetWindowTextA(tmp);
	tmp.Format("%d",OLD);
	et_old.SetWindowTextA(tmp);



	//登陆成功，连接数据库


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGTYbsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGTYbsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGTYbsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGTYbsDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	CAdoConn m_ado;
	CString tmp,user,pass;
	tmp.Format("");
	m_ado.OnInitADOConn(tmp);
	CString   sql;
	sql.Format("select * from user where user ='%s' and pass='%s'");

	_RecordsetPtr m_ret=NULL;
	bool aa;

	m_ret=m_ado.GetRecordSet((_bstr_t)sql);
	
	int len=0;
	//
	while(m_ret->adoEOF==0)
	{
		len++;
		m_ret->MoveNext();
	}

	tmp.Format("%d",len);
	AfxMessageBox(tmp	);

	//
	m_ado.ExitConnect();

	//OnOK();

}


void CGTYbsDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}
