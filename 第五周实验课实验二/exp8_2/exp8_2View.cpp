
// exp8_2View.cpp : Cexp8_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp8_2.h"
#endif

#include "exp8_2Doc.h"
#include "exp8_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp8_2View

IMPLEMENT_DYNCREATE(Cexp8_2View, CView)

BEGIN_MESSAGE_MAP(Cexp8_2View, CView)
END_MESSAGE_MAP()

// Cexp8_2View ����/����

Cexp8_2View::Cexp8_2View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP BM;
	m_Bitmap.LoadMappedBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
}

Cexp8_2View::~Cexp8_2View()
{
}

BOOL Cexp8_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp8_2View ����

void Cexp8_2View::OnDraw(CDC* pDC)
{
	Cexp8_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
}


// Cexp8_2View ���

#ifdef _DEBUG
void Cexp8_2View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp8_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp8_2Doc* Cexp8_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp8_2Doc)));
	return (Cexp8_2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp8_2View ��Ϣ�������
