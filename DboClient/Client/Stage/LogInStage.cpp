#include "precomp_dboclient.h"
#include "LogInStage.h"

// shared
#include "NtlResultCode.h"

// network
#include "NtlClientNet.h"

// core
#include "NtlDebug.h"
#include "NtlEventQueue.h"
#include "NtlSystemInfo.h"

// simulation
#include "NtlNetSender.h"
#include "InputActionMap.h"
#include "NtlStorageManager.h"

// presentation
#include "NtlPLResourcePack.h"
#include "NtlCameraManager.h"
#include "CharStageState.h"

// dbo
#include "DboDef.h"
#include "DboGlobal.h"
#include "DboEvent.h"
#include "DboEventGenerator.h"
#include "DisplayStringDef.h"
#include "DisplayStringManager.h"
#include "LogInGuiGroup.h"
#include "LogInStageState.h"
#include "AlarmManager.h"

#include "DboApplication.h"
#include "MoviePlayer.h"


namespace
{
	// zoom mode
#define dZOOM_NONE				0
#define dZOOM_IN				1
#define dZOOM_OUT				2
};

CLogInStage::CLogInStage(const char *pStageName)
:CNtlStage(pStageName),
m_pWorldEntity(NULL),
m_bWorldAddCamera(FALSE),
m_bAutoLogIn(FALSE),
m_pState(NULL),
m_pGuiGroup(NULL)
{
}

CLogInStage::~CLogInStage()
{
}

bool CLogInStage::Create(void)
{
	NTL_FUNCTION("CLogInStage::Create" );

	// event 등록.
	LinkMsg(g_EventUpdateTick, 0);
	LinkMsg(g_EventLogInServerConnect, 0);
	LinkMsg(g_EventLobbyServerConnect, 0);
	LinkMsg(g_EventLogInStageStateEnter, 0);
	LinkMsg(g_EventLogInStageStateExit, 0);
	LinkMsg(g_EventLogInStageTimeOut, 0);
	LinkMsg(g_EventLoginMessage, 0);	

	m_pState	= NTL_NEW CLogInStageState;	
	
	
	
	m_pGuiGroup = NTL_NEW CLogInGuiGroup;

	if(!m_pGuiGroup->Create())
	{
		NTL_DELETE(m_pGuiGroup);
		NTL_RETURN(FALSE);
	}

	// avooo's commnet : 애플리케이션이 처음 실행될 때만 로고가 보이도록 하였다.
	//					 게임중 로그인 화면으로 돌아왔을 때 로고가 또 보이니 어색하다.
	static RwBool bFirstRunLogo = TRUE;
	if( bFirstRunLogo )
	{
		GetLogInStageState()->ChangeState(LOGIN_STATE_LOGO);

#ifndef NDEBUG
		RwBool bWindowMode = GetNtlStorageManager()->GetBoolData( dSTORAGE_GRAPHIC_WINDOW_MODE );
		RwInt32 nScreenWidth = GetNtlStorageManager()->GetIntData( dSTORAGE_GRAPHIC_SELECT_VIDEOWIDTH );
		RwInt32 nScreenHeight = GetNtlStorageManager()->GetIntData( dSTORAGE_GRAPHIC_SELECT_VIDEOHEIGHT );
		GetNtlStorageManager()->SetData( dSTORAGE_GRAPHIC_WINDOW_MODE, B2b(!NTL_DEBUG_WINDOW_MODE) );
		GetNtlStorageManager()->SetData( dSTORAGE_GRAPHIC_SELECT_VIDEOWIDTH, DEFAULT_SCREEN_WIDTH );
		GetNtlStorageManager()->SetData( dSTORAGE_GRAPHIC_SELECT_VIDEOHEIGHT, DEFAULT_SCREEN_HEIGHT );
		GetNtlStorageManager()->ApplyStorageType( eNTL_STORAGE_GRAPHIC, eNTL_STORAGE_APPLY_ALL );
		GetNtlStorageManager()->SetData( dSTORAGE_GRAPHIC_WINDOW_MODE, B2b(bWindowMode) );
		GetNtlStorageManager()->SetData( dSTORAGE_GRAPHIC_SELECT_VIDEOWIDTH, nScreenWidth );
		GetNtlStorageManager()->SetData( dSTORAGE_GRAPHIC_SELECT_VIDEOHEIGHT, nScreenHeight );
#else
		GetNtlStorageManager()->ApplyStorageType( eNTL_STORAGE_GRAPHIC, eNTL_STORAGE_APPLY_ALL );		
#endif

		GetNtlStorageManager()->ApplyStorageType( eNTL_STORAGE_SOUND, eNTL_STORAGE_APPLY_ALL );


		bFirstRunLogo = !bFirstRunLogo;
	}
	else
	{
		GetLogInStageState()->ChangeState(LOGIN_STATE_SERVER_CONNECT);
	}

	GetInputActionMap()->LinkGameExit(this, &CLogInStage::ActionGameExit);
	CDboGlobal::GetInstance()->UpdateLoginStage(CDboGlobal::GetInstance()->m_pDiscordPresence);
	NTL_RETURN(TRUE);
}

