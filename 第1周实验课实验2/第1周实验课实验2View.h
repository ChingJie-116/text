
// ��1��ʵ���ʵ��2View.h : C��1��ʵ���ʵ��2View ��Ľӿ�
//

#pragma once


class C��1��ʵ���ʵ��2View : public CView
{
protected: // �������л�����
	C��1��ʵ���ʵ��2View();
	DECLARE_DYNCREATE(C��1��ʵ���ʵ��2View)

// ����
public:
	C��1��ʵ���ʵ��2Doc* GetDocument() const;

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
	virtual ~C��1��ʵ���ʵ��2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ��1��ʵ���ʵ��2View.cpp �еĵ��԰汾
inline C��1��ʵ���ʵ��2Doc* C��1��ʵ���ʵ��2View::GetDocument() const
   { return reinterpret_cast<C��1��ʵ���ʵ��2Doc*>(m_pDocument); }
#endif

