
// exp0_3View.h : Cexp0_3View 类的接口
//

#pragma once


class Cexp0_3View : public CView
{
protected: // 仅从序列化创建
	Cexp0_3View();
	DECLARE_DYNCREATE(Cexp0_3View)

// 特性
public:
	Cexp0_3Doc* GetDocument() const;

// 操作
public:

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
	virtual ~Cexp0_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString u;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp0_3View.cpp 中的调试版本
inline Cexp0_3Doc* Cexp0_3View::GetDocument() const
   { return reinterpret_cast<Cexp0_3Doc*>(m_pDocument); }
#endif

