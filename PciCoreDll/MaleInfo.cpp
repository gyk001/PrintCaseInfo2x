// mi.cpp : 实现文件
//

#include "stdafx.h"
#include "MaleInfo.h"

IMPLEMENT_DYNCREATE(CMaleInfo, CObject)
// CMaleInfo

CMaleInfo::CMaleInfo()
:
EN_age(0),				//年龄     
/*《男方信息-既往病史》*/
ji_wang_bing_shi_qi_ta( _T("无") ),
/*《个人史》*/
  
/*《婚姻史》*/


/*《一般体格检查》*/
shen_gao(0),				//身高		-数字
ti_zhong(0),				//体重		-数字
xue_ya1(0),				//血压		-数字
xue_ya2(0),				//血压		-数字
/*《第二性征》*/
/*《生殖系统检查》*/
sheng_zhi_qi_ta(_T("无")),	
gao_wan_ti_ji_zuo(0),		//睾丸体积左	-数字
gao_wan_ti_ji_you(0),		//睾丸体积右	-数字

/*《精液常规分析》*/
jin_yu_tian_shu(0),			//禁欲天数	-数字
jing_ye_liang(0),	//精液量	-数字
EN_PH(0),				//PH		-数字
ye_hua_shi_jian(0),	//液化时间	-数字
mi_du(0),				//密度		-数字
huo_li_A_ji(0),		//活力A级		-数字
huo_li_B_ji(0),		//活力B级		-数字
huo_li_C_ji(0),		//活力C级		-数字
huo_li_D_ji(0),		//活力D级		-数字
zheng_chang_xing_tai_lv(0),//正常形态率	-数字


/*《血型》*/

/*《微生物检查》*/

/*《肝炎》*/

/*《生殖激素》*/
sheng_zhi_ji_su(_T("未查"))	,//生殖激素
yi_chuan_xue_jian_cha(_T("未查"))	

{
	cs_mi_niao_sheng_zhi = CCascadeString(_T("有"));	//泌尿生殖病史	*无|有	-填空（有）  
	ci_xi_yan = CCascadeInt(_T("有"));				//吸烟		*无|有	-数字（有）
	cs_yao_wu_guo_min = CCascadeString(_T("有"));			//药物过敏史	*无|有	-填空（有）
    cs_chu_sheng_que_xian = CCascadeString(_T("有"));		//出生缺陷	*无|有	-填空（有） 
	/*《家族史》*/
	cs_yi_chuan_bing_shi=CCascadeString(_T("有"));	//遗传病史	*无|有	-填空（有）
	cs_bu_yun_bu_yu=CCascadeString(_T("有"));		//不孕不育病史	*无|有	-填空（有）
    /*《第二性征》*/
    cs_ru_fang = CCascadeString(_T("异常"));
	/*《生殖系统检查》*/
	cs_yin_jing=CCascadeString(_T("异常"));				//阴茎		*正常|异常	-填空（异常）
	cs_gao_wan_zhi_di_zuo=CCascadeString(_T("异常"));		//睾丸质地左	*正常|异常	-填空（异常）
	cs_gao_wan_zhi_di_you=CCascadeString(_T("异常"));		//睾丸质地右	*正常|异常	-填空（异常）
	cs_fu_gao_zuo=CCascadeString(_T("异常"));			//附睾左	*正常|异常	-填空（异常）
	cs_fu_gao_you=CCascadeString(_T("异常"));			//附睾右	*正常|异常	-填空（异常）
	cs_shu_jing_guan_zuo=CCascadeString(_T("异常"));		//输精管左	*正常|异常	-填空（异常）
	cs_shu_jing_guan_you=CCascadeString(_T("异常"));		//输精管右	*正常|异常	-填空（异常）
	cs_jing_suo_jing_mai_zuo=CCascadeString(_T("异常"));	//精索静脉左	*正常|异常	-填空（异常）
	cs_jing_suo_jing_mai_you=CCascadeString(_T("异常"));	//精索静脉右	*正常|异常	-填空（异常）
    date_jing_ye_fen_xi = CTime::GetCurrentTime();
    date_luo_kuan = CTime::GetCurrentTime();
    date_chu_zhen = CTime::GetCurrentTime();
}

