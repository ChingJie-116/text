
// exp2_1View.h : Cexp2_1View ��Ľӿ�
//

#pragma once


class Cexp2_1View : public CView
{
protected: // �������л�����
	Cexp2_1View();
	DECLARE_DYNCREATE(Cexp2_1View)

// ����
public:
	Cexp2_1Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp2_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp2_1View.cpp �еĵ��԰汾
inline Cexp2_1Doc* Cexp2_1View::GetDocument() const
   { return reinterpret_cast<Cexp2_1Doc*>(m_pDocument); }
#endif