void CLogInStage::Destroy(void)
{
	NTL_FUNCTION("CLogInStage::Destroy" );

	CNtlPostEffectCamera::SetPostEffectFilters(POST_EFFECT_FILTER_NONE);

	// event 해제.
	UnLinkMsg(g_EventUpdateTick);
	UnLinkMsg(g_EventLogInServerConnect);
	UnLinkMsg(g_EventLobbyServerConnect);
	UnLinkMsg(g_EventLogInStageStateEnter);
	UnLinkMsg(g_EventLogInStageStateExit);
	UnLinkMsg(g_EventLogInStageTimeOut);
	UnLinkMsg(g_EventLoginMessage);
	
	if (m_bWorldAddCamera)
	{
		RpWorldRemoveCamera(CNtlPLGlobal::m_pRpWorld, CNtlPLGlobal::m_RwCamera);
		m_bWorldAddCamera = FALSE;
	}
	if (m_pWorldEntity)
	{
		GetSceneManager()->DeleteEntity(m_pWorldEntity);
		m_pWorldEntity = NULL;
	}

	if(m_pGuiGroup)
	{
		m_pGuiGroup->Destroy();
		NTL_DELETE(m_pGuiGroup);
	}

	if(m_pState)
	{
		NTL_DELETE(m_pState);
	}

	GetInputActionMap()->UnLinkGameExit();

	NTL_RETURNVOID();
}
void CLogInStage::DestroyBackGroundStage()
{
	if (m_bWorldAddCamera)
	{
		RpWorldRemoveCamera(CNtlPLGlobal::m_pRpWorld, CNtlPLGlobal::m_RwCamera);
		m_bWorldAddCamera = FALSE;
	}
	if (m_pWorldEntity)
	{
		GetSceneManager()->DeleteEntity(m_pWorldEntity);
		m_pWorldEntity = NULL;
	}
}
void CLogInStage::CreateBackGroundStage()
{

	int loginScreen;

	/* initialize random seed: */
	srand(time(NULL));

	/* generate secret number between 1 and 10: */
	loginScreen = rand() % 4 + 1;

#ifdef MODSENABLED
	strcpy(dGET_WORLD_PARAM()->CurWorkingFolderName, ".");//Relative Paths you fucking kunts
#else
	_getcwd(dGET_WORLD_PARAM()->CurWorkingFolderName, 256);
#endif
	strcpy(dGET_WORLD_PARAM()->CurDefaultTexPath, dGET_WORLD_PARAM()->CurWorkingFolderName);
	strcat(dGET_WORLD_PARAM()->CurDefaultTexPath, "\\texture\\ntlwe\\");
	std::string str = "\\world\\";
	//Set the world for the random login screen
	switch (loginScreen)
	{
	case 1:
		str += "dbo_dojo_001";
		break;
	case 2:
		str += "DBO_Start_001";
		break;
	case 3:
		str += "DBO_Select_Character";
		break;
	case 4:
		str += "dbo_korin_tower";
		break;
	/*case 5:
		break;*/
	default:
		str += "dbo_dojo_001";
		break;
	}

	strcpy(dGET_WORLD_PARAM()->WorldProjectFolderName, dGET_WORLD_PARAM()->CurWorkingFolderName);
	strcat(dGET_WORLD_PARAM()->WorldProjectFolderName, str.c_str());
	str += "\\";
	str += "#######.gwp";
	FILE* pFile = NULL;
	SPackResFileData sPackFileData;
	RwBool bPack = GetNtlResourcePackManager()->LoadTerrain(str.c_str(), sPackFileData);
	if (bPack)
	{
		pFile = fopen(sPackFileData.strPackFileName.c_str(), "rb");
		if (pFile)
			fseek(pFile, sPackFileData.uiOffset, SEEK_SET);
	}
	else
	{
		std::string strWorldFileName = ".";
		strWorldFileName += str;
		pFile = fopen(strWorldFileName.c_str(), "rb");
	}
	// create a global world param
	if (pFile)
	{
		LoadFileWorldState(dGET_WORLD_PARAM(), pFile);
		fclose(pFile);
	}
	DBO_ASSERT(dNTL_WORLD_VERSION_COMPARE(dGET_WORLD_PARAM()->WorldVer, dNTL_WORLD_VERSION), "invalid world resource version. world(" << dGET_WORLD_PARAM()->WorldProjectFolderName << ") support_version(" << dNTL_WORLD_VERSION << ") resource_version(" << dGET_WORLD_PARAM()->WorldVer << ")");
	DWORD dwCur = GetTickCount();
	//set the location of the random login screen
	switch (loginScreen)
	{
	case 1:
		//DBO Dojo
		m_vAvatarPos.x = -24.85f;
		m_vAvatarPos.y = 94.44f;
		m_vAvatarPos.z = 12.59f;


		m_vCameraPos.x = -29.85f;
		m_vCameraPos.y = 98.44f;
		m_vCameraPos.z = 32.59f;

		m_vCameraPosAt.x = -31.13f;
		m_vCameraPosAt.y = 98.5f;
		m_vCameraPosAt.z = 33.59f;
		break;
	case 2:
		//DBO Start 001
		m_vAvatarPos.x = 133.15f;
		m_vAvatarPos.y = 0.65f;
		m_vAvatarPos.z = -261.32f;

		m_vCameraPos.x = 129.39f;
		m_vCameraPos.y = 4.27f;
		m_vCameraPos.z = -279.74f;

		m_vCameraPosAt.x = 129.88f;
		m_vCameraPosAt.y = 4.33f;
		m_vCameraPosAt.z = -280.61f;
		break;
	case 3:
		//DBO Char Select
		m_vAvatarPos.x = -293.45f;
		m_vAvatarPos.y = 53.12f;
		m_vAvatarPos.z = -279.074f;


		m_vCameraPos.x = -294.509f;
		m_vCameraPos.y = 53.188f;
		m_vCameraPos.z = -279.966f;

		m_vCameraPosAt.x = -295.269f;
		m_vCameraPosAt.y = 53.258f;
		m_vCameraPosAt.z = -280.606f;
		break;
	case 4:
		//Korins Tower
		m_vAvatarPos.x = 94.76f;
		m_vAvatarPos.y = 38.52f;
		m_vAvatarPos.z = -208.80f;


		m_vCameraPos.x = 100.76f;
		m_vCameraPos.y = 35.52f;
		m_vCameraPos.z = -198.80f;

		m_vCameraPosAt.x = 81.56f;
		m_vCameraPosAt.y = 37.52f;
		m_vCameraPosAt.z = -209.80f;
		break;
	/*case 5:
		m_vAvatarPos.x = f;
		m_vAvatarPos.y = f;
		m_vAvatarPos.z = f;


		m_vCameraPos.x = f;
		m_vCameraPos.y = f;
		m_vCameraPos.z = f;

		m_vCameraPosAt.x = f;
		m_vCameraPosAt.y = f;
		m_vCameraPosAt.z = f;
		break;*/
	default:
		m_vAvatarPos.x = -24.85f;
		m_vAvatarPos.y = 94.44f;
		m_vAvatarPos.z = 12.59f;


		m_vCameraPos.x = -29.85f;
		m_vCameraPos.y = 98.44f;
		m_vCameraPos.z = 32.59f;

		m_vCameraPosAt.x = -31.13f;
		m_vCameraPosAt.y = 98.5f;
		m_vCameraPosAt.z = 33.59f;
		break;
	}



	m_pWorldEntity = static_cast<CNtlPLWorldEntity*>(GetSceneManager()->CreateEntity(PLENTITY_WORLD, "NtlWorld"));
	m_pWorldEntity->CreateWorld(m_vAvatarPos);

	RpWorldAddCamera(CNtlPLGlobal::m_pRpWorld, CNtlPLGlobal::m_RwCamera);
	m_bWorldAddCamera = TRUE;

	DWORD dwElapsedTime = GetTickCount() - dwCur;
	char buffer[256];
	wsprintf(buffer, "World Create Elapsed: %u\n", (int)dwElapsedTime);
	OutputDebugString(buffer);

	GetNtlGameCameraManager()->SetFov(60.f);

	//Player Position을 제대로 Update를 해주어야 하늘이 제대로 나온다.

	CNtlPostEffectCamera::SetPostEffectFilters(POST_EFFECT_FILTER_HDR);
}
void CLogInStage::TeleportStage()
{

	m_pWorldEntity->SetPortalPosition(m_vAvatarPos);
	m_pWorldEntity->SetPlayerPosition(m_vAvatarPos);
	m_pWorldEntity->Update(0.8f);
	API_PL_CameraLookAt(CNtlPLGlobal::m_RwCamera, &m_vCameraPos, &m_vCameraPosAt);
}

