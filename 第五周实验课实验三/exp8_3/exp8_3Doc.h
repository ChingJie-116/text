
// exp8_3Doc.h : Cexp8_3Doc ��Ľӿ�
//


#pragma once


class Cexp8_3Doc : public CDocument
{
protected: // �������л�����
	Cexp8_3Doc();
	DECLARE_DYNCREATE(Cexp8_3Doc)

// ����
public:

// ����
public:

	CRect rect;
	CRect circle;
	CPoint point1;
	CPoint point2;
	int n;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~Cexp8_3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	
	
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
