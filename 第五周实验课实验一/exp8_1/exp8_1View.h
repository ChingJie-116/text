
// exp8_1View.h : Cexp8_1View 类的接口
//

#pragma once


class Cexp8_1View : public CView
{
protected: // 仅从序列化创建
	Cexp8_1View();
	DECLARE_DYNCREATE(Cexp8_1View)

// 特性
public:
	Cexp8_1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp8_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // exp8_1View.cpp 中的调试版本
inline Cexp8_1Doc* Cexp8_1View::GetDocument() const
   { return reinterpret_cast<Cexp8_1Doc*>(m_pDocument); }
#endif

