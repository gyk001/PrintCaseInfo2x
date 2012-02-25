// PrintCaseInfo2xDoc.h : CPrintCaseInfo2xDoc 类的接口
//
#pragma once
#include "../PciCoreDll/FemaleInfo.h"
#include "../PciCoreDll/MaleInfo.h"
#include "../PciCoreDll/CommonInfo.h"

#define  FILE_CTRL_LOCKED 0x01
#define  FILE_CTRL_MINOR_VERSION 0x02	//包含次版本号信息




class CPrintCaseInfo2xDoc : public CDocument
{
protected: // 仅从序列化创建
	CPrintCaseInfo2xDoc();
	DECLARE_DYNCREATE(CPrintCaseInfo2xDoc)

// 属性
public:
public:
	CCommonInfo commonInfo;    //通用信息
	CMaleInfo maleInfo; //男士信息
	CFemaleInfo femaleInfo;//女士信息

	int    majorVersion;            //文件的程序主版本号
	int	minorVersion;		//文件的程序次版本号		

	UINT ctrlFlag;       //控制信息位
	CString  password;   //文件解锁密码

// 操作
public:

// 重写
public:
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~CPrintCaseInfo2xDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CString   Ser(CString   yuanwen) ;
	CString   unSer(CString   yuanwen) ;
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void ReportSaveLoadException(LPCTSTR lpszPathName, CException* e, BOOL bSaving, UINT nIDPDefault);
	//重载为已修改文档标题加星
	virtual void SetModifiedFlag(BOOL bModified);
public:
	virtual void DeleteContents();
public:
	//接收视图数据，更新文档
	virtual BOOL UpdateDocFromView();
	//重载为先同步数据再保存文件
	virtual BOOL DoFileSave( );
	//检查密码
	BOOL ValidatePassword( const CString password);
	//读取文件
	void ReadFile(CArchive& ar);

public:
	afx_msg void OnExportToWord();
public:
	afx_msg void OnMenuFileLock();
public:
	afx_msg void OnMenuDelFileLock();
public:
	afx_msg void OnUpdateMenuFileLock(CCmdUI *pCmdUI);
public:
	afx_msg void OnUpdateMenuDelFileLock(CCmdUI *pCmdUI);
};


