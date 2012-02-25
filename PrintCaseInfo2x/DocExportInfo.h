#pragma once
#include "PrintCaseInfo2xDoc.h"
#include "../DocExport/WordTools.h"
// CDocExportInfo 命令目标

class CDocExportInfo : public CObject
{
public:
	//线程控制对话框
	CDialog * pDlg;	
	//是否继续执行
	BOOL bExit;
	//文档指针
	CPrintCaseInfo2xDoc * pDoc;
	//Word工具
	CWordTools wdt;

	

public:
	CDocExportInfo(CDialog* pDlg , 	CPrintCaseInfo2xDoc * pDoc );
	virtual ~CDocExportInfo();
public:
	BOOL SBT(CString bkName, CString bkText);
public:
	BOOL DocInit(void);
public:
	void ShowWordApp(void);
};


