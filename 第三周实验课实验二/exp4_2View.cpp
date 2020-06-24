
// exp4_2View.cpp : Cexp4_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp4_2.h"
#endif

#include "exp4_2Doc.h"
#include "exp4_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp4_2View

IMPLEMENT_DYNCREATE(Cexp4_2View, CView)

BEGIN_MESSAGE_MAP(Cexp4_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp4_2View ����/����

Cexp4_2View::Cexp4_2View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp4_2View::~Cexp4_2View()
{
}

BOOL Cexp4_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp4_2View ����

void Cexp4_2View::OnDraw(CDC* /*pDC*/)
{
	Cexp4_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp4_2View ��ӡ

BOOL Cexp4_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp4_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp4_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp4_2View ���

#ifdef _DEBUG
void Cexp4_2View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp4_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp4_2Doc* Cexp4_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp4_2Doc)));
	return (Cexp4_2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp4_2View ��Ϣ�������


void Cexp4_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp4_2Doc* pDoc = GetDocument();
	pDoc->a;
	pDoc->b;
	CString s;
	s.Format(_T("a+b=%d"), pDoc->a + pDoc->b);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}
