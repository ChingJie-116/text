
// exp1_4View.h : Cexp1_4View 类的接口
//

#pragma once


class Cexp1_4View : public CView
{
protected: // 仅从序列化创建
	Cexp1_4View();
	DECLARE_DYNCREATE(Cexp1_4View)

// 特性
public:
	Cexp1_4Doc* GetDocument() const;

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
	virtual ~Cexp1_4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp1_4View.cpp 中的调试版本
inline Cexp1_4Doc* Cexp1_4View::GetDocument() const
   { return reinterpret_cast<Cexp1_4Doc*>(m_pDocument); }
#endif

