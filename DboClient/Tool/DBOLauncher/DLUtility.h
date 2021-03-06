/*****************************************************************************
*
* File			: DLUtility.h
* Author		: 
* Copyright		: (주) NTL
* Date			:
* Abstract		: 
*****************************************************************************
* Desc          : 
*
*****************************************************************************/


#pragma once


#include "DBOLauncherDef.h"
#include "DLEventSys.h"


//////////////////////////////////////////////////////////////////////////
//
// 현재 구동되는 클라이언트의 Language type을 얻어내는 함수
//
//////////////////////////////////////////////////////////////////////////


extern eDL_LANGUAGE_TYPE	GetLanguageType( void );


//////////////////////////////////////////////////////////////////////////
//
// 현재 구동중인 system을 얻어온다
//
//////////////////////////////////////////////////////////////////////////


class CDLProcessSys;
class CDLMessageSys;
class CDLIntegritySys;
class CDLSkinSys;
class CDLStateSys;

extern CDLProcessSys*		GetProcessSys( void );
extern CDLEventSys*			GetEventSys( void );
extern CDLMessageSys*		GetMessageSys( void );
extern CDLIntegritySys*		GetIntegritySys( void );
extern CDLSkinSys*			GetSkinSys( void );
extern CDLStateSys*			GetStateSys( void );


//////////////////////////////////////////////////////////////////////////
//
// Event
//
//////////////////////////////////////////////////////////////////////////


extern void					DLSendEvent( eDL_EVENT eMsg, sDL_EVENT_DATA_BASE* pData );
extern void					DLPostEvent( eDL_EVENT eMsg, sDL_EVENT_DATA_BASE* pData );


//////////////////////////////////////////////////////////////////////////
//
// Message
//
//////////////////////////////////////////////////////////////////////////


extern void					DLSendMessage_ToUser( unsigned int uiMsgID );		/*eDL_MSG*/
extern void					DLSendMessage_ForDebug( const CString& strMsg );


//////////////////////////////////////////////////////////////////////////
//
// Attach back-slash
//
//////////////////////////////////////////////////////////////////////////


extern void AttachBackSlash( CString& strString );


//////////////////////////////////////////////////////////////////////////
//
// Directory
//
//////////////////////////////////////////////////////////////////////////


bool MakeDirectory( const CString& strPath );