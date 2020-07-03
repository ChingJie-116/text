
// MFC7_1View.cpp : CMFC7_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC7_1.h"
#endif

#include "MFC7_1Doc.h"
#include "MFC7_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC7_1View

IMPLEMENT_DYNCREATE(CMFC7_1View, CView)

BEGIN_MESSAGE_MAP(CMFC7_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOWCIRCLE, &CMFC7_1View::OnShowcircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC7_1View ����/����

CMFC7_1View::CMFC7_1View()
{
	// TODO: �ڴ˴���ӹ������
	r = 0;
	set = true;

}

CMFC7_1View::~CMFC7_1View()
{
}

BOOL CMFC7_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC7_1View ����

void CMFC7_1View::OnDraw(CDC* pDC)
{
	CMFC7_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
	if (n = 1) {
		if (set) {
			SetTimer(1, 100, NULL);
			set = false;
		}
		this->GetClientRect(&cr);
		int x = cr.Width() / 2;
		int y = cr.Height() / 2;
        pDC->Ellipse(x - r, y - r, x + r, y + r);
	}
	
}


// CMFC7_1View ��ӡ

BOOL CMFC7_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC7_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC7_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC7_1View ���

#ifdef _DEBUG
void CMFC7_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC7_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC7_1Doc* CMFC7_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC7_1Doc)));
	return (CMFC7_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC7_1View ��Ϣ�������


void CMFC7_1View::OnShowcircle()
{
	// TODO: �ڴ���������������
	n = 1;
}


void CMFC7_1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	  r++;
	  Invalidate();
	CView::OnTimer(nIDEvent);
}
