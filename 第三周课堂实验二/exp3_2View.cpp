
// exp3_2View.cpp : Cexp3_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp3_2.h"
#endif

#include "exp3_2Doc.h"
#include "exp3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp3_2View

IMPLEMENT_DYNCREATE(Cexp3_2View, CView)

BEGIN_MESSAGE_MAP(Cexp3_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp3_2View ����/����

Cexp3_2View::Cexp3_2View()
{
	// TODO: �ڴ˴���ӹ������
	ca.SetSize(256);
}

Cexp3_2View::~Cexp3_2View()
{
}

BOOL Cexp3_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp3_2View ����

void Cexp3_2View::OnDraw(CDC* pDC)
{
	Cexp3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca.GetAt(i));

}


// Cexp3_2View ��ӡ

BOOL Cexp3_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp3_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp3_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp3_2View ���

#ifdef _DEBUG
void Cexp3_2View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp3_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp3_2Doc* Cexp3_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp3_2Doc)));
	return (Cexp3_2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp3_2View ��Ϣ�������


void Cexp3_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int a = rand() % 50 + 5;
	int b = rand() % 100 + 10;
	CRect cr(point.x-a,point.y-b,point.x+a,point.y+b);
	ca.Add(cr);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