void CLogInStage::HandleEvents(RWS::CMsg &pMsg)
{
	if(pMsg.Id == g_EventUpdateTick)
	{
		float fElapsed = *reinterpret_cast<float*>(pMsg.pData);
		EventProcUpdateTick(fElapsed);
	}
	else if(pMsg.Id == g_EventLogInServerConnect)
	{
		LogInServerConnect(pMsg);
	}
	else if(pMsg.Id == g_EventLobbyServerConnect)
	{
		LobbyServerConnect(pMsg);
	}
	else if(pMsg.Id == g_EventLogInStageStateEnter)
	{
		LoginStageStateEnter(pMsg);
	}
	else if(pMsg.Id == g_EventLogInStageStateExit)
	{
		LoginStageStateExit(pMsg);
	}
	else if(pMsg.Id == g_EventLogInStageTimeOut)
	{
		LogInStageTimeOutEventHandler(pMsg);
	}
	else if(pMsg.Id == g_EventLoginMessage)
	{
		LogInMessageEventHandler(pMsg);
	}
}

void CLogInStage::EventProcUpdateTick(RwReal fElapsed)
{
	GetLogInStageState()->Update(fElapsed);
}

void CLogInStage::LogInServerConnect(RWS::CMsg &pMsg)
{
	SDboEventServerConnect *pConnect = reinterpret_cast<SDboEventServerConnect*>( pMsg.pData );

	if(pConnect->byConnectType == SERVER_CONNECT_TYPE_CONNENCT_SUCCESS)
	{
		GetLogInStageState()->ChangeState(LOGIN_STATE_IDLE);
	}
	else if(pConnect->byConnectType == SERVER_CONNECT_TYPE_CONNENCT_FAIL)
	{
		GetLogInStageState()->ChangeState(LOGIN_STATE_SERVER_CONNECT_FAIL);
		GetAlarmManager()->AlarmMessage( DST_ACCOUNT_SERVER_CONNECT_FAIL );
	}
	else if(pConnect->byConnectType == SERVER_CONNECT_TYPE_CONNENCT_DISCONNECT)
	{
		GetAlarmManager()->AlarmMessage( DST_SERVER_DISCONNECT );
	}
}

