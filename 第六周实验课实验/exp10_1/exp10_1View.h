
// exp10_1View.h : Cexp10_1View ��Ľӿ�
//

#pragma once


class Cexp10_1View : public CView
{
protected: // �������л�����
	Cexp10_1View();
	DECLARE_DYNCREATE(Cexp10_1View)

// ����
public:
	Cexp10_1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp10_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	//CRect cr;
	CPoint m_point;
	CString m_str;
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // exp10_1View.cpp �еĵ��԰汾
inline Cexp10_1Doc* Cexp10_1View::GetDocument() const
   { return reinterpret_cast<Cexp10_1Doc*>(m_pDocument); }
#endif

