
// exp3_1View.cpp : Cexp3_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp3_1.h"
#endif

#include "exp3_1Doc.h"
#include "exp3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp3_1View

IMPLEMENT_DYNCREATE(Cexp3_1View, CView)

BEGIN_MESSAGE_MAP(Cexp3_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp3_1View ����/����

Cexp3_1View::Cexp3_1View()
{
	// TODO: �ڴ˴���ӹ������
	ca.SetSize(256);
}

Cexp3_1View::~Cexp3_1View()
{
}

BOOL Cexp3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp3_1View ����

void Cexp3_1View::OnDraw(CDC* pDC)
{
	Cexp3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
}


// Cexp3_1View ��ӡ

BOOL Cexp3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp3_1View ���

#ifdef _DEBUG
void Cexp3_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp3_1Doc* Cexp3_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp3_1Doc)));
	return (Cexp3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp3_1View ��Ϣ�������


void Cexp3_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect cr;
	this->GetClientRect(&cr);
	int x = cr.Width() / 2;
	int y = cr.Height() / 2;
	int r;
	if (x < y)r = x;
	else r = y;
	CClientDC dc(this);
	dc.Ellipse(x - r, y - r, x + r, y + r);
	CView::OnLButtonDown(nFlags, point);
}
