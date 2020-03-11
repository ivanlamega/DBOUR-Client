#pragma once

#include "Table.h"
#include "NPCTable.h"

enum eMOB_PROPERTY_TYPE
{
	MOB_PROPERTY_DUNGEON_BOSS,	
	MOB_PROPERTY_NONE = 0xFF
};

// MOB
#pragma pack(push, 4)
struct bBoxData {
	TBLIDX big_bag_idx;
	BYTE drop_rate;
	BYTE try_count;
};
struct sMOB_TBLDAT : public sBOT_TBLDAT
{
public:
	DWORD			dwMobGroup;		
	WORD			wMob_Kind;
	DWORD			dwDrop_Zenny;
	float			fDrop_Zenny_Rate;
	WORD			wExp;
	BYTE			byGrade;
	BYTE			unknown;

	BYTE			byMob_Type;
	TBLIDX			drop_Item_Tblidx;

	bool			bSize;
	WORD			wTMQPoint;
	
	TBLIDX			dropQuestTblidx;
	bBoxData		drop_big_box[3];

	DWORD			scan_range_show;
	BYTE			byProperty;
	BYTE			KDBlockRate;
	BYTE			byHtbBlockRate;

	WORD			wSightAngle;
	DWORD			immunityBitFlag;
	bool			canDragonballDrop;
	WORD			wClass;
	WORD			wUseRace;

	float			rewardExpRate;
	float			rewardZennyRate;

	DWORD			formulaOffset;

	float			setting_rate_lp;
	float			setting_rate_lp_regen;

	float			setting_rate_phy_offence;
	float			setting_rate_eng_offence;

	float			setting_rate_phy_defence;
	float			setting_rate_eng_defence;

	float			setting_rate_attack_rate;
	float			setting_rate_dodge_rate;

	float			setting_phy_offence_rate;
	float			setting_eng_offence_rate;

	float			setting_defence_rate;


public:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)

class CMobTable : public CTable
{
public:
	typedef std::map<DWORD, TBLIDX> MOB_TABLE;
	typedef MOB_TABLE::iterator MOB_TABLEIT;
	typedef MOB_TABLE::value_type MOB_TABLEVAL;

public:
	CMobTable(void);
public:
	virtual ~CMobTable(void);

	bool Create(DWORD dwCodePage);
	void Destroy();

protected:
	void Init();

public:
	MOB_TABLEIT	MobBegin() { return m_mapMobTableList.begin(); }
	MOB_TABLEIT	MobEnd() { return m_mapMobTableList.end(); }

	sTBLDAT *			FindData(TBLIDX tblidx); 
	TBLIDX				FindTblidxByGroup(DWORD dwMobGroup); 
protected:
	WCHAR** GetSheetListInWChar() { return &(CMobTable::m_pwszSheetList[0]); }
	void* AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage);
	bool DeallocNewTable(void* pvTable, WCHAR* pwszSheetName);
	bool AddTable(void * pvTable, bool bReload);
	bool SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData);

public:

	virtual bool				LoadFromBinary(CNtlSerializer& serializer, bool bReload);

	virtual bool				SaveToBinary(CNtlSerializer& serializer);


private:
	static WCHAR* m_pwszSheetList[];
	MOB_TABLE			m_mapMobTableList;
};
