
// exp0_3View.h : Cexp0_3View ��Ľӿ�
//

#pragma once


class Cexp0_3View : public CView
{
protected: // �������л�����
	Cexp0_3View();
	DECLARE_DYNCREATE(Cexp0_3View)

// ����
public:
	Cexp0_3Doc* GetDocument() const;

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
	virtual ~Cexp0_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString u;
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp0_3View.cpp �еĵ��԰汾
inline Cexp0_3Doc* Cexp0_3View::GetDocument() const
   { return reinterpret_cast<Cexp0_3Doc*>(m_pDocument); }
#endif

