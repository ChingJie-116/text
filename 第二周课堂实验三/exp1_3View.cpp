
// exp1_3View.cpp : Cexp1_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp1_3.h"
#endif

#include "exp1_3Doc.h"
#include "exp1_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1_3View

IMPLEMENT_DYNCREATE(Cexp1_3View, CView)

BEGIN_MESSAGE_MAP(Cexp1_3View, CView)
END_MESSAGE_MAP()

// Cexp1_3View ����/����

Cexp1_3View::Cexp1_3View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp1_3View::~Cexp1_3View()
{
}

BOOL Cexp1_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp1_3View ����

void Cexp1_3View::OnDraw(CDC* pDC)
{
	Cexp1_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect rect;
	this->GetClientRect(rect);
	pDC->Ellipse(rect);
}


// Cexp1_3View ���

#ifdef _DEBUG
void Cexp1_3View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1_3Doc* Cexp1_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1_3Doc)));
	return (Cexp1_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1_3View ��Ϣ�������
