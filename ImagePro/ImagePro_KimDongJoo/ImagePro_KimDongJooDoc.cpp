
// ImagePro_KimDongJooDoc.cpp : CImagePro_KimDongJooDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "ImagePro_KimDongJoo.h"
#endif

#include "ImagePro_KimDongJooDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CImagePro_KimDongJooDoc

IMPLEMENT_DYNCREATE(CImagePro_KimDongJooDoc, CDocument)

BEGIN_MESSAGE_MAP(CImagePro_KimDongJooDoc, CDocument)
END_MESSAGE_MAP()


// CImagePro_KimDongJooDoc ����/�Ҹ�

CImagePro_KimDongJooDoc::CImagePro_KimDongJooDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CImagePro_KimDongJooDoc::~CImagePro_KimDongJooDoc()
{
}

BOOL CImagePro_KimDongJooDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CImagePro_KimDongJooDoc serialization

void CImagePro_KimDongJooDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring() == TRUE)
	{
		ar.Write(resultImg, 256 * 256);
	}
	else
	{
		CFile *fp = ar.GetFile();
		if (fp->GetLength() == 256 * 256) {
			ar.Read(inputImg, 256 * 256);
		}
		else {
			AfxMessageBox("256x256 ũ���� ���ϸ� ��밡���մϴ�.");
		}
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CImagePro_KimDongJooDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CImagePro_KimDongJooDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CImagePro_KimDongJooDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CImagePro_KimDongJooDoc ����

#ifdef _DEBUG
void CImagePro_KimDongJooDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImagePro_KimDongJooDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImagePro_KimDongJooDoc ���
