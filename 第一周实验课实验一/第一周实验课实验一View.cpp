
// ��һ��ʵ���ʵ��һView.cpp : C��һ��ʵ���ʵ��һView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��һ��ʵ���ʵ��һ.h"
#endif

#include "��һ��ʵ���ʵ��һDoc.h"
#include "��һ��ʵ���ʵ��һView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��һ��ʵ���ʵ��һView

IMPLEMENT_DYNCREATE(C��һ��ʵ���ʵ��һView, CView)

BEGIN_MESSAGE_MAP(C��һ��ʵ���ʵ��һView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C��һ��ʵ���ʵ��һView ����/����

C��һ��ʵ���ʵ��һView::C��һ��ʵ���ʵ��һView()
{
	// TODO: �ڴ˴���ӹ������

}

C��һ��ʵ���ʵ��һView::~C��һ��ʵ���ʵ��һView()
{
}

BOOL C��һ��ʵ���ʵ��һView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��һ��ʵ���ʵ��һView ����

void C��һ��ʵ���ʵ��һView::OnDraw(CDC* pDC)
{
	C��һ��ʵ���ʵ��һDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
}


// C��һ��ʵ���ʵ��һView ��ӡ

BOOL C��һ��ʵ���ʵ��һView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��һ��ʵ���ʵ��һView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��һ��ʵ���ʵ��һView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��һ��ʵ���ʵ��һView ���

#ifdef _DEBUG
void C��һ��ʵ���ʵ��һView::AssertValid() const
{
	CView::AssertValid();
}

void C��һ��ʵ���ʵ��һView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��һ��ʵ���ʵ��һDoc* C��һ��ʵ���ʵ��һView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��һ��ʵ���ʵ��һDoc)));
	return (C��һ��ʵ���ʵ��һDoc*)m_pDocument;
}
#endif //_DEBUG


// C��һ��ʵ���ʵ��һView ��Ϣ�������


void C��һ��ʵ���ʵ��һView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C��һ��ʵ���ʵ��һDoc* pDoc = GetDocument();
	CClientDC dc(this);
	dc.TextOutW(200, 200, pDoc->s);
	CView::OnLButtonDown(nFlags, point);
}
