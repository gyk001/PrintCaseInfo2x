#pragma once
#include "afxpriv.h"
#include "afxres.h"

// CMyPreviewView 视图

class CMyPreviewView : public CPreviewView
{
	DECLARE_DYNCREATE(CMyPreviewView)

protected:
	CMyPreviewView();           // 动态创建所使用的受保护的构造函数
	virtual ~CMyPreviewView();

public:

#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
	//自定义关闭预览
	afx_msg void OnPreviewClose();
protected:
	//更新一/两页按钮
	afx_msg void OnUpdateNumPageChange(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};


