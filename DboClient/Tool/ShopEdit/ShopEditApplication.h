#ifndef __GUIDEV_APPLICATION__
#define __GUIDEV_APPLICATION__

#include "NtlApplication.h"
#include "NtlCamera.h"

#include "gui_precomp.h"
#include "guicore_precomp.h"

class CTableContainer;

class CShopEditApplication : public CNtlApplication
{
protected:
	CNtlCamera*		m_pCamera;
	RtCharset*		m_pCharset;
	RwRGBA			m_BackgroundColor;
	RwRGBA			m_ForegroundColor;
	gui::CDialog*			m_pThis;

	// gui 
	gui::CResourceManager*	m_pResMgr;
	gui::CSurfaceManager*	m_pSurMgr;
	gui::CComponentManager*	m_pCompMgr;
	gui::CGUIManager*		m_pGuiMgr;
	

	std::string	m_strSurPage;
	std::string m_strSkillPage;
	std::string	m_strResPage;
	std::string m_strSkillResPage;
	std::string	m_strCompPage;

	COMPPAGE_HANDLE m_hCompPage;
	gui::CStaticBox*    m_pSttDialogTitle;
	gui::CButton*       m_pBtnClose;
	gui::CButton*       m_pBtnTitleName;
	gui::CButton*       m_pBtnTitleLevel;
	gui::CButton*       m_pBtnTitleLoc;
	gui::CButton*       m_pBtnTitleChannel;
	gui::CButton*       m_pBtnAdd;
	gui::CButton*       m_pBtnParty;
	gui::CButton*       m_pBtnMail;
	gui::CButton*       m_pBtnWhisper;
	gui::CButton*       m_pBtnBlock;
	gui::CButton*       m_pBtnDelete;
	gui::CScrollBar*    m_pSbScroll;
	gui::CStaticBox*    m_pSttLevel[13];
	gui::CStaticBox*    m_pSttLoc[13];
	gui::CStaticBox*    m_pSttChannel[13];
	gui::CPanel*        m_pPnlBackSpace[13];
	gui::CPanel*        m_pPnlIcon[13];

	// 슬롯
	gui::CSlot          m_slotClose;
	gui::CSlot          m_slotTab;
	gui::CSlot          m_slotBtnAdd;
	gui::CSlot          m_slotBtnParty;
	gui::CSlot          m_slotBtnMail;
	gui::CSlot          m_slotBtnWhisper;
	gui::CSlot          m_slotBtnBlock;
	gui::CSlot          m_slotBtnDelete;
	gui::CSlot          m_slotScroll;
	gui::CSlot          m_slotScrollMove;
	gui::CSlot          m_slotTabChange;
	gui::CSlot          m_slotMouseLeave;
	gui::CSlot          m_slotCaptureWheelMove;
	gui::CSlot          m_slotMouseMove[13];
	gui::CSlot          m_slotBtnMouseLeave[13];
	gui::CSlot          m_slotListWheelMove[13];
	gui::CSlot          m_slotToggled[13];
	gui::CSlot          m_slotBtnTitleName;
	gui::CSlot          m_slotBtnTitleLevel;
	gui::CSlot          m_slotBtnTitleLoc;
	gui::CSlot          m_slotBtnTitleChannel;

	RwUInt32            m_uiCurrentCharID;
	RwInt32             m_nButtonIndex;                     ///< 버튼에 이벤트 슬롯을 달기위한 변수
	RwInt32				m_iX_fromParent, m_iY_fromParent;
	gui::CButton*		m_pExitButton;				///< 창닫기 버튼


	// Help Button
	gui::CButton*		m_pBtnHelp;
	gui::CSlot			m_slotClickedBtnHelp;

	RwBool	m_bActiveBtn;

	//
	CTableContainer* m_pTableContainer;


	

	

protected:
	VOID	OnBtnClick( gui::CComponent* pComponent );
	VOID	OnActiveBtnClick( gui::CComponent* pComponent );
	VOID	OnInputReturn(VOID);
	VOID	OnScrollChanged( RwInt32 nNewOffset );
	VOID	OnCaptureWheelMove( RwInt32 nFlag, RwInt16 sDelta, CPos& pos );
	VOID	OnResizeSkillCustomize( RwInt32 nOldWidth, RwInt32 nOldHeight );
	VOID		OnListToggledCbbTitle(RwBool bToggled, gui::CComponent* pComponent);
	VOID		OnClickedBtnTitle(gui::CComponent* pComponent);
	VOID		OnSelectNpc(RwInt32 nIndex);

	void PopulateShopData(RwInt32 byIndex);

	VOID CreateInfoStaticBox();

	CRectangle GetPosition();
	
	RwBool	CreateSubSystem(RwUInt32 iWidth, RwUInt32 iHeight, RwBool zBuffer);
	LRESULT	PreTranslateMessage(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
	RwBool	Update(RwReal fTime, RwReal fElapsedTime);
	RwBool	Resize(RwUInt32 iWidth, RwUInt32 iHeight, RwBool zBuffer);

	void	DisplayInfo();
	RwBool	AttachPlugin();
	
public:

	CShopEditApplication(void);
	~CShopEditApplication(void);

	virtual void   Destroy();

	virtual LRESULT WndProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

	static CShopEditApplication * m_pInstance;
};

#endif
