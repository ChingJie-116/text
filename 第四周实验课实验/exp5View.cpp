
// exp5View.cpp : Cexp5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp5.h"
#endif

#include "exp5Doc.h"
#include "exp5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp5View

IMPLEMENT_DYNCREATE(Cexp5View, CView)

BEGIN_MESSAGE_MAP(Cexp5View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cexp5View 构造/析构

Cexp5View::Cexp5View()
{
	// TODO: 在此处添加构造代码

}

Cexp5View::~Cexp5View()
{
}

BOOL Cexp5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp5View 绘制

void Cexp5View::OnDraw(CDC* pDC)
{
	Cexp5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->m_tagRec);
	

}


// Cexp5View 打印

BOOL Cexp5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp5View 诊断

#ifdef _DEBUG
void Cexp5View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp5Doc* Cexp5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp5Doc)));
	return (Cexp5Doc*)m_pDocument;
}
#endif //_DEBUG


 //Cexp5View 消息处理程序

void Cexp5View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp5Doc* pDoc = GetDocument();
	pDoc->a.x = point.x;
	pDoc->a.y = point.y;
	CClientDC dc(this);
	CString s;
	s.Format(_T("鼠标的位置是：%d,%d"),pDoc->a.x, pDoc->a.y);
	dc.TextOutW(20, 20, s);
	CView::OnMouseMove(nFlags, point);
}
void Cexp5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Cexp5Doc* pDoc = GetDocument();	 
	pDoc->m_tagRec.left = pDoc->a.x;
	pDoc->m_tagRec.top = pDoc->a.y;
	CView::OnLButtonDown(nFlags, point);
} 

void Cexp5View::OnLButtonUp(UINT nFlags, CPoint point)
 {
	 // TODO: 在此添加消息处理程序代码和/或调用默认值
	 Cexp5Doc* pDoc = GetDocument();
	 pDoc->m_tagRec.right = point.x;
	 pDoc->m_tagRec.bottom = point.y;
	 InvalidateRect(NULL, TRUE);
	 CView::OnLButtonUp(nFlags, point);
 }
