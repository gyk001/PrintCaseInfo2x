// DocExportInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "PrintCaseInfo2x.h"
#include "DocExportInfo.h"


// CDocExportInfo

CDocExportInfo::CDocExportInfo(CDialog* pDlg , 	CPrintCaseInfo2xDoc * pDoc )
:pDoc(pDoc)
,bExit(FALSE)
,pDlg(pDlg)
{
}

CDocExportInfo::~CDocExportInfo()
{
	//wdt.CloseApp();
}


// CDocExportInfo 成员函数

//设置书签内容 （SBT=SetBookmarkText)
BOOL CDocExportInfo::SBT(CString bkName, CString bkText)
{
	if (bExit)
	{
	//	PostMessage(pDlg->GetSafeHwnd(), WM_DLG_CLOSE,0,0);
		return FALSE;
	}
	//TODO:
// 	if( ! wdt.BookmarkText( bkName , bkText ) )
// 	{
// 		return FALSE;
// 	}
	//Sleep(1);
	PostMessage(pDlg->GetSafeHwnd(), WM_EXPORT_STEP_IT,0,0);
/*	TRACE_FUNC();*/
	return TRUE;
}

BOOL CDocExportInfo::DocInit(void)
{
	if( !wdt.Create())
	{
		return FALSE;
	}
	PostMessage(pDlg->GetSafeHwnd(), WM_EXPORT_STEP_IT,0,0);
	return TRUE;
}

void CDocExportInfo::ShowWordApp(void)
{
	wdt.ShowApp();
}
