//////////////////////////////////////////////////////////////////////////////
//启动画面类，继承CWnd窗口类
class CSplashWnd : public CWnd
{
public:
	CBitmap bitmap;									//建立位图实例
	BITMAP mapInfo;									//建立位图信息实例
	CSplashWnd();
	~CSplashWnd();
	void QuitSplashWnd();
protected:
	afx_msg BOOL OnCreate(LPCREATESTRUCT lpcs);
	afx_msg BOOL OnEraseBkgnd(CDC *pDC);
	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
public:
	afx_msg void OnPaint();
};