
// exp9_1View.cpp : Cexp9_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp9_1.h"
#endif

#include "exp9_1Doc.h"
#include "exp9_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp9_1View

IMPLEMENT_DYNCREATE(Cexp9_1View, CView)

BEGIN_MESSAGE_MAP(Cexp9_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &Cexp9_1View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp9_1View 构造/析构

Cexp9_1View::Cexp9_1View()
{
	// TODO: 在此处添加构造代码

}

Cexp9_1View::~Cexp9_1View()
{
}

BOOL Cexp9_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp9_1View 绘制

void Cexp9_1View::OnDraw(CDC* /*pDC*/)
{
	Cexp9_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
}


// Cexp9_1View 打印

BOOL Cexp9_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp9_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp9_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp9_1View 诊断

#ifdef _DEBUG
void Cexp9_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp9_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp9_1Doc* Cexp9_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp9_1Doc)));
	return (Cexp9_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp9_1View 消息处理程序


void Cexp9_1View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	CClientDC dc(this);
	int r = cfd.DoModal();
	if (r == IDOK) {
		CString filename=cfd.GetPathName();
		CImage img;
		img.Load(filename);
		int w, h, sx, sy; {
			CRect rect;
			GetClientRect(&rect);
			float rect_ratio = 1.0*rect.Width() / rect.Height();
			float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
			if (rect_ratio > img_ratio) {
				h = rect.Height();
				w = img_ratio*h;
				sx = (rect.Width() - w) / 2;
				sy = 0;
			}
			else {
				w = rect.Width();
				h = w / img_ratio;
				sx = 0;
				sy = (rect.Height() - h) / 2;
			}
		}
		img.Draw(dc.m_hDC,sx,sy,w,h);
	}
}
