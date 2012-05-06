#pragma once


#define FEMALE_CTRL_WIDTH 780 

#include "Resource.h"
#include "../PciCoreDll/FemaleInfo.h"
#include "../PciCoreDll/CommonInfo.h"
#include "../GeneralDll/MyComboBox.h"
#include "PrintCaseInfoView.h"
#include "afxwin.h"
// CFormInputView 窗体视图

class CFemaleInputView : public CPrintCaseInfoView
{
	DECLARE_DYNCREATE(CFemaleInputView)

public:
	CFemaleInputView();           // 动态创建所使用的受保护的构造函数
	virtual ~CFemaleInputView();

public:
	enum { IDD = IDD_FEMALE_INPUT_VIEW };
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
	CFemaleInfo femaleInfo;
    CCommonInfo commonInfo;
    CDateTimeCtrl ctrl_date_shou_ci_bing_cheng_ji_lu;
public:
     virtual void OnInitialUpdate();
public:
    CMyComboBox ctrl_combo_xi_yan;
    CMyComboBox ctrl_combo_yao_wu_guo_min;
    CMyComboBox ctrl_combo_chu_sheng_que_xian;
    CMyComboBox ctrl_combo_yi_chuan_bing_shi;
    CMyComboBox ctrl_combo_bu_yun_bu_yu_shi;
    CMyComboBox ctrl_combo_wai_yin;
    CMyComboBox ctrl_combo_yin_dao;
    CMyComboBox ctrl_combo_gong_jing;
    CMyComboBox ctrl_combo_zi_gong_da_xiao;
    CMyComboBox ctrl_combo_fu_jian_zuo;
    CMyComboBox ctrl_combo_fu_jian_you;
    CMyComboBox ctrl_combo_ying_yang;
    CMyComboBox ctrl_combo_fa_yu;
    CMyComboBox ctrl_combo_jing_shen;
    CMyComboBox ctrl_combo_mao_fa;
    CMyComboBox ctrl_combo_pi_fu_nian_mo;
    CMyComboBox ctrl_combo_lin_ba_jie;
    CMyComboBox ctrl_combo_ru_fang;
    CMyComboBox ctrl_combo_xin;
    CMyComboBox ctrl_combo_fei;
    CMyComboBox ctrl_combo_gan;
    CMyComboBox ctrl_combo_pi;
    CMyComboBox ctrl_combo_shen;
    CMyComboBox ctrl_combo_ji_zhu_si_zhi;
    CMyComboBox ctrl_combo_shou_shu_shi;
	CMyComboBox ctrl_combo_jian_kang_zhaung_kuang;
	CMyComboBox ctrl_combo_pen_qiang_yan;
public:
	//更新一个控件的数据
	//virtual void DoDataExchangeOneCtrl( UINT id , CDataExchange* pDX);

};


