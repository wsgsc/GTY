#pragma once

class CAdoConn
{
public:
	CAdoConn(void);
	~CAdoConn(void);


public:
	_ConnectionPtr  m_pConnection;
	_RecordsetPtr m_pRecordset;
	

	int GetRecordCount();
	_RecordsetPtr& GetRecordSet(BSTR bstrSQL);
	bool OnInitADOConn(CString path);
	void ExitConnect();
	BOOL ExecuteSQL(_bstr_t	bstrSQL);
	CString GetAppDir();
	CString path;
};

