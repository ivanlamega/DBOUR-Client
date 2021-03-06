#include "precomp_guidevtool.h"
#include "GuiDevApplication.h"
#include "NtlDebug.h"
#include "NtlCharsetPrint.h"
#include "NtlText.h"

#include "guicore_precomp.h"
#include "gui_precomp.h"
#include "gui_html_doc.h"
#include "gui_htmlbox_generic.h"
#include "gui_fontmanager.h"
#include "gui_renderer.h"

CGuiDevApplication * CGuiDevApplication::m_pInstance = NULL;

CGuiDevApplication::CGuiDevApplication() : m_pCharset(NULL)
{
	m_pInstance = this;

	m_BackgroundColor.red   = 50;
	m_BackgroundColor.green = 50;
	m_BackgroundColor.blue  = 50;
	m_BackgroundColor.alpha = 0;

	m_ForegroundColor.red   = 255;
	m_ForegroundColor.green = 255;
	m_ForegroundColor.blue  = 255;
	m_ForegroundColor.alpha = 255;

	m_pCamera = NULL;
	m_pResMgr = 0;
	m_pSurMgr = 0;
	m_pCompMgr = 0;
	m_pGuiMgr = 0;

	m_fTime = 0.0f;
}

CGuiDevApplication::~CGuiDevApplication()
{
	
}

RwBool CGuiDevApplication::CreateSubSystem(RwUInt32 iWidth, RwUInt32 iHeight, RwBool zBuffer)
{
	NTL_FUNCTION("CGuiDevApplication::CreateSubSystem" );

	CNtlApplication::CreateSubSystem(iWidth, iHeight, zBuffer);

	gui::CHtmlBox_Generic::LinkHtmlLinkTag( Logic_CallbackHtmlLinkTag );

	// camera 
	m_pCamera = NTL_NEW CNtlCamera;
	if(!m_pCamera->Create(iWidth, iHeight, zBuffer, 1.f, 500.f))
	{
		NTL_RETURN(FALSE);
	}
	
	// character set
	m_pCharset = RtCharsetCreate(&m_ForegroundColor, &m_BackgroundColor);
    if( m_pCharset == NULL )
	{
		NTL_RETURN(FALSE);
	}	

	m_pResMgr = NTL_NEW gui::CResourceManager;
	m_pSurMgr = NTL_NEW gui::CSurfaceManager(m_pResMgr);	
	m_pCompMgr = NTL_NEW gui::CComponentManager;
	m_pGuiMgr = NTL_NEW gui::CGUIManager(CRectangle(0, 0, iWidth, iHeight));
		
	// gui setup
	gui::CSetupGUI::Init( GetHWnd(), iWidth, iHeight, m_pGuiMgr, "script\\GuiFont.def", "metatag.htm",
		"script\\FlashFont.def" );

	m_pResMgr->AddPage("GuiDevTest.rsr");
	m_strResPage = "GuiDevTest.rsr";

	m_pSurMgr->AddPage("GuiDevTest.srf");
	m_strSurPage = "GuiDevTest.srf";

	m_hCompPage = m_pCompMgr->AddPage("GuiDevTest.frm");
	m_strCompPage = "GuiDevTest.frm";

	m_pCompMgr->CreateComponents(m_hCompPage, m_pGuiMgr, m_pSurMgr);
	gui::CToolTip* pToolTip = new gui::CToolTip( CRectangle( 0, 0, 100, 100 ), m_pGuiMgr, m_pSurMgr );
	pToolTip->SetMouseMargin( 32, 32 );
	gui::GetGlobalComponent()->SetToolTip( pToolTip );
				
	m_pHtml = reinterpret_cast<gui::CHtmlBox*>( m_pCompMgr->GetComponent( m_hCompPage, "testhtml" ) );
	m_pHtml->SetHtmlFromFile( "1.html" );
	/*m_pHtml->SetIntervalTextEnable( 0.01f );*/

	NTL_RETURN(TRUE);
}	

