
// exp4_2View.h : Cexp4_2View ��Ľӿ�
//

#pragma once


class Cexp4_2View : public CView
{
protected: // �������л�����
	Cexp4_2View();
	DECLARE_DYNCREATE(Cexp4_2View)

// ����
public:
	Cexp4_2Doc* GetDocument() const;

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
	virtual ~Cexp4_2View();
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

#ifndef _DEBUG  // exp4_2View.cpp �еĵ��԰汾
inline Cexp4_2Doc* Cexp4_2View::GetDocument() const
   { return reinterpret_cast<Cexp4_2Doc*>(m_pDocument); }
#endif

