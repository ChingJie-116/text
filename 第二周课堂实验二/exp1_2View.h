
// exp1_2View.h : Cexp1_2View ��Ľӿ�
//

#pragma once


class Cexp1_2View : public CView
{
protected: // �������л�����
	Cexp1_2View();
	DECLARE_DYNCREATE(Cexp1_2View)

// ����
public:
	Cexp1_2Doc* GetDocument() const;

// ����
public:
	CArray<CRect, CRect&> ca;
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
	virtual ~Cexp1_2View();
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

#ifndef _DEBUG  // exp1_2View.cpp �еĵ��԰汾
inline Cexp1_2Doc* Cexp1_2View::GetDocument() const
   { return reinterpret_cast<Cexp1_2Doc*>(m_pDocument); }
#endif

