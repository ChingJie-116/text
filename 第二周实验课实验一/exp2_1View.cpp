
// exp2_1View.cpp : Cexp2_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp2_1.h"
#endif

#include "exp2_1Doc.h"
#include "exp2_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp2_1View

IMPLEMENT_DYNCREATE(Cexp2_1View, CView)

BEGIN_MESSAGE_MAP(Cexp2_1View, CView)
END_MESSAGE_MAP()

// Cexp2_1View ����/����

Cexp2_1View::Cexp2_1View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp2_1View::~Cexp2_1View()
{
}

BOOL Cexp2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp2_1View ����

void Cexp2_1View::OnDraw(CDC* pDC)
{
	Cexp2_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	int b = pDoc->a;
	CString w;
	w.Format(_T("%d"),b);
	pDC->TextOutW(100,200,w);
	CString s=_T("����***");
	pDC->TextOutW(200,200,s);
}


// Cexp2_1View ���

#ifdef _DEBUG
void Cexp2_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp2_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp2_1Doc* Cexp2_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp2_1Doc)));
	return (Cexp2_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp2_1View ��Ϣ�������
