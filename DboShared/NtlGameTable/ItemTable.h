//***********************************************************************************
//
//	File		:	ItemTable.h
//
//	Begin		:	2006-03-09
//
//	Copyright	:	ⓒ NTL-Inc Co., Ltd
//
//	Author		:	Chung Doo sup   ( john@ntl-inc.com )
//
//	Desc		:	
//
//***********************************************************************************

#pragma once

#include "Table.h"
#include "NtlItem.h"
// Hard Coding
#define	HOIPOISTONE_ITEM_INDEX	19954

const DWORD		DBO_MAX_LENGTH_ITEM_NAME_TEXT = 32;
const DWORD		DBO_MAX_LENGTH_ITEM_ICON_NAME = 32;
const DWORD		DBO_MAX_LENGTH_ITEM_MODEL_NAME = 32;
const DWORD		DBO_MAX_LENGTH_ITEM_SUBWEAPON_ACT_MODEL_NAME = 32;

#pragma pack(push, 4)
struct sITEM_TBLDAT : public sTBLDAT
{
	sITEM_TBLDAT()
	{
		bValidity_Able = true;
	};

public:
	//	TBLIDX			Name;
	//	WCHAR			wszNameText[ 20 + 1 ];
	//	bool			bValidity_Able;
	////	std::string		strIcon_Name;
	//	char			szIcon_Name[ DBO_MAX_LENGTH_ITEM_ICON_NAME + 1 ];
	//	BYTE			byModel_Type;
	////	std::string		strModel;
	//	char			szModel[ DBO_MAX_LENGTH_ITEM_MODEL_NAME + 1 ];
	////	std::string		strSub_Weapon_Act_Model;
	//	char			szSub_Weapon_Act_Model[ DBO_MAX_LENGTH_ITEM_SUBWEAPON_ACT_MODEL_NAME + 1 ];
	//	BYTE			byItem_Type;
	//	BYTE			byEquip_Type;
	//	DWORD			wEquip_Slot_Type_Bit_Flag;		// Now a Dword 
	//	WORD			wFunction_Bit_Flag;
	//	BYTE			byRestrictType;
	//
	//	BYTE			byMax_Stack;
	//	BYTE			byRank;
	//	WORD			wWeight;
	//	DWORD			dwCost;
	//	BYTE			bySell_Price;
	//	BYTE			byDurability;
	//	BYTE			byDropVisual;
	//	BYTE			byDurability_Count;
	//	BYTE			byBattle_Attribute;
	//
	//	WORD			wPhysical_Offence;
	//	WORD			wEnergy_Offence;
	//	WORD			wPhysical_Defence;
	//	WORD			wEnergy_Defence;
	//
	//
	//	float			fAttack_Range_Bonus;
	//	WORD			wAttack_Speed_Rate;  // 애니메이 속도에 대한 %
	//	BYTE			byNeed_Level;
	//	BYTE			byNeed_Max_Level;
	//	DWORD			dwNeed_Class_Bit_Flag;
	//	DWORD			dwNeed_Gender_Bit_Flag;
	//	BYTE			byClass_Special;
	//	BYTE			byRace_Special;
	//	BYTE			byNeed_Str;
	//	BYTE			byNeed_Con;
	//	BYTE			byNeed_Foc;
	//	BYTE			byNeed_Dex;
	//	BYTE			byNeed_Sol;
	//	BYTE			byNeed_Eng;
	//	TBLIDX			set_Item_Tblidx;
	//	TBLIDX			Note;
	//	BYTE			byBag_Size;
	//	WORD			wScouter_Watt;	
	//	DWORD			dwScouter_MaxPower;
	//	BYTE			byScouter_Parts_Type;
	//	TBLIDX			Use_Item_Tblidx;
	//	TBLIDX			Item_Option_Tblidx;
	//	BYTE			bCanHaveOption;
	//	BYTE			byItemGroup;
	//	TBLIDX			Charm_Tblidx;
	//	WORD			wCostumeHideBitFlag;
	//	TBLIDX			NeedItemTblidx;		// 천하제일무도회 상점에서 구매에 필요한 아이템
	//	DWORD			CommonPoint;		// 무도사포인트, NetPY
	//	BYTE			byCommonPointType;
	//	BYTE			byNeedFunction;
	//	DWORD			dwUseDurationMax;	//아이템 최대 사용기간 ( 초 단위 )
	//	BYTE			byDurationType;		//eDURATIONTYPE
	//	BYTE			bCanRenew;
	//	TBLIDX			contentsTblidx;
	//	DWORD			dwDurationGroup;	// 같은 종류의 기간제 아이템인지를 나타내는 그룹
	//	WORD			dropLevel;
	//	DWORD			CreateEnchanteRateTblidx;
	//	DWORD			ExcellentTblidx;
	//	DWORD			RareTblidx;
	//	DWORD			LegendaryTblidx;
	//	bool			CreateSuperiorAble;
	//	bool			CreateExcellentAble;
	//	bool			CreateRareAble;
	//	bool			CreateLegendaryAble;
	//	FLOAT			fAtkPhy;
	//	FLOAT			fAtkEng;
	//	FLOAT			fDefPhy;
	//	FLOAT			fDefEng;
	//	BYTE			ScouterPartsType2;
	//	BYTE			ScouterPartsType3;
	//	BYTE			ScouterPartsType4;
	//	BYTE			TMPCategoryType;
	//	WORD			DisassembleBitFlag;
	//	BYTE			NormalMin;
	//	BYTE			NormalMax;
	//	BYTE			RankupMin;
	//	BYTE			RankupMax;

	//TW Table Structure
	bool			bValidity_Able;

	TBLIDX			Name;

	WCHAR			wszNameText[DBO_MAX_LENGTH_ITEM_NAME_TEXT + 1];
	char			szIcon_Name[DBO_MAX_LENGTH_ITEM_ICON_NAME + 1];
	BYTE			byModel_Type;
	char			szModel[DBO_MAX_LENGTH_ITEM_MODEL_NAME + 1];
	char			szSub_Weapon_Act_Model[DBO_MAX_LENGTH_ITEM_SUBWEAPON_ACT_MODEL_NAME + 1];

	BYTE			byItem_Type;
	BYTE			byEquip_Type;
	DWORD			wEquip_Slot_Type_Bit_Flag;		// Now a Dword 
	WORD			wFunction_Bit_Flag;

	BYTE			byMax_Stack;
	BYTE			byRank;
	DWORD			wWeight;
	DWORD			dwCost;
	DWORD			bySell_Price;
	BYTE			byDurability;
	//
	BYTE			byDurability_Count;
	BYTE			byBattle_Attribute;
	WORD			wPhysical_Offence;
	WORD			wEnergy_Offence;
	WORD			wPhysical_Defence;
	WORD			wEnergy_Defence;

	float			fAttack_Range_Bonus;
	WORD			wAttack_Speed_Rate;
	BYTE			byNeed_Level;
	BYTE			byNeed_Max_Level;
	DWORD			dwNeed_Class_Bit_Flag;
	DWORD			dwNeed_Gender_Bit_Flag;
	BYTE			byClass_Special;
	BYTE			byRace_Special;
	WORD			byNeed_Str;
	WORD			byNeed_Con;
	WORD			byNeed_Foc;
	WORD			byNeed_Dex;
	WORD			byNeed_Sol;
	WORD			byNeed_Eng;
	TBLIDX			set_Item_Tblidx;
	TBLIDX			Note;
	BYTE			byBag_Size;
	WORD			wScouter_Watt;
	DWORD			dwScouter_MaxPower;
	BYTE			byScouter_Parts_Type;
	BYTE			ScouterPartsType2;
	BYTE			ScouterPartsType3;
	BYTE			ScouterPartsType4;

	TBLIDX			Use_Item_Tblidx;
	BYTE			bCanHaveOption;
	TBLIDX			Item_Option_Tblidx;

	BYTE			byItemGroup;
	TBLIDX			Charm_Tblidx;
	WORD			wCostumeHideBitFlag;
	TBLIDX			NeedItemTblidx;
	DWORD			CommonPoint;
	BYTE			byCommonPointType;
	BYTE			byNeedFunction;
	DWORD			dwUseDurationMax;
	BYTE			byDurationType;		//eDURATIONTYPE
	TBLIDX			contentsTblidx;
	DWORD			dwDurationGroup;
	WORD			dropLevel;
	DWORD			CreateEnchanteRateTblidx;
	DWORD			ExcellentTblidx;
	DWORD			RareTblidx;
	DWORD			LegendaryTblidx;
	bool			CreateSuperiorAble;
	bool			CreateExcellentAble;
	bool			CreateRareAble;
	bool			CreateLegendaryAble;
	BYTE			byRestrictType;

	FLOAT			fAtkPhy;
	FLOAT			fAtkEng;
	FLOAT			fDefPhy;
	FLOAT			fDefEng;

	BYTE			TMPCategoryType;
	BYTE			bCanRenew;
	WORD			DisassembleBitFlag;

	BYTE			NormalMin;
	BYTE			NormalMax;
	BYTE			RankupMin;
	BYTE			RankupMax;

	BYTE			bCanDisassemble;
	BYTE			byDropVisual;
public:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)
class CItemTable : public CTable
{
public:

	CItemTable(void);
	virtual ~CItemTable(void);

	bool Create(DWORD dwCodePage);
	void Destroy();


protected:
	void Init();

public:
	sTBLDAT* FindData(TBLIDX tblidx);

protected:
	WCHAR** GetSheetListInWChar() { return &(CItemTable::m_pwszSheetList[0]); }
	void* AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage);
	bool DeallocNewTable(void* pvTable, WCHAR* pwszSheetName);
	bool AddTable(void* pvTable, bool bReload);
	bool SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData);

public:
	virtual bool				LoadFromBinary(CNtlSerializer& serializer, bool bReload);
	virtual bool				SaveToBinary(CNtlSerializer& serializer);

private:
	static WCHAR* m_pwszSheetList[];
};