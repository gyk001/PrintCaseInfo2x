// FormInputView.cpp : 实现文件
//


#include "stdafx.h"
#include "MaleInputView.h"
#include "PrintCaseInfo2xDoc.h"
#include "MainFrm.h"
#include "Resource.h"



// CFormInputView

IMPLEMENT_DYNCREATE(CMaleInputView, CPrintCaseInfoView)

CMaleInputView::CMaleInputView()
: CPrintCaseInfoView(CMaleInputView::IDD)
{
	viewWidth = MALE_CTRL_WIDTH;
}
CMaleInputView::~CMaleInputView()
{
}

void CMaleInputView::DoDataExchange(CDataExchange* pDX)
{

	//#define DDX_Text(pDx , id , a  ) DDX_Text_NEW(pDx , id , a  ) 

	CPrintCaseInfoView::DoDataExchange( pDX );
	CPrintCaseInfo2xDoc*  pDoc =(CPrintCaseInfo2xDoc*) GetDocument();
	CMaleInfo* pMaleInfo;	
	if ( !pDoc )
	{
		pDX->Fail();
		return;
	}
	pMaleInfo = &(pDoc->maleInfo);
	DDX_Text_CSTRING(pDX, IDC_EDIT_EN_NAME, pMaleInfo -> EN_name);
	DDX_Text_UINT(pDX,  IDC_EDIT_EN_AGE, pMaleInfo -> EN_age);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_EN_PHONE, pMaleInfo -> EN_phone);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_EN_OCCUPATION, pMaleInfo -> EN_occupation);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_EN_KNOWLEDGE_DEGREE, pMaleInfo -> EN_knowledge_degree);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_MI_NIAO_SHENG_ZHI, pMaleInfo -> cs_mi_niao_sheng_zhi.strMore);
	DDX_Text_INT(pDX,  IDC_EDIT_XI_YAN, pMaleInfo -> ci_xi_yan.iMore);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_EN_NATION, pMaleInfo -> EN_nation);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_EN_ADDRESS, pMaleInfo -> EN_address);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_EN_COMPANY, pMaleInfo -> EN_company);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_ZHU_SU, pMaleInfo -> zhu_su);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_XIAN_BING_SHI, pMaleInfo -> xian_bing_shi);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_JIAN_KANG_ZHUANG_KUANG_GUO_QU, pMaleInfo -> jian_kang_zhuang_kuang_guo_qu);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_SHENG_ZHI_QI_TA, pMaleInfo -> sheng_zhi_qi_ta);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_JI_WANG_BING_SHI_QI_TA, pMaleInfo -> ji_wang_bing_shi_qi_ta);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_JIAN_KANG_ZHUANG_KUANG_XIAN_ZAI, pMaleInfo -> jian_kang_zhuang_kuang_xian_zai);
	DDX_Text_INT(pDX,  IDC_EDIT_JIN_YU_TIAN_SHU, pMaleInfo -> jin_yu_tian_shu);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_YIN_JING, pMaleInfo -> cs_yin_jing.strMore);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_YAO_WU_GUO_MIN, pMaleInfo -> cs_yao_wu_guo_min.strMore);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_CHU_SHENG_QUE_XIAN, pMaleInfo -> cs_chu_sheng_que_xian.strMore);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_YI_CHUAN_BING_SHI, pMaleInfo -> cs_yi_chuan_bing_shi.strMore);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_BU_YUN_BU_YU, pMaleInfo -> cs_bu_yun_bu_yu.strMore);
	DDX_Text_INT(pDX,  IDC_EDIT_XUE_YA_1, pMaleInfo -> xue_ya1);
	DDX_Text_INT(pDX,  IDC_EDIT_XUE_YA_2, pMaleInfo -> xue_ya2);
	DDX_Text_FLOAT(pDX,  IDC_EDIT_TI_ZHONG, pMaleInfo -> ti_zhong);
	DDX_Text_INT(pDX,  IDC_EDIT_SHEN_GAO, pMaleInfo -> shen_gao);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_RU_FANG, pMaleInfo -> cs_ru_fang.strMore);
	DDX_Text_CSTRING(pDX,  IDC_COMB_HOU_JIE, pMaleInfo -> hou_jie);
	DDX_Text_INT(pDX,  IDC_EDIT_GAO_WAN_TI_JI_ZUO, pMaleInfo -> gao_wan_ti_ji_zuo);
	DDX_Text_INT(pDX,  IDC_EDIT_GAO_WAN_TI_JI_YOU, pMaleInfo -> gao_wan_ti_ji_you);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_GAO_WAN_ZHI_DI_ZUO, pMaleInfo -> cs_gao_wan_zhi_di_zuo.strMore);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_GAO_WAN_ZHI_DI_YOU, pMaleInfo -> cs_gao_wan_zhi_di_you.strMore);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_FU_GAO_ZUO, pMaleInfo -> cs_fu_gao_zuo.strMore);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_FU_GAO_YOU, pMaleInfo -> cs_fu_gao_you.strMore);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_SHU_JING_GUAN_ZUO, pMaleInfo -> cs_shu_jing_guan_zuo.strMore);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_SHU_JING_GUAN_YOU, pMaleInfo -> cs_shu_jing_guan_you.strMore);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_JING_SUO_JING_MAI_ZUO, pMaleInfo -> cs_jing_suo_jing_mai_zuo.strMore);  
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_JING_SUO_JING_MAI_YOU, pMaleInfo -> cs_jing_suo_jing_mai_you.strMore);
	DDX_Text_FLOAT(pDX,  IDC_EDIT_JING_YE_LIANG, pMaleInfo -> jing_ye_liang);
	DDX_Text_FLOAT(pDX,  IDC_EDIT_EN_PH, pMaleInfo -> EN_PH);
	DDX_Text_INT(pDX,  IDC_EDIT_YE_HUA_SHI_JIAN, pMaleInfo -> ye_hua_shi_jian);
	DDX_Text_FLOAT(pDX,  IDC_EDIT_MI_DU, pMaleInfo -> mi_du);
	DDX_Text_FLOAT(pDX,  IDC_EDIT_HUO_LI_A_JI, pMaleInfo -> huo_li_A_ji);
	DDX_Text_FLOAT(pDX,  IDC_EDIT_HUO_LI_B_JI, pMaleInfo -> huo_li_B_ji);
	DDX_Text_FLOAT(pDX,  IDC_EDIT_HUO_LI_C_JI, pMaleInfo -> huo_li_C_ji);
	DDX_Text_FLOAT(pDX,  IDC_EDIT_HUO_LI_D_JI, pMaleInfo -> huo_li_D_ji);
	DDX_Text_INT(pDX,  IDC_EDIT_ZHENG_CHANG_XING_TAI_LV, pMaleInfo -> zheng_chang_xing_tai_lv);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_BAI_XI_BAO, pMaleInfo -> bai_xi_bao);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_SHENG_ZHI_JI_SU, pMaleInfo -> sheng_zhi_ji_su);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_YI_CHUAN_XUE_JIAN_CHA, pMaleInfo -> yi_chuan_xue_jian_cha);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_CHU_BU_ZHEN_DUAN, pMaleInfo -> chu_bu_zhen_duan);
	DDX_Text_CSTRING(pDX,  IDC_EDIT_NAN_YI_SHI, pMaleInfo -> nan_yi_shi);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_XIN_XUE_GUAN,pMaleInfo -> xin_xue_guan);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_MI_NIAO_SHENG_ZHI,pMaleInfo -> cs_mi_niao_sheng_zhi.strBase);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_XING_CHUAN_BO,pMaleInfo -> xing_chuan_bo);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_JIE_HE,pMaleInfo -> jie_he);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_GAN_YAN,pMaleInfo -> ji_wang_gan_yan);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_XI_YAN,pMaleInfo -> ci_xi_yan.strBase);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_XU_JIU,pMaleInfo -> xu_jiu);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_ZHONG_DA_JING_SHENG_CI_JI,pMaleInfo -> zhong_da_jing_sheng_ci_ji);
	DDX_CBString_CSTRING(pDX,   IDC_COMB_HU_XU,pMaleInfo -> hu_xu);
	DDX_CBString_CSTRING(pDX,   IDC_COMB_CS_YIN_JING,pMaleInfo -> cs_yin_jing.strBase);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_YAO_WU_GUO_MIN,pMaleInfo -> cs_yao_wu_guo_min.strBase);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_JIN_QING_JIE_HUN,pMaleInfo -> jin_qin_jie_hun);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_ZAI_HUN,pMaleInfo -> zai_hun);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_YI_CHUAN_BING_SHI,pMaleInfo -> cs_yi_chuan_bing_shi.strBase);	
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_CHU_SHENG_QUE_XIAN,pMaleInfo -> cs_chu_sheng_que_xian.strBase);	
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_BU_YUN_BU_YU,pMaleInfo -> cs_bu_yun_bu_yu.strBase);	
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_RU_FANG,pMaleInfo -> cs_ru_fang.strBase);	
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_GAO_WAN_ZHI_DI_ZUO,pMaleInfo -> cs_gao_wan_zhi_di_zuo.strBase);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_GAO_WAN_ZHI_DI_YOU,pMaleInfo -> cs_gao_wan_zhi_di_you.strBase);	
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_FU_GAO_ZUO,pMaleInfo -> cs_fu_gao_zuo.strBase);	
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_FU_GAO_YOU,pMaleInfo -> cs_fu_gao_you.strBase);	
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_SHU_JING_GUAN_ZUO,pMaleInfo -> cs_shu_jing_guan_zuo.strBase);	
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_SHU_JING_GUAN_YOU,pMaleInfo -> cs_shu_jing_guan_you.strBase);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_YIN_MAO,pMaleInfo -> yin_mao);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_JING_SUO_JING_MAI_ZUO,pMaleInfo -> cs_jing_suo_jing_mai_zuo.strBase);
	DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_JING_SUO_JING_MAI_YOU,pMaleInfo -> cs_jing_suo_jing_mai_you.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_XUE_XING, pMaleInfo -> xue_xing);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_RH_YIN_ZI, pMaleInfo -> Rh_yin_zi);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_LIN_QIU_JUN, pMaleInfo -> lin_qiu_jun);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_ZHI_YUAN_TI, pMaleInfo -> zhi_yuan_ti);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_YI_YUAN_TI, pMaleInfo -> yi_yuan_ti);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_GAN_YAN_HIV, pMaleInfo -> EN_HIV);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_GAN_YAN_GAN_YAN, pMaleInfo -> gan_yan);
	DDX_DateTimeCtrl_CTIME( pDX, IDC_DATETIMEPICKER_DATE_JING_YE_FEN_XI , pMaleInfo -> date_jing_ye_fen_xi);
	DDX_DateTimeCtrl_CTIME( pDX, IDC_DATETIMEPICKER_DATE_LUO_KUAN , pMaleInfo -> date_luo_kuan);
	DDX_DateTimeCtrl_CTIME( pDX, IDC_DATETIMEPICKER_DATE_CHU_ZHEN , pMaleInfo -> date_chu_zhen);

	DDX_Control(pDX, IDC_COMBO_XI_YAN, ctrl_combo_xi_yan);
	DDX_Control(pDX, IDC_COMBO_CS_YAO_WU_GUO_MIN, ctrl_combo_yao_wu_guo_min_shi);
	DDX_Control(pDX, IDC_COMBO_MI_NIAO_SHENG_ZHI, ctrl_combo_mi_niao_sheng_zhi_bing_shi);
	DDX_Control(pDX, IDC_COMBO_CS_CHU_SHENG_QUE_XIAN, ctrl_combo_chu_sheng_que_xian);
	DDX_Control(pDX, IDC_COMB_CS_YIN_JING, ctrl_combo_yin_jing);
	DDX_Control(pDX, IDC_COMBO_CS_GAO_WAN_ZHI_DI_ZUO, ctrl_combo_gao_wan_zhi_di_zuo);
	DDX_Control(pDX, IDC_COMBO_CS_GAO_WAN_ZHI_DI_YOU, ctrl_combo_gao_wan_zhi_di_you);
	DDX_Control(pDX, IDC_COMBO_CS_FU_GAO_ZUO, ctrl_combo_fu_gao_zuo);
	DDX_Control(pDX, IDC_COMBO_CS_FU_GAO_YOU, ctrl_combo_fu_gao_you);
	DDX_Control(pDX, IDC_COMBO_CS_SHU_JING_GUAN_ZUO, ctrl_combo_shu_jing_guan_zuo);
	DDX_Control(pDX, IDC_COMBO_CS_SHU_JING_GUAN_YOU, ctrl_combo_shu_jing_guan_you);
	DDX_Control(pDX, IDC_COMBO_CS_JING_SUO_JING_MAI_ZUO, ctrl_combo_jing_suo_jing_mai_zuo);
	DDX_Control(pDX, IDC_COMBO_CS_JING_SUO_JING_MAI_YOU, ctrl_combo_jing_zuo_jing_mai_you);
	DDX_Control(pDX, IDC_COMBO_CS_YI_CHUAN_BING_SHI, ctrl_combo_yi_chuan_bing_shi);
	DDX_Control(pDX, IDC_COMBO_CS_BU_YUN_BU_YU, ctrl_combo_bu_yun_bu_yu_shi);
	DDX_Control(pDX, IDC_COMBO_CS_RU_FANG, ctrl_combo_ru_fang);
}

