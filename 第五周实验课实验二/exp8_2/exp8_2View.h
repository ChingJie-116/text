
// exp8_2View.h : Cexp8_2View ��Ľӿ�
//

#pragma once


class Cexp8_2View : public CView
{
protected: // �������л�����
	Cexp8_2View();
	DECLARE_DYNCREATE(Cexp8_2View)

// ����
public:
	Cexp8_2Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp8_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp8_2View.cpp �еĵ��԰汾
inline Cexp8_2Doc* Cexp8_2View::GetDocument() const
   { return reinterpret_cast<Cexp8_2Doc*>(m_pDocument); }
#endif

