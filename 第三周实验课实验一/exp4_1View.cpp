
// exp4_1View.cpp : Cexp4_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp4_1.h"
#endif

#include "exp4_1Doc.h"
#include "exp4_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp4_1View

IMPLEMENT_DYNCREATE(Cexp4_1View, CView)

BEGIN_MESSAGE_MAP(Cexp4_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// Cexp4_1View ����/����

Cexp4_1View::Cexp4_1View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp4_1View::~Cexp4_1View()
{
}

BOOL Cexp4_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp4_1View ����

void Cexp4_1View::OnDraw(CDC* pDC)
{
	Cexp4_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp4_1View ��ӡ

BOOL Cexp4_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp4_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp4_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp4_1View ���

#ifdef _DEBUG
void Cexp4_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp4_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp4_1Doc* Cexp4_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp4_1Doc)));
	return (Cexp4_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp4_1View ��Ϣ�������


void Cexp4_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s=_T("�����������");
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}


void Cexp4_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString w = _T("�������̧��");
	CClientDC dc(this);
	dc.TextOutW(400, 400, w);
	CView::OnLButtonUp(nFlags, point);
}
