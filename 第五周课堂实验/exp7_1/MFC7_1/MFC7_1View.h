
// MFC7_1View.h : CMFC7_1View ��Ľӿ�
//

#pragma once


class CMFC7_1View : public CView
{
protected: // �������л�����
	CMFC7_1View();
	DECLARE_DYNCREATE(CMFC7_1View)

// ����
public:
	CMFC7_1Doc* GetDocument() const;

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
	virtual ~CMFC7_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	int r, n;
	bool set;
	CRect cr;
	int x;
	int y;
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowcircle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC7_1View.cpp �еĵ��԰汾
inline CMFC7_1Doc* CMFC7_1View::GetDocument() const
   { return reinterpret_cast<CMFC7_1Doc*>(m_pDocument); }
#endif

