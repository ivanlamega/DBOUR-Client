//***********************************************************************************
//
//	File		:	UseItemTable.h
//
//	Begin		:	2006-08-22
//
//	Copyright	:	¨Ï NTL-Inc Co., Ltd
//
//	Author		:	Chung Doo sup   ( john@ntl-inc.com )
//
//	Desc		:	
//
//***********************************************************************************

#pragma once

#include "Table.h"
#include "NtlItem.h"

const DWORD		DBO_MAX_LENGTH_USE_ITEM_CASTING_EFFECT_NAME = 32;
const DWORD		DBO_MAX_LENGTH_USE_ITEM_ACTION_EFFECT_NAME = 32;

enum eUSE_ITEM_NEED_STATE
{
	USE_ITEM_NEED_STATE_NORMAL_IDLE = 0,
	USE_ITEM_NEED_STATE_SIT_DOWN,
	USE_ITEM_NEED_STATE_MOVING,
	USE_ITEM_NEED_STATE_NORMAL_BATTLE
};

#pragma pack(push, 4)
struct sUSE_ITEM_TBLDAT : public sTBLDAT
{
public:
		
	BYTE			byUse_Item_Active_Type;
	BYTE			byBuff_Group;
	BYTE			byBuffKeepType;
	DWORD			dwCool_Time_Bit_Flag;
	WORD			wFunction_Bit_Flag;
	DWORD			dwRestrictFlag;
	DWORD			dwAllow_Bit_Flag;

	BYTE			byAppoint_Target;
	BYTE			byApply_Target;

	DWORD			dwApply_Target_Index;

	BYTE			byApply_Target_Max;
	BYTE			byApply_Range;
	BYTE			byArea_A1;
	BYTE			byApply_Area2;
	WORD			wNeed_State_Bit_Flag;

	TBLIDX			aSystem_Effect[NTL_MAX_EFFECT_IN_ITEM];
	BYTE			abySystem_Effect_Type[NTL_MAX_EFFECT_IN_ITEM];
	double			afSystem_Effect_Value[NTL_MAX_EFFECT_IN_ITEM];

	DWORD			wRequire_LP;
	WORD			wRequire_EP;
	BYTE			byRequire_RP_Ball;

	float			fCasting_Time;
	DWORD			dwCastingTimeInMilliSecs;
	DWORD			wCool_Time;
	DWORD			dwCoolTimeInMilliSecs;
	DWORD			wKeep_Time;
	DWORD			dwKeepTimeInMilliSecs;

	uint16_t		unkw1;
	uint16_t		pad;
	uint16_t		unkw2;

	BYTE			bKeep_Effect;
	BYTE			byUse_Range_Min;
	BYTE			byUse_Range_Max;

	TBLIDX			Use_Info_Text;
	TBLIDX			Action_Info_Text;

	WCHAR			szCasting_Effect[ DBO_MAX_LENGTH_USE_ITEM_CASTING_EFFECT_NAME + 1 ];
	

	
	ANIMATIONID		wCasting_Animation_Start;
	ANIMATIONID		wCasting_Animation_Loop;
	ANIMATIONID		wAction_Animation_Index;
	ANIMATIONID		wAction_Loop_Animation_Index;
	ANIMATIONID		wAction_End_Animation_Index;

	BYTE			byCastingEffectPosition;
	BYTE			byActionEffectPosition;

	TBLIDX			useWorldIndex;

	float			fUseLoc_X;
	float			fUseLoc_Z;
	float			fUseLoc_Radius;
	QUESTID			RequiredQuestID;

public:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)

enum eUSE_ITEM_FUNCTION
{
	USE_ITEM_FUNCTION_NON_CONSUMABLE = 0,

	USE_ITEM_FUNCTION_COUNT,

	USE_ITEM_FUNCTION_FIRST = USE_ITEM_FUNCTION_NON_CONSUMABLE,
	USE_ITEM_FUNCTION_LAST = USE_ITEM_FUNCTION_NON_CONSUMABLE
};

class CUseItemTable : public CTable
{
public:

	CUseItemTable(void);
	virtual ~CUseItemTable(void);
	
	bool Create(DWORD dwCodePage);
	void Destroy();

protected:
	void Init();

public:
	sTBLDAT *			FindData(TBLIDX tblidx); 
	
protected:
	WCHAR** GetSheetListInWChar() { return &(CUseItemTable::m_pwszSheetList[0]); }
	void* AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage);
	bool DeallocNewTable(void* pvTable, WCHAR* pwszSheetName);
	bool AddTable(void * pvTable, bool bReload);
	bool SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData);


public:

	virtual bool				LoadFromBinary(CNtlSerializer& serializer, bool bReload);

	virtual bool				SaveToBinary(CNtlSerializer& serializer);


private:
	static WCHAR* m_pwszSheetList[];
};