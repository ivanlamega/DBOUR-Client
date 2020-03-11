
/*-------------------------------------------------------------------------*\
|                                                                           |
|  FILE: ISRTP.H	                                                    |
|                                                                           |
|                                                                           |
|   RTPatch InstallShield(TM) Interface DLL API Header File		    |
|                                                                           |
|                                                                           |
|  (C) Copyright Pocket Soft, Inc. 1998-2002.  All Rights Reserved.         |
|                                                                           |
\*-------------------------------------------------------------------------*/
#ifndef ISRTP_INCLUDED
#define ISRTP_INCLUDED

//----------------------------------------------------
// Manifest constants
//----------------------------------------------------
# define ISPATCH_FULL_PATHS		0x1
# define ISPATCH_SEARCH_ALL		0x2
# define ISPATCH_SUPPRESS_WARNINGS	0x4
# define ISPATCH_SUPPRESS_ERRORS	0x8
# define ISPATCH_SUPPRESS_STATUS	0x10
# define ISPATCH_SUPPRESS_COPYRIGHT	0x20
# define ISPATCH_NO_USER_INTERACTION	0x40
# define ISPATCH_SUPPRESS_ALL		0x7c
# define ISPATCH_OEM_PATCHFILE		0x80
# define ISPATCH_SEARCH_NET		0x100
# define ISPATCH_LOG_FILE		0x200
# define ISPATCH_REBOOT_WARN		0x400
# define ISPATCH_REBOOT_RESTART 	0x800
# define ISPATCH_MAX			0x4000
# define ISPATCH_MIN			0
# define ISPATCH_CENTER			-1

//----------------------------------------------------------
// ISRTPatch16 and ISRTPatch32 - main entry point prototypes
//----------------------------------------------------------

prototype isrtp16.ISRTPatch16( NUMBER, STRING, STRING, STRING, STRING, STRING, LONG, LONG, LONG );
prototype isrtp32.ISRTPatch32( NUMBER, STRING, STRING, STRING, STRING, STRING, LONG, LONG, LONG );

//-------------------------------------------------------------------
// GetCurrentDirectory and GetCurrentFolder - used to store the CWD
//-------------------------------------------------------------------
prototype NUMBER KERNEL.GetCurrentDirectory ( NUMBER, STRING );
prototype NUMBER GetCurrentFolder( STRING );

//-------------------------------------------------------------------
// ISRTPatch16SetText and ISRTPatch32SetText - secondary entry points
//-------------------------------------------------------------------

prototype isrtp16.ISRTPatch16SetText( STRING, STRING, STRING, STRING );
prototype isrtp32.ISRTPatch32SetText( STRING, STRING, STRING, STRING );

//--------------------------------------
// ISRTPatch - script function prototype
//--------------------------------------

prototype ISRTPatch(
	STRING, 	// full path for Patch File
	STRING, 	// full path for Apply Directory
	STRING, 	// Title for Status Window
	STRING, 	// .RTPatch options string
	LONG, 		// other (interface) options
	LONG, 		// vertical positioning
			//   ISPATCH_MIN => top
			//   ISPATCH_MAX => bottom
			//   ISPATCH_CENTER => centered
	LONG );		// horizontal positioning
			//   ISPATCH_MIN => left
			//   ISPATCH_MAX => right
			//   ISPATCH_CENTER => centered


//---------------------------------------------
// ISRTPatchSetText - script function prototype
//---------------------------------------------

prototype ISRTPatchSetText(
	STRING,		// override text for Copyright line 1
	STRING,		// override text for Copyright line 2
	STRING );	// override text for Status line

//---------------------------------------------
// ISRTPatchSetLogFile - script function prototype
//---------------------------------------------

prototype ISRTPatchSetLogFile(
	STRING );	// override Log File name

// global variables for use by ISRTPatchSetText mechanism

BOOL bISRTPOverrides;
BOOL bISRTPLFPresent;
STRING szISRTPCopy1;
STRING szISRTPCopy2;
STRING szISRTPStatus;
STRING szISRTPLogFile;
# endif /* ISRTP_INCLUDED */

