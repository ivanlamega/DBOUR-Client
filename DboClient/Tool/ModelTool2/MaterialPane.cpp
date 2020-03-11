// MaterialPane.cpp : implementation file
//

#include "stdafx.h"
#include "ModelTool2.h"
#include "MaterialPane.h"
#include <filesystem>
CMaterialPane* CMaterialPane::m_pInstance = NULL;

// CMaterialPane

IMPLEMENT_DYNCREATE(CMaterialPane, CXTResizeFormView)

CMaterialPane::CMaterialPane()
	: CXTResizeFormView(CMaterialPane::IDD)
{
    m_pInstance = this;
    m_pMTClump = NULL;
}

CMaterialPane::~CMaterialPane()
{
}

void CMaterialPane::DoDataExchange(CDataExchange* pDX)
{
    CXTResizeFormView::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST_MATERIAL, m_listBoxMaterial);
	DDX_Control(pDX, IDC_MATERIAL_FLAGS, m_listBoxMaterialFlags);
    DDX_Control(pDX, IDC_EDIT_NAME, m_editTextureName);
    DDX_Control(pDX, IDC_EDIT_SIZE, m_editTextureSize);
    DDX_Control(pDX, IDC_BT_MATERIAL_ADD, m_btTextureAdd);
    DDX_Control(pDX, IDC_BT_MATERIAL_DEL, m_btTextureDelete);
	DDX_Control(pDX, IDC_FLAGGROUP, m_groupFlag);
	DDX_Control(pDX, IDC_SETFLAG, m_btnFlagSet);
}

BEGIN_MESSAGE_MAP(CMaterialPane, CXTResizeFormView)
	ON_LBN_SELCHANGE(IDC_LIST_MATERIAL, &CMaterialPane::OnLbnSelchangeListMaterial)
	ON_BN_CLICKED(IDC_BT_MATERIAL_ADD, &CMaterialPane::OnBnClickedBtMaterialAdd)
	ON_BN_CLICKED(IDC_BT_MATERIAL_DEL, &CMaterialPane::OnBnClickedBtMaterialDel)
	ON_BN_CLICKED(IDC_SETFLAG, &CMaterialPane::OnBtnClickedSetFlag)
END_MESSAGE_MAP()


// CMaterialPane diagnostics

