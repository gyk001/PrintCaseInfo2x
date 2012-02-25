// PasswordDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PrintCaseInfo2x.h"
#include "PasswordDlg.h"


// CPasswordDlg 对话框

IMPLEMENT_DYNAMIC(CPasswordDlg, CDialog)

CPasswordDlg::CPasswordDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPasswordDlg::IDD, pParent)
	, m_password(_T(""))
	,dlgFlag ( DKF_VLD)
{

}

CPasswordDlg::~CPasswordDlg()
{
}

void CPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
}


BEGIN_MESSAGE_MAP(CPasswordDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CPasswordDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CPasswordDlg 消息处理程序


BOOL CPasswordDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	switch (dlgFlag)
	{
		case DKF_SET:
			SetWindowText( _T("文件加锁") );
			GetDlgItem( IDOK )->SetWindowText( _T("文件加锁(&P)") );
			GetDlgItem( IDC_STATIC_MESSAGE )->SetWindowText( _T("文件加锁，请输入解锁密码") );
			break;
		case DKF_VLD:	
			SetWindowText( _T("文件解锁") );
			GetDlgItem( IDOK )->SetWindowText( _T("文件解锁(&D)") );
			GetDlgItem( IDC_STATIC_MESSAGE )->SetWindowText( _T("文件已加锁，请输入解锁密码") );
			break;
		default:
			TRACE(_T("error:dlgFlag is not Set!\n"));
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CPasswordDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	switch (dlgFlag)
	{
	case DKF_SET:
		if (m_password.IsEmpty())
		{

			GetDlgItem( IDC_STATIC_MESSAGE )->SetWindowText( _T("密码不能为空！") );
			GetDlgItem( IDC_EDIT_PASSWORD )->SetFocus();
			

		}
		else
		{
			OnOK();	
		}
		break;
	case DKF_VLD:
		if (m_password != m_docPassword)
		{
			GetDlgItem( IDC_STATIC_MESSAGE )->SetWindowText( _T("密码错误，请重新输入") );
			GetDlgItem( IDC_EDIT_PASSWORD )->SetFocus();
		}
		else
		{
			OnOK();
		}
		break;
	}
}
