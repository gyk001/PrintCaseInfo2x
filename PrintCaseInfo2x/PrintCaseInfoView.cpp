// PrintCaseInfoView.cpp : 实现文件
//
#include "stdafx.h"
#include "PrintCaseInfo2x.h"
#include "PrintCaseInfoView.h"
#include "PrintCaseInfo2xDoc.h"
#include "PrintInfoEx.h"
#include "DocExportInfo.h"

#define PAGE_LEFT 300
#define PAGE_TOP 200
#define PAGE_RIGHT 200
#define PAGE_BOTTOM 200
#define LINE_HEIGHT 71
#define  MUTI_TEXT_BLANK_WIDTH 150

extern inline CString toStringFomat( int num,CString formater);
extern inline CString toStringFomat( float num,CString formater);
extern inline CString toString(CString str,CString itemName);
extern inline CString toString( CTime time , CString itemName=_T("") ,  bool hasHour = false);

inline CString toString(CString str,CString itemName)
{
    return itemName +_T(":")+ str ;
}





/*
inline CString toStringNotNull( CString str,CString itemName)
{
return (str == _T("")) ? _T("")  : itemName+str;
}
*/
inline CString toStringFomat( int num,CString formater)
{
    CString text;
    text.Format( formater ,num  );
    return text;
}

inline CString toStringFomat( float num,CString formater)
{
    CString text;
    text.Format( formater ,num  );
    return text;
}

inline CString toString( CTime time ,CString itemName ,   bool hasHour )
{
    CString t;
    if ( hasHour )
    {  
        t.Format( _T("%4d年%02d月%02d日%02d时") , time.GetYear() ,time.GetMonth() , time.GetDay() , time.GetHour());
    }
    else
    {
        t.Format( _T("%4d年%02d月%02d日") , time.GetYear() ,time.GetMonth() , time.GetDay() );
    }
    return itemName +t;
}

// CPrintCaseInfoView

IMPLEMENT_DYNCREATE(CPrintCaseInfoView, CScorllCenterFormView)

CPrintCaseInfoView::CPrintCaseInfoView( )
: CScorllCenterFormView(CPrintCaseInfoView::IDD)
{
// 	PHY_LEFT= 0;
// 	PHY_RIGHT = 0;
// 	PHY_TOP = 0;
// 	PHY_BOTTOM = 0;
// 	PAGE_WIDTH=2100;
// 	PAGE_HEIGHT=2970;
}

CPrintCaseInfoView::CPrintCaseInfoView(UINT nIDTemplate )
    : CScorllCenterFormView(nIDTemplate)
{
// 	PHY_LEFT= 0;
// 	PHY_RIGHT = 0;
// 	PHY_TOP = 0;
// 	PHY_BOTTOM = 0;
// 	PAGE_WIDTH=2100;
// 	PAGE_HEIGHT=2970;
}

CPrintCaseInfoView::~CPrintCaseInfoView()
{
}

void CPrintCaseInfoView::DoDataExchange(CDataExchange* pDX)
{
    CScorllCenterFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPrintCaseInfoView, CScorllCenterFormView)
    // 标准打印命令
    ON_COMMAND(ID_FILE_PRINT_DIRECT, &OnFilePrint)
    ON_COMMAND(ID_FILE_PRINT_PREVIEW, &OnFilePrintPreview)
    ON_COMMAND(ID_FILE_PRINT, &OnFilePrint)
    ON_MESSAGE(WM_SAVEFOCUS, OnSaveFocus)
	ON_MESSAGE_BOOL(WM_UPDATE_DOC_FROM_VIEW, OnUpdateDocFromView)
END_MESSAGE_MAP()


// CPrintCaseInfoView 诊断

#ifdef _DEBUG
void CPrintCaseInfoView::AssertValid() const
{
    CScorllCenterFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPrintCaseInfoView::Dump(CDumpContext& dc) const
{
    CScorllCenterFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPrintCaseInfoView 消息处理程序

LRESULT CPrintCaseInfoView::OnSaveFocus(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
    CScorllCenterFormView::SaveFocusControl();
    return (LRESULT)0;
}

// CPrintCaseInfoView 打印
BOOL CPrintCaseInfoView::OnPreparePrinting(CPrintInfo* pInfo)
{
    //更新数据
    UpdateData(TRUE);
    pInfo->SetMaxPage(7);
    //	pInfo->m_bDirect=TRUE;
    return DoPreparePrinting(pInfo);
}

void CPrintCaseInfoView::SetPageMargin(CDC *pDC, CPrintInfo *pInfo, int l, int t, int r, int b)
{
    double scaleX = 254.0 / (double)GetDeviceCaps(pDC->m_hAttribDC, LOGPIXELSX);
    double scaleY = 254.0 / (double)GetDeviceCaps(pDC->m_hAttribDC, LOGPIXELSY);

    int x = GetDeviceCaps(pDC->m_hAttribDC,	PHYSICALOFFSETX); 
    int y = GetDeviceCaps(pDC->m_hAttribDC,	PHYSICALOFFSETY); 
    int w = GetDeviceCaps(pDC->m_hAttribDC,	PHYSICALWIDTH); 
    int h = GetDeviceCaps(pDC->m_hAttribDC,	PHYSICALHEIGHT); 

    int PAGE_WIDTH = (int)((double)w*scaleX);//纸张宽度，单位0.1mm
    int PAGE_HEIGHT= (int)((double)h*scaleY);//纸张高度，单位0.1mm
    int PHY_LEFT = (int)((double)x*scaleY);//物理左边距，单位0.1mm
    int PHY_TOP = (int)((double)y*scaleY);// 物理上边距，单位0.1mm

    CRect rcTemp =pInfo->m_rectDraw;
    //TRACE("RECT-1 %d %d %d %d %d %d\n",rcTemp.left,rcTemp.top,rcTemp.right,rcTemp.bottom,rcTemp.Width(),rcTemp.Height());
    rcTemp.NormalizeRect();
    //TRACE("RECT-2 %d %d %d %d %d %d\n",rcTemp.left,rcTemp.top,rcTemp.right,rcTemp.bottom,rcTemp.Width(),rcTemp.Height());
    int PHY_RIGHT = PAGE_WIDTH - rcTemp.Width() - PHY_LEFT; // 物理右边距，单位0.1mm
    int PHY_BOTTOM= PAGE_HEIGHT - rcTemp.Height() - PHY_TOP; // 物理下边距，单位0.1mm
    if(PHY_RIGHT<0) PHY_RIGHT=0;
    if(PHY_BOTTOM<0) PHY_BOTTOM=0;
    //TRACE("打印机物理边距 左%d 上%d 右%d 下%d \n",PHY_LEFT,PHY_TOP,PHY_RIGHT,PHY_BOTTOM);

    // 若边距小于物理边距，则调整它们
    if (l < PHY_LEFT) l = PHY_LEFT;
    if (t < PHY_TOP) t = PHY_TOP;
    if (r < PHY_RIGHT) r = PHY_RIGHT;
    if (b < PHY_BOTTOM) b = PHY_BOTTOM;

    pInfo->m_rectDraw.left +=(l-PHY_LEFT);
    pInfo->m_rectDraw.top -=(t-PHY_TOP) ;
    pInfo->m_rectDraw.right -=  (r-PHY_RIGHT);
    pInfo->m_rectDraw.bottom += (b-PHY_BOTTOM);

}
void CPrintCaseInfoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* pInfo)
{
    pInfo->m_strPageDesc=_T("病例打印预览 第%u页\n病例打印预览 第%u-%u页\n");
    if ( ! pInfo->m_lpUserData)
    {
        pInfo->m_lpUserData=new CPrintInfoEx(pInfo->m_rectDraw);
    }
}

void CPrintCaseInfoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* pInfo)
{
    //添加打印后进行的清除过程
    if(pInfo->m_lpUserData)
    {
        delete (CPrintInfoEx*)pInfo->m_lpUserData;
        pInfo->m_lpUserData=NULL;
    }
}





// CPrintCaseInfoView 消息处理程序

void CPrintCaseInfoView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
    CScorllCenterFormView::OnPrepareDC(pDC, pInfo);
    pDC->SetMapMode(MM_LOMETRIC);
// 	if(pDC->IsPrinting())//若正在进行打印则判断当前页数据；
// 	{
// 		//pDC->SetWindowOrg(PHY_LEFT,-(PAGE_HEIGHT-PHY_BOTTOM-PHY_TOP)*(pInfo->m_nCurPage-1)-PHY_TOP);
// 
// 	}
}

void CPrintCaseInfoView::PageHeaderFooter(CDC* pDC, CPrintInfo* pInfo, CString nv_fang_xing_ming ,CString bing_li_hao ,CTime time)
{


    CFont *oldFont = pDC->SelectObject(&mainFont);
    // 页眉
    UINT oldTextAlign = pDC->SetTextAlign(TA_CENTER | TA_BOTTOM);

    int mid = (pInfo->m_rectDraw.left + pInfo->m_rectDraw.right) / 2;
    pDC->TextOut(mid, pInfo->m_rectDraw.top , _T("济南市中心医院生殖医学科"));
    pInfo->m_rectDraw.top -=40;
    pDC->MoveTo(pInfo->m_rectDraw.TopLeft());
    pDC->LineTo(pInfo->m_rectDraw.right,pInfo->m_rectDraw.top);
    //  int xh = pInfo->m_rectDraw.top-50;
    pInfo->m_rectDraw.top -=60;   
    pDC->SelectObject(&titleFont);
    pDC->SetTextAlign(TA_CENTER | TA_TOP);
    switch ( pInfo->m_nCurPage )
    {
    case 2:
        pDC->TextOut(mid, pInfo->m_rectDraw.top , _T("人类辅助生殖病历（1）"));
        break;
    case 3:
        pDC->TextOut(mid, pInfo->m_rectDraw.top , _T("人类辅助生殖病历（2）"));
        break;
    case 4:
        pDC->TextOut(mid, pInfo->m_rectDraw.top , _T("人类辅助生殖病历（3）"));
        break;
    case 5:
        pDC->TextOut(mid, pInfo->m_rectDraw.top , _T("人类辅助生殖男方病历（1）"));
        break;
    case 6:
        pDC->TextOut(mid, pInfo->m_rectDraw.top , _T("人类辅助生殖男方病历（2）"));
        break;
    case 7:
        pDC->TextOut(mid, pInfo->m_rectDraw.top , _T("人类辅助生殖病例"));
        break;
    }
    pDC->SetTextAlign(oldTextAlign);
    pDC->SelectObject(&smaleFont);
    CPrintInfoEx* pInfoEx=(CPrintInfoEx*)pInfo->m_lpUserData;
    pInfoEx->setRect( pInfo->m_rectDraw);
    pInfoEx->rc.top +=30;
    pInfoEx->setLeft( pInfo->m_rectDraw.right - 450 );
    pInfoEx->setRectHeight( 60);
    if ( pInfo->m_nCurPage ==2 )
    {
        //pInfoEx->drawBox( pDC );
        PrintText( pDC ,pInfo ,  toString( time , _T("日    期：") ,false ) );
    }
    else
    {
        PrintText( pDC ,pInfo ,  _T("女方姓名：") + nv_fang_xing_ming  );
    }
    pInfoEx->MoveDown();
    pInfoEx->setRectHeight( 60);
    PrintText( pDC ,pInfo ,  _T("病 历 号：") + bing_li_hao );
    pDC->SelectObject(&mainFont);

    //页脚
    CString buf;
    if ( pInfo->m_nCurPage==7 )
    {
        buf = _T( "第1页" );
    } 
    else
    {
        buf.Format(_T("第 %d 页"), pInfo->m_nCurPage-1);
    }

    pDC->SetTextAlign(TA_RIGHT | TA_TOP);
    pDC->TextOut(pInfo->m_rectDraw.right, pInfo->m_rectDraw.bottom - 20, buf);
    pDC->SelectObject(oldFont);
    pDC->SetTextAlign(oldTextAlign);
}

void CPrintCaseInfoView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
    pDC->LineTo(100,100);

    CPrintCaseInfo2xDoc* pDoc =(CPrintCaseInfo2xDoc*) GetDocument();
    if (!pDoc)
    {
        AfxMessageBox(_T("Err!"));
        return;
    }
    CCommonInfo *pCommonInfo =&pDoc->commonInfo;
    CMaleInfo *pMaleInfo=&pDoc->maleInfo;      
    CFemaleInfo *pFemaleInfo=&pDoc->femaleInfo;   
    CPrintInfoEx* pInfoEx=(CPrintInfoEx*)pInfo->m_lpUserData;


    SetPageMargin(pDC,pInfo, PAGE_LEFT, PAGE_TOP, PAGE_RIGHT, PAGE_BOTTOM);
    //标题旁边的信息 -- 五号
    smaleFont.CreatePointFont(105,_T("宋体"),pDC);

    //小标题字体 -- 小四号
    boldFont.CreatePointFont(105,_T("宋体"),pDC);
    LOGFONT lf;
    boldFont.GetLogFont(&lf);
    lf.lfWeight = FW_BOLD;
    boldFont.DeleteObject();
    boldFont.CreateFontIndirect(&lf);
    //正文字体 --  小四
    mainFont.CreatePointFont(102,_T("宋体"),pDC);
    mainFont.GetLogFont(&lf);
    mainFont.DeleteObject();
    mainFont.CreateFontIndirect(&lf);
    mainFont.GetLogFont(&lf);
    TRACE("# %ld #\n",lf.lfHeight);
    //页标题字体 -- 三号字体
    titleFont.CreatePointFont(150,_T("宋体"),pDC);
    titleFont.GetLogFont(&lf);
    lf.lfWeight = FW_BOLD;
    titleFont.DeleteObject();
    titleFont.CreateFontIndirect(&lf);

    CBrush   br;   
    br.CreateStockObject(NULL_BRUSH);
    CBrush*oldBrush = pDC->SelectObject(&br);
    CFont *oldFont = pDC->SelectObject(&mainFont);    
    int oldBkMode = pDC->SetBkMode(TRANSPARENT);   
    COLORREF oldTextColor = pDC->SetTextColor(RGB(0,0,0));
    if(pInfo->m_nCurPage!=1)
    {
        PageHeaderFooter(pDC,pInfo , pFemaleInfo->EN_name , pCommonInfo->bing_li_hao ,pCommonInfo->date_ye_mei);
        pInfo->m_rectDraw.top-=100;
    }
    CString text;
    int tmpX=0; 
    int tmpY=0;

    CFont ft;

    switch (pInfo->m_nCurPage)
    {
    case 1:
        //	pDC->Rectangle(pInfo->m_rectDraw);
        pInfoEx->setRect(pInfo->m_rectDraw);
        pInfoEx->setRectHeight( 5*LINE_HEIGHT);
        ft.CreatePointFont(350 ,_T("宋体"),pDC);
        PrintTextMult2(pDC,pInfo,toString( pCommonInfo->bing_li_hao , _T("编号") ) );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        //pInfoEx->drawBox( pDC );
        ft.DeleteObject();
        ft.CreatePointFont(160 ,_T("宋体"),pDC);
        pDC->SelectObject(&ft);
        PrintText(pDC,pInfo, _T("济南市中心医院生殖医学科") , 0 , 0 , true );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 3*LINE_HEIGHT);
        //pInfoEx->drawBox( pDC );
        ft.DeleteObject();
        ft.CreatePointFont(360 ,_T("宋体"),pDC);
        pDC->SelectObject( &ft);
		//VER_DO:2.2 
        //PrintText(pDC,pInfo, _T("夫精人工授精病历") , 0 , 0 , true );
        PrintText(pDC,pInfo, _T("人类辅助生殖技术病历") , 0 , 0 , true );
        //空一行
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);        

        tmpX = pInfoEx->rc.Width()/2 + pInfo->m_rectDraw.left ;

        //女方姓名 
        pInfoEx->MoveDown();
        pInfoEx->SetRight( tmpX );
        pInfoEx->setRectHeight( 2*LINE_HEIGHT );
        //pInfoEx->drawBox( pDC );
        pDC->SelectObject( &titleFont );
        PrintTextMult2(pDC,pInfo, _T("女方姓名:") , 1 );
        ft.DeleteObject();
        ft.CreatePointFont(160 ,_T("宋体"),pDC);
        pDC->SelectObject( &ft );
        PrintTextMult2(pDC,pInfo, pFemaleInfo->EN_name);
        //男方姓名
        pInfoEx->MoveRight();
        pInfoEx->SetRight(  pInfo->m_rectDraw.right );
        pInfoEx->setRectHeight( 2*LINE_HEIGHT );
        //pInfoEx->drawBox( pDC );
        pDC->SelectObject( &titleFont );
        PrintTextMult2(pDC,pInfo, _T("男方姓名:") , 1 );
        pDC->SelectObject( &ft );
        PrintTextMult2(pDC,pInfo, pMaleInfo->EN_name);
        //女方电话
        pInfoEx->MoveDown();
        pInfoEx->setLeft( pInfo->m_rectDraw.left );
        pInfoEx->SetRight( tmpX );
        pInfoEx->setRectHeight( 2*LINE_HEIGHT );
        //pInfoEx->drawBox( pDC );
        pDC->SelectObject( &titleFont );
        PrintTextMult2(pDC,pInfo, _T("电话:") , 1 );
        pDC->SelectObject( &ft );
        PrintTextMult2(pDC,pInfo, pFemaleInfo->EN_phone);
        //男方电话
        pInfoEx->MoveRight();
        pInfoEx->SetRight(  pInfo->m_rectDraw.right );
        pInfoEx->setRectHeight( 2*LINE_HEIGHT );
        //pInfoEx->drawBox( pDC );
        pDC->SelectObject( &titleFont );
        PrintTextMult2(pDC,pInfo, _T("电话:") , 1 );
        pDC->SelectObject( &ft );
        PrintTextMult2(pDC,pInfo, pMaleInfo->EN_phone);

        //女方单位
        pInfoEx->MoveDown();
        pInfoEx->setLeft( pInfo->m_rectDraw.left );
        pInfoEx->SetRight( tmpX );
        pInfoEx->setRectHeight( 2*LINE_HEIGHT );
        //pInfoEx->drawBox( pDC );
        pDC->SelectObject( &titleFont );
        PrintTextMult2(pDC,pInfo, _T("单位:") , 1 );
        pDC->SelectObject( &ft );
        PrintTextMult2(pDC,pInfo, pFemaleInfo->EN_company);
        //男方单位
        pInfoEx->MoveRight();
        pInfoEx->SetRight(  pInfo->m_rectDraw.right );
        pInfoEx->setRectHeight( 2*LINE_HEIGHT );
        //pInfoEx->drawBox( pDC );
        pDC->SelectObject( &titleFont );
        PrintTextMult2(pDC,pInfo, _T("单位:") , 1 );
        pDC->SelectObject( &ft );
        PrintTextMult2(pDC,pInfo, pMaleInfo->EN_company);
        //通讯地址
        pInfoEx->MoveDown();
        pInfoEx->setLeft( pInfo->m_rectDraw.left );
        pInfoEx->SetRight( pInfo->m_rectDraw.right );
        pInfoEx->setRectHeight( 2*LINE_HEIGHT );
        //pInfoEx->drawBox( pDC );
        pDC->SelectObject( &titleFont );
        PrintTextMult2(pDC,pInfo, _T("通讯地址:")  ,1 );
        pDC->SelectObject( &ft );
        PrintTextMult2(pDC,pInfo, pFemaleInfo->EN_address);
        //通讯地址
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 2*LINE_HEIGHT );
        //pInfoEx->drawBox( pDC );
        pDC->SelectObject( &titleFont );
        PrintTextMult2(pDC,pInfo, _T("邮政编码:")  ,1 );
        pDC->SelectObject( &ft );
        PrintTextMult2(pDC,pInfo, pFemaleInfo->EN_postalcode);
        //诊断
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        //pInfoEx->drawBox( pDC );
        pDC->SelectObject( &titleFont );
        PrintText(pDC,pInfo, _T("诊断:")   );
        pInfoEx->MoveDown();
        pInfoEx->rc.left += MUTI_TEXT_BLANK_WIDTH;
        pInfoEx->rc.right -= MUTI_TEXT_BLANK_WIDTH;
        pInfoEx->setRectHeight( 5*LINE_HEIGHT );
        //	pInfoEx->drawBox( pDC );
        pDC->SelectObject( &ft );
        PrintTextMult2(pDC,pInfo, pFemaleInfo->zhen_duan+_T("\r\n")+pMaleInfo->chu_bu_zhen_duan);
        // 		NewLine( pDC , pInfo );
        // 		PrintTextMult2(pDC,pInfo, pMaleInfo->chu_bu_zhen_duan);
        pInfoEx->SetRight( pInfo->m_rectDraw.right);
        pInfoEx->setLeft( pInfo->m_rectDraw.left);

        //IUI时间：
        pInfoEx->MoveDown();
        pInfoEx->setLeft( pInfo->m_rectDraw.left );
        pInfoEx->SetRight( tmpX );
        pInfoEx->setRectHeight( 2*LINE_HEIGHT );
        //pInfoEx->drawBox( pDC );
        pDC->SelectObject( &titleFont );
        PrintTextMult2(pDC,pInfo, _T("IUI时间:") , 1 );
        //结局
        pInfoEx->MoveRight();
        pInfoEx->SetRight(  pInfo->m_rectDraw.right );
        pInfoEx->setRectHeight( 2*LINE_HEIGHT );
        //pInfoEx->drawBox( pDC );
        pDC->SelectObject( &titleFont );
        PrintTextMult2(pDC,pInfo, _T("结局:") , 1 );
        pDC->SelectObject( &ft );

        break;
    case 2:
        pInfo->m_rectDraw.bottom += 2*LINE_HEIGHT;
        pDC->Rectangle(pInfo->m_rectDraw);

        pInfoEx->setRect(pInfo->m_rectDraw);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        text=_T("女方姓名:")+pFemaleInfo->EN_name;
        pDC->SelectObject( & mainFont );
        PrintText(pDC,pInfo,text,1,16);
        text.Format(_T("年龄:%d"),pFemaleInfo->EN_age);
        PrintText(pDC,pInfo,text,1,8);
        text=_T("职业:")+pFemaleInfo->EN_occupation;
        PrintText(pDC,pInfo,text,1,12);

        text=_T("文化程度:")+pFemaleInfo->EN_knowledge_degree;
        PrintText(pDC,pInfo,text,1,16);
        text=_T("民族:")+pFemaleInfo->EN_nation;
        PrintText(pDC,pInfo,text,1,10);
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        text=_T("身份证号码:")+pFemaleInfo->EN_identity_card;
        PrintText(pDC,pInfo,text);
        //////////////////////////////////////////////////////////////////////////

        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->drawBox(pDC);

        text.Format(_T("丈夫姓名:%s"),pMaleInfo->EN_name);
        PrintText(pDC,pInfo, text, 1 ,16);

        text.Format(_T("年龄:%d"),pMaleInfo->EN_age);
        PrintText(pDC,pInfo,text , 1 , 8 );
        text=_T("职业:")+pMaleInfo->EN_occupation;
        PrintText(pDC,pInfo,text ,1 ,12);
        text=_T("文化程度:")+pMaleInfo->EN_knowledge_degree;
        PrintText(pDC,pInfo,text, 1 , 16);
        text=_T("民族:")+pMaleInfo->EN_nation;
        PrintText(pDC,pInfo,text, 1 ,10);

        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        text=_T("身份证号码:")+pMaleInfo->EN_identity_card;
        PrintText(pDC,pInfo,text);

        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->drawBox(pDC);

        text= _T("通讯地址:")+pFemaleInfo->EN_address;
        PrintText(pDC,pInfo,text, 1 , 42);
        text= _T("联系电话:")+pFemaleInfo->EN_phone;
        PrintText(pDC,pInfo,text);


        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pDC->SelectObject(&boldFont);
        PrintText(pDC,pInfo,_T("主诉："),0);
        text = pFemaleInfo->zhu_su;
        pDC->SelectObject(&mainFont);
        PrintText(pDC,pInfo,text);

        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(6*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight( 6*LINE_HEIGHT);
       
		pDC->SelectObject(&boldFont);
        PrintTextMult2(pDC,pInfo,_T("现病史：") , 0 );
		tmpX = pInfoEx->cur.x;
		pInfoEx->setLeft( pInfoEx->rc.left + 10);
		pInfoEx->SetRight( pInfoEx->rc.right - 10);
		pInfoEx->cur.x =tmpX ;
        pDC->SelectObject(&mainFont);
        PrintTextMult2(pDC,pInfo,pFemaleInfo->xian_bing_shi);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft( pInfo->m_rectDraw.left);
        pInfoEx->setRectHeight(5*LINE_HEIGHT);
        pInfoEx->setRectWidth(2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintTextV(pDC,pInfo,_T("既往史"));
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        NewLine( pDC ,pInfo , true);
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->ji_wang_gan_yan , _T(" 肝炎") ) , 12 );
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->jie_he , _T("结核") ) , 12);
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->shen_zang_ji_bing , _T("肾脏疾病") ) );
        NewLine(pDC,pInfo);
        NewHalfLine( pDC ,pInfo , true);
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->xin_xue_guan_ji_bing , _T(" 心血管疾病") ) ,6);
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->mi_niao_xi_tong_gan_ran, _T("泌尿系统感染") ) , 4 );
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->xing_chuan_bo_ji_bing_shi, _T("性传播疾病史") ) );
        NewLine(pDC,pInfo);
        NewHalfLine( pDC ,pInfo , true);
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->lan_wei_yan , _T(" 阑尾炎") )  , 10);
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->pen_qiang_yan , _T("盆腔炎") ) );
        NewLine(pDC,pInfo);
        NewHalfLine( pDC ,pInfo , true);
        PrintTextMult2(pDC,pInfo, pFemaleInfo->cs_shou_shu_shi.toString(_T(" 手术史")) ,4);
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->ji_wang_qi_ta, _T("其他") ));

        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(4*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        NewLine( pDC ,pInfo , true);
        PrintTextMult2(pDC,pInfo, pFemaleInfo->ci_xi_yan.toString( _T(" 吸烟:%d支/天") , _T(" 吸烟:无") )  , 6);        
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->xu_jiu , _T("酗酒") )  , 12 );
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->xi_du , _T("吸毒") ) );
        NewLine(pDC,pInfo);
        NewHalfLine( pDC ,pInfo , true);
        PrintTextMult2(pDC,pInfo, pFemaleInfo->cs_yao_wu_guo_min.toString(_T(" 药物过敏史")) , 6);
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->zhong_da_jing_shen_ci_ji , _T("重大精神刺激") )  ,4);
        NewLine(pDC,pInfo);
        NewHalfLine( pDC ,pInfo , true);
        PrintTextMult2(pDC,pInfo, pFemaleInfo->cs_chu_sheng_que_xian.toString( _T(" 健康状况") ) ,6);
        PrintTextMult2(pDC,pInfo, pFemaleInfo->cs_chu_sheng_que_xian.toString(_T("出生缺陷")));

        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectWidth(2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintTextV(pDC,pInfo,_T("个人史"));
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();

        pInfoEx->setRectHeight(3*LINE_HEIGHT);
        pInfoEx->setRectWidth(2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintTextV(pDC,pInfo,_T("月经史"));
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        NewLine( pDC ,pInfo , true);
        PrintTextMult2(pDC,pInfo, toStringFomat( pFemaleInfo->chu_chao, _T(" 初潮%d岁") ));
        //月经周期
        text.Format( _T("月经周期: %d 天/%s 天" ) , pFemaleInfo->yue_jing_shi_yue_jing_zhou_qi1 , pFemaleInfo->yue_jing_shi_yue_jing_zhou_qi2);
        PrintTextMult2(pDC,pInfo, text, 6 );
        //末次月经
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->mo_ci_yue_jing ,_T("末次月经" ) ) , 6 );
        NewLine(pDC,pInfo);
        NewHalfLine( pDC ,pInfo , true);
        //经量
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->jing_liang ,_T(" 经量" ) ) , 12 );
        //痛经
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->tong_jing , _T("痛经") ) );

        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(5*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        NewLine( pDC ,pInfo , true);
        //近亲结婚
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->jin_qin_jie_hun , _T(" 近亲结婚")  ) );
        //再婚
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->zai_hun , _T("再婚") ) );    
        //妊娠
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->ren_chen , _T("妊娠")  ) );  
        NewLine(pDC,pInfo);
        NewHalfLine( pDC ,pInfo , true);
        //末次妊娠时间     
        PrintTextMult2(pDC,pInfo, toString( pFemaleInfo->mo_ci_ren_shen ,_T(" 末次妊娠时间" ) ) );
        //孕
        PrintTextMult2(pDC,pInfo, toStringFomat( pFemaleInfo->yun, _T("孕%d次") ) , 6 );    
        //产
        PrintTextMult2(pDC,pInfo, toStringFomat( pFemaleInfo->chan, _T("产%d次") ) , 6 );    
        //人工流产
        PrintTextMult2(pDC,pInfo, toStringFomat( pFemaleInfo->ren_gong_liu_chan, _T("人工流产%d次") ));   
        NewLine(pDC,pInfo);
        NewHalfLine( pDC ,pInfo , true);
        //自然流产
        PrintTextMult2(pDC,pInfo, toStringFomat( pFemaleInfo->zi_ran_liu_chan, _T(" 自然流产%d次") ) , 6 );    
        //药流
        PrintTextMult2(pDC,pInfo, toStringFomat( pFemaleInfo->yao_liu, _T("药流%d次") ) , 6 );    
        //引产
        PrintTextMult2(pDC,pInfo, toStringFomat( pFemaleInfo->yin_chan , _T("引产%d次") ) , 6 );    
        //早产
        PrintTextMult2(pDC,pInfo, toStringFomat( pFemaleInfo->zao_chan, _T("早产%d次") ));    
        NewLine(pDC,pInfo);
        NewHalfLine( pDC ,pInfo , true);
        //宫外孕左
        PrintTextMult2(pDC,pInfo, toStringFomat( pFemaleInfo->gong_wai_yuan_zuo, _T(" 宫外孕左%d次") ) , 6); 
        //宫外孕右
        PrintTextMult2(pDC,pInfo, toStringFomat( pFemaleInfo->gong_wai_yuan_you, _T("宫外孕右%d次") ) , 6 );  
        //足月产
        PrintTextMult2(pDC,pInfo, toStringFomat( pFemaleInfo->zu_yue_chan, _T("足月产%d次") ) , 6 ); 
        //现有子女
        PrintTextMult2(pDC,pInfo, toStringFomat( pFemaleInfo->xian_you_zi_nv, _T("现有子女%d人") ) , 6 ); 
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectWidth(2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintTextV(pDC,pInfo,_T("婚育史"));
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->SetBottom(pInfo->m_rectDraw.bottom);
        pInfoEx->setRectWidth(2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintTextV(pDC,pInfo,_T("家族史"));
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        //遗传病史
        NewLine( pDC ,pInfo , true);
        PrintTextMult2(pDC,pInfo, pFemaleInfo->cs_yi_chuan_bing_shi.toString(_T(" 遗传病史")));  
        NewLine(pDC,pInfo);
        NewHalfLine( pDC ,pInfo , true);
        //不孕不育病史
        PrintTextMult2(pDC,pInfo, pFemaleInfo->cs_bu_yun_bu_yu_shi.toString(_T(" 不孕不育病史")));      
        break;
    case 3:
        pDC->Rectangle(pInfo->m_rectDraw);
        pInfoEx->setRect(pInfo->m_rectDraw);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->setRectHeight(9*LINE_HEIGHT);
        pInfoEx->setRectWidth(2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintTextV(pDC,pInfo,_T("体格检查"));
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        // 		pInfoEx->setRectHeight( LINE_HEIGHT/2 );
        // 		pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        //一般情况T
        PrintText(pDC,pInfo, toStringFomat(pFemaleInfo->yi_ban_qing_kuang_T ,_T(" 一般情况: T %.1f℃")) , 2 , 20 );       
        //一般情况P
        PrintText(pDC,pInfo, toStringFomat(pFemaleInfo->yi_ban_qing_kuang_P ,_T("P %d 次/分")) , 2 , 12 );      
        //一般情况R
        PrintText(pDC,pInfo, toStringFomat(pFemaleInfo->yi_ban_qing_kuang_R ,_T("R %d 次/分")) , 2 , 12 );      
        //一般情况BP
        text.Format( _T("BP %d/%d mmHg"),pFemaleInfo->yi_ban_qing_kuang_BP1,pFemaleInfo->yi_ban_qing_kuang_BP2 );
        PrintText(pDC,pInfo, text);   
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        //身高
        PrintText(pDC,pInfo, toStringFomat(pFemaleInfo->shen_gao ,_T(" 身高: %d cm")) , 0 , 34 );    
        //体重
        PrintText(pDC,pInfo, toStringFomat(pFemaleInfo->ti_zhong ,_T("体重: %.1f kg"))); 
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        //营养
        PrintText(pDC,pInfo, pFemaleInfo->cs_ying_yang.toString(_T(" 营养")) , 0 , 34 );
        //发育
        PrintText(pDC,pInfo, pFemaleInfo->cs_fa_yu.toString(_T("发育")) );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        //精神
        PrintText(pDC,pInfo, pFemaleInfo->cs_jing_shen.toString(_T(" 精神"))  , 0 , 34 );
        //毛发
        PrintText(pDC,pInfo, pFemaleInfo->cs_mao_fa.toString(_T("毛发")));
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        //皮肤黏膜
        PrintText(pDC,pInfo, pFemaleInfo->cs_pi_fu_nian_mo.toString(_T(" 皮肤黏膜")) , 0 , 34 );
        //淋巴结
        PrintText(pDC,pInfo, pFemaleInfo->cs_lin_ba_jie.toString(_T("淋巴结")));
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        //乳房
        PrintText(pDC,pInfo, pFemaleInfo->cs_ru_fang.toString(_T(" 乳房")) , 0 , 34 );
        //溢乳
        PrintText(pDC,pInfo, toString(pFemaleInfo->yi_ru, _T("溢乳") ));
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        //心
        PrintText(pDC,pInfo, pFemaleInfo->cs_xin.toString(_T(" 心")) , 0 , 34 );
        //肺
        PrintText(pDC,pInfo, pFemaleInfo->cs_fei.toString(_T("肺")));
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        //肝
        PrintText(pDC,pInfo, pFemaleInfo->cs_gan.toString(_T(" 肝")) , 0 , 34 );
        //脾
        PrintText(pDC,pInfo, pFemaleInfo->cs_pi.toString(_T("脾")));
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        //肾
        PrintText(pDC,pInfo, pFemaleInfo->cs_shen.toString(_T(" 肾")) , 0 , 34 );
        //脊柱四肢
         PrintText(pDC,pInfo, pFemaleInfo->cs_ji_zhu_si_zhi.toString(_T("脊柱四肢")));

        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(4*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        NewHalfLine( pDC , pInfo , true );
        //外阴
        PrintTextMult2(pDC,pInfo, pFemaleInfo->cs_wai_yin.toString(_T(" 外阴")) , 6 );        
        //阴道
        PrintTextMult2(pDC,pInfo, pFemaleInfo->cs_yin_dao.toString(_T("阴道")));        
        NewLine(pDC,pInfo);
        NewSmallHalfLine( pDC , pInfo , true );
        //宫颈
        if (  pFemaleInfo->cs_gong_jing.strBase == _T( "糜烂"))
        {
            PrintTextMult2(pDC,pInfo, pFemaleInfo->cs_gong_jing.toString(_T(" 宫颈（糜烂）"))  , 6 ); 
        } 
        else
        {
            PrintTextMult2(pDC,pInfo, pFemaleInfo->cs_gong_jing.toString(_T(" 宫颈"))  , 6 ); 
        }
        //宫颈其他
        PrintTextMult2(pDC,pInfo, toString(pFemaleInfo->gong_jing_qi_ta,_T("其他")) );  
        NewLine(pDC,pInfo);
        NewSmallHalfLine( pDC , pInfo , true );
        //子宫
        PrintTextMult2(pDC,pInfo, toString(pFemaleInfo->zi_gong,_T(" 子宫")) , 6 );  
        //子宫大小
        PrintTextMult2(pDC,pInfo, pFemaleInfo->cs_fu_ke_jian_cha_zi_gong_da_xiao.toString(_T("大小"))); 
        NewLine(pDC,pInfo);
        NewSmallHalfLine( pDC , pInfo , true );
        //子宫质地
        PrintTextMult2(pDC,pInfo, toString(pFemaleInfo->zhi_di,_T(" 子宫质地")) , 6 );  
        //子宫活动度
        PrintTextMult2(pDC,pInfo, toString(pFemaleInfo->huo_dong_du,_T("子宫活动度"))  , 6 );  
        //压痛
        PrintTextMult2(pDC,pInfo, toString(pFemaleInfo->ya_tong,_T("压痛")) );
        NewLine(pDC,pInfo);
        NewSmallHalfLine( pDC , pInfo , true );
        //左侧附件
        PrintTextMult2(pDC,pInfo, pFemaleInfo->cs_fu_jian_zuo.toString(_T(" 左侧附件")) , 6); 
        //右侧附件
        PrintTextMult2(pDC,pInfo, pFemaleInfo->cs_fu_jian_you.toString(_T("右侧附件"))); 
        // PCI-V1.2 去掉了【妇科检查】的【其他】项
        // 		NewLine(pDC,pInfo);
        // 		NewSmallHalfLine( pDC , pInfo , true );
        // 		//其他
        // 		PrintTextMult2(pDC,pInfo, toString(pFemaleInfo->qi_ta,_T(" 其他")) );  
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectWidth(2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintTextV(pDC,pInfo,_T("妇科检查"));
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->MoveRight();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->setRectWidth( (pInfo->m_rectDraw.Width() - 142)/2);
        //pInfoEx->drawBox(pDC);
        //血常规
        PrintText(pDC,pInfo,_T("       血常规"),0);
        PrintText(pDC,pInfo, toString(pFemaleInfo->xue_chang_gui,_T("")) );         
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        //尿常规
        PrintText(pDC,pInfo,_T(" 尿常规"),0);
        PrintText(pDC,pInfo, toString(pFemaleInfo->niao_chang_gui,_T("")) );      
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->setRectWidth(3*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        text = _T("血 型");
        PrintText(pDC,pInfo,text,0,0,true);
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        //血型
        PrintText(pDC,pInfo, toString(pFemaleInfo->xue_xing,_T(" 血型")) ,3,10);  
        //Rh因子
        PrintText(pDC,pInfo, toString(pFemaleInfo->Rh_yin_zi,_T("Rh因子")) );  
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        tmpY= pInfoEx->rc.top;
        tmpX=pInfoEx->rc.Width()/3;
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toStringFomat( pFemaleInfo->EN_FSH ,  _T(" FSH %.2f miu/ml") ));
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintTextScript(pDC , pInfo , _T(" E"),_T("2") , false , 0 ) ;
        PrintText(pDC,pInfo,toStringFomat( pFemaleInfo->EN_E_2 ,  _T(" %.2f pg/ml") ));
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toStringFomat( pFemaleInfo->EN_P ,  _T(" P %.2f ng/ml") ));
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left+3*LINE_HEIGHT);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        tmpX=pInfoEx->rc.Width()/3;
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toStringFomat( pFemaleInfo->EN_LH ,  _T(" LH %.2f miu/ml") ));
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toStringFomat( pFemaleInfo->EN_PRL ,  _T(" PRL %.2f ng/ml") ));
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);      
        PrintText(pDC,pInfo,toStringFomat( pFemaleInfo->EN_T ,  _T(" T %.2f ng/ml") ));

        //////////////////////////////////////////////////////////////////////////
        pInfoEx->rc.top = tmpY;
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectWidth(3*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        PrintText(pDC,pInfo,_T("基础"),0,0,true);
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        PrintText(pDC,pInfo,_T("内分泌"),0,0,true);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,_T("TORCH"),0,0,true);
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        tmpX=pInfoEx->rc.Width()/4;
        pInfoEx->setRectWidth(tmpX*2/3);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString( pFemaleInfo->gong_xing_chong , _T("弓形虫")));
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString( pFemaleInfo->ju_xi_bao_bing_du , _T(" 巨细胞病毒")));
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString( pFemaleInfo->feng_zhen_bing_du , _T(" 风疹病毒")));
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);      
        PrintText(pDC,pInfo,toString( pFemaleInfo->dan_chun_pao_zhen_bing_du_II_xing , _T(" 单纯疱疹病毒Ⅱ型")));
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->setLeft(pInfo->m_rectDraw.left+3*LINE_HEIGHT);
        tmpY= pInfoEx->rc.top;
        tmpX=pInfoEx->rc.Width()/3;
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString( pFemaleInfo->EN_HBSAG , _T(" HBsAg")));
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString( pFemaleInfo->EN_HBSAB , _T(" HBsAb")));
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString( pFemaleInfo->EN_HBEAG , _T(" HBeAg")));
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left+3*LINE_HEIGHT);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        tmpX=pInfoEx->rc.Width()/3;
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString( pFemaleInfo->EN_HBEAB , _T(" HBeAb")));
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString( pFemaleInfo->EN_HBCAB , _T(" HBcAb")));
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);      
        PrintText(pDC,pInfo,toString( pFemaleInfo->EN_HAVI , _T(" HAV-I")));
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left+3*LINE_HEIGHT);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        tmpX=pInfoEx->rc.Width()/3;
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString( pFemaleInfo->EN_HCVAb , _T(" HCVAb")));
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString( pFemaleInfo->EN_HCVAg , _T(" HCV-Ag")));
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);      
        PrintText(pDC,pInfo,toString( pFemaleInfo->EN_HIVAb , _T(" HIVAb")));
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->rc.top = tmpY;
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectWidth(3*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        PrintText(pDC,pInfo,_T("肝炎"),0,0,true);
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        PrintText(pDC,pInfo,_T("HIV"),0,0,true);
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectWidth(3*LINE_HEIGHT);
        pInfoEx->setRectHeight(2*LINE_HEIGHT);
        PrintText(pDC,pInfo,_T("不孕四抗") , 0 , 0 , true);
        pInfoEx->drawBox(pDC);
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        PrintText(pDC,pInfo,toString( pFemaleInfo->kang_zi_gong_nei_mo_kang_ti , _T(" 抗子宫内膜抗体"))  , 1, 30 );
        PrintText(pDC,pInfo,toString( pFemaleInfo->kang_luan_chao_kang_ti , _T(" 抗卵巢抗体"))  , 1, 30 );
        pInfoEx->MoveDown();     
        pInfoEx->setRectHeight(LINE_HEIGHT);
		//【抗透明带抗体】改为【抗HCG抗体】
        PrintText(pDC,pInfo,toString( pFemaleInfo->kang_tou_ming_dai_kang_ti , _T(" 抗HCG抗体")) , 1, 30 );
        PrintText(pDC,pInfo,toString( pFemaleInfo->kang_jing_zi_kang_ti , _T(" 抗精子抗体"))  , 1, 30 );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        tmpX=pInfo->m_rectDraw.Width()/3;
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString(pFemaleInfo->gan_gong , _T("    肝功") ) );
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString(pFemaleInfo->shen_gong , _T(" 肾功") ) );
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);    
        PrintText(pDC,pInfo,toString(pFemaleInfo->ran_se_ti , _T(" 染色体") ) );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->setRectWidth(3*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,_T("宫颈刮片"),0,0,true);
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);        
        PrintText(pDC,pInfo,pFemaleInfo->gong_jing_gua_pian);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pDC->SelectObject(&smaleFont);
        PrintText(pDC,pInfo,toString(pFemaleInfo->zhi_yuan_ti , _T(" 支原体") ) ,1 );
        PrintText(pDC,pInfo,toString(pFemaleInfo->yi_yuan_ti , _T("衣原体") ) , 1 );
        PrintText(pDC,pInfo,toString(pFemaleInfo->di_chong , _T("滴虫") )  , 1 );
        PrintText(pDC,pInfo,toString(pFemaleInfo->mei_jun , _T("霉菌") ) , 1  );
        PrintText(pDC,pInfo,toString(pFemaleInfo->xian_suo_xi_bao , _T("线索细胞") )  ,  1 );
       // PrintText(pDC,pInfo,toString(pFemaleInfo->qing_jie_du,_T("清洁度")));
        pDC->SelectObject(&mainFont);
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectWidth(3*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,_T("宫颈涂片"),0,0,true);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        PrintText(pDC,pInfo,_T("子宫输卵管"),0,0,true);
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString(pFemaleInfo->zi_gong_xing_tai, _T(" 子宫形态") ));
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        //左侧输卵管
        PrintText(pDC,pInfo, toString(pFemaleInfo->zuo_ce_shu_luan_guan,_T(" 左侧输卵管") ),0,28);
        //右侧输卵管
        PrintText(pDC,pInfo, toString(pFemaleInfo->you_ce_shu_luan_guan,_T("右侧输卵管") ));
        pInfoEx->MoveLeft();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        PrintText(pDC,pInfo,_T("造影"),0,0,true);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(4*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,_T("妇科B超"),0,0,true);
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        //妇科B超 日期
		PrintText(pDC,pInfo, toString( pFemaleInfo->fu_ke_Bchao_ri_qi, _T(" 日期") ) , 0 , 34 );	
		pInfoEx->MoveDown();
		pInfoEx->setRectHeight( LINE_HEIGHT );
        //妇科B超 子宫大小
        PrintText(pDC,pInfo,  _T(" 子宫大小:")+ pFemaleInfo->fu_ke_Bchao_zi_gong_da_xiao +_T("cm"));
        //妇科B超 子宫内膜
        PrintText(pDC,pInfo, toStringFomat( pFemaleInfo->fu_ke_Bchao_zi_gong_nei_mo , _T("子宫内膜:%.1f cm") ));
        //妇科B超 子宫类型
        PrintText(pDC,pInfo, toString( pFemaleInfo->fu_ke_B_chao_zi_gong_lei_xing , _T("类型") )+_T("型"));
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        //	pInfoEx->SetBottom( pInfo->m_rectDraw.bottom);
        //妇科B超 左侧卵巢
        PrintText(pDC,pInfo, toString( pFemaleInfo->fu_ke_B_chao_zuo_ce_luan_chao , _T(" 左侧卵巢") )+_T(" cm"),0);
        PrintText(pDC,pInfo, _T("，卵泡:")  + pFemaleInfo->fu_ke_B_chao_zuo_ce_luan_chao_Fc);		
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        //妇科B超 右侧卵巢
        PrintText(pDC,pInfo, toString( pFemaleInfo->fu_ke_B_chao_you_ce_luan_chao , _T(" 右侧卵巢") )+_T(" cm"),0);
        PrintText(pDC,pInfo, _T("，卵泡:")  + pFemaleInfo->fu_ke_B_chao_you_ce_luan_chao_Fc);		
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->SetBottom(pInfo->m_rectDraw.bottom);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,pFemaleInfo->gong_qiang_jing);
        pInfoEx->MoveLeft();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,_T("宫  腔  镜"),0,0,true);   
        //////////////////////////////////////////////////////////////////////////*/
        break;
    case 4:
        // pDC->Rectangle(pInfo->m_rectDraw);
        pInfoEx->setRect(pInfo->m_rectDraw);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->setRectHeight(LINE_HEIGHT);
        PrintText(pDC,pInfo,_T("治疗前自然周期排卵监测："));
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->setRectWidth(4*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,_T("日    期"),0,0,true);
        tmpX = (pInfo->m_rectDraw.right-pInfoEx->rc.right)/4;
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo, pFemaleInfo->nv_pai_luan_jian_ce_ri_qi1 ,0,0,true);
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo, pFemaleInfo->nv_pai_luan_jian_ce_ri_qi2 ,0,0,true);
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo, pFemaleInfo->nv_pai_luan_jian_ce_ri_qi3 ,0,0,true);
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,  pFemaleInfo->nv_pai_luan_jian_ce_ri_qi4 ,0,0,true);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->setRectWidth(4*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,_T("月经周期"),0,0,true);
        tmpX = (pInfo->m_rectDraw.right-pInfoEx->rc.right)/4;
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,pFemaleInfo->yue_jing_zhou_qi1,0,0,true);
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,pFemaleInfo->yue_jing_zhou_qi2 , 0 ,0, true );
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,pFemaleInfo->yue_jing_zhou_qi3 , 0 ,0, true );
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,pFemaleInfo->yue_jing_zhou_qi4 , 0 ,0, true );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->setRectWidth(4*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,_T("卵泡直径"),0,0,true);
        tmpX = (pInfo->m_rectDraw.right-pInfoEx->rc.right)/4;
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,pFemaleInfo->luan_pao_zhi_jing1 , 0 ,0, true );
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,pFemaleInfo->luan_pao_zhi_jing2 , 0 , 0,  true );
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,pFemaleInfo->luan_pao_zhi_jing3, 0 ,0, true );
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,pFemaleInfo->luan_pao_zhi_jing4 , 0 ,0, true );     
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->setRectWidth(4*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,_T("子宫内膜"),0,0,true);
        tmpX = (pInfo->m_rectDraw.right-pInfoEx->rc.right)/4;
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,pFemaleInfo->zi_gong_nei_mo1 , 0 ,0, true );
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,pFemaleInfo->zi_gong_nei_mo2 , 0,0 , true );
        pInfoEx->MoveRight();
        pInfoEx->setRectWidth(tmpX);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,pFemaleInfo->zi_gong_nei_mo3 , 0 ,0, true );
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,pFemaleInfo->zi_gong_nei_mo4 , 0  ,0, true );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->setRectHeight(2*LINE_HEIGHT);
        pDC->SelectObject(&titleFont);
        PrintText(pDC,pInfo,_T("病 史 小 结"),0,0,true);
        pDC->SelectObject(&mainFont);
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(9*LINE_HEIGHT);
        pInfoEx->drawBox( pDC );
        pInfoEx->rc.left += MUTI_TEXT_BLANK_WIDTH;
        pInfoEx->rc.right -= MUTI_TEXT_BLANK_WIDTH;
        NewLine( pDC , pInfo , true );
        PrintTextMult2( pDC,pInfo, pFemaleInfo->bing_shi_xiao_jie );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft( pInfo->m_rectDraw.left);
        pInfoEx->SetRight( pInfo->m_rectDraw.right  );
        pInfoEx->setRectHeight(LINE_HEIGHT);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        //pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,_T("诊断") , 1 );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 5* LINE_HEIGHT);
        pInfoEx->rc.left += MUTI_TEXT_BLANK_WIDTH;
        pInfoEx->rc.right -= MUTI_TEXT_BLANK_WIDTH;
        PrintTextMult2( pDC,pInfo, pFemaleInfo->zhen_duan );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft( pInfo->m_rectDraw.left );
        pInfoEx->SetRight( pInfo->m_rectDraw.right );
        pInfoEx->setRectHeight(LINE_HEIGHT);
        //pInfoEx->drawBox(pDC);
        PrintTextMult2( pDC , pInfo , _T("诊疗计划") , 1 );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 5* LINE_HEIGHT);
        pInfoEx->rc.left += MUTI_TEXT_BLANK_WIDTH;
        pInfoEx->rc.right -= MUTI_TEXT_BLANK_WIDTH;
        PrintTextMult2( pDC,pInfo, pFemaleInfo->zheng_liao_ji_hua );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfoEx->rc.left+pInfoEx->rc.Width()*2/3);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        PrintText(pDC,pInfo, toString( pFemaleInfo->nv_yi_shi , _T("医师") ) );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        PrintText(pDC,pInfo,toString(  pFemaleInfo->nv_date_luo_kuan , _T("")  ));  
        //////////////////////////////////////////////////////////////////////////
        break;
    case 5:
        pInfo->m_rectDraw.bottom += 3*LINE_HEIGHT;
        pDC->Rectangle(pInfo->m_rectDraw);
        pInfoEx->setRect(pInfo->m_rectDraw);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        text=_T("男方姓名:")+pMaleInfo->EN_name;
        PrintText(pDC,pInfo,text, 1,16);
        text.Format(_T("年龄:%d"),pMaleInfo->EN_age);
        PrintText(pDC,pInfo,text, 1,10);
        text=_T("职业:")+pMaleInfo->EN_occupation;
        PrintText(pDC,pInfo,text, 1,12);
        text=_T("文化程度:")+pMaleInfo->EN_knowledge_degree;
        PrintText(pDC,pInfo,text, 1 ,18);
        text=_T("民族:")+pMaleInfo->EN_nation;
        PrintText(pDC,pInfo,text, 1 ,10);
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        text=_T("通讯地址：")+pMaleInfo->EN_address ;
        PrintText( pDC,pInfo,text, 1,40);    
        text=_T("联系电话：")+pMaleInfo->EN_phone ;
        PrintText(pDC,pInfo,text);    
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,toString( pMaleInfo->date_chu_zhen , _T("初诊时间：") ));    
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pDC->SelectObject(&boldFont);
        PrintText(pDC,pInfo,_T("主诉：") , 1 );
        pDC->SelectObject(&mainFont);
        PrintText(pDC , pInfo , pMaleInfo->zhu_su );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
		pInfoEx->MoveDown();
		pInfoEx->setRectHeight(4*LINE_HEIGHT);
		pInfoEx->drawBox(pDC);
		pInfoEx->setRectHeight( 4*LINE_HEIGHT);
		pDC->SelectObject(&boldFont);
		PrintTextMult2(pDC,pInfo,_T("现病史：") , 0 );
		tmpX = pInfoEx->cur.x;
		pInfoEx->setLeft( pInfoEx->rc.left + 10);
		pInfoEx->SetRight( pInfoEx->rc.right - 10);
		pInfoEx->cur.x =tmpX ;
		pDC->SelectObject(&mainFont);
        PrintTextMult2(pDC,pInfo,pMaleInfo->xian_bing_shi);
        pInfoEx->SetRight( pInfo->m_rectDraw.right );
        pInfoEx->setLeft( pInfo->m_rectDraw.left );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 6*LINE_HEIGHT);
        pInfoEx->setRectWidth(2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintTextV(pDC,pInfo,_T("既往病史"));
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight( LINE_HEIGHT );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        PrintText(pDC,pInfo, toString( pMaleInfo->ji_wang_gan_yan , _T(" 肝炎") ) , 0,34 );
        PrintText(pDC,pInfo, toString( pMaleInfo->jie_he , _T("结核") ) );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        PrintText(pDC,pInfo, toString( pMaleInfo->xin_xue_guan, _T(" 心血管疾病")) , 0,34 );
        PrintText(pDC,pInfo, toString( pMaleInfo->xing_chuan_bo, _T("性传播疾病史") ) );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        PrintText(pDC,pInfo, pMaleInfo->cs_mi_niao_sheng_zhi.toString( _T(" 泌尿生殖病史") ) , 0,34 );
        PrintText(pDC,pInfo, toString( pMaleInfo->ji_wang_bing_shi_qi_ta ,_T( " 其他" ) ) );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 2*LINE_HEIGHT );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectHeight( 8*LINE_HEIGHT);
        pInfoEx->setRectWidth(2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintTextV(pDC,pInfo,_T("个人史"));
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight( LINE_HEIGHT );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        PrintText(pDC,pInfo, pMaleInfo->ci_xi_yan.toString( _T(" 吸烟:%d支/天") ,_T(" 吸烟:无") ) );  
        PrintText( pDC , pInfo , toString( pMaleInfo->xu_jiu , _T( "酗酒" ) ) );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        PrintText(pDC,pInfo, pMaleInfo->cs_yao_wu_guo_min.toString( _T(" 药物过敏史") ) );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        PrintText( pDC , pInfo , toString( pMaleInfo->zhong_da_jing_sheng_ci_ji , _T( " 重大精神刺激史" ) ) );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        PrintText (pDC , pInfo , toString( pMaleInfo->jian_kang_zhuang_kuang_guo_qu , _T( " 健康状况：过去" ) ) );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        PrintText( pDC , pInfo , toString( pMaleInfo->jian_kang_zhuang_kuang_xian_zai , _T( "           现在" ) ) );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );    
        PrintText( pDC , pInfo , pMaleInfo->cs_chu_sheng_que_xian .toString(  _T( " 出生缺陷" ) ) );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );    
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectHeight(2*LINE_HEIGHT);
        pInfoEx->setRectWidth(2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pDC->SelectObject(&boldFont);
        PrintTextV(pDC , pInfo , _T("婚姻史") );
        pDC->SelectObject(&mainFont);
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo, toString( pMaleInfo->jin_qin_jie_hun, _T(" 近亲结婚") )  , 1, 20 );
        PrintText(pDC,pInfo, toString( pMaleInfo->zai_hun, _T("再婚") )  );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->setRectHeight(4*LINE_HEIGHT);
        pInfoEx->setRectWidth(2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pDC->SelectObject(&boldFont);
        PrintTextV(pDC , pInfo , _T("家族史") );
        pDC->SelectObject(&mainFont);
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        pDC->SelectObject(&mainFont);
        pInfoEx->setRectHeight( LINE_HEIGHT);
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        PrintText( pDC , pInfo , pMaleInfo->cs_yi_chuan_bing_shi .toString(  _T( " 遗传病史" ) ) );  
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        PrintText(pDC,pInfo, pFemaleInfo->cs_bu_yun_bu_yu_shi.toString(_T(" 不孕不育病史")));
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->SetBottom( pInfo->m_rectDraw.bottom );
        pInfoEx->setRectWidth(4*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pDC->SelectObject(&boldFont);
        PrintText(pDC , pInfo , _T("一般体格检查") , 0 ,0 , true);
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        pDC->SelectObject(&mainFont);
        PrintText(pDC,pInfo, toStringFomat( pMaleInfo->shen_gao , _T(" 身高:%d cm") ) );     
        PrintText(pDC,pInfo, toStringFomat(pMaleInfo->ti_zhong ,_T("体重: %.1f Kg")));       
        text.Format(  _T("血压:%d/%d mmHg" ) , pMaleInfo->xue_ya1, pMaleInfo->xue_ya2);
        PrintText(pDC,pInfo, text);     
        //TODO
        //////////////////////////////////////////////////////////////////////////
        break;
    case 6:
        pDC->Rectangle(pInfo->m_rectDraw);
        pInfoEx->setRect(pInfo->m_rectDraw);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->setRectHeight(3*LINE_HEIGHT);
        pInfoEx->setRectWidth(4*LINE_HEIGHT);        
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , _T("第二性征") , 0 , 0,true);        
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight( LINE_HEIGHT );
        PrintText(pDC,pInfo, toString( pMaleInfo->hu_xu , _T(" 胡须") ) , 0, 20 ); 
        PrintText(pDC,pInfo, toString( pMaleInfo->hou_jie , _T("喉结") ) ); 
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        PrintTextMult2(pDC,pInfo,  pMaleInfo->cs_ru_fang.toString( _T(" 乳房") ) ); 
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft( pInfo->m_rectDraw.left);
        pInfoEx->setRectWidth(4*LINE_HEIGHT);
        pInfoEx->setRectHeight( 9*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , _T("生殖系统检查") , 0 , 0,true);       
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight( LINE_HEIGHT);
        PrintText(pDC,pInfo,  pMaleInfo->cs_yin_jing.toString( _T(" 阴茎") ) , 0  ,28 ); 
        PrintText(pDC,pInfo, toString( pMaleInfo->yin_mao , _T("阴毛") ) ); 
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight( LINE_HEIGHT);
        PrintText(pDC,pInfo, toStringFomat( pMaleInfo->gao_wan_ti_ji_zuo , _T(" 睾丸：体积 左 %d ml") ) );
        PrintText(pDC,pInfo, toStringFomat( pMaleInfo->gao_wan_ti_ji_zuo , _T("右 %d ml") ) ); 
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        PrintText(pDC,pInfo,  pMaleInfo->cs_gao_wan_zhi_di_zuo.toString( _T("       质地 左") ) ); 
        PrintText(pDC,pInfo,  pMaleInfo->cs_gao_wan_zhi_di_you.toString( _T("右") ) ); 

        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo,  pMaleInfo->cs_fu_gao_zuo.toString( _T(" 附睾: 左") ) ); 
        PrintText(pDC,pInfo,  pMaleInfo->cs_fu_gao_you.toString( _T("右") ) ); 
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight( LINE_HEIGHT);
        PrintText(pDC,pInfo,  pMaleInfo->cs_shu_jing_guan_zuo.toString( _T(" 输精管：左") ) ); 
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        PrintText(pDC,pInfo,  pMaleInfo->cs_shu_jing_guan_you.toString( _T("         右") ) ); 

        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight( LINE_HEIGHT);
        PrintText(pDC,pInfo,  pMaleInfo->cs_jing_suo_jing_mai_zuo.toString( _T(" 精索静脉：左") ) ); 
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        PrintText(pDC,pInfo,  pMaleInfo->cs_jing_suo_jing_mai_you.toString( _T("           右") ) ); 

        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        PrintText(pDC,pInfo,  toString( pMaleInfo->sheng_zhi_qi_ta , _T(" 其它") ) );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setLeft( pInfo->m_rectDraw.left);
        pInfoEx->setRectWidth(4*LINE_HEIGHT);
        pInfoEx->setRectHeight( 5*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , _T("精液常规分析") , 0 , 0,true);       
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        tmpX = pInfoEx->rc.left;
        tmpY = pInfoEx->rc.Width()/2;
        pInfoEx->setRectHeight( LINE_HEIGHT);
        pInfoEx->setRectWidth(pInfoEx->rc.Width()/2);
        pInfoEx->drawBox( pDC );
        PrintText(pDC,pInfo, toString(  pMaleInfo->date_jing_ye_fen_xi , _T(" 日期：") ) );
        pInfoEx->MoveRight();
        pInfoEx->SetRight( pInfo->m_rectDraw.right );
        pInfoEx->drawBox( pDC );
        PrintText(pDC,pInfo, toStringFomat( pMaleInfo->jin_yu_tian_shu , _T(" 禁欲 %d 天") ) ); 
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        pInfoEx->drawBox( pDC );
        PrintText(pDC,pInfo, toStringFomat( pMaleInfo->EN_PH , _T(" PH %.1f") ) ); 
        pInfoEx->MoveLeft();
        pInfoEx->setLeft( tmpX );
        pInfoEx->drawBox( pDC );
        PrintText(pDC,pInfo, toStringFomat( pMaleInfo->jing_ye_liang , _T(" 精液量 %.1f ml") ) ); 
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        pInfoEx->drawBox( pDC );
        PrintText(pDC,pInfo, toStringFomat( pMaleInfo->ye_hua_shi_jian , _T(" 液化时间 %d min") ) ); 
        pInfoEx->MoveRight();
        pInfoEx->SetRight( pInfo->m_rectDraw.right );
        pInfoEx->drawBox( pDC );
        PrintText(pDC,pInfo, toStringFomat( pMaleInfo->mi_du , _T(" 密度 %.2f ×") ) , 0 , 0 );
        PrintTextScript( pDC ,pInfo , _T("10") , _T("6") ,true , 0 );
        PrintText( pDC ,pInfo , _T("/ml") );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        pInfoEx->setLeft( tmpX );
        pInfoEx->drawBox( pDC );
        PrintText(pDC,pInfo, toStringFomat( pMaleInfo->huo_li_A_ji , _T(" 活动力 A级:%.2f %%") ) ,1  );
        PrintText(pDC,pInfo, toStringFomat( pMaleInfo->huo_li_B_ji , _T("  B级:%.2f %%") ) , 1 );
        PrintText(pDC,pInfo, toStringFomat( pMaleInfo->huo_li_C_ji , _T("  C级:%.2f %%") ) , 1 );
        PrintText(pDC,pInfo, toStringFomat( pMaleInfo->huo_li_D_ji , _T("  D级:%.2f %%") ), 1 );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        pInfoEx->setRectWidth(pInfoEx->rc.Width()/2);
        pInfoEx->drawBox( pDC );
        PrintText(pDC,pInfo, toStringFomat( pMaleInfo->zheng_chang_xing_tai_lv , _T(" 正常形态率 %d %%") ) );
        pInfoEx->MoveRight();
        pInfoEx->SetRight( pInfo->m_rectDraw.right );
        pInfoEx->drawBox( pDC );
        PrintText(pDC,pInfo, toString( pMaleInfo->bai_xi_bao , _T(" 白细胞") ) +_T(" HP"));

        //////////////////////////////////////////////////////////////////////////
        pInfoEx->setLeft( tmpX );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC,pInfo, toString(pMaleInfo->xue_xing,_T(" 血型")) ,3,10);  
        PrintText(pDC,pInfo, toString(pMaleInfo->Rh_yin_zi,_T("Rh因子")) );  
        pInfoEx->MoveLeft();
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , _T("血  型") , 0 , 0,true);  
        //////////////////////////////////////////////////////////////////////////
		  pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , _T("微生物检查") , 0 , 0,true);  
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight( LINE_HEIGHT );
        pInfoEx->setRectWidth( pInfoEx->rc.Width()/2 );
        pInfoEx->drawBox( pDC );
		PrintText(pDC , pInfo ,  toString( pMaleInfo->zhi_yuan_ti , _T(" 支原体") ) );  
        pInfoEx->MoveRight();
        pInfoEx->SetRight( pInfo->m_rectDraw.right );

        PrintText(pDC , pInfo ,  toString( pMaleInfo->zhi_yuan_ti , _T(" 支原体") ) );  
		PrintText(pDC , pInfo ,  toString( pMaleInfo->yi_yuan_ti , _T(" 衣原体") ) );  
        /*
		pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        pInfoEx->drawBox( pDC );
        pInfoEx->MoveLeft();
        pInfoEx->setLeft( tmpX );
        pInfoEx->drawBox( pDC );
        PrintText(pDC , pInfo ,  toString( pMaleInfo->yi_yuan_ti , _T(" 衣原体") ) );  
		*/
      
/*   
		pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , _T("微生物检查") , 0 , 0,true);  
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight( LINE_HEIGHT );
        pInfoEx->setRectWidth( pInfoEx->rc.Width()/2 );
        pInfoEx->drawBox( pDC );
        PrintText(pDC , pInfo ,  toString( pMaleInfo->lin_qiu_jun , _T(" 淋球菌") ) );  
        pInfoEx->MoveRight();
        pInfoEx->SetRight( pInfo->m_rectDraw.right );

        PrintText(pDC , pInfo ,  toString( pMaleInfo->zhi_yuan_ti , _T(" 支原体") ) );  
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        pInfoEx->drawBox( pDC );
        pInfoEx->MoveLeft();
        pInfoEx->setLeft( tmpX );
        pInfoEx->drawBox( pDC );
        PrintText(pDC , pInfo ,  toString( pMaleInfo->yi_yuan_ti , _T(" 衣原体") ) );  
*/      
		//////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo ,  pMaleInfo->gan_yan );
        pInfoEx->MoveRight();
        pInfoEx->SetRight( pInfo->m_rectDraw.right );
        PrintText(pDC , pInfo ,  toString( pMaleInfo->EN_HIV , _T(" HIV") ) );  
        pInfoEx->setLeft(pInfo->m_rectDraw.left);
        pInfoEx->SetRight( tmpX );
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , _T("肝  炎") , 0 , 0,true);  
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , _T("生殖激素") , 0 , 0,true);  
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->setRectWidth( pInfoEx->rc.Width() /2);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , pMaleInfo->sheng_zhi_ji_su);  
        pInfoEx->MoveRight();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo ,   toString( pMaleInfo->yi_chuan_xue_jian_cha , _T("遗传学检查") )); 
        //todo
        ///////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->SetRight(pInfo->m_rectDraw.right);
        pInfoEx->setLeft( pInfo->m_rectDraw.left);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        PrintText(pDC , pInfo , _T("初步诊断:") );
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 9*LINE_HEIGHT);
        pInfoEx->rc.left += MUTI_TEXT_BLANK_WIDTH;
        pInfoEx->rc.right -= MUTI_TEXT_BLANK_WIDTH;

        PrintTextMult2(pDC,pInfo, pMaleInfo->chu_bu_zhen_duan);
        //////////////////////////////////////////////////////////////////////////

        pInfoEx->MoveDown();
        pInfoEx->setLeft(pInfoEx->rc.left+pInfoEx->rc.Width()*2/3);
        pInfoEx->setRectHeight(LINE_HEIGHT);
        PrintText(pDC,pInfo,  toString( pMaleInfo->nan_yi_shi  ,  _T("医师") ) );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(LINE_HEIGHT);
        PrintText(pDC,pInfo,toString( pMaleInfo->date_luo_kuan , _T("") ));  
        break;
    case 7:
        //pDC->Rectangle(pInfo->m_rectDraw);
        pInfoEx->setRect(pInfo->m_rectDraw);
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->setRectHeight( LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo ,toString( pCommonInfo->date_shou_ci_bing_cheng_ji_lu , _T("") , true ) );    
        pInfoEx->resetCur();
        pDC->SelectObject( &boldFont);
        PrintText(pDC , pInfo , _T("首次病程记录") , 0 , 0,true);        
        pDC->SelectObject( &mainFont );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 6* LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight(  LINE_HEIGHT);
        PrintText(pDC , pInfo , _T("病例特点") , 1); 
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 5* LINE_HEIGHT);
        pInfoEx->rc.left += MUTI_TEXT_BLANK_WIDTH;
        pInfoEx->rc.right -= MUTI_TEXT_BLANK_WIDTH;
        PrintTextMult2( pDC,  pInfo , pCommonInfo->bing_li_te_dian );
        pInfoEx->SetRight( pInfo->m_rectDraw.right );
        pInfoEx->setLeft( pInfo->m_rectDraw.left );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 6* LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight(  LINE_HEIGHT);
        PrintText(pDC , pInfo , _T("初步诊断") , 1); 
        pInfoEx->MoveDown();
        pInfoEx->rc.left += MUTI_TEXT_BLANK_WIDTH;
        pInfoEx->rc.right -= MUTI_TEXT_BLANK_WIDTH;
        pInfoEx->setRectHeight( 5* LINE_HEIGHT);
        PrintTextMult2(pDC,pInfo, pFemaleInfo->zhen_duan+_T("\r\n")+pMaleInfo->chu_bu_zhen_duan);
        pInfoEx->setLeft( pInfo->m_rectDraw.left );

        pInfoEx->SetRight( pInfo->m_rectDraw.right );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(  2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , _T("诊疗计划"  ) );       
        NewLine( pDC , pInfo );
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(  2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , toString( pCommonInfo->ni_xing_AIH_fang_shi , _T("1、拟行AIH的方式")  ) );
		//////////////////////////////////////////////////////////////////////////
/*       TODODO
		pInfoEx->MoveDown();
        pInfoEx->setRectHeight(  2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , toString( pCommonInfo->fu_he_AIH_zhi_zheng , _T("2、符合AIH的指征")  ) ); 
		*/
		//计算行数
		CString a = pCommonInfo->fu_he_AIH_zhi_zheng;
		a = a.Trim();
		int index = 0;
		int lcount = 1;
		do{
			index = a.Find(_T("\n"),index+1);
			lcount ++;
		}while( index !=-1 );


		pInfoEx->MoveDown();
        pInfoEx->setRectHeight( lcount*36 );
        pInfoEx->drawBox(pDC);
        pInfoEx->setRectHeight( lcount*36 );
		pInfoEx->SetTop(pInfoEx->cur.y -= 10);

        PrintTextMult2(pDC,pInfo,_T("2、符合AIH的指征：") , 0 );
		tmpX = pInfoEx->cur.x;
		pInfoEx->setLeft( pInfoEx->rc.left + 10);
		pInfoEx->SetRight( pInfoEx->rc.right - 10);
		pInfoEx->cur.x =tmpX ;
        PrintTextMult2(pDC,pInfo, pCommonInfo->fu_he_AIH_zhi_zheng );

        pInfoEx->setLeft( pInfo->m_rectDraw.left);
		pInfoEx->SetRight( pInfo->m_rectDraw.right);

/*
		pInfoEx->MoveDown();
        pInfoEx->setRectHeight(  lcount*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , toString( pCommonInfo->fu_he_AIH_zhi_zheng , _T("2、符合AIH的指征")  ) ); 
*/

		
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(  2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , toString( pCommonInfo->jin_ji_zheng , _T("3、禁忌症")  ) );   
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(2*  LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , toString( pCommonInfo->ni_xing_zhi_liao_fang_an , _T("4、拟行治疗方案")  ) );  
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(  2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , toString( pCommonInfo->fu_zhu_jian_cha_yi_chang_jie_guo , _T("5、辅助检查异常结果")  ) );  
        //////////////////////////////////////////////////////////////////////////
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight(  2*LINE_HEIGHT);
        pInfoEx->drawBox(pDC);
        PrintText(pDC , pInfo , toString( pCommonInfo->bing_cheng_ji_lu_qi_ta , _T("6、其他")  ) );    
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( 2*LINE_HEIGHT );
        pInfoEx->drawBox( pDC ); 
        pInfoEx->MoveDown();
        pInfoEx->setRectHeight( LINE_HEIGHT );
        pInfoEx->cur.x = pInfoEx->rc.right - 400;
        PrintText(pDC , pInfo , toString( pCommonInfo->bing_cheng_ji_lu_yi_shi , _T("医师")  ) );
    }

    pDC->SelectObject(oldBrush);
    pDC->SelectObject(oldFont);
    pDC->SetBkMode(oldBkMode);
    pDC->SetTextColor(oldTextColor);
    titleFont.DeleteObject();
    mainFont.DeleteObject();
    boldFont.DeleteObject();
    smaleFont.DeleteObject();
}



//单行字符
void CPrintCaseInfoView::PrintText(CDC* pDC, CPrintInfo* pInfo,CString text , int blankNum ,int minWord,bool center)
{
    CPrintInfoEx* pInfoEx=(CPrintInfoEx*)pInfo->m_lpUserData; 
    TEXTMETRIC tm;
    pDC->GetTextMetrics (&tm);
    int fontWidht = tm.tmAveCharWidth;
    int textWidth = max(pDC->GetTextExtent(text).cx,minWord*fontWidht);
// 	int textHeitht = tm.tmHeight+tm.tmExternalLeading;
    UINT f = DT_VCENTER|DT_SINGLELINE;
    if (center)
    {
        f |= DT_CENTER;
    }
    else
    {
        f |= DT_LEFT;
    }
    pDC->DrawText(text,CRect(pInfoEx->cur,pInfoEx->rc.BottomRight()),f);
    pInfoEx->cur.x +=textWidth+blankNum*fontWidht;
}

void CPrintCaseInfoView::PrintTextScript(CDC* pDC, CPrintInfo* pInfo,CString text , CString scriptText ,bool superscript, int blankNum ,bool vCenter )
{
    CPrintInfoEx* pInfoEx=(CPrintInfoEx*)pInfo->m_lpUserData; 
    TEXTMETRIC tm;
    pDC->GetTextMetrics (&tm);
    int fontWidht = tm.tmAveCharWidth;
    int textWidth = pDC->GetTextExtent(text).cx;
//	int textHeitht = tm.tmHeight+tm.tmExternalLeading;
    UINT f =DT_LEFT ;
    if (vCenter)
    {
        f = DT_VCENTER |DT_SINGLELINE;
    }
    pDC->DrawText(text,CRect(pInfoEx->cur,pInfoEx->rc.BottomRight()) , f);
    pInfoEx->cur.x +=textWidth;

    CFont scriptFont;
    scriptFont.CreatePointFont(80 ,_T("宋体"),pDC);

    UINT oldTextAlign ;
    CFont *pOldFont = pDC->SelectObject(&scriptFont);
    pDC->GetTextMetrics (&tm);
    fontWidht = tm.tmAveCharWidth;
    textWidth =  pDC->GetTextExtent(scriptText).cx ;
    if ( superscript )
    {
        oldTextAlign = pDC->SetTextAlign( TA_LEFT| TA_TOP);
        pDC->TextOut( pInfoEx->cur.x ,pInfoEx->cur.y ,  scriptText );
    } 
    else
    {
        oldTextAlign = pDC->SetTextAlign( TA_LEFT| TA_BOTTOM);
        pDC->TextOut( pInfoEx->cur.x , pInfoEx->rc.bottom +8,  scriptText );
    }

    pInfoEx->cur.x +=textWidth+blankNum*fontWidht;
    pDC->SelectObject(pOldFont);
    pDC->SetTextAlign( oldTextAlign);
}

void CPrintCaseInfoView::PrintTextMult2(CDC* pDC, CPrintInfo* pInfo,CString text ,int blankNum )
{
    if (text == _T(""))
    {
        return;
    }
    CPrintInfoEx* pInfoEx=(CPrintInfoEx*)pInfo->m_lpUserData; 
    TEXTMETRIC tm;
    pDC->GetTextMetrics (&tm);
    int fontWidht = tm.tmAveCharWidth;
    CString blankStr;
    for ( int i=0 ; i< ( pInfoEx->cur.x-pInfoEx->rc.left)/tm.tmAveCharWidth ; i++)
    {
        blankStr +=_T(" ");
    }
    text = blankStr + text ;
    int textWidth = pDC->GetTextExtent(text).cx;
    int textHeitht = tm.tmHeight+tm.tmExternalLeading;
    if ( textWidth < abs(pInfoEx->rc.Width()) )
    {
        pDC->DrawText( text , CRect( pInfoEx->rc.left, pInfoEx->cur.y,  pInfoEx->rc.right , pInfoEx->rc.bottom ) , DT_LEFT|DT_WORDBREAK);
        pInfoEx->cur.x = pInfoEx->rc.left + textWidth ;
    } 
    else
    {   
        int drawHeight = pDC->DrawText(text,CRect( pInfoEx->rc.left, pInfoEx->cur.y,  pInfoEx->rc.right , pInfoEx->rc.bottom ),DT_LEFT|DT_WORDBREAK);
        pInfoEx->cur.x = pInfoEx->rc.left + textWidth % pInfoEx->rc.Width();
        pInfoEx->cur.y += drawHeight;
        pInfoEx->cur.y += textHeitht;
    }
    pInfoEx->cur.x +=blankNum*fontWidht;
}

//换行
void CPrintCaseInfoView::NewLine(CDC* pDC, CPrintInfo* pInfo , bool force)
{
    CPrintInfoEx* pInfoEx=(CPrintInfoEx*)pInfo->m_lpUserData; 
    if( !force )
    {
        if( pInfoEx->cur.x == pInfoEx->rc.left )
        {
            return ;
        }
    }
    TEXTMETRIC tm;
    pDC->GetTextMetrics (&tm);
    int textHeitht = tm.tmHeight+tm.tmExternalLeading+tm.tmInternalLeading;
    pInfoEx->cur.x = pInfoEx->rc.left;
    pInfoEx->cur.y -= textHeitht;
}

//换行
void CPrintCaseInfoView::NewHalfLine(CDC* pDC, CPrintInfo* pInfo , bool force)
{
    CPrintInfoEx* pInfoEx=(CPrintInfoEx*)pInfo->m_lpUserData; 
    if( !force )
    {
        if( pInfoEx->cur.x == pInfoEx->rc.left )
        {
            return ;
        }
    }
    TEXTMETRIC tm;
    pDC->GetTextMetrics (&tm);
    int textHeitht = tm.tmHeight+tm.tmExternalLeading+tm.tmInternalLeading;
    pInfoEx->cur.x = pInfoEx->rc.left;
    pInfoEx->cur.y -= textHeitht/2;
}

//换行
void CPrintCaseInfoView::NewSmallHalfLine(CDC* pDC, CPrintInfo* pInfo , bool force)
{
    CPrintInfoEx* pInfoEx=(CPrintInfoEx*)pInfo->m_lpUserData; 
    if( !force )
    {
        if( pInfoEx->cur.x == pInfoEx->rc.left )
        {
            return ;
        }
    }
    TEXTMETRIC tm;
    pDC->GetTextMetrics (&tm);
    int textHeitht = tm.tmHeight+tm.tmExternalLeading+tm.tmInternalLeading;
    pInfoEx->cur.x = pInfoEx->rc.left;
    pInfoEx->cur.y -= textHeitht/5;
}

//竖排文本
void CPrintCaseInfoView::PrintTextV(CDC* pDC, CPrintInfo* pInfo,CString text)
{
    CPrintInfoEx* pInfoEx=(CPrintInfoEx*)pInfo->m_lpUserData; 
    CFont *pOldFont=pDC->SelectObject(&boldFont);//选入设备描述表

    int textL=text.GetLength();
    TEXTMETRIC tm;
    pDC->GetTextMetrics (&tm);
    int textHeitht = (tm.tmHeight/*+tm.tmExternalLeading*/)*textL;
    int textWidth = tm.tmMaxCharWidth;

    CPoint centerPoint = pInfoEx->rc.CenterPoint();
    CRect rc = CRect( centerPoint.x-textWidth/2-2, centerPoint.y+textHeitht/2 , centerPoint.x+textWidth/2+2 ,  centerPoint.y-textHeitht/2 );

    //   pDC->Rectangle(rc);
    pDC->DrawText(text,rc,DT_WORDBREAK);
    pDC->SelectObject(pOldFont); //将myFont从设备环境中分离
}

void CPrintCaseInfoView::OnInitialUpdate()
{
    TRACE_FUNC();
    CScorllCenterFormView::OnInitialUpdate();
    //更新文档数据，主要是下拉列表，因为新建时下拉列表项的文档内容为空，界面内容为默认值
    UpdateData(TRUE);
    //并无实际有效内容修改，清除文档修改标志
    GetDocument()->SetModifiedFlag(FALSE);
    // TODO: 在此添加专用代码和/或调用基类
}

BOOL CPrintCaseInfoView::OnUpdateDocFromView()
{
	//TRACE_FUNC();
	return UpdateData(TRUE);

}
