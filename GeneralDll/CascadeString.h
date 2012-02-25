#pragma once
#include "CascadeInfo.h"
// CCascadString 命令目标

class AFX_EXT_CLASS CCascadeString : public CCascadeInfo
{
public:
	CCascadeString();
	CCascadeString(CString strFlag);
	virtual ~CCascadeString();
	CString strMore;//详细信息
public:
	virtual void Serialize(CArchive& ar);
	void operator=(const CCascadeString& cs);
    CString toString(CString name);
};


