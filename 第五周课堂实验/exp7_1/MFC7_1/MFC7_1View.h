
// MFC7_1View.h : CMFC7_1View 类的接口
//

#pragma once


class CMFC7_1View : public CView
{
protected: // 仅从序列化创建
	CMFC7_1View();
	DECLARE_DYNCREATE(CMFC7_1View)

// 特性
public:
	CMFC7_1Doc* GetDocument() const;

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
	virtual ~CMFC7_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	int r, n;
	bool set;
	CRect cr;
	int x;
	int y;
protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowcircle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC7_1View.cpp 中的调试版本
inline CMFC7_1Doc* CMFC7_1View::GetDocument() const
   { return reinterpret_cast<CMFC7_1Doc*>(m_pDocument); }
#endif

