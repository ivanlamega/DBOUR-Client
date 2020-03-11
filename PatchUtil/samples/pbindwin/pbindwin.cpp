//---------------------------
// C Source code
//---------------------------

#include	<windows.h>
#include	<setjmp.h>
#include	<string.h>

#include	"pbindwin.h"
#include	"resource.h"

#define		MAX_MESSAGES	10

# ifdef _WIN32
# define EXPORT 
# else
# define EXPORT __export
# define _MAX_PATH 260
# endif

BOOL InitApplication(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);
void WinIdle( void );
int MessagePump( void );

long FAR PASCAL EXPORT MainWndProc(HWND, UINT, WPARAM, LPARAM);
LPVOID CALLBACK EXPORT CallBack( UINT Id, LPVOID Parm );

void StartStatus( void );
void KillStatus( void );
void PutPct( int Pct );
void PutStatus( char * Line );
void PutCopyright( char * Line, char *Line2 );
void CenterWindow( HWND handle );

HINSTANCE hInst;
HWND hwnd;                                /* handle to main window           */
BOOL InCallBack = FALSE;


BOOL AbortPatch;
jmp_buf	QuitThisThing;
BOOL DLLActive = FALSE; 
BOOL PendingDestroy = FALSE;
char CmdLine[_MAX_PATH];
char Options[_MAX_PATH];
char VersionLine[100];
BOOL VersionSet = FALSE;
UINT RetCode;
RECT StartUpRect;
char UpdateDir[_MAX_PATH];
void far * CallBackParam;

PATCHCALLBACK CallBackPtr;

int StatusFlag=FALSE;
int StatusPct=0;

HWND hStatusDialog;
DLGPROC lpProcStatusDlg;

#define WM_PAINT_METER WM_USER+100


//----------------------------------------------------
// WinMain - initialization, main message loop
//----------------------------------------------------

int WINAPI WinMain(
  HINSTANCE hInstance, 
  HINSTANCE hPrevInstance, 
  LPSTR lpCmdLine, 
  int nCmdShow)
{

  MSG msg;
  int RetVal;
  
  // setup error handling for WinIdle, MyAlloc
  

  RetVal = setjmp( QuitThisThing ); // just in case a VERY early malloc fails...
  if (RetVal)
  {
    if (RetVal == -1)
      return( 0 );
    else
      return( RetVal );
  }
  if (!hPrevInstance  && !InitApplication(hInstance))
    return( FALSE );

  if (!InitInstance(hInstance, nCmdShow))
    return( FALSE );
  
  WinIdle();

  // Here you would do any "welcome messages"
  //  and acquire the Update Directory and options.

  strcpy( UpdateDir, "." );

  strcpy( Options, "" );


  WinIdle();
  // Execute Patch
  {
    char Buffer[_MAX_PATH];

    strcpy( CmdLine, "\"" );
    AnsiToOem( UpdateDir, Buffer );
    strcat( CmdLine, Buffer );
    strcat( CmdLine, "\" " );
    strcat( CmdLine, Options );

    AbortPatch = FALSE;
    DLLActive = TRUE;
    StartStatus();
    RetCode = RTPatchBoundApply( CmdLine, CallBackPtr, TRUE );
    if (!PendingDestroy)
    {
      DLLActive = FALSE;
      if (AbortPatch)

      {
        MessageBox( hwnd, "Update Aborted", "", MB_OK | MB_ICONINFORMATION );
	DestroyWindow( hwnd );
	longjmp( QuitThisThing, 1 );
      }
    }
    else
    {
      DLLActive = FALSE;
      DestroyWindow( hwnd );
      longjmp( QuitThisThing, 1 );
    }
  }


  WinIdle();
  // Success or failure messages go here

  if (RetCode ==0)
  {
    MessageBox( hwnd, 
    	"Update Successful", 
	"", 
	MB_OK | MB_ICONINFORMATION );
  }
  DestroyWindow( hwnd );

  while( GetMessage( &msg, NULL, 0, 0 ) )
  {
    TranslateMessage( &msg );
    DispatchMessage( &msg );
  }
  return( msg.wParam );

}



//----------------------------------------------------
// InitApplication - init window data and register window class
//----------------------------------------------------

BOOL InitApplication( HINSTANCE hInstance )
{
  WNDCLASS	wc;

  wc.style = 0;
  wc.lpfnWndProc = MainWndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;

  wc.hInstance = hInstance;
  wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// Your application icon
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = CreateSolidBrush( GetSysColor( COLOR_APPWORKSPACE ) );
  wc.lpszMenuName =  NULL;
  wc.lpszClassName = "CustomPatchWClass";

  return (RegisterClass(&wc));
}

//----------------------------------------------------
// InitInstance - saves instance handle and creates main window
//----------------------------------------------------

BOOL InitInstance( HINSTANCE	hInstance,
		   int		nCmdShow )
{
  hInst = hInstance;

  // Build main window

  hwnd = CreateWindow(
			  "CustomPatchWClass",
			  "",			// Your window title
			  WS_OVERLAPPEDWINDOW,
			  CW_USEDEFAULT,
			  CW_USEDEFAULT,
			  CW_USEDEFAULT,
			  CW_USEDEFAULT,
			  NULL,
			  NULL,
			  hInstance,
			  NULL
		      );
  CallBackPtr = (PATCHCALLBACK) MakeProcInstance( (FARPROC) CallBack, hInst );

  CenterWindow( hwnd );
  ShowWindow(hwnd, nCmdShow);
  UpdateWindow(hwnd);

  return (TRUE);
}
//----------------------------------------------------
// WinIdle - message processing with termination checking
//----------------------------------------------------
void WinIdle( void )
{
  WPARAM Code;

  if (-1 != (Code = MessagePump()))
  {
    if (Code == 0)
      longjmp( QuitThisThing, -1 );
    else
      longjmp( QuitThisThing, (int) Code );
  }
}

//----------------------------------------------------
// MessagePump - do some messages...
//----------------------------------------------------
int MessagePump( void )
{
  MSG msg;
  int Count;


  Count = MAX_MESSAGES;
  while( --Count && PeekMessage( &msg, NULL, 0, 0, PM_REMOVE ) )
  {
    if (msg.message == WM_QUIT)
      return( msg.wParam );
    TranslateMessage( &msg );
    DispatchMessage( &msg );
  }
  return(-1);
  
}


//----------------------------------------------------

// MainWndProc - process messages
//----------------------------------------------------

long PASCAL EXPORT MainWndProc(HWND hWnd, 
				     UINT message, 
				     WPARAM wParam, 
				     LPARAM lParam)
{

  switch (message) 
  {

    case WM_CLOSE:
      AbortPatch = TRUE;
      if (!DLLActive)
      {
        DestroyWindow( hWnd );
      }
      else
      {
        PendingDestroy = TRUE;
      }
      break;

    case WM_DESTROY:

      AbortPatch = TRUE;
      if (StatusFlag)
        KillStatus();
      FreeProcInstance( (FARPROC) CallBackPtr );
      FreeProcInstance( (FARPROC) lpProcStatusDlg );
      PostQuitMessage(0);
      break;

    case WM_SETFOCUS:
      if (StatusFlag)
      {
        SetFocus( hStatusDialog );
	break;
      }
    default:
      return( DefWindowProc(hWnd, message, wParam, lParam));
      
    
  }
  return( 0 );
}

//----------------------------------------------------

