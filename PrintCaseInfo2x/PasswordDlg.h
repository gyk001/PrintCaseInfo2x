#pragma once


// CPasswordDlg 对话框

class CPasswordDlg : public CDialog
{
	DECLARE_DYNAMIC(CPasswordDlg)
public:	
	enum DlgKindFlag
	{
		DKF_SET,//设置密码
		DKF_DEL,//删除密码
		DKF_VLD//验证密码
	};
	DlgKindFlag dlgFlag;
	CPasswordDlg(  CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPasswordDlg();
	CString m_password;
	CString m_docPassword;
// 对话框数据
	enum { IDD = IDD_PASSWORD_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	virtual BOOL OnInitDialog();
};
