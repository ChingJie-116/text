
// exp1_4View.cpp : Cexp1_4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cexp1_4View ����/����

Cexp1_4View::Cexp1_4View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp1_4View::~Cexp1_4View()
{
}

BOOL Cexp1_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp1_4View ����

void Cexp1_4View::OnDraw(CDC* pDC)
{
	Cexp1_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CClientDC dc(this);
	CBrush brush(RGB(0,255, 255));
	dc.SelectObject(&brush);
	dc.Ellipse(20,20,220,120);
}


// Cexp1_4View ��ӡ

BOOL Cexp1_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp1_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp1_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp1_4View ���

#ifdef _DEBUG
void Cexp1_4View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1_4Doc* Cexp1_4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1_4Doc)));
	return (Cexp1_4Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1_4View ��Ϣ�������
