
// exp1_3View.cpp : Cexp1_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp1_3.h"
#endif

#include "exp1_3Doc.h"
#include "exp1_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1_3View

IMPLEMENT_DYNCREATE(Cexp1_3View, CView)

BEGIN_MESSAGE_MAP(Cexp1_3View, CView)
END_MESSAGE_MAP()

// Cexp1_3View 构造/析构

Cexp1_3View::Cexp1_3View()
{
	// TODO: 在此处添加构造代码

}

Cexp1_3View::~Cexp1_3View()
{
}

BOOL Cexp1_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp1_3View 绘制

void Cexp1_3View::OnDraw(CDC* pDC)
{
	Cexp1_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect rect;
	this->GetClientRect(rect);
	pDC->Ellipse(rect);
}


// Cexp1_3View 诊断

#ifdef _DEBUG
void Cexp1_3View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1_3Doc* Cexp1_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1_3Doc)));
	return (Cexp1_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1_3View 消息处理程序
