// CommonInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "CommonInfo.h"


// CCommonInfo
IMPLEMENT_DYNCREATE(CCommonInfo, CObject)

CCommonInfo::CCommonInfo()
{
    date_ye_mei=CTime::GetCurrentTime();
    date_shou_ci_bing_cheng_ji_lu=CTime::GetCurrentTime();
}

CCommonInfo::~CCommonInfo()
{
}


// CCommonInfo 成员函数
void CCommonInfo::Serialize(CArchive& ar,int marjorVersion, int minjorVersion)
{
    if (ar.IsStoring())
    {
        ar<<bing_li_hao;       
        ar<<bing_li_te_dian;          
        ar<<ni_xing_AIH_fang_shi;    
        ar<<fu_he_AIH_zhi_zheng;    
        ar<<jin_ji_zheng;       
        ar<<ni_xing_zhi_liao_fang_an;       
        ar<<fu_zhu_jian_cha_yi_chang_jie_guo; 
        ar<<bing_cheng_ji_lu_qi_ta;         
        ar<<bing_cheng_ji_lu_yi_shi;
    }
    else
    {
        ar>> bing_li_hao;       
        ar>> bing_li_te_dian;     
        ar>> ni_xing_AIH_fang_shi;    
        ar>> fu_he_AIH_zhi_zheng;    
        ar>> jin_ji_zheng;       
        ar>> ni_xing_zhi_liao_fang_an;       
        ar>> fu_zhu_jian_cha_yi_chang_jie_guo; 
        ar>> bing_cheng_ji_lu_qi_ta;         
        ar>> bing_cheng_ji_lu_yi_shi; 
		

    }
    date_ye_mei .Serialize64( ar );       
    date_shou_ci_bing_cheng_ji_lu.Serialize64( ar ) ;  
}

void CCommonInfo::operator=(const CCommonInfo& ci)
{
        bing_li_hao = ci. bing_li_hao;
        date_ye_mei = ci. date_ye_mei;
        date_shou_ci_bing_cheng_ji_lu = ci. date_shou_ci_bing_cheng_ji_lu;
        bing_li_te_dian = ci.bing_li_te_dian;
        ni_xing_AIH_fang_shi = ci.ni_xing_AIH_fang_shi;
        fu_he_AIH_zhi_zheng = ci. fu_he_AIH_zhi_zheng;
        jin_ji_zheng = ci. jin_ji_zheng;
        ni_xing_zhi_liao_fang_an = ci. ni_xing_zhi_liao_fang_an;
        fu_zhu_jian_cha_yi_chang_jie_guo = ci. fu_zhu_jian_cha_yi_chang_jie_guo;
        bing_cheng_ji_lu_qi_ta = ci. bing_cheng_ji_lu_qi_ta;
        bing_cheng_ji_lu_yi_shi = ci. bing_cheng_ji_lu_yi_shi;
}