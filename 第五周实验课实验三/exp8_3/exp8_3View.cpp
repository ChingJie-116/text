
// exp8_3View.cpp : Cexp8_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp8_3.h"
#endif

#include "exp8_3Doc.h"
#include "exp8_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp8_3View

IMPLEMENT_DYNCREATE(Cexp8_3View, CView)

BEGIN_MESSAGE_MAP(Cexp8_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DRAWLINE, &Cexp8_3View::OnDrawline)
	ON_COMMAND(ID_DRAWRECTANGLE, &Cexp8_3View::OnDrawrectangle)
	ON_COMMAND(ID_DRAWELLIPSE, &Cexp8_3View::OnDrawellipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cexp8_3View 构造/析构

Cexp8_3View::Cexp8_3View()
{
	// TODO: 在此处添加构造代码
	i = 0;
	
}

Cexp8_3View::~Cexp8_3View()
{
}

BOOL Cexp8_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp8_3View 绘制

void Cexp8_3View::OnDraw(CDC* pDC)
{
	Cexp8_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPoint point;
	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->rect);
	pDC->Ellipse(pDoc->circle);
	pDC->MoveTo(pDoc->point1);
	pDC->LineTo(pDoc->point2);
}


// Cexp8_3View 打印

BOOL Cexp8_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp8_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp8_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp8_3View 诊断

#ifdef _DEBUG
void Cexp8_3View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp8_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp8_3Doc* Cexp8_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp8_3Doc)));
	return (Cexp8_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp8_3View 消息处理程序


void Cexp8_3View::OnDrawline()
{
	// TODO: 在此添加命令处理程序代码
	Cexp8_3Doc* pDoc = GetDocument();
	pDoc->n = 1;
	
	
}


void Cexp8_3View::OnDrawrectangle()
{
	// TODO: 在此添加命令处理程序代码
	Cexp8_3Doc* pDoc = GetDocument();
	pDoc->n = 3;
	
	
}


void Cexp8_3View::OnDrawellipse()
{
	// TODO: 在此添加命令处理程序代码
	Cexp8_3Doc* pDoc = GetDocument();
	pDoc->n = 2;
	
}


void Cexp8_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp8_3Doc* pDoc = GetDocument();
	if (pDoc->n == 1) {
		pDoc->point1.x = point.x;
		pDoc->point1.y = point.y;

	}
	if (pDoc->n == 3) {
		pDoc->rect.left = point.x;
		pDoc->rect.top = point.y;
	}
	if (pDoc->n == 2) {
		pDoc->circle.left = point.x;
		pDoc->circle.top = point.y;
	}
	

	CView::OnLButtonDown(nFlags, point);
}


void Cexp8_3View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp8_3Doc* pDoc = GetDocument();
	pDoc->a.x = point.x;
	pDoc->a.y = point.y;
	CClientDC dc(this);
	CString s;
	s.Format(_T("鼠标的位置是：%d,%d"), pDoc->a.x, pDoc->a.y);
	dc.TextOutW(20, 20, s);
	CView::OnMouseMove(nFlags, point);
}


void Cexp8_3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp8_3Doc* pDoc = GetDocument();
	if (pDoc->n == 1) {
		pDoc->point2.x = point.x;
		pDoc->point2.y = point.y;
	}
	if (pDoc->n == 3) {
		pDoc->rect.right = point.x;
		pDoc->rect.bottom = point.y;
	}
	if (pDoc->n == 2) {
		pDoc->circle.right = point.x;
		pDoc->circle.bottom = point.y;
	}
	Invalidate();
	
	CView::OnLButtonUp(nFlags, point);
}
