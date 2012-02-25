// DocExportDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PrintCaseInfo2x.h"
#include "DocExportDlg.h"


// CDocExportDlg 对话框

IMPLEMENT_DYNAMIC(CDocExportDlg, CDialog)

CDocExportDlg::CDocExportDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDocExportDlg::IDD, pParent)

{

}

CDocExportDlg::~CDocExportDlg()
{
	if (pInfo)
	{
		delete pInfo;
	}
}

void CDocExportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX ,IDC_PROGRESS1 ,m_progressCtrl);
}


BEGIN_MESSAGE_MAP(CDocExportDlg, CDialog)
	ON_BN_CLICKED(IDC_OPEN_WORD, &CDocExportDlg::OnBnClickedOpenWord)
	ON_BN_CLICKED(IDC_PREVIEW_WORD, &CDocExportDlg::OnBnClickedPreviewWord)
	ON_BN_CLICKED(IDC_SAVE_WORD, &CDocExportDlg::OnBnClickedSaveWord)
	ON_BN_CLICKED(IDCANCEL, &CDocExportDlg::OnBnClickedCancel)
	ON_MESSAGE_VOID(WM_DLG_CLOSE,CloseIt )
	ON_MESSAGE_VOID(WM_EXPORT_FINISHED,OnExportFinished )	
	ON_MESSAGE_VOID(WM_EXPORT_STEP_IT,OnStepIt )	
END_MESSAGE_MAP()


// CDocExportDlg 消息处理程序

BOOL CDocExportDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_progressCtrl.SetRange32(0,1000);
	m_progressCtrl.SetStep(1);
	pInfo=new CDocExportInfo( this , pCidDoc);
	pThread = AfxBeginThread(DocExportThreadProc,(LPVOID) pInfo, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	pThread->ResumeThread();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

//关闭对话框，此时应确保线程已经退出
void CDocExportDlg::CloseIt(void)
{
	//无需数据交换，直接调用OnCancel
	CDialog::OnCancel();
}

//用Word打开
void CDocExportDlg::OnBnClickedOpenWord()
{
	// TODO: 在此添加控件通知处理程序代码
	pInfo->bExit = DOC_EXPORT_OPEN;
	pThread->ResumeThread();
}

//在Word中预览
void CDocExportDlg::OnBnClickedPreviewWord()
{
	// TODO: 在此添加控件通知处理程序代码
	pInfo->bExit = DOC_EXPORT_PREVIEW;
	pThread->ResumeThread();
}

//保存为Word文档
void CDocExportDlg::OnBnClickedSaveWord()
{
	// TODO: 在此添加控件通知处理程序代码
	pInfo->bExit = DOC_EXPORT_SAVE;
	pThread->ResumeThread();
}

//点击取消按钮
void CDocExportDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_STATIC_MSG)->SetWindowText(_T("正在取消，请稍后..."));
	//通知线程退出
	pInfo->bExit =DOC_EXPORT_CANCEL;	
	pThread->ResumeThread();
}

//导出完毕，更改界面状态
void CDocExportDlg::OnExportFinished(void)
{
	GetDlgItem(IDC_OPEN_WORD)->EnableWindow();
	GetDlgItem(IDC_PREVIEW_WORD)->EnableWindow();
	GetDlgItem(IDC_SAVE_WORD)->EnableWindow();
	GetDlgItem(IDC_STATIC_MSG)->SetWindowText(_T("导出完毕！"));

}

// 推进滚动条
void CDocExportDlg::OnStepIt(void)
{
	m_progressCtrl.StepIt();
}

