
// exp1_1View.cpp : Cexp1_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp1_1.h"
#endif

#include "exp1_1Doc.h"
#include "exp1_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp1_1View

IMPLEMENT_DYNCREATE(Cexp1_1View, CView)

BEGIN_MESSAGE_MAP(Cexp1_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
//ON_WM_LBUTTONUP()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp1_1View ����/����

Cexp1_1View::Cexp1_1View()
{
	// TODO: �ڴ˴���ӹ������
	
}

Cexp1_1View::~Cexp1_1View()
{
}

BOOL Cexp1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp1_1View ����

void Cexp1_1View::OnDraw(CDC* pDC)
{
	Cexp1_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp1_1View ��ӡ

BOOL Cexp1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp1_1View ���

#ifdef _DEBUG
void Cexp1_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp1_1Doc* Cexp1_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp1_1Doc)));
	return (Cexp1_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp1_1View ��Ϣ�������




void Cexp1_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
				CDC *pDC = this->GetDC();
				int r = rand() % 50+5;
				pDC->Ellipse(point.x - r, point.y - r, point.x + r, point.y + r);
	CView::OnLButtonDown(nFlags, point);
}
