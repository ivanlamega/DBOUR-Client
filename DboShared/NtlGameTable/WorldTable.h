//***********************************************************************************
//
//	File		:	WorldTable.h
//
//	Begin		:	2006-03-09
//
//	Copyright	:	¨Ï NTL-Inc Co., Ltd
//
//	Author		:	Hyun Woo, Koo   ( zeroera@ntl-inc.com )
//
//	Desc		:	
//
//***********************************************************************************

#pragma once

#include "Table.h"
#include "NtlVector.h"

const DWORD		DBO_MAX_LENGTH_WORLD_NAME = 32;
const DWORD		DBO_MAX_LENGTH_WORLD_NAME_IN_UNICODE = 32;
const DWORD		DBO_MAX_LENGTH_WORLD_MOB_SPAWN_TABLE_NAME = 64;
const DWORD		DBO_MAX_LENGTH_WORLD_NPC_SPAWN_TABLE_NAME = 64;
const DWORD		DBO_MAX_LENGTH_WORLD_OBJ_SPAWN_TABLE_NAME = 64;
const DWORD		DBO_MAX_LENGTH_WORLD_RESOURCE_FOLDER_NAME = 64;
const DWORD		DBO_MAX_LENGTH_WORLD_RESOURCE_FLASH_NAME = 32;

#pragma pack(push, 4)
struct sWORLD_TBLDAT : public sTBLDAT
{
public:

	char			szName[DBO_MAX_LENGTH_WORLD_NAME + 1];

	WCHAR			wszName[DBO_MAX_LENGTH_WORLD_NAME_IN_UNICODE + 1];
	bool			bDynamic;
	DWORD			nCreateCount;
	DWORD			CreateCountShareGroup;
	BYTE			byDoorType;

	DWORD			dwDestroyTimeInMilliSec;

	WCHAR			wszMobSpawn_Table_Name[DBO_MAX_LENGTH_WORLD_MOB_SPAWN_TABLE_NAME + 1];
	WCHAR			wszNpcSpawn_Table_Name[DBO_MAX_LENGTH_WORLD_NPC_SPAWN_TABLE_NAME + 1];
	WCHAR			wszObjSpawn_Table_Name[DBO_MAX_LENGTH_WORLD_OBJ_SPAWN_TABLE_NAME + 1];

	CNtlVector			vStart;
	CNtlVector			vEnd;
	CNtlVector			vStandardLoc;
	CNtlVector			vBattleStartLoc;
	CNtlVector			vBattleEndLoc;
	CNtlVector			vOutSideBattleStartLoc;
	CNtlVector			vOutSideBattleEndLoc;
	CNtlVector			vSpectatorStartLoc;
	CNtlVector			vSpectatorEndLoc;
	CNtlVector			vDefaultLoc;
	CNtlVector			vDefaultDir;
	CNtlVector			vStart1Loc;
	CNtlVector			vStart1Dir;
	CNtlVector			vStart2Loc;
	CNtlVector			vStart2Dir;

	CNtlVector			vWait1Loc;
	CNtlVector			vWait1Dir;

	CNtlVector			vWait2Loc;
	CNtlVector			vWait2Dir;
	
	CNtlVector			vWait3Loc;
	CNtlVector			vWait3Dir;

	float			fSplitSize;
	bool			bNight_Able;
	BYTE			byStatic_Time;
	WORD			wFuncFlag;

	BYTE			byWorldRuleType;	// eGAMERULE_TYPE
	TBLIDX			worldRuleTbldx;

	// outWorldTblidx = World id when exiting the current world, (Dojo001 out world id : 1)
	TBLIDX			outWorldTblidx;
	CNtlVector			outWorldLoc;
	CNtlVector			outWorldDir;
	WCHAR			wszResourceFolder[DBO_MAX_LENGTH_WORLD_RESOURCE_FOLDER_NAME + 1];
	float			fBGMRestTime;
	DWORD			dwWorldResourceID;
	float			fFreeCamera_Height;

	WCHAR			wszEnterResourceFlash[DBO_MAX_LENGTH_WORLD_RESOURCE_FLASH_NAME + 1];
	WCHAR			wszLeaveResourceFlash[DBO_MAX_LENGTH_WORLD_RESOURCE_FLASH_NAME + 1];

	TBLIDX			wpsLinkIndex;

	BYTE			byStartPointRange;
	BYTE			byDragonballHaveRate[5];
	BYTE			byDragonballDropRate[5];

	DWORD			dwProhibititedFlag;
protected:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)

class CWorldTable : public CTable
{
public:

	CWorldTable(void);
	virtual ~CWorldTable(void);

/*
public:

	BOOL				Check() { return TRUE; }*/

	bool Create(DWORD dwCodePage);
	void Destroy();

protected:
	void Init();

public:
	sTBLDAT *			FindData(TBLIDX tblidx); 
	
protected:
	WCHAR** GetSheetListInWChar() { return &(CWorldTable::m_pwszSheetList[0]); }
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
