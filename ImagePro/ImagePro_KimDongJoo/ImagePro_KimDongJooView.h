
// ImagePro_KimDongJooView.h : CImagePro_KimDongJooView Ŭ������ �������̽�
//

#pragma once


class CImagePro_KimDongJooView : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	CImagePro_KimDongJooView();
	DECLARE_DYNCREATE(CImagePro_KimDongJooView)

// Ư���Դϴ�.
public:
	CImagePro_KimDongJooDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CImagePro_KimDongJooView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ImagePro_KimDongJooView.cpp�� ����� ����
inline CImagePro_KimDongJooDoc* CImagePro_KimDongJooView::GetDocument() const
   { return reinterpret_cast<CImagePro_KimDongJooDoc*>(m_pDocument); }
#endif