// Status window Dialog Box Proc
//----------------------------------------------------
BOOL CALLBACK EXPORT StatusProc( HWND handle, UINT Id, WPARAM wParam, LPARAM lParam)
{
    static HWND hStatusLine, hCopyrightLine, hProgressMeter;
    static HGDIOBJ hBkBrush, hWhiteBrush, hRedBrush, hSavedBrush;
    static HGDIOBJ hSavedPen, hBlackPen, hNullPen;
    static RECT ProgressRect;
    HDC hdc;
    int iPartition;
    char szPercent[8];
    BOOL   bRetFlag = FALSE;
    

    switch ( Id )
    {
        case WM_INITDIALOG:
           	// Set the title bar 
           	CenterWindow( handle );
		SetWindowText( handle, "Patch Progress" );
           	SetDlgItemText (handle, IDC_STATUS, "");
		SetDlgItemText (handle, IDC_COPYRIGHT, "" );
		SetDlgItemText (handle, IDC_COPYRIGHT2, "" );
		// save some useful handles...
        	hStatusLine = GetDlgItem( handle, IDC_STATUS );
        	hProgressMeter = GetDlgItem(handle, IDC_PROGRESS );

StatusPct=0;
		// Background Brush (light gray)
           	hBkBrush = GetStockObject(LTGRAY_BRUSH);
		// brush for right hand side of progress meter
           	hWhiteBrush = GetStockObject(WHITE_BRUSH);
           	// red brush for left hand side of progress meter
           	hRedBrush = CreateSolidBrush(RGB(255,0,0));
           	// Pens for various progress meter rectangles
           	hBlackPen = GetStockObject(BLACK_PEN);
           	hNullPen = GetStockObject(NULL_PEN);

            	bRetFlag = FALSE;
        break;

		case WM_PAINT:
        	InvalidateRect(hProgressMeter,NULL,TRUE);
        	UpdateWindow(hProgressMeter); 		 
        	GetClientRect(hProgressMeter, &ProgressRect);

        case WM_PAINT_METER: // Application defined message
		// simple progress meter: red on white with black
		// border.  Includes percent complete figure in center.

		if (StatusPct < 0)
		  StatusPct = 0;
		if (StatusPct > 100)

  StatusPct = 100;
        	hdc = GetDC(hProgressMeter);
        	iPartition = (int)((((long)ProgressRect.right) * ((long)StatusPct))/100);
		if (Id == WM_PAINT) 
		{
		  hSavedPen = SelectObject(hdc, hBlackPen);
		  hSavedBrush = SelectObject(hdc, hWhiteBrush);
        	  Rectangle(hdc, ProgressRect.left, ProgressRect.top, 
		  	ProgressRect.right, ProgressRect.bottom);
		  if (StatusPct)
		  {
        	    SelectObject(hdc, hNullPen);
        	    SelectObject(hdc, hRedBrush);

    Rectangle(hdc, ProgressRect.left+1, ProgressRect.top+1, 
		  	iPartition, ProgressRect.bottom);
		  }
        	}
        	else 
		{
        	  hSavedPen= SelectObject(hdc, hNullPen);
		  hSavedBrush = SelectObject(hdc, hRedBrush);
		  if (StatusPct)
		  {
		    Rectangle(hdc, ProgressRect.left+1, ProgressRect.top+1, 
		  	iPartition, ProgressRect.bottom);
		  }
		  if (StatusPct != 100)
		  {
		    SelectObject(hdc, hWhiteBrush);

    Rectangle(hdc, iPartition ? iPartition : iPartition+1, 
		  	ProgressRect.top+1, ProgressRect.right, ProgressRect.bottom);
	          }
		}
		SelectObject(hdc, hSavedBrush);
		SelectObject(hdc, hSavedPen);
		SetBkMode(hdc, TRANSPARENT);
		wsprintf(szPercent, "%u%%", StatusPct);
		DrawText(hdc, (LPCSTR) szPercent, -1, &ProgressRect, 
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hProgressMeter, hdc);        	
        	break;

# ifdef _WIN32
	    case WM_CTLCOLORSTATIC:
		case WM_CTLCOLORBTN:
		  SetBkMode( (HDC) wParam, TRANSPARENT );
		case WM_CTLCOLORDLG:
		  return( (BOOL) hBkBrush );
# else
	    case WM_CTLCOLOR:
		switch (HIWORD(lParam))
		{
		  case CTLCOLOR_STATIC:
		  case CTLCOLOR_BTN:
		    SetBkMode((HDC) wParam, TRANSPARENT);
		  case CTLCOLOR_DLG:
		    return ((BOOL) hBkBrush);
		}
# endif
	      case WM_DESTROY:
		// free up resources

DeleteObject(hRedBrush);
		StatusFlag = FALSE;
		return (0);

	      case WM_COMMAND:
		switch (wParam)
		{
		  case IDCANCEL:
		    AbortPatch = TRUE;
		    KillStatus();
		    return( TRUE );
	  
		  default:
		    break;
		}
		break;

        default:
             break;
    }
    return (bRetFlag);
}
//----------------------------------------------------
// StartStatus - fires up the status window
//----------------------------------------------------

void StartStatus( void )
{
  if (!StatusFlag)
  {
    StatusFlag = TRUE;
    lpProcStatusDlg = MakeProcInstance( StatusProc, hInst );
    hStatusDialog = CreateDialog(hInst, "StatusBox", 
    	hwnd, lpProcStatusDlg );
  }
}

//----------------------------------------------------
// KillStatus - removes the status window
//----------------------------------------------------
void KillStatus( void )
{
  DestroyWindow( hStatusDialog );
  StatusFlag = FALSE;

}
//----------------------------------------------------
// PutPct - sets the main progress meter value
//----------------------------------------------------
void PutPct( int Pct )
{
  if (StatusFlag && Pct != StatusPct)
  {
    StatusPct = Pct;
    SendMessage( hStatusDialog, WM_PAINT_METER, 0, 0);
  }
}
//----------------------------------------------------
// PutStatus - sets the main status line text
//----------------------------------------------------

void PutStatus( char * Line )
{
  char Buffer[200];

  if (StatusFlag)
  {
    OemToAnsi( Line, Buffer );
    SetDlgItemText( hStatusDialog, IDC_STATUS, Buffer );
  }
}
//----------------------------------------------------
// PutCopyright - sets the copyright line text
//----------------------------------------------------
void PutCopyright( char * Line, char *Line2 )
{
  char Buffer[200];

  if (StatusFlag)
  {
    OemToAnsi( Line, Buffer );
    SetDlgItemText( hStatusDialog, IDC_COPYRIGHT, Buffer );

    OemToAnsi( Line2, Buffer );
    SetDlgItemText( hStatusDialog, IDC_COPYRIGHT2, Buffer );
  }
}
//----------------------------------------------------
// CenterWindow - centers window on Parent, making sure
//	we don't go out of bounds
//----------------------------------------------------

void CenterWindow( HWND handle )
{
  HWND Parent;
  RECT MyRect;
  RECT ParentRect;
  RECT BigRect;
  int  left, top, height, width;

  Parent = GetParent( handle );

  if (Parent)
  {
    GetWindowRect( Parent, &ParentRect );
  }
  else
  {
    GetWindowRect( GetDesktopWindow(), &ParentRect );
  }
  GetWindowRect( handle, &MyRect );
  GetWindowRect( GetDesktopWindow(), &BigRect );
  width = MyRect.right - MyRect.left;
  height = MyRect.bottom - MyRect.top;
  left = ParentRect.left + ((ParentRect.right - ParentRect.left) - width)/2;
  top = ParentRect.top + ((ParentRect.bottom - ParentRect.top) - height)/2;
  if (left < 0)

    left = 0;
  if (top < 0)
    top = 0;
  if (width > BigRect.right)
    width = BigRect.right;
  if (height > BigRect.bottom)
    height = BigRect.bottom;
  if ((left+width) > BigRect.right)
    left = BigRect.right - width;
  if ((top+height) > BigRect.bottom)
    top = BigRect.bottom - height;
  MoveWindow( handle,	left, top, width, height, TRUE );
}

//----------------------------------------------------
// CallBack - handle callbacks from the DLL
//----------------------------------------------------

