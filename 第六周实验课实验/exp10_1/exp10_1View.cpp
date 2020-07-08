
// exp10_1View.cpp : Cexp10_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp10_1.h"
#endif

#include "exp10_1Doc.h"
#include "exp10_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp10_1View

IMPLEMENT_DYNCREATE(Cexp10_1View, CView)

BEGIN_MESSAGE_MAP(Cexp10_1View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// Cexp10_1View 构造/析构

Cexp10_1View::Cexp10_1View()
{
	// TODO: 在此处添加构造代码
	/*cr.left = 100;
	cr.top = 160;
	cr.right = 400;
	cr.bottom = 600;*/
}

Cexp10_1View::~Cexp10_1View()
{
}

BOOL Cexp10_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp10_1View 绘制

void Cexp10_1View::OnDraw(CDC* pDC/**/)
{
	Cexp10_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
//	pDC->Rectangle(&cr);
	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp10_1View 诊断

#ifdef _DEBUG
void Cexp10_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp10_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp10_1Doc* Cexp10_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp10_1Doc)));
	return (Cexp10_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp10_1View 消息处理程序
int Cexp10_1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
    // TODO:  在此添加您专用的创建代码
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight);
	ShowCaret();
	
	return 0;
}

void Cexp10_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point);
	m_str.Empty();
	m_point = point;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp10_1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	if (0x0d == nChar) {
		m_str.Empty();
		m_point.y += tm.tmHeight;
	}
	else {
		m_str += TCHAR(nChar);
	}
	CSize cz = dc.GetTextExtent(m_str);
	CPoint pt;
	pt.x = m_point.x + cz.cx;
	pt.y = m_point.y;
	SetCaretPos(pt);
	dc.TextOutW(m_point.x, m_point.y, m_str);
	CView::OnChar(nChar, nRepCnt, nFlags);
}




