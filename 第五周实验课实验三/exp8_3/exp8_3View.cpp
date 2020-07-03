
// exp8_3View.cpp : Cexp8_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// Cexp8_3View ����/����

Cexp8_3View::Cexp8_3View()
{
	// TODO: �ڴ˴���ӹ������
	i = 0;
	
}

Cexp8_3View::~Cexp8_3View()
{
}

BOOL Cexp8_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp8_3View ����

void Cexp8_3View::OnDraw(CDC* pDC)
{
	Cexp8_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPoint point;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->rect);
	pDC->Ellipse(pDoc->circle);
	pDC->MoveTo(pDoc->point1);
	pDC->LineTo(pDoc->point2);
}


// Cexp8_3View ��ӡ

BOOL Cexp8_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp8_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp8_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp8_3View ���

#ifdef _DEBUG
void Cexp8_3View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp8_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp8_3Doc* Cexp8_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp8_3Doc)));
	return (Cexp8_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp8_3View ��Ϣ�������


void Cexp8_3View::OnDrawline()
{
	// TODO: �ڴ���������������
	Cexp8_3Doc* pDoc = GetDocument();
	pDoc->n = 1;
	
	
}


void Cexp8_3View::OnDrawrectangle()
{
	// TODO: �ڴ���������������
	Cexp8_3Doc* pDoc = GetDocument();
	pDoc->n = 3;
	
	
}


void Cexp8_3View::OnDrawellipse()
{
	// TODO: �ڴ���������������
	Cexp8_3Doc* pDoc = GetDocument();
	pDoc->n = 2;
	
}


void Cexp8_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp8_3Doc* pDoc = GetDocument();
	pDoc->a.x = point.x;
	pDoc->a.y = point.y;
	CClientDC dc(this);
	CString s;
	s.Format(_T("����λ���ǣ�%d,%d"), pDoc->a.x, pDoc->a.y);
	dc.TextOutW(20, 20, s);
	CView::OnMouseMove(nFlags, point);
}


void Cexp8_3View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