#ifdef _DEBUG
void CMaterialPane::AssertValid() const
{
	CXTResizeFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMaterialPane::Dump(CDumpContext& dc) const
{
	CXTResizeFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMaterialPane message handlers

void CMaterialPane::OnInitialUpdate()
{
    CXTResizeFormView::OnInitialUpdate();

    SetResize(IDC_FRAME_MATERIAL, SZ_TOP_LEFT, SZ_BOTTOM_RIGHT);
    SetResize(IDC_LIST_MATERIAL, SZ_TOP_LEFT, SZ_BOTTOM_RIGHT);
    SetResize(IDC_STATIC_MULTI_TEXTURE, SZ_BOTTOM_LEFT, SZ_BOTTOM_RIGHT);
    SetResize(IDC_ST_NAME, SZ_BOTTOM_LEFT, SZ_BOTTOM_LEFT);
    SetResize(IDC_ST_SIZE, SZ_BOTTOM_LEFT, SZ_BOTTOM_LEFT);
    SetResize(IDC_EDIT_NAME, SZ_BOTTOM_LEFT, SZ_BOTTOM_RIGHT);
    SetResize(IDC_EDIT_SIZE, SZ_BOTTOM_LEFT, SZ_BOTTOM_RIGHT);
    SetResize(IDC_BT_MATERIAL_ADD, SZ_BOTTOM_LEFT, SZ_BOTTOM_LEFT);
    SetResize(IDC_BT_MATERIAL_DEL, SZ_BOTTOM_LEFT, SZ_BOTTOM_LEFT);

    SetClump(NULL);
}

void CMaterialPane::SetClump(CMTClump* pMTClump)
{
    if(!pMTClump)
    {
        m_pMTClump = NULL;        
        SetEnable(FALSE);
    }
    else
    {
        m_pMTClump = pMTClump;
        OnDataUpdate();
        SetEnable(TRUE);
    }
}

void CMaterialPane::SetEnable(BOOL bEnable)
{
    if(bEnable == FALSE)
    {
        m_listBoxMaterial.ResetContent();
		m_listBoxMaterialFlags.ResetContent();
        m_editTextureName.SetWindowText(L"");
        m_editTextureSize.SetWindowText(L"");
    }

    m_listBoxMaterial.EnableWindow(bEnable);
	m_listBoxMaterialFlags.EnableWindow(bEnable);
    m_editTextureName.EnableWindow(bEnable);
    m_editTextureSize.EnableWindow(bEnable);
    m_btTextureAdd.EnableWindow(bEnable);
    m_btTextureDelete.EnableWindow(bEnable);
}

std::vector<char*> getMaterialFlags(RpMaterial* mat)
{
	std::vector<char*> matFlags;
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_INVALID)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_INVALID");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_SKIN_COLOR)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_SKIN_COLOR");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_HEAD_COLOR)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_HEAD_COLOR");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_ADD_COLOR)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_ADD_COLOR");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_BELT_COLOR)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_BELT_COLOR");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_UV_MATRIX)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_UV_MATRIX");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_ENV_MAP)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_ENV_MAP");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_EMUV)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_EMUV");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_MIXED)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_MIXED");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_EMBLEM)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_EMBLEM");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_SIMPLEMATERIAL)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_SIMPLEMATERIAL");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_DXT1_ALPHA_CHECK)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_DXT1_ALPHA_CHECK");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_DOGI_PANTS)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_DOGI_PANTS");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_PETRIFY)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_PETRIFY");
	}
	if (RpNtlMaterialExtGetFlag(mat) & rpNTL_MATERIAL_DOGI_SKIRT)
	{
		matFlags.push_back((char*)"rpNTL_MATERIAL_DOGI_SKIRT");
	}

	return matFlags;
}