BEGIN_MESSAGE_MAP(CMaleInputView, CPrintCaseInfoView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON1, &CMaleInputView::OnBnClickedButton1)

END_MESSAGE_MAP()


// CFormInputView 诊断

#ifdef _DEBUG
void CMaleInputView::AssertValid() const
{
	CPrintCaseInfoView::AssertValid();
}

#ifndef _WIN32_WCE
void CMaleInputView::Dump(CDumpContext& dc) const
{
	CPrintCaseInfoView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormInputView 消息处理程序



int CMaleInputView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CPrintCaseInfoView::OnCreate(lpCreateStruct) == -1)
		return -1;

	ctrl_combo_bu_yun_bu_yu_shi.Init( IDC_EDIT_CS_BU_YUN_BU_YU , _T("有"));    
	ctrl_combo_yi_chuan_bing_shi.Init( IDC_EDIT_CS_YI_CHUAN_BING_SHI , _T("有"));
	ctrl_combo_ru_fang.Init( IDC_EDIT_CS_RU_FANG , _T("异常"));
	ctrl_combo_xi_yan.Init( IDC_EDIT_XI_YAN , _T("有"));
	ctrl_combo_yao_wu_guo_min_shi.Init( IDC_EDIT_CS_YAO_WU_GUO_MIN, _T("有"));
	ctrl_combo_mi_niao_sheng_zhi_bing_shi.Init( IDC_EDIT_MI_NIAO_SHENG_ZHI , _T("有"));
	ctrl_combo_chu_sheng_que_xian.Init( IDC_EDIT_CS_CHU_SHENG_QUE_XIAN , _T("有"));
	ctrl_combo_yin_jing.Init( IDC_EDIT_CS_YIN_JING , _T("异常"));
	ctrl_combo_gao_wan_zhi_di_zuo.Init( IDC_EDIT_CS_GAO_WAN_ZHI_DI_ZUO , _T("异常"));
	ctrl_combo_gao_wan_zhi_di_you.Init( IDC_EDIT_CS_GAO_WAN_ZHI_DI_YOU , _T("异常"));
	ctrl_combo_fu_gao_zuo.Init( IDC_EDIT_CS_FU_GAO_ZUO , _T("异常"));
	ctrl_combo_fu_gao_you.Init( IDC_EDIT_CS_FU_GAO_YOU , _T("异常"));
	ctrl_combo_shu_jing_guan_zuo.Init( IDC_EDIT_CS_SHU_JING_GUAN_ZUO , _T("异常"));
	ctrl_combo_shu_jing_guan_you.Init( IDC_EDIT_CS_SHU_JING_GUAN_YOU , _T("异常"));
	ctrl_combo_jing_suo_jing_mai_zuo.Init( IDC_EDIT_CS_JING_SUO_JING_MAI_ZUO , _T("异常"));
	ctrl_combo_jing_zuo_jing_mai_you.Init( IDC_EDIT_CS_JING_SUO_JING_MAI_YOU , _T("异常"));
	return 0;
}

