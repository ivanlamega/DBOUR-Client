#include "precomp_dboclient.h"
#include "HLSSideView.h"

// core
#include "NtlDebug.h"

// presentation
#include "NtlPLGuiManager.h"

// sl
#include "NtlSLLogic.h"

// dbo
#include "DisplayStringDef.h"
#include "DisplayStringManager.h"

#define NOTIFY_SHOWTIME_MAX     5.0f                        ///< Notify 정보를 보여줄 시간 (초)


CHLSSideViewGui::CHLSSideViewGui(const RwChar* pName)
: CSideViewBase(pName)
{
   // ZeroMemory(&m_UpdateHLSInfo, sizeof(m_UpdateHLSInfo));
    m_dwUpdateHLSPoint = 0;
    m_fRemainTime = 0.0f;
    //m_type = E_HLS_INFO;
    //m_type = 0;
    m_fNotifyShowTime = 0.0f;
    m_bIsPCBang = FALSE;
}

CHLSSideViewGui::~CHLSSideViewGui(void)
{
}

RwBool CHLSSideViewGui::Create() 
{
    if(!CNtlPLGui::Create("", "gui\\HLSSideView.srf", "gui\\HLSSideView.frm"))
        return FALSE;

    CNtlPLGui::CreateComponents(CNtlPLGuiManager::GetInstance()->GetGuiManager());
    
    m_pThis = (gui::CDialog*)GetComponent("dlgMain");

    // 배경
    m_BackPanel.SetType(CWindowby3::WT_HORIZONTAL);    
    m_BackPanel.SetSurface(0, GetNtlGuiManager()->GetSurfaceManager()->GetSurface("HLSSideView.srf", "srfDialogBackUp"));
    m_BackPanel.SetSurface(1, GetNtlGuiManager()->GetSurfaceManager()->GetSurface("HLSSideView.srf", "srfDialogBackCenter"));
    m_BackPanel.SetSurface(2, GetNtlGuiManager()->GetSurfaceManager()->GetSurface("HLSSideView.srf", "srfDialogBackDown"));	    

    // sig	
    m_slotPaint			= m_pThis->SigPaint().Connect( this, &CHLSSideViewGui::OnPaint );
    m_slotMove			= m_pThis->SigMove().Connect(this, &CHLSSideViewGui::OnMove);
    m_slotResize		= m_pThis->SigMove().Connect(this, &CHLSSideViewGui::OnResize);

    //////////////////////////////////////////////////////////////////////////
    // 현재 HLS 정보
    CRectangle rect;
    rect.SetRectWH(20, 10, 250, 14);
    // 다음 HLS 획득까지 남은 시간
    //m_pstbRemainTimeTitle = NTL_NEW gui::CStaticBox(rect, m_pThis, GetNtlGuiManager()->GetSurfaceManager(), COMP_TEXT_LEFT );
    //m_pstbRemainTimeTitle->CreateFontStd( DEFAULT_FONT, DEFAULT_FONT_SIZE, DEFAULT_FONT_ATTR);	        
    //m_pstbRemainTimeTitle->SetTextColor(RGB(167, 184, 193));
    //m_pstbRemainTimeTitle->SetText(GetDisplayStringManager()->GetString(DST_HLS_REMAIN_TIME));
    //

    //rect.SetRectWH(20, 26, 250, 14);
    //m_pstbRemainTimeData = NTL_NEW gui::CStaticBox(rect, m_pThis, GetNtlGuiManager()->GetSurfaceManager(), COMP_TEXT_LEFT );
    //m_pstbRemainTimeData->CreateFontStd( DEFAULT_FONT, DEFAULT_FONT_SIZE, DEFAULT_FONT_ATTR);	        
    //m_pstbRemainTimeData->SetTextColor(RGB(255, 255, 255));    
    //

    //// 누적 획득 넷피
    //rect.SetRectWH(20, 50, 250, 14);
    //m_pstbGetTitle = NTL_NEW gui::CStaticBox(rect, m_pThis, GetNtlGuiManager()->GetSurfaceManager(), COMP_TEXT_LEFT );
    //m_pstbGetTitle->CreateFontStd( DEFAULT_FONT, DEFAULT_FONT_SIZE, DEFAULT_FONT_ATTR);	        
    //m_pstbGetTitle->SetTextColor(RGB(167, 184, 193));
    //m_pstbGetTitle->SetText(GetDisplayStringManager()->GetString(DST_HLS_GET_HLS));
    //

    //rect.SetRectWH(20, 66, 250, 14);
    //m_pstbGetData = NTL_NEW gui::CStaticBox(rect, m_pThis, GetNtlGuiManager()->GetSurfaceManager(), COMP_TEXT_LEFT );
    //m_pstbGetData->CreateFontStd( DEFAULT_FONT, DEFAULT_FONT_SIZE, DEFAULT_FONT_ATTR);	        
    //m_pstbGetData->SetTextColor(RGB(255, 255, 255));    
    //

    //// 현재 넷피
    rect.SetRectWH(20, 90, 250, 14);
    m_pstbCurrentTitle = NTL_NEW gui::CStaticBox(rect, m_pThis, GetNtlGuiManager()->GetSurfaceManager(), COMP_TEXT_LEFT );
    m_pstbCurrentTitle->CreateFontStd( DEFAULT_FONT, DEFAULT_FONT_SIZE, DEFAULT_FONT_ATTR);	        
    m_pstbCurrentTitle->SetTextColor(RGB(167, 184, 193));
    m_pstbCurrentTitle->SetText(L"CASH SHOP");
    

    //rect.SetRectWH(20, 106, 250, 14);
    //m_pstbCurrentData = NTL_NEW gui::CStaticBox(rect, m_pThis, GetNtlGuiManager()->GetSurfaceManager(), COMP_TEXT_LEFT );
    //m_pstbCurrentData->CreateFontStd( DEFAULT_FONT, DEFAULT_FONT_SIZE, DEFAULT_FONT_ATTR);	            
    //m_pstbCurrentData->SetTextColor(RGB(255, 255, 255));
    
    //////////////////////////////////////////////////////////////////////////
    // HLS 획득 정보

    rect.SetRectWH(20, 10, 250, 14);
    m_pstbGetPoint = NTL_NEW gui::CStaticBox(rect, m_pThis, GetNtlGuiManager()->GetSurfaceManager(), COMP_TEXT_LEFT );
    m_pstbGetPoint->CreateFontStd( DEFAULT_FONT, DEFAULT_FONT_SIZE, DEFAULT_FONT_ATTR);	        
    m_pstbGetPoint->SetTextColor(RGB(167, 184, 193));    

   // LinkMsg(g_EventUpdateHLS);    
    LinkMsg(g_EventNetMarbleMemberShipNfy);

    GetNtlGuiManager()->AddUpdateFunc(this);

    Show(false);

    return TRUE;
}

