// MyComboBox.cpp : 实现文件
//

#include "stdafx.h"
#include "MyComboBox.h"


// CMyComboBox

IMPLEMENT_DYNAMIC(CMyComboBox, CComboBox)

CMyComboBox::CMyComboBox()
{
}

void CMyComboBox::Init( UINT theEditID , CString EnableText)
{
    CComboBox();
    this->theEditID = theEditID;
    this->EnableText = EnableText;
}
CMyComboBox::~CMyComboBox()
{
}


BEGIN_MESSAGE_MAP(CMyComboBox, CComboBox)
    ON_CONTROL_REFLECT(CBN_SELCHANGE, &CMyComboBox::OnCbnSelchange)
END_MESSAGE_MAP()



// CMyComboBox 消息处理程序


void CMyComboBox::OnCbnSelchange()
{
    Check();
}

void CMyComboBox::Check()
{
    CString text;
    GetWindowText(text);
    CWnd * p = GetParent()->GetDlgItem( theEditID );
    if ( p )
    {
        p->EnableWindow( text == EnableText );
    }
}