// PrintCaseInfo2xDoc.cpp : CPrintCaseInfo2xDoc 类的实现
//

#include "stdafx.h"
#include "PrintCaseInfo2x.h"
#include "MainFrm.h"
#include "PrintCaseInfo2xDoc.h"
#include "PrintCaseInfoView.h"
#include "PasswordDlg.h"
#include "DocExportDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPrintCaseInfo2xDoc

IMPLEMENT_DYNCREATE(CPrintCaseInfo2xDoc, CDocument)

BEGIN_MESSAGE_MAP(CPrintCaseInfo2xDoc, CDocument)
	ON_COMMAND(ID_EXPORT_TO_WORD, &CPrintCaseInfo2xDoc::OnExportToWord)
	ON_COMMAND(ID_MENU_FILE_LOCK, &CPrintCaseInfo2xDoc::OnMenuFileLock)
	ON_COMMAND(ID_MENU_DEL_FILE_LOCK, &CPrintCaseInfo2xDoc::OnMenuDelFileLock)
	ON_UPDATE_COMMAND_UI(ID_MENU_FILE_LOCK, &CPrintCaseInfo2xDoc::OnUpdateMenuFileLock)
	ON_UPDATE_COMMAND_UI(ID_MENU_DEL_FILE_LOCK, &CPrintCaseInfo2xDoc::OnUpdateMenuDelFileLock)
END_MESSAGE_MAP()


// CPrintCaseInfo2xDoc 构造/析构

CPrintCaseInfo2xDoc::CPrintCaseInfo2xDoc()
{
	// TODO: 在此添加一次性构造代码

}

CPrintCaseInfo2xDoc::~CPrintCaseInfo2xDoc()
{
}


// CPrintCaseInfo2xDoc 序列化

BOOL CPrintCaseInfo2xDoc::ValidatePassword(CString password)
{
	password = unSer( password );
	//AfxMessageBox( password  );

	CPasswordDlg dlg;
	dlg.dlgFlag = CPasswordDlg::DKF_VLD;
	dlg.m_docPassword = password;
	if(dlg.DoModal() == IDCANCEL)
	{
		THROW( new   CUserException( TRUE , IDS_EXCEPTION_CANCEL_OPEN )) ;
		//	return FALSE;
	}

	return TRUE;
}

void CPrintCaseInfo2xDoc::ReadFile(CArchive& ar)
{
	if (ar.IsStoring())
	{
		return;
	}
	CString fileType;
	ar>>fileType;
	if ( fileType != fileTypeString )
	{
		THROW( new   CUserException( TRUE , IDS_EXCEPTION_FILE_TYPE_ERROR )) ;
		return ;
	}

	//读取主板本号
	ar >> majorVersion;
	if( majorVersion < 2 ){ //1.x版本的文档无次版本号，取消支持
		THROW( new   CUserException( TRUE , IDS_EXCEPTION_VERSION_LOW )) ;
		return ;
	}
	//读取次版本号
	ar>>minorVersion;



	if ( majorVersion > appMarjorVersion ) //文件主版本号过高
	{
		THROW( new   CUserException( TRUE , IDS_EXCEPTION_VERSION_LOW )) ;
		return ;
	}
	else
	{
		if(minorVersion > appMinjorVersion) //文件次版本号过高
		{
			THROW( new   CUserException( TRUE , IDS_EXCEPTION_VERSION_LOW )) ;
			return ;
		}else
		{
			if(  majorVersion < minSupportMarjorVersion ) // 文件主板本号过低
			{
				//取消低版本文件支持
				THROW( new   CUserException( TRUE , IDS_EXCEPTION_LOW_VERSION_FILE )) ;
				return ;
			}
			else
			{
				if ( minorVersion < minSupportMinjorVersion) //文件次版本号过低
				{
					//取消低版本文件支持
					THROW( new   CUserException( TRUE , IDS_EXCEPTION_LOW_VERSION_FILE )) ;
					return ;
				}
				else
				{//可以支持该文件版本
					//读取控制标识
					ar >>ctrlFlag;

					if ( ctrlFlag & FILE_CTRL_LOCKED ) // 文件已加锁
					{
						//读取解锁密码
						ar>> password;
						//验证密码
						ValidatePassword(password);
					}
				}
			}
		}

	}
	/*
	if ( majorVersion < appSupportMajorVersion )
	{//1.x版本
		//取消低版本文件支持
		THROW( new   CUserException( TRUE , IDS_EXCEPTION_LOW_VERSION_FILE )) ;
		return ;
	}
	else//2.x版
	{
		ar>>minorVersion;
		if ( minorVersion > appMinjorVersion )
		{
			THROW( new   CUserException( TRUE , IDS_EXCEPTION_VERSION_LOW )) ;
			return ;
		}	
		if ( minorVersion < minSupportMinjorVersion)
		{
			//取消低版本文件支持
			THROW( new   CUserException( TRUE , IDS_EXCEPTION_LOW_VERSION_FILE )) ;
			return ;
		}
		ar >>ctrlFlag;
		if ( ctrlFlag & FILE_CTRL_LOCKED )
		{
			ar>> password;
			ValidatePassword(password);
		}
	}
*/
	commonInfo.Serialize( ar ,majorVersion , minorVersion);
	maleInfo.Serialize(ar);
	femaleInfo.Serialize( ar ,majorVersion , minorVersion);
}

