
// exp2_3View.h : Cexp2_3View ��Ľӿ�
//

#pragma once


class Cexp2_3View : public CView
{
protected: // �������л�����
	Cexp2_3View();
	DECLARE_DYNCREATE(Cexp2_3View)

// ����
public:
	Cexp2_3Doc* GetDocument() const;

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
	virtual ~Cexp2_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp2_3View.cpp �еĵ��԰汾
inline Cexp2_3Doc* Cexp2_3View::GetDocument() const
   { return reinterpret_cast<Cexp2_3Doc*>(m_pDocument); }
#endif

