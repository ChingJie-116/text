
// exp7_1View.h : Cexp7_1View ��Ľӿ�
//

#pragma once


class Cexp7_1View : public CView
{
protected: // �������л�����
	Cexp7_1View();
	DECLARE_DYNCREATE(Cexp7_1View)

// ����
public:
	Cexp7_1Doc* GetDocument() const;

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
	virtual ~Cexp7_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp7_1View.cpp �еĵ��԰汾
inline Cexp7_1Doc* Cexp7_1View::GetDocument() const
   { return reinterpret_cast<Cexp7_1Doc*>(m_pDocument); }
#endif

