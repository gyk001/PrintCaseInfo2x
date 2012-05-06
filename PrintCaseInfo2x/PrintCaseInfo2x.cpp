// PrintCaseInfo2x.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "PrintCaseInfo2x.h"
#include "MainFrm.h"
#include "../GeneralDll/GeneralDll.h"
#include "PrintCaseInfo2xDoc.h"
#include "PrintCaseInfoView.h"
#include "AboutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPrintCaseInfo2xApp

BEGIN_MESSAGE_MAP(CPrintCaseInfo2xApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CPrintCaseInfo2xApp::OnAppAbout)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_FILE_NEW, &CPrintCaseInfo2xApp::OnFileNew)
END_MESSAGE_MAP()


// CPrintCaseInfo2xApp 构造

CPrintCaseInfo2xApp::CPrintCaseInfo2xApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
	TCHAR szStylesPath[_MAX_PATH];
	VERIFY(::GetModuleFileName(
		AfxGetApp()->m_hInstance, szStylesPath, _MAX_PATH));		

	m_strStylesPath = szStylesPath;
	int nIndex  = m_strStylesPath.ReverseFind(_T('\\'));
	if (nIndex > 0) {
		m_strStylesPath = m_strStylesPath.Left(nIndex);
	}
	else {
		m_strStylesPath.Empty();
	}
	m_strStylesPath += _T("\\Styles\\");
}


// 唯一的一个 CPrintCaseInfo2xApp 对象

CPrintCaseInfo2xApp theApp;
//程序版本号 2.3
const int appMarjorVersion = 2;
const int appMinjorVersion = 3;

//支持的文件版本号最低为 2.1
const int minSupportMarjorVersion = 2;
const int minSupportMinjorVersion = 1;



const CString fileTypeString = _T("printcaseinfo-yisufuyou");



// CPrintCaseInfo2xApp 初始化

BOOL CPrintCaseInfo2xApp::InitInstance()
{

	SetRegistryKey(_T("PrintCaseInfo"));
	CWnd *pSplashWnd = NULL;
//#ifndef _DEBUG 
	//调试模式不显示启动画面，也不加载皮肤
	pSplashWnd =	ShowSplashWnd();
	
	CXTPWinDwmWrapper().SetProcessDPIAware();
	XTPSkinManager()->SetApplyOptions(XTPSkinManager()->GetApplyOptions() | xtpSkinApplyMetrics);

	CString style;
	style = GetProfileString(  _T("Settings"), _T("theme") , _T("Office2007.Blue.cjstyles") );
	XTPSkinManager()->LoadSkin(  m_strStylesPath+style );	
	WriteProfileString( _T("Settings") , _T("theme") , style );
//#endif

	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	//SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)
	// 注册应用程序的文档模板。文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CPrintCaseInfo2xDoc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架窗口
		RUNTIME_CLASS(CPrintCaseInfoView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

		QuitSplashWnd( pSplashWnd);//退出闪屏界面
	// 启用“DDE 执行”
	EnableShellOpen();
	//RegisterShellFileTypes(TRUE);

	// 分析标准外壳命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// 调度在命令行中指定的命令。如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;



	//更新窗口标题
	//TRACE_FUNC();
	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// 仅当具有后缀时才调用 DragAcceptFiles
	//  在 SDI 应用程序中，这应在 ProcessShellCommand  之后发生
	// 启用拖/放
	m_pMainWnd->DragAcceptFiles();
	return TRUE;
}


// 用于运行对话框的应用程序命令
void CPrintCaseInfo2xApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CPrintCaseInfo2xApp 消息处理程序




void CPrintCaseInfo2xApp::OnFileNew()
{
	if (m_pMainWnd)
	{	//发送消息更新文档信息，防止视图和文档数据不同步
		m_pMainWnd->SendMessage(WM_UPDATE_DOC_FROM_VIEW );
	}

	CWinApp::OnFileNew();
}

CString CPrintCaseInfo2xApp::GetStylesPath(void)
{
	return m_strStylesPath;
}
