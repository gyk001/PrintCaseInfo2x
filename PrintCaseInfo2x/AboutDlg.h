#pragma once
#include "hyperlink.h"
#include "waveLib.h"

// CAboutDlg 对话框

class CAboutDlg : public CDialog
{
	DECLARE_DYNAMIC(CAboutDlg)

public:
	CAboutDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAboutDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CHyperLink m_QQLink;
	CHyperLink m_GmailLink;
	_WAVE_OBJECT bp;
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
