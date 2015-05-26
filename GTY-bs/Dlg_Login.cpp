// Dlg_Login.cpp : 实现文件
//

#include "stdafx.h"
#include "GTY-bs.h"
#include "Dlg_Login.h"
#include "afxdialogex.h"
#include "AdoConn.h"
extern int INDEX;
extern CString USER;
extern int OLD;
extern double HIGHT;
extern double WEIGHT;
extern CString WORK;
extern CString NAME;
// CDlg_Login 对话框

IMPLEMENT_DYNAMIC(CDlg_Login, CDialogEx)

CDlg_Login::CDlg_Login(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlg_Login::IDD, pParent)
{

	m_user = _T("");
	m_pass = _T("");
}

CDlg_Login::~CDlg_Login()
{
}

void CDlg_Login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, et_user);
	DDX_Control(pDX, IDC_EDIT2, et_pass);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDV_MaxChars(pDX, m_user, 255);
	DDX_Text(pDX, IDC_EDIT2, m_pass);
	DDV_MaxChars(pDX, m_pass, 255);
}


BEGIN_MESSAGE_MAP(CDlg_Login, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlg_Login::OnBnClickedOk)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDCANCEL, &CDlg_Login::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDlg_Login 消息处理程序


void CDlg_Login::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tmpu,tmpp,path,sql;
	CAdoConn mado;
	et_user.GetWindowTextA(tmpu);
	et_pass.GetWindowTextA(tmpp);
	if(tmpu=="")
	{
		AfxMessageBox("请输入用户名!");
		return;
	}

	if(tmpp=="")
	{
		AfxMessageBox("请输入密码!");
		
		return;
	}

//判断登陆是否成功
	path=mado.GetAppDir()+"\\test.mdb";
	mado.OnInitADOConn(path);
	sql.Format("select * from pass where user ='%s' and pass = '%s' ",tmpu,tmpp);
	_RecordsetPtr m_ret=NULL;
	

	m_ret=mado.GetRecordSet((_bstr_t)sql);
		_variant_t vr;
	if(m_ret->adoEOF==0)//登陆成功
	{
		INDEX=(int)m_ret->GetCollect("index");
		vr=m_ret->GetCollect("年龄");
		if(vr.vt==VT_NULL)
			OLD=0;
		else
			OLD=(int )vr;

		vr=m_ret->GetCollect("体重");
		if(vr.vt==VT_NULL)
			WEIGHT=0;
		else
			WEIGHT=(float)vr;

		vr=m_ret->GetCollect("身高");
		if(vr.vt==VT_NULL)
			HIGHT=0;
		else 
			HIGHT=(float)vr;

		vr=m_ret->GetCollect("姓名");

		if(vr.vt==VT_NULL)
			NAME.Format("");
		else
			NAME.Format("%s",(char *)(_bstr_t)vr);

		vr=m_ret->GetCollect("工作");
		if(vr.vt==VT_NULL)
			WORK.Format("");
		else
			WORK.Format("%s",(char *)(_bstr_t)vr);
		//WEIGHT=(float)m_ret->GetCollect("体重");
		//HIGHT=(float)m_ret->GetCollect(_bstr_t("身高"));
	
		//NAME.Format("%s",(char *)(_bstr_t)m_ret->GetCollect("姓名"));
		//WORK.Format("%s",(char *)(_bstr_t)m_ret->GetCollect("工作"));
		USER=tmpu;
		mado.ExitConnect();
		CDialogEx::OnOK();

	}else
	{
		mado.ExitConnect();
		
		AfxMessageBox("登陆失败");
	}
	
}


void CDlg_Login::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}


void CDlg_Login::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	exit(0);
}