void CMaterialPane::fillComboBox()
{
	USES_CONVERSION;
	m_groupFlag.InsertString(0,A2W("rpNTL_MATERIAL_INVALID"));
	m_groupFlag.SetItemData(0, rpNTL_MATERIAL_INVALID);
	m_groupFlag.InsertString(1, A2W("rpNTL_MATERIAL_SKIN_COLOR"));
	m_groupFlag.SetItemData(1, rpNTL_MATERIAL_SKIN_COLOR);
	m_groupFlag.InsertString(2, A2W("rpNTL_MATERIAL_HEAD_COLOR"));
	m_groupFlag.SetItemData(2, rpNTL_MATERIAL_HEAD_COLOR);
	m_groupFlag.InsertString(3, A2W("rpNTL_MATERIAL_ADD_COLOR"));
	m_groupFlag.SetItemData(3, rpNTL_MATERIAL_ADD_COLOR);
	m_groupFlag.InsertString(4, A2W("rpNTL_MATERIAL_BELT_COLOR"));
	m_groupFlag.SetItemData(4, rpNTL_MATERIAL_BELT_COLOR);
	m_groupFlag.InsertString(5,A2W("rpNTL_MATERIAL_UV_MATRIX"));
	m_groupFlag.SetItemData(5, rpNTL_MATERIAL_UV_MATRIX);
	m_groupFlag.InsertString(6,A2W("rpNTL_MATERIAL_ENV_MAP"));
	m_groupFlag.SetItemData(6, rpNTL_MATERIAL_ENV_MAP);
	m_groupFlag.InsertString(7,A2W("rpNTL_MATERIAL_EMUV"));
	m_groupFlag.SetItemData(7, rpNTL_MATERIAL_EMUV);
	m_groupFlag.InsertString(8,A2W("rpNTL_MATERIAL_MIXED"));
	m_groupFlag.SetItemData(8, rpNTL_MATERIAL_MIXED);
	m_groupFlag.InsertString(9,A2W("rpNTL_MATERIAL_EMBLEM"));
	m_groupFlag.SetItemData(9, rpNTL_MATERIAL_EMBLEM);
	m_groupFlag.InsertString(10,A2W("rpNTL_MATERIAL_SIMPLEMATERIAL"));
	m_groupFlag.SetItemData(10, rpNTL_MATERIAL_SIMPLEMATERIAL);
	m_groupFlag.InsertString(11,A2W("rpNTL_MATERIAL_DXT1_ALPHA_CHECK"));
	m_groupFlag.SetItemData(11, rpNTL_MATERIAL_DXT1_ALPHA_CHECK);
	m_groupFlag.InsertString(12,A2W("rpNTL_MATERIAL_DOGI_PANTS"));
	m_groupFlag.SetItemData(12, rpNTL_MATERIAL_DOGI_PANTS);
	m_groupFlag.InsertString(13,A2W("rpNTL_MATERIAL_PETRIFY"));
	m_groupFlag.SetItemData(13, rpNTL_MATERIAL_PETRIFY);
	m_groupFlag.InsertString(14,A2W("rpNTL_MATERIAL_DOGI_SKIRT"));
	m_groupFlag.SetItemData(14, rpNTL_MATERIAL_DOGI_SKIRT);

}
void CMaterialPane::OnDataUpdate()
{
    USES_CONVERSION;

    if(!m_pMTClump)
        return;

    m_listBoxMaterial.ResetContent();
	fillComboBox();
    std::vector<char*> vMaterialNames = m_pMTClump->GetMaterialNames();
	
    for(UINT i = 0; i < vMaterialNames.size(); ++i)
    {
        m_listBoxMaterial.AddString(A2W(vMaterialNames[i]));
    }
	
}
void CMaterialPane::OnLbnSelchangeListMaterial()
{
    USES_CONVERSION;
    if(!m_pMTClump)
        return;

    // Material 정보를 가져와서 리스트 박스에 세팅한다. (멀티 텍스쳐)
    int nIndex = m_listBoxMaterial.GetCurSel();
    WCHAR szMaterialName[256] = {0,};
    m_listBoxMaterial.GetText(nIndex, szMaterialName);
    OnDisplayMaterialInfo(szMaterialName);
}

void CMaterialPane::OnBnClickedBtMaterialAdd()
{
    USES_CONVERSION;
    if(!m_pMTClump)
        return;

    // 멀티텍스처 추가 기능
    WCHAR szOpenFilter[] = L"Texture File (*.dds;*.png)|*.dds; *.png||";    
    CFileDialog dlgTextureFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, szOpenFilter);
    if(dlgTextureFile.DoModal() == IDOK)
    {
		CString strFileName = dlgTextureFile.GetFileName();
        CString strFilePath = dlgTextureFile.GetPathName();        
        strFilePath.Replace(strFileName, L"");
        strFileName.MakeUpper();
        strFileName.Replace(L".DDS", L"");
        //strFileName.Replace(L".PNG", L"");
        
        
		// ListBox에서 Material 이름을 가져온다.
        int nIndex = m_listBoxMaterial.GetCurSel();
        WCHAR szMaterialName[256] = {0,};
        m_listBoxMaterial.GetText(nIndex, szMaterialName);

        RwBool bReturn = m_pMTClump->SetMultiTexture(W2A(szMaterialName), W2A(strFileName), W2A(strFilePath));
        if(bReturn == (RwBool)TRUE)
        {
            OnDisplayMaterialInfo(szMaterialName);
        }
        else
        {
            m_editTextureName.SetWindowText(L"");
            m_editTextureSize.SetWindowText(L"");
            MessageBox(L"Set MultiTexture Fail");
        }
    }
}

