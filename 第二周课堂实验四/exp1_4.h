
// exp1_4.h : exp1_4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cexp1_4App:
// �йش����ʵ�֣������ exp1_4.cpp
//

class Cexp1_4App : public CWinAppEx
{
public:
	Cexp1_4App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cexp1_4App theApp;
