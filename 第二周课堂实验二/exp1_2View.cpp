
// exp1_2View.cpp : Cexp1_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp1_2.h"
#endif

#include "exp1_2Doc.h"
#include "exp1_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1_2View

IMPLEMENT_DYNCREATE(Cexp1_2View, CView)

BEGIN_MESSAGE_MAP(Cexp1_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp1_2View ����/����

Cexp1_2View::Cexp1_2View()
{
	// TODO: �ڴ˴���ӹ������
	ca.SetSize(256);
}

Cexp1_2View::~Cexp1_2View()
{
}

BOOL Cexp1_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp1_2View ����

void Cexp1_2View::OnDraw(CDC* pDC)
{
	Cexp1_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca.GetAt(i));
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp1_2View ��ӡ

BOOL Cexp1_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp1_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp1_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp1_2View ���

#ifdef _DEBUG
void Cexp1_2View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1_2Doc* Cexp1_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1_2Doc)));
	return (Cexp1_2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1_2View ��Ϣ�������


void Cexp1_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int r = rand() % 50 + 5;
	//CClientDC dc(this);
	CRect cr(point.x - r, point.y - r, point.x + r, point.y + r);
	ca.Add(cr);
	this->Invalidate();
	//dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
