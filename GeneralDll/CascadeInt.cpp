// CascadeInt.cpp : 实现文件
//

#include "stdafx.h"
#include "CascadeInt.h"


// CCascadeInt

CCascadeInt::CCascadeInt()
{
	iMore=0;
}
CCascadeInt::CCascadeInt(CString strFlag)
{
	iMore=0;
	strHasMore = strFlag;
}

CCascadeInt::~CCascadeInt()
{
}


// CCascadeInt 成员函数
CString CCascadeInt::toString(CString fomater , CString otherStr)
{
    if ( strHasMore == strBase )
    {
        CString text;
        text.Format( fomater, iMore);
        return text;
    }
    return otherStr;
}


void CCascadeInt::Serialize(CArchive& ar)
{
    //TRACE("*******************BEGIN CCascadeInt::Serialize\n");
	CCascadeInfo::Serialize(ar);
	if (ar.IsStoring())
	{	// storing code
		if (strBase==strHasMore)
		{
			ar<<iMore;
		}
	}
	else
	{	// loading code
		if (strBase==strHasMore)
		{
			ar>>iMore;
		}
	}
	//TRACE("*******************END CCascadeInt::Serialize\n");
}

void CCascadeInt::operator=(const CCascadeInt& ci)
{
	strBase=ci.strBase;
	strHasMore=ci.strHasMore;
	iMore=ci.iMore;
	//	TRACE("\noperator="+strBase+"-"+strMore+"-"+strHasMore+"\n");
}

