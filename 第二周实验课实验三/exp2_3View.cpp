
// exp2_3View.cpp : Cexp2_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp2_3.h"
#endif

#include "exp2_3Doc.h"
#include "exp2_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp2_3View

IMPLEMENT_DYNCREATE(Cexp2_3View, CView)

BEGIN_MESSAGE_MAP(Cexp2_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_RBUTTONDOWN()
ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp2_3View 构造/析构

Cexp2_3View::Cexp2_3View()
{
	// TODO: 在此处添加构造代码

}

Cexp2_3View::~Cexp2_3View()
{
}

BOOL Cexp2_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp2_3View 绘制

void Cexp2_3View::OnDraw(CDC* /*pDC*/)
{
	Cexp2_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp2_3View 打印

BOOL Cexp2_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp2_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp2_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp2_3View 诊断

#ifdef _DEBUG
void Cexp2_3View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp2_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp2_3Doc* Cexp2_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp2_3Doc)));
	return (Cexp2_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp2_3View 消息处理程序





void Cexp2_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp2_3Doc* pDoc = GetDocument();
	pDoc->count += 1;
	
	CView::OnLButtonDown(nFlags, point);
}


void Cexp2_3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp2_3Doc* pDoc = GetDocument();
	CString s;
	CClientDC dc(this);
	s.Format(_T("(%d)"), pDoc->count);
	dc.TextOutW(400, 200, s);
	CView::OnRButtonDown(nFlags, point);
}
