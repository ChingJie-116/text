
// exp4_3Doc.cpp : Cexp4_3Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp4_3.h"
#endif

#include "exp4_3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cexp4_3Doc

IMPLEMENT_DYNCREATE(Cexp4_3Doc, CDocument)

BEGIN_MESSAGE_MAP(Cexp4_3Doc, CDocument)
END_MESSAGE_MAP()


// Cexp4_3Doc 构造/析构

Cexp4_3Doc::Cexp4_3Doc()
{
	// TODO: 在此添加一次性构造代码
	A.left = 30; A.top = 30;
	A.right = 200; A.bottom = 200;
	B.left = 250; B.top = 30;
	B.right = 450; B.bottom = 200;
	C.left = 500; C.top = 30;
	C.right = 700; C.bottom = 200;
	/*D.left = 800; D.top = 30;
	D.right = 1000; D.bottom = 200;*/
	a = rand() % 50 + 5;
	b = rand() % 50 + 5;
	c = a + b;
	
}

Cexp4_3Doc::~Cexp4_3Doc()
{
}

BOOL Cexp4_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// Cexp4_3Doc 序列化

void Cexp4_3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void Cexp4_3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void Cexp4_3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void Cexp4_3Doc::SetSearchContent(const CString& value)
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

// Cexp4_3Doc 诊断

#ifdef _DEBUG
void Cexp4_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cexp4_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cexp4_3Doc 命令
