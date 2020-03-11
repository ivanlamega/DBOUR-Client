#include "precomp_ntlpresentation.h"
#include "NtlPLEntity.h"

// core
#include "NtlDebug.h"

// presentaiton
#include "NtlPLElapsedController.h"
#include "NtlPLSceneManager.h"
#include "NtlPLEntityBlend.h"
#ifdef TW_VER
void CNtlPLEntity::LoadUnknownStructFromFile(FILE *pFile) {
	if (iUnknownShit2 == 0) {
		return;
	}
	pUnknownNewStructIfUnknownShit2IsTrue = new unknownNewStructIfUnknownShit2IsTrue[iUnknownShit2];

	for (int i = 0; i < iUnknownShit2; ++i) {
		auto &pCurrentStruct = pUnknownNewStructIfUnknownShit2IsTrue[i];

		fread(&pCurrentStruct.dwMoreUnknownShit, sizeof pCurrentStruct.dwMoreUnknownShit, 1, pFile);
		fread(&pCurrentStruct.dwMoreUnknownShitNum, sizeof pCurrentStruct.dwMoreUnknownShitNum, 1, pFile);

		pCurrentStruct.pamountOftheseDependOnShitNum = new unknownNewStructIfUnknownShit2IsTrue::amountOftheseDependOnShitNum[pCurrentStruct.dwMoreUnknownShitNum];
		for (unsigned int k = 0; k < pCurrentStruct.dwMoreUnknownShitNum; ++k) {
			auto &pUnknownByNum = pCurrentStruct.pamountOftheseDependOnShitNum[k];


			fread(&pUnknownByNum.dwUnknownShitBool, sizeof pUnknownByNum.dwUnknownShitBool, 1, pFile);

			if (pUnknownByNum.dwUnknownShitBool > 0) {
				pUnknownByNum.pOnlyHereIf_ShitBool_IsTrue =
					new unknownNewStructIfUnknownShit2IsTrue::amountOftheseDependOnShitNum::onlyHereIf_ShitBool_IsTrue[pUnknownByNum.dwUnknownShitBool];

				for (int j = 0; j < pUnknownByNum.dwUnknownShitBool; ++j) {
					auto &pCurrentInnerStruct = pUnknownByNum.pOnlyHereIf_ShitBool_IsTrue[j];
					fread(&pCurrentInnerStruct.uiLength, sizeof pCurrentInnerStruct.uiLength, 1, pFile);
					_ASSERT(pCurrentInnerStruct.uiLength < 128);
					fread(&pCurrentInnerStruct.acName, sizeof pCurrentInnerStruct.acName[0] * pCurrentInnerStruct.uiLength, 1, pFile);
					pCurrentInnerStruct.acName[pCurrentInnerStruct.uiLength] = '\0';

					fread(&pCurrentInnerStruct.uiLength2, sizeof pCurrentInnerStruct.uiLength2, 1, pFile);
					_ASSERT(pCurrentInnerStruct.uiLength2 < 128);
					fread(&pCurrentInnerStruct.acName2, sizeof(pCurrentInnerStruct.acName2[0]) * pCurrentInnerStruct.uiLength2, 1, pFile);
					pCurrentInnerStruct.acName2[pCurrentInnerStruct.uiLength2] = '\0';

					fread(&pCurrentInnerStruct.idkSize, sizeof pCurrentInnerStruct.idkSize, 1, pFile);
					pCurrentInnerStruct.idkArray = new BYTE[pCurrentInnerStruct.idkSize * 8];
					fread(pCurrentInnerStruct.idkArray, 8 * pCurrentInnerStruct.idkSize * sizeof pCurrentInnerStruct.idkArray[0], 1, pFile);
				}
			}

		}
	}


}