void CPrintCaseInfo2xDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << fileTypeString;
		ar << appMarjorVersion;	
		ar << appMinjorVersion;
		ar << ctrlFlag;
		if ( ctrlFlag & FILE_CTRL_LOCKED )
		{
			ar<< Ser( password );
		}
		commonInfo.Serialize( ar ,majorVersion, minorVersion );
		maleInfo.Serialize(ar);
		femaleInfo.Serialize(ar,majorVersion , minorVersion);
	}
	else
	{   
		ReadFile( ar );
	}


}


// CPrintCaseInfo2xDoc 诊断

#ifdef _DEBUG
void CPrintCaseInfo2xDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPrintCaseInfo2xDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPrintCaseInfo2xDoc 命令

CString   CPrintCaseInfo2xDoc::Ser(CString   yuanwen)    
{   
	TCHAR   charyou;   
	CString miwen;
	for(int   i=0;i<yuanwen.GetLength()+1;i++)   
	{                   
		charyou=yuanwen.GetAt(i)+1;   
		miwen.AppendChar( charyou )   ;
	}   
	return miwen;
}  

CString   CPrintCaseInfo2xDoc::unSer(CString   miwen)
{   
	TCHAR   charyou;  
	CString yuanwen;
	for(int   i=0;i<miwen.GetLength()+1;i++)   
	{                 
		charyou=miwen.GetAt(i)-1;   
		yuanwen.AppendChar( charyou )  ;
	}     
	return yuanwen;
} 

void CPrintCaseInfo2xDoc::ReportSaveLoadException(LPCTSTR lpszPathName, CException* e, BOOL bSaving, UINT nIDPDefault)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (e->IsKindOf( RUNTIME_CLASS( CUserException ) ) )
	{
		e->ReportError();

	} 
	else if (e->IsKindOf( RUNTIME_CLASS( CArchiveException ) ) )
	{
		AfxMessageBox(IDS_EXCEPTION_FILE_TYPE_ERROR);            
		//e->Delete();
	} 
	else
	{
		CDocument::ReportSaveLoadException(lpszPathName, e, bSaving, nIDPDefault);
	}
}

void CPrintCaseInfo2xDoc::SetModifiedFlag(BOOL bModified) 
{ 
	TRACE_FUNC();
	CDocument::SetModifiedFlag(bModified); 
 	if(AfxGetMainWnd())
 		AfxGetMainWnd() -> SendMessage(WM_UPDATE_FRAME_TITLE);
}


void CPrintCaseInfo2xDoc::DeleteContents()
{
	// TODO: 在此添加专用代码和/或调用基类
	maleInfo=CMaleInfo();
	femaleInfo=CFemaleInfo();
	commonInfo =CCommonInfo();
	majorVersion = 0;
	minorVersion = 0;
	ctrlFlag = 0 ;
	CDocument::DeleteContents();
}

BOOL CPrintCaseInfo2xDoc::UpdateDocFromView()
{
	TRACE_FUNC();
	POSITION pos = GetFirstViewPosition();
	while (pos != NULL)
	{
		CPrintCaseInfoView* pView = (CPrintCaseInfoView*)GetNextView(pos);
		ASSERT_VALID(pView);
		if( ! pView->OnUpdateDocFromView() )
		{
			return FALSE;
		}
	}
	return TRUE;
}

BOOL CPrintCaseInfo2xDoc::DoFileSave( )
{
		TRACE_FUNC();
		//保持文档视图数据同步
		if ( ! UpdateDocFromView() )
		{
			return FALSE;
		}
		return CDocument::DoFileSave();
}


void CPrintCaseInfo2xDoc::OnExportToWord()
{
	// TODO: 在此添加命令处理程序代码
//CWinThread*  p = AfxBeginThread(RUNTIME_CLASS(CDocExportThread));
		AfxMessageBox(_T("功能暂为开放！"),MB_OK);
	/*	CDocExportDlg dlg;
		dlg.pCidDoc = this;
		dlg.DoModal();
		*/
}

void CPrintCaseInfo2xDoc::OnMenuFileLock()
{
	// TODO: 在此添加命令处理程序代码
	CPasswordDlg dlg;
	dlg.dlgFlag = CPasswordDlg::DKF_SET;
	if(dlg.DoModal() ==IDOK)
	{
		password = dlg.m_password;
		ctrlFlag |= FILE_CTRL_LOCKED;
		SetModifiedFlag(TRUE);
		AfxMessageBox(_T("该文件密码为:")+password+_T("\r\n请牢记！"));	
	}
}

void CPrintCaseInfo2xDoc::OnMenuDelFileLock()
{
	// TODO: 在此添加命令处理程序代码

	if(ValidatePassword(password))
	{
		ctrlFlag &= ~FILE_CTRL_LOCKED;
		SetModifiedFlag(TRUE);
		AfxMessageBox(_T("密码已删除！")) ;
	}
}

void CPrintCaseInfo2xDoc::OnUpdateMenuFileLock(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
		if(! ctrlFlag&FILE_CTRL_LOCKED)
		{
			pCmdUI->SetText(_T("设置密码(&P)"));			
		}
		else
		{
			pCmdUI->SetText(_T("更改密码(&M)"));
		}
}

void CPrintCaseInfo2xDoc::OnUpdateMenuDelFileLock(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(ctrlFlag&FILE_CTRL_LOCKED);
}
