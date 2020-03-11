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

#include "stdafx.h"
#include "HLSItemTable.h"
#include "NtlDebug.h"
#include "NtlBattle.h"
#include "NtlSerializer.h"

//- yoshiki : Let's consider of implementing NtlAssert series.
//#include "NtlAssert.h"

WCHAR* CHLSItemTable::m_pwszSheetList[] =
{
	L"Table_Data_KOR",
	NULL
};

CHLSItemTable::CHLSItemTable(void)
{
	Init();
}

CHLSItemTable::~CHLSItemTable(void)
{
	Destroy();
}

bool CHLSItemTable::Create(DWORD dwCodePage)
{
	return CTable::Create(dwCodePage);
}

void CHLSItemTable::Destroy()
{
	CTable::Destroy();
}

void CHLSItemTable::Init()
{
}

void* CHLSItemTable::AllocNewTable(WCHAR* pwszSheetName, DWORD dwCodePage)
{
	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sHLS_ITEM_TBLDAT* pNewItem = new sHLS_ITEM_TBLDAT;
		if (NULL == pNewItem)
			return NULL;

		CPINFO cpInfo;
		if(false == GetCPInfo(dwCodePage, &cpInfo))
		{
			delete pNewItem;
			return NULL;
		}
		
		m_dwCodePage = dwCodePage;
		return pNewItem;
	}

	return NULL;
}

bool CHLSItemTable::DeallocNewTable(void* pvTable, WCHAR* pwszSheetName)
{
	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sHLS_ITEM_TBLDAT* pItem = (sHLS_ITEM_TBLDAT*)pvTable;
		if (FALSE != IsBadReadPtr(pItem, sizeof(*pItem)))
			return false;

		delete pItem;

		return true;
	}

	return false;
}

bool CHLSItemTable::AddTable(void * pvTable, bool bReload)
{
	sHLS_ITEM_TBLDAT * pTbldat = (sHLS_ITEM_TBLDAT*) pvTable;
	sHLS_ITEM_TBLDAT * pExistTbldat = NULL;
		
	if( bReload )
	{
		pExistTbldat = (sHLS_ITEM_TBLDAT*) FindData( pTbldat->tblidx );
		if( pExistTbldat )
		{
			CopyMemory( pTbldat, pExistTbldat, pTbldat->GetDataSize() );
			// 데이타의 리로드 성공을 위한 true 반환
			return true;  
		}
	}

	if ( false == m_mapTableList.insert( std::map<TBLIDX, sTBLDAT*>::value_type(pTbldat->tblidx, pTbldat)).second )
	{
		CTable::CallErrorCallbackFunction(L"[File] : %s\r\n Table Tblidx[%u] is Duplicated ",m_wszXmlFileName, pTbldat->tblidx );
		_ASSERTE( 0 );
		return false;
	}


	return true;
}

