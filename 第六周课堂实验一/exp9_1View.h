
// exp9_1View.h : Cexp9_1View 类的接口
//

#pragma once


class Cexp9_1View : public CView
{
protected: // 仅从序列化创建
	Cexp9_1View();
	DECLARE_DYNCREATE(Cexp9_1View)

// 特性
public:
	Cexp9_1Doc* GetDocument() const;

// 操作
public:
	//CArray<CRect, CRect&> ca;
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
	virtual ~Cexp9_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // exp9_1View.cpp 中的调试版本
inline Cexp9_1Doc* Cexp9_1View::GetDocument() const
   { return reinterpret_cast<Cexp9_1Doc*>(m_pDocument); }
#endif

