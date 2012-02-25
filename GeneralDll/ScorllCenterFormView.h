#pragma once
#include "stdafx.h"
#include "float.h"
#include "resource.h"
#include "MyComboBox.h"
#include "MyPreviewView.h"


// CScorllCenterFormView 窗体视图
class AFX_EXT_CLASS CScorllCenterFormView : public CFormView
{
	DECLARE_DYNCREATE(CScorllCenterFormView)

protected:
	CScorllCenterFormView(UINT nIDTemplate=IDD);           // 动态创建所使用的受保护的构造函数
	virtual ~CScorllCenterFormView();

public:
	enum { IDD = IDD_FORMVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	//调整控件居中的变量
	int viewWidth;
private:
	// 总是用滚轮滚动视图
	bool bAlwaysScrollWithWheel;
	int newSeek;
	int oldSeek;
	bool bCtrlFocus;
public:
	void resetAllComboBox(  );
	void CheckAllComboBox(  );
private:
	//滚动视图位置至下一TAB控件
	BOOL MoveViewToNextTAB(  );
	//移动使居中
	void MoveAllCtrl(  int x );
	//判断是否为多行编辑框
	BOOL   IsMultEdit(   CWnd*   pWnd   ) ;
	//判断是否为组合框
	BOOL   IsCombBox(   CWnd*   pWnd   )   ;
protected: 
	/****          给CFormView添加打印支持         *****/
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	/***************************************************/
	//打印预览
	afx_msg void OnFilePrintPreview();
public:
	virtual void OnInitialUpdate();
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
public:
	//分割视图鼠标滚轮消息的响应需要重载下面两个函数
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

public:
	//鼠标滚轮始终用以滚动视图
	void AlwaysScrollWithWheel(bool bAlways);
protected:
	//更新一个控件的数据
	virtual BOOL UpdateDataOneCtrl( UINT id , BOOL bSaveAndValidate = TRUE );
	virtual void DoDataExchangeOneCtrl( UINT id , CDataExchange* pDX);
protected:
	//自定义控件变量交换函数，关联文档的修改标志
	void DDX_Text_UINT(CDataExchange* pDX, int nIDC, UINT& value);
	void DDX_Text_CSTRING(CDataExchange* pDX, int nIDC, CString& value);
	void DDX_Text_INT(CDataExchange* pDX, int nIDC, int& value);
	void DDX_Text_FLOAT(CDataExchange* pDX, int nIDC, float& value);
	void DDX_CBString_CSTRING(CDataExchange* pDX, int nIDC, CString& value);
	void DDX_DateTimeCtrl_CTIME(CDataExchange* pDX, int nIDC, CTime& value);
private:
	//自定义Float和Double变量交换函数，DDX_Text_FLOAT会调用该函数
	void  AfxTextFloatFormat(CDataExchange* pDX, int nIDC,
		void* pData, double value, int nSizeGcvt);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
};
//控件变量交换函数需要调用该函数
extern  void AFX_CDECL _Afx_DDX_TextWithFormat(CDataExchange* pDX, int nIDC,
												  LPCTSTR lpszFormat, UINT nIDPrompt, ...);

