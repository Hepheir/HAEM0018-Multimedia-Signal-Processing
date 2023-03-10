
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

void CImagePro_KimDongJooDoc::PixelAdd()
{
	int value = 0;

	for (int x = 0; x < 256; x++) {
		for (int y = 0; y < 256; y++) {
			value = inputImg[x][y] + 100;
			if (value > 255) {
				resultImg[x][y] = 255;
			}
			else {
				resultImg[x][y] = value;
			}
		}
	}
}


void CImagePro_KimDongJooDoc::PixelHistoEq()
{
	int x, y, i, k;
	int acc_hist = 0;
	float N = 256 * 256;
	int hist[256], sum[256];

	// initialize
	for (k = 0; k < 256; k++) {
		hist[k] = 0;
	}

	for (y = 0; y < 256; y++) {
		for (x = 0; x < 256; x++) {
			k = inputImg[y][x];
			hist[k] += 1;
		}
	}

	for (i = 0; i < 256; i++) {
		acc_hist = acc_hist + hist[i];
		sum[i] = acc_hist;
	}

	for (y = 0; y < 256; y++) {
		for (x = 0; x < 256; x++) {
			k = inputImg[y][x];
			resultImg[y][x] = sum[k] / N * 255;
		}
	}
}


void CImagePro_KimDongJooDoc::PixelTwoImageAdd()
{
	int value = 0;

	LoadTwoImages();

	for (int y = 0; y < 256; y++) {
		for (int x = 0; x < 256; x++) {
			value = inputImg[y][x] + inputImg2[y][x];
			if (value > 255) {
				resultImg[y][x] = 255;
			}
			else {
				resultImg[y][x] = value;
			}
		}
	}
}


void CImagePro_KimDongJooDoc::LoadTwoImages()
{
	CFile file;
	CFileDialog dlg(TRUE);

	AfxMessageBox("Select the First Image");

	if (dlg.DoModal() == IDOK) {
		file.Open(dlg.GetPathName(), CFile::modeRead);
		file.Read(inputImg, 256 * 256);
		file.Close();
	}

	AfxMessageBox("Select the Second Image");

	if (dlg.DoModal() == IDOK) {
		file.Open(dlg.GetPathName(), CFile::modeRead);
		file.Read(inputImg2, 256 * 256);
		file.Close();
	}
}
