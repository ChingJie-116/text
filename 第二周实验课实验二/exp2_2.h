
// exp2_2.h : exp2_2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cexp2_2App:
// �йش����ʵ�֣������ exp2_2.cpp
//

class Cexp2_2App : public CWinApp
{
public:
	Cexp2_2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cexp2_2App theApp;