VOID CHLSSideViewGui::Destroy() 
{
    GetNtlGuiManager()->RemoveUpdateFunc(this);

   // UnLinkMsg(g_EventUpdateHLS);    
    UnLinkMsg(g_EventNetMarbleMemberShipNfy);

    CNtlPLGui::DestroyComponents();
    CNtlPLGui::Destroy(); 
}
VOID CHLSSideViewGui::OnPressESC() 
{

}
VOID CHLSSideViewGui::OnSideViewOpen( const void* pData ) 
{
    //eHLSSideViewType type = (eHLSSideViewType)(RwInt32)pData;    
   // SetState(type);

    Show(true);
}

VOID CHLSSideViewGui::OnSideViewClose() 
{
    Show(false);
}

VOID CHLSSideViewGui::OnSideViewLocate( const CRectangle& rectSideIcon ) 
{
    RwInt32 iHeight = m_bIsPCBang? HLS_SIDEVIEW_HEIGHT_PCBANG : HLS_SIDEVIEW_HEIGHT_NORMAL;
    m_pThis->SetHeight(iHeight);
    LocateComponent();
    m_pThis->SetPosition(rectSideIcon.left - m_pThis->GetWidth() + rectSideIcon.GetWidth(), rectSideIcon.top - iHeight);
}

