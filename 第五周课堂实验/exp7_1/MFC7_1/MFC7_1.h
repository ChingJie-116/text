
// MFC7_1.h : MFC7_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC7_1App:
// �йش����ʵ�֣������ MFC7_1.cpp
//

class CMFC7_1App : public CWinAppEx
{
public:
	CMFC7_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC7_1App theApp;
