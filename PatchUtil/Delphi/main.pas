{ This simple example shows the syntax for linking into the 16-bit and
  32-bit DLLs and calling RTPatchApply or RTPatchApply32 from a Delphi
  app.  A single form is included in this project with one edit field,
  an 'apply' button and a 'cancel' button.  The user is expected to
  type a fully qualified cmdLine in the edit box and then click on
  'apply'  All output is directed to a file in order to make this
  example as self-contained as possible. }


unit Main;

interface

uses
  SysUtils, WinTypes, WinProcs, Messages, Classes, Graphics, Controls,
  Forms, Dialogs, StdCtrls;

type
  TMainForm = class(TForm)
    InputField: TEdit;
    Label1: TLabel;
    Apply: TButton;
    Cancel: TButton;
    procedure ApplyClick(Sender: TObject);
    procedure CancelClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

const
  MAX_MESSAGES = 10;   { Max number of messages to process at any one time}

var
  MainForm: TMainForm;
  CallBackProc: TFarProc;
  hWND: THandle;

  ReOpenBuf: TOFStruct; { some variables for our output file}
  Output: file;
  FileId: Integer;


{ Declare the CallBack function.  If we are compiling in a 32-bit
  world, we need to declare the CallBack as stdcall }
function CallBack (id: Cardinal; lpParm: pointer): pchar;
  export;
{$IFDEF WIN32}
 stdcall;
{$ENDIF}

{ Declare the RTPatchApply32 function, depending on the platform, this
  may be RTPatchApply or RTPatchApply32 }
{$IFDEF WIN32}
function RTPatchApply32 ( cmdLine: pChar; CallBack: pointer;
WaitFlag: boolean ): word; stdcall;
{$ELSE}
function RTPatchApply ( cmdLine: pChar; CallBack: pointer;
WaitFlag: boolean ): word;
{$ENDIF}

implementation

{ Declare the RTPatchApply function }
{$IFDEF WIN32}
function RTPatchApply32; external 'patchw32.dll'
  name 'RTPatchApply32@12';
{$ELSE}
function RTPatchApply; external 'patchw';
{$ENDIF}

{$R *.DFM}

{ called when the user clicks 'apply' }
procedure TMainForm.ApplyClick(Sender: TObject);
var
  cmdLine: pChar;
  retCode: short;

begin
  { Allocate space for the cmdLine, copy it from the edit box of the
    MainForm, and call RTPatchapply with that commandLine }
  cmdLine:= strAlloc(255);
  MainForm.InputField.GetTextBuf(cmdLine, 255);

{$IFDEF WIN32}
  retCode:= RTPatchApply32(cmdLine, @CallBack, TRUE);
{$ELSE}
  retCode:= RTPatchApply(cmdLine, @CallBack, TRUE);
{$ENDIF}

  { Display the retCode of RTPatchApply32. You should use the
    documentation provided to determine the cause of a specific retcode.
    Zero indicates success. }
  MessageDlg('RTPatchApply32 returned a value of: ' +
            IntToStr (retCode) +  #10#13#10#13 +
            'You should use this value to provide feedback to your end-user.',
            mtInformation,
            [mbOK],
            0);

  { Free some variables and quit }
  strDispose (cmdLine);
  Application.Terminate;

end;

{ This sample CallBack function has little functionality.  It is provided
  to demonstrate the syntax for the CallBack that RTPatchApply expects.
  Our example Aborts on many IDs.  You would need to add something
  reasonable in place of the command 'result:= NIL;' In most cases
  you can get to the lpParm parameter by typecasting to a pChar.
  For ID0013, it is necessary to access two string pointers, thus
  you will have to do the following:
    TYPE
      Tarray=array[0..1] of pChar;
      Locarray=^Tarray;

  You can then access the first string with LocArray(lpParm)^[0]
    and the second field with LocArray(lpParm)^[1]
}
function CallBack (Id: Cardinal; lpParm: pointer) : pChar;
type
  Tarray = array[0..1] of pChar;
  Locarray= ^Tarray;

var
  msg: TMsg;
  MsgCount: Integer;
  sysName: pChar;
  sysLoc: pChar;

