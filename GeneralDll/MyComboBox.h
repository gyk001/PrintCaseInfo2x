#pragma once
// CMyComboBox

class  AFX_EXT_CLASS CMyComboBox : public CComboBox 
{
	DECLARE_DYNAMIC(CMyComboBox)

public:
    CMyComboBox( );    
    void Init( UINT theEditID , CString EnableText);
	virtual ~CMyComboBox();
	UINT theEditID;
    CString EnableText;
protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnCbnSelchange();
    void Check();
};


