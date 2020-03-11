#pragma once

// core
#include "ceventhandler.h"
#include "NtlSLEvent.h"

// presentation
#include "NtlPLGui.h"

// dbo
#include "SideIconGui.h"

/**
 * \ingroup Client
 * \brief PC방 HLS 정보/알림및 상점용 사이드 아이콘
 *
 * \date 2009-04-20
 * \author agebreak
 */
class CHLSSideIconGui : public CSideIconBase, public RWS::CEventHandler
{
public:
    CHLSSideIconGui(const RwChar* pName);
    virtual ~CHLSSideIconGui(void);

    RwBool		Create();
    VOID		Destroy();

    virtual VOID	OnIconButtonClicked(gui::CComponent* pComponent);
    virtual VOID	OnSideViewClosed();
    virtual void	Show(bool bShow);

protected:
    virtual VOID	HandleEvents( RWS::CMsg &msg );
    void            OnMouseEnter(gui::CComponent* pComponent);
    void            OnMouseLeave(gui::CComponent* pComponent);

protected:
    gui::CSlot      m_slotHLSBtn;
    gui::CSlot      m_slotHLSMouseEnter;
    gui::CSlot      m_slotHLSMouseLeave;
    gui::CButton*   m_pBtnHLS;
    RwBool          m_bNetmarbleMemberShip;
};
