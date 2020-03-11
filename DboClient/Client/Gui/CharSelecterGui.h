/******************************************************************************
* File			: CharSelecterGui.h
* Author		: Hong SungBock
* Copyright		: (주)NTL
* Date			: 2007. 10. 15
* Abstract		:
*****************************************************************************
* Desc KR		: 자신의 캐릭터중 플레이할 캐릭터를 선택하기 위한 GUI
* Desc EN		: GUI for selecting one of your characters to play
*****************************************************************************/

#pragma once

#include <list>

// core
#include "ceventhandler.h"

// share
#include "NtlSharedDef.h"

// gui
#include "gui_button.h"

// presentation
#include "NtlPLGui.h"

// simulation
#include "Inputhandler.h"

// dbo
#include "Windowby3.h"


class CCharSelecterGui : public CNtlPLGui, public RWS::CEventHandler
{
public:
	enum eCharState
	{
		CHAR_STATE_NORMAL,
		CHAR_STATE_RESERVATED_DEL,

		NUM_CHAR_STATE
	};

	struct sCharSlot
	{
		gui::CButton*		pButton[NUM_CHAR_STATE];
		gui::CStaticBox*	pName;
		gui::CStaticBox*	pLevel;

		gui::CStaticBox*	pNewCharacter;
		gui::CStaticBox*	pNewCharacterFoc; 

		CSurfaceGui			srfRace;

		gui::CSlot			m_slotButton[NUM_CHAR_STATE];
		gui::CSlot			m_slotButtonMove[NUM_CHAR_STATE];
		gui::CSlot			m_slotButtonLeave[NUM_CHAR_STATE];

		RwBool				m_bHaveChar;
		RwUInt8				m_byState;

		sCharSlot() : m_bHaveChar(true), m_byState(CHAR_STATE_NORMAL)
		{}

		VOID SetPosition(RwInt32 iXPos, RwInt32 iYPos)
		{			
			srfRace.SetPosition(iXPos + 12, iYPos + 15);
		}

	VOID Render(RwBool bFocus)
	{
		if (m_bHaveChar)
		{
			srfRace.Render();
		}
		else
		{
			if (bFocus)
				pNewCharacter;
			else
				pNewCharacterFoc;
		}
	}
};

	CCharSelecterGui(const RwChar* pName);
	virtual ~CCharSelecterGui();

	virtual RwBool		Create();
	virtual VOID		Update(RwReal fElapsed);
	virtual VOID		Destroy();

	VOID		SetPosition(RwInt32 iXPos, RwInt32 iYPos);

protected:
	CCharSelecterGui() {}
	virtual VOID	HandleEvents( RWS::CMsg &msg );

	VOID			SelectSlot(RwUInt8 byIndex);
	VOID			SetDelButton();

	VOID			EnableButtons(bool bEnable);

	VOID			OnClickCharButton(gui::CComponent* pComponent);
	VOID			OnClickDelCharButton(gui::CComponent* pComponent);
	VOID			OnClickRecoveryCharButton(gui::CComponent* pComponent);
	VOID			OnMouseButtonMove(RwInt32 nFlags, RwInt32 nX, RwInt32 nY);
	VOID			OnMouseButtonLeave(gui::CComponent* pComponent);
	VOID			OnPaint();
	VOID			OnPostPaint();

protected:	
	gui::CSlot			m_slotCharDelButton;
	gui::CSlot			m_slotCharRecoveryButton;
	gui::CSlot			m_slotPaint;
	gui::CSlot			m_slotPostPaint;

	CWindowby3			m_Background_UP;	///< ¹è°æ »ó´Ü
	CWindowby3			m_Background_DOWN;	///< ¹è°æ ÇÏ´Ü

	//CSurfaceGui			m_srfTitleText;		///< Title text	surface

	gui::CStaticBox*	m_pTitle; /// Character List Title

	gui::CButton*		m_pCharDelButton;	///< Ä³¸¯ÅÍ »èÁ¦ ¹öÆ°
	gui::CButton*		m_pCharRecoveryButton;///< Ä³¸¯ÅÍ º¹±¸ ¹öÆ°

	gui::CFrame*		m_pPostPaintDummy;

	RwUInt8				m_byFocusIndex;

	sCharSlot			m_CharSlot[NTL_MAX_COUNT_USER_CHAR_SLOT];///< Ä³¸¯ÅÍ ½½·Ô
};