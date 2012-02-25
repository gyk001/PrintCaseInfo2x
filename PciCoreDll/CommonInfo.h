#pragma once

// CCommonInfo 命令目标

class AFX_EXT_CLASS CCommonInfo : public CObject
{
protected:
    DECLARE_DYNCREATE(CCommonInfo)
public:
	CCommonInfo();
	virtual ~CCommonInfo();
    virtual void Serialize(CArchive& ar);
    void operator=(const CCommonInfo& ci);
public:
    CString     bing_li_hao;      //病例号
    CTime       date_ye_mei;      //日期
    CTime       date_shou_ci_bing_cheng_ji_lu; //首次病程记录
    CString     bing_li_te_dian;         //病例特点
    //CString     zhen_liao_ji_hua;       //诊疗计划
    CString     ni_xing_AIH_fang_shi;   //1、拟行AIH的方式：
    CString     fu_he_AIH_zhi_zheng;   //2、符合AIH的指征：
    CString     jin_ji_zheng;      //3、禁忌症：
    CString     ni_xing_zhi_liao_fang_an;      // 4、拟行治疗方案：
    CString     fu_zhu_jian_cha_yi_chang_jie_guo;//5、辅助检查异常结果：
    CString     bing_cheng_ji_lu_qi_ta;        //6、其它：
    CString     bing_cheng_ji_lu_yi_shi;       //医师
};