RwBool CGuiDevApplication::AttachPlugin()
{
	NTL_FUNCTION( "CGuiDevApplication::AttachPlugin" );

	if( !RpWorldPluginAttach() )
		NTL_RETURN(FALSE);
	
	if( !RpCollisionPluginAttach() )
		NTL_RETURN(FALSE);
	
	if( !RtAnimInitialize() )
		NTL_RETURN(FALSE);
	
	if( !RpHAnimPluginAttach() )
		NTL_RETURN(FALSE);
	
	if( !RpSkinPluginAttach() )
		NTL_RETURN(FALSE);

	if ( !RpToonPluginAttach() )
		NTL_RETURN(FALSE);

	if( !RpUserDataPluginAttach() )
		NTL_RETURN(FALSE);

	if( !RpIdPluginAttach() )
		NTL_RETURN(FALSE);
	
	//if( !RpToonMultiTexPluginAttach() )
		//NTL_RETURN(FALSE);

	NTL_RETURN(TRUE);
}

RwBool CGuiDevApplication::Resize(RwUInt32 iWidth, RwUInt32 iHeight, RwBool zBuffer)
{
	NTL_FUNCTION("CGuiDevApplication::Resize" );

	CNtlApplication::Resize(iWidth, iHeight, zBuffer, FALSE );

	if(m_pCamera != NULL)
	{
		if (m_pCamera->GetCamera())
		{
			if (iWidth == 0 || iHeight == 0)
			{
			}
			else
			{
				RwRect rt;
				rt.x = 0; rt.y = 0; rt.w = iWidth; rt.h = iHeight;
				m_pCamera->SetCameraSize(&rt); 				
			}
			NTL_RETURN(TRUE);
		}
		else
		{
			NTL_RETURN(FALSE);
		}
	}

	NTL_RETURN(TRUE);
}


LRESULT CGuiDevApplication::PreTranslateMessage(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	if(m_pGuiMgr)
        return m_pGuiMgr->Win32EventProc(window, message, wParam, lParam);
	else
		return 0;
}

RwBool CGuiDevApplication::Update(RwReal fTime, RwReal fElapsedTime)
{
	NTL_FUNCTION("CGuiDevApplication::Update" );

	CEventTimer::KeepAlive();
	
	m_fTime += fElapsedTime;

	m_pHtml->Update( fElapsedTime );

	//
	const RwReal fGoalTime = 1.0f;

	if( m_fTime <= fGoalTime )
	{
		const RwUInt32 nStartValue = 768;
		const RwUInt32 nEndValue = 0;
		RwReal fControlValue = gui::GetValueByPercentOfStart( nStartValue, nEndValue, 150 );
		RwReal fControlValue2 = gui::GetValueByPercentOfStart( nStartValue, nEndValue, -50 );
		RwReal fYPos = gui::GetResult3BezierInterpolation( m_fTime, fGoalTime, nStartValue, fControlValue, fControlValue2, nEndValue );
		RwReal fNorTime = m_fTime / fGoalTime;
		RwReal fNorYPos = 1 - ( fYPos / 768.0f );
		gui::CPanel* pPanel;
		WCHAR buf[256];

		CRectangle rect;
		rect.SetRectWH( m_fTime / fGoalTime * 768, fYPos, 4, 4 );
		pPanel = NTL_NEW gui::CPanel( rect, m_pGuiMgr, m_pSurMgr, m_pSurMgr->GetSurface( "GuiDevTest.srf", "srfRedPoint" ) );
		swprintf_s( buf, 256, L"%.2f : %.2f", fNorTime, fNorYPos );
		pPanel->SetToolTip( buf );
		m_listPoint.push_back( pPanel );

		fControlValue = gui::GetValueByPercentOfStart( nStartValue, nEndValue, 100 );
		fYPos = gui::GetResult2BezierInterpolation( m_fTime, fGoalTime, nStartValue, fControlValue, nEndValue );
		fNorYPos = 1 - ( fYPos / 768.0f );
		rect.SetRectWH( m_fTime / fGoalTime * 768, fYPos, 4, 4 );
		pPanel = NTL_NEW gui::CPanel( rect, m_pGuiMgr, m_pSurMgr, m_pSurMgr->GetSurface( "GuiDevTest.srf", "srfWhitePoint" ) );
		swprintf_s( buf, 256, L"%.2f : %.2f", fNorTime, fNorYPos );
		pPanel->SetToolTip( buf );
		m_listPoint.push_back( pPanel );

		RwReal fValue[10] = { nStartValue, 200.0f, 150.0f, 110.0f, 80.0f, 50.0f, 30.0f, 15.0f, 8.0f, nEndValue };
		fYPos = gui::GetResultBezierInterpolation( m_fTime, fGoalTime, fValue, 10 );
		rect.SetRectWH( m_fTime / fGoalTime * 768, fYPos, 4, 4 );
		pPanel = NTL_NEW gui::CPanel( rect, m_pGuiMgr, m_pSurMgr, m_pSurMgr->GetSurface( "GuiDevTest.srf", "srfBluePoint" ) );
		swprintf_s( buf, 256, L"%.2f : %.2f", fNorTime, fNorYPos );
		pPanel->SetToolTip( buf );
		m_listPoint.push_back( pPanel );

		fControlValue = gui::GetValueByPercentOfStart( nStartValue, nEndValue, 100 );
		RwReal fControlTime = gui::GetResult2BezierInterpolation( m_fTime, fGoalTime, 0.0f, gui::GetValueByPercentOfStart( 0.0f, fGoalTime, 0 ), fGoalTime );
		fYPos = gui::GetResult2BezierInterpolation( m_fTime, fGoalTime, nStartValue, fControlValue, nEndValue );
		fNorYPos = 1 - ( fYPos / 768.0f );
		fNorTime = fControlTime / fGoalTime;
		//rect.SetRectWH( m_fTime / fGoalTime * 768, fYPos, 4, 4 );
		rect.SetRectWH( fControlTime / fGoalTime * 768, fYPos, 4, 4 );
		pPanel = NTL_NEW gui::CPanel( rect, m_pGuiMgr, m_pSurMgr, m_pSurMgr->GetSurface( "GuiDevTest.srf", "srfGreenPoint" ) );
		swprintf_s( buf, 256, L"%.2f(%.2f) : %.2f", fNorTime, m_fTime / fGoalTime, fNorYPos );
		pPanel->SetToolTip( buf );
		m_listPoint.push_back( pPanel );
	}
	//

	if (RwCameraClear(m_pCamera->GetCamera(), &m_BackgroundColor, rwCAMERACLEARZ|rwCAMERACLEARIMAGE))
	{	
		//Ready to render scene.
		if( RwCameraBeginUpdate(m_pCamera->GetCamera()) )
		{
			RwBlendFunction eSrcBlend;
			RwBlendFunction eDestBlend;

			RwD3D9SetTexture(NULL, 0);
			RwD3D9SetTexture(NULL, 1);

			RwD3D9SetTextureStageState (0, D3DTSS_COLOROP, D3DTOP_MODULATE); 
			RwD3D9SetTextureStageState (0, D3DTSS_COLORARG1, D3DTA_TEXTURE); 
			RwD3D9SetTextureStageState (0, D3DTSS_COLORARG2, D3DTA_DIFFUSE); 

			// stage 0 alpha : nada 
			RwD3D9SetTextureStageState (0, D3DTSS_ALPHAOP,  D3DTOP_MODULATE); 
			RwD3D9SetTextureStageState (0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE); 
			RwD3D9SetTextureStageState (0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE); 

			RwRenderStateSet(rwRENDERSTATESHADEMODE, (void *)rwSHADEMODEGOURAUD);
			RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void *) FALSE);
			RwRenderStateSet(rwRENDERSTATEZWRITEENABLE, (void *) FALSE);
			RwRenderStateSet(rwRENDERSTATETEXTURERASTER, (void *) NULL);
			RwRenderStateSet(rwRENDERSTATEVERTEXALPHAENABLE, (void *) TRUE);
			RwRenderStateGet(rwRENDERSTATESRCBLEND, (void *)&eSrcBlend);
			RwRenderStateGet(rwRENDERSTATEDESTBLEND, (void *)&eDestBlend);
			RwRenderStateSet(rwRENDERSTATESRCBLEND, (void *)rwBLENDSRCALPHA);
			RwRenderStateSet(rwRENDERSTATEDESTBLEND, (void *)rwBLENDINVSRCALPHA);

			// gui render
			g_GuiRenderer.ResetRender();

			if(m_pGuiMgr)
				m_pGuiMgr->Show();

			g_GuiRenderer.Render();

			RwD3D9SetTexture(NULL, 0);

			RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void *) TRUE);
			RwRenderStateSet(rwRENDERSTATEZWRITEENABLE, (void *) TRUE);
			RwRenderStateSet(rwRENDERSTATETEXTURERASTER, (void *) NULL);
			RwRenderStateSet(rwRENDERSTATEVERTEXALPHAENABLE, (void *) FALSE);
			RwRenderStateSet(rwRENDERSTATESRCBLEND, (void *)eSrcBlend);
			RwRenderStateSet(rwRENDERSTATEDESTBLEND, (void *)eDestBlend);

			DisplayInfo();

			RwCameraEndUpdate(RwCameraGetCurrentCamera());
		}

		RwCameraShowRaster(m_pCamera->GetCamera(), GetHWnd(), 0);
	}
	NTL_RETURN(TRUE);
}

