
// GTY-bs.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGTYbsApp:
// �йش����ʵ�֣������ GTY-bs.cpp
//

class CGTYbsApp : public CWinApp
{
public:
	CGTYbsApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGTYbsApp theApp;