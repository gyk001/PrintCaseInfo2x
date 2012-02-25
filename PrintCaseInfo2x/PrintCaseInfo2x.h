// PrintCaseInfo2x.h : PrintCaseInfo2x 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CPrintCaseInfo2xApp:
// 有关此类的实现，请参阅 PrintCaseInfo2x.cpp
//

class CPrintCaseInfo2xApp : public CWinApp
{
public:
	CPrintCaseInfo2xApp();
private:
		CString m_strStylesPath;

// 重写
public:
	virtual BOOL InitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnFileNew();
public:
	CString GetStylesPath(void);
};

extern CPrintCaseInfo2xApp theApp;
extern const int appMarjorVersion ;
extern const int appMinjorVersion ;
extern const int minSupportMarjorVersion ;
extern const int minSupportMinjorVersion ;

extern const CString fileTypeString;
extern UINT DocExportThreadProc(const LPVOID lpParam);