void CMaleInputView::DoDataExchangeOneCtrl( UINT id , CDataExchange* pDX)
{
	CPrintCaseInfoView::DoDataExchange( pDX );
	CPrintCaseInfo2xDoc*  pDoc =(CPrintCaseInfo2xDoc*) GetDocument();
	CMaleInfo* pMaleInfo;	
	if ( ! pDoc )
	{
		pDX->Fail();
		return;
	}
	pMaleInfo = &(pDoc->maleInfo);
	switch ( id )
	{
	case IDC_EDIT_EN_NAME:
		DDX_Text_CSTRING(pDX, IDC_EDIT_EN_NAME, pMaleInfo -> EN_name);
		break;
	case IDC_EDIT_EN_AGE:
		DDX_Text_UINT(pDX,  IDC_EDIT_EN_AGE, pMaleInfo -> EN_age);
		break;
	case IDC_EDIT_EN_PHONE:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_EN_PHONE, pMaleInfo -> EN_phone);
		break;
	case IDC_EDIT_EN_OCCUPATION:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_EN_OCCUPATION, pMaleInfo -> EN_occupation);
		break;
	case IDC_EDIT_EN_KNOWLEDGE_DEGREE:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_EN_KNOWLEDGE_DEGREE, pMaleInfo -> EN_knowledge_degree);
		break;
	case IDC_EDIT_MI_NIAO_SHENG_ZHI:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_MI_NIAO_SHENG_ZHI, pMaleInfo -> cs_mi_niao_sheng_zhi.strMore);
		break;
	case IDC_EDIT_XI_YAN:
		DDX_Text_INT(pDX,  IDC_EDIT_XI_YAN, pMaleInfo -> ci_xi_yan.iMore);
		break;
	case IDC_EDIT_EN_NATION:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_EN_NATION, pMaleInfo -> EN_nation);
		break;
	case IDC_EDIT_EN_ADDRESS:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_EN_ADDRESS, pMaleInfo -> EN_address);
		break;
	case IDC_EDIT_EN_COMPANY:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_EN_COMPANY, pMaleInfo -> EN_company);
		break;
	case IDC_EDIT_ZHU_SU:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_ZHU_SU, pMaleInfo -> zhu_su);
		break;
	case IDC_EDIT_XIAN_BING_SHI:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_XIAN_BING_SHI, pMaleInfo -> xian_bing_shi);
		break;
	case IDC_EDIT_JIAN_KANG_ZHUANG_KUANG_GUO_QU:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_JIAN_KANG_ZHUANG_KUANG_GUO_QU, pMaleInfo -> jian_kang_zhuang_kuang_guo_qu);
		break;
	case IDC_EDIT_SHENG_ZHI_QI_TA:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_SHENG_ZHI_QI_TA, pMaleInfo -> sheng_zhi_qi_ta);
		break;
	case IDC_EDIT_JI_WANG_BING_SHI_QI_TA:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_JI_WANG_BING_SHI_QI_TA, pMaleInfo -> ji_wang_bing_shi_qi_ta);
		break;
	case IDC_EDIT_JIAN_KANG_ZHUANG_KUANG_XIAN_ZAI:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_JIAN_KANG_ZHUANG_KUANG_XIAN_ZAI, pMaleInfo -> jian_kang_zhuang_kuang_xian_zai);
		break;
	case IDC_EDIT_JIN_YU_TIAN_SHU:
		DDX_Text_INT(pDX,  IDC_EDIT_JIN_YU_TIAN_SHU, pMaleInfo -> jin_yu_tian_shu);
		break;
	case IDC_EDIT_CS_YIN_JING:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_YIN_JING, pMaleInfo -> cs_yin_jing.strMore);
		break;
	case IDC_EDIT_CS_YAO_WU_GUO_MIN:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_YAO_WU_GUO_MIN, pMaleInfo -> cs_yao_wu_guo_min.strMore);
		break;
	case IDC_EDIT_CS_CHU_SHENG_QUE_XIAN:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_CHU_SHENG_QUE_XIAN, pMaleInfo -> cs_chu_sheng_que_xian.strMore);
		break;
	case IDC_EDIT_CS_YI_CHUAN_BING_SHI:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_YI_CHUAN_BING_SHI, pMaleInfo -> cs_yi_chuan_bing_shi.strMore);
		break;
	case IDC_EDIT_CS_BU_YUN_BU_YU:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_BU_YUN_BU_YU, pMaleInfo -> cs_bu_yun_bu_yu.strMore);
		break;
	case IDC_EDIT_XUE_YA_1:
		DDX_Text_INT(pDX,  IDC_EDIT_XUE_YA_1, pMaleInfo -> xue_ya1);
		break;
	case IDC_EDIT_XUE_YA_2:
		DDX_Text_INT(pDX,  IDC_EDIT_XUE_YA_2, pMaleInfo -> xue_ya2);
		break;
	case IDC_EDIT_TI_ZHONG:
		DDX_Text_FLOAT(pDX,  IDC_EDIT_TI_ZHONG, pMaleInfo -> ti_zhong);
		break;
	case IDC_EDIT_SHEN_GAO:
		DDX_Text_INT(pDX,  IDC_EDIT_SHEN_GAO, pMaleInfo -> shen_gao);
		break;
	case IDC_EDIT_CS_RU_FANG:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_RU_FANG, pMaleInfo -> cs_ru_fang.strMore);
		break;
	case IDC_COMB_HOU_JIE:
		DDX_Text_CSTRING(pDX,  IDC_COMB_HOU_JIE, pMaleInfo -> hou_jie);
		break;
	case IDC_EDIT_GAO_WAN_TI_JI_ZUO:
		DDX_Text_INT(pDX,  IDC_EDIT_GAO_WAN_TI_JI_ZUO, pMaleInfo -> gao_wan_ti_ji_zuo);
		break;
	case IDC_EDIT_GAO_WAN_TI_JI_YOU:
		DDX_Text_INT(pDX,  IDC_EDIT_GAO_WAN_TI_JI_YOU, pMaleInfo -> gao_wan_ti_ji_you);
		break;
	case IDC_EDIT_CS_GAO_WAN_ZHI_DI_ZUO:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_GAO_WAN_ZHI_DI_ZUO, pMaleInfo -> cs_gao_wan_zhi_di_zuo.strMore);
		break;
	case IDC_EDIT_CS_GAO_WAN_ZHI_DI_YOU:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_GAO_WAN_ZHI_DI_YOU, pMaleInfo -> cs_gao_wan_zhi_di_you.strMore);
		break;
	case IDC_EDIT_CS_FU_GAO_ZUO:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_FU_GAO_ZUO, pMaleInfo -> cs_fu_gao_zuo.strMore);
		break;
	case IDC_EDIT_CS_FU_GAO_YOU:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_FU_GAO_YOU, pMaleInfo -> cs_fu_gao_you.strMore);
		break;
	case IDC_EDIT_CS_SHU_JING_GUAN_ZUO:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_SHU_JING_GUAN_ZUO, pMaleInfo -> cs_shu_jing_guan_zuo.strMore);
		break;
	case IDC_EDIT_CS_SHU_JING_GUAN_YOU:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_SHU_JING_GUAN_YOU, pMaleInfo -> cs_shu_jing_guan_you.strMore);
		break;
	case IDC_EDIT_CS_JING_SUO_JING_MAI_ZUO:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_JING_SUO_JING_MAI_ZUO, pMaleInfo -> cs_jing_suo_jing_mai_zuo.strMore);  
		break;
	case IDC_EDIT_CS_JING_SUO_JING_MAI_YOU:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CS_JING_SUO_JING_MAI_YOU, pMaleInfo -> cs_jing_suo_jing_mai_you.strMore);
		break;
	case IDC_EDIT_JING_YE_LIANG:
		DDX_Text_FLOAT(pDX,  IDC_EDIT_JING_YE_LIANG, pMaleInfo -> jing_ye_liang);
		break;
	case IDC_EDIT_EN_PH:
		DDX_Text_FLOAT(pDX,  IDC_EDIT_EN_PH, pMaleInfo -> EN_PH);
		break;
	case IDC_EDIT_YE_HUA_SHI_JIAN:
		DDX_Text_INT(pDX,  IDC_EDIT_YE_HUA_SHI_JIAN, pMaleInfo -> ye_hua_shi_jian);
		break;
	case IDC_EDIT_MI_DU:
		DDX_Text_FLOAT(pDX,  IDC_EDIT_MI_DU, pMaleInfo -> mi_du);
		break;
	case IDC_EDIT_HUO_LI_A_JI:
		DDX_Text_FLOAT(pDX,  IDC_EDIT_HUO_LI_A_JI, pMaleInfo -> huo_li_A_ji);
		break;
	case IDC_EDIT_HUO_LI_B_JI:
		DDX_Text_FLOAT(pDX,  IDC_EDIT_HUO_LI_B_JI, pMaleInfo -> huo_li_B_ji);
		break;
	case IDC_EDIT_HUO_LI_C_JI:
		DDX_Text_FLOAT(pDX,  IDC_EDIT_HUO_LI_C_JI, pMaleInfo -> huo_li_C_ji);
		break;
	case IDC_EDIT_HUO_LI_D_JI:
		DDX_Text_FLOAT(pDX,  IDC_EDIT_HUO_LI_D_JI, pMaleInfo -> huo_li_D_ji);
		break;
	case IDC_EDIT_ZHENG_CHANG_XING_TAI_LV:
		DDX_Text_INT(pDX,  IDC_EDIT_ZHENG_CHANG_XING_TAI_LV, pMaleInfo -> zheng_chang_xing_tai_lv);
		break;
	case IDC_EDIT_BAI_XI_BAO:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_BAI_XI_BAO, pMaleInfo -> bai_xi_bao);
		break;
	case IDC_EDIT_SHENG_ZHI_JI_SU:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_SHENG_ZHI_JI_SU, pMaleInfo -> sheng_zhi_ji_su);
		break;
	case IDC_EDIT_YI_CHUAN_XUE_JIAN_CHA:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_YI_CHUAN_XUE_JIAN_CHA, pMaleInfo -> yi_chuan_xue_jian_cha);
		break;
	case IDC_EDIT_CHU_BU_ZHEN_DUAN:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_CHU_BU_ZHEN_DUAN, pMaleInfo -> chu_bu_zhen_duan);
		break;
	case IDC_EDIT_NAN_YI_SHI:
		DDX_Text_CSTRING(pDX,  IDC_EDIT_NAN_YI_SHI, pMaleInfo -> nan_yi_shi);
		break;
	case IDC_COMBO_XIN_XUE_GUAN:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_XIN_XUE_GUAN,pMaleInfo -> xin_xue_guan);
		break;
	case IDC_COMBO_MI_NIAO_SHENG_ZHI:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_MI_NIAO_SHENG_ZHI,pMaleInfo -> cs_mi_niao_sheng_zhi.strBase);
		break;
	case IDC_COMBO_XING_CHUAN_BO:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_XING_CHUAN_BO,pMaleInfo -> xing_chuan_bo);
		break;
	case IDC_COMBO_JIE_HE:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_JIE_HE,pMaleInfo -> jie_he);
		break;
	case IDC_COMBO_GAN_YAN:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_GAN_YAN,pMaleInfo -> ji_wang_gan_yan);
		break;
	case IDC_COMBO_XI_YAN:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_XI_YAN,pMaleInfo -> ci_xi_yan.strBase);
		break;
	case IDC_COMBO_XU_JIU:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_XU_JIU,pMaleInfo -> xu_jiu);
		break;
	case IDC_COMBO_ZHONG_DA_JING_SHENG_CI_JI:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_ZHONG_DA_JING_SHENG_CI_JI,pMaleInfo -> zhong_da_jing_sheng_ci_ji);
		break;
	case IDC_COMB_HU_XU:
		DDX_CBString_CSTRING(pDX,   IDC_COMB_HU_XU,pMaleInfo -> hu_xu);
		break;
	case IDC_COMB_CS_YIN_JING:
		DDX_CBString_CSTRING(pDX,   IDC_COMB_CS_YIN_JING,pMaleInfo -> cs_yin_jing.strBase);
		break;
	case IDC_COMBO_CS_YAO_WU_GUO_MIN:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_YAO_WU_GUO_MIN,pMaleInfo -> cs_yao_wu_guo_min.strBase);
		break;
	case IDC_COMBO_JIN_QING_JIE_HUN:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_JIN_QING_JIE_HUN,pMaleInfo -> jin_qin_jie_hun);
		break;
	case IDC_COMBO_ZAI_HUN:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_ZAI_HUN,pMaleInfo -> zai_hun);
		break;
	case IDC_COMBO_CS_YI_CHUAN_BING_SHI:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_YI_CHUAN_BING_SHI,pMaleInfo -> cs_yi_chuan_bing_shi.strBase);	
		break;
	case IDC_COMBO_CS_CHU_SHENG_QUE_XIAN:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_CHU_SHENG_QUE_XIAN,pMaleInfo -> cs_chu_sheng_que_xian.strBase);	
		break;
	case IDC_COMBO_CS_BU_YUN_BU_YU:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_BU_YUN_BU_YU,pMaleInfo -> cs_bu_yun_bu_yu.strBase);	
		break;
	case IDC_COMBO_CS_RU_FANG:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_RU_FANG,pMaleInfo -> cs_ru_fang.strBase);	
		break;
	case IDC_COMBO_CS_GAO_WAN_ZHI_DI_ZUO:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_GAO_WAN_ZHI_DI_ZUO,pMaleInfo -> cs_gao_wan_zhi_di_zuo.strBase);
		break;
	case IDC_COMBO_CS_GAO_WAN_ZHI_DI_YOU:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_GAO_WAN_ZHI_DI_YOU,pMaleInfo -> cs_gao_wan_zhi_di_you.strBase);	
		break;
	case IDC_COMBO_CS_FU_GAO_ZUO:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_FU_GAO_ZUO,pMaleInfo -> cs_fu_gao_zuo.strBase);	
		break;
	case IDC_COMBO_CS_FU_GAO_YOU:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_FU_GAO_YOU,pMaleInfo -> cs_fu_gao_you.strBase);	
		break;
	case IDC_COMBO_CS_SHU_JING_GUAN_ZUO:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_SHU_JING_GUAN_ZUO,pMaleInfo -> cs_shu_jing_guan_zuo.strBase);	
		break;
	case IDC_COMBO_CS_SHU_JING_GUAN_YOU:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_SHU_JING_GUAN_YOU,pMaleInfo -> cs_shu_jing_guan_you.strBase);
		break;
	case IDC_COMBO_YIN_MAO:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_YIN_MAO,pMaleInfo -> yin_mao);
		break;
	case IDC_COMBO_CS_JING_SUO_JING_MAI_ZUO:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_JING_SUO_JING_MAI_ZUO,pMaleInfo -> cs_jing_suo_jing_mai_zuo.strBase);
		break;
	case IDC_COMBO_CS_JING_SUO_JING_MAI_YOU:
		DDX_CBString_CSTRING(pDX,   IDC_COMBO_CS_JING_SUO_JING_MAI_YOU,pMaleInfo -> cs_jing_suo_jing_mai_you.strBase);
		break;
	case IDC_COMBO_XUE_XING:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_XUE_XING, pMaleInfo -> xue_xing);
		break;
	case IDC_COMBO_RH_YIN_ZI:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_RH_YIN_ZI, pMaleInfo -> Rh_yin_zi);
		break;
	case IDC_COMBO_LIN_QIU_JUN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_LIN_QIU_JUN, pMaleInfo -> lin_qiu_jun);
		break;
	case IDC_COMBO_ZHI_YUAN_TI:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_ZHI_YUAN_TI, pMaleInfo -> zhi_yuan_ti);
		break;
	case IDC_COMBO_YI_YUAN_TI:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_YI_YUAN_TI, pMaleInfo -> yi_yuan_ti);
		break;
	case IDC_COMBO_GAN_YAN_HIV:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_GAN_YAN_HIV, pMaleInfo -> EN_HIV);
		break;
	case IDC_COMBO_GAN_YAN_GAN_YAN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_GAN_YAN_GAN_YAN, pMaleInfo -> gan_yan);
		break;
	case IDC_DATETIMEPICKER_DATE_JING_YE_FEN_XI :
		DDX_DateTimeCtrl_CTIME( pDX, IDC_DATETIMEPICKER_DATE_JING_YE_FEN_XI , pMaleInfo -> date_jing_ye_fen_xi);
		break;
	case IDC_DATETIMEPICKER_DATE_LUO_KUAN :
		DDX_DateTimeCtrl_CTIME( pDX, IDC_DATETIMEPICKER_DATE_LUO_KUAN , pMaleInfo -> date_luo_kuan);
		break;
	case IDC_DATETIMEPICKER_DATE_CHU_ZHEN :
		DDX_DateTimeCtrl_CTIME( pDX, IDC_DATETIMEPICKER_DATE_CHU_ZHEN , pMaleInfo -> date_chu_zhen);
		break;
	}
	//AfxGetMainWnd() -> SendMessage(WM_UPDATE_FRAME_TITLE);
}

void CMaleInputView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
// 	GetDocument()->SetModifiedFlag(FALSE);
// 	AfxGetMainWnd() -> SendMessage(WM_UPDATE_FRAME_TITLE);
	//UpdateData();
	//SendMessage(WM_UPDATE_VIEW_TO_DOC);
}