bool CHLSItemTable::SetTableData(void* pvTable, WCHAR* pwszSheetName, std::wstring* pstrDataName, BSTR bstrData)
{

	if (0 == wcscmp(pwszSheetName, L"Table_Data_KOR"))
	{
		sHLS_ITEM_TBLDAT* pItem = (sHLS_ITEM_TBLDAT*)pvTable;

		if (0 == wcscmp(pstrDataName->c_str(), L"Tblidx"))
		{
			CheckNegativeInvalid( pstrDataName->c_str(), bstrData );
			pItem->tblidx = READ_DWORD( bstrData );
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Name_Text"))
		{
			CheckNegativeInvalid( pstrDataName->c_str(), bstrData );
			READ_STRINGW(bstrData, pItem->wszName, _countof(pItem->wszName));
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Name"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->Name = READ_DWORD(bstrData);
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Note"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->Note = READ_DWORD(bstrData);
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Icon_Name"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			READ_STRINGW(bstrData, pItem->wszIcon, _countof(pItem->wszIcon));
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"CJI_Product_ID"))
		{
			CheckNegativeInvalid( pstrDataName->c_str(), bstrData );
			READ_STRINGW(bstrData, pItem->wszCJIProductID, _countof(pItem->wszCJIProductID));
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"HLS_Item_Type"))
		{
			CheckNegativeInvalid( pstrDataName->c_str(), bstrData );
			pItem->wHLSItemType = READ_WORD(bstrData, pstrDataName->c_str());
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"HLS_Duration_Type"))
		{
			CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
			pItem->byHLSDurationType = READ_BYTE(bstrData, pstrDataName->c_str());
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"HLS_Duration_Time"))
		{
			if (CheckInvalidValue(bstrData))
			{
				pItem->dwHLSDurationTime = INVALID_DWORD;
			}
			else
			{
				CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
				pItem->dwHLSDurationTime = READ_DWORD(bstrData);
			}
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Item_Tblidx"))
		{
			if (CheckInvalidValue(bstrData))
			{
				pItem->dwItemTblidx = INVALID_DWORD;
			}
			else
			{
				CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
				pItem->dwItemTblidx = READ_DWORD(bstrData);
			}
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"On_Sale"))
		{
			CheckNegativeInvalid( pstrDataName->c_str(), bstrData );
			pItem->bOnSale = READ_BOOL(bstrData, pstrDataName->c_str());
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Sell_Type"))
		{
			if (CheckInvalidValue(bstrData))
			{
				pItem->bySellType = INVALID_BYTE;
			}
			else
			{
				CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
				pItem->bySellType = READ_BYTE(bstrData, pstrDataName->c_str());
			}
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Cash"))
		{
			if (CheckInvalidValue(bstrData))
			{
				pItem->wCash = INVALID_WORD;
			}
			else
			{
				CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
				pItem->wCash = READ_WORD(bstrData, pstrDataName->c_str());
			}
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Discount"))
		{
			if (CheckInvalidValue(bstrData))
			{
				pItem->byDiscount = INVALID_BYTE;
			}
			else
			{
				CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
				pItem->byDiscount = READ_BYTE(bstrData, pstrDataName->c_str());
			}
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Item_Stack_Count"))
		{
			if (CheckInvalidValue(bstrData))
			{
				pItem->byStackCount = INVALID_BYTE;
			}
			else
			{
				CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
				pItem->byStackCount = READ_BYTE(bstrData, pstrDataName->c_str());
			}
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Display_Bit_Flag"))
		{
			if (CheckInvalidValue(bstrData))
			{
				pItem->wDisplayBitFlag = INVALID_WORD;
			}
			else
			{
				CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
				pItem->wDisplayBitFlag = READ_WORD(bstrData, pstrDataName->c_str());
			}
		}
		else if ( 0 == wcsncmp(pstrDataName->c_str(), L"Sub_Item_Tblidx_", wcslen(L"Sub_Item_Tblidx_") ) )
		{
			bool bFound = false;

			WCHAR szBuffer[1024] = { 0x00, };
			for( int i = 0; i < DBO_MAX_COUNT_HLSITEM_SUB_ITEM; i++ )
			{
				swprintf( szBuffer, 1024, L"Sub_Item_Tblidx_%d", i + 1 );

				if( 0 == wcscmp(pstrDataName->c_str(), szBuffer) )
				{
					if (CheckInvalidValue(bstrData))
					{
						pItem->asSubItem[i].itemTblidx = INVALID_DWORD;
					}
					else
					{
						pItem->asSubItem[i].itemTblidx = READ_DWORD(bstrData);
					}

					bFound = true;
					break;
				}
			}

			if( false == bFound )
			{
				CTable::CallErrorCallbackFunction(L"[File] : %s\n[Error] : Unknown field name found!(Field Name = %s)", m_wszXmlFileName, pstrDataName->c_str());
				return false;
			}
		}
		else if ( 0 == wcsncmp(pstrDataName->c_str(), L"Sub_Item_Count_", wcslen(L"Sub_Item_Count_") ) )
		{
			bool bFound = false;

			WCHAR szBuffer[1024] = { 0x00, };
			for( int i = 0; i < DBO_MAX_COUNT_HLSITEM_SUB_ITEM; i++ )
			{
				swprintf( szBuffer, 1024, L"Sub_Item_Count_%d", i + 1 );

				if( 0 == wcscmp(pstrDataName->c_str(), szBuffer) )
				{
					if (CheckInvalidValue(bstrData))
					{
						pItem->asSubItem[i].byStackCount = INVALID_BYTE;
					}
					else
					{
						pItem->asSubItem[i].byStackCount = READ_BYTE(bstrData, pstrDataName->c_str());
					}

					bFound = true;
					break;
				}
			}

			if( false == bFound )
			{
				CTable::CallErrorCallbackFunction(L"[File] : %s\n[Error] : Unknown field name found!(Field Name = %s)", m_wszXmlFileName, pstrDataName->c_str());
				return false;
			}
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Quick_Link"))
		{
			if (CheckInvalidValue(bstrData))
			{
				pItem->byQuickLink = INVALID_BYTE;
			}
			else
			{
				CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
				pItem->byQuickLink = READ_BYTE(bstrData, pstrDataName->c_str());
			}			
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Priority"))
		{
			if (CheckInvalidValue(bstrData))
			{
				pItem->byPriority = INVALID_BYTE;
			}
			else
			{
				CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
				pItem->byPriority = READ_BYTE(bstrData, pstrDataName->c_str());
			}			
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Display_Consume_Type"))
		{
			if (CheckInvalidValue(bstrData))
			{
				pItem->byDisplayConsumeType = INVALID_BYTE;
			}
			else
			{
				CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
				pItem->byDisplayConsumeType = READ_BYTE(bstrData, pstrDataName->c_str());
			}			
		}
		else if (0 == wcscmp(pstrDataName->c_str(), L"Yardrat_Tab_Type"))
		{
			if (CheckInvalidValue(bstrData))
			{
				pItem->byYardratTabType = INVALID_BYTE;
			}
			else
			{
				CheckNegativeInvalid(pstrDataName->c_str(), bstrData);
				pItem->byYardratTabType = READ_BYTE(bstrData, pstrDataName->c_str());
			}			
		}
		else
		{
			CTable::CallErrorCallbackFunction(L"[File] : %s\n[Error] : Unknown field name found!(Field Name = %s)", m_wszXmlFileName, pstrDataName->c_str());
			return false;
		}
	}
	else
	{
		return false;
	}

	return true;
}


sTBLDAT* CHLSItemTable::FindData(TBLIDX tblidx)
{
	if (0 == tblidx)
		return NULL;

	TABLEIT iter;
	iter = m_mapTableList.find(tblidx);
	if (End() == iter)
		return NULL;
	
	return (sTBLDAT*)(iter->second); 
}

bool CHLSItemTable::LoadFromBinary(CNtlSerializer& serializer, bool bReload)
{
	if( false == bReload )
	{
		Reset();
	}

	BYTE byMargin = 1;
	serializer >> byMargin;

	bool bLoop = true;
	do
	{
		sHLS_ITEM_TBLDAT* pTableData = new sHLS_ITEM_TBLDAT;
		if (NULL == pTableData)
		{
			//- yoshiki : To log system!
			Destroy();
			return false;
		}

		if (false == pTableData->LoadFromBinary(serializer))
		{
			delete pTableData;
			bLoop = false;
			break;
		}

		//  [4/26/2008 zeroera] : 설명 : 실패하더라도 Load의 종료여부는 File Loading에서 결정한다
		if( false == AddTable(pTableData, bReload) )
		{
			delete pTableData;
		}

	} while (false != bLoop);

	return true;
}

bool CHLSItemTable::SaveToBinary(CNtlSerializer& serializer)
{
	serializer.Refresh();

	BYTE byMargin = 1;
	serializer << byMargin;

	TABLE::iterator iter;
	for (iter = Begin() ; End() != iter ; iter++)
	{
		sHLS_ITEM_TBLDAT* pTableData = (sHLS_ITEM_TBLDAT*)(iter->second);

		pTableData->SaveToBinary(serializer);
	}

	return true;
}
