
// GTY-bsDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CGTYbsDlg �Ի���




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


// CGTYbsDlg ��Ϣ�������

BOOL CGTYbsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CString tmp;
	//������½
	CDlg_Login dlg_login;
	dlg_login.DoModal();
	

	//��½�ж�  INDEX
	switch(INDEX)
	{
	case 0: //ϵͳ����Ա
		tmp.Format("���һ�ӭ ϵͳ����Ա��½!");
		break;

	case 1: //�ܾ���
		tmp.Format("���һ�ӭ �ܾ����½!");
		break;

	case 2: //��ͨԱ��
		tmp.Format("��ӭ %s-��ͨԱ����½!",USER);
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



	//��½�ɹ����������ݿ�


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGTYbsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CGTYbsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGTYbsDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
