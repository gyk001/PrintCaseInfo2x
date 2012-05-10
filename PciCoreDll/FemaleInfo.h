#pragma once
#include "../GeneralDll/CascadeInt.h"
#include "../GeneralDll/CascadeString.h"
// CFemaleInfo 命令目标

class AFX_EXT_CLASS CFemaleInfo : public CObject
{
protected:
	DECLARE_DYNCREATE(CFemaleInfo)
public:
	CFemaleInfo();
	virtual ~CFemaleInfo();
	virtual void Save2_1(CArchive& ar);
	virtual void Serialize(CArchive& ar,int marjorVersion, int minjorVersion);
	void operator=(const CFemaleInfo& fi);
public:
	/*《女方信息：》*/
	CString EN_name;				//姓名
	int EN_age;				//年龄
	CString EN_occupation ;			//职业
	CString EN_knowledge_degree ;	//文化程度
	CString EN_nation ;				//民族
	CString EN_identity_card ;		//身份证号码 
	CString EN_company ;			//单位 
	CString EN_address ;			//通信地址 
	CString EN_phone ;				//联系电话 
	CString EN_postalcode          ;                       //邮政编码
	CString  zhen_duan               ;                       //诊断	
	CString zhu_su ;				//主诉 
	CString xian_bing_shi;			//现病史
// 
// 	/*《IUI时间：》*/
// 	CString         EN_IUI_time_1;          //1
// 	CString         EN_IUI_time_2;          //2
// 	CString         EN_IUI_time_3;          //3
// 
// 	/*《结局：》*/
// 	CString jie_ju;			//结局


	/*《女方信息-既往史》*/
	CCascadeString          cs_ji_wang_gan_yan;                        //肝炎          *无|有
	CCascadeString          cs_jie_he;                 //结核          *无|有
	CCascadeString          cs_shen_zang_ji_bing;                       //肾脏疾病      *无|有
	CCascadeString          cs_xin_xue_guan_ji_bing;                   //心血管疾病    *无|有
	CCascadeString          cs_mi_niao_xi_tong_gan_ran;                        //泌尿系感染    *无|有
	CCascadeString          cs_xing_chuan_bo_ji_bing_shi;       //性传播疾病史  *无|有
	CCascadeString          cs_lan_wei_yan;                    //阑尾炎                *无|有
	CCascadeString          cs_pen_qiang_yan;                  //盆腔炎                *无|有
	CCascadeString          cs_shou_shu_shi;                   //手术史                *无|有  -填空（有）
	CString                 ji_wang_qi_ta;                  //其他                  -填空

	/*《女方信息-个人史》*/
	CCascadeInt             ci_xi_yan;//吸烟           *无|有  -数字（有）
	CString                 xu_jiu;                 //酗酒          *无|有
	CString                 xi_du;                  //吸毒          *无|有
	CCascadeString          cs_yao_wu_guo_min;//药物过敏史   *无|有  -填空（有）
	CString                 zhong_da_jing_shen_ci_ji;                       //重大精神刺激史        *无|有
	CCascadeString			cs_jian_kang_zhuang_kuang; 
	CCascadeString          cs_chu_sheng_que_xian;//出生缺陷           *无|有  -填空（有）
	/*《女方信息-月经史》*/
	int                     chu_chao;                       //初潮          -数字
	CString                 yue_jing_shi_yue_jing_zhou_qi1;                       //月经周期              -数字   -数字
	CString					yue_jing_shi_yue_jing_zhou_qi2;                       //月经周期              -数字   -数字
	CString                 mo_ci_yue_jing;                 //末次月经              //待定
	CString                 jing_liang;                     //经量          *正常|多|少
	CString                 tong_jing;                      //痛经          *有|无
	/*《女方信息-婚育史》*/
	CString                 jin_qin_jie_hun;                        //近亲结婚              *否|是
	CString                 zai_hun;                        //再婚          *否|是
	CString                 ren_chen;                       //妊娠          *否|是
	CString                 mo_ci_ren_shen;                 //末次妊娠时间  【年月】
	int                 yun;                    //孕            //待定
	int                 chan;                   //产            //待定
	int                     ren_gong_liu_chan;      //人工流产      -数字
	int                     zi_ran_liu_chan;        //自然流产      -数字
	int                     yao_liu;                //药流          -数字
	int                     yin_chan;               //引产          -数字
	int                     zao_chan;               //早产          -数字
	int                     gong_wai_yuan_zuo;      //宫外孕（左）    -数字
	int                     gong_wai_yuan_you;      //宫外孕（右）    -数字
	int                     zu_yue_chan;            //足月产        -数字
	int                     xian_you_zi_nv;         //现有子女      -数字
	/*《女方信息-家族史》*/
	CCascadeString          cs_yi_chuan_bing_shi;      //遗传病史      *无|有  -填空（//待定）
	CCascadeString          cs_bu_yun_bu_yu_shi;       //不孕不育史    *无|有  -填空（//待定）

