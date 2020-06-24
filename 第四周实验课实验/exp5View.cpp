
// exp5View.cpp : Cexp5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp5.h"
#endif

#include "exp5Doc.h"
#include "exp5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp5View

IMPLEMENT_DYNCREATE(Cexp5View, CView)

BEGIN_MESSAGE_MAP(Cexp5View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cexp5View ����/����

Cexp5View::Cexp5View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp5View::~Cexp5View()
{
}

BOOL Cexp5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp5View ����

void Cexp5View::OnDraw(CDC* pDC)
{
	Cexp5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->m_tagRec);
	

}


// Cexp5View ��ӡ

BOOL Cexp5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp5View ���

#ifdef _DEBUG
void Cexp5View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp5Doc* Cexp5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp5Doc)));
	return (Cexp5Doc*)m_pDocument;
}
#endif //_DEBUG


 //Cexp5View ��Ϣ�������

void Cexp5View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp5Doc* pDoc = GetDocument();
	pDoc->a.x = point.x;
	pDoc->a.y = point.y;
	CClientDC dc(this);
	CString s;
	s.Format(_T("����λ���ǣ�%d,%d"),pDoc->a.x, pDoc->a.y);
	dc.TextOutW(20, 20, s);
	CView::OnMouseMove(nFlags, point);
}
void Cexp5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp5Doc* pDoc = GetDocument();	 
	pDoc->m_tagRec.left = pDoc->a.x;
	pDoc->m_tagRec.top = pDoc->a.y;
	CView::OnLButtonDown(nFlags, point);
} 

void Cexp5View::OnLButtonUp(UINT nFlags, CPoint point)
 {
	 // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	 Cexp5Doc* pDoc = GetDocument();
	 pDoc->m_tagRec.right = point.x;
	 pDoc->m_tagRec.bottom = point.y;
	 InvalidateRect(NULL, TRUE);
	 CView::OnLButtonUp(nFlags, point);
 }
