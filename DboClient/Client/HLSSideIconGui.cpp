#include "precomp_dboclient.h"
#include "HLSSideIconGui.h"

// core
#include "NtlDebug.h"

// presentation
#include "NtlPLGuiManager.h"

// dbo
#include "DboEvent.h"
#include "DboEventGenerator.h"
#include "DboPacketGenerator.h"
#include "DialogManager.h"
#include "DboGlobal.h"


CHLSSideIconGui::CHLSSideIconGui(const RwChar* pName)
: CSideIconBase(pName)
{
    m_bNetmarbleMemberShip = FALSE;
}

CHLSSideIconGui::~CHLSSideIconGui(void)
{
}

RwBool CHLSSideIconGui::Create() 
{
    NTL_FUNCTION("CHLSSideIconGui::Create");

    if(!CNtlPLGui::Create("gui\\HLS.rsr", "gui\\HLSSideIcon.srf", "gui\\hlssideicon.frm"))
        NTL_RETURN(FALSE);

    CNtlPLGui::CreateComponents(CNtlPLGuiManager::GetInstance()->GetGuiManager());

    m_pThis = (gui::CDialog*)GetComponent("dlgMain");
    m_pBtnHLS = (gui::CButton*)GetComponent("btnHLSSideIcon");
    m_slotHLSBtn = m_pBtnHLS->SigClicked().Connect(this, &CHLSSideIconGui::OnIconButtonClicked);
    m_slotHLSMouseEnter = m_pBtnHLS->SigMouseEnter().Connect(this, &CHLSSideIconGui::OnMouseEnter);
    m_slotHLSMouseLeave = m_pBtnHLS->SigMouseLeave().Connect(this, &CHLSSideIconGui::OnMouseLeave);
    
    //LinkMsg(g_EventUpdateHLS);
    LinkMsg(g_EventNetMarbleMemberShipNfy);

	//if (GetNtlSLGlobal()->IsEnableUseHLSStore())
	//{
		Show(false);
	//}
	//else
	//{
	//	Show(FALSE);
	//}    

    NTL_RETURN(TRUE);
}

VOID CHLSSideIconGui::Destroy() 
{
    //UnLinkMsg(g_EventUpdateHLS);
    UnLinkMsg(g_EventNetMarbleMemberShipNfy);

   CNtlPLGui::DestroyComponents();
   CNtlPLGui::Destroy();
   Show(TRUE);
}

VOID CHLSSideIconGui::HandleEvents( RWS::CMsg &msg ) 
{
    /*if(msg.Id == g_EventUpdateHLS)
    {
		m_bNetmarbleMemberShip = TRUE;

        Show(TRUE);
        CSideIconGui::GetInstance()->OpenSideView(this, SIDEVIEW_HLS, (VOID*)E_HLS_INFO);
    }
    else if(msg.Id == g_EventNetMarbleMemberShipNfy)
    {
        m_bNetmarbleMemberShip = TRUE;

        Show(TRUE);
        CSideIconGui::GetInstance()->OpenSideView(this, SIDEVIEW_HLS, (VOID*)E_HLS_INFO);        
    }*/
}

VOID CHLSSideIconGui::OnIconButtonClicked( gui::CComponent* pComponent ) 
{
    //CSideIconGui::GetInstance()->CloseSideView(SIDEVIEW_HLS);

	// 기획팀에서 요청하기 전까지 활성화 시키지 않는다.
	// 09. 08. 17 월요일 기획팀 김종완씨의 요청으로 클라이언트팀 조해성 작업함
	/*if( !GetDialogManager()->IsOpenDialog( DIALOG_HLSSHOP ) )
		GetDboGlobal()->GetGamePacketGenerator()->SendShopHLSItemStartReq();
	else
		GetDboGlobal()->GetGamePacketGenerator()->SendShopHLSItemEndReq();*/
}

VOID CHLSSideIconGui::OnSideViewClosed() 
{

}

void CHLSSideIconGui::OnMouseEnter(gui::CComponent* pComponent)
{
    //CSideIconGui::GetInstance()->OpenSideView(this, SIDEVIEW_HLS, (VOID*)E_HLS_INFO);
}

void CHLSSideIconGui::OnMouseLeave(gui::CComponent* pComponent)
{
    //CSideIconGui::GetInstance()->CloseSideView(SIDEVIEW_HLS);
}

void CHLSSideIconGui::Show( bool bShow ) 
{
    __super::Show(bShow);    
}