	/*《女方信息-体格检查》*/
	float                     yi_ban_qing_kuang_T;    //一般情况T     -数字
	int                     yi_ban_qing_kuang_P;    //一般情况P     -数字
	int                     yi_ban_qing_kuang_R;    //一般情况R     -数字
	int                     yi_ban_qing_kuang_BP1;   //一般情况BP    -数字
	int                     yi_ban_qing_kuang_BP2;   //一般情况BP    -数字
	int                     shen_gao;               //身高          -数字
	float                     ti_zhong;               //体重          -数字
	CCascadeString          cs_ying_yang;              //营养          *正常|异常      -填空（异常）
	CCascadeString          cs_fa_yu;                  //发育          *正常|异常      -填空（异常）
	CCascadeString          cs_jing_shen;              //精神          *正常|异常      -填空（异常）
	CCascadeString          cs_mao_fa;                 //毛发          *正常|异常      -填空（异常）
	CCascadeString          cs_pi_fu_nian_mo;          //皮肤粘膜      *正常|异常      -填空（异常）
	CCascadeString          cs_lin_ba_jie;             //淋巴结        *正常|异常      -填空（异常）
	CCascadeString          cs_ru_fang;                //乳房          *正常|异常      -填空（异常）
	CString          yi_ru;                  //溢乳          *正常|异常      -填空（异常）
	CCascadeString          cs_xin;                    //心            *正常|异常      -填空（异常）
	CCascadeString          cs_fei;                    //肺            *正常|异常      -填空（异常）
	CCascadeString          cs_gan;                    //肝            *正常|异常      -填空（异常）
	CCascadeString          cs_pi;                     //脾            *正常|异常      -填空（异常）
	CCascadeString          cs_shen;                   //肾            *正常|异常      -填空（异常）
	CCascadeString          cs_ji_zhu_si_zhi;          //脊柱四肢      *正常|异常      -填空（异常）
	/*《女性信息-妇科检查》*/
	CCascadeString          cs_wai_yin;                //外阴          *正常|异常      -填空（异常）
	CCascadeString          cs_yin_dao;                //阴道          *正常|异常      -填空（异常）
	CCascadeString          cs_gong_jing;              //宫颈          *光滑|糜烂      *轻|中|重（糜烂）
	CString                 gong_jing_qi_ta;     //宫颈其他              -填空
	CString                 zi_gong;                //子宫          *前位|后位|平位
	CCascadeString          cs_fu_ke_jian_cha_zi_gong_da_xiao;        //子宫大小            
	CString                 zhi_di;                 //质地          *软|中|硬
	CString                 huo_dong_du;            //活动度                *活动|受限|固定
	CString                 ya_tong;                //压痛          *无|有
	CCascadeString          cs_fu_jian_zuo;            //附件（左）      *正常|异常      -填空（异常）
	CCascadeString          cs_fu_jian_you;            //附件（右）      *正常|异常      -填空（异常）
	//CString                 qi_ta;                  //其他          -填空
	/*《女性信息-.》*/
	CString         xue_chang_gui;          //血常规                -填空
	CString         niao_chang_gui;         //尿常规                -填空
	/*《女性信息-血型》*/
	CString         xue_xing;               //血型          //待定
	CString         Rh_yin_zi;              //Rh因子        //待定
	/*《女性信息-基础内分泌》*/
	float             EN_FSH;                 //FSH           -数字
	float             EN_E_2;                 //E（下标2）      -数字
	float             EN_P;                   //P             -数字
	float             EN_LH;                  //LH            -数字
	float             EN_PRL;                 //PRL   -数字
	float             EN_T;                   //T             -数字
	/*《女性信息-TORCH》*/
	CString         gong_xing_chong;                        //弓形虫                //待定
	CString         ju_xi_bao_bing_du;                      //巨细胞病毒    //待定
	CString         feng_zhen_bing_du;                      //风疹病毒              //待定
	CString         dan_chun_pao_zhen_bing_du_II_xing;      //单纯疱疹病毒II型       //待定
	/*《女性信息-肝炎 HIV》*/
    CString         EN_HBSAG;
    CString         EN_HBSAB;
    CString         EN_HBEAG;

    CString         EN_HBEAB;
    CString         EN_HBCAB;
    CString         EN_HAVI;

    CString         EN_HCVAb;               //HCVAb         //待定
	CString         EN_HCVAg;              //HCV-Ag        //待定
	CString         EN_HIVAb;               //HIVAb         //待定
	/*《女性信息-不孕四抗》*/
	CString         kang_zi_gong_nei_mo_kang_ti;    //抗子宫内膜抗体//待定
	CString         kang_luan_chao_kang_ti;         //抗卵巢抗体    //待定
	CString         kang_tou_ming_dai_kang_ti;      //抗透明带抗体  //待定
	CString         kang_jing_zi_kang_ti;           //抗精子抗体    //待定
	/*《女性信息-.》*/
	CString gan_gong;//肝功         //待定
	CString shen_gong;//肾功                //待定
	CString ran_se_ti;//染色体              //待定

	/*《女性信息-宫颈刮片》*/
	CString gong_jing_gua_pian;		//宫颈刮片                -填空
	/*《女性信息-宫颈涂片》*/
	CString         zhi_yuan_ti;            //支原体                //待定
	CString         yi_yuan_ti;             //衣原体                //待定
	CString         di_chong;               //滴虫                  //待定
	CString         mei_jun;                //霉菌                  //待定
	CString         xian_suo_xi_bao;        //线索细胞              //待定
	CString         qing_jie_du;            //清洁度                
	/*《女性信息-子宫输卵管造影》*/
	CString          zi_gong_xing_tai;              //子宫形态      -填空
	CString          zuo_ce_shu_luan_guan;          //左侧输卵管    -填空
	CString          you_ce_shu_luan_guan;          //右侧输卵管    -填空
	/*《女性信息-妇科B超》*/
	CString			fu_ke_Bchao_ri_qi;					//妇科B超日期
	CString             fu_ke_Bchao_zi_gong_da_xiao;        //子宫大小              -数字
	float             fu_ke_Bchao_zi_gong_nei_mo;         //子宫内膜              -数字  
    CString     fu_ke_B_chao_zi_gong_lei_xing;      //待定“ABC”
	CString         fu_ke_B_chao_you_ce_luan_chao;       //右侧卵巢              -填空
	CString         fu_ke_B_chao_you_ce_luan_chao_Fc;       //右侧卵巢Fc              -填空
	CString         fu_ke_B_chao_zuo_ce_luan_chao;       //左侧卵巢              -填空
	CString         fu_ke_B_chao_zuo_ce_luan_chao_Fc;       //左侧卵巢Fc              -填空

	/*《女性信息-宫腔镜》*/
	CString         gong_qiang_jing;        //宫腔镜                -填空
	//?????????????//待定    “治疗前自然周期排卵监测：”
	/*《女性信息-//待定》*/

    CString           nv_pai_luan_jian_ce_ri_qi1;
	CString         yue_jing_zhou_qi1;       //月经周期              //待定
	CString         luan_pao_zhi_jing1;      //卵泡直径              //待定
	CString         zi_gong_nei_mo1;         //子宫内膜              //待定

    CString           nv_pai_luan_jian_ce_ri_qi2;
    CString         yue_jing_zhou_qi2;       //月经周期              //待定
    CString         luan_pao_zhi_jing2;      //卵泡直径              //待定
    CString         zi_gong_nei_mo2;         //子宫内膜              //待定


    CString           nv_pai_luan_jian_ce_ri_qi3;
    CString         yue_jing_zhou_qi3;       //月经周期              //待定
    CString         luan_pao_zhi_jing3;      //卵泡直径              //待定
    CString         zi_gong_nei_mo3;         //子宫内膜              //待定


    CString           nv_pai_luan_jian_ce_ri_qi4;
    CString         yue_jing_zhou_qi4;       //月经周期              //待定
    CString         luan_pao_zhi_jing4;      //卵泡直径              //待定
    CString         zi_gong_nei_mo4;         //子宫内膜              //待定
	/*《女性信息-病史小结》*/
	CString         bing_shi_xiao_jie;      //病史小结              -填空
	/*《女性信息-诊断》*/
	//CString         zhen_duan;              //诊断          -填空
	/*《女性信息-诊疗计划》*/
	CString          zheng_liao_ji_hua;     //诊疗计划              -填空
	/*《女性信息-落款》*/
	CString         nv_yi_shi;              //医师          -填空
	//CString         nv_nian_yue_ri;         //年月日                【年月日】
    CTime           nv_date_luo_kuan;
};


