
// exp8_1View.h : Cexp8_1View ��Ľӿ�
//

#pragma once


class Cexp8_1View : public CView
{
protected: // �������л�����
	Cexp8_1View();
	DECLARE_DYNCREATE(Cexp8_1View)

// ����
public:
	Cexp8_1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp8_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // exp8_1View.cpp �еĵ��԰汾
inline Cexp8_1Doc* Cexp8_1View::GetDocument() const
   { return reinterpret_cast<Cexp8_1Doc*>(m_pDocument); }
#endif