VOID CHLSSideViewGui::HandleEvents( RWS::CMsg &msg ) 
{
    //if(msg.Id == g_EventUpdateHLS)
    //{
    //    SDboEventUpdateHLS* pData = (SDboEventUpdateHLS*)msg.pData;        
    //    memcpy_s(&m_UpdateHLSInfo, sizeof(SDboEventUpdateHLS), pData, sizeof(SDboEventUpdateHLS));        
    //    m_fRemainTime = (RwReal)m_UpdateHLSInfo.timeNextGainTime; // 단위 초
    //    
    //    // HLS 획득이면
    //    if(pData->HLS > Logic_GetHLS())
    //    {
    //        m_dwUpdateHLSPoint = pData->HLS - Logic_GetHLS();
    //        SetState(E_HLS_NOTIFY);
    //        Show(true);
    //    }

    //}
    //else if(msg.Id == g_EventNetMarbleMemberShipNfy)
    //{
    //    SetState(E_HLS_INFO);
    //    m_bIsPCBang = TRUE;
    //}
}

VOID CHLSSideViewGui::LocateComponent() 
{
    m_BackPanel.SetRect( m_pThis->GetScreenRect() );
}

VOID CHLSSideViewGui::OnMove( RwInt32 iOldX, RwInt32 iOldY ) 
{
    LocateComponent();
}

VOID CHLSSideViewGui::OnResize( RwInt32 iOldW, RwInt32 iOldH ) 
{
    LocateComponent();
}

VOID CHLSSideViewGui::OnPaint() 
{
    m_BackPanel.Render();
}

//VOID CHLSSideViewGui::SetState( eHLSSideViewType type ) 
//{
//    m_pstbRemainTimeTitle->Show(false);
//    m_pstbRemainTimeData->Show(false);
//    m_pstbGetTitle->Show(false);
//    m_pstbGetData->Show(false);
//    m_pstbCurrentTitle->Show(false);
//    m_pstbCurrentData->Show(false);
//    m_pstbGetPoint->Show(false);
//
//    switch(type)
//    {
//    case E_HLS_INFO:
//        OnShowInfo();
//        break;
//    case E_HLS_NOTIFY:
//        OnShowNotify();
//        break;
//    }
//
//    m_type = type;
//}

VOID CHLSSideViewGui::OnShowInfo() 
{
    m_pstbCurrentTitle->Show(true);
   // m_pstbCurrentData->Show(true);    

    
        m_pThis->SetHeight(HLS_SIDEVIEW_HEIGHT_NORMAL);
        m_pstbCurrentTitle->SetPosition(20, 10);
     //   m_pstbCurrentData->SetPosition(20, 26);
    

    LocateComponent();

    // 총 넷피
    WCHAR wcTotalHLS[128] = {0,};
   // swprintf_s(wcTotalHLS, L"%d %s", Logic_GetHLS(), GetDisplayStringManager()->GetString(DST_HLS_POINT));
    m_pstbCurrentData->SetText(wcTotalHLS);

}

VOID CHLSSideViewGui::OnShowNotify() 
{
    m_pstbGetPoint->Show(true);

    //m_pThis->SetHeight(HLS_SIDEVIEW_HEIGHT_NFY);

    LocateComponent();
    
    // 메시지
    WCHAR wcNotify[128] = {0,};
   // swprintf_s(wcNotify, GetDisplayStringManager()->GetString(DST_HLS_GET_NOTIFY), m_dwUpdateHLSPoint);
    //m_pstbGetPoint->SetText(wcNotify);
}

VOID CHLSSideViewGui::Update( RwReal fElapsed ) 
{
    // 남은 시간 계산
    //if(m_UpdateHLSInfo.timeNextGainTime > 0 && m_fRemainTime > 0.0f)
    //{
    //    m_fRemainTime -= fElapsed;
    //    m_fRemainTime = max(0.0f, m_fRemainTime);

    //    m_UpdateHLSInfo.timeNextGainTime = (DWORD)m_fRemainTime;

    //    if(m_pstbCurrentData->IsVisible())  // Info 정보 표시중이면 갱신한다.
    //    {
    //        OnShowInfo();
    //    }        
    //}    

  /*  if(m_pstbGetPoint->IsVisible())
    {
        m_fNotifyShowTime += fElapsed;

        if(m_fNotifyShowTime > NOTIFY_SHOWTIME_MAX)
        {
            Show(FALSE);
            m_fNotifyShowTime = 0.0f;
        }
    }*/
}