// FemaleInfo.cpp : 实现文件

#include "stdafx.h"
#include "FemaleInfo.h"
#include <shlwapi.h>


// CFemaleInfo
IMPLEMENT_DYNCREATE(CFemaleInfo, CObject)

CFemaleInfo::CFemaleInfo()
:EN_age(0),				//年龄
gong_jing_gua_pian(_T("未查")),
/*《女方信息-月经史》*/
chu_chao(0),                       //初潮          -数字
yue_jing_shi_yue_jing_zhou_qi1(0),                       //月经周期              -数字   -数字
yue_jing_shi_yue_jing_zhou_qi2(_T("")),                       //月经周期              -数字   -数字

/*《女方信息-婚育史》*/
yun(),
chan(0),
ren_gong_liu_chan(0),      //人工流产      -数字
zi_ran_liu_chan(0),        //自然流产      -数字
yao_liu(0),                //药流          -数字
yin_chan(0),               //引产          -数字
zao_chan(0),               //早产          -数字
gong_wai_yuan_zuo(0),      //宫外孕（左）    -数字
gong_wai_yuan_you(0),      //宫外孕（右）    -数字
zu_yue_chan(0),            //足月产        -数字
xian_you_zi_nv(0),         //现有子女      -数字
/*《女方信息-体格检查》*/
yi_ban_qing_kuang_T(0),    //一般情况T     -数字
yi_ban_qing_kuang_P(0),    //一般情况P     -数字
yi_ban_qing_kuang_R(0),    //一般情况R     -数字
yi_ban_qing_kuang_BP1(0),   //一般情况BP    -数字   -数字
yi_ban_qing_kuang_BP2(0),
shen_gao(0),               //身高          -数字
ti_zhong(0),               //体重          -数字
/*《女性信息-基础内分泌》*/
EN_FSH(0),                 //FSH           -数字
EN_E_2(0),                 //E（下标2）      -数字
EN_P(0),                   //P             -数字
EN_LH(0),                  //LH            -数字
EN_PRL(0),                 //PRL   -数字
EN_T(0),                   //T             -数字
/* 《 肝功 》*/
ran_se_ti(_T("未查")),
/*《女性信息-妇科B超》*/
fu_ke_Bchao_zi_gong_da_xiao(_T("")),        //子宫大小              -数字
fu_ke_Bchao_zi_gong_nei_mo(0)         //子宫内膜              -数字   //待定“ABC”

{
	/*《女方信息-既往史》*/
	cs_shou_shu_shi= CCascadeString(_T("有"));                  //手术史                *无|有  -填空（有）
	/*《女方信息-个人史》*/
	ci_xi_yan=CCascadeInt(_T("有"));//吸烟           *无|有  -数字（有）
	cs_yao_wu_guo_min=CCascadeString(_T("有"));//药物过敏史   *无|有  -填空（有）
	cs_jian_kang_zhuang_kuang = CCascadeString( _T("健康") );
	cs_chu_sheng_que_xian=CCascadeString(_T("有"));//出生缺陷           *无|有  -填空（有）

	/*《女方信息-家族史》*/
	cs_yi_chuan_bing_shi= CCascadeString(_T("有"));     //遗传病史      *无|有  -填空（//待定）
	cs_bu_yun_bu_yu_shi= CCascadeString(_T("有"));      //不孕不育史    *无|有  -填空（//待定）

	/*《女方信息-体格检查》*/

	cs_ying_yang= CCascadeString(_T("异常"));             //营养          *正常|异常      -填空（异常）
	cs_fa_yu= CCascadeString(_T("异常"));                 //发育          *正常|异常      -填空（异常）
	cs_jing_shen= CCascadeString(_T("异常"));             //精神          *正常|异常      -填空（异常）
	cs_mao_fa= CCascadeString(_T("异常"));                //毛发          *正常|异常      -填空（异常）
	cs_pi_fu_nian_mo= CCascadeString(_T("异常"));         //皮肤粘膜      *正常|异常      -填空（异常）
	cs_lin_ba_jie= CCascadeString(_T("异常"));            //淋巴结        *正常|异常      -填空（异常）
	cs_ru_fang= CCascadeString(_T("异常"));               //乳房          *正常|异常      -填空（异常）
	cs_xin= CCascadeString(_T("异常"));                   //心            *正常|异常      -填空（异常）
	cs_fei= CCascadeString(_T("异常"));                   //肺            *正常|异常      -填空（异常）
	cs_gan= CCascadeString(_T("异常"));                   //肝            *正常|异常      -填空（异常）
	cs_pi= CCascadeString(_T("异常"));                    //脾            *正常|异常      -填空（异常）
	cs_shen= CCascadeString(_T("异常"));                  //肾            *正常|异常      -填空（异常）
	cs_ji_zhu_si_zhi= CCascadeString(_T("异常"));         //脊柱四肢      *正常|异常      -填空（异常）
	/*《女性信息-妇科检查》*/
	cs_wai_yin= CCascadeString(_T("异常"));               //外阴          *正常|异常      -填空（异常）
	cs_yin_dao= CCascadeString(_T("异常"));               //阴道          *正常|异常      -填空（异常）
	cs_gong_jing= CCascadeString(_T("糜烂"));             //宫颈          *光滑|糜烂      *轻|中|重（糜烂）
	cs_fu_ke_jian_cha_zi_gong_da_xiao= CCascadeString(_T("异常"));       //子宫大小              *正常|异常      -填空（异常）
	cs_fu_jian_zuo= CCascadeString(_T("异常"));           //附件（左）      *正常|异常      -填空（异常）
	cs_fu_jian_you= CCascadeString(_T("异常"));           //附件（右）      *正常|异常      -填空（异常）

	pen_qiang_yan = CCascadeString(_T("有"));           //盆腔炎      *无|有      -填空（有）

    nv_date_luo_kuan = CTime::GetCurrentTime();//
}

CFemaleInfo::~CFemaleInfo()
{
}

