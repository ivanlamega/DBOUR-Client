#ifndef _DBO_TSACTOUTMSG_H_
#define _DBO_TSACTOUTMSG_H_


#include "DboTSCoreDefine.h"


/**
	Direction action
	용도 : Client quest, client trigger, Server quest, server trigger pc
	설명 : 서버는 클라이언트에게 연출 상태로 바꾸라는 메시지를 내려준다.
		   클라이언트, 서버의 TS에서 m_tcJump의 동작 처리를 해준다
*/


class CDboTSActOutMsg : public CNtlTSAction
{
	NTL_TS_DECLARE_RTTI

		// Member variables
protected:
	unsigned int						m_uiTblidx;
	unsigned int						m_uiActionId;

	// Constructions
public:
	CDboTSActOutMsg(void);

	// Methods
public:
	virtual unsigned int				GetEntityType(void) const { return DBO_ACT_ID_ACT_OUT_MSG; }

	// Implementations
protected:
	// 스크립트로 부터 컴포넌트 객체의 데이터를 로딩 및 입력 시키기 위한 함수
	virtual	void						ApplyScriptDataForScript(const CNtlTSScrProperty& clProperty);
	virtual	void						TakeScriptDataForScript(CNtlTSScrProperty& clProperty);
};


#endif