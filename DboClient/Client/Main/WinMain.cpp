#include "precomp_dboclient.h"
#include "DboApplication.h"
#include "NtlDebug.h"
#include "DboCompileOpt.h"
#include "DboDef.h"
#include "NtlClientService.h"
#include "BugTrap.h"
#include "Version.h"
#ifdef _UNICODE
#pragma comment(lib, "BugTrapU.lib")  // Link to Unicode DLL
#else
#pragma comment(lib, "BugTrap.lib")      // Link to ANSI DLL
#endif

BOOL IsMultiOpen(const char *pExeName)
{
	HANDLE hMutex = ::CreateMutex(NULL, FALSE, pExeName);
	if(NULL == hMutex)
		return FALSE;

	if(GetLastError() == ERROR_ALREADY_EXISTS)
		return FALSE;
	return TRUE;
}

BOOL IsLimitDirectory(void)
{
	RwChar chCurrDir[1024];
	memset(chCurrDir, 0, 1024);

	GetCurrentDirectory(1024, chCurrDir);

	RwInt32 iLen = (RwInt32)strlen(chCurrDir);
	if(iLen >= 200)
		return FALSE;

	return TRUE;
}
static void SetErrorReport()
{
	
	//CDboExtraErrorReport::SetDXDiagLog();

	// 버그트랩용 설정    
	char szVer[32] = { 0, };
	sprintf_s(szVer, "%d.%d.%d.%d", _VERSION_MAJOR_, _VERSION_MINOR_, _VERSION_REVISION_, _VERSION_BUILD_);

	BT_SetAppName(_T("Dragon Ball Online Universe Revelations"));
	BT_SetAppVersion(szVer);
	BT_SetDialogMessage(BTDM_INTRO1, "Dragon Ball Online Revelations has crashed and must be terminated.");
	BT_SetSupportEMail(_T("noreply@liquidmuds.com"));
	BT_SetFlags(BTF_DETAILEDMODE | BTF_ATTACHREPORT | BTF_SCREENCAPTURE | BTF_DESCRIBEERROR | BTF_LISTPROCESSES | BTF_SHOWADVANCEDUI);
	BT_SetSupportURL(_T("https://universe.dborevelations.com/forum/forum/52-support/"));
	// BugTrapServer ===========================================
	BT_SetSupportServer(_T("217.146.81.120"), 21221);

	char buf[NTL_MAX_DIR_PATH] = { 0, };
	::GetCurrentDirectory(NTL_MAX_DIR_PATH, buf);

	// 추가 정보 (게임 ID)    
	std::string strAddLogFile = buf;
	strAddLogFile += "\\";
	strAddLogFile += ERROR_REPORT_FILE_NAME;
	BT_AddLogFile(strAddLogFile.c_str());

	// DBO Log
	strAddLogFile = buf;
	strAddLogFile += "\\dbolog.txt";
	BT_AddLogFile(strAddLogFile.c_str());

	BT_InstallSehFilter();
	BT_SetTerminate();

	NtlLogFilePrintArgs("Initalizing Dragon Ball Online Universe Revelations Version %s", szVer);

}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR    lpCmdLine,
                     int       nCmdShow)
{

#ifdef MUTEX_CHECK
	//if ( NULL == lpCmdLine && strcmp( lpCmdLine, "nomutex" ) > 0 )
	//{
		if(!IsMultiOpen("DragonBall"))
		{
			::MessageBox(NULL, "DragonBall is already opened !!!", "DragonBall", MB_OK);
			return 1;
		}
	//}
#endif

	NtlClientNetSetPrintFlag( 0 );
	SetErrorReport();

	// 서비스 시작
	if ( !GetServiceInterface()->Begin( lpCmdLine ) )
	{
		::MessageBox(NULL, "Wrong service information.", "DragonBall", MB_OK);
		return 1;
	}

	eDBO_SERVICE_PUBLISHER eService = GetServiceInterface()->GetPublisherID();
	if( eDBO_SERVICE_PUBLISHER_CJI_KOR == eService )
	{
		for( RwUInt8 i = 0 ; i < 4 ; ++i )
		{
			RwChar* pcData = (RwChar*)GetServiceInterface()->GetServiceData(i);

			if( !pcData || strlen(pcData) == 0 )
			{
				::MessageBox(NULL, "Wrong service data", "DragonBall", MB_OK);
				return 1;
			}
		}
	}
	else if (eDBO_SERVICE_PUBLISHER_DBONU == eService) 
	{
		for (RwUInt8 i = 0; i < 2; i++)
		{
			RwChar* pcData = (RwChar*)GetServiceInterface()->GetServiceData(i);
			if (!pcData || strlen(pcData) == 0)
			{
				::MessageBox(NULL, "Make sure to run the game from the launcher.", "Dragonball Online: Universe Revelations", MB_OK);
				ShellExecute(NULL, "open", "dbourlauncher.exe", NULL, NULL, SW_SHOWDEFAULT);
				return 1;
			}
		}
	}

	if(!IsLimitDirectory())
	{
		::MessageBox(NULL, "A directory name length must not exceed 200 letters", "DragonBall", MB_OK);
		return 1;
	}

	// 보안 솔루션 시작
	// - 보안 솔루션이 실패 했어도 게임이 실행될때까지 종료하지 않고 대기하고 있다가 종료시킨다
//	GetServiceInterface()->CreateSecuritySolution();

	CDboApplication app;
	
	app.Init();

#ifdef NDEBUG
	if(!app.Create(hInstance, 0, 0, EXTRA_SCREEN_WIDTH, EXTRA_SCREEN_HEIGHT, TRUE))
	{
		NTL_ASSERTE("Application create failed!!!");
		return 1;
	}

#else

	if(!app.Create(hInstance, 0, 0, DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, NTL_DEBUG_WINDOW_MODE))
	{
		NTL_ASSERTE("Application create failed!!!");
		return 1;
	}

#endif

	// 보안 솔루션에 윈도우를 연결한다
//	GetServiceInterface()->AttachSecuritySolutionWindow( app.GetHWnd() );

	app.MessagePump();
	app.Destroy();

	// 보안 솔루션 종료
//	GetServiceInterface()->DeleteSecuritySolution();

	// 서비스 종료
//	GetServiceInterface()->End();

	return 1;
}


