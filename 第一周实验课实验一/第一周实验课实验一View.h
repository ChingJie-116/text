
// ��һ��ʵ���ʵ��һView.h : C��һ��ʵ���ʵ��һView ��Ľӿ�
//

#pragma once


class C��һ��ʵ���ʵ��һView : public CView
{
protected: // �������л�����
	C��һ��ʵ���ʵ��һView();
	DECLARE_DYNCREATE(C��һ��ʵ���ʵ��һView)

// ����
public:
	C��һ��ʵ���ʵ��һDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C��һ��ʵ���ʵ��һView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ��һ��ʵ���ʵ��һView.cpp �еĵ��԰汾
inline C��һ��ʵ���ʵ��һDoc* C��һ��ʵ���ʵ��һView::GetDocument() const
   { return reinterpret_cast<C��һ��ʵ���ʵ��һDoc*>(m_pDocument); }
#endif

