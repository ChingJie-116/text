
// exp1_2View.h : Cexp1_2View 类的接口
//

#pragma once


class Cexp1_2View : public CView
{
protected: // 仅从序列化创建
	Cexp1_2View();
	DECLARE_DYNCREATE(Cexp1_2View)

// 特性
public:
	Cexp1_2Doc* GetDocument() const;

// 操作
public:
	CArray<CRect, CRect&> ca;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cexp1_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp1_2View.cpp 中的调试版本
inline Cexp1_2Doc* Cexp1_2View::GetDocument() const
   { return reinterpret_cast<Cexp1_2Doc*>(m_pDocument); }
#endif

