
// exp10_1View.cpp : Cexp10_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp10_1.h"
#endif

#include "exp10_1Doc.h"
#include "exp10_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp10_1View

IMPLEMENT_DYNCREATE(Cexp10_1View, CView)

BEGIN_MESSAGE_MAP(Cexp10_1View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// Cexp10_1View ����/����

Cexp10_1View::Cexp10_1View()
{
	// TODO: �ڴ˴���ӹ������
	/*cr.left = 100;
	cr.top = 160;
	cr.right = 400;
	cr.bottom = 600;*/
}

Cexp10_1View::~Cexp10_1View()
{
}

BOOL Cexp10_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp10_1View ����

void Cexp10_1View::OnDraw(CDC* pDC/**/)
{
	Cexp10_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
//	pDC->Rectangle(&cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp10_1View ���

#ifdef _DEBUG
void Cexp10_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp10_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp10_1Doc* Cexp10_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp10_1Doc)));
	return (Cexp10_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp10_1View ��Ϣ�������
int Cexp10_1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
    // TODO:  �ڴ������ר�õĴ�������
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight);
	ShowCaret();
	
	return 0;
}

void Cexp10_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCaretPos(point);
	m_str.Empty();
	m_point = point;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp10_1View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	if (0x0d == nChar) {
		m_str.Empty();
		m_point.y += tm.tmHeight;
	}
	else {
		m_str += TCHAR(nChar);
	}
	CSize cz = dc.GetTextExtent(m_str);
	CPoint pt;
	pt.x = m_point.x + cz.cx;
	pt.y = m_point.y;
	SetCaretPos(pt);
	dc.TextOutW(m_point.x, m_point.y, m_str);
	CView::OnChar(nChar, nRepCnt, nFlags);
}




