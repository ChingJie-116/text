
// exp8_1View.cpp : Cexp8_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp8_1.h"
#endif

#include "exp8_1Doc.h"
#include "exp8_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp8_1View

IMPLEMENT_DYNCREATE(Cexp8_1View, CView)

BEGIN_MESSAGE_MAP(Cexp8_1View, CView)
	ON_COMMAND(ID_SHOWNAME, &Cexp8_1View::OnShowname)
END_MESSAGE_MAP()

// Cexp8_1View ����/����

Cexp8_1View::Cexp8_1View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp8_1View::~Cexp8_1View()
{
}

BOOL Cexp8_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp8_1View ����

void Cexp8_1View::OnDraw(CDC* /*pDC*/)
{
	Cexp8_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp8_1View ���

#ifdef _DEBUG
void Cexp8_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp8_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp8_1Doc* Cexp8_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp8_1Doc)));
	return (Cexp8_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp8_1View ��Ϣ�������


void Cexp8_1View::OnShowname()
{
	// TODO: �ڴ���������������
	CString s = _T("�����");
	CClientDC dc(this);
	dc.TextOutW(20, 300, s);

}
