
// exp4_3.h : exp4_3 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// Cexp4_3App:
// 有关此类的实现，请参阅 exp4_3.cpp
//

class Cexp4_3App : public CWinAppEx
{
public:
	Cexp4_3App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cexp4_3App theApp;
