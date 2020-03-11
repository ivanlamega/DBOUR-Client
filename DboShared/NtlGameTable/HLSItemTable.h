//***********************************************************************************
//
//	File		:	HLSItemTable.h
//
//	Begin		:	2009-8-14
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

#include "NtlHlsItem.h"

const DWORD		DBO_MAX_LENGTH_HLSITEM_ID_TEXT = 30;
const DWORD		DBO_MAX_LENGTH_HLSITEM_NAME_TEXT = 26;
const DWORD		DBO_MAX_LENGTH_HLSITEM_ICON_NAME = 32;
const DWORD		DBO_MAX_SUB_ITEM_COUNT = 5;

struct sSUB_ITEM
{
	DWORD	itemTblidx;
	BYTE	byStackCount;
};

#pragma pack(push, 4)
struct sHLS_ITEM_TBLDAT : public sTBLDAT
{
public:
	WCHAR           wszName[DBO_MAX_LENGTH_HLSITEM_NAME_TEXT+1];
	DWORD           Name;
	DWORD           Note;
	WCHAR           wszIcon[DBO_MAX_LENGTH_HLSITEM_ICON_NAME + 1];
	WCHAR           wszCJIProductID[DBO_MAX_LENGTH_HLSITEM_ID_TEXT+1];
	WORD            wHLSItemType;
	BYTE            byHLSDurationType;
	DWORD           dwHLSDurationTime;
	DWORD           dwItemTblidx;
	bool            bOnSale;
	BYTE            bySellType;
	WORD 		    wCash;
	BYTE            byDiscount;    // 할인률
	BYTE            byStackCount;
	WORD            wDisplayBitFlag;        //eHLS_DISPLAY_ITEM_FUNC_BIT_FLAG
	sSUB_ITEM       asSubItem[DBO_MAX_SUB_ITEM_COUNT];
	BYTE            byQuickLink;        //CJ VIP 할인가능한가
	BYTE            byPriority; // CJ VIP 할인률
	BYTE            byDisplayConsumeType;
	BYTE            byYardratTabType;

public:

	virtual int GetDataSize()
	{
		return sizeof(*this) - sizeof(void*);
	}
};
#pragma pack(pop)

class CHLSItemTable : public CTable
{
public:

	CHLSItemTable(void);
	virtual ~CHLSItemTable(void);
	
	bool Create(DWORD dwCodePage);
	void Destroy();

protected:
	void Init();

public:
	sTBLDAT *			FindData(TBLIDX tblidx); 
	
protected:
	WCHAR** GetSheetListInWChar() { return &(CHLSItemTable::m_pwszSheetList[0]); }
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