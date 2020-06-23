
// exp0_3View.cpp : Cexp0_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp0_3.h"
#endif

#include "exp0_3Doc.h"
#include "exp0_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp0_3View

IMPLEMENT_DYNCREATE(Cexp0_3View, CView)

BEGIN_MESSAGE_MAP(Cexp0_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp0_3View 构造/析构

Cexp0_3View::Cexp0_3View()
{
	// TODO: 在此处添加构造代码
	u = _T("计信学院");
}

Cexp0_3View::~Cexp0_3View()
{
}

BOOL Cexp0_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp0_3View 绘制

void Cexp0_3View::OnDraw(CDC* pDC)
{
	Cexp0_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp0_3View 打印

BOOL Cexp0_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp0_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp0_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp0_3View 诊断

#ifdef _DEBUG
void Cexp0_3View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp0_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp0_3Doc* Cexp0_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp0_3Doc)));
	return (Cexp0_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp0_3View 消息处理程序


void Cexp0_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp0_3Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString t;
	t = pDoc->s + u;
	dc.TextOutW(200, 200, t);
	CView::OnLButtonDown(nFlags, point);
}
