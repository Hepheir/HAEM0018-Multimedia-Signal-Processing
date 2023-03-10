
// ImagePro_KimDongJooView.cpp : CImagePro_KimDongJooView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "ImagePro_KimDongJoo.h"
#endif

#include "ImagePro_KimDongJooDoc.h"
#include "ImagePro_KimDongJooView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImagePro_KimDongJooView

IMPLEMENT_DYNCREATE(CImagePro_KimDongJooView, CScrollView)

BEGIN_MESSAGE_MAP(CImagePro_KimDongJooView, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CImagePro_KimDongJooView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CImagePro_KimDongJooView ����/�Ҹ�

CImagePro_KimDongJooView::CImagePro_KimDongJooView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CImagePro_KimDongJooView::~CImagePro_KimDongJooView()
{
}

BOOL CImagePro_KimDongJooView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CImagePro_KimDongJooView �׸���

void CImagePro_KimDongJooView::OnDraw(CDC* /*pDC*/)
{
	CImagePro_KimDongJooDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}

void CImagePro_KimDongJooView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CImagePro_KimDongJooView �μ�


void CImagePro_KimDongJooView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImagePro_KimDongJooView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CImagePro_KimDongJooView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CImagePro_KimDongJooView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CImagePro_KimDongJooView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImagePro_KimDongJooView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImagePro_KimDongJooView ����

#ifdef _DEBUG
void CImagePro_KimDongJooView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CImagePro_KimDongJooView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CImagePro_KimDongJooDoc* CImagePro_KimDongJooView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImagePro_KimDongJooDoc)));
	return (CImagePro_KimDongJooDoc*)m_pDocument;
}
#endif //_DEBUG


// CImagePro_KimDongJooView �޽��� ó����
