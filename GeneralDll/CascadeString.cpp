// CascadString.cpp : 实现文件
//

#include "stdafx.h"
#include "CascadeString.h"


// CCascadString

CCascadeString::CCascadeString()
{
}

CCascadeString::CCascadeString(CString strFlag)
{
	strHasMore=strFlag;
}

CCascadeString::~CCascadeString()
{
}


// CCascadString 成员函数

void CCascadeString::Serialize(CArchive& ar)
{
    //TRACE("*******************BEGIN CCascadeString::Serialize\n");
	CCascadeInfo::Serialize(ar);

	if (ar.IsStoring())
	{	// storing code
		if (strBase==strHasMore)
		{
			ar<<strMore;
		}
	}
	else
	{	// loading code
		if (strBase==strHasMore)
		{
			ar>>strMore;
		}
	}
    //TRACE("*******************End CCascadeString::Serialize\n");
}

void CCascadeString::operator=(const CCascadeString& cs)
{
	strBase=cs.strBase;
	strHasMore=cs.strHasMore;
	strMore=cs.strMore;
	//	TRACE(_T("\noperator=")+strBase+_T("-")+strMore+_T("-")+strHasMore+_T("\n"));
}

CString CCascadeString::toString(CString name)
{
    //CString text = name+_T("[")+strBase + _T("]");
    if (strBase==strHasMore)
    {
        return name+  _T(":") + strMore;
    }
	else
	{
		return name+  _T(":") + strBase;
	}
   // return text;
}