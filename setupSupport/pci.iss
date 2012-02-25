; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！

#define MyAppName "病例打印程序"
#define MyAppVerName "病例打印程序 V 2.2"
#define MyAppPublisher "guoyukun"
;#define MyAppURL "http://www.FuyouIT.com/"
;#define MyUpdateURL "http://www.FuyouIT.com/123"
#define MyAppExeName "PrintCaseInfo2x.exe"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{3AA65159-29F0-4207-BC1F-7C5AE9C5BCF7}
AppName={#MyAppName}
AppVerName={#MyAppVerName}
AppPublisher={#MyAppPublisher}
;AppPublisherURL={#MyAppURL}
;AppSupportURL={#MyAppURL}
;AppUpdatesURL={#MyUpdateURL}
DefaultDirName={pf}\fuyouit\pci
DefaultGroupName={#MyAppName}
;LicenseFile=C:\Documents and Settings\Administrator\桌面\shouquan.rtf
;InfoBeforeFile=C:\Documents and Settings\Administrator\桌面\qian.rtf
;InfoAfterFile=C:\Documents and Settings\Administrator\桌面\hou.rtf
OutputDir=C:\Users\Guo\Desktop\pcisetup
OutputBaseFilename=pciSetup
SetupIconFile=D:\VCWorkSpace\Work\PrintCaseInfo2x-DLL\install.ico
Compression=lzma
SolidCompression=yes

WizardImageFile=compiler:Office2007.bmp
WizardSmallImageFile=compiler:WizModernSmallImage-IS.bmp
UninstallDisplayIcon=C:\Users\Guo\Desktop\pcisetup\uninstall.ico
VersionInfoVersion=2.1.0.3
VersionInfoCompany=guoyukun
VersionInfoDescription=病例打印程序V2.2安装包
VersionInfoTextVersion=2, 2, 0, 0

[Languages]
Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"
Name: "english"; MessagesFile: "compiler:Languages\English.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "D:\项目\ws-勿删\VCWorkSpace\Work\PrintCaseInfo2x-DLL\bin\release\PrintCaseInfo2x.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\项目\ws-勿删\VCWorkSpace\Work\PrintCaseInfo2x-DLL\bin\release\DocExport.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\项目\ws-勿删\VCWorkSpace\Work\PrintCaseInfo2x-DLL\bin\release\GeneralDll.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\项目\ws-勿删\VCWorkSpace\Work\PrintCaseInfo2x-DLL\bin\release\PciCoreDll.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Developer Tools\Xtreme ToolkitPro v12.1.1\Bin\vc80\ToolkitPro1211vc80U.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\项目\ws-勿删\VCWorkSpace\Work\PrintCaseInfo2x-DLL\PrintCaseInfoExe\mfc80u.dll"  ; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\项目\ws-勿删\VCWorkSpace\Work\PrintCaseInfo2x-DLL\PrintCaseInfoExe\msvcr80.dll"  ; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\项目\ws-勿删\VCWorkSpace\Work\PrintCaseInfo2x-DLL\bin\release\PrintCaseInfo2x.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\项目\ws-勿删\VCWorkSpace\Work\PrintCaseInfo2x-DLL\Files\styles\*"; DestDir: "{app}\styles"; Flags: ignoreversion recursesubdirs createallsubdirs
; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”

; Add the ISSkin DLL used for skinning Inno Setup installations.
Source: compiler:ISSkin.dll; DestDir: {app}; Flags: dontcopy

; Add the Visual Style resource contains resources used for skinning,
; you can also use Microsoft Visual Styles (*.msstyles) resources.
Source: compiler:IsSkins\Tech45.cjstyles; DestDir: {tmp}; Flags: dontcopy
[Icons]
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"                  ; WorkingDir: "{app}"
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}" ; WorkingDir: "{app}"
Name: "{group}\{cm:ProgramOnTheWeb,{#MyAppName}}"; Filename: "{#MyAppURL}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon                   ; WorkingDir: "{app}"
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon    ; WorkingDir: "{app}"

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#MyAppName}}"; Flags: nowait postinstall skipifsilent

[Code]
// Importing LoadSkin API from ISSkin.DLL
procedure LoadSkin(lpszPath: AnsiString; lpszIniFileName: AnsiString);
external 'LoadSkin@files:isskin.dll stdcall';

// Importing UnloadSkin API from ISSkin.DLL
procedure UnloadSkin();
external 'UnloadSkin@files:isskin.dll stdcall';

// Importing ShowWindow Windows API from User32.DLL
function ShowWindow(hWnd: Integer; uType: Integer): Integer;
external 'ShowWindow@user32.dll stdcall';

function InitializeSetup(): Boolean;
begin
	ExtractTemporaryFile('Tech45.cjstyles');
	LoadSkin(AnsiString(ExpandConstant('{tmp}\Tech45.cjstyles')), '');
	Result := True;
end;

procedure DeinitializeSetup();
begin
	// Hide Window before unloading skin so user does not get
	// a glimse of an unskinned window before it is closed.
	ShowWindow(StrToInt(ExpandConstant('{wizardhwnd}')), 0);
	UnloadSkin();
end;

[Registry]
Root: HKCR; Subkey: ".cid"; ValueType: string; ValueName: ""; ValueData: "PrintCaseInfo2x.Document" ; Flags:uninsdeletekey
Root: HKCR; Subkey: ".cid\ShellNew"; ValueType: string; ValueName: "NullFile"; ValueData: ""  ; Flags:uninsdeletekey

Root: HKCR; Subkey: "PrintCaseInfo2x.Document"; ValueType: string; ValueName: ""; ValueData: "PrintCaseInfo2x.Document" ; Flags:uninsdeletekey
Root: HKCR; Subkey: "PrintCaseInfo2x.Document\DefaultIcon"; ValueType: string; ValueName: ""; ValueData: "{app}\PrintCaseInfo2x.EXE,1" ; Flags:uninsdeletekey
Root: HKCR; Subkey: "PrintCaseInfo2x.Document\shell\open\command"; ValueType: string; ValueName: ""; ValueData: "{app}\PrintCaseInfo2x.EXE %1" ; Flags:uninsdeletekey





