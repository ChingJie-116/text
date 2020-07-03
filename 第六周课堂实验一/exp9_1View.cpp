
// exp9_1View.cpp : Cexp9_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp9_1.h"
#endif

#include "exp9_1Doc.h"
#include "exp9_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp9_1View

IMPLEMENT_DYNCREATE(Cexp9_1View, CView)

BEGIN_MESSAGE_MAP(Cexp9_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &Cexp9_1View::OnFileOpen)
END_MESSAGE_MAP()

// Cexp9_1View ����/����

Cexp9_1View::Cexp9_1View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp9_1View::~Cexp9_1View()
{
}

BOOL Cexp9_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp9_1View ����

void Cexp9_1View::OnDraw(CDC* /*pDC*/)
{
	Cexp9_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	
}


// Cexp9_1View ��ӡ

BOOL Cexp9_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp9_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp9_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp9_1View ���

#ifdef _DEBUG
void Cexp9_1View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp9_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp9_1Doc* Cexp9_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp9_1Doc)));
	return (Cexp9_1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp9_1View ��Ϣ�������


void Cexp9_1View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	CClientDC dc(this);
	int r = cfd.DoModal();
	if (r == IDOK) {
		CString filename=cfd.GetPathName();
		CImage img;
		img.Load(filename);
		int w, h, sx, sy; {
			CRect rect;
			GetClientRect(&rect);
			float rect_ratio = 1.0*rect.Width() / rect.Height();
			float img_ratio = 1.0*img.GetWidth() / img.GetHeight();
			if (rect_ratio > img_ratio) {
				h = rect.Height();
				w = img_ratio*h;
				sx = (rect.Width() - w) / 2;
				sy = 0;
			}
			else {
				w = rect.Width();
				h = w / img_ratio;
				sx = 0;
				sy = (rect.Height() - h) / 2;
			}
		}
		img.Draw(dc.m_hDC,sx,sy,w,h);
	}
}
