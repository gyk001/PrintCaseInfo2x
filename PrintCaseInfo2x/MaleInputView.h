#pragma once

#include "afxwin.h"
#include "Resource.h"
#include "../PciCoreDll/MaleInfo.h"
#include "../GeneralDll/MyComboBox.h"
#include "PrintCaseInfoView.h"

#define  MALE_CTRL_WIDTH 780

// CFormInputView 窗体视图

class CMaleInputView : public CPrintCaseInfoView
{
	DECLARE_DYNCREATE(CMaleInputView)

public:
	CMaleInputView();           
	virtual ~CMaleInputView();

public:
	enum { IDD = IDD_MALE_INPUT_VIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
	CMaleInfo maleInfo;
public:
    CMyComboBox ctrl_combo_xi_yan;
    CMyComboBox ctrl_combo_yao_wu_guo_min_shi;
    CMyComboBox ctrl_combo_mi_niao_sheng_zhi_bing_shi;
    CMyComboBox ctrl_combo_chu_sheng_que_xian;
    CMyComboBox ctrl_combo_yin_jing;
    CMyComboBox ctrl_combo_gao_wan_zhi_di_zuo;
    CMyComboBox ctrl_combo_gao_wan_zhi_di_you;
    CMyComboBox ctrl_combo_fu_gao_zuo;
    CMyComboBox ctrl_combo_fu_gao_you;
    CMyComboBox ctrl_combo_shu_jing_guan_zuo;
    CMyComboBox ctrl_combo_shu_jing_guan_you;
    CMyComboBox ctrl_combo_jing_suo_jing_mai_zuo;
    CMyComboBox ctrl_combo_jing_zuo_jing_mai_you;
    CMyComboBox ctrl_combo_yi_chuan_bing_shi;
    CMyComboBox ctrl_combo_bu_yun_bu_yu_shi;
    CMyComboBox ctrl_combo_ru_fang;
public:
	//更新一个控件的数据
	virtual void DoDataExchangeOneCtrl( UINT id , CDataExchange* pDX);
	afx_msg void OnBnClickedButton1();
};


