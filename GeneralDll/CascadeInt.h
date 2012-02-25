#pragma once
#include "CascadeInfo.h"
// CCascadeInt ÃüÁîÄ¿±ê

class AFX_EXT_CLASS CCascadeInt : public CCascadeInfo
{
public:
	CCascadeInt();
	CCascadeInt(CString strFlag);
	virtual ~CCascadeInt();
public:
	int iMore;
public:
	virtual void Serialize(CArchive& ar);
	void operator=(const CCascadeInt& ci);
    CString toString(CString fomater , CString otherStr);
};


