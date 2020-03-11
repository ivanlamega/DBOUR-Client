#pragma once

// core
#include "ceventhandler.h"

// presentation
#include "NtlPLGui.h"

// dbo
#include "Windowby3.h"
#include "SideIconGui.h"
#include "DBOEvent.h"
    
/**
 * \ingroup Client
 * \brief HLS 정보를 표시하는 Side View
 *
 * \date 2009-04-20
 * \author agebreak
 */
class CHLSSideViewGui : public CSideViewBase, public RWS::CEventHandler
{
public:
    enum EHLSSideViewHeight
    {
        HLS_SIDEVIEW_HEIGHT_NORMAL = 60,
        HLS_SIDEVIEW_HEIGHT_PCBANG = 140,
        HLS_SIDEVIEW_HEIGHT_NFY    = 60,
    };

public:
    CHLSSideViewGui(const RwChar* pName);
    virtual ~CHLSSideViewGui(void);

    RwBool		Create();
    VOID		Destroy();
    VOID		Update(RwReal fElapsed);

    virtual VOID	OnPressESC();
    virtual VOID	OnSideViewOpen(const void* pData);
    virtual VOID	OnSideViewClose();
    virtual VOID	OnSideViewLocate(const CRectangle& rectSideIcon);	

protected:
    virtual VOID	HandleEvents( RWS::CMsg &msg );
    VOID			LocateComponent();
    VOID			OnMove(RwInt32 iOldX, RwInt32 iOldY);
    VOID			OnResize( RwInt32 iOldW, RwInt32 iOldH );
    VOID			OnPaint();

   // VOID            SetState(eHLSSideViewType type);
    VOID            OnShowInfo();           ///< 현재 HLS 정보를 출력한다
    VOID            OnShowNotify();         ///< HLS 습득 정보를 출력한다. 

protected:
    CWindowby3			m_BackPanel;		///< 배경
   // eHLSSideViewType  m_type;             ///< 현재 보여지는 타입

    gui::CSlot			m_slotPaint;
    gui::CSlot			m_slotMove;
    gui::CSlot			m_slotResize;

    // 현재 HLS 정보
    gui::CStaticBox*    m_pstbRemainTimeTitle;
    gui::CStaticBox*    m_pstbRemainTimeData;    
    gui::CStaticBox*    m_pstbGetTitle;
    gui::CStaticBox*    m_pstbGetData;    
    gui::CStaticBox*    m_pstbCurrentTitle;
    gui::CStaticBox*    m_pstbCurrentData;   

    // HLS 획득 정보
    gui::CStaticBox*    m_pstbGetPoint;

   // SDboEventUpdateHLS m_UpdateHLSInfo;                 ///< 서버로 부터 받은 HLS 업데이트 정보
    DWORD                m_dwUpdateHLSPoint;              ///< 획득 포인트
    RwReal               m_fRemainTime;                     ///< 다음 HLS 획득까지의 남은 시간
    RwReal               m_fNotifyShowTime;                 ///< Notify 표시 시간    
    RwBool               m_bIsPCBang;                       ///< PC방인지를 판단한다.
};
