
// exp4_3View.cpp : Cexp4_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp4_3View ����/����

Cexp4_3View::Cexp4_3View()
{
	// TODO: �ڴ˴���ӹ������
	
}

Cexp4_3View::~Cexp4_3View()
{
}

BOOL Cexp4_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp4_3View ����

void Cexp4_3View::OnDraw(CDC*  pDC )
{
	Cexp4_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);/**/
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp4_3View ��ӡ

BOOL Cexp4_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp4_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp4_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp4_3View ���

#ifdef _DEBUG
void Cexp4_3View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp4_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp4_3Doc* Cexp4_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp4_3Doc)));
	return (Cexp4_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp4_3View ��Ϣ�������


void Cexp4_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
		v.Format(_T("�����Ч"));
		CClientDC dc(this);
		dc.TextOutW(615, 500, v);
	}
	if (point.x <= 700 && point.x >= 500 && point.y <= 200 && point.x >= 30) {
		w.Format(_T("a+b=%d"), pDoc->c);
		dc.TextOutW(600, 100, w);
	}/**/
	CView::OnLButtonDown(nFlags, point);
}
