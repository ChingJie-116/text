
// exp4_3View.cpp : Cexp4_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp4_3.h"
#endif

#include "exp4_3Doc.h"
#include "exp4_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp4_3View

IMPLEMENT_DYNCREATE(Cexp4_3View, CView)

BEGIN_MESSAGE_MAP(Cexp4_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp4_3View 构造/析构

Cexp4_3View::Cexp4_3View()
{
	// TODO: 在此处添加构造代码
	
}

Cexp4_3View::~Cexp4_3View()
{
}

BOOL Cexp4_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp4_3View 绘制

void Cexp4_3View::OnDraw(CDC*  pDC )
{
	Cexp4_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);/**/
	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp4_3View 打印

BOOL Cexp4_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp4_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp4_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp4_3View 诊断

#ifdef _DEBUG
void Cexp4_3View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp4_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp4_3Doc* Cexp4_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp4_3Doc)));
	return (Cexp4_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp4_3View 消息处理程序


void Cexp4_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp4_3Doc* pDoc = GetDocument();
	CClientDC dc(this);
	
    CString s,u,v,w;
	if (point.x<=200&& point.x>= 30&& point.y <= 200 && point.x >= 30) {
		s.Format(_T("%d"), pDoc->a);	
		dc.TextOutW(100,100, s);
	}
	if (point.x <= 450 && point.x >= 250&& point.y <= 200 && point.x >= 30) {
		u.Format(_T("%d"), pDoc->b);
		dc.TextOutW(300, 100, u);
	}
	if (point.x <= 30 || point.x >= 450 && point.y <= 30 || point.y >= 200) {
		v.Format(_T("点击无效"));
		CClientDC dc(this);
		dc.TextOutW(615, 500, v);
	}
	if (point.x <= 700 && point.x >= 500 && point.y <= 200 && point.x >= 30) {
		w.Format(_T("a+b=%d"), pDoc->c);
		dc.TextOutW(600, 100, w);
	}/**/
	CView::OnLButtonDown(nFlags, point);
}
