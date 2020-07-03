
// exp8_1View.cpp : Cexp8_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp8_1.h"
#endif

#include "exp8_1Doc.h"
#include "exp8_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp8_1View

IMPLEMENT_DYNCREATE(Cexp8_1View, CView)

BEGIN_MESSAGE_MAP(Cexp8_1View, CView)
	ON_COMMAND(ID_SHOWNAME, &Cexp8_1View::OnShowname)
END_MESSAGE_MAP()

// Cexp8_1View 构造/析构

Cexp8_1View::Cexp8_1View()
{
	// TODO: 在此处添加构造代码

}

Cexp8_1View::~Cexp8_1View()
{
}

BOOL Cexp8_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp8_1View 绘制

void Cexp8_1View::OnDraw(CDC* /*pDC*/)
{
	Cexp8_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp8_1View 诊断

#ifdef _DEBUG
void Cexp8_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp8_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp8_1Doc* Cexp8_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp8_1Doc)));
	return (Cexp8_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp8_1View 消息处理程序


void Cexp8_1View::OnShowname()
{
	// TODO: 在此添加命令处理程序代码
	CString s = _T("蓝庆杰");
	CClientDC dc(this);
	dc.TextOutW(20, 300, s);

}