void CFemaleInfo::Save2_1(CArchive& ar)
{
	/*《女方信息：》*/
	ar<< EN_name;				//姓名
	ar<< EN_age;				//年龄
	ar<< EN_occupation ;			//职业
	ar<< EN_knowledge_degree ;	//文化程度
	ar<< EN_nation ;				//民族
	ar<< EN_identity_card ;		//身份证号码 
	ar<< EN_company ;			//单位 
	ar<< EN_address ;			//通信地址 
	ar<< EN_phone ;				//联系电话 
	ar<< EN_postalcode ;  //邮政编码
	ar<< zhen_duan ;  //诊断	
	ar<< zhu_su ;				//主诉 
	ar<< xian_bing_shi;			//现病史

	/*《女方信息-既往史》*/
	ar<<  ji_wang_gan_yan;  //肝炎 *无|有
	ar<<  jie_he;  //结核 *无|有
	ar<<  shen_zang_ji_bing;  //肾脏疾病 *无|有
	ar<<  xin_xue_guan_ji_bing;  //心血管疾病 *无|有
	ar<<  mi_niao_xi_tong_gan_ran;  //泌尿系感染 *无|有
	ar<<  xing_chuan_bo_ji_bing_shi; //性传播疾病史 *无|有
	ar<<  lan_wei_yan;  //阑尾炎 *无|有
	//ar<<  pen_qiang_yan;  //盆腔炎 *无|有
	pen_qiang_yan.Serialize(ar);
						AfxMessageBox( pen_qiang_yan.strBase+_T("*")+pen_qiang_yan.strHasMore+_T("*")+pen_qiang_yan.strMore );
	ar<<  ji_wang_qi_ta;  //其他  -填空

	/*《女方信息-个人史》*/
	ar<<  xu_jiu;  //酗酒 *无|有
	ar<<  xi_du;  //吸毒 *无|有
	ar<<  zhong_da_jing_shen_ci_ji;  //重大精神刺激史 *无|有
	/*《女方信息-月经史》*/
	ar<<  chu_chao;  //初潮 -数字
	ar<<  yue_jing_shi_yue_jing_zhou_qi1;  //月经周期 -数字 -数字
	ar<<  yue_jing_shi_yue_jing_zhou_qi2;  //月经周期 -数字 -数字
	ar<<  mo_ci_yue_jing;  //末次月经 //待定
	ar<<  jing_liang;  //经量 *正常|多|少
	ar<<  tong_jing;  //痛经 *有|无
	/*《女方信息-婚育史》*/
	ar<<  jin_qin_jie_hun;  //近亲结婚 *否|是
	ar<<  zai_hun;  //再婚 *否|是
	ar<<  ren_chen;  //妊娠 *否|是
	ar<<  mo_ci_ren_shen;  //末次妊娠时间 【年月】
	ar<<  yun;  //孕 //待定
	ar<<  chan;  //产 //待定
	ar<<  ren_gong_liu_chan; //人工流产 -数字
	ar<<  zi_ran_liu_chan; //自然流产 -数字
	ar<<  yao_liu; //药流 -数字
	ar<<  yin_chan; //引产 -数字
	ar<<  zao_chan; //早产 -数字
	ar<<  gong_wai_yuan_zuo; //宫外孕（左） -数字
	ar<<  gong_wai_yuan_you; //宫外孕（右） -数字
	ar<<  zu_yue_chan; //足月产 -数字
	ar<<  xian_you_zi_nv; //现有子女 -数字
	/*《女方信息-体格检查》*/
	ar<<  yi_ban_qing_kuang_T; //一般情况T -数字
	ar<<  yi_ban_qing_kuang_P; //一般情况P -数字
	ar<<  yi_ban_qing_kuang_R; //一般情况R -数字
	ar<<  yi_ban_qing_kuang_BP1; //一般情况BP -数字 -数字
	ar<< yi_ban_qing_kuang_BP2;
	ar<<  shen_gao; //身高 -数字
	ar<<  ti_zhong; //体重 -数字
	ar<< yi_ru; //溢乳 - 无|有

	/*《女性信息-妇科检查》*/
	ar<<  gong_jing_qi_ta; //宫颈其他 -填空
	ar<<  zi_gong; //子宫 *前位|后位|平位
	ar<<  zhi_di;  //质地 *软|中|硬
	ar<<  huo_dong_du; //活动度 *活动|受限|固定
	ar<<  ya_tong; //压痛 *无|有
	/*《女性信息-.》*/
	ar<< xue_chang_gui; //血常规 -填空
	ar<< niao_chang_gui; //尿常规 -填空
	/*《女性信息-血型》*/
	ar<< xue_xing; //血型 //待定
	ar<< Rh_yin_zi; //Rh因子 //待定
	/*《女性信息-基础内分泌》*/
	ar<< EN_FSH;  //FSH -数字
	ar<< EN_E_2;  //E（下标2） -数字
	ar<< EN_P;  //P -数字
	ar<< EN_LH;  //LH -数字
	ar<< EN_PRL;  //PRL -数字
	ar<< EN_T;  //T -数字
	/*《女性信息-TORCH》*/
	ar<< gong_xing_chong;  //弓形虫 //待定
	ar<< ju_xi_bao_bing_du;  //巨细胞病毒 //待定
	ar<< feng_zhen_bing_du;  //风疹病毒 //待定
	ar<< dan_chun_pao_zhen_bing_du_II_xing; //单纯疱疹病毒II型 //待定
	/*《女性信息-肝炎 HIV》*/
	ar<< EN_HBSAG;
	ar<< EN_HBSAB;
	ar<<  EN_HBEAG;

	ar<< EN_HBEAB;
	ar<<EN_HBCAB;
	ar<< EN_HAVI;

	ar<< EN_HCVAb; //HCVAb //待定
	ar<< EN_HCVAg; //HCV-Ag //待定
	ar<< EN_HIVAb; //HIVAb //待定
	/*《女性信息-不孕四抗体》*/
	ar<< kang_zi_gong_nei_mo_kang_ti; //抗子宫内膜抗体//待定
	ar<< kang_luan_chao_kang_ti; //抗卵巢抗体 //待定
	ar<< kang_tou_ming_dai_kang_ti; //抗透明带抗体 //待定
	ar<< kang_jing_zi_kang_ti; //抗精子抗体 //待定
	/*《女性信息-.》*/
	ar<< gan_gong;//肝功 //待定
	ar<< shen_gong;//肾功 //待定
	ar<< ran_se_ti;//染色体 //待定
	/*《女性信息-宫颈刮片》*/
	ar<< gong_jing_gua_pian;		//宫颈刮片 -填空
	/*《女性信息-宫颈涂片》*/
	ar<< zhi_yuan_ti; //支原体 //待定
	ar<< yi_yuan_ti; //衣原体 //待定
	ar<< di_chong; //滴虫  //待定
	ar<< mei_jun; //霉菌  //待定
	ar<< xian_suo_xi_bao; //线索细胞 //待定
	ar<< qing_jie_du; //清洁度 
	/*《女性信息-子宫输卵管造影》*/
	ar<< zi_gong_xing_tai; //子宫形态 -填空
	ar<< zuo_ce_shu_luan_guan; //左侧输卵管 -填空
	ar<< you_ce_shu_luan_guan; //右侧输卵管 -填空
	/*《女性信息-妇科B超》*/
	ar<<fu_ke_Bchao_ri_qi;
	ar<< fu_ke_Bchao_zi_gong_da_xiao; //子宫大小 -数字
	ar<< fu_ke_Bchao_zi_gong_nei_mo; //子宫内膜 -数字 
	ar<< fu_ke_B_chao_zi_gong_lei_xing; //待定“ABC”
	ar<< fu_ke_B_chao_you_ce_luan_chao; //右侧卵巢 -填空
	ar<< fu_ke_B_chao_you_ce_luan_chao_Fc; //右侧卵巢 -填空
	ar<< fu_ke_B_chao_zuo_ce_luan_chao; //左侧卵巢 -填空
	ar<< fu_ke_B_chao_zuo_ce_luan_chao_Fc; //左侧卵巢 -填空
	/*《女性信息-宫腔镜》*/
	ar<< gong_qiang_jing; //宫腔镜 -填空
	/*《女性信息-治疗前自然周期排卵监测》*/

	ar<< nv_pai_luan_jian_ce_ri_qi1;
	ar<< yue_jing_zhou_qi1; //月经周期 //待定
	ar<< luan_pao_zhi_jing1; //卵泡直径 //待定
	ar<< zi_gong_nei_mo1; //子宫内膜 //待定

	ar<< nv_pai_luan_jian_ce_ri_qi2;
	ar<< yue_jing_zhou_qi2; //月经周期 //待定
	ar<< luan_pao_zhi_jing2; //卵泡直径 //待定
	ar<< zi_gong_nei_mo2; //子宫内膜 //待定

	ar<< nv_pai_luan_jian_ce_ri_qi3;
	ar<< yue_jing_zhou_qi3; //月经周期 //待定
	ar<< luan_pao_zhi_jing3; //卵泡直径 //待定
	ar<< zi_gong_nei_mo3; //子宫内膜 //待定

	ar<< nv_pai_luan_jian_ce_ri_qi4;
	ar<< yue_jing_zhou_qi4; //月经周期 //待定
	ar<< luan_pao_zhi_jing4; //卵泡直径 //待定
	ar<< zi_gong_nei_mo4; //子宫内膜 //待定
	/*《女性信息-病史小结》*/
	ar<< bing_shi_xiao_jie; //病史小结 -填空
	/*《女性信息-诊断》*/
	//ar<< zhen_duan; //诊断 -填空
	/*《女性信息-诊疗计划》*/
	ar<< zheng_liao_ji_hua; //诊疗计划 -填空
	/*《女性信息-落款》*/
	ar<< nv_yi_shi; //医师 -填空

	/*《女方信息-既往史》*/
	cs_shou_shu_shi.Serialize(ar);                  //手术史                *无|有  -填空（有）
	/*《女方信息-个人史》*/
	ci_xi_yan.Serialize(ar);//吸烟           *无|有  -数字（有）
	cs_yao_wu_guo_min.Serialize(ar);//药物过敏史   *无|有  -填空（有）
	cs_jian_kang_zhuang_kuang .Serialize( ar );
	cs_chu_sheng_que_xian.Serialize(ar);//出生缺陷           *无|有  -填空（有）

	/*《女方信息-家族史》*/
	cs_yi_chuan_bing_shi.Serialize(ar);     //遗传病史      *无|有  -填空（//待定）
	cs_bu_yun_bu_yu_shi.Serialize(ar);      //不孕不育史    *无|有  -填空（//待定）

	/*《女方信息-体格检查》*/

	cs_ying_yang.Serialize(ar);             //营养          *正常|异常      -填空（异常）
	cs_fa_yu.Serialize(ar);                 //发育          *正常|异常      -填空（异常）
	cs_jing_shen.Serialize(ar);             //精神          *正常|异常      -填空（异常）
	cs_mao_fa.Serialize(ar);                //毛发          *正常|异常      -填空（异常）
	cs_pi_fu_nian_mo.Serialize(ar);         //皮肤粘膜      *正常|异常      -填空（异常）
	cs_lin_ba_jie.Serialize(ar);            //淋巴结        *正常|异常      -填空（异常）
	cs_ru_fang.Serialize(ar);               //乳房          *正常|异常      -填空（异常）
	cs_xin.Serialize(ar);                   //心            *正常|异常      -填空（异常）
	cs_fei.Serialize(ar);                   //肺            *正常|异常      -填空（异常）
	cs_gan.Serialize(ar);                   //肝            *正常|异常      -填空（异常）
	cs_pi.Serialize(ar);                    //脾            *正常|异常      -填空（异常）
	cs_shen.Serialize(ar);                  //肾            *正常|异常      -填空（异常）
	cs_ji_zhu_si_zhi.Serialize(ar);         //脊柱四肢      *正常|异常      -填空（异常）
	/*《女性信息-妇科检查》*/
	cs_wai_yin.Serialize(ar);               //外阴          *正常|异常      -填空（异常）
	cs_yin_dao.Serialize(ar);               //阴道          *正常|异常      -填空（异常）
	cs_gong_jing.Serialize(ar);             //宫颈          *光滑|糜烂      *轻|中|重（糜烂）
	cs_fu_ke_jian_cha_zi_gong_da_xiao.Serialize(ar);       //子宫大小              *正常|异常      -填空（异常）
	cs_fu_jian_zuo.Serialize(ar);           //附件（左）      *正常|异常      -填空（异常）
	cs_fu_jian_you.Serialize(ar);           //附件（右）      *正常|异常      -填空（异常）

	nv_date_luo_kuan.Serialize64( ar );
}
void CFemaleInfo::Serialize(CArchive& ar,int marjorVersion, int minjorVersion)
{
	if (ar.IsStoring())
	{
		Save2_1(ar);
	} 
	else
	{
		CString tmpstr ;

		/*《女方信息：》*/
		ar>> EN_name;				//姓名
		ar>> EN_age;				//年龄
		ar>> EN_occupation ;			//职业
		ar>> EN_knowledge_degree ;	//文化程度
		ar>> EN_nation ;				//民族
		ar>> EN_identity_card ;		//身份证号码 
		ar>> EN_company ;			//单位 
		ar>> EN_address ;			//通信地址 
		ar>> EN_phone ;				//联系电话 
		ar>> EN_postalcode ;  //邮政编码
		ar>> zhen_duan ;  //诊断	
		ar>> zhu_su ;				//主诉 
		ar>> xian_bing_shi;			//现病史

		/*《女方信息-既往史》*/
		ar>>  ji_wang_gan_yan;  //肝炎 *无|有
		ar>>  jie_he;  //结核 *无|有
		ar>>  shen_zang_ji_bing;  //肾脏疾病 *无|有
		ar>>  xin_xue_guan_ji_bing;  //心血管疾病 *无|有
		ar>>  mi_niao_xi_tong_gan_ran;  //泌尿系感染 *无|有
		ar>>  xing_chuan_bo_ji_bing_shi; //性传播疾病史 *无|有
		ar>>  lan_wei_yan;  //阑尾炎 *无|有

		if(marjorVersion>=2 && minjorVersion>2){
			AfxMessageBox( pen_qiang_yan.strBase+_T("*")+pen_qiang_yan.strHasMore+_T("*")+pen_qiang_yan.strMore );
			pen_qiang_yan.Serialize(ar) ; //盆腔炎 *无|有
					AfxMessageBox( pen_qiang_yan.strBase+_T("*")+pen_qiang_yan.strHasMore+_T("*")+pen_qiang_yan.strMore );
		}else{
			AfxMessageBox( _T("/") );
			ar>>tmpstr;
			pen_qiang_yan.strBase = tmpstr; 
		}
		ar>>  ji_wang_qi_ta;  //其他  -填空

		/*《女方信息-个人史》*/
		ar>>  xu_jiu;  //酗酒 *无|有
		ar>>  xi_du;  //吸毒 *无|有
		ar>>  zhong_da_jing_shen_ci_ji;  //重大精神刺激史 *无|有
		/*《女方信息-月经史》*/
		ar>>  chu_chao;  //初潮 -数字
		ar>>  yue_jing_shi_yue_jing_zhou_qi1;  //月经周期 -数字 -数字
		ar>>  yue_jing_shi_yue_jing_zhou_qi2;  //月经周期 -数字 -数字
		ar>>  mo_ci_yue_jing;  //末次月经 //待定
		ar>>  jing_liang;  //经量 *正常|多|少
		ar>>  tong_jing;  //痛经 *有|无
		/*《女方信息-婚育史》*/
		ar>>  jin_qin_jie_hun;  //近亲结婚 *否|是
		ar>>  zai_hun;  //再婚 *否|是
		ar>>  ren_chen;  //妊娠 *否|是
		ar>>  mo_ci_ren_shen;  //末次妊娠时间 【年月】
		ar>>  yun;  //孕 //待定
		ar>>  chan;  //产 //待定
		ar>>  ren_gong_liu_chan; //人工流产 -数字
		ar>>  zi_ran_liu_chan; //自然流产 -数字
		ar>>  yao_liu; //药流 -数字
		ar>>  yin_chan; //引产 -数字
		ar>>  zao_chan; //早产 -数字
		ar>>  gong_wai_yuan_zuo; //宫外孕（左） -数字
		ar>>  gong_wai_yuan_you; //宫外孕（右） -数字
		ar>>  zu_yue_chan; //足月产 -数字
		ar>>  xian_you_zi_nv; //现有子女 -数字
		/*《女方信息-体格检查》*/
		ar>>  yi_ban_qing_kuang_T; //一般情况T -数字
		ar>>  yi_ban_qing_kuang_P; //一般情况P -数字
		ar>>  yi_ban_qing_kuang_R; //一般情况R -数字
		ar>>  yi_ban_qing_kuang_BP1; //一般情况BP -数字 -数字
		ar>>  yi_ban_qing_kuang_BP2;
		ar>>  shen_gao; //身高 -数字
		ar>>  ti_zhong; //体重 -数字
		ar>> yi_ru; //溢乳 - 无|有
		/*《女性信息-妇科检查》*/
		ar>>  gong_jing_qi_ta; //宫颈其他 -填空
		ar>>  zi_gong; //子宫 *前位|后位|平位
		ar>>  zhi_di;  //质地 *软|中|硬
		ar>>  huo_dong_du; //活动度 *活动|受限|固定
		ar>>  ya_tong; //压痛 *无|有
		/*《女性信息-.》*/
		ar>> xue_chang_gui; //血常规 -填空
		ar>> niao_chang_gui; //尿常规 -填空
		/*《女性信息-血型》*/
		ar>> xue_xing; //血型 //待定
		ar>> Rh_yin_zi; //Rh因子 //待定
		/*《女性信息-基础内分泌》*/
		ar>> EN_FSH;  //FSH -数字
		ar>> EN_E_2;  //E（下标2） -数字
		ar>> EN_P;  //P -数字
		ar>> EN_LH;  //LH -数字
		ar>> EN_PRL;  //PRL -数字
		ar>> EN_T;  //T -数字
		/*《女性信息-TORCH》*/
		ar>> gong_xing_chong;  //弓形虫 //待定
		ar>> ju_xi_bao_bing_du;  //巨细胞病毒 //待定
		ar>> feng_zhen_bing_du;  //风疹病毒 //待定
		ar>> dan_chun_pao_zhen_bing_du_II_xing; //单纯疱疹病毒II型 //待定
		/*《女性信息-肝炎 HIV》*/
		ar>> EN_HBSAG;
		ar>> EN_HBSAB;
		ar>>  EN_HBEAG;

		ar>> EN_HBEAB;
		ar>> EN_HBCAB;
		ar>> EN_HAVI;

		ar>> EN_HCVAb; //HCVAb //待定
		ar>> EN_HCVAg; //HCV-Ag //待定
		ar>> EN_HIVAb; //HIVAb //待定
		/*《女性信息-不孕四抗体》*/
		ar>> kang_zi_gong_nei_mo_kang_ti; //抗子宫内膜抗体//待定
		ar>> kang_luan_chao_kang_ti; //抗卵巢抗体 //待定
		ar>> kang_tou_ming_dai_kang_ti; //抗透明带抗体 //待定
		ar>> kang_jing_zi_kang_ti; //抗精子抗体 //待定
		/*《女性信息-.》*/
		ar>> gan_gong;//肝功 //待定
		ar>> shen_gong;//肾功 //待定
		ar>> ran_se_ti;//染色体 //待定
		/*《女性信息-宫颈刮片》*/
		ar>> gong_jing_gua_pian;		//宫颈刮片 -填空
		/*《女性信息-宫颈涂片》*/
		ar>> zhi_yuan_ti; //支原体 //待定
		ar>> yi_yuan_ti; //衣原体 //待定
		ar>> di_chong; //滴虫  //待定
		ar>> mei_jun; //霉菌  //待定
		ar>> xian_suo_xi_bao; //线索细胞 //待定
		ar>> qing_jie_du; //清洁度 
		/*《女性信息-子宫输卵管造影》*/
		ar>> zi_gong_xing_tai; //子宫形态 -填空
		ar>> zuo_ce_shu_luan_guan; //左侧输卵管 -填空
		ar>> you_ce_shu_luan_guan; //右侧输卵管 -填空
		/*《女性信息-妇科B超》*/
		ar >> fu_ke_Bchao_ri_qi;
		ar>> fu_ke_Bchao_zi_gong_da_xiao; //子宫大小 -数字
		ar>> fu_ke_Bchao_zi_gong_nei_mo; //子宫内膜 -数字
		ar>> fu_ke_B_chao_zi_gong_lei_xing; //待定“ABC”
		ar>> fu_ke_B_chao_you_ce_luan_chao; //右侧卵巢 -填空
		ar>> fu_ke_B_chao_you_ce_luan_chao_Fc; //右侧卵巢 -填空
		ar>> fu_ke_B_chao_zuo_ce_luan_chao; //左侧卵巢 -填空
		ar>> fu_ke_B_chao_zuo_ce_luan_chao_Fc; //左侧卵巢 -填空
		/*《女性信息-宫腔镜》*/
		ar>> gong_qiang_jing; //宫腔镜 -填空
		/*《女性信息- 治疗前自然周期排卵监测》*/

		ar>> nv_pai_luan_jian_ce_ri_qi1;
		ar>> yue_jing_zhou_qi1; //月经周期 //待定
		ar>> luan_pao_zhi_jing1; //卵泡直径 //待定
		ar>> zi_gong_nei_mo1; //子宫内膜 //待定

		ar>> nv_pai_luan_jian_ce_ri_qi2;
		ar>> yue_jing_zhou_qi2; //月经周期 //待定
		ar>> luan_pao_zhi_jing2; //卵泡直径 //待定
		ar>> zi_gong_nei_mo2; //子宫内膜 //待定

		ar>> nv_pai_luan_jian_ce_ri_qi3;
		ar>> yue_jing_zhou_qi3; //月经周期 //待定
		ar>> luan_pao_zhi_jing3; //卵泡直径 //待定
		ar>> zi_gong_nei_mo3; //子宫内膜 //待定

		ar>> nv_pai_luan_jian_ce_ri_qi4;
		ar>> yue_jing_zhou_qi4; //月经周期 //待定
		ar>> luan_pao_zhi_jing4; //卵泡直径 //待定
		ar>> zi_gong_nei_mo4; //子宫内膜 //待定

		/*《女性信息-病史小结》*/
		ar>> bing_shi_xiao_jie; //病史小结 -填空
		/*《女性信息-诊断》*/
		//ar>> zhen_duan; //诊断 -填空
		/*《女性信息-诊疗计划》*/
		ar>> zheng_liao_ji_hua; //诊疗计划 -填空
		/*《女性信息-落款》*/
		ar>> nv_yi_shi; //医师 -填空
		/*《女方信息-既往史》*/
		cs_shou_shu_shi.Serialize(ar);                  //手术史                *无|有  -填空（有）
		/*《女方信息-个人史》*/
		ci_xi_yan.Serialize(ar);//吸烟           *无|有  -数字（有）
		cs_yao_wu_guo_min.Serialize(ar);//药物过敏史   *无|有  -填空（有）
		cs_jian_kang_zhuang_kuang .Serialize( ar );
		cs_chu_sheng_que_xian.Serialize(ar);//出生缺陷           *无|有  -填空（有）

		/*《女方信息-家族史》*/
		cs_yi_chuan_bing_shi.Serialize(ar);     //遗传病史      *无|有  -填空（//待定）
		cs_bu_yun_bu_yu_shi.Serialize(ar);      //不孕不育史    *无|有  -填空（//待定）

		/*《女方信息-体格检查》*/

		cs_ying_yang.Serialize(ar);             //营养          *正常|异常      -填空（异常）
		cs_fa_yu.Serialize(ar);                 //发育          *正常|异常      -填空（异常）
		cs_jing_shen.Serialize(ar);             //精神          *正常|异常      -填空（异常）
		cs_mao_fa.Serialize(ar);                //毛发          *正常|异常      -填空（异常）
		cs_pi_fu_nian_mo.Serialize(ar);         //皮肤粘膜      *正常|异常      -填空（异常）
		cs_lin_ba_jie.Serialize(ar);            //淋巴结        *正常|异常      -填空（异常）
		cs_ru_fang.Serialize(ar);               //乳房          *正常|异常      -填空（异常）
		cs_xin.Serialize(ar);                   //心            *正常|异常      -填空（异常）
		cs_fei.Serialize(ar);                   //肺            *正常|异常      -填空（异常）
		cs_gan.Serialize(ar);                   //肝            *正常|异常      -填空（异常）
		cs_pi.Serialize(ar);                    //脾            *正常|异常      -填空（异常）
		cs_shen.Serialize(ar);                  //肾            *正常|异常      -填空（异常）
		cs_ji_zhu_si_zhi.Serialize(ar);         //脊柱四肢      *正常|异常      -填空（异常）
		/*《女性信息-妇科检查》*/
		cs_wai_yin.Serialize(ar);               //外阴          *正常|异常      -填空（异常）
		cs_yin_dao.Serialize(ar);               //阴道          *正常|异常      -填空（异常）
		cs_gong_jing.Serialize(ar);             //宫颈          *光滑|糜烂      *轻|中|重（糜烂）
		cs_fu_ke_jian_cha_zi_gong_da_xiao.Serialize(ar);       //子宫大小              *正常|异常      -填空（异常）
		cs_fu_jian_zuo.Serialize(ar);           //附件（左）      *正常|异常      -填空（异常）
		cs_fu_jian_you.Serialize(ar);           //附件（右）      *正常|异常      -填空（异常）

		nv_date_luo_kuan.Serialize64( ar );
	}
}


