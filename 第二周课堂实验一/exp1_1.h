
// exp1_1.h : exp1_1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cexp1_1App:
// �йش����ʵ�֣������ exp1_1.cpp
//

class Cexp1_1App : public CWinAppEx
{
public:
	Cexp1_1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cexp1_1App theApp;
