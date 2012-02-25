#include <stdafx.h>
#include "SplashWnd.h"
#include "Resource.h"
//////////////////////////////////////////////////////////////////////////////
//CSplashWnd消息循环
BEGIN_MESSAGE_MAP(CSplashWnd, CWnd)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////
//CSplashWnd构造函数
CSplashWnd::CSplashWnd()
{
	bitmap.LoadBitmap(IDB_SPLASH);						//加载位图资源
	bitmap.GetBitmap(&mapInfo);						//获取位图信息
	
	//
	//注册WNDCLASS
	//
	CString strWndClass;

	strWndClass = AfxRegisterWndClass(
		NULL,
		AfxGetApp() ->LoadStandardCursor(IDC_ARROW),
		NULL,
		NULL);

#ifdef _DEBUG //调试状态禁用TOPMOST属性，方便调试
	DWORD exStyle = WS_EX_TOOLWINDOW ;
#else
	DWORD exStyle = WS_EX_TOOLWINDOW  | WS_EX_TOPMOST ;
#endif
	CreateEx( exStyle, strWndClass, NULL, WS_POPUP, CW_USEDEFAULT, CW_USEDEFAULT,
		mapInfo.bmWidth, mapInfo.bmHeight,NULL, NULL, NULL );
}

//////////////////////////////////////////////////////////////////////////////
//CSplashWnd析构函数
CSplashWnd::~CSplashWnd()
{
	
}

//CSplashAlpha窗口建立消息函数,对应WM_CREATE
BOOL CSplashWnd::OnCreate(LPCREATESTRUCT lpcs)
{
	//居中渐显窗口
	CenterWindow();
	AnimateWindow(500, AW_BLEND);
	return true;
}

void CSplashWnd::QuitSplashWnd()
{
	//渐隐窗口
	AnimateWindow(300, AW_BLEND | AW_HIDE);
	PostMessage(WM_CLOSE);
}

//////////////////////////////////////////////////////////////////////////////
//窗体背景重绘消息函数，对应消息ON_ERASEBKGND
BOOL CSplashWnd::OnEraseBkgnd(CDC *pDC)
{
	CDC dcMem;										//建立内存设备
	dcMem.CreateCompatibleDC(pDC);					//使内存设备和pDC设备兼容

	CBitmap *pOldBitmap = dcMem.SelectObject(&bitmap);  //保存原有设备，载入新设备
	//dcMem.TextOut(0,0,_T("ffffffffffffff"));	
	pDC ->BitBlt(0, 0, mapInfo.bmWidth, mapInfo.bmHeight, &dcMem, 0, 0, SRCCOPY);
	//从内存设备传送位图到pDC设备
	pDC ->SelectObject(pOldBitmap);					//恢复原有设备(删除原有设备)
	return true;
}

void CSplashWnd::PostNcDestroy()
{
	// TODO: 在此添加专用代码和/或调用基类
	CWnd::PostNcDestroy();
	//释放空间，本窗口为new
	delete this;
}


