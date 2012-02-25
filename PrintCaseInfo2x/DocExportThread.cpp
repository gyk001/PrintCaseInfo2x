#include "stdafx.h"
#include "PrintCaseInfo2xDoc.h"
#include "DocExportInfo.h"




extern UINT DocExportThreadProc(const LPVOID lpParam)
{

	CDocExportInfo  *lpObject = (CDocExportInfo*)lpParam;
	if(lpObject == NULL || !lpObject->IsKindOf(RUNTIME_CLASS(CDocExportInfo)))
	{
		//输入参数非法 
		PostMessage(lpObject->pDlg->GetSafeHwnd(), WM_DLG_CLOSE,0,0);
		return  DOC_EXPORT_ERROR; 
	}
	
	//Ole初始化
 	if(S_OK != CoInitialize(NULL) )
 		return DOC_EXPORT_ERROR;

	//创建文档
	lpObject->DocInit();

	bool bWordNotClose = false;
	for(int i=0;i<999;i++)
	{	
		if( ! lpObject->SBT(_T("FEMALE_NAME") ,_T("dd")))
		{
			goto EndExport;
		}
		
	}

	PostMessage(lpObject->pDlg->GetSafeHwnd(), WM_EXPORT_FINISHED,0,0);
	
	//
	TRACE_FUNC();
	SuspendThread( GetCurrentThread() );
	
	switch (lpObject->bExit)
	{
	case DOC_EXPORT_OPEN:
		bWordNotClose = true;
		lpObject->wdt.ShowApp();
		break;
	case DOC_EXPORT_PREVIEW:
		bWordNotClose = true;
		lpObject->wdt.PrintPreview();
		break;
// 	case DOC_EXPORT_SAVE:
// // 		lpObject->wdt.ShowApp();
// // 		lpObject->wdt.SaveDocument();	
// // 		lpObject->wdt.ActivateApp();
// // 	//	lpObject->wdt.HideApp();
// 		break;
// 	case DOC_EXPORT_CANCEL:
// 
// 		break;
	default:

		break;
	}
EndExport:

	if ( !bWordNotClose )
	{
		lpObject->wdt.CloseApp();
	}

	TRACE_FUNC();
	CoUninitialize();	
	PostMessage(lpObject->pDlg->GetSafeHwnd(), WM_DLG_CLOSE,0,0);	
	return 0;
}