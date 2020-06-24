
// exp2_1View.cpp : Cexp2_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp2_1.h"
#endif

#include "exp2_1Doc.h"
#include "exp2_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp2_1View

IMPLEMENT_DYNCREATE(Cexp2_1View, CView)

BEGIN_MESSAGE_MAP(Cexp2_1View, CView)
END_MESSAGE_MAP()

// Cexp2_1View 构造/析构

Cexp2_1View::Cexp2_1View()
{
	// TODO: 在此处添加构造代码

}

Cexp2_1View::~Cexp2_1View()
{
}

BOOL Cexp2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp2_1View 绘制

void Cexp2_1View::OnDraw(CDC* pDC)
{
	Cexp2_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int b = pDoc->a;
	CString w;
	w.Format(_T("%d"),b);
	pDC->TextOutW(100,200,w);
	CString s=_T("我是***");
	pDC->TextOutW(200,200,s);
}


// Cexp2_1View 诊断

#ifdef _DEBUG
void Cexp2_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp2_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp2_1Doc* Cexp2_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp2_1Doc)));
	return (Cexp2_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp2_1View 消息处理程序
