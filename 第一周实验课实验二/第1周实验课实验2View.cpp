
// ��1��ʵ���ʵ��2View.cpp : C��1��ʵ���ʵ��2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��1��ʵ���ʵ��2.h"
#endif

#include "��1��ʵ���ʵ��2Doc.h"
#include "��1��ʵ���ʵ��2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��1��ʵ���ʵ��2View

IMPLEMENT_DYNCREATE(C��1��ʵ���ʵ��2View, CView)

BEGIN_MESSAGE_MAP(C��1��ʵ���ʵ��2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C��1��ʵ���ʵ��2View ����/����

C��1��ʵ���ʵ��2View::C��1��ʵ���ʵ��2View()
{
	// TODO: �ڴ˴���ӹ������

}

C��1��ʵ���ʵ��2View::~C��1��ʵ���ʵ��2View()
{
}

BOOL C��1��ʵ���ʵ��2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��1��ʵ���ʵ��2View ����

void C��1��ʵ���ʵ��2View::OnDraw(CDC* /*pDC*/)
{
	C��1��ʵ���ʵ��2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��1��ʵ���ʵ��2View ��ӡ

BOOL C��1��ʵ���ʵ��2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��1��ʵ���ʵ��2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��1��ʵ���ʵ��2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��1��ʵ���ʵ��2View ���

#ifdef _DEBUG
void C��1��ʵ���ʵ��2View::AssertValid() const
{
	CView::AssertValid();
}

void C��1��ʵ���ʵ��2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��1��ʵ���ʵ��2Doc* C��1��ʵ���ʵ��2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��1��ʵ���ʵ��2Doc)));
	return (C��1��ʵ���ʵ��2Doc*)m_pDocument;
}
#endif //_DEBUG


// C��1��ʵ���ʵ��2View ��Ϣ�������

void C��1��ʵ���ʵ��2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C��1��ʵ���ʵ��2Doc* pDoc = GetDocument();
	pDoc->count += 1;
	CView::OnLButtonDown(nFlags, point);
}

void C��1��ʵ���ʵ��2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C��1��ʵ���ʵ��2Doc* pDoc = GetDocument();
	
	CString s;
	CClientDC dc(this);
	s.Format(_T("(%d)"), pDoc->count);
	dc.TextOutW(400, 200, s);
	CView::OnRButtonDown(nFlags, point);
}