CMaleInfo::~CMaleInfo()
{
}


// CMaleInfo 成员函数
// CMaleInfo 序列化

void CMaleInfo::Serialize(CArchive& ar,int marjorVersion, int minjorVersion)
{
	if (ar.IsStoring())
	{
		ar<< EN_name;//姓名
		ar<< EN_age;//年龄
 		ar<< EN_occupation ;//职业
		ar<< EN_knowledge_degree ;//文化程度
		ar<< EN_nation ;//民族
		ar<< EN_identity_card ;//身份证号码 
		ar<< EN_company ;//单位 
		ar<< EN_address ;//通信地址 
		ar<< EN_phone ;//联系电话 
		ar<< zhu_su ;//主诉 
		ar<< xian_bing_shi;		//! 现病史  

		/*《男方信息-既往病史》*/
		ar<< ji_wang_gan_yan;		//肝炎		*无|有                               
		ar<< jie_he;			//结核		*无|有                               
		ar<< xin_xue_guan;		//心血管疾病	*无|有                               
		ar<< xing_chuan_bo;		//性传播疾病	*无|有                               
		ar<< ji_wang_bing_shi_qi_ta;	//其他		-填空 
			/*《个人史》*/
		ar<< xu_jiu;				//酗酒		*无|有               
		ar<< zhong_da_jing_sheng_ci_ji;		//重大精神刺激史	*无|有               
		ar<< jian_kang_zhuang_kuang_guo_qu;		//健康状况过去	-填空
		ar<< jian_kang_zhuang_kuang_xian_zai	;//健康状况现在	-填空  
		/*《婚姻史》*/
		ar<<  jin_qin_jie_hun;       //近亲结婚              *否|是  
		ar<<zai_hun;                        //再婚          *否|是

		/*《一般体格检查》*/
		ar<< shen_gao;    //身高          -数字
		ar<< ti_zhong;     //体重          -数字
		ar<<xue_ya1;         //血压          -数字
		ar<<xue_ya2;         //血压          -数字
		/*《第二性征》*/
		ar<< hu_xu;        // 胡须            *有|无
		ar<< hou_jie;      //喉结          *正常|异常
		/*《生殖系统检查》*/
		ar<< yin_mao;                               //阴毛          *正常|异常
		ar<< gao_wan_ti_ji_zuo;              //睾丸体积左    -数字
		ar<< gao_wan_ti_ji_you;              //睾丸体积右    -数字
		ar<< sheng_zhi_qi_ta;                //其他          -填空
		/*《精液常规分析》*/

		ar<< jin_yu_tian_shu;                //禁欲天数      -数字
		ar<< jing_ye_liang;                  //精液量        -数字
		ar<< EN_PH;                          //PH            -数字
		ar<< ye_hua_shi_jian;                //液化时间      -数字
		ar<< mi_du;                          //密度          -数字
		ar<< huo_li_A_ji;                    //活力A级               -数字
		ar<< huo_li_B_ji;                    //活力B级               -数字
		ar<< huo_li_C_ji;                    //活力C级               -数字
		ar<< huo_li_D_ji;                    //活力D级               -数字
		ar<< zheng_chang_xing_tai_lv;//正常形态率    -数字
		ar<< bai_xi_bao;                     //白细胞                -数字

		/*《血型》*/ //???????????????????????????????以下类型
		ar<< xue_xing;       //血型          //待定
		ar<< Rh_yin_zi;      //Rh因子        //待定
		/*《微生物检查》*/
		ar<< lin_qiu_jun;    //淋球菌                
		ar<< zhi_yuan_ti;    //支原体
		ar<< yi_yuan_ti;     //衣原体
		/*《肝炎》*/
		
		if(false){
			ar<< gan_yan;        //肝炎
			ar<< EN_HIV;         //HIV
		}else{
			/*《男性信息-肝炎 HIV》*/
			ar<< EN_HBSAG;
			ar<< EN_HBSAB;
			ar<<  EN_HBEAG;

			ar<< EN_HBEAB;
			ar<< EN_HBCAB;
			ar<< EN_HAVI;

			ar<< EN_HCVAb; //HCVAb //待定
			ar<< EN_HCVAg; //HCV-Ag //待定
			ar<< EN_HIVAb; //HIVAb //待定
		}

		/*《生殖激素》*/
		ar<< sheng_zhi_ji_su;        //生殖激素
		ar<< yi_chuan_xue_jian_cha;  //遗传学检查
		ar<< chu_bu_zhen_duan;     //初步诊断
		/*《落款》*/
		ar<< nan_yi_shi;                     //医师          -填空


	}
	else
	{
		ar>> EN_name;//姓名
		ar>> EN_age;//年龄
 		ar>> EN_occupation ;//职业
		ar>> EN_knowledge_degree ;//文化程度
		ar>> EN_nation ;//民族
		ar>> EN_identity_card ;//身份证号码 
		ar>> EN_company ;//单位 
		ar>> EN_address ;//通信地址 
		ar>> EN_phone ;//联系电话 
		ar>> zhu_su ;//主诉 
		ar>> xian_bing_shi;		//! 现病史  

		/*《男方信息-既往病史》*/
		ar>> ji_wang_gan_yan;		//肝炎		*无|有                               
		ar>> jie_he;			//结核		*无|有                               
		ar>> xin_xue_guan;		//心血管疾病	*无|有                               
		ar>> xing_chuan_bo;		//性传播疾病	*无|有                               
		ar>> ji_wang_bing_shi_qi_ta;	//其他		-填空 
			/*《个人史》*/
		ar>> xu_jiu;				//酗酒		*无|有               
		ar>> zhong_da_jing_sheng_ci_ji;		//重大精神刺激史	*无|有               
		ar>> jian_kang_zhuang_kuang_guo_qu;		//健康状况过去	-填空
		ar>> jian_kang_zhuang_kuang_xian_zai	;//健康状况现在	-填空  
		/*《婚姻史》*/
		ar>>  jin_qin_jie_hun;       //近亲结婚              *否|是  
		ar>>zai_hun;                        //再婚          *否|是

		/*《一般体格检查》*/
		ar>> shen_gao;    //身高          -数字
		ar>> ti_zhong;     //体重          -数字
		ar>>xue_ya1;         //血压          -数字
		ar>>xue_ya2;         //血压          -数字
		/*《第二性征》*/
		ar>> hu_xu;        // 胡须            *有|无
		ar>> hou_jie;      //喉结          *正常|异常
		/*《生殖系统检查》*/
		ar>> yin_mao;                               //阴毛          *正常|异常
		ar>> gao_wan_ti_ji_zuo;              //睾丸体积左    -数字
		ar>> gao_wan_ti_ji_you;              //睾丸体积右    -数字
		ar>> sheng_zhi_qi_ta;                //其他          -填空
		/*《精液常规分析》*/

		ar>> jin_yu_tian_shu;                //禁欲天数      -数字
		ar>> jing_ye_liang;                  //精液量        -数字
		ar>> EN_PH;                          //PH            -数字
		ar>> ye_hua_shi_jian;                //液化时间      -数字
		ar>> mi_du;                          //密度          -数字
		ar>> huo_li_A_ji;                    //活力A级               -数字
		ar>> huo_li_B_ji;                    //活力B级               -数字
		ar>> huo_li_C_ji;                    //活力C级               -数字
		ar>> huo_li_D_ji;                    //活力D级               -数字
		ar>> zheng_chang_xing_tai_lv;//正常形态率    -数字
		ar>> bai_xi_bao;                     //白细胞               

		/*《血型》*/ //???????????????????????????????以下类型
		ar>> xue_xing;       //血型          //待定
		ar>> Rh_yin_zi;      //Rh因子        //待定
		/*《微生物检查》*/
		ar>> lin_qiu_jun;    //淋球菌                
		ar>> zhi_yuan_ti;    //支原体
		ar>> yi_yuan_ti;     //衣原体
		if(marjorVersion>=2 && minjorVersion>2){
			ar>> EN_HBSAG;
			ar>> EN_HBSAB;
			ar>>  EN_HBEAG;

			ar>> EN_HBEAB;
			ar>> EN_HBCAB;
			ar>> EN_HAVI;

			ar>> EN_HCVAb; //HCVAb //待定
			ar>> EN_HCVAg; //HCV-Ag //待定
			ar>> EN_HIVAb; //HIVAb //待定
		}else{
			CString unuseful;
			/*《肝炎》*/
			ar>> unuseful;//gan_yan;        //肝炎
			ar>> unuseful;// EN_HIV;         //HIV
		}
		/*《生殖激素》*/
		ar>> sheng_zhi_ji_su;        //生殖激素
		ar>> yi_chuan_xue_jian_cha;  //遗传学检查
		ar>> chu_bu_zhen_duan;     //初步诊断
		/*《落款》*/
		ar>> nan_yi_shi;                     //医师          -填空



	}
	/*《男方信息-既往病史》*/
	cs_mi_niao_sheng_zhi.Serialize(ar);	//泌尿生殖病史	*无|有	-填空（有）  
	/*《个人史》*/
	ci_xi_yan.Serialize(ar);				//吸烟		*无|有	-数字（有）
	cs_yao_wu_guo_min.Serialize(ar);			//药物过敏史	*无|有	-填空（有）
	cs_chu_sheng_que_xian.Serialize(ar);		//出生缺陷	*无|有	-填空（有） 
	/*《家族史》*/
	cs_yi_chuan_bing_shi.Serialize(ar);      //遗传病史      *无|有  -填空（有）
	cs_bu_yun_bu_yu.Serialize(ar);           //不孕不育病史  *无|有  -填空（有）
    /*第二性征*/
  //  if ( ar.IsStoring())
    {
        cs_ru_fang.Serialize( ar );
    }
	/*《生殖系统检查》*/
	cs_yin_jing.Serialize(ar);                       //阴茎          *正常|异常      -填空（异常）
	cs_gao_wan_zhi_di_zuo.Serialize(ar);             //睾丸质地左    *正常|异常      -填空（异常）
	cs_gao_wan_zhi_di_you.Serialize(ar);             //睾丸质地右    *正常|异常      -填空（异常）
	cs_fu_gao_zuo.Serialize(ar);                     //附睾左        *正常|异常      -填空（异常）
	cs_fu_gao_you.Serialize(ar);                     //附睾右        *正常|异常      -填空（异常）
	cs_shu_jing_guan_zuo.Serialize(ar);              //输精管左      *正常|异常      -填空（异常）
	cs_shu_jing_guan_you.Serialize(ar);              //输精管右      *正常|异常      -填空（异常）
	cs_jing_suo_jing_mai_zuo.Serialize(ar);  //精索静脉左    *正常|异常      -填空（异常）
	cs_jing_suo_jing_mai_you.Serialize(ar);  //精索静脉右    *正常|异常      -填空（异常）
    date_jing_ye_fen_xi.Serialize64( ar );  //精液常规分析-日期
    date_luo_kuan.Serialize64( ar );
    date_chu_zhen.Serialize64( ar );
    if (ar.IsStoring())
{
    
}
			
}

void CMaleInfo::operator=(const CMaleInfo& mi)
{
	EN_name=mi. EN_name;//姓名
	EN_age=mi. EN_age;//年龄
	EN_occupation=mi. EN_occupation ;//职业
	EN_knowledge_degree=mi. EN_knowledge_degree ;//文化程度
	EN_nation=mi. EN_nation ;//民族
	EN_identity_card=mi. EN_identity_card ;//身份证号码 
	EN_company=mi. EN_company ;//单位 
	EN_address =mi. EN_address ;//通信地址 
	EN_phone =mi. EN_phone ;//联系电话 
	zhu_su =mi. zhu_su ;//主诉 
    date_chu_zhen = mi.date_chu_zhen ;//初诊时间
	xian_bing_shi=mi. xian_bing_shi;		//! 现病史  



	/*《男方信息-既往病史》*/
	ji_wang_gan_yan=mi. ji_wang_gan_yan;		//肝炎		*无|有                               
	jie_he=mi. jie_he;			//结核		*无|有                               
	xin_xue_guan=mi. xin_xue_guan;		//心血管疾病	*无|有                               
	xing_chuan_bo=mi. xing_chuan_bo;		//性传播疾病	*无|有                               
	ji_wang_bing_shi_qi_ta=mi. ji_wang_bing_shi_qi_ta;	//其他		-填空 


	/*《个人史》*/
	xu_jiu=mi. xu_jiu;				//酗酒		*无|有               
	zhong_da_jing_sheng_ci_ji=mi. zhong_da_jing_sheng_ci_ji;		//重大精神刺激史	*无|有               
	jian_kang_zhuang_kuang_guo_qu=mi. jian_kang_zhuang_kuang_guo_qu;		//健康状况过去	-填空
	jian_kang_zhuang_kuang_xian_zai	=mi. jian_kang_zhuang_kuang_xian_zai	;//健康状况现在	-填空  


	/*《婚姻史》*/
	jin_qin_jie_hun=mi.  jin_qin_jie_hun;       //近亲结婚              *否|是  
	zai_hun=mi.zai_hun;                        //再婚          *否|是


	//*《一般体格检查》*/
	shen_gao=mi. shen_gao;    //身高          -数字
	ti_zhong=mi. ti_zhong;     //体重          -数字
	xue_ya1=mi.xue_ya1;         //血压          -数字
	xue_ya2=mi.xue_ya2;         //血压          -数字
	/*《第二性征》*/
	hu_xu=mi. hu_xu;        // 胡须            *有|无
	hou_jie=mi. hou_jie;      //喉结          *正常|异常
	cs_ru_fang=mi. cs_ru_fang;     //乳房          *正常|异常


	/*《生殖系统检查》*/
	yin_mao=mi. yin_mao;                               //阴毛          *正常|异常
	gao_wan_ti_ji_zuo=mi. gao_wan_ti_ji_zuo;              //睾丸体积左    -数字
	gao_wan_ti_ji_you=mi. gao_wan_ti_ji_you;              //睾丸体积右    -数字
	sheng_zhi_qi_ta=mi. sheng_zhi_qi_ta;                //其他          -填空

	/*《精液常规分析》*/
    date_jing_ye_fen_xi = mi.date_jing_ye_fen_xi;   //精液常规分析-日期
	jin_yu_tian_shu=mi. jin_yu_tian_shu;                //禁欲天数      -数字
	jing_ye_liang=mi. jing_ye_liang;                  //精液量        -数字
	EN_PH=mi. EN_PH;                          //PH            -数字
	ye_hua_shi_jian=mi. ye_hua_shi_jian;                //液化时间      -数字
	mi_du=mi. mi_du;                          //密度          -数字
	huo_li_A_ji=mi. huo_li_A_ji;                    //活力A级               -数字
	huo_li_B_ji=mi. huo_li_B_ji;                    //活力B级               -数字
	huo_li_C_ji=mi. huo_li_C_ji;                    //活力C级               -数字
	huo_li_D_ji=mi. huo_li_D_ji;                    //活力D级               -数字
	zheng_chang_xing_tai_lv=mi. zheng_chang_xing_tai_lv;//正常形态率    -数字
	bai_xi_bao=mi. bai_xi_bao;                     //白细胞                -数字

	 /*《血型》*/ //???????????????????????????????以下类型
	xue_xing=mi. xue_xing;       //血型          //待定
	Rh_yin_zi=mi. Rh_yin_zi;      //Rh因子        //待定


	/*《微生物检查》*/
	lin_qiu_jun=mi. lin_qiu_jun;    //淋球菌                
	zhi_yuan_ti=mi. zhi_yuan_ti;    //支原体
	yi_yuan_ti=mi. yi_yuan_ti;     //衣原体


	/*《肝炎》*/
	gan_yan=mi. gan_yan;        //肝炎
	EN_HIV=mi. EN_HIV;         //HIV


	/*《生殖激素》*/
	sheng_zhi_ji_su=mi. sheng_zhi_ji_su;        //生殖激素
	yi_chuan_xue_jian_cha=mi. yi_chuan_xue_jian_cha;  //遗传学检查
	chu_bu_zhen_duan=mi. chu_bu_zhen_duan;     //初步诊断

	/*《男方信息-既往病史》*/
	cs_mi_niao_sheng_zhi=mi.cs_mi_niao_sheng_zhi;	//泌尿生殖病史	*无|有	-填空（有）  

	/*《个人史》*/
	ci_xi_yan=mi.ci_xi_yan;				//吸烟		*无|有	-数字（有）
	cs_yao_wu_guo_min=mi.cs_yao_wu_guo_min;			//药物过敏史	*无|有	-填空（有）
	cs_chu_sheng_que_xian=mi.cs_chu_sheng_que_xian;		//出生缺陷	*无|有	-填空（有） 
	/*《家族史》*/
	cs_yi_chuan_bing_shi=mi.cs_yi_chuan_bing_shi;      //遗传病史      *无|有  -填空（有）
	cs_bu_yun_bu_yu=mi.cs_bu_yun_bu_yu;           //不孕不育病史  *无|有  -填空（有）

	/*《生殖系统检查》*/
	cs_yin_jing=mi.cs_yin_jing;                       //阴茎          *正常|异常      -填空（异常）
	cs_gao_wan_zhi_di_zuo=mi.cs_gao_wan_zhi_di_zuo;             //睾丸质地左    *正常|异常      -填空（异常）
	cs_gao_wan_zhi_di_you=mi.cs_gao_wan_zhi_di_you;             //睾丸质地右    *正常|异常      -填空（异常）
	cs_fu_gao_zuo=mi.cs_fu_gao_zuo;                     //附睾左        *正常|异常      -填空（异常）
	cs_fu_gao_you=mi.cs_fu_gao_you;                     //附睾右        *正常|异常      -填空（异常）
	cs_shu_jing_guan_zuo=mi.cs_shu_jing_guan_zuo;              //输精管左      *正常|异常      -填空（异常）
	cs_shu_jing_guan_you=mi.cs_shu_jing_guan_you;              //输精管右      *正常|异常      -填空（异常）
	cs_jing_suo_jing_mai_zuo=mi.cs_jing_suo_jing_mai_zuo;  //精索静脉左    *正常|异常      -填空（异常）
	cs_jing_suo_jing_mai_you=mi.cs_jing_suo_jing_mai_you;  //精索静脉右    *正常|异常      -填空（异常）
    /*《落款》*/
    nan_yi_shi=mi. nan_yi_shi;                     //医师          -填空
    date_luo_kuan = mi.date_luo_kuan;
    date_chu_zhen = mi.date_chu_zhen; //初诊时间

	EN_HBSAG=mi.EN_HBSAG ;
    EN_HBSAB=mi.EN_HBSAB ;
    EN_HBEAG=mi. EN_HBEAG;

    EN_HBEAB=mi. EN_HBEAB;
    EN_HBCAB=mi.EN_HBCAB;
    EN_HAVI=mi.EN_HAVI;
	
    EN_HCVAb=mi.EN_HCVAb; //HCVAb //待定
	EN_HCVAg=mi.EN_HCVAg; //HCV-Ag //待定
	EN_HIVAb=mi.EN_HIVAb; //HIVAb //待定
}