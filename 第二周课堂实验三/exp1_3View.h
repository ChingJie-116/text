
// exp1_3View.h : Cexp1_3View ��Ľӿ�
//

#pragma once


class Cexp1_3View : public CView
{
protected: // �������л�����
	Cexp1_3View();
	DECLARE_DYNCREATE(Cexp1_3View)

// ����
public:
	Cexp1_3Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp1_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp1_3View.cpp �еĵ��԰汾
inline Cexp1_3Doc* Cexp1_3View::GetDocument() const
   { return reinterpret_cast<Cexp1_3Doc*>(m_pDocument); }
#endif