LPVOID CALLBACK EXPORT CallBack( UINT Id, LPVOID Parm )
{ 
  MSG msg;
  UINT MsgCount;
  LPVOID RetVal;

  CallBackParam = Parm; 
  InCallBack=TRUE;
  RetVal = "";
  
  // do a few messages while we're here...
  
  for ( MsgCount = MAX_MESSAGES;
	MsgCount && PeekMessage( &msg, NULL, 0, 0, PM_REMOVE );
  	MsgCount--)
  {
    TranslateMessage( &msg );
    DispatchMessage( &msg );
  }
  

  switch( Id )
  {
    case 1:
    case 3:

    case 9:
    case 0xa:
    case 0xb:
      // these are all text output...
      break;

    case 2:
      // warning 
      OemToAnsi(  (const char *) Parm,  (char *) Parm );
      if (IDCANCEL ==
	MessageBox( hwnd,  (const char *) Parm, 
		"Patch Warning", MB_ICONEXCLAMATION | MB_OKCANCEL ) )
	AbortPatch = TRUE;
      break;

    case 4:
      // error
      OemToAnsi( (const char *) Parm,  (char *) Parm );
      MessageBox( hwnd,  (const char *) Parm, "Patch Error", MB_ICONSTOP | MB_OK );
      break;

    case 0xc:

      // set copyright string
      // parse it - format is sep line, centered line 1 (product name),
      //	centered line 2 (platform/edition info), then second call has centered line 3
      //	( copyright info), sep line, blank line
      {
        char *Ptr, *Ptr2; 
    
        if (!VersionSet)
        {
          Ptr = (char *) Parm;
          if (!strlen(Ptr))
            break;
          Ptr2 = NULL;
          Ptr += strcspn( Ptr, "\n" );
          if (*Ptr)
          {
            Ptr++;
            Ptr2 = Ptr;

          }
          Ptr += strcspn( Ptr, "\n" );
          if (*Ptr)
          {
            *Ptr = '\0';
          }
          Ptr2 += strspn( Ptr2, " \t\n" );
          strcpy( VersionLine, Ptr2 );
          VersionSet = TRUE;
        }
        else
        {
          Ptr = Ptr2 = (char *) Parm;
          Ptr += strcspn( Ptr, "\n" );
          if (*Ptr)
          {
            *Ptr = '\0';
          }  
          Ptr2 += strspn( Ptr2, " \t\n" );
          PutCopyright( VersionLine, Ptr2 );

        }

      }
      break;



    case 5:
      // % complete
      PutPct( (int) (((long)(0xffff & *((UINT *) Parm))*100L)/0x8000L) );
      break;

    case 6:
      // Number of patch files
      break;

    case 7:
      // begin patch
      {
        char	Buffer[ 100 ];

        strcpy( Buffer, "Processing: " );
	    strcat( Buffer, (const char *) Parm );
	    PutStatus( Buffer );
      }
      break;

    case 8:
      // end patch 
      PutStatus(" ");

      PutPct( 0 );
      break;

    case 0xd:
      // this one shouldn't happen (only occurs if the patch file
      //   file bound to the executable is invalid in some way).
      MessageBox( hwnd, "Callback 0D", "Abort", MB_OK );
      AbortPatch = TRUE;
      break;

    case 0xe:
      // this one shouldn't happen either (same reason)
      break;

    case 0xf:
      // Do password dialog here (abort in this skeleton)
      AbortPatch = TRUE;
      break;

    case 0x10:
      // Incorrect password alert
      break;

    case 0x11:
      // do disk change dialog (abort in this skeleton)
      AbortPatch = TRUE;
      
      break;

    case 0x12:
      // Invalid disk alert (abort in this skeleton)
      AbortPatch = TRUE;
      break;

    case 0x13:
      // system location confirmation (always returns "Y" in this skeleton)
      RetVal = "Y";
      break;
      
    case 0x14:
      // Do Location Dialog (abort in this skeleton)

      AbortPatch = TRUE;
      break;
      
     case 0x16:
       PutStatus( "Searching for Systems to Update..." );
       PutPct( 0 );
       break;
       
     case 0x15:
    default:
      break;

  } 
  
  // do a few more messages while we're here...
  
  for ( MsgCount = MAX_MESSAGES;
	MsgCount && PeekMessage( &msg, NULL, 0, 0, PM_REMOVE );
  	MsgCount--)
  {
    TranslateMessage( &msg );
    DispatchMessage( &msg );
  }
  

  InCallBack = FALSE;

  if (AbortPatch)
    return (NULL);
  else
    return (RetVal);
}