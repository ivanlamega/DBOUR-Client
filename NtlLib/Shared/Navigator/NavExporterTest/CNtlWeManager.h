//*****************************************************************************
// File       : CNtlWeManager.h
// Desc       : 
// Begin      : 
// Copyright  : 
// Author     : 
// Update     : 
//*****************************************************************************

#ifndef ___C_NTL_WE_MANAGER_H___
#define ___C_NTL_WE_MANAGER_H___

//-----------------------------------------------------------------------------
// Pre-Compiler Option Table
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Header Table
//-----------------------------------------------------------------------------

#include "NavExporterTest.h"


//-----------------------------------------------------------------------------
// Name Space Table
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Constant Table
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// Type Definition Table
//-----------------------------------------------------------------------------


//=============================================================================
// Name       : CNtlWeManager
// Desc       : 
// Author     : 
//=============================================================================

class CNtlWeManager : public CWeManager
{
	protected:

		HWND							m_hWnd;

	public:

		inline void						SetWnd( HWND hWnd ) { m_hWnd = hWnd; }

		inline void						Message( const CFixedString & rcString ) const { SetWindowText( m_hWnd, rcString.GetBuffer() ); }

	public:

		static CWeManager *				CreateFileConverter( void ) { return new CNtlWeManager; }
		static void						DestroyFileConverter( CNtlWeManager ** ppcConverter ) { delete *ppcConverter; *ppcConverter = NULL; }
};

//=============================================================================
// End of Class : CNtlWeManager
//=============================================================================

#endif //___C_NTL_WE_MANAGER_H___

//*****************************************************************************
//
// End of File : CNtlWeManager.h
//
//*****************************************************************************