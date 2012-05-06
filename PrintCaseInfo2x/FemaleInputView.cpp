// FormInputView.cpp : 实现文件
//

#include "stdafx.h"
#include "FemaleInputView.h"
#include "PrintCaseInfo2xDoc.h"
//#include ""
#include "Resource.h"


// CFormInputView

IMPLEMENT_DYNCREATE(CFemaleInputView, CPrintCaseInfoView)

CFemaleInputView::CFemaleInputView()
: CPrintCaseInfoView(CFemaleInputView::IDD)
{
	
	viewWidth =FEMALE_CTRL_WIDTH;
}

CFemaleInputView::~CFemaleInputView()
{
}

void CFemaleInputView::DoDataExchange(CDataExchange* pDX)
{
	TRACE(_T(" * CFemaleInputView::DoDataExchange(CDataExchange* pDX) * \n"));
	CPrintCaseInfoView::DoDataExchange(pDX);
	CPrintCaseInfo2xDoc*  pDoc =(CPrintCaseInfo2xDoc*) GetDocument();
	CMaleInfo* pMaleInfo;	
	CFemaleInfo* pFemaleInfo;
	CCommonInfo* pCommonInfo;
	if ( ! pDoc )
	{
		pDX->Fail();
		return;
	}
	pMaleInfo = &(pDoc->maleInfo);
	pFemaleInfo = &(pDoc->femaleInfo);
	pCommonInfo = &(pDoc->commonInfo);

	DDX_Text_CSTRING(pDX, IDC_EDIT_F_PAI_LUAN_JIAN_CE4 , pFemaleInfo -> nv_pai_luan_jian_ce_ri_qi4);  
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_PAI_LUAN_JIAN_CE3 , pFemaleInfo -> nv_pai_luan_jian_ce_ri_qi3);  
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_PAI_LUAN_JIAN_CE2 , pFemaleInfo -> nv_pai_luan_jian_ce_ri_qi2);  
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_PAI_LUAN_JIAN_CE1 , pFemaleInfo -> nv_pai_luan_jian_ce_ri_qi1);  
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZUO_CE_SHU_LUAN_GUAN,pFemaleInfo -> zuo_ce_shu_luan_guan);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZUO_CE_LUAN_CHAO_FC,pFemaleInfo -> fu_ke_B_chao_zuo_ce_luan_chao_Fc);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZUO_CE_LUAN_CHAO,pFemaleInfo -> fu_ke_B_chao_zuo_ce_luan_chao);
	DDX_Text_INT(pDX, IDC_EDIT_F_ZU_CHAN_YUE,pFemaleInfo -> zu_yue_chan);
	DDX_Text_INT(pDX, IDC_EDIT_F_ZI_RAN_LIU_CHAN,pFemaleInfo -> zi_ran_liu_chan);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZI_GONG_XING_TAI,pFemaleInfo -> zi_gong_xing_tai);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZI_GONG_NEI_MO4,pFemaleInfo -> zi_gong_nei_mo4);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZI_GONG_NEI_MO3,pFemaleInfo -> zi_gong_nei_mo3);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZI_GONG_NEI_MO2,pFemaleInfo -> zi_gong_nei_mo2);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZI_GONG_NEI_MO1,pFemaleInfo -> zi_gong_nei_mo1);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZHU_SU,pFemaleInfo -> zhu_su);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZHENG_LIAO_JI_HUA,pFemaleInfo -> zheng_liao_ji_hua);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZHEN_DUAN,pFemaleInfo -> zhen_duan);
	DDX_Text_INT(pDX, IDC_EDIT_F_ZAO_CHAN,pFemaleInfo -> zao_chan);
	DDX_Text_INT(pDX, IDC_EDIT_F_YUN,pFemaleInfo -> yun);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_YUE_JING_ZHOU_QI4,pFemaleInfo -> yue_jing_zhou_qi4);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_YUE_JING_ZHOU_QI3,pFemaleInfo -> yue_jing_zhou_qi3);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_YUE_JING_ZHOU_QI2,pFemaleInfo -> yue_jing_zhou_qi2);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_YUE_JING_ZHOU_QI1,pFemaleInfo -> yue_jing_zhou_qi1);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_YUE_JING_SHI_YUE_JING_ZHOU_QI2,pFemaleInfo -> yue_jing_shi_yue_jing_zhou_qi2);
	DDX_Text_INT(pDX, IDC_EDIT_F_YUE_JING_SHI_YUE_JING_ZHOU_QI1,pFemaleInfo -> yue_jing_shi_yue_jing_zhou_qi1);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_YOU_CE_SHU_LUAN_GUAN,pFemaleInfo -> you_ce_shu_luan_guan);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_YOU_CE_LUAN_CHAO_FC,pFemaleInfo -> fu_ke_B_chao_you_ce_luan_chao_Fc);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_YOU_CE_LUAN_CHAO,pFemaleInfo -> fu_ke_B_chao_you_ce_luan_chao);
	DDX_Text_INT(pDX, IDC_EDIT_F_YIN_CHAN,pFemaleInfo -> yin_chan);
	DDX_Text_FLOAT(pDX, IDC_EDIT_F_YI_BAN_QING_KUANG_T,pFemaleInfo -> yi_ban_qing_kuang_T);
	DDX_Text_INT(pDX, IDC_EDIT_F_YI_BAN_QING_KUANG_R,pFemaleInfo -> yi_ban_qing_kuang_R);
	DDX_Text_INT(pDX, IDC_EDIT_F_YI_BAN_QING_KUANG_P,pFemaleInfo -> yi_ban_qing_kuang_P);
	DDX_Text_INT(pDX, IDC_EDIT_F_YI_BAN_QING_KUANG_BP2,pFemaleInfo -> yi_ban_qing_kuang_BP2);
	DDX_Text_INT(pDX, IDC_EDIT_F_YI_BAN_QING_KUANG_BP1,pFemaleInfo -> yi_ban_qing_kuang_BP1);
	DDX_Text_INT(pDX, IDC_EDIT_F_YAO_LIU,pFemaleInfo -> yao_liu);
	DDX_Text_INT(pDX, IDC_EDIT_F_XIAN_YOU_ZI_NV,pFemaleInfo -> xian_you_zi_nv);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_XIAN_BING_SHI,pFemaleInfo -> xian_bing_shi);
	DDX_Text_FLOAT(pDX, IDC_EDIT_F_TI_ZHONG,pFemaleInfo -> ti_zhong);
	DDX_Text_INT(pDX, IDC_EDIT_F_SHEN_GAO,pFemaleInfo -> shen_gao);
	DDX_Text_INT(pDX, IDC_EDIT_F_REN_GONG_LIU_CHAN,pFemaleInfo -> ren_gong_liu_chan);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_RAN_SE_TI,pFemaleInfo -> ran_se_ti);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_NV_YI_SHI,pFemaleInfo -> nv_yi_shi);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_MO_CI_YUE_JING,pFemaleInfo -> mo_ci_yue_jing);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_MO_CI_REN_CHEN,pFemaleInfo -> mo_ci_ren_shen);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_LUAN_PAO_ZHI_JING4,pFemaleInfo -> luan_pao_zhi_jing4);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_LUAN_PAO_ZHI_JING3,pFemaleInfo -> luan_pao_zhi_jing3);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_LUAN_PAO_ZHI_JING2,pFemaleInfo -> luan_pao_zhi_jing2);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_LUAN_PAO_ZHI_JING1,pFemaleInfo -> luan_pao_zhi_jing1);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_JI_WANG_QI_TA,pFemaleInfo -> ji_wang_qi_ta);
	DDX_Text_INT(pDX, IDC_EDIT_F_GONG_WAI_YUAN_ZUO,pFemaleInfo -> gong_wai_yuan_zuo);
	DDX_Text_INT(pDX, IDC_EDIT_F_GONG_WAI_YUAN_YOU,pFemaleInfo -> gong_wai_yuan_you);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_GONG_QIANG_JING,pFemaleInfo -> gong_qiang_jing);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_GONG_JING_JIAN_CHA,pFemaleInfo -> gong_jing_qi_ta);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_GONG_JING_GUA_PIAN,pFemaleInfo -> gong_jing_gua_pian);
	DDX_Text_FLOAT(pDX, IDC_EDIT_F_FU_KE_ZI_GONG_NEI_MO,pFemaleInfo -> fu_ke_Bchao_zi_gong_nei_mo);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_FU_KE_ZI_GONG_DA_XIAO,pFemaleInfo -> fu_ke_Bchao_zi_gong_da_xiao);
	DDX_Text_CSTRING( pDX ,IDC_EDIT_F_FU_KE_B_CHAO_RI_QI , pFemaleInfo -> fu_ke_Bchao_ri_qi)  ;
	DDX_Text_FLOAT(pDX, IDC_EDIT_F_EN_T,pFemaleInfo -> EN_T);
	DDX_Text_FLOAT(pDX, IDC_EDIT_F_EN_PRL,pFemaleInfo -> EN_PRL);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_POSTALCODE,pFemaleInfo -> EN_postalcode);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_PHONE,pFemaleInfo -> EN_phone);
	DDX_Text_FLOAT(pDX, IDC_EDIT_F_EN_P,pFemaleInfo -> EN_P);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_occupation,pFemaleInfo -> EN_occupation);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_NATION,pFemaleInfo -> EN_nation);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_NAME,pFemaleInfo -> EN_name);
	DDX_Text_FLOAT(pDX, IDC_EDIT_F_EN_LH,pFemaleInfo -> EN_LH);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_KNOWLEDGE_DEGREE,pFemaleInfo -> EN_knowledge_degree);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_IDENTITY_CARD,pFemaleInfo -> EN_identity_card);
	DDX_Text_FLOAT(pDX, IDC_EDIT_F_EN_FSH,pFemaleInfo -> EN_FSH);
	DDX_Text_FLOAT(pDX, IDC_EDIT_F_EN_E_2,pFemaleInfo -> EN_E_2);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_COMPANY,pFemaleInfo -> EN_company);
	DDX_Text_INT(pDX, IDC_EDIT_F_EN_AGE,pFemaleInfo -> EN_age);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_ADDRESS,pFemaleInfo -> EN_address);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_ZI_GONG_DA_XIAO,pFemaleInfo -> cs_fu_ke_jian_cha_zi_gong_da_xiao.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_YING_YANG,pFemaleInfo -> cs_ying_yang.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_YIN_DAO,pFemaleInfo -> cs_yin_dao.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_YI_CHUAN_BING_SHI,pFemaleInfo -> cs_yi_chuan_bing_shi.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_YAO_WU_GUO_MIN,pFemaleInfo -> cs_yao_wu_guo_min.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_XIN,pFemaleInfo -> cs_xin.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_WAI_YIN,pFemaleInfo -> cs_wai_yin.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_SHOU_SHU_SHI,pFemaleInfo -> cs_shou_shu_shi.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_SHEN,pFemaleInfo -> cs_shen.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_RU_FANG,pFemaleInfo -> cs_ru_fang.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_PI_FU_NIAN_MO,pFemaleInfo -> cs_pi_fu_nian_mo.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_PI,pFemaleInfo -> cs_pi.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_MAO_FA,pFemaleInfo -> cs_mao_fa.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_LIN_BA_JIE,pFemaleInfo -> cs_lin_ba_jie.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_JING_SHEN,pFemaleInfo -> cs_jing_shen.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_JIAN_KANG_ZHUANG_KUANG,pFemaleInfo -> cs_jian_kang_zhuang_kuang.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_JI_ZHU_SI_ZHI,pFemaleInfo -> cs_ji_zhu_si_zhi.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_GAN,pFemaleInfo -> cs_gan.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_FU_JIAN_ZUO,pFemaleInfo -> cs_fu_jian_zuo.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_FU_JIAN_YOU,pFemaleInfo -> cs_fu_jian_you.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_FEI,pFemaleInfo -> cs_fei.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_FA_YU,pFemaleInfo -> cs_fa_yu.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_CHU_SHENG_QUE_XIAN,pFemaleInfo -> cs_chu_sheng_que_xian.strMore);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_BU_YUN_BU_YU_SHI,pFemaleInfo -> cs_bu_yun_bu_yu_shi.strMore);
	DDX_Text_INT(pDX, IDC_EDIT_F_CI_XI_YAN,pFemaleInfo -> ci_xi_yan.iMore);
	DDX_Text_INT(pDX, IDC_EDIT_F_CHU_CHAO,pFemaleInfo -> chu_chao);
	DDX_Text_INT(pDX, IDC_EDIT_F_CHAN,pFemaleInfo -> chan);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_BING_SHI_XIAO_JIE,pFemaleInfo -> bing_shi_xiao_jie);
	DDX_Text_CSTRING(pDX, IDC_EDIT_EN_IDENTITY_CARD,pMaleInfo -> EN_identity_card);

	DDX_Text_CSTRING(pDX, IDC_EDIT_C_NI_XING_ZHI_LIAO_FANG_AN,pCommonInfo -> ni_xing_zhi_liao_fang_an);
	DDX_Text_CSTRING(pDX, IDC_EDIT_C_NI_XING_AIH_FANG_SHI,pCommonInfo -> ni_xing_AIH_fang_shi);
	DDX_Text_CSTRING(pDX, IDC_EDIT_C_JIN_JI_ZHENG,pCommonInfo -> jin_ji_zheng);
	DDX_Text_CSTRING(pDX, IDC_EDIT_C_FU_ZHU_JIAN_CHA_YI_CHANG_JIE_GUO,pCommonInfo -> fu_zhu_jian_cha_yi_chang_jie_guo);
	DDX_Text_CSTRING(pDX, IDC_EDIT_C_FU_HE_AIH_ZHI_ZHENG,pCommonInfo -> fu_he_AIH_zhi_zheng);
	DDX_Text_CSTRING(pDX, IDC_EDIT_C_BING_LI_TE_DIAN,pCommonInfo -> bing_li_te_dian);
	DDX_Text_CSTRING(pDX, IDC_EDIT_C_BING_LI_HAO,pCommonInfo -> bing_li_hao);
	DDX_Text_CSTRING(pDX, IDC_EDIT_C_BING_CHENG_JI_LU_YI_SHI,pCommonInfo -> bing_cheng_ji_lu_yi_shi);
	DDX_Text_CSTRING(pDX, IDC_EDIT_C_BING_CHENG_JI_LU_QI_TA,pCommonInfo -> bing_cheng_ji_lu_qi_ta);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_FU_KE_ZI_GONG_LEI_XING,pFemaleInfo -> fu_ke_B_chao_zi_gong_lei_xing);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_ZI_GONG,pFemaleInfo -> zi_gong);



	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_ZHONG_DA_JING_SHEN_CI_JI,pFemaleInfo -> zhong_da_jing_shen_ci_ji);
	CString a = _T("--->")+pFemaleInfo -> zhong_da_jing_shen_ci_ji;
	TRACE(a);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_ZHI_DI,pFemaleInfo -> zhi_di);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_ZAI_HUN,pFemaleInfo -> zai_hun);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_YA_TONG,pFemaleInfo -> ya_tong);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_XU_JIU,pFemaleInfo -> xu_jiu);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_XING_CHUAN_BO_JI_BING_SHI,pFemaleInfo -> xing_chuan_bo_ji_bing_shi);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_XIN_XUE_GUAN_JI_BING,pFemaleInfo -> xin_xue_guan_ji_bing);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_XI_DU,pFemaleInfo -> xi_du);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_TING_JING,pFemaleInfo -> tong_jing);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_SHEN_ZANG_JI_BING,pFemaleInfo -> shen_zang_ji_bing);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_REN_CHEN,pFemaleInfo -> ren_chen);


	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_MI_NIAO_XI_TONG_GAN_RAN,pFemaleInfo -> mi_niao_xi_tong_gan_ran);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_LAN_WEI_YAN,pFemaleInfo -> lan_wei_yan);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_JING_LIANG,pFemaleInfo -> jing_liang);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_JIN_QIN_JIE_HUN,pFemaleInfo -> jin_qin_jie_hun);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_JIE_HE,pFemaleInfo -> jie_he);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_JI_WANG_GAN_YAN,pFemaleInfo -> ji_wang_gan_yan);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_HUO_DONG_DU,pFemaleInfo -> huo_dong_du);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_ZI_GONG_DA_XIAO,pFemaleInfo -> cs_fu_ke_jian_cha_zi_gong_da_xiao.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_YING_YANG,pFemaleInfo -> cs_ying_yang.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_YIN_DAO,pFemaleInfo -> cs_yin_dao.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_YI_RU,pFemaleInfo -> yi_ru);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_YI_CHUAN_BING_SHI,pFemaleInfo -> cs_yi_chuan_bing_shi.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_YAO_WU_GUO_MIN,pFemaleInfo -> cs_yao_wu_guo_min.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_XIN,pFemaleInfo -> cs_xin.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_WAI_YIN,pFemaleInfo -> cs_wai_yin.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_SHOU_SHU_SHI,pFemaleInfo -> cs_shou_shu_shi.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_SHEN,pFemaleInfo -> cs_shen.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_RU_FANG,pFemaleInfo -> cs_ru_fang.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_PI_FU_NIAN_MO,pFemaleInfo -> cs_pi_fu_nian_mo.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_PI,pFemaleInfo -> cs_pi.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_MAO_FA,pFemaleInfo -> cs_mao_fa.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_LIN_BA_JIE,pFemaleInfo -> cs_lin_ba_jie.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_JING_SHEN,pFemaleInfo -> cs_jing_shen.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_JIAN_KANG_ZHUANG_KUANG,pFemaleInfo -> cs_jian_kang_zhuang_kuang.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_JI_ZHU_SI_ZHI,pFemaleInfo -> cs_ji_zhu_si_zhi.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_GONG_JING_MORE,pFemaleInfo -> cs_gong_jing.strMore);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_GONG_JING,pFemaleInfo -> cs_gong_jing.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_GAN,pFemaleInfo -> cs_gan.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_FU_JIAN_ZUO,pFemaleInfo -> cs_fu_jian_zuo.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_FU_JIAN_YOU,pFemaleInfo -> cs_fu_jian_you.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_FEI,pFemaleInfo -> cs_fei.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_FA_YU,pFemaleInfo -> cs_fa_yu.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_CHU_SHENG_QUE_XIAN,pFemaleInfo -> cs_chu_sheng_que_xian.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_BU_YUN_BU_YU_SHI,pFemaleInfo -> cs_bu_yun_bu_yu_shi.strBase);
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CI_XI_YAN,pFemaleInfo -> ci_xi_yan.strBase);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_ZHI_YUAN_TI,pFemaleInfo -> zhi_yuan_ti);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_YI_YUAN_TI,pFemaleInfo -> yi_yuan_ti);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_XUE_XING,pFemaleInfo -> xue_xing);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_XUE_CHANG_GUI,pFemaleInfo -> xue_chang_gui);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_XIAN_SUO_XI_BAO,pFemaleInfo -> xian_suo_xi_bao);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_SHEN_GONG,pFemaleInfo -> shen_gong);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_RH_YIN_ZI,pFemaleInfo -> Rh_yin_zi);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_QING_JIE_DU,pFemaleInfo -> qing_jie_du);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_MEI_JUN,pFemaleInfo -> mei_jun);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_KANG_ZI_GONG_NEI_MO_KANG_TI,pFemaleInfo -> kang_zi_gong_nei_mo_kang_ti);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_KANG_TOU_MING_DAI_KANG_TI,pFemaleInfo -> kang_tou_ming_dai_kang_ti);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_KANG_LUAN_CHAO_KANG_TI,pFemaleInfo -> kang_luan_chao_kang_ti);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_KANG_JING_ZI_KANG_TI,pFemaleInfo -> kang_jing_zi_kang_ti);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_JU_XI_BAO_BING_DU,pFemaleInfo -> ju_xi_bao_bing_du);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_GONG_XING_CHONG,pFemaleInfo -> gong_xing_chong);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_GAN_GONG,pFemaleInfo -> gan_gong);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_FENG_ZHEN_BING_DU,pFemaleInfo -> feng_zhen_bing_du);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HIVAB,pFemaleInfo -> EN_HIVAb);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HCVAG,pFemaleInfo -> EN_HCVAg);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HCVAB,pFemaleInfo -> EN_HCVAb);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HBSAG,pFemaleInfo -> EN_HBSAG);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HBSAB,pFemaleInfo -> EN_HBSAB);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HBEAG,pFemaleInfo -> EN_HBEAG);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HBEAB,pFemaleInfo -> EN_HBEAB);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HBCAB,pFemaleInfo -> EN_HBCAB);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HAV_I,pFemaleInfo -> EN_HAVI);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_DI_CHONG,pFemaleInfo -> di_chong);
	DDX_CBString_CSTRING(pDX, IDC_COMBO_F_DAN_CHUN_PAO_ZHEN_BING_DU_II_XING,pFemaleInfo -> dan_chun_pao_zhen_bing_du_II_xing);
	DDX_CBString_CSTRING(pDX, IDC_COMB_F_NIAO_CHANG_GUI,pFemaleInfo -> niao_chang_gui);

	
	DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_PEN_QIANG_YAN,pFemaleInfo -> pen_qiang_yan.strBase);
	DDX_Text_CSTRING(pDX, IDC_EDIT_F_PEN_QIANG_YAN,pFemaleInfo -> pen_qiang_yan.strMore);


	DDX_DateTimeCtrl_CTIME(pDX, IDC_DATETIMEPICKER_F_DATE_LUO_KUAN ,pFemaleInfo -> nv_date_luo_kuan);
	DDX_DateTimeCtrl_CTIME(pDX, IDC_DATETIMEPICKER_C_DATE_YE_MEI ,pCommonInfo -> date_ye_mei);  
	DDX_DateTimeCtrl_CTIME(pDX, IDC_DATETIMEPICKER_C_DATE_SHOU_CI_BING_CHENG_JI_LU ,pCommonInfo -> date_shou_ci_bing_cheng_ji_lu); 


	DDX_Control( pDX , IDC_DATETIMEPICKER_C_DATE_SHOU_CI_BING_CHENG_JI_LU , ctrl_date_shou_ci_bing_cheng_ji_lu );
	DDX_Control(pDX, IDC_COMBO_F_CI_XI_YAN, ctrl_combo_xi_yan);
	DDX_Control(pDX, IDC_COMBO_F_CS_YAO_WU_GUO_MIN, ctrl_combo_yao_wu_guo_min);
	DDX_Control(pDX, IDC_COMBO_F_CS_CHU_SHENG_QUE_XIAN, ctrl_combo_chu_sheng_que_xian);
	DDX_Control(pDX, IDC_COMBO_F_CS_YI_CHUAN_BING_SHI, ctrl_combo_yi_chuan_bing_shi);
	DDX_Control(pDX, IDC_COMBO_F_CS_BU_YUN_BU_YU_SHI, ctrl_combo_bu_yun_bu_yu_shi);
	DDX_Control(pDX, IDC_COMBO_F_CS_WAI_YIN, ctrl_combo_wai_yin);
	DDX_Control(pDX, IDC_COMBO_F_CS_YIN_DAO, ctrl_combo_yin_dao);
	DDX_Control(pDX, IDC_COMBO_F_CS_GONG_JING, ctrl_combo_gong_jing);
	DDX_Control(pDX, IDC_COMBO_F_CS_ZI_GONG_DA_XIAO, ctrl_combo_zi_gong_da_xiao);
	DDX_Control(pDX, IDC_COMBO_F_CS_FU_JIAN_ZUO, ctrl_combo_fu_jian_zuo);
	DDX_Control(pDX, IDC_COMBO_F_CS_FU_JIAN_YOU, ctrl_combo_fu_jian_you);
	DDX_Control(pDX, IDC_COMBO_F_CS_YING_YANG, ctrl_combo_ying_yang);
	DDX_Control(pDX, IDC_COMBO_F_CS_FA_YU, ctrl_combo_fa_yu);
	DDX_Control(pDX, IDC_COMBO_F_CS_JING_SHEN, ctrl_combo_jing_shen);
	DDX_Control(pDX, IDC_COMBO_F_CS_MAO_FA, ctrl_combo_mao_fa);
	DDX_Control(pDX, IDC_COMBO_F_CS_PI_FU_NIAN_MO, ctrl_combo_pi_fu_nian_mo);
	DDX_Control(pDX, IDC_COMBO_F_CS_LIN_BA_JIE, ctrl_combo_lin_ba_jie);
	DDX_Control(pDX, IDC_COMBO_F_CS_RU_FANG, ctrl_combo_ru_fang);
	DDX_Control(pDX, IDC_COMBO_F_CS_XIN, ctrl_combo_xin);
	DDX_Control(pDX, IDC_COMBO_F_CS_FEI, ctrl_combo_fei);
	DDX_Control(pDX, IDC_COMBO_F_CS_GAN, ctrl_combo_gan);
	DDX_Control(pDX, IDC_COMBO_F_CS_PI, ctrl_combo_pi);
	DDX_Control(pDX, IDC_COMBO_F_CS_SHEN, ctrl_combo_shen);
	DDX_Control(pDX, IDC_COMBO_F_CS_JI_ZHU_SI_ZHI, ctrl_combo_ji_zhu_si_zhi);
	DDX_Control(pDX, IDC_COMBO_F_CS_SHOU_SHU_SHI, ctrl_combo_shou_shu_shi);
	DDX_Control(pDX, IDC_COMBO_F_CS_JIAN_KANG_ZHUANG_KUANG, ctrl_combo_jian_kang_zhaung_kuang);

	DDX_Control(pDX, IDC_COMBO_F_PEN_QIANG_YAN,ctrl_combo_pen_qiang_yan);
	}

