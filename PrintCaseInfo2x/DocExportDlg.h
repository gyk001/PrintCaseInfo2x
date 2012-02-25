#pragma once
#include "DocExportInfo.h"

// CDocExportDlg 对话框

class CDocExportDlg : public CDialog
{
	DECLARE_DYNAMIC(CDocExportDlg)

public:
	CDocExportDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDocExportDlg();

// 对话框数据
	enum { IDD = IDD_DOC_EXPORT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CProgressCtrl m_progressCtrl;

	DECLARE_MESSAGE_MAP()
public:	
	CPrintCaseInfo2xDoc *pCidDoc;
	CDocExportInfo *pInfo;
	virtual BOOL OnInitDialog();
private:
	CWinThread *pThread;
public:
	void CloseIt(void);
public:
	afx_msg void OnBnClickedOpenWord();
public:
	afx_msg void OnBnClickedPreviewWord();
public:
	afx_msg void OnBnClickedSaveWord();
public:
	afx_msg void OnBnClickedCancel();
public:
//	bool bFinished;
public:
	void OnExportFinished(void);
public:
	// 推进滚动条
	void OnStepIt(void);
};
