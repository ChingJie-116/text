
// ��һ��ʵ���ʵ��һDoc.cpp : C��һ��ʵ���ʵ��һDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��һ��ʵ���ʵ��һ.h"
#endif

#include "��һ��ʵ���ʵ��һDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C��һ��ʵ���ʵ��һDoc

IMPLEMENT_DYNCREATE(C��һ��ʵ���ʵ��һDoc, CDocument)

BEGIN_MESSAGE_MAP(C��һ��ʵ���ʵ��һDoc, CDocument)
END_MESSAGE_MAP()


// C��һ��ʵ���ʵ��һDoc ����/����

C��һ��ʵ���ʵ��һDoc::C��һ��ʵ���ʵ��һDoc()
{
	// TODO: �ڴ����һ���Թ������
	s = _T("�����");
}

C��һ��ʵ���ʵ��һDoc::~C��һ��ʵ���ʵ��һDoc()
{
}

BOOL C��һ��ʵ���ʵ��һDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C��һ��ʵ���ʵ��һDoc ���л�

void C��һ��ʵ���ʵ��һDoc::Serialize(CArchive& ar)
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
void C��һ��ʵ���ʵ��һDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C��һ��ʵ���ʵ��һDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C��һ��ʵ���ʵ��һDoc::SetSearchContent(const CString& value)
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

// C��һ��ʵ���ʵ��һDoc ���

#ifdef _DEBUG
void C��һ��ʵ���ʵ��һDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C��һ��ʵ���ʵ��һDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C��һ��ʵ���ʵ��һDoc ����
