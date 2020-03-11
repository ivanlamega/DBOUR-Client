#pragma once

#include "NtlWorldConceptController.h"

class CNtlPLCharacter;
class CNtlPLEntity;

/**
 * \ingroup NtlSimulation
 * \brief PVP를 할때의 제어 클래스 
 * \date 2007-06-14
 * \author agebreak
 */
typedef std::map<RwUInt32, RwUInt32>				MAP_OPENBATTLE;		// first SerialID
typedef std::map<RwUInt32, RwUInt32>::iterator		MAP_OPENBATTLE_ITER;

class CNtlWorldConceptOpenPVP : public CNtlWorldConceptController
{
public:
	CNtlWorldConceptOpenPVP(void);
	~CNtlWorldConceptOpenPVP(void);

	virtual void	Update(RwReal fElapsedTime);	
	virtual void	ChangeState(RwInt32 iState);

	RwBool IsAttackableEnemy(RwUInt32 uiHandle);

	CNtlSobActor * GetNearAttackableEnemy(CNtlSobActor * pActor);
	void			EventHandler_BattleStart(void * pData);
	void			EventHandler_BattleEnd(void * pData);
	MAP_OPENBATTLE*		GetBattlers(VOID) { return &m_mapMembers; }

	//---- PVP 관련 메소드
	void				SetFreePvPTarget(SERIAL_HANDLE hTarget);					///< PVP 타겟을 설정한다.
	SERIAL_HANDLE		GetFreePvPTarget(void) const;								///< 현재 설정된 PVP Target의 Serail ID를 반환한다.

	void				SetFreePvPReferPos(RwV3d vPos);
	RwV3d				GetFreePvPReferPos(void) const;

	void				CreateFreePvPMark(void);							///< PVP 마크(현재는 심판)을 생성한다.
	void				DestroyFreePvPMark(void);							///< PVP 마크를 제거한다.

protected:
	/// PVP 관련 정보 구조체
	struct FreeBattleInfo
	{
		CNtlPLCharacter		*pCharacter;
        CNtlPLEntity*       pBoundEffect;
		SERIAL_HANDLE		hFreePvPTarget;
		RwV3d				vFreePvPPos;
	};

protected:
	FreeBattleInfo		m_FreeBattleInfo;		///< PVP 관련 구조체
	MAP_OPENBATTLE		m_mapMembers;

};


// 인라인 함수들

inline void	CNtlWorldConceptOpenPVP::SetFreePvPTarget(SERIAL_HANDLE hTarget)
{
	m_FreeBattleInfo.hFreePvPTarget = hTarget;
}

inline SERIAL_HANDLE CNtlWorldConceptOpenPVP::GetFreePvPTarget(void) const
{
	return m_FreeBattleInfo.hFreePvPTarget;
}

inline void	CNtlWorldConceptOpenPVP::SetFreePvPReferPos(RwV3d vPos)
{
	m_FreeBattleInfo.vFreePvPPos = vPos;
}

inline RwV3d CNtlWorldConceptOpenPVP::GetFreePvPReferPos(void) const
{
	return m_FreeBattleInfo.vFreePvPPos;
}