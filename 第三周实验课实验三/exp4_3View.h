
// exp4_3View.h : Cexp4_3View ��Ľӿ�
//

#pragma once


class Cexp4_3View : public CView
{
protected: // �������л�����
	Cexp4_3View();
	DECLARE_DYNCREATE(Cexp4_3View)

// ����
public:
	Cexp4_3Doc* GetDocument() const;

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
	virtual ~Cexp4_3View();
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

#ifndef _DEBUG  // exp4_3View.cpp �еĵ��԰汾
inline Cexp4_3Doc* Cexp4_3View::GetDocument() const
   { return reinterpret_cast<Cexp4_3Doc*>(m_pDocument); }
#endif

