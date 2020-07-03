
// exp8_2View.h : Cexp8_2View 类的接口
//

#pragma once


class Cexp8_2View : public CView
{
protected: // 仅从序列化创建
	Cexp8_2View();
	DECLARE_DYNCREATE(Cexp8_2View)

// 特性
public:
	Cexp8_2Doc* GetDocument() const;

// 操作
public:
	CBitmap m_Bitmap;
	int m_nWidth;
	int m_nHeight;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp8_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp8_2View.cpp 中的调试版本
inline Cexp8_2Doc* Cexp8_2View::GetDocument() const
   { return reinterpret_cast<Cexp8_2Doc*>(m_pDocument); }
#endif

