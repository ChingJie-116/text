
// MFC7_1View.cpp : CMFC7_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC7_1.h"
#endif

#include "MFC7_1Doc.h"
#include "MFC7_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC7_1View

IMPLEMENT_DYNCREATE(CMFC7_1View, CView)

BEGIN_MESSAGE_MAP(CMFC7_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOWCIRCLE, &CMFC7_1View::OnShowcircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC7_1View 构造/析构

CMFC7_1View::CMFC7_1View()
{
	// TODO: 在此处添加构造代码
	r = 0;
	set = true;

}

CMFC7_1View::~CMFC7_1View()
{
}

BOOL CMFC7_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC7_1View 绘制

void CMFC7_1View::OnDraw(CDC* pDC)
{
	CMFC7_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	if (n = 1) {
		if (set) {
			SetTimer(1, 100, NULL);
			set = false;
		}
		this->GetClientRect(&cr);
		int x = cr.Width() / 2;
		int y = cr.Height() / 2;
        pDC->Ellipse(x - r, y - r, x + r, y + r);
	}
	
}


// CMFC7_1View 打印

BOOL CMFC7_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC7_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC7_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC7_1View 诊断

#ifdef _DEBUG
void CMFC7_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC7_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC7_1Doc* CMFC7_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC7_1Doc)));
	return (CMFC7_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC7_1View 消息处理程序


void CMFC7_1View::OnShowcircle()
{
	// TODO: 在此添加命令处理程序代码
	n = 1;
}


void CMFC7_1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	  r++;
	  Invalidate();
	CView::OnTimer(nIDEvent);
}
