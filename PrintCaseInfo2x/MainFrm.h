// MainFrm.h : CMainFrame 类的接口
//


#pragma once

class CMainFrame :public CXTPFrameWndBase<CFrameWnd>
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
protected:
	enum eViewStatus
	{
		eSplitteView ,
		eSwitchView			
	};
private:
	eViewStatus  viewStatus;
	CView* pFView,*pMView;
public:
	CSplitterWnd m_wndSplitter;
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg void UpdateAppTitle();
	afx_msg void UpdateDocFromView();
public:
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
public:
	afx_msg void OnMenuMaleView();
public:
	afx_msg void OnMenuFemaleView();
	void SwitchView(CView*pNewView);
	//CView* ReplaceView(/*int nRow, int nCol,*/ CView* pNewView);
	//CView* ReplaceView(int nRow, int nCol, CRuntimeClass* pViewClass);
public:
	afx_msg void OnUpdateWindowSplit(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateMenuMaleView(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateMenuFemaleView(CCmdUI *pCmdUI);
	afx_msg void OnCustomize();
public:
	afx_msg void OnSoftConfig();
public:
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
};