void CNtlPLEntity::SaveUnknownStructToFile(FILE *pFile) {
	if (iUnknownShit2 == 0) {
		return;
	}

	for (int i = 0; i < iUnknownShit2; ++i) {
		auto &pCurrentStruct = pUnknownNewStructIfUnknownShit2IsTrue[i];

		fwrite(&pCurrentStruct.dwMoreUnknownShit, sizeof pCurrentStruct.dwMoreUnknownShit, 1, pFile);
		fwrite(&pCurrentStruct.dwMoreUnknownShitNum, sizeof pCurrentStruct.dwMoreUnknownShitNum, 1, pFile);

		for (unsigned int k = 0; k < pCurrentStruct.dwMoreUnknownShitNum; ++k) {
			auto &pUnknownByNum = pCurrentStruct.pamountOftheseDependOnShitNum[k];

			fwrite(&pUnknownByNum.dwUnknownShitBool, sizeof pUnknownByNum.dwUnknownShitBool, 1, pFile);

			if (pUnknownByNum.dwUnknownShitBool > 0) {
				for (int j = 0; j < pUnknownByNum.dwUnknownShitBool; ++j) {
					auto &pCurrentInnerStruct = pUnknownByNum.pOnlyHereIf_ShitBool_IsTrue[j];
					fwrite(&pCurrentInnerStruct.uiLength, sizeof pCurrentInnerStruct.uiLength, 1, pFile);
					fwrite(&pCurrentInnerStruct.acName, sizeof pCurrentInnerStruct.acName[0] * pCurrentInnerStruct.uiLength, 1, pFile);

					fwrite(&pCurrentInnerStruct.uiLength2, sizeof pCurrentInnerStruct.uiLength2, 1, pFile);
					fwrite(&pCurrentInnerStruct.acName2, sizeof(pCurrentInnerStruct.acName2[0]) * pCurrentInnerStruct.uiLength2, 1, pFile);
					fwrite(&pCurrentInnerStruct.idkSize, sizeof pCurrentInnerStruct.idkSize, 1, pFile);
					fwrite(pCurrentInnerStruct.idkArray, 8 * pCurrentInnerStruct.idkSize * sizeof pCurrentInnerStruct.idkArray[0], 1, pFile);
				}
			}
		}
	}
}