void CFemaleInfo::operator=(const CFemaleInfo& fi)
{
	/*《女方信息：》*/
	EN_name=fi.EN_name;				//姓名
	EN_age=fi.EN_age;				//年龄
	EN_occupation =fi.EN_occupation ;			//职业
	EN_knowledge_degree =fi.EN_knowledge_degree ;	//文化程度
	EN_nation =fi.EN_nation ;				//民族
	EN_identity_card =fi.EN_identity_card ;		//身份证号码 
	EN_company =fi.EN_company ;			//单位 
	EN_address =fi.EN_address ;			//通信地址 
	EN_phone =fi.EN_phone ;				//联系电话 
	EN_postalcode =fi.EN_postalcode ;  //邮政编码
	zhen_duan =fi.zhen_duan ;  //诊断	
	zhu_su =fi.zhu_su ;				//主诉 
	xian_bing_shi=fi.xian_bing_shi;			//现病史


	/*《女方信息-既往史》*/
	ji_wang_gan_yan=fi.ji_wang_gan_yan;  //肝炎 *无|有
	jie_he=fi.jie_he;  //结核 *无|有
	shen_zang_ji_bing=fi.shen_zang_ji_bing;  //肾脏疾病 *无|有
	xin_xue_guan_ji_bing=fi.xin_xue_guan_ji_bing;  //心血管疾病 *无|有
	mi_niao_xi_tong_gan_ran=fi.mi_niao_xi_tong_gan_ran;  //泌尿系感染 *无|有
	xing_chuan_bo_ji_bing_shi=fi.xing_chuan_bo_ji_bing_shi; //性传播疾病史 *无|有
	lan_wei_yan=fi.lan_wei_yan;  //阑尾炎 *无|有
	pen_qiang_yan=fi.pen_qiang_yan;  //盆腔炎 *无|有
	
	ji_wang_qi_ta=fi.ji_wang_qi_ta;  //其他  -填空
	/*《女方信息-个人史》*/
	xu_jiu=fi.xu_jiu;  //酗酒 *无|有
	xi_du=fi.xi_du;  //吸毒 *无|有
	zhong_da_jing_shen_ci_ji=fi.zhong_da_jing_shen_ci_ji;  //重大精神刺激史 *无|有
	/*《女方信息-月经史》*/
	chu_chao=fi.chu_chao;  //初潮 -数字
	yue_jing_shi_yue_jing_zhou_qi1=fi.yue_jing_shi_yue_jing_zhou_qi1;  //月经周期 -数字 -数字
	yue_jing_shi_yue_jing_zhou_qi2=fi.yue_jing_shi_yue_jing_zhou_qi2;  //月经周期 -数字 -数字
	mo_ci_yue_jing=fi.mo_ci_yue_jing;  //末次月经 //待定
	jing_liang=fi.jing_liang;  //经量 *正常|多|少
	tong_jing=fi.tong_jing;  //痛经 *有|无
	/*《女方信息-婚育史》*/
	jin_qin_jie_hun=fi.jin_qin_jie_hun;  //近亲结婚 *否|是
	zai_hun=fi.zai_hun;  //再婚 *否|是
	ren_chen=fi.ren_chen;  //妊娠 *否|是
	mo_ci_ren_shen=fi.mo_ci_ren_shen;  //末次妊娠时间 【年月】
	yun=fi.yun;  //孕 //待定
	chan=fi.chan;  //产 //待定
	ren_gong_liu_chan=fi.ren_gong_liu_chan; //人工流产 -数字
	zi_ran_liu_chan=fi.zi_ran_liu_chan; //自然流产 -数字
	yao_liu=fi.yao_liu; //药流 -数字
	yin_chan=fi.yin_chan; //引产 -数字
	zao_chan=fi.zao_chan; //早产 -数字
	gong_wai_yuan_zuo=fi.gong_wai_yuan_zuo; //宫外孕（左） -数字
	gong_wai_yuan_you=fi.gong_wai_yuan_you; //宫外孕（右） -数字
	zu_yue_chan=fi.zu_yue_chan; //足月产 -数字
	xian_you_zi_nv=fi.xian_you_zi_nv; //现有子女 -数字
	/*《女方信息-体格检查》*/
	yi_ban_qing_kuang_T=fi.yi_ban_qing_kuang_T; //一般情况T -数字
	yi_ban_qing_kuang_P=fi.yi_ban_qing_kuang_P; //一般情况P -数字
	yi_ban_qing_kuang_R=fi.yi_ban_qing_kuang_R; //一般情况R -数字
	yi_ban_qing_kuang_BP1=fi.yi_ban_qing_kuang_BP1; //一般情况BP -数字 -数字
    yi_ban_qing_kuang_BP2=fi.yi_ban_qing_kuang_BP2;
	shen_gao=fi.shen_gao; //身高 -数字
	ti_zhong=fi.ti_zhong; //体重 -数字
	/*《女性信息-妇科检查》*/
	gong_jing_qi_ta=fi.gong_jing_qi_ta; //宫颈其他 -填空
	zi_gong=fi.zi_gong; //子宫 *前位|后位|平位
	zhi_di=fi.zhi_di;  //质地 *软|中|硬
	huo_dong_du=fi.huo_dong_du; //活动度 *活动|受限|固定
	ya_tong=fi.ya_tong; //压痛 *无|有
	//qi_ta=fi.qi_ta;  //其他 -填空
	/*《女性信息-.》*/
	xue_chang_gui=fi.xue_chang_gui; //血常规 -填空
	niao_chang_gui=fi.niao_chang_gui; //尿常规 -填空
	/*《女性信息-血型》*/
	xue_xing=fi.xue_xing; //血型 //待定
	Rh_yin_zi=fi.Rh_yin_zi; //Rh因子 //待定
	/*《女性信息-基础内分泌》*/
	EN_FSH=fi.EN_FSH;  //FSH -数字
	EN_E_2=fi.EN_E_2;  //E（下标2） -数字
	EN_P=fi.EN_P;  //P -数字
	EN_LH=fi.EN_LH;  //LH -数字
	EN_PRL=fi.EN_PRL;  //PRL -数字
	EN_T=fi.EN_T;  //T -数字
	/*《女性信息-TORCH》*/
	gong_xing_chong=fi.gong_xing_chong;  //弓形虫 //待定
	ju_xi_bao_bing_du=fi.ju_xi_bao_bing_du;  //巨细胞病毒 //待定
	feng_zhen_bing_du=fi.feng_zhen_bing_du;  //风疹病毒 //待定
	dan_chun_pao_zhen_bing_du_II_xing=fi.dan_chun_pao_zhen_bing_du_II_xing; //单纯疱疹病毒II型 //待定
	/*《女性信息-肝炎 HIV》*/
    EN_HBSAG=fi.EN_HBSAG ;
    EN_HBSAB=fi.EN_HBSAB ;
     EN_HBEAG=fi. EN_HBEAG;

    EN_HBEAB=fi. EN_HBEAB;
    EN_HBCAB=fi.EN_HBCAB;
    EN_HAVI=fi. EN_HAVI;
	
    EN_HCVAb=fi.EN_HCVAb; //HCVAb //待定
	EN_HCVAg=fi.EN_HCVAg; //HCV-Ag //待定
	EN_HIVAb=fi.EN_HIVAb; //HIVAb //待定
	/*《女性信息-不孕四抗体》*/
	kang_zi_gong_nei_mo_kang_ti=fi.kang_zi_gong_nei_mo_kang_ti; //抗子宫内膜抗体//待定
	kang_luan_chao_kang_ti=fi.kang_luan_chao_kang_ti; //抗卵巢抗体 //待定
	kang_tou_ming_dai_kang_ti=fi.kang_tou_ming_dai_kang_ti; //抗透明带抗体 //待定
	kang_jing_zi_kang_ti=fi.kang_jing_zi_kang_ti; //抗精子抗体 //待定
	/*《女性信息-.》*/
	gan_gong=fi.gan_gong;//肝功 //待定
	shen_gong=fi.shen_gong;//肾功 //待定
	ran_se_ti=fi.ran_se_ti;//染色体 //待定
	/*《女性信息-宫颈刮片》*/
	gong_jing_gua_pian=fi.gong_jing_gua_pian;		//宫颈刮片 -填空
	/*《女性信息-宫颈涂片》*/
	zhi_yuan_ti=fi.zhi_yuan_ti; //支原体 //待定
	yi_yuan_ti=fi.yi_yuan_ti; //衣原体 //待定
	di_chong=fi.di_chong; //滴虫  //待定
	mei_jun=fi.mei_jun; //霉菌  //待定
	xian_suo_xi_bao=fi.xian_suo_xi_bao; //线索细胞 //待定
	qing_jie_du=fi.qing_jie_du; //清洁度 
	/*《女性信息-子宫输卵管造影》*/
	zi_gong_xing_tai=fi.zi_gong_xing_tai; //子宫形态 -填空
	zuo_ce_shu_luan_guan=fi.zuo_ce_shu_luan_guan; //左侧输卵管 -填空
	you_ce_shu_luan_guan=fi.you_ce_shu_luan_guan; //右侧输卵管 -填空
	/*《女性信息-妇科B超》*/
	fu_ke_Bchao_ri_qi  = fi.fu_ke_Bchao_ri_qi;
	fu_ke_Bchao_zi_gong_da_xiao=fi.fu_ke_Bchao_zi_gong_da_xiao; //子宫大小 -数字
	fu_ke_Bchao_zi_gong_nei_mo=fi.fu_ke_Bchao_zi_gong_nei_mo; //子宫内膜 -数字 
    fu_ke_B_chao_zi_gong_lei_xing=fi.fu_ke_B_chao_zi_gong_lei_xing;//待定“ABC”
	fu_ke_B_chao_you_ce_luan_chao=fi.fu_ke_B_chao_you_ce_luan_chao; //右侧卵巢 -填空
	fu_ke_B_chao_zuo_ce_luan_chao=fi.fu_ke_B_chao_zuo_ce_luan_chao; //左侧卵巢 -填空
	fu_ke_B_chao_you_ce_luan_chao_Fc=fi.fu_ke_B_chao_you_ce_luan_chao_Fc; //右侧卵巢 -填空
	fu_ke_B_chao_zuo_ce_luan_chao_Fc=fi.fu_ke_B_chao_zuo_ce_luan_chao_Fc; //左侧卵巢 -填空
	/*《女性信息-宫腔镜》*/
	gong_qiang_jing=fi.gong_qiang_jing; //宫腔镜 -填空
	//?????????????///?????????????//待定 “治疗前自然周期排卵监测：”
	/*《女性信息-排卵监测》*/

    nv_pai_luan_jian_ce_ri_qi1 = fi.nv_pai_luan_jian_ce_ri_qi1;
    nv_pai_luan_jian_ce_ri_qi2 = fi.nv_pai_luan_jian_ce_ri_qi2;
    nv_pai_luan_jian_ce_ri_qi3 = fi.nv_pai_luan_jian_ce_ri_qi3;
    nv_pai_luan_jian_ce_ri_qi4 = fi.nv_pai_luan_jian_ce_ri_qi4;
	yue_jing_zhou_qi1=fi.yue_jing_zhou_qi1; //月经周期 //待定
	luan_pao_zhi_jing1=fi.luan_pao_zhi_jing1; //卵泡直径 //待定
	zi_gong_nei_mo1=fi.zi_gong_nei_mo1; //子宫内膜 //待定


    yue_jing_zhou_qi2=fi.yue_jing_zhou_qi2; //月经周期 //待定
    luan_pao_zhi_jing2=fi.luan_pao_zhi_jing2; //卵泡直径 //待定
    zi_gong_nei_mo2=fi.zi_gong_nei_mo2; //子宫内膜 //待定


    yue_jing_zhou_qi3=fi.yue_jing_zhou_qi3; //月经周期 //待定
    luan_pao_zhi_jing3=fi.luan_pao_zhi_jing3; //卵泡直径 //待定
    zi_gong_nei_mo3=fi.zi_gong_nei_mo3; //子宫内膜 //待定


    yue_jing_zhou_qi4=fi.yue_jing_zhou_qi4; //月经周期 //待定
    luan_pao_zhi_jing4=fi.luan_pao_zhi_jing4; //卵泡直径 //待定
    zi_gong_nei_mo4=fi.zi_gong_nei_mo4; //子宫内膜 //待定
	/*《女性信息-病史小结》*/
	bing_shi_xiao_jie=fi.bing_shi_xiao_jie; //病史小结 -填空
	/*《女性信息-诊断》*/
	// =fi.// zhen_duan; //诊断 -填空
	/*《女性信息-诊疗计划》*/
	zheng_liao_ji_hua=fi.zheng_liao_ji_hua; //诊疗计划 -填空
	/*《女性信息-落款》*/
	nv_yi_shi=fi.nv_yi_shi; //医师 -填空

	
	/*《女方信息-既往史》*/
	cs_shou_shu_shi=fi.cs_shou_shu_shi;                  //手术史                *无|有  -填空（有）
	/*《女方信息-个人史》*/
	ci_xi_yan=fi.ci_xi_yan;//吸烟           *无|有  -数字（有）
	cs_yao_wu_guo_min=fi.cs_yao_wu_guo_min;//药物过敏史   *无|有  -填空（有）
	cs_jian_kang_zhuang_kuang = fi.cs_jian_kang_zhuang_kuang; //健康状况（健康）
	cs_chu_sheng_que_xian=fi.cs_chu_sheng_que_xian;//出生缺陷           *无|有  -填空（有）
	/*《女方信息-家族史》*/
	cs_yi_chuan_bing_shi=fi.cs_yi_chuan_bing_shi;     //遗传病史      *无|有  -填空（//待定）
	cs_bu_yun_bu_yu_shi=fi.cs_bu_yun_bu_yu_shi;      //不孕不育史    *无|有  -填空（//待定）
	/*《女方信息-体格检查》*/
	cs_ying_yang=fi.cs_ying_yang;             //营养          *正常|异常      -填空（异常）
	cs_fa_yu=fi.cs_fa_yu;                 //发育          *正常|异常      -填空（异常）
	cs_jing_shen=fi.cs_jing_shen;             //精神          *正常|异常      -填空（异常）
	cs_mao_fa=fi.cs_mao_fa;                //毛发          *正常|异常      -填空（异常）
	cs_pi_fu_nian_mo=fi.cs_pi_fu_nian_mo;         //皮肤粘膜      *正常|异常      -填空（异常）
	cs_lin_ba_jie=fi.cs_lin_ba_jie;            //淋巴结        *正常|异常      -填空（异常）
	cs_ru_fang=fi.cs_ru_fang;               //乳房          *正常|异常      -填空（异常）
	yi_ru=fi.yi_ru;                 //溢乳          *正常|异常      -填空（异常）
	cs_xin=fi.cs_xin;                   //心            *正常|异常      -填空（异常）
	cs_fei=fi.cs_fei;                   //肺            *正常|异常      -填空（异常）
	cs_gan=fi.cs_gan;                   //肝            *正常|异常      -填空（异常）
	cs_pi=fi.cs_pi;                    //脾            *正常|异常      -填空（异常）
	cs_shen=fi.cs_shen;                  //肾            *正常|异常      -填空（异常）
	cs_ji_zhu_si_zhi=fi.cs_ji_zhu_si_zhi;         //脊柱四肢      *正常|异常      -填空（异常）
	/*《女性信息-妇科检查》*/
	cs_wai_yin=fi.cs_wai_yin;               //外阴          *正常|异常      -填空（异常）
	cs_yin_dao=fi.cs_yin_dao;               //阴道          *正常|异常      -填空（异常）
	cs_gong_jing=fi.cs_gong_jing;             //宫颈          *光滑|糜烂      *轻|中|重（糜烂）
	cs_fu_ke_jian_cha_zi_gong_da_xiao=fi.cs_fu_ke_jian_cha_zi_gong_da_xiao;       //子宫大小              *正常|异常      -填空（异常）
	cs_fu_jian_zuo=fi.cs_fu_jian_zuo;           //附件（左）      *正常|异常      -填空（异常）
	cs_fu_jian_you=fi.cs_fu_jian_you;           //附件（右）      *正常|异常      -填空（异常）
    nv_date_luo_kuan = fi.nv_date_luo_kuan; //落款时间
}
// CFemaleInfo 成员函数


