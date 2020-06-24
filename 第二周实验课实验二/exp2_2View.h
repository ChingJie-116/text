
// exp2_2View.h : Cexp2_2View 类的接口
//

#pragma once


class Cexp2_2View : public CView
{
protected: // 仅从序列化创建
	Cexp2_2View();
	DECLARE_DYNCREATE(Cexp2_2View)

// 特性
public:
	Cexp2_2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cexp2_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp2_2View.cpp 中的调试版本
inline Cexp2_2Doc* Cexp2_2View::GetDocument() const
   { return reinterpret_cast<Cexp2_2Doc*>(m_pDocument); }
#endif

