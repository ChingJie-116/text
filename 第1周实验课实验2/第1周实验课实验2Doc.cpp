
// ��1��ʵ���ʵ��2Doc.cpp : C��1��ʵ���ʵ��2Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��1��ʵ���ʵ��2.h"
#endif

#include "��1��ʵ���ʵ��2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C��1��ʵ���ʵ��2Doc

IMPLEMENT_DYNCREATE(C��1��ʵ���ʵ��2Doc, CDocument)

BEGIN_MESSAGE_MAP(C��1��ʵ���ʵ��2Doc, CDocument)
END_MESSAGE_MAP()


// C��1��ʵ���ʵ��2Doc ����/����

C��1��ʵ���ʵ��2Doc::C��1��ʵ���ʵ��2Doc()
{
	// TODO: �ڴ����һ���Թ������
	count = 0;
}

C��1��ʵ���ʵ��2Doc::~C��1��ʵ���ʵ��2Doc()
{
}

BOOL C��1��ʵ���ʵ��2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C��1��ʵ���ʵ��2Doc ���л�

void C��1��ʵ���ʵ��2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void C��1��ʵ���ʵ��2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void C��1��ʵ���ʵ��2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C��1��ʵ���ʵ��2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// C��1��ʵ���ʵ��2Doc ���

#ifdef _DEBUG
void C��1��ʵ���ʵ��2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C��1��ʵ���ʵ��2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C��1��ʵ���ʵ��2Doc ����
