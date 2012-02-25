#pragma once
#include "msword.h"
// CWordTools 命令目标


#define  wdFormatDocument     0     
#define  wdFormatDOSText     4     
#define  wdFormatDOSTextLineBreaks     5     
#define  wdFormatEncodedText     7     
#define  wdFormatFilteredHTML     10     
#define  wdFormatHTML     8     
#define  wdFormatRTF     6     
#define  wdFormatTemplate     1     
#define  wdFormatText     2     
#define  wdFormatTextLineBreaks     3     
#define  wdFormatUnicodeText     7     
#define  wdFormatWebArchive     9     
#define  wdFormatXML     11   

#define wdGoToBookmark -1



class AFX_CLASS_EXPORT CWordTools : public CObject
{
private:
	_Application m_wdApp;
	Documents m_wdDocs;
	_Document m_wdDoc;
	Bookmarks  m_wdBookmarks;
	//Bookmark  m_wdBookmark;
	Selection m_wdSel;
	Range     m_wdRange;
	InlineShapes m_wdInlineShapes; 
	InlineShape m_wdInlineShape;
public:
	CWordTools();
	virtual ~CWordTools();
public:
	//**********************创建新文档*******************************************
	BOOL CreateApp();                    //创建一个新的WORD应用程序
	BOOL CreateDocuments();                //创建一个新的Word文档集合
	BOOL CreateDocument(CString DocTemplate = _T(""));                //创建一个新的Word文档
	BOOL Create(CString DocTemplate = _T(""));                        //创建新的WORD应用程序并创建一个新的文档
	void ShowApp();                        //显示WORD文档
	void HideApp();                        //隐藏word文档
	void PrintPreview();
	//**********************打开文档*********************************************
	BOOL OpenDocument(CString fileName);//打开已经存在的文档。
	BOOL Open(CString fileName);        //创建新的WORD应用程序并打开一个已经存在的文档。
	BOOL SetActiveDocument(short i);    //设置当前激活的文档。

	//**********************保存文档*********************************************
	BOOL SaveDocument();                //文档是以打开形式，保存。
	BOOL SaveDocumentAs(CString fileName);//文档以创建形式，保存。
	BOOL CloseDocument();
	void CloseApp(); 

	//**********************文本书写操作*****************************************
	void WriteText(CString szText);        //当前光标处写文本
	void WriteNewLineText(CString szText, int nLineCount = 1); //换N行写字
	void WriteEndLine(CString szText);    //文档结尾处写文本
	void WholeStory();                    //全选文档内容
	void Copy();                        //复制文本内容到剪贴板
	void InsertFile(CString fileName);    //将本地的文件全部内容写入到当前文档的光标处。

	//**********************图片插入操作*****************************************
	void InsertShapes(CString fileName);//在当前光标的位置插入图片

	//**********************超链接插入操作*****************************************
	void InsertHyperlink(CString fileLink);//超级链接地址，可以是相对路径。

public:
	// 查找bkName书签，并修改内容为bkText，成功返回TRUE，失败返回FALSE
	BOOL BookmarkText(CString bkName, CString bkText);
	//删除所有书签
	BOOL DeleteAllBookmarks();
public:
	void ActivateApp(void);
};