BEGIN_MESSAGE_MAP(CFemaleInputView, CPrintCaseInfoView)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CFormInputView 诊断

#ifdef _DEBUG
void CFemaleInputView::AssertValid() const
{
	CPrintCaseInfoView::AssertValid();
}

#ifndef _WIN32_WCE
void CFemaleInputView::Dump(CDumpContext& dc) const
{
	CPrintCaseInfoView::Dump(dc);
}
#endif
#endif //_DEBUG



void CFemaleInputView::OnInitialUpdate()
{	
	CPrintCaseInfoView::OnInitialUpdate();
	ctrl_date_shou_ci_bing_cheng_ji_lu.SetFormat( _T("yyyy年MM月dd日HH时") );
	( (CEdit *)GetDlgItem( IDC_EDIT_F_EN_IDENTITY_CARD) )->SetLimitText( 18 );
	( (CEdit *)GetDlgItem( IDC_EDIT_EN_IDENTITY_CARD) )->SetLimitText( 18 );

}


int CFemaleInputView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CPrintCaseInfoView::OnCreate(lpCreateStruct) == -1)
		return -1;
	ctrl_combo_shou_shu_shi.Init( IDC_EDIT_F_CS_SHOU_SHU_SHI , _T("有") );
	ctrl_combo_xi_yan .Init( IDC_EDIT_F_CI_XI_YAN , _T("有"));
	ctrl_combo_yao_wu_guo_min.Init( IDC_EDIT_F_CS_YAO_WU_GUO_MIN , _T("有"));
	ctrl_combo_chu_sheng_que_xian.Init( IDC_EDIT_F_CS_CHU_SHENG_QUE_XIAN , _T("有"));
	ctrl_combo_yi_chuan_bing_shi.Init( IDC_EDIT_F_CS_YI_CHUAN_BING_SHI , _T("有"));
	ctrl_combo_bu_yun_bu_yu_shi.Init( IDC_EDIT_F_CS_BU_YUN_BU_YU_SHI , _T("有"));
	ctrl_combo_wai_yin.Init( IDC_EDIT_F_CS_WAI_YIN , _T("异常"));
	ctrl_combo_yin_dao.Init( IDC_EDIT_F_CS_YIN_DAO , _T("异常"));
	ctrl_combo_gong_jing.Init( IDC_COMBO_F_CS_GONG_JING_MORE , _T("糜烂"));
	ctrl_combo_zi_gong_da_xiao.Init( IDC_EDIT_F_CS_ZI_GONG_DA_XIAO , _T("异常"));
	ctrl_combo_fu_jian_zuo.Init( IDC_EDIT_F_CS_FU_JIAN_ZUO , _T("异常"));
	ctrl_combo_fu_jian_you.Init( IDC_EDIT_F_CS_FU_JIAN_YOU , _T("异常"));
	ctrl_combo_ying_yang.Init( IDC_EDIT_F_CS_YING_YANG, _T("异常"));
	ctrl_combo_fa_yu.Init( IDC_EDIT_F_CS_FA_YU , _T("异常"));
	ctrl_combo_jing_shen.Init( IDC_EDIT_F_CS_JING_SHEN , _T("异常"));
	ctrl_combo_mao_fa.Init( IDC_EDIT_F_CS_MAO_FA , _T("异常"));
	ctrl_combo_pi_fu_nian_mo.Init( IDC_EDIT_F_CS_PI_FU_NIAN_MO , _T("异常"));
	ctrl_combo_lin_ba_jie.Init( IDC_EDIT_F_CS_LIN_BA_JIE , _T("异常"));
	ctrl_combo_ru_fang.Init( IDC_EDIT_F_CS_RU_FANG , _T("异常"));
	ctrl_combo_xin.Init( IDC_EDIT_F_CS_XIN , _T("异常"));
	ctrl_combo_fei.Init( IDC_EDIT_F_CS_FEI , _T("异常"));
	ctrl_combo_gan.Init( IDC_EDIT_F_CS_GAN , _T("异常"));
	ctrl_combo_pi.Init( IDC_EDIT_F_CS_PI , _T("异常"));
	ctrl_combo_shen.Init( IDC_EDIT_F_CS_SHEN , _T("异常"));
	ctrl_combo_ji_zhu_si_zhi.Init( IDC_EDIT_F_CS_JI_ZHU_SI_ZHI , _T("异常"));
	ctrl_combo_jian_kang_zhaung_kuang.Init( IDC_EDIT_F_CS_JIAN_KANG_ZHUANG_KUANG , _T( "不健康" ) );
	
	ctrl_combo_pen_qiang_yan.Init(IDC_EDIT_F_PEN_QIANG_YAN,_T("有"));
	return 0;
}
/*
void CFemaleInputView::DoDataExchangeOneCtrl( UINT id , CDataExchange* pDX)
{
	CPrintCaseInfoView::DoDataExchange( pDX );
	CPrintCaseInfo2xDoc*  pDoc =(CPrintCaseInfo2xDoc*) GetDocument();

	if ( ! pDoc )
	{
		pDX->Fail();
		return;
	}
	CMaleInfo* pMaleInfo = &(pDoc->maleInfo);
	CFemaleInfo* pFemaleInfo = &(pDoc->femaleInfo);
	CCommonInfo* pCommonInfo = &(pDoc->commonInfo);
	switch ( id )
	{
	case IDC_EDIT_F_PAI_LUAN_JIAN_CE4:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_PAI_LUAN_JIAN_CE4 , pFemaleInfo -> nv_pai_luan_jian_ce_ri_qi4);  
		break;
	case IDC_EDIT_F_PAI_LUAN_JIAN_CE3:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_PAI_LUAN_JIAN_CE3 , pFemaleInfo -> nv_pai_luan_jian_ce_ri_qi3);  
		break;
	case IDC_EDIT_F_PAI_LUAN_JIAN_CE2 :
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_PAI_LUAN_JIAN_CE2 , pFemaleInfo -> nv_pai_luan_jian_ce_ri_qi2);  
		break;
	case IDC_EDIT_F_PAI_LUAN_JIAN_CE1 :
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_PAI_LUAN_JIAN_CE1 , pFemaleInfo -> nv_pai_luan_jian_ce_ri_qi1);  
		break;
	case IDC_EDIT_F_ZUO_CE_SHU_LUAN_GUAN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZUO_CE_SHU_LUAN_GUAN,pFemaleInfo -> zuo_ce_shu_luan_guan);
		break;
	case IDC_EDIT_F_ZUO_CE_LUAN_CHAO_FC:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZUO_CE_LUAN_CHAO_FC,pFemaleInfo -> fu_ke_B_chao_zuo_ce_luan_chao_Fc);
		break;
	case IDC_EDIT_F_ZUO_CE_LUAN_CHAO:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZUO_CE_LUAN_CHAO,pFemaleInfo -> fu_ke_B_chao_zuo_ce_luan_chao);
		break;
	case IDC_EDIT_F_ZU_CHAN_YUE:
		DDX_Text_INT(pDX, IDC_EDIT_F_ZU_CHAN_YUE,pFemaleInfo -> zu_yue_chan);
		break;
	case IDC_EDIT_F_ZI_RAN_LIU_CHAN:
		DDX_Text_INT(pDX, IDC_EDIT_F_ZI_RAN_LIU_CHAN,pFemaleInfo -> zi_ran_liu_chan);
		break;
	case IDC_EDIT_F_ZI_GONG_XING_TAI:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZI_GONG_XING_TAI,pFemaleInfo -> zi_gong_xing_tai);
		break;
	case IDC_EDIT_F_ZI_GONG_NEI_MO4:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZI_GONG_NEI_MO4,pFemaleInfo -> zi_gong_nei_mo4);
		break;
	case IDC_EDIT_F_ZI_GONG_NEI_MO3:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZI_GONG_NEI_MO3,pFemaleInfo -> zi_gong_nei_mo3);
		break;
	case IDC_EDIT_F_ZI_GONG_NEI_MO2:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZI_GONG_NEI_MO2,pFemaleInfo -> zi_gong_nei_mo2);
		break;
	case IDC_EDIT_F_ZI_GONG_NEI_MO1:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZI_GONG_NEI_MO1,pFemaleInfo -> zi_gong_nei_mo1);
		break;
	case IDC_EDIT_F_ZHU_SU:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZHU_SU,pFemaleInfo -> zhu_su);
		break;
	case IDC_EDIT_F_ZHENG_LIAO_JI_HUA:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZHENG_LIAO_JI_HUA,pFemaleInfo -> zheng_liao_ji_hua);
		break;
	case IDC_EDIT_F_ZHEN_DUAN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_ZHEN_DUAN,pFemaleInfo -> zhen_duan);
		break;
	case IDC_EDIT_F_ZAO_CHAN:
		DDX_Text_INT(pDX, IDC_EDIT_F_ZAO_CHAN,pFemaleInfo -> zao_chan);
		break;
	case IDC_EDIT_F_YUN:
		DDX_Text_INT(pDX, IDC_EDIT_F_YUN,pFemaleInfo -> yun);
		break;
	case IDC_EDIT_F_YUE_JING_ZHOU_QI4:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_YUE_JING_ZHOU_QI4,pFemaleInfo -> yue_jing_zhou_qi4);
		break;
	case IDC_EDIT_F_YUE_JING_ZHOU_QI3:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_YUE_JING_ZHOU_QI3,pFemaleInfo -> yue_jing_zhou_qi3);
		break;
	case IDC_EDIT_F_YUE_JING_ZHOU_QI2:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_YUE_JING_ZHOU_QI2,pFemaleInfo -> yue_jing_zhou_qi2);
		break;
	case IDC_EDIT_F_YUE_JING_ZHOU_QI1:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_YUE_JING_ZHOU_QI1,pFemaleInfo -> yue_jing_zhou_qi1);
		break;
	case IDC_EDIT_F_YUE_JING_SHI_YUE_JING_ZHOU_QI2:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_YUE_JING_SHI_YUE_JING_ZHOU_QI2,pFemaleInfo -> yue_jing_shi_yue_jing_zhou_qi2);
		break;
	case IDC_EDIT_F_YUE_JING_SHI_YUE_JING_ZHOU_QI1:
		DDX_Text_INT(pDX, IDC_EDIT_F_YUE_JING_SHI_YUE_JING_ZHOU_QI1,pFemaleInfo -> yue_jing_shi_yue_jing_zhou_qi1);
		break;
	case IDC_EDIT_F_YOU_CE_SHU_LUAN_GUAN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_YOU_CE_SHU_LUAN_GUAN,pFemaleInfo -> you_ce_shu_luan_guan);
		break;
	case IDC_EDIT_F_YOU_CE_LUAN_CHAO_FC:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_YOU_CE_LUAN_CHAO_FC,pFemaleInfo -> fu_ke_B_chao_you_ce_luan_chao_Fc);
		break;
	case IDC_EDIT_F_YOU_CE_LUAN_CHAO:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_YOU_CE_LUAN_CHAO,pFemaleInfo -> fu_ke_B_chao_you_ce_luan_chao);
		break;
	case IDC_EDIT_F_YIN_CHAN:
		DDX_Text_INT(pDX, IDC_EDIT_F_YIN_CHAN,pFemaleInfo -> yin_chan);
		break;
	case IDC_EDIT_F_YI_BAN_QING_KUANG_T:
		DDX_Text_FLOAT(pDX, IDC_EDIT_F_YI_BAN_QING_KUANG_T,pFemaleInfo -> yi_ban_qing_kuang_T);
		break;
	case IDC_EDIT_F_YI_BAN_QING_KUANG_R:
		DDX_Text_INT(pDX, IDC_EDIT_F_YI_BAN_QING_KUANG_R,pFemaleInfo -> yi_ban_qing_kuang_R);
		break;
	case IDC_EDIT_F_YI_BAN_QING_KUANG_P:
		DDX_Text_INT(pDX, IDC_EDIT_F_YI_BAN_QING_KUANG_P,pFemaleInfo -> yi_ban_qing_kuang_P);
		break;
	case IDC_EDIT_F_YI_BAN_QING_KUANG_BP2:
		DDX_Text_INT(pDX, IDC_EDIT_F_YI_BAN_QING_KUANG_BP2,pFemaleInfo -> yi_ban_qing_kuang_BP2);
		break;
	case IDC_EDIT_F_YI_BAN_QING_KUANG_BP1:
		DDX_Text_INT(pDX, IDC_EDIT_F_YI_BAN_QING_KUANG_BP1,pFemaleInfo -> yi_ban_qing_kuang_BP1);
		break;
	case IDC_EDIT_F_YAO_LIU:
		DDX_Text_INT(pDX, IDC_EDIT_F_YAO_LIU,pFemaleInfo -> yao_liu);
		break;
	case IDC_EDIT_F_XIAN_YOU_ZI_NV:
		DDX_Text_INT(pDX, IDC_EDIT_F_XIAN_YOU_ZI_NV,pFemaleInfo -> xian_you_zi_nv);
		break;
	case IDC_EDIT_F_XIAN_BING_SHI:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_XIAN_BING_SHI,pFemaleInfo -> xian_bing_shi);
		break;
	case IDC_EDIT_F_TI_ZHONG:
		DDX_Text_FLOAT(pDX, IDC_EDIT_F_TI_ZHONG,pFemaleInfo -> ti_zhong);
		break;
	case IDC_EDIT_F_FU_KE_B_CHAO_RI_QI:
			DDX_Text_CSTRING( pDX ,IDC_EDIT_F_FU_KE_B_CHAO_RI_QI , pFemaleInfo -> fu_ke_Bchao_ri_qi)  ;
			break;
	case IDC_EDIT_F_SHEN_GAO:
		DDX_Text_INT(pDX, IDC_EDIT_F_SHEN_GAO,pFemaleInfo -> shen_gao);
		break;
	case IDC_EDIT_F_REN_GONG_LIU_CHAN:
		DDX_Text_INT(pDX, IDC_EDIT_F_REN_GONG_LIU_CHAN,pFemaleInfo -> ren_gong_liu_chan);
		break;
	case IDC_EDIT_F_RAN_SE_TI:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_RAN_SE_TI,pFemaleInfo -> ran_se_ti);
		break;
	case IDC_EDIT_F_NV_YI_SHI:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_NV_YI_SHI,pFemaleInfo -> nv_yi_shi);
		break;
	case IDC_EDIT_F_MO_CI_YUE_JING:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_MO_CI_YUE_JING,pFemaleInfo -> mo_ci_yue_jing);
		break;
	case IDC_EDIT_F_MO_CI_REN_CHEN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_MO_CI_REN_CHEN,pFemaleInfo -> mo_ci_ren_shen);
		break;
	case IDC_EDIT_F_LUAN_PAO_ZHI_JING4:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_LUAN_PAO_ZHI_JING4,pFemaleInfo -> luan_pao_zhi_jing4);
		break;
	case IDC_EDIT_F_LUAN_PAO_ZHI_JING3:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_LUAN_PAO_ZHI_JING3,pFemaleInfo -> luan_pao_zhi_jing3);
		break;
	case IDC_EDIT_F_LUAN_PAO_ZHI_JING2:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_LUAN_PAO_ZHI_JING2,pFemaleInfo -> luan_pao_zhi_jing2);
		break;
	case IDC_EDIT_F_LUAN_PAO_ZHI_JING1:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_LUAN_PAO_ZHI_JING1,pFemaleInfo -> luan_pao_zhi_jing1);
		break;
	case IDC_EDIT_F_JI_WANG_QI_TA:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_JI_WANG_QI_TA,pFemaleInfo -> ji_wang_qi_ta);
		break;
	case IDC_EDIT_F_GONG_WAI_YUAN_ZUO:
		DDX_Text_INT(pDX, IDC_EDIT_F_GONG_WAI_YUAN_ZUO,pFemaleInfo -> gong_wai_yuan_zuo);
		break;
	case IDC_EDIT_F_GONG_WAI_YUAN_YOU:
		DDX_Text_INT(pDX, IDC_EDIT_F_GONG_WAI_YUAN_YOU,pFemaleInfo -> gong_wai_yuan_you);
		break;
	case IDC_EDIT_F_GONG_QIANG_JING:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_GONG_QIANG_JING,pFemaleInfo -> gong_qiang_jing);
		break;
	case IDC_EDIT_F_GONG_JING_JIAN_CHA:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_GONG_JING_JIAN_CHA,pFemaleInfo -> gong_jing_qi_ta);
		break;
	case IDC_EDIT_F_GONG_JING_GUA_PIAN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_GONG_JING_GUA_PIAN,pFemaleInfo -> gong_jing_gua_pian);
		break;
	case IDC_EDIT_F_FU_KE_ZI_GONG_NEI_MO:
		DDX_Text_FLOAT(pDX, IDC_EDIT_F_FU_KE_ZI_GONG_NEI_MO,pFemaleInfo -> fu_ke_Bchao_zi_gong_nei_mo);
		break;
	case IDC_EDIT_F_FU_KE_ZI_GONG_DA_XIAO:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_FU_KE_ZI_GONG_DA_XIAO,pFemaleInfo -> fu_ke_Bchao_zi_gong_da_xiao);
		break;
	case IDC_EDIT_F_EN_T:
		DDX_Text_FLOAT(pDX, IDC_EDIT_F_EN_T,pFemaleInfo -> EN_T);
		break;
	case IDC_EDIT_F_EN_PRL:
		DDX_Text_FLOAT(pDX, IDC_EDIT_F_EN_PRL,pFemaleInfo -> EN_PRL);
		break;
	case IDC_EDIT_F_EN_POSTALCODE:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_POSTALCODE,pFemaleInfo -> EN_postalcode);
		break;
	case IDC_EDIT_F_EN_PHONE:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_PHONE,pFemaleInfo -> EN_phone);
		break;
	case IDC_EDIT_F_EN_P:
		DDX_Text_FLOAT(pDX, IDC_EDIT_F_EN_P,pFemaleInfo -> EN_P);
		break;
	case IDC_EDIT_F_EN_occupation:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_occupation,pFemaleInfo -> EN_occupation);
		break;
	case IDC_EDIT_F_EN_NATION:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_NATION,pFemaleInfo -> EN_nation);
		break;
	case IDC_EDIT_F_EN_NAME:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_NAME,pFemaleInfo -> EN_name);
		break;
	case IDC_EDIT_F_EN_LH:
		DDX_Text_FLOAT(pDX, IDC_EDIT_F_EN_LH,pFemaleInfo -> EN_LH);
		break;
	case IDC_EDIT_F_EN_KNOWLEDGE_DEGREE:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_KNOWLEDGE_DEGREE,pFemaleInfo -> EN_knowledge_degree);
		break;
	case IDC_EDIT_F_EN_IDENTITY_CARD:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_IDENTITY_CARD,pFemaleInfo -> EN_identity_card);
		break;
	case IDC_EDIT_F_EN_FSH:
		DDX_Text_FLOAT(pDX, IDC_EDIT_F_EN_FSH,pFemaleInfo -> EN_FSH);
		break;
	case IDC_EDIT_F_EN_E_2:
		DDX_Text_FLOAT(pDX, IDC_EDIT_F_EN_E_2,pFemaleInfo -> EN_E_2);
		break;
	case IDC_EDIT_F_EN_COMPANY:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_COMPANY,pFemaleInfo -> EN_company);
		break;
	case IDC_EDIT_F_EN_AGE:
		DDX_Text_INT(pDX, IDC_EDIT_F_EN_AGE,pFemaleInfo -> EN_age);
		break;
	case IDC_EDIT_F_EN_ADDRESS:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_EN_ADDRESS,pFemaleInfo -> EN_address);
		break;
	case IDC_EDIT_F_CS_ZI_GONG_DA_XIAO:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_ZI_GONG_DA_XIAO,pFemaleInfo -> cs_fu_ke_jian_cha_zi_gong_da_xiao.strMore);
		break;
	case IDC_EDIT_F_CS_YING_YANG:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_YING_YANG,pFemaleInfo -> cs_ying_yang.strMore);
		break;
	case IDC_EDIT_F_CS_YIN_DAO:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_YIN_DAO,pFemaleInfo -> cs_yin_dao.strMore);
		break;
	case IDC_EDIT_F_CS_YI_CHUAN_BING_SHI:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_YI_CHUAN_BING_SHI,pFemaleInfo -> cs_yi_chuan_bing_shi.strMore);
		break;
	case IDC_EDIT_F_CS_YAO_WU_GUO_MIN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_YAO_WU_GUO_MIN,pFemaleInfo -> cs_yao_wu_guo_min.strMore);
		break;
	case IDC_EDIT_F_CS_XIN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_XIN,pFemaleInfo -> cs_xin.strMore);
		break;
	case IDC_EDIT_F_CS_WAI_YIN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_WAI_YIN,pFemaleInfo -> cs_wai_yin.strMore);
		break;
	case IDC_EDIT_F_CS_SHOU_SHU_SHI:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_SHOU_SHU_SHI,pFemaleInfo -> cs_shou_shu_shi.strMore);
		break;
	case IDC_EDIT_F_CS_SHEN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_SHEN,pFemaleInfo -> cs_shen.strMore);
		break;
	case IDC_EDIT_F_CS_RU_FANG:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_RU_FANG,pFemaleInfo -> cs_ru_fang.strMore);
		break;
	case IDC_EDIT_F_CS_PI_FU_NIAN_MO:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_PI_FU_NIAN_MO,pFemaleInfo -> cs_pi_fu_nian_mo.strMore);
		break;
	case IDC_EDIT_F_CS_PI:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_PI,pFemaleInfo -> cs_pi.strMore);
		break;
	case IDC_EDIT_F_CS_MAO_FA:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_MAO_FA,pFemaleInfo -> cs_mao_fa.strMore);
		break;
	case IDC_EDIT_F_CS_LIN_BA_JIE:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_LIN_BA_JIE,pFemaleInfo -> cs_lin_ba_jie.strMore);
		break;
	case IDC_EDIT_F_CS_JING_SHEN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_JING_SHEN,pFemaleInfo -> cs_jing_shen.strMore);
		break;
	case IDC_EDIT_F_CS_JIAN_KANG_ZHUANG_KUANG:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_JIAN_KANG_ZHUANG_KUANG,pFemaleInfo -> cs_jian_kang_zhuang_kuang.strMore);
		break;
	case IDC_EDIT_F_CS_JI_ZHU_SI_ZHI:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_JI_ZHU_SI_ZHI,pFemaleInfo -> cs_ji_zhu_si_zhi.strMore);
		break;
	case IDC_EDIT_F_CS_GAN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_GAN,pFemaleInfo -> cs_gan.strMore);
		break;
	case IDC_EDIT_F_CS_FU_JIAN_ZUO:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_FU_JIAN_ZUO,pFemaleInfo -> cs_fu_jian_zuo.strMore);
		break;
	case IDC_EDIT_F_CS_FU_JIAN_YOU:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_FU_JIAN_YOU,pFemaleInfo -> cs_fu_jian_you.strMore);
		break;
	case IDC_EDIT_F_CS_FEI:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_FEI,pFemaleInfo -> cs_fei.strMore);
		break;
	case IDC_EDIT_F_CS_FA_YU:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_FA_YU,pFemaleInfo -> cs_fa_yu.strMore);
		break;
	case IDC_EDIT_F_CS_CHU_SHENG_QUE_XIAN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_CHU_SHENG_QUE_XIAN,pFemaleInfo -> cs_chu_sheng_que_xian.strMore);
		break;
	case IDC_EDIT_F_CS_BU_YUN_BU_YU_SHI:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_CS_BU_YUN_BU_YU_SHI,pFemaleInfo -> cs_bu_yun_bu_yu_shi.strMore);
		break;
	case IDC_EDIT_F_CI_XI_YAN:
		DDX_Text_INT(pDX, IDC_EDIT_F_CI_XI_YAN,pFemaleInfo -> ci_xi_yan.iMore);
		break;
	case IDC_EDIT_F_CHU_CHAO:
		DDX_Text_INT(pDX, IDC_EDIT_F_CHU_CHAO,pFemaleInfo -> chu_chao);
		break;
	case IDC_EDIT_F_CHAN:
		DDX_Text_INT(pDX, IDC_EDIT_F_CHAN,pFemaleInfo -> chan);
		break;
	case IDC_EDIT_F_BING_SHI_XIAO_JIE:
		DDX_Text_CSTRING(pDX, IDC_EDIT_F_BING_SHI_XIAO_JIE,pFemaleInfo -> bing_shi_xiao_jie);
		break;
	case IDC_EDIT_EN_IDENTITY_CARD:
		DDX_Text_CSTRING(pDX, IDC_EDIT_EN_IDENTITY_CARD,pMaleInfo -> EN_identity_card);
		break;
	case IDC_EDIT_C_NI_XING_ZHI_LIAO_FANG_AN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_C_NI_XING_ZHI_LIAO_FANG_AN,pCommonInfo -> ni_xing_zhi_liao_fang_an);
		break;
	case IDC_EDIT_C_NI_XING_AIH_FANG_SHI:
		DDX_Text_CSTRING(pDX, IDC_EDIT_C_NI_XING_AIH_FANG_SHI,pCommonInfo -> ni_xing_AIH_fang_shi);
		break;
	case IDC_EDIT_C_JIN_JI_ZHENG:
		DDX_Text_CSTRING(pDX, IDC_EDIT_C_JIN_JI_ZHENG,pCommonInfo -> jin_ji_zheng);
		break;
	case IDC_EDIT_C_FU_ZHU_JIAN_CHA_YI_CHANG_JIE_GUO:
		DDX_Text_CSTRING(pDX, IDC_EDIT_C_FU_ZHU_JIAN_CHA_YI_CHANG_JIE_GUO,pCommonInfo -> fu_zhu_jian_cha_yi_chang_jie_guo);
		break;
	case IDC_EDIT_C_FU_HE_AIH_ZHI_ZHENG:
		DDX_Text_CSTRING(pDX, IDC_EDIT_C_FU_HE_AIH_ZHI_ZHENG,pCommonInfo -> fu_he_AIH_zhi_zheng);
		break;
	case IDC_EDIT_C_BING_LI_TE_DIAN:
		DDX_Text_CSTRING(pDX, IDC_EDIT_C_BING_LI_TE_DIAN,pCommonInfo -> bing_li_te_dian);
		break;
	case IDC_EDIT_C_BING_LI_HAO:
		DDX_Text_CSTRING(pDX, IDC_EDIT_C_BING_LI_HAO,pCommonInfo -> bing_li_hao);
		break;
	case IDC_EDIT_C_BING_CHENG_JI_LU_YI_SHI:
		DDX_Text_CSTRING(pDX, IDC_EDIT_C_BING_CHENG_JI_LU_YI_SHI,pCommonInfo -> bing_cheng_ji_lu_yi_shi);
		break;
	case IDC_EDIT_C_BING_CHENG_JI_LU_QI_TA:
		DDX_Text_CSTRING(pDX, IDC_EDIT_C_BING_CHENG_JI_LU_QI_TA,pCommonInfo -> bing_cheng_ji_lu_qi_ta);
		break;
	case IDC_COMBO_FU_KE_ZI_GONG_LEI_XING:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_FU_KE_ZI_GONG_LEI_XING,pFemaleInfo -> fu_ke_B_chao_zi_gong_lei_xing);
		break;
	case IDC_COMBO_F_ZI_GONG:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_ZI_GONG,pFemaleInfo -> zi_gong);
		break;
	case IDC_COMBO_F_ZHONG_DA_JING_SHEN_CI_JI:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_ZHONG_DA_JING_SHEN_CI_JI,pFemaleInfo -> zhong_da_jing_shen_ci_ji);
		break;
	case IDC_COMBO_F_ZHI_DI:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_ZHI_DI,pFemaleInfo -> zhi_di);
		break;
	case IDC_COMBO_F_ZAI_HUN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_ZAI_HUN,pFemaleInfo -> zai_hun);
		break;
	case IDC_COMBO_F_YA_TONG:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_YA_TONG,pFemaleInfo -> ya_tong);
		break;
	case IDC_COMBO_F_XU_JIU:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_XU_JIU,pFemaleInfo -> xu_jiu);
		break;
	case IDC_COMBO_F_XING_CHUAN_BO_JI_BING_SHI:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_XING_CHUAN_BO_JI_BING_SHI,pFemaleInfo -> xing_chuan_bo_ji_bing_shi);
		break;
	case IDC_COMBO_F_XIN_XUE_GUAN_JI_BING:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_XIN_XUE_GUAN_JI_BING,pFemaleInfo -> xin_xue_guan_ji_bing);
		break;
	case IDC_COMBO_F_XI_DU:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_XI_DU,pFemaleInfo -> xi_du);
		break;
	case IDC_COMBO_F_TING_JING:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_TING_JING,pFemaleInfo -> tong_jing);
		break;
	case IDC_COMBO_F_SHEN_ZANG_JI_BING:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_SHEN_ZANG_JI_BING,pFemaleInfo -> shen_zang_ji_bing);
		break;
	case IDC_COMBO_F_REN_CHEN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_REN_CHEN,pFemaleInfo -> ren_chen);
		break;
	case IDC_COMBO_F_PEN_QIANG_YAN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_PEN_QIANG_YAN,pFemaleInfo -> pen_qiang_yan);
		break;
	case IDC_COMBO_F_MI_NIAO_XI_TONG_GAN_RAN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_MI_NIAO_XI_TONG_GAN_RAN,pFemaleInfo -> mi_niao_xi_tong_gan_ran);
		break;
	case IDC_COMBO_F_LAN_WEI_YAN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_LAN_WEI_YAN,pFemaleInfo -> lan_wei_yan);
		break;
	case IDC_COMBO_F_JING_LIANG:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_JING_LIANG,pFemaleInfo -> jing_liang);
		break;
	case IDC_COMBO_F_JIN_QIN_JIE_HUN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_JIN_QIN_JIE_HUN,pFemaleInfo -> jin_qin_jie_hun);
		break;
	case IDC_COMBO_F_JIE_HE:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_JIE_HE,pFemaleInfo -> jie_he);
		break;
	case IDC_COMBO_F_JI_WANG_GAN_YAN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_JI_WANG_GAN_YAN,pFemaleInfo -> ji_wang_gan_yan);
		break;
	case IDC_COMBO_F_HUO_DONG_DU:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_HUO_DONG_DU,pFemaleInfo -> huo_dong_du);
		break;
	case IDC_COMBO_F_CS_ZI_GONG_DA_XIAO:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_ZI_GONG_DA_XIAO,pFemaleInfo -> cs_fu_ke_jian_cha_zi_gong_da_xiao.strBase);
		break;
	case IDC_COMBO_F_CS_YING_YANG:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_YING_YANG,pFemaleInfo -> cs_ying_yang.strBase);
		break;
	case IDC_COMBO_F_CS_YIN_DAO:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_YIN_DAO,pFemaleInfo -> cs_yin_dao.strBase);
		break;
	case IDC_COMBO_F_CS_YI_RU:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_YI_RU,pFemaleInfo -> yi_ru);
		break;
	case IDC_COMBO_F_CS_YI_CHUAN_BING_SHI:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_YI_CHUAN_BING_SHI,pFemaleInfo -> cs_yi_chuan_bing_shi.strBase);
		break;
	case IDC_COMBO_F_CS_YAO_WU_GUO_MIN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_YAO_WU_GUO_MIN,pFemaleInfo -> cs_yao_wu_guo_min.strBase);
		break;
	case IDC_COMBO_F_CS_XIN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_XIN,pFemaleInfo -> cs_xin.strBase);
		break;
	case IDC_COMBO_F_CS_WAI_YIN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_WAI_YIN,pFemaleInfo -> cs_wai_yin.strBase);
		break;
	case IDC_COMBO_F_CS_SHOU_SHU_SHI:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_SHOU_SHU_SHI,pFemaleInfo -> cs_shou_shu_shi.strBase);
		break;
	case IDC_COMBO_F_CS_SHEN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_SHEN,pFemaleInfo -> cs_shen.strBase);
		break;
	case IDC_COMBO_F_CS_RU_FANG:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_RU_FANG,pFemaleInfo -> cs_ru_fang.strBase);
		break;
	case IDC_COMBO_F_CS_PI_FU_NIAN_MO:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_PI_FU_NIAN_MO,pFemaleInfo -> cs_pi_fu_nian_mo.strBase);
		break;
	case IDC_COMBO_F_CS_PI:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_PI,pFemaleInfo -> cs_pi.strBase);
		break;
	case IDC_COMBO_F_CS_MAO_FA:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_MAO_FA,pFemaleInfo -> cs_mao_fa.strBase);
		break;
	case IDC_COMBO_F_CS_LIN_BA_JIE:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_LIN_BA_JIE,pFemaleInfo -> cs_lin_ba_jie.strBase);
		break;
	case IDC_COMBO_F_CS_JING_SHEN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_JING_SHEN,pFemaleInfo -> cs_jing_shen.strBase);
		break;
	case IDC_COMBO_F_CS_JIAN_KANG_ZHUANG_KUANG:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_JIAN_KANG_ZHUANG_KUANG,pFemaleInfo -> cs_jian_kang_zhuang_kuang.strBase);
		break;
	case IDC_COMBO_F_CS_JI_ZHU_SI_ZHI:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_JI_ZHU_SI_ZHI,pFemaleInfo -> cs_ji_zhu_si_zhi.strBase);
		break;
	case IDC_COMBO_F_CS_GONG_JING_MORE:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_GONG_JING_MORE,pFemaleInfo -> cs_gong_jing.strMore);
		break;
	case IDC_COMBO_F_CS_GONG_JING:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_GONG_JING,pFemaleInfo -> cs_gong_jing.strBase);
		break;
	case IDC_COMBO_F_CS_GAN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_GAN,pFemaleInfo -> cs_gan.strBase);
		break;
	case IDC_COMBO_F_CS_FU_JIAN_ZUO:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_FU_JIAN_ZUO,pFemaleInfo -> cs_fu_jian_zuo.strBase);
		break;
	case IDC_COMBO_F_CS_FU_JIAN_YOU:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_FU_JIAN_YOU,pFemaleInfo -> cs_fu_jian_you.strBase);
		break;
	case IDC_COMBO_F_CS_FEI:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_FEI,pFemaleInfo -> cs_fei.strBase);
		break;
	case IDC_COMBO_F_CS_FA_YU:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_FA_YU,pFemaleInfo -> cs_fa_yu.strBase);
		break;
	case IDC_COMBO_F_CS_CHU_SHENG_QUE_XIAN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_CHU_SHENG_QUE_XIAN,pFemaleInfo -> cs_chu_sheng_que_xian.strBase);
		break;
	case IDC_COMBO_F_CS_BU_YUN_BU_YU_SHI:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CS_BU_YUN_BU_YU_SHI,pFemaleInfo -> cs_bu_yun_bu_yu_shi.strBase);
		break;
	case IDC_COMBO_F_CI_XI_YAN:
		DDX_CBString_CSTRING(pDX,  IDC_COMBO_F_CI_XI_YAN,pFemaleInfo -> ci_xi_yan.strBase);
		break;
	case IDC_COMBO_F_ZHI_YUAN_TI:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_ZHI_YUAN_TI,pFemaleInfo -> zhi_yuan_ti);
		break;
	case IDC_COMBO_F_YI_YUAN_TI:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_YI_YUAN_TI,pFemaleInfo -> yi_yuan_ti);
		break;
	case IDC_COMBO_F_XUE_XING:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_XUE_XING,pFemaleInfo -> xue_xing);
		break;
	case IDC_COMBO_F_XUE_CHANG_GUI:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_XUE_CHANG_GUI,pFemaleInfo -> xue_chang_gui);
		break;
	case IDC_COMBO_F_XIAN_SUO_XI_BAO:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_XIAN_SUO_XI_BAO,pFemaleInfo -> xian_suo_xi_bao);
		break;
	case IDC_COMBO_F_SHEN_GONG:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_SHEN_GONG,pFemaleInfo -> shen_gong);
		break;
	case IDC_COMBO_F_RH_YIN_ZI:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_RH_YIN_ZI,pFemaleInfo -> Rh_yin_zi);
		break;
	case IDC_COMBO_F_QING_JIE_DU:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_QING_JIE_DU,pFemaleInfo -> qing_jie_du);
		break;
	case IDC_COMBO_F_MEI_JUN:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_MEI_JUN,pFemaleInfo -> mei_jun);
		break;
	case IDC_COMBO_F_KANG_ZI_GONG_NEI_MO_KANG_TI:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_KANG_ZI_GONG_NEI_MO_KANG_TI,pFemaleInfo -> kang_zi_gong_nei_mo_kang_ti);
		break;
	case IDC_COMBO_F_KANG_TOU_MING_DAI_KANG_TI:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_KANG_TOU_MING_DAI_KANG_TI,pFemaleInfo -> kang_tou_ming_dai_kang_ti);
		break;
	case IDC_COMBO_F_KANG_LUAN_CHAO_KANG_TI:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_KANG_LUAN_CHAO_KANG_TI,pFemaleInfo -> kang_luan_chao_kang_ti);
		break;
	case IDC_COMBO_F_KANG_JING_ZI_KANG_TI:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_KANG_JING_ZI_KANG_TI,pFemaleInfo -> kang_jing_zi_kang_ti);
		break;
	case IDC_COMBO_F_JU_XI_BAO_BING_DU:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_JU_XI_BAO_BING_DU,pFemaleInfo -> ju_xi_bao_bing_du);
		break;
	case IDC_COMBO_F_GONG_XING_CHONG:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_GONG_XING_CHONG,pFemaleInfo -> gong_xing_chong);
		break;
	case IDC_COMBO_F_GAN_GONG:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_GAN_GONG,pFemaleInfo -> gan_gong);
		break;
	case IDC_COMBO_F_FENG_ZHEN_BING_DU:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_FENG_ZHEN_BING_DU,pFemaleInfo -> feng_zhen_bing_du);
		break;
	case IDC_COMBO_F_EN_HIVAB:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HIVAB,pFemaleInfo -> EN_HIVAb);
		break;
	case IDC_COMBO_F_EN_HCVAG:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HCVAG,pFemaleInfo -> EN_HCVAg);
		break;
	case IDC_COMBO_F_EN_HCVAB:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HCVAB,pFemaleInfo -> EN_HCVAb);
		break;
	case IDC_COMBO_F_EN_HBSAG:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HBSAG,pFemaleInfo -> EN_HBSAG);
		break;
	case IDC_COMBO_F_EN_HBSAB:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HBSAB,pFemaleInfo -> EN_HBSAB);
		break;
	case IDC_COMBO_F_EN_HBEAG:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HBEAG,pFemaleInfo -> EN_HBEAG);
		break;
	case IDC_COMBO_F_EN_HBEAB:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HBEAB,pFemaleInfo -> EN_HBEAB);
		break;
	case IDC_COMBO_F_EN_HBCAB:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HBCAB,pFemaleInfo -> EN_HBCAB);
		break;
	case IDC_COMBO_F_EN_HAV_I:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_EN_HAV_I,pFemaleInfo -> EN_HAVI);
		break;
	case IDC_COMBO_F_DI_CHONG:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_DI_CHONG,pFemaleInfo -> di_chong);
		break;
	case IDC_COMBO_F_DAN_CHUN_PAO_ZHEN_BING_DU_II_XING:
		DDX_CBString_CSTRING(pDX, IDC_COMBO_F_DAN_CHUN_PAO_ZHEN_BING_DU_II_XING,pFemaleInfo -> dan_chun_pao_zhen_bing_du_II_xing);
		break;
	case IDC_COMB_F_NIAO_CHANG_GUI:
		DDX_CBString_CSTRING(pDX, IDC_COMB_F_NIAO_CHANG_GUI,pFemaleInfo -> niao_chang_gui);
		break;
	case IDC_DATETIMEPICKER_F_DATE_LUO_KUAN :
		DDX_DateTimeCtrl_CTIME(pDX, IDC_DATETIMEPICKER_F_DATE_LUO_KUAN ,pFemaleInfo -> nv_date_luo_kuan);
		break;
	case IDC_DATETIMEPICKER_C_DATE_YE_MEI :
		DDX_DateTimeCtrl_CTIME(pDX, IDC_DATETIMEPICKER_C_DATE_YE_MEI ,pCommonInfo -> date_ye_mei);  
		break;
	case IDC_DATETIMEPICKER_C_DATE_SHOU_CI_BING_CHENG_JI_LU :
		DDX_DateTimeCtrl_CTIME(pDX, IDC_DATETIMEPICKER_C_DATE_SHOU_CI_BING_CHENG_JI_LU ,pCommonInfo -> date_shou_ci_bing_cheng_ji_lu); 
		break;

	}

}
*/