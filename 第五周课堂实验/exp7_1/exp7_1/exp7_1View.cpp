
// exp7_1View.cpp : Cexp7_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp7_1.h"
#endif

#include "exp7_1Doc.h"
#include "exp7_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp7_1View

IMPLEMENT_DYNCREATE(Cexp7_1View, CView)

BEGIN_MESSAGE_MAP(Cexp7_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cexp7_1View ����/����

Cexp7_1View::Cexp7_1View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp7_1View::~Cexp7_1View()
{
}

BOOL Cexp7_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp7_1View ����

void Cexp7_1View::OnDraw(CDC* /*pDC*/)
{
	Cexp7_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp7_1View ��ӡ

BOOL Cexp7_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp7_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp7_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp7_1View ���

#ifdef _DEBUG
void Cexp7_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp7_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp7_1Doc* Cexp7_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp7_1Doc)));
	return (Cexp7_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp7_1View ��Ϣ�������
