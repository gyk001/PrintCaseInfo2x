#define STRINGIFY(x) #x
#define TOSTRING(x) (_T(STRINGIFY(x)))

extern "C" AFX_API_EXPORT BOOL InitDocExportDLL();
//extern "C" AFX_API_EXPORT UINT ExportToDoc2_0();

bool ResToFile(int ResID, CString ResKind, CString &fileName);