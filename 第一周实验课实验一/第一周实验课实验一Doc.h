
// ��һ��ʵ���ʵ��һDoc.h : C��һ��ʵ���ʵ��һDoc ��Ľӿ�
//


#pragma once


class C��һ��ʵ���ʵ��һDoc : public CDocument
{
protected: // �������л�����
	C��һ��ʵ���ʵ��һDoc();
	DECLARE_DYNCREATE(C��һ��ʵ���ʵ��һDoc)

// ����
public:

// ����
public:
	
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
	virtual ~C��һ��ʵ���ʵ��һDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CString s;
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
