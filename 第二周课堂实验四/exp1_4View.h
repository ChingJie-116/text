
// exp1_4View.h : Cexp1_4View ��Ľӿ�
//

#pragma once


class Cexp1_4View : public CView
{
protected: // �������л�����
	Cexp1_4View();
	DECLARE_DYNCREATE(Cexp1_4View)

// ����
public:
	Cexp1_4Doc* GetDocument() const;

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
	virtual ~Cexp1_4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp1_4View.cpp �еĵ��԰汾
inline Cexp1_4Doc* Cexp1_4View::GetDocument() const
   { return reinterpret_cast<Cexp1_4Doc*>(m_pDocument); }
#endif