void CNtlPLEntity::SkipUnknownStructToFile(BYTE *&pFileMemTmp, RwInt32 dwUnknownShit2) {
	if (dwUnknownShit2 == 0) {
		return;
	}
	unknownNewStructIfUnknownShit2IsTrue *pUnknownNewStructIfUnknownShit2IsTrue = new unknownNewStructIfUnknownShit2IsTrue[dwUnknownShit2];

	for (int i = 0; i < dwUnknownShit2; ++i) {
		auto &pCurrentStruct = pUnknownNewStructIfUnknownShit2IsTrue[i];

		memcpy(&pCurrentStruct.dwMoreUnknownShit, pFileMemTmp, sizeof pCurrentStruct.dwMoreUnknownShit);
		pFileMemTmp += sizeof pCurrentStruct.dwMoreUnknownShit;
		memcpy(&pCurrentStruct.dwMoreUnknownShitNum, pFileMemTmp, sizeof pCurrentStruct.dwMoreUnknownShitNum);
		pFileMemTmp += sizeof pCurrentStruct.dwMoreUnknownShitNum;

		pCurrentStruct.pamountOftheseDependOnShitNum = new unknownNewStructIfUnknownShit2IsTrue::amountOftheseDependOnShitNum[pCurrentStruct.dwMoreUnknownShitNum];
		for (unsigned int k = 0; k < pCurrentStruct.dwMoreUnknownShitNum; ++k) {
			auto &pUnknownByNum = pCurrentStruct.pamountOftheseDependOnShitNum[k];

			memcpy(&pUnknownByNum.dwUnknownShitBool, pFileMemTmp, sizeof pUnknownByNum.dwUnknownShitBool);
			pFileMemTmp += sizeof pUnknownByNum.dwUnknownShitBool;

			if (pUnknownByNum.dwUnknownShitBool > 0) {
				pUnknownByNum.pOnlyHereIf_ShitBool_IsTrue =
					new unknownNewStructIfUnknownShit2IsTrue::amountOftheseDependOnShitNum::onlyHereIf_ShitBool_IsTrue[pUnknownByNum.dwUnknownShitBool];

				for (int j = 0; j < pUnknownByNum.dwUnknownShitBool; ++j) {
					auto &pCurrentInnerStruct = pUnknownByNum.pOnlyHereIf_ShitBool_IsTrue[j];
					memcpy(&pCurrentInnerStruct.uiLength, pFileMemTmp, sizeof pCurrentInnerStruct.uiLength);
					pFileMemTmp += sizeof pCurrentInnerStruct.uiLength;
					//fread(&pCurrentInnerStruct.acName, sizeof pCurrentInnerStruct.acName[0] * pCurrentInnerStruct.uiLength, 1, pFile);
					pFileMemTmp += sizeof pCurrentInnerStruct.acName[0] * pCurrentInnerStruct.uiLength;
					pCurrentInnerStruct.acName[pCurrentInnerStruct.uiLength] = '\0';

					memcpy(&pCurrentInnerStruct.uiLength2, pFileMemTmp, sizeof pCurrentInnerStruct.uiLength2);
					pFileMemTmp += sizeof pCurrentInnerStruct.uiLength2;
					//fread(&pCurrentInnerStruct.acName2, sizeof(pCurrentInnerStruct.acName2[0]) * pCurrentInnerStruct.uiLength2, 1, pFile);
					pFileMemTmp += sizeof(pCurrentInnerStruct.acName2[0]) * pCurrentInnerStruct.uiLength2;
					pCurrentInnerStruct.acName2[pCurrentInnerStruct.uiLength2] = '\0';

					memcpy(&pCurrentInnerStruct.idkSize, pFileMemTmp, sizeof pCurrentInnerStruct.idkSize);
					pFileMemTmp += sizeof pCurrentInnerStruct.idkSize;
					pCurrentInnerStruct.idkArray = new BYTE[pCurrentInnerStruct.idkSize * 8];
					//fread(&pCurrentInnerStruct.idkArray, 8 * pCurrentInnerStruct.idkSize * sizeof pCurrentInnerStruct.idkArray[0], 1, pFile);
					pFileMemTmp += 8 * pCurrentInnerStruct.idkSize * sizeof pCurrentInnerStruct.idkArray[0];
				}

				// Destructor do it
				//delete[] pUnknownByNum.pOnlyHereIf_ShitBool_IsTrue;
			}
		}
		// Destructor do it
		//delete[] pCurrentStruct.pamountOftheseDependOnShitNum;
		//pCurrentStruct.pamountOftheseDependOnShitNum = nullptr;
	}

	//delete[] pUnknownNewStructIfUnknownShit2IsTrue;
	//pUnknownNewStructIfUnknownShit2IsTrue = nullptr;
}
#endif

CNtlPLEntity::CNtlPLEntity() 
{ 
#ifdef dNTL_WORLD_CULLING_NEW
	m_uiRenderFrame		= -1;
#else
	m_uiCullIID			= 0xffffffff;
#endif
	
	m_uiClassID			= PLENTITY_INVALID_TYPE; 
	m_uiLayer			= PLENTITY_LAYER_INVALID;
	m_uiMinimapLayer	= NTL_PLEFLAG_MINIMAP_LAYER_NONE;
	m_uiFlags			= 0; 
	m_uiSID				= 0xffffffff;
	m_uiSerialID		= 0xffffffff;
	m_ObjNameIdx		= 0xffffffff;
	m_byPickOrder		= NTL_PICK_ORDER_NORMAL;

#ifdef TW_VER
	uUnknownUnionShit.dwUnknownShit = 0xFFFFFFFF;
	iUnknownShit2 = 0;
#endif

	m_uiCullFlags		= 0;

	m_fWeightAlpha				= 1.0f;
	m_fWeightElapsedTime		= 1.0f;
	m_fVisibleCullingDistance	= 1512.0f;
	m_pElapController			= NULL;
	m_pBlendController			= NULL;
}


CNtlPLEntity::~CNtlPLEntity()
{
	if(m_pElapController)
	{
		NTL_DELETE(m_pElapController);
	}

	if(m_pBlendController)
	{
		NTL_DELETE(m_pBlendController);
	}

#ifdef TW_VER
	if (pUnknownNewStructIfUnknownShit2IsTrue) {
		delete[] pUnknownNewStructIfUnknownShit2IsTrue;
	}
#endif

}


RwBool CNtlPLEntity::Update(RwReal fElapsed)
{
	if(m_pElapController)
	{
		m_pElapController->Update(fElapsed);
		if(m_pElapController->IsFinish())
		{
			NTL_DELETE(m_pElapController);
		}
	}

	if(m_pBlendController)
	{
		m_pBlendController->Update(fElapsed);        

		if(m_pBlendController->IsFinish())
		{
			NTL_DELETE(m_pBlendController);
		}
	}

	return TRUE;
}

#ifdef dNTL_WORLD_CULLING_NEW
RwBool CNtlPLEntity::CullingTest(RwCamera* pRwCamera, RwUInt16 uiRenderFrame)
{
#ifdef _DEBUG
	++CNtlPLGlobal::m_uiCullTestCnt;
#endif

	// Culiing Test를 시도 한다면 Culling을 사용하겠다는 의미다. 초기값을 변경한다.
	if (m_uiRenderFrame != uiRenderFrame)
	{
		m_uiRenderFrame= uiRenderFrame;
		// PVS Flag는 기존의 내용을 유지 해야 한다.
		// 한 Frame에서 한번만 시도 되어야 하며, 한번만 내용이 적용 되어야 한다.
		m_uiCullFlags &= NTL_PLEFLAG_CULLED_PVS;
	}

	return ((m_uiFlags & NTL_PLEFLAG_NOT_VISIBLE) || (m_uiCullFlags && CNtlPLGlobal::m_UseTerrainPVSMode));
}
#else
RwBool CNtlPLEntity::CullingTest(RwCamera* pRwCamera)
{
#ifdef _DEBUG
	++CNtlPLGlobal::m_uiCullTestCnt;
#endif

	m_uiCullFlags &= NTL_PLEFLAG_CULLED_PVS;
	return ((m_uiFlags & NTL_PLEFLAG_NOT_VISIBLE) || (m_uiCullFlags && CNtlPLGlobal::m_UseTerrainPVSMode));
}
#endif

/*RwBool CNtlPLEntity::CullingTest(RwCamera* pRwCamera, const RpAtomic* pAtomic)
{
	if ((m_uiFlags & NTL_PLEFLAG_NOT_VISIBLE) || (m_uiCullFlags && CNtlPLGlobal::m_UseTerrainPVSMode))
	{
		return TRUE;
	}
	else if (!RwCameraFrustumTestSphere(pRwCamera, &pAtomic->worldBoundingSphere))
	{
		return TRUE;
	}
	return FALSE;
}*/


void CNtlPLEntity::SetWeightAlpha(RwReal fWeightValue)
{
	m_fWeightAlpha = fWeightValue;
}

void CNtlPLEntity::SetVisibleCullingDistance(RwReal fDistance)
{
	/*
#define LIMIT_DISTANCE_FILTER_DIST	450.0f

	if(m_uiClassID != PLENTITY_OBJECT)
		m_fVisibleCullingDistance = fDistance; 
	else
	{
		if(m_fVisibleCullingDistance > LIMIT_DISTANCE_FILTER_DIST)
			if(fDistance < LIMIT_DISTANCE_FILTER_DIST)
				GetSceneManager()->AddDistanceFilter(this);
		else
			if(fDistance > LIMIT_DISTANCE_FILTER_DIST)
				GetSceneManager()->RemoveDistanceFilter(this);

		m_fVisibleCullingDistance = fDistance;
	}
	*/

	m_fVisibleCullingDistance = fDistance;
}

CNtlPLEntityBlendController* CNtlPLEntity::GetAlphaBlendController(void)
{
	if(!m_pBlendController)
	{
		m_pBlendController = NTL_NEW CNtlPLEntityBlendController(this);
	}

	return m_pBlendController;
}

void CNtlPLEntity::CreateWeightElapsedController(RwReal fLifeTime, RwReal fWeightValue) 
{
	if(!m_pElapController)
	{
		m_pElapController = NTL_NEW CNtlElapsedControllerGroup;
		m_pElapController->SetControlEntity(this);
	}

	m_pElapController->CreateController(fLifeTime, fWeightValue);
}


void CNtlPLEntity::DeleteWeightElapsedController(void)
{
	if(m_pElapController)
	{
		NTL_DELETE(m_pElapController);
	}
}