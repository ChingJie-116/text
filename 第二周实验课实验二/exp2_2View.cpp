
// exp2_2View.cpp : Cexp2_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp2_2.h"
#endif

#include "exp2_2Doc.h"
#include "exp2_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp2_2View

IMPLEMENT_DYNCREATE(Cexp2_2View, CView)

BEGIN_MESSAGE_MAP(Cexp2_2View, CView)
END_MESSAGE_MAP()

// Cexp2_2View ����/����

Cexp2_2View::Cexp2_2View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp2_2View::~Cexp2_2View()
{
}

BOOL Cexp2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp2_2View ����

void Cexp2_2View::OnDraw(CDC* pDC)
{
	Cexp2_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	int b = pDoc->a;
	CString w;
	w.Format(_T("%d"), b);
	pDC->TextOutW(100, 100, w);
	pDC->TextOutW(200, 200, pDoc->s);
}


// Cexp2_2View ���

#ifdef _DEBUG
void Cexp2_2View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp2_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp2_2Doc* Cexp2_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp2_2Doc)));
	return (Cexp2_2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp2_2View ��Ϣ�������
