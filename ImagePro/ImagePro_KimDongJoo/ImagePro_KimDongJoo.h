
// ImagePro_KimDongJoo.h : ImagePro_KimDongJoo ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CImagePro_KimDongJooApp:
// �� Ŭ������ ������ ���ؼ��� ImagePro_KimDongJoo.cpp�� �����Ͻʽÿ�.
//

class CImagePro_KimDongJooApp : public CWinAppEx
{
public:
	CImagePro_KimDongJooApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CImagePro_KimDongJooApp theApp;
