
// exp9_1View.h : Cexp9_1View ��Ľӿ�
//

#pragma once


class Cexp9_1View : public CView
{
protected: // �������л�����
	Cexp9_1View();
	DECLARE_DYNCREATE(Cexp9_1View)

// ����
public:
	Cexp9_1Doc* GetDocument() const;

// ����
public:
	//CArray<CRect, CRect&> ca;
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
	virtual ~Cexp9_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // exp9_1View.cpp �еĵ��԰汾
inline Cexp9_1Doc* Cexp9_1View::GetDocument() const
   { return reinterpret_cast<Cexp9_1Doc*>(m_pDocument); }
#endif