void CLogInStage::LobbyServerConnect(RWS::CMsg &pMsg)
{
	SDboEventServerConnect *pConnect = reinterpret_cast<SDboEventServerConnect*>( pMsg.pData );

	if( pConnect->byConnectType == SERVER_CONNECT_TYPE_CONNENCT_SUCCESS )
	{
		GetLogInStageState()->ChangeState(LOGIN_STATE_CHAR_SERVER_LOGIN);
	}
	else if( pConnect->byConnectType == SERVER_CONNECT_TYPE_CONNENCT_FAIL )
	{
		m_bAutoLogIn = TRUE;
		GetLogInStageState()->ChangeState(LOGIN_STATE_CHAR_SERVER_CONNECT);
	}
}

void CLogInStage::LoginStageStateEnter(RWS::CMsg &pMsg)
{
	SDboEventLogInStageStateEnter *pStageStateEnter = reinterpret_cast<SDboEventLogInStageStateEnter*>(pMsg.pData);

	ELogInStageState eState = (ELogInStageState)pStageStateEnter->byState;
	switch(eState)
	{
	case LOGIN_STATE_LOGO:
		break;
	case LOGIN_STATE_SERVER_CONNECT:
		{
		CreateBackGroundStage();
		TeleportStage();

			// account server connect...
			SConfigData *pConfigData = GetDboGlobal()->GetConfigData();  
			SConnectData *pConnectData = GetDboGlobal()->GetConnectData();  
			CNtlClientNet *pNet = GetDboGlobal()->GetNetwork(); 


#ifdef NET_SERVER_SYNC
			pNet->Connect( (char*)pConfigData->strAddr.c_str(), (WORD)pConfigData->dwPort, &pConnectData->sAuthCon.hSocket, true, NETCLIENT_ENCODE_NONE ); //SanGawku - Packet Encryption
#else
            CLoginPacketGenerator *pLoginPackGenerator = CDboGlobal::GetInstance()->GetLoginPacketGenerator(); 
            CNtlNetSender *pNetSender = pLoginPackGenerator->GetNetSender();
			pNetSender->SetData(INVALID_HSERVER, NULL); 
			GetLogInStageState()->ChangeState(LOGIN_STATE_IDLE);
#endif
		}
		break;
	case LOGIN_STATE_SERVER_CONNECT_FAIL:
		break;
	case LOGIN_STATE_IDLE:
		if(m_bAutoLogIn)
		{
			// 서버로 로그인 요청
			SUserData *pUserData = GetDboGlobal()->GetUserData();
			const char* pMacAddress = GetSystemMacAddress();

			if( pMacAddress )
			{
				GetDboGlobal()->GetLoginPacketGenerator()->SendLonInReq(pUserData->wchUserID, pUserData->wchPassword, CLIENT_LVER, CLIENT_RVER, pMacAddress); 
				GetLogInStageState()->ChangeState(LOGIN_STATE_LOGINREQ);
			}
			else
			{
				GetAlarmManager()->AlarmMessage(L"Fail read MAC address", CAlarmManager::ALARM_TYPE_LOBBY_MSGBOX, MBW_POST_QUIT_MESSAGE);
			}
		}
		break;
	case LOGIN_STATE_LOGINREQ:
		break;
	case LOGIN_STATE_CHAR_SERVER_CONNECT:
		{
#ifdef NET_SERVER_SYNC

			SConnectData *pConData = GetDboGlobal()->GetConnectData();  
			CNtlClientNet *pNet = GetDboGlobal()->GetNetwork(); 

			SCharServerInfo sCharServerInfo;
			RwBool bExist = pConData->PopCharacterServer(&sCharServerInfo);
			if(bExist)
				pNet->Connect( (char*)sCharServerInfo.chServerIP, sCharServerInfo.wServerPort, &pConData->sCharCon.hSocket, TRUE, NETCLIENT_ENCODE_NONE );
			else
			{
				GetAlarmManager()->AlarmMessage( DST_CHAR_SERVER_CONNECT_FAIL );
				GetLogInStageState()->ChangeState(LOGIN_STATE_SERVER_CONNECT_FAIL);
			}
#else
			CLobbyPacketGenerator *pLobbyPacketGenerator = GetDboGlobal()->GetLobbyPacketGenerator(); 
			CNtlNetSender *pNetSender = pLobbyPacketGenerator->GetNetSender();
			pNetSender->SetData(INVALID_HSERVER, NULL); 

			GetLogInStageState()->ChangeState(LOGIN_STATE_CHAR_SERVER_LOGIN);
#endif
		}
		break;
	}
}

void CLogInStage::LoginStageStateExit(RWS::CMsg &pMsg)
{
}

void CLogInStage::LogInStageTimeOutEventHandler(RWS::CMsg &msg)
{
	SDboEventLogInStageTimeOut *pStageTimeOut = reinterpret_cast<SDboEventLogInStageTimeOut*>(msg.pData);

	ELogInStageState eState = (ELogInStageState)pStageTimeOut->byState;
	switch(eState)
	{
	case LOGIN_STATE_LOGO:
		break;
	case LOGIN_STATE_SERVER_CONNECT: 
		GetAlarmManager()->AlarmMessage( DST_ACCOUNT_SERVER_CONNECT_FAIL );
		break;
	case LOGIN_STATE_SERVER_CONNECT_FAIL:
		break;
	case LOGIN_STATE_IDLE:
		break;
	case LOGIN_STATE_LOGINREQ:
		GetAlarmManager()->AlarmMessage( AUTH_AUTHKEY_FAIL, TRUE );
		GetLogInStageState()->ChangeState(LOGIN_STATE_IDLE);
		break;
	case LOGIN_STATE_CHAR_SERVER_CONNECT:
		GetLogInStageState()->ChangeState(LOGIN_STATE_CHAR_SERVER_CONNECT);
		break;
	case LOGIN_STATE_CHAR_SERVER_LOGIN:
		GetAlarmManager()->AlarmMessage( CHARACTER_AUTHKEY_FAIL, TRUE );
		m_bAutoLogIn = FALSE;
		GetLogInStageState()->ChangeState(LOGIN_STATE_SERVER_CONNECT);
		break;
	}
}

void CLogInStage::LogInMessageEventHandler(RWS::CMsg &msg)
{
	SDboEventLoginMessage* pEvent = reinterpret_cast<SDboEventLoginMessage*>( msg.pData );

	switch(pEvent->byMessage)
	{
	case LOGIN_EVENT_FINISH_LOGO_PLAY:
		{
			Logic_SetOptionMovieStop();
			GetLogInStageState()->ChangeState(LOGIN_STATE_SERVER_CONNECT);
			break;
		}
	}
}

int CLogInStage::ActionGameExit(void)
{
	CDboApplication::GetInstance()->SetRenderEnable(TRUE);
	/*CDboApplication::GetInstance()->SetToggleScreenMode(TRUE);*/
	
	GetInputActionMap()->SetActive(FALSE);
	
	return TRUE;
}