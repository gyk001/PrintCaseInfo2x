// CascadeInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "CascadeInfo.h"

IMPLEMENT_DYNCREATE(CCascadeInfo, CObject)
// CCascadeInfo

CCascadeInfo::CCascadeInfo()
{
}

CCascadeInfo::~CCascadeInfo()
{
}


// CCascadeInfo 成员函数
// CPrintCaseInfoDoc 序列化

void CCascadeInfo::Serialize(CArchive& ar)
{

	if (ar.IsStoring())
	{
		ar<<strBase<<strHasMore;
	}
	else
	{
		ar>>strBase>>strHasMore;
	}
	//TRACE(_T("Serialize ")+strBase+_T("-")+strHasMore+_T(" \n"));
    //TRACE("*******************END CCascadeInfo::Serialize\n");
}
