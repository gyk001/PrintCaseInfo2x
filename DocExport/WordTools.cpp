#include "WordTools.h"
// WordTools.cpp : 实现文件
//

#include "stdafx.h"
#include "Resource.h"
#include "DocExport.h"


// CWordTools

CWordTools::CWordTools()
{
	
}

CWordTools::~CWordTools()
{
	COleVariant vTrue((short)TRUE),    
		vFalse((short)FALSE),
		vOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	//m_wdDoc.Save();
// 	m_wdApp.Quit(vFalse,    // SaveChanges.
// 		vTrue,            // OriginalFormat.
// 		vFalse            // RouteDocument.
// 		);
	//释放内存申请资源
	//m_wdBookmark.ReleaseDispatch();
	m_wdBookmarks.ReleaseDispatch();
	m_wdInlineShape.ReleaseDispatch();
	m_wdInlineShapes.ReleaseDispatch();
	//m_wdTb.ReleaseDispatch();
	m_wdRange.ReleaseDispatch();
	m_wdSel.ReleaseDispatch();
	//m_wdFt.ReleaseDispatch();
	m_wdDoc.ReleaseDispatch();
	m_wdDocs.ReleaseDispatch();
	m_wdApp.ReleaseDispatch();
}



BOOL CWordTools::CreateApp()
{
	if (FALSE == m_wdApp.CreateDispatch(_T("Word.Application")))
	{
		AfxMessageBox(_T("Application创建失败，请确保安装了word 2000或以上版本!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	return TRUE;
}

BOOL CWordTools::CreateDocuments()
{
	if (FALSE == CreateApp()) 
	{
		return FALSE;
	}
	m_wdDocs.AttachDispatch(m_wdApp.GetDocuments());
	if (!m_wdDocs.m_lpDispatch) 
	{
		AfxMessageBox(_T("Documents创建失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	return TRUE;
}
BOOL CWordTools::CreateDocument(CString DocTemplate/* = _T("")*/)
{
	if (!m_wdDocs.m_lpDispatch) 
	{
		AfxMessageBox(_T("Documents为空!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	if (DocTemplate.IsEmpty())
	{
		//CString strDotName;
		//CHAR szSknName [ MAX_PATH ];
		if( !ResToFile( IDR_PCI_DOT,_T("DOT"), DocTemplate))
		{
			//AfxMessageBox(_T("d"));
			return FALSE;
		}	
	}
	COleVariant varTrue(short(1),VT_BOOL),vOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	CComVariant Template(DocTemplate);    //没有使用WORD的文档模板
	CComVariant NewTemplate(false),DocumentType(0),Visible;

	m_wdDocs.Add(&Template,&NewTemplate,&DocumentType,&Visible);    

	//得到document变量
	m_wdDoc = m_wdApp.GetActiveDocument();
	if (!m_wdDoc.m_lpDispatch) 
	{
		AfxMessageBox(_T("Document获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	//得到selection变量
	m_wdSel = m_wdApp.GetSelection();
	if (!m_wdSel.m_lpDispatch) 
	{
		AfxMessageBox(_T("Select获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	//得到Range变量
	m_wdRange = m_wdDoc.Range(vOptional,vOptional);
	if(!m_wdRange.m_lpDispatch)
	{
		AfxMessageBox(_T("Range获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	//得到Bookmark变量
	m_wdBookmarks = m_wdDoc.GetBookmarks();
	if(!m_wdBookmarks.m_lpDispatch)
	{
		AfxMessageBox(_T("Bookmark获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	return TRUE;
}

BOOL CWordTools::Create(CString DocTemplate/* = _T("")*/)
{
	if (FALSE == CreateDocuments()) 
	{
		return FALSE;
	}
	return CreateDocument(DocTemplate);
}

void CWordTools::ShowApp()
{
	m_wdApp.SetVisible(TRUE);
	m_wdApp.Activate();
}

void CWordTools::PrintPreview()
{
	m_wdApp.SetVisible(TRUE);
	m_wdApp.Activate();
	m_wdDoc.PrintPreview();

}

void CWordTools::HideApp()
{
	m_wdApp.SetVisible(FALSE);
}

BOOL CWordTools::OpenDocument(CString fileName)
{
	if (!m_wdDocs.m_lpDispatch) 
	{
		AfxMessageBox(_T("Documents为空!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}

	COleVariant vTrue((short)TRUE),    
		vFalse((short)FALSE),
		vOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR),
		vZ((short)0);
	COleVariant     vFileName(fileName);

	//得到document变量
	m_wdDoc.AttachDispatch(m_wdDocs.Open(
		vFileName,        // FileName
		vTrue,            // Confirm Conversion.
		vFalse,            // ReadOnly.
		vFalse,            // AddToRecentFiles.
		vOptional,        // PasswordDocument.
		vOptional,        // PasswordTemplate.
		vOptional,        // Revert.
		vOptional,        // WritePasswordDocument.
		vOptional,        // WritePasswordTemplate.
		vOptional,        // Format. // Last argument for Word 97
		vOptional,        // Encoding // New for Word 2000/2002
		vOptional,        // Visible
		//*如下4个是word2003需要的参数。本版本是word2000。
			vOptional,    // OpenAndRepair
			vZ,            // DocumentDirection wdDocumentDirection LeftToRight
			vOptional,    // NoEncodingDialog
			vOptional
			)                // Close Open parameters
			);                    // Close AttachDispatch

	if (!m_wdDoc.m_lpDispatch) 
	{
		AfxMessageBox(_T("Document获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	//得到selection变量
	m_wdSel = m_wdApp.GetSelection();
	if (!m_wdSel.m_lpDispatch) 
	{
		AfxMessageBox(_T("Select获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	//得到全部DOC的Range变量
	m_wdRange = m_wdDoc.Range(vOptional,vOptional);
	if(!m_wdRange.m_lpDispatch)
	{
		AfxMessageBox(_T("Range获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	return TRUE;
}

BOOL CWordTools::Open(CString fileName)
{
	if (FALSE == CreateDocuments()) 
	{
		return FALSE;
	}
	return OpenDocument(fileName);
}

BOOL CWordTools::SetActiveDocument(short i)
{
	COleVariant     vIndex(i),vOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	m_wdDoc.AttachDispatch(m_wdDocs.Item(vIndex));
	m_wdDoc.Activate();
	if (!m_wdDoc.m_lpDispatch) 
	{
		AfxMessageBox(_T("Document获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	//得到selection变量
	m_wdSel = m_wdApp.GetSelection();
	if (!m_wdSel.m_lpDispatch) 
	{
		AfxMessageBox(_T("Select获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	//得到全部DOC的Range变量
	m_wdRange = m_wdDoc.Range(vOptional,vOptional);
	if(!m_wdRange.m_lpDispatch)
	{
		AfxMessageBox(_T("Range获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	HideApp();
	return TRUE;
}

BOOL CWordTools::SaveDocument()
{
	if (!m_wdDoc.m_lpDispatch) 
	{
		AfxMessageBox(_T("Document获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	m_wdDoc.Save();
	return TRUE;
}

BOOL CWordTools::SaveDocumentAs(CString fileName)
{
	if (!m_wdDoc.m_lpDispatch) 
	{
		AfxMessageBox(_T("Document获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	COleVariant vTrue((short)TRUE),    
		vFalse((short)FALSE),
		vOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	COleVariant vFileName(fileName);

	m_wdDoc.SaveAs(
		vFileName,		//Filename
		COleVariant( (long) wdFormatDocument),				//wdFormatDOSText   =   4 
		vFalse,				//LockComments   
		COleVariant(_T("")),		//Password   
		vFalse,				//Add   to   recent   files
		COleVariant(_T("")),		//Write   password  
		vFalse,			//ReadOnlyRecommended   
		vFalse,			//Embed   TrueType   fonts   
		vFalse,			//SaveNativePictureFormat   
		vFalse,			//SaveForms   data   
		vFalse,			//SaveAsAOCELetter
		vFalse,			//Encoding   
		vFalse,			//InsertLineBreaks   
		vFalse,			//AllowSubstitutions   
		vFalse,			//LineEnding   
		vFalse			//AddBiDiMarks   
		); 

	return    TRUE;
}

BOOL CWordTools::CloseDocument()
{
	COleVariant vTrue((short)TRUE),    
		vFalse((short)FALSE),
		vOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	m_wdDoc.Close(vFalse,    // SaveChanges.
		vTrue,            // OriginalFormat.
		vFalse            // RouteDocument.
		);
	m_wdDoc.AttachDispatch(m_wdApp.GetActiveDocument());
	if (!m_wdDoc.m_lpDispatch) 
	{
		AfxMessageBox(_T("Document获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	//得到selection变量
	m_wdSel = m_wdApp.GetSelection();
	if (!m_wdSel.m_lpDispatch) 
	{
		AfxMessageBox(_T("Select获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	//得到全部DOC的Range变量
	m_wdRange = m_wdDoc.Range(vOptional,vOptional);
	if(!m_wdRange.m_lpDispatch)
	{
		AfxMessageBox(_T("Range获取失败!"), MB_OK|MB_ICONWARNING);
		return FALSE;
	}
	return TRUE;
}

void CWordTools::CloseApp()
{
	COleVariant vTrue((short)TRUE),    
		vFalse((short)FALSE);
	m_wdApp.Quit(vFalse,    // SaveChanges.
		vTrue,            // OriginalFormat.
		vFalse            // RouteDocument.
		);
	//释放内存申请资源
	//m_wdBookmark.ReleaseDispatch();
	m_wdBookmarks.ReleaseDispatch();
	m_wdInlineShape.ReleaseDispatch();
	m_wdInlineShapes.ReleaseDispatch();
	//m_wdTb.ReleaseDispatch();
	m_wdRange.ReleaseDispatch();
	m_wdSel.ReleaseDispatch();
	//m_wdFt.ReleaseDispatch();
	m_wdDoc.ReleaseDispatch();
	m_wdDocs.ReleaseDispatch();
	m_wdApp.ReleaseDispatch();
}

void CWordTools::WriteText(CString szText)
{
	m_wdSel.TypeText(szText);
}

void CWordTools::WriteNewLineText(CString szText, int nLineCount /**//* = 1 */)
{
	int i;
	if (nLineCount <= 0)
	{
		nLineCount = 0;
	}
	for (i = 0; i < nLineCount; i++)
	{
		m_wdSel.TypeParagraph();
	}
	WriteText(szText);
}

void CWordTools::WriteEndLine(CString szText)
{
	m_wdRange.InsertAfter(szText);
}

void CWordTools::WholeStory()
{
	m_wdRange.WholeStory();
}

void CWordTools::Copy()
{
	m_wdRange.CopyAsPicture();
}

void CWordTools::InsertFile(CString fileName)
{
	COleVariant     vFileName(fileName),
		vTrue((short)TRUE),
		vFalse((short)FALSE),
		vOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR),
		vNull(_T(""));
	/**//*
		void InsertFile(LPCTSTR FileName, VARIANT* Range, VARIANT* ConfirmConversions, VARIANT* Link, VARIANT* Attachment);
		*/
	m_wdSel.InsertFile(
		fileName,
		vNull,
		vFalse,
		vFalse,
		vFalse
		);
}

void CWordTools::InsertShapes(CString fileName)
{
	COleVariant vTrue((short)TRUE),    
		vFalse((short)FALSE),
		vOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	m_wdInlineShapes=m_wdSel.GetInlineShapes();
	m_wdInlineShape=m_wdInlineShapes.AddPicture(fileName,vFalse,vTrue,vOptional);
}

void CWordTools::InsertHyperlink(CString fileLink)
{
	COleVariant     vAddress(fileLink),vSubAddress(_T(""));
	Range aRange = m_wdSel.GetRange();
	Hyperlinks vHyperlinks(aRange.GetHyperlinks());

	vHyperlinks.Add(
		aRange,            //Object，必需。转换为超链接的文本或图形。
		vAddress,         //Variant 类型，可选。指定的链接的地址。此地址可以是电子邮件地址、Internet 地址或文件名。请注意，Microsoft Word 不检查该地址的正确性。
		vSubAddress,     //Variant 类型，可选。目标文件内的位置名，如书签、已命名的区域或幻灯片编号。
		vAddress,         //Variant 类型，可选。当鼠标指针放在指定的超链接上时显示的可用作“屏幕提示”的文本。默认值为 Address。
		vAddress,         //Variant 类型，可选。指定的超链接的显示文本。此参数的值将取代由 Anchor 指定的文本或图形。
		vSubAddress        //Variant 类型，可选。要在其中打开指定的超链接的框架或窗口的名字。
		); 
	vHyperlinks.ReleaseDispatch();
}
// 查找bkName书签，并修改内容为bkText，成功返回TRUE，失败返回FALSE
BOOL CWordTools::BookmarkText(CString bkName, CString bkText)
{
	if(!m_wdBookmarks.Exists(bkName))
	{
	//	AfxMessageBox(bkName_T("不存在"));
		return FALSE;
	}
	COleVariant  vWhat((long)wdGoToBookmark),//宏中值是-1
		vWhich,//录制宏中没这个参数
		vCount((short)0),//录制宏中没这个参数，估计是第几个书签
		vName(bkName);//书签名
	m_wdSel.GoTo(vWhat,vWhich,vCount,vName);
	m_wdSel.TypeText(bkText);
	return TRUE;
}

// 删除书签，成功返回TRUE，失败返回FALSE
BOOL CWordTools::DeleteAllBookmarks()
{
/*
	for (int i=0;i<m_wdBookmarks.GetCount();i++)
	{
		COleVariant vI((long)i);
		((Bookmark*)m_wdBookmarks.Item(vI))->Delete();
	}
	return TRUE;
	*/
	return FALSE;
}



void CWordTools::ActivateApp(void)
{
	m_wdApp.Activate();
}
