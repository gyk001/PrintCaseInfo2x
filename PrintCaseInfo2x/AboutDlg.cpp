// AboutDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PrintCaseInfo2x.h"
#include "AboutDlg.h"


// CAboutDlg 对话框

IMPLEMENT_DYNAMIC(CAboutDlg, CDialog)

CAboutDlg::CAboutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAboutDlg::IDD, pParent)
{

}

CAboutDlg::~CAboutDlg()
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_QQ, m_QQLink);
	DDX_Control(pDX, IDC_STATIC_GMAIL, m_GmailLink);
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CAboutDlg 消息处理程序

BOOL CAboutDlg::OnInitDialog()
{
//	extern const int appMarjorVersion ;
//extern const int appMinjorVersion ;
	CDialog::OnInitDialog();
	CString version ;
	version.Format(_T("[%d.%d 版]"),appMarjorVersion,appMinjorVersion);
		//= CString( "V"+appMarjorVersion);
	//version.Append(CString("."+appMinjorVersion));
	TRACE(version);
	GetDlgItem(IDC_STATIC_VERSION)->SetWindowText( version );
	// TODO:  在此添加额外的初始化
	m_GmailLink.SetURL( _T("mailto:Gyk001@Gmail.com?subject=【生殖医学病例打印程序】使用反馈"));
	m_QQLink.SetURL( _T("tencent://message/?uin=644655955"));


	_Init(&bp, AfxGetInstanceHandle(), GetDlgItem(IDC_STATIC_MESSAGE)->m_hWnd, IDB_BITMAP_ABOUT); 
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CAboutDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CDialog::OnMouseMove(nFlags, point);
}
