#include "StdAfx.h"
#include "AdoConn.h"


CAdoConn::CAdoConn(void)
{
}


CAdoConn::~CAdoConn(void)
{
}


int CAdoConn::GetRecordCount(){
	try{
		int n=m_pRecordset->GetRecordCount();
		return n;
	}
	catch(_com_error	e)
	{

		e.Description();
	}

	return -1;
}


_RecordsetPtr& CAdoConn::GetRecordSet(BSTR bstrSQL){
	try{
		if(m_pConnection==NULL)
		{
			OnInitADOConn(path);
		}

		m_pRecordset.CreateInstance(_uuidof(Recordset));
		m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
		m_pRecordset->Open(bstrSQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}catch(_com_error e)
	{
		e.Description();
	}

	return m_pRecordset;
}
bool CAdoConn::OnInitADOConn(CString path){
	//初始化OLE/COM 库环境
	try{
		m_pConnection.CreateInstance(_uuidof(Connection));
		m_pRecordset.CreateInstance(_uuidof(Recordset));
		this->path=path;
		  CString tmp;
	  tmp.Format("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s",path);
		_bstr_t strConnect=(_bstr_t) tmp;
	

		HRESULT IRet=m_pConnection->Open(strConnect,"","",adModeUnknown);
		if(IRet==0)
		{
			TRACE("\n secc \n");
		}
		return true;

	}catch(_com_error e)
	{
		AfxMessageBox("数据库连接失败!请确认数据库是否丢失!");
		return false;
	}
}
void CAdoConn::ExitConnect(){
	//关闭记录集
	if(m_pRecordset!=NULL){
		m_pRecordset->Close();
	}

	m_pConnection->Close();

	::CoUninitialize();
}

CString CAdoConn::GetAppDir(){
	HMODULE module = GetModuleHandle(0); 
	char pFileName[MAX_PATH]; 
	GetModuleFileName(module, pFileName, MAX_PATH); 

	CString csFullPath(pFileName); 
	int nPos = csFullPath.ReverseFind( _T('\\') ); 
	if( nPos < 0 ) 
		return CString(""); 
	else 
		return csFullPath.Left( nPos ); 
	}
BOOL CAdoConn::ExecuteSQL(_bstr_t	bstrSQL){
	_variant_t RecordsAffected;
	try{
		if(m_pConnection==NULL){
			OnInitADOConn(path);
		}
		m_pConnection->Execute(bstrSQL,NULL,adCmdText);
	}catch(_com_error e)
	{

		e.Description();
		return FALSE;
	}

	return true;
}