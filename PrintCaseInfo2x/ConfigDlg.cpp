// ConfigDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PrintCaseInfo2x.h"
#include "ConfigDlg.h"


// CConfigDlg 对话框

IMPLEMENT_DYNAMIC(CConfigDlg, CDialog)

CConfigDlg::CConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigDlg::IDD, pParent)
	, m_strStyle(_T(""))
	, m_VS(0)
{

}

CConfigDlg::~CConfigDlg()
{
}

void CConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_STYTLE, ctrlComboStytleFile);
	DDX_CBString(pDX, IDC_COMBO_STYTLE, m_strStyle);
	DDX_CBIndex(pDX, IDC_COMBO_VIEW, m_VS);
	DDX_Control(pDX, IDC_COMBO_VIEW, ctrlComboView);
}


BEGIN_MESSAGE_MAP(CConfigDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CConfigDlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO_STYTLE, &CConfigDlg::OnCbnSelchangeComboStyle)
	ON_CBN_SELCHANGE(IDC_COMBO_VIEW, &CConfigDlg::OnCbnSelchangeComboView)
END_MESSAGE_MAP()


// CConfigDlg 消息处理程序

void CConfigDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}

BOOL CConfigDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CString   fileName;   
	CFileFind   m_find;   
	ctrlComboStytleFile.AddString( _T("无风格"));   
	if(m_find.FindFile( theApp.GetStylesPath()+_T("*.cjstyles") , 0 ) )   
	{   
		while(m_find.FindNextFile())   
		{   

			fileName   =   m_find.GetFileName();   
			ctrlComboStytleFile.AddString(fileName);   

		}   
		fileName   =   m_find.GetFileName();   
		ctrlComboStytleFile.AddString(fileName);   
	}   
	m_find.Close();//查找文件完毕   

	CString style;
	style = theApp.GetProfileString(  _T("Settings"), _T("theme") , _T("无风格") );
	int sel = ctrlComboStytleFile.SelectString( -1 ,style);

	if ( sel>0 )
	{
		ctrlComboStytleFile.SetCurSel( sel );
	}
	int vs ;
	vs = theApp.GetProfileInt(  _T("Settings"), _T("Vscombo") , 0 );
	ctrlComboView.SetCurSel( vs );

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CConfigDlg::OnCbnSelchangeComboStyle()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData( );
	TRACE(m_strStyle+_T("\n"));
	theApp.WriteProfileString( _T("Settings") , _T("theme") , m_strStyle );
	XTPSkinManager()->LoadSkin( theApp.GetStylesPath()+m_strStyle );	
	//XTPSkinManager()->
}

void CConfigDlg::OnCbnSelchangeComboView()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData( );
	theApp.WriteProfileInt( _T("Settings") , _T("Vscombo") , m_VS );
	AfxMessageBox(_T("更改将在下次启动时生效！"));
}