void CGuiDevApplication::Destroy()
{
	NTL_FUNCTION("CGuiDevApplication::Destroy" );

	m_pCompMgr->DestroyComponents (m_hCompPage);
	m_pResMgr->RemovePage(m_strResPage);
	m_pSurMgr->RemovePage(m_strSurPage);
	m_pCompMgr->RemovePage(m_hCompPage);
	
	if(m_pGuiMgr)
	{
		NTL_DELETE(m_pGuiMgr);
	}

	m_listPoint.clear();

	if(m_pCompMgr)
	{
		NTL_DELETE(m_pCompMgr);
	}

	if(m_pSurMgr)
	{
		NTL_DELETE(m_pSurMgr);
	}

	if(m_pResMgr)
	{
		NTL_DELETE(m_pResMgr);
	}

	// 여기는 더 점검을 해 봐야 한다...
	// 왜 이렇게 만들었쥐? 이해가 안되네... 내가 하고서리...;; 
	CEventListener_Win32::RemoveAll();

	// character set destroy
	if(m_pCharset)
    {
		RtCharsetClose();
		RwRasterDestroy(m_pCharset);
		m_pCharset = NULL;
    }
	
	// camera destroy
	if(m_pCamera)
	{
		m_pCamera->Destroy();
		NTL_DELETE(m_pCamera);
		m_pCamera = NULL;
	}

	// gui
	gui::CSetupGUI::Deinit();

	//
	CNtlApplication::Destroy();
	
	NTL_RETURNVOID();
}

void CGuiDevApplication::DisplayInfo()
{
	RwChar caption[256];
	RwInt32 iIdx = 0;
	
	//fps
	RsSprintf(caption, RWSTRING("FPS: %4.2f"), GetFps());
	RsCharsetPrint(m_pCharset, caption, 0, iIdx++, rsPRINTPOSTOPRIGHT);
}



LRESULT CGuiDevApplication::WndProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch( message )
	{
	case WM_KEYUP:
		{
			if( wParam == VK_F1 )
			{
				m_pHtml->SetNextPage();
			}
			else if( wParam == VK_F2 )
			{
				m_pHtml->SetPrevPage();
			}
		}
		break;
	default:
		break;
	}

	return CNtlApplication::WndProc(window, message, wParam, lParam);
}

void Logic_CallbackHtmlLinkTag( gui::CComponent* pComponent, RwUInt8 byType, RwUInt32 uiIndex, std::wstring& strFilename )
{
	if( byType == gui::eHTML_LINK_FILE )
	{
		gui::CHtmlBox* pHtmlBox = reinterpret_cast<gui::CHtmlBox*>( pComponent );
		pHtmlBox->SetHtmlFromFile( strFilename.c_str() );
	}
	// Interface ( Table )
	else if( byType == gui::eHTML_LINK_INTERFACE )
	{

	}
}