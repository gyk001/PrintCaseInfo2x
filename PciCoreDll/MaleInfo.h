#pragma once
#include "../GeneralDll/CascadeString.h"
#include "../GeneralDll/CascadeInt.h"
// CMaleInfo 命令目标

class AFX_EXT_CLASS CMaleInfo : public CObject
{
protected:

	DECLARE_DYNCREATE(CMaleInfo)
public:
	CMaleInfo();
	virtual ~CMaleInfo();
	virtual void Serialize(CArchive& ar,int marjorVersion, int minjorVersion);
	void operator=(const CMaleInfo& mi);
public:
	CString EN_name;				//姓名
	UINT EN_age;				//年龄
	CString EN_occupation ;			//职业
	CString EN_knowledge_degree ;	//文化程度
	CString EN_nation ;				//民族
	CString EN_identity_card ;		//身份证号码 
	CString EN_company ;			//单位 
	CString EN_address ;			//通信地址 
	CString EN_phone ;				//联系电话 
    CTime   date_chu_zhen;    //初诊时间
	CString zhu_su ;				//主诉 
	CString xian_bing_shi;			//现病史


	/*《男方信息-既往病史》*/
	CString ji_wang_gan_yan;		//肝炎		*无|有
	CString jie_he;			//结核		*无|有
	CString xin_xue_guan;		//心血管疾病	*无|有
	CString	xing_chuan_bo;		//性传播疾病	*无|有
	CCascadeString cs_mi_niao_sheng_zhi;	//泌尿生殖病史	*无|有	-填空（有）
	CString	ji_wang_bing_shi_qi_ta;	//其他		-填空
	/*《个人史》*/
	CCascadeInt ci_xi_yan;				//吸烟		*无|有	-数字（有）
	CString	xu_jiu;					//酗酒		*无|有
	CCascadeString cs_yao_wu_guo_min;			//药物过敏史	*无|有	-填空（有）
	CString zhong_da_jing_sheng_ci_ji;		//重大精神刺激史	*无|有
	CString jian_kang_zhuang_kuang_guo_qu;		//健康状况过去	-填空
	CString jian_kang_zhuang_kuang_xian_zai;	//健康状况现在	-填空
	CCascadeString cs_chu_sheng_que_xian;		//出生缺陷	*无|有	-填空（有）

	/*《婚姻史》*/
	CString		jin_qin_jie_hun;	//近亲结婚		*否|是	
	CString		zai_hun;			//再婚		*否|是
	/*《家族史》*/
	CCascadeString		cs_yi_chuan_bing_shi;	//遗传病史	*无|有	-填空（有）
	CCascadeString		cs_bu_yun_bu_yu;		//不孕不育病史	*无|有	-填空（有）
	/*《一般体格检查》*/
	int	 shen_gao;				//身高		-数字
	float	 ti_zhong;				//体重		-数字
	int	 xue_ya1;				//血压		-数字
	int	 xue_ya2;				//血压		-数字
	/*《第二性征》*/
	CString hu_xu;                  // 胡须            *有|无
	CString	hou_jie;				//喉结		*正常|异常
	CCascadeString	cs_ru_fang;				//乳房		*正常|异常
	/*《生殖系统检查》*/
	CCascadeString	 cs_yin_jing;				//阴茎		*正常|异常	-填空（异常）
	CString			 yin_mao;				//阴毛		*正常|异常
	int				gao_wan_ti_ji_zuo;		//睾丸体积左	-数字
	int				gao_wan_ti_ji_you;		//睾丸体积右	-数字
	CCascadeString	cs_gao_wan_zhi_di_zuo;		//睾丸质地左	*正常|异常	-填空（异常）
	CCascadeString	cs_gao_wan_zhi_di_you;		//睾丸质地右	*正常|异常	-填空（异常）
	CCascadeString	cs_fu_gao_zuo;			//附睾左	*正常|异常	-填空（异常）
	CCascadeString	cs_fu_gao_you;			//附睾右	*正常|异常	-填空（异常）
	CCascadeString	cs_shu_jing_guan_zuo;		//输精管左	*正常|异常	-填空（异常）
	CCascadeString	cs_shu_jing_guan_you;		//输精管右	*正常|异常	-填空（异常）
	CCascadeString	cs_jing_suo_jing_mai_zuo;	//精索静脉左	*正常|异常	-填空（异常）
	CCascadeString	cs_jing_suo_jing_mai_you;	//精索静脉右	*正常|异常	-填空（异常）
	CString sheng_zhi_qi_ta;				//其他		-填空
		/*《精液常规分析》*/
    CTime   date_jing_ye_fen_xi;
	int		jin_yu_tian_shu;		//禁欲天数	-数字
	float		jing_ye_liang;			//精液量	-数字
	float		EN_PH;				//PH		-数字
	int		ye_hua_shi_jian;		//液化时间	-数字
	float		mi_du;				//密度		-数字
	float		huo_li_A_ji;			//活力A级		-数字
	float		huo_li_B_ji;			//活力B级		-数字
	float		huo_li_C_ji;			//活力C级		-数字
	float		huo_li_D_ji;			//活力D级		-数字
	int		zheng_chang_xing_tai_lv;//正常形态率	-数字
	CString		bai_xi_bao;			//白细胞		-数字

	/*《血型》*/ 
	CString xue_xing;	//血型		//待定
	CString Rh_yin_zi;	//Rh因子	//待定
	/*《微生物检查》*/
	CString lin_qiu_jun;	//淋球菌		
	CString	zhi_yuan_ti;	//支原体
	CString	yi_yuan_ti;	//衣原体
	/*《肝炎》*/
	CString gan_yan;	//肝炎
	CString	EN_HIV;		//HIV
	/*《生殖激素》*/
	CString	sheng_zhi_ji_su;	//生殖激素
	CString	yi_chuan_xue_jian_cha;	//遗传学检查

	CString chu_bu_zhen_duan;	//初步诊断
	/*《落款》*/
	CString nan_yi_shi;			//医师		-填空
    CTime   date_luo_kuan;


	CString         EN_HBSAG;
    CString         EN_HBSAB;
    CString         EN_HBEAG;

    CString         EN_HBEAB;
    CString         EN_HBCAB;
    CString         EN_HAVI;

    CString         EN_HCVAb;               //HCVAb         //待定
	CString         EN_HCVAg;              //HCV-Ag        //待定
	CString         EN_HIVAb;               //HIVAb         //待定

};