begin

  result:= '';

  { Do some message processing while we are here }
  for  MsgCount := MAX_MESSAGES DOWNTO 0 DO
  begin
    if (PeekMessage( msg, hWND, 0, 0, PM_REMOVE ) = false) then
      break;
    TranslateMessage( msg );
    DispatchMessage( msg );
  end;

  case id of

    1..4: { Print some warning/error messages to a file }
        _lwrite(FileId, pChar(lpParm), strLen(pChar(lpParm)));

   { 5: } { % Complete THIS file (not entire patch process % complete)
         Here you may want to update a progress meter, or otherwise
         let your customer know that some kind of progress is being
         made.

         Note that lpParm is a far pointer to a 16-bit unsigned integer,
         Thus the way to access the % complete for the current file is:
         percComplete := word(lpParm^)

         The range for percComplete would be 0x0000 .. 0x8000
         or 0 .. 32768 (Base10)
         }

   { 6: } { Number of patch files to patch
            This number may be useful to determine a rough estimate
            on percent complete for entire patch process

            Note that lpParm is a far pointer to a 32-bit Integer,
            Thus the way to access the number of patch files is to
            use: numPatchFiles := longint(lpParm^)
            }

   { 7: } { Patch file start
            Use to inform user which file is being patched }

   { 8: } { Current file patch Complete }

     9: { Print a progress message }
       _lwrite(FileId, pChar(lpParm), strLen(pChar(lpParm)));

    10:  { Print a help message }
       _lwrite(FileId, pChar(lpParm), strLen(pChar(lpParm)));

    11:  { Print a patch file comment }
       _lwrite(FileId, pChar(lpParm), strLen(pChar(lpParm)));

    12: { Print Copyright Information
          You may choose to substitute your own copyright information
          at this point}
       _lwrite(FileId, pChar(lpParm), strLen(pChar(lpParm)));

    13:  { Patch File dialog
             Occurs when the indicated patch file can not be found, or
             no patch file name was provided.  Set result to the full
             path to the patch file.  For now, abort the patch. }
        begin
          Result:= NIL;
          _lwrite(FileId, 'Aborted on ID 13', 16);
        end;

    14: { Invalid patch file alert
          Insert messages about contacting technical support here.
          For now, just abort the patch }
        begin
          Result:= NIL;
          _lwrite(FileId, 'Aborted on ID 14', 16);
        end;

    15: { Password Dialog
          (If patch file is password protected) return pointer to
          password.  For now, dont allow this.  Abort patch. }
        begin
          Result:= NIL;
          _lwrite(FileId, 'Aborted on ID 15', 16);
        end;

    16: { Invalid password alert
          Prompt user for password again.  We shouldn't get here
          since we abort on password dialog }
        begin
          Result:= NIL;
          _lwrite(FileId, 'Aborted on ID 16', 16);
        end;

    17: { Next Disk dialog
          If using the split option, then return the disk change string.
          For now, abort the patch. }
        begin
          Result:= NIL;
          _lwrite(FileId, 'Aborted on ID 17', 16);
        end;

    18: { Invalid disk alert
          Inserted disk does not contain valid patch files.
          For now abort patch. }
        begin
          Result:= NIL;
          _lwrite(FileId, 'Aborted on ID 18', 16);
        end;

    19: { Location confirmation dialog
            If using SYSTEMTAGs and confirm, allow user to
            accept/deny the system location.  Our CallBack
            always accepts : 'YES'
          Note that the variables sysName and sysLoc hold
            the system information. }
        begin
          sysName:= stralloc(255);
          sysLoc:= strAlloc (255);
          strCopy (sysName, LocArray(lpParm)^[0]);
          strCopy (sysLoc, LocArray(lpParm)^[1]);

     { ... Do something here. Possibly display the
       system info contained in sysName and sysLoc ... }

          Result:= 'Y';     { Accept system Location }
          strDispose (sysName);
          strDispose (sysLoc);
        end;

    20: { Location dialog
          If system is not found, then have the user supply patch
          with that location.  Return full path to the system location.
          For now, simply abort the patch. }
        begin
          Result:= NIL;
          _lwrite(FileId, 'Aborted on ID 20', 16);
        end;

  { 21: } { Idle CallBack
            Included to provide Message dispatching and to keep
            the system responsive to the user }

  { 22: } {Searching for system CallBack }

  end;

  { Do some more message processing while we are here }
  for  MsgCount := MAX_MESSAGES DOWNTO 0 DO
  begin
    if (PeekMessage( msg, hWND, 0, 0, PM_REMOVE ) = false) then
      break;
    TranslateMessage( msg );
    DispatchMessage( msg );
  end;

  { The contents of Result are often not used, but in all cases
    returning a NIL value in Result will Abort the patch.  Thus if
    the return value is not used, and the patching should continue,
    you should assign Result to '', or some other non-NIL value. }

end;

{ If user selects 'Cancel' just kill the application }
procedure TMainForm.CancelClick(Sender: TObject);
begin
  application.Terminate;
end;


{ Startup stuff:
    Get a handle for the output file
    Get a handle for the application to do message
      processing. }
begin
  fileId := OpenFile('Patch.log', ReOpenBuf, OF_CREATE);
  if (fileId = -1) then
    raise exception.create('Unable to open output file.');
  hWND:= Application.Handle;
end.
