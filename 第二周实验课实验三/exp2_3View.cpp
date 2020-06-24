
// exp2_3View.cpp : Cexp2_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp2_3.h"
#endif

#include "exp2_3Doc.h"
#include "exp2_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp2_3View

IMPLEMENT_DYNCREATE(Cexp2_3View, CView)

BEGIN_MESSAGE_MAP(Cexp2_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_RBUTTONDOWN()
ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp2_3View ����/����

Cexp2_3View::Cexp2_3View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp2_3View::~Cexp2_3View()
{
}

BOOL Cexp2_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp2_3View ����

void Cexp2_3View::OnDraw(CDC* /*pDC*/)
{
	Cexp2_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp2_3View ��ӡ

BOOL Cexp2_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp2_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp2_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp2_3View ���

#ifdef _DEBUG
void Cexp2_3View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp2_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp2_3Doc* Cexp2_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp2_3Doc)));
	return (Cexp2_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp2_3View ��Ϣ�������





void Cexp2_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp2_3Doc* pDoc = GetDocument();
	pDoc->count += 1;
	
	CView::OnLButtonDown(nFlags, point);
}


void Cexp2_3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp2_3Doc* pDoc = GetDocument();
	CString s;
	CClientDC dc(this);
	s.Format(_T("(%d)"), pDoc->count);
	dc.TextOutW(400, 200, s);
	CView::OnRButtonDown(nFlags, point);
}
