
// exp1_4View.cpp : Cexp1_4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp1_4.h"
#endif

#include "exp1_4Doc.h"
#include "exp1_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1_4View

IMPLEMENT_DYNCREATE(Cexp1_4View, CView)

BEGIN_MESSAGE_MAP(Cexp1_4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cexp1_4View 构造/析构

Cexp1_4View::Cexp1_4View()
{
	// TODO: 在此处添加构造代码

}

Cexp1_4View::~Cexp1_4View()
{
}

BOOL Cexp1_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp1_4View 绘制

void Cexp1_4View::OnDraw(CDC* pDC)
{
	Cexp1_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CClientDC dc(this);
	CBrush brush(RGB(0,255, 255));
	dc.SelectObject(&brush);
	dc.Ellipse(20,20,220,120);
}


// Cexp1_4View 打印

BOOL Cexp1_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp1_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp1_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp1_4View 诊断

#ifdef _DEBUG
void Cexp1_4View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1_4Doc* Cexp1_4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1_4Doc)));
	return (Cexp1_4Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1_4View 消息处理程序
