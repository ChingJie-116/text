
// exp2_2View.h : Cexp2_2View ��Ľӿ�
//

#pragma once


class Cexp2_2View : public CView
{
protected: // �������л�����
	Cexp2_2View();
	DECLARE_DYNCREATE(Cexp2_2View)

// ����
public:
	Cexp2_2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp2_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp2_2View.cpp �еĵ��԰汾
inline Cexp2_2Doc* Cexp2_2View::GetDocument() const
   { return reinterpret_cast<Cexp2_2Doc*>(m_pDocument); }
#endif