void CMaterialPane::OnBnClickedBtMaterialDel()
{
    USES_CONVERSION;

    if(!m_pMTClump)
        return;

    // 기존에 있던 멀티 텍스처를 제거한다.

    
    // ListBox에서 Material 이름을 가져온다.
    int nIndex = m_listBoxMaterial.GetCurSel();
    WCHAR szMaterialName[256] = {0,};
    m_listBoxMaterial.GetText(nIndex, szMaterialName);

    RwBool bReturn = m_pMTClump->SetMultiTexture(W2A(szMaterialName), NULL, NULL);
    if(bReturn == (RwBool)TRUE)
    {
        // 화면 정보를 갱신한다.
        m_editTextureName.SetWindowText(L"");
        m_editTextureSize.SetWindowText(L"");
    }
    else
    {
        MessageBox(L"Delete MultiTexture Fail");
    }
    
}

void CMaterialPane::OnDisplayMaterialInfo(WCHAR* szMaterialName)
{
    USES_CONVERSION;

    if(!m_pMTClump || !szMaterialName)
        return;
	m_listBoxMaterialFlags.ResetContent();
    RpMaterial* pMaterial = m_pMTClump->GetMaterialByName(W2A(szMaterialName));    
    if(pMaterial)
    {
        // 텍스쳐 설정
        RwTexture* pTexture = NtlMatExtGetMultiTexture(pMaterial);
        if(pTexture)
        {
            // 이름 설정
            std::string strTextureName = RwTextureGetName(pTexture);
            RwRaster* pRaster = RwTextureGetRaster(pTexture);
            RwInt32 nWidth = RwRasterGetWidth(pRaster);
            RwInt32 nHeight = RwRasterGetHeight(pRaster);

            m_editTextureName.SetWindowText(A2W(strTextureName.c_str()));
            CString strTextureSize;
            strTextureSize.Format(L"WIDTH:%d, HEIGHT:%d", nWidth, nHeight);
            m_editTextureSize.SetWindowText(strTextureSize);
        }
        else
        {
            // MultiTexture가 없을때
            m_editTextureName.SetWindowText(L"");
            m_editTextureSize.SetWindowText(L"");
        }

		std::vector<char*> vMaterialFlags = getMaterialFlags(pMaterial);
		for (UINT j = 0; j < vMaterialFlags.size(); ++j)
		{
			m_listBoxMaterialFlags.AddString(A2W(vMaterialFlags[j]));
		}
    }
}

void CMaterialPane::OnBtnClickedSetFlag()
{
	USES_CONVERSION;

	if (!m_pMTClump)
		return;

	int nIndex = m_listBoxMaterial.GetCurSel();
	WCHAR szMaterialName[256] = { 0, };
	m_listBoxMaterial.GetText(nIndex, szMaterialName);

	int nNdex = m_groupFlag.GetCurSel();
	DWORD flag = m_groupFlag.GetItemData(nNdex);

	if (nIndex == -1)
		return;

	RpMaterial* pMaterial = m_pMTClump->GetMaterialByName(W2A(szMaterialName));
	if (pMaterial)
	{
		// 텍스쳐 설정
		RwTexture* pTexture = RpMaterialGetTexture(pMaterial);
		if (pTexture)
		{
			NtlMatExtSetFlag(pMaterial, flag);
			OnDisplayMaterialInfo(szMaterialName);
			CString strClumpName = A2W(m_pMTClump->GetClumpName());

			WCHAR szOpenFilter[] = L"Clump File (*.dff)|*.dff||";
			CFileDialog fileDlg(FALSE, L"dff", strClumpName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szOpenFilter);

			if (fileDlg.DoModal() == IDOK)
			{
				CString strFileName = fileDlg.GetPathName();

				RwBool retBool = m_pMTClump->Save(W2A(strFileName));
				if (retBool == (RwBool)FALSE)
				{
					MessageBox(L"Clump File Save Fail");
				}
			}
		}

	}
}