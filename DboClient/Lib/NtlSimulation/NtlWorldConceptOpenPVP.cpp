#include "precomp_ntlsimulation.h"
#include "NtlWorldConceptOpenPVP.h"
#include "NtlWorldConcept.h"

// sound
#include "NtlSoundEventGenerator.h"
#include "GUISoundDefine.h"

// presentation
#include "NtlPLCharacter.h"
#include "NtlPLSceneManager.h"

// simulation
#include "NtlSLLogic.h"
#include "NtlSLVisualDeclear.h"

#include "NtlSobAvatar.h"
#include "NtlSobManager.h"
#include "NtlSobGroup.h"
#include "NtlSobPet.h"
#include "NtlSLLogic.h"

CNtlWorldConceptOpenPVP::CNtlWorldConceptOpenPVP(void)
{
}

CNtlWorldConceptOpenPVP::~CNtlWorldConceptOpenPVP(void)
{
}

void CNtlWorldConceptOpenPVP::Update( RwReal fElapsedTime ) 
{
	switch(m_iWorldState)
	{
	case WORLD_STATE_ENTER:
		ChangeState(WORLD_STATE_IDLE);
		break;
	case WORLD_STATE_IDLE:
		break;
	case WORLD_STATE_EXIT:
			ChangeState(WORLD_STATE_NONE);
		break;
	}
}

void CNtlWorldConceptOpenPVP::CreateFreePvPMark( void ) 
{
}

void CNtlWorldConceptOpenPVP::DestroyFreePvPMark( void ) 
{
}

void CNtlWorldConceptOpenPVP::ChangeState( RwInt32 iState ) 
{
	CNtlWorldConceptController::ChangeState(iState);

	switch(iState)
	{
	case WORLD_STATE_ENTER:
		{
			//CNtlSoundEventGenerator::SendEventMusic(EVENT_MUSIC_START_PVP_BGM);
/*
			sNtlSoundPlayParameta tSoundParam;
			tSoundParam.iChannelGroup	= CHANNEL_GROUP_JINGLE_MUSIC_WITHOUT_FADE;
			tSoundParam.pcFileName		= GSD_JINGLE_PVP_START;
			GetSoundManager()->Play(&tSoundParam);
			*/
			break;
		}		
	case WORLD_STATE_EXIT:
		{
			//CNtlSoundEventGenerator::SendEventMusic(EVENT_MUSIC_END_PVP_BGM);

		/*	sNtlSoundPlayParameta tSoundParam;
			tSoundParam.iChannelGroup	= CHANNEL_GROUP_JINGLE_MUSIC_WITHOUT_FADE;
			tSoundParam.pcFileName		= GSD_JINGLE_PVP_END;
			GetSoundManager()->Play(&tSoundParam);*/
			break;
		}		
	}	
}

RwBool CNtlWorldConceptOpenPVP::IsAttackableEnemy(RwUInt32 uiHandle)
{
	CNtlSob* pSob = GetNtlSobManager()->GetSobObject(uiHandle);
	if (!pSob)
		return FALSE;

	MAP_OPENBATTLE_ITER iter_member = m_mapMembers.find(uiHandle);

	if (iter_member != m_mapMembers.end())
	{
		MAP_OPENBATTLE_ITER iter_me = m_mapMembers.find(GetNtlSLGlobal()->GetAvatarInfo()->uiSerialId);
			if(iter_me != m_mapMembers.end())
				return TRUE;
			else 
				return FALSE;
	}

	return FALSE;
}

CNtlSobActor* CNtlWorldConceptOpenPVP::GetNearAttackableEnemy(CNtlSobActor* pActor)
{
	MAP_OPENBATTLE_ITER iter_member;

	RwReal fLen, fMinLen = FLT_MAX;
	RwV3d vPos = pActor->GetPosition();
	RwV3d vSub, vTarPos;
	CNtlSobActor* pTargetActor = NULL;
	CNtlSobActor* pSobActor;

	for (iter_member = m_mapMembers.begin(); iter_member != m_mapMembers.end(); ++iter_member)
	{
		RwUInt32 hSerial = iter_member->second;
		pSobActor = reinterpret_cast<CNtlSobActor*>(GetNtlSobManager()->GetSobObject(hSerial));

		if (!Logic_CanTargetted(pSobActor) || Logic_IsCondition(pSobActor, CHARCOND_FLAG_HIDING_KI))
			continue;

		vTarPos = pSobActor->GetPosition();
		RwV3dSub(&vSub, &vTarPos, &vPos);
		fLen = RwV3dLength(&vSub);

		if (fLen > 50.0f)
			continue;

		if (fLen < fMinLen)
		{
			fMinLen = fLen;
			pTargetActor = pSobActor;
		}
	}

	return pTargetActor;
}

void CNtlWorldConceptOpenPVP::EventHandler_BattleStart(void* pData)
{
	SNtlEventTSOpenBattleStart* pPlayers = reinterpret_cast<SNtlEventTSOpenBattleStart*>(pData);

	RwUInt32 hSerial = pPlayers->handle;
	m_mapMembers.emplace(hSerial,hSerial);

}

void CNtlWorldConceptOpenPVP::EventHandler_BattleEnd(void* pData)
{
	SNtlEventTSOpenBattleEnd* pPlayers = reinterpret_cast<SNtlEventTSOpenBattleEnd*>(pData);
	RwUInt32 hSerial = pPlayers->handle;

	MAP_OPENBATTLE_ITER iter_member = m_mapMembers.find(hSerial);

	if (iter_member != m_mapMembers.end())
	{
		m_mapMembers.erase(hSerial);
	}
}

