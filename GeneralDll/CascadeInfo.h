#pragma once

// CCascadeInfo 命令目标

class  CCascadeInfo : public CObject
{
public:
	DECLARE_DYNCREATE(CCascadeInfo)
	CCascadeInfo();

	virtual ~CCascadeInfo();
	virtual void Serialize(CArchive& ar);
public:
	CString strBase;//基本信息
	CString strHasMore;//标示信息
};


