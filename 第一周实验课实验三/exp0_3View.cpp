
// exp0_3View.cpp : Cexp0_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp0_3.h"
#endif

#include "exp0_3Doc.h"
#include "exp0_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp0_3View

IMPLEMENT_DYNCREATE(Cexp0_3View, CView)

BEGIN_MESSAGE_MAP(Cexp0_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cexp0_3View ����/����

Cexp0_3View::Cexp0_3View()
{
	// TODO: �ڴ˴���ӹ������
	u = _T("����ѧԺ");
}

Cexp0_3View::~Cexp0_3View()
{
}

BOOL Cexp0_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp0_3View ����

void Cexp0_3View::OnDraw(CDC* pDC)
{
	Cexp0_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp0_3View ��ӡ

BOOL Cexp0_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp0_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp0_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp0_3View ���

#ifdef _DEBUG
void Cexp0_3View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp0_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp0_3Doc* Cexp0_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp0_3Doc)));
	return (Cexp0_3Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp0_3View ��Ϣ�������


void Cexp0_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp0_3Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString t;
	t = pDoc->s + u;
	dc.TextOutW(200, 200, t);
	CView::OnLButtonDown(nFlags, point);
}
