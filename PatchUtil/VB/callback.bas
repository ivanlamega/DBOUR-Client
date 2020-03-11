Attribute VB_Name = "Module1"
Option Explicit

' Declaration for imported string copy function
Declare Function lstrcpy& Lib "kernel32" Alias "lstrcpyA" _
(ByVal lpDest As Any, ByVal lpSource As Any)

Declare Sub CopyMemory Lib "kernel32" Alias "RtlMoveMemory" _
(pdst As Any, pSrc As Any, ByVal nBytes As Long)

Declare Function lstrlenByNum& Lib "kernel32" Alias "lstrlenA" _
(ByVal lpString As Long)


' Sample CallBack function.  Note that there is very little
'  functionality in this CallBack.  It is meant as a guide on how
'  to define a CallBack that is of the form expected by our DLL
'
' The return value of this CallBack is often not used by RTPatchApply32.
'  However, returning a NULL value will cause the patch application
'  process to abort.  In this case a ZERO (0) represents NULL.
'
' In many Id cases we simply abort the patch.  You would want to
'  do something reasonable in these situations (ie ask user for
'  some input and then set CallBack to the result of that query.
'
' Note the use of the Long data type in place of pointers.  It is
'  neccessary to treat lpParm as a memory address, and then
'  do a memcopy in order to access the information contained
'  at that location.  Similarly, you must provide RTPatchApply32
'  with a memory address to the return value when required.  For example,
'  in the case of ID #19 (0x0013), RTPatch expects a pointer to a string
'  containing a yes/no answer to the location dialog question.
'  We simply accept whatever location is found and return the memory
'  address of a "y" string.  We use the undocumented function StrPtr.
'  Take care when using this function as it is difficult to obtain
'  support for it.
'
' Note also that in some cases, you are required to return a string
'  (e.g., CallBack 15 - password). You must convert the string you are
'  returning from Unicode. To do so, use the StrConv function with 
'  vbFromUnicode.

Function CallBack(ByVal Id As Long, ByVal lpParm As Long) As Long
        
  Dim lRetCode As Long
  Dim sBuffer As String
  Dim lLength As Long
  Dim Abort As Boolean
  Dim sYesString As String
  
  sYesString = String$(1, "y")
  lLength = lstrlenByNum(ByVal lpParm)
  sBuffer = String$(lLength, Chr$(0))
  lRetCode = lstrcpy(sBuffer, ByVal lpParm)
   
  'The VarPtr function in VB is considered to be an "undocumented feature"
  ' Issues of portability and forward comptability should be taken into
  ' consideration before using this function
  CallBack = VarPtr("")
  
  Select Case Id
    Case 1 To 4:
            'print warning and error messages
            Print #1, sBuffer
    
    Case 5: 'percent complete this file
            ' lpParm points to a 16-bit Int, thus do
            ' a memcopy at the address given in lpParm
            ' for 16 bits, or 2 bytes.
            
            'Note that the perComplete ranges from 0x0000 to
            ' 0x8000 (or 0 to 32768 in Base10).
            Dim perComplete As Long
            CopyMemory perComplete, ByVal lpParm, 2
    
    Case 6: 'number of patch files to process
            ' lpParm points to a 32-bit Int, thus do
            ' a memcopy at the address given in lpParm
            ' for 32 bits, or 4 bytes.
            Dim numPatchFiles As Long
            CopyMemory numPatchFiles, ByVal lpParm, LenB(numPatchFiles)
        
    Case 7: 'patch file start
    
    Case 8: 'current patch file complete
    
    Case 9 To 12:
            'print progress messages
            Print #1, sBuffer
    
    Case 13:
            'patch file dialog, return pointer to
              ' the full path of the patch file
            Print #1, "Aborted on Patch File Loaction Dialog (ID #13)"
            Abort = True
    Case 14:
            'invalid patch file
            Print #1, "Aborted on Invalid Patch File (ID #14)"
            Abort = True
             
    Case 15:
            'password dialog. 
            'remember to use password = StrConv (string, vbFromUnicode)
            Print #1, "Aborted on Password Dialog (ID #15)"
            Abort = True
             
    Case 16:
            'invalid password
            Print #1, "Aborted on Invalid Password (ID #16)"
            Abort = True
             
    Case 17:
            'next disk dialog
            Print #1, "Aborted on Next Disk Dialog (ID #17)"
            Abort = True
             
    Case 18:
            'invalid disk alert
            Print #1, "Aborted on Invalid Disk Alert (ID #18)"
            Abort = True
             
    Case 19:
            'location confirm
            
            ' Sample code provided demonstates how to access
            ' the systemName and systemLocation data.
            ' sysName and sysLoc hold this information after
            ' execution of the code below.  At this point, you may
            ' wish to prompt the user to confirm this location.
            
            ' We simply accept any location.
            
            ReDim buffer(2) As Long
            Dim sysName As String
            Dim sysLoc As String
            
            ' Copy array of string pointers into an array of LONGs
            CopyMemory buffer(0), ByVal lpParm, 2 * LenB(buffer(0))
        
            'Copy the systemName info into sysName
            lLength = lstrlenByNum(ByVal buffer(0))
            sysName = String$(lLength, Chr$(0))
            lRetCode = lstrcpy(sysName, ByVal buffer(0))
  
            'Copy the systemLocation info into sysLoc
            lLength = lstrlenByNum(ByVal buffer(1))
            sysLoc = String$(lLength, Chr$(0))
            lRetCode = lstrcpy(sysLoc, ByVal buffer(1))
         
            'Return the address of a "y" string.  Note above comment
            ' portability and forward compatibility when using the StrPtr
            ' function
            CallBack = StrPtr(sYesString)
             
    Case 20:
            'location dialog
            Print #1, "Aborted on Location Dialog (ID #20)"
            Abort = True
             
    Case 21: 'idle callBack
    Case 22: 'searching for system location
    
  End Select
  
  ' Return a zero if abort is true.  This will cause RTPatchApply32
  '  to ABORT the patch
  If Abort Then
    CallBack = 0
  End If
    
End Function


