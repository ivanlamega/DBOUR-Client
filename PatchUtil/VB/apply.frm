VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H80000004&
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "RTPatch Apply"
   ClientHeight    =   2130
   ClientLeft      =   45
   ClientTop       =   345
   ClientWidth     =   7125
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2130
   ScaleWidth      =   7125
   ShowInTaskbar   =   0   'False
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Cancel 
      Caption         =   "Cancel"
      Height          =   375
      Left            =   5640
      TabIndex        =   3
      Top             =   1440
      Width           =   1215
   End
   Begin VB.CommandButton Apply 
      Caption         =   "Apply"
      Height          =   375
      Left            =   3960
      TabIndex        =   2
      Top             =   1440
      Width           =   1215
   End
   Begin VB.TextBox Edit 
      Height          =   375
      Left            =   1440
      TabIndex        =   0
      Top             =   840
      Width           =   5415
   End
   Begin VB.Label Label1 
      BackColor       =   &H80000004&
      Caption         =   "Enter patch commandLine:"
      Height          =   255
      Left            =   120
      TabIndex        =   1
      Top             =   360
      Width           =   2655
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
' Declaration for the imported RTPatchApply32 function.  Note that it is
' aliased to RTPatchApply32@12 to take into account name decoration.
' Also note the use of the ByVal keyword.
Private Declare Function RTPatchApply32 Lib "patchw32" Alias "RTPatchApply32@12" _
(ByVal cmdLine As String, ByVal CalledBack As Any, ByVal WaitFlag As Boolean) _
As Integer

' Upon selection of the "Apply" button, copy the given command line
' and start the patching process.  Note that there is no error checking
' on the commandline entered
Private Sub Apply_Click()
  Dim result As VbMsgBoxResult  ' Result of MessageBox
  Dim cmdLine As String         ' CommandLine to pass to RTPApply
  Dim retVal As Long
  cmdLine = Edit.Text
  
  ' Check to make sure the user entered a cmdLine
  If cmdLine <> "" Then
    ' Open a file to send output
    Open "patch.log" For Output As #1
    
    ' Call RTPatchApply32
    retVal = RTPatchApply32(cmdLine, AddressOf CallBack, True)
    
    ' You should use the return value of RTPatchApply32 to determine
    ' the success/failure of the patch apply process
    MsgBox "RTPatchApply32 returned a value of: " + str(retVal) + Chr(10) + Chr(13) + Chr(10) + Chr(13) + _
            "You should use this return value to give useful feedback to your end-user", _
            vbOKOnly, _
            "Patching Complete"
    
    End
  End If
  
 
End Sub

' Terminate application if the Cancel button is selected.
Private Sub Cancel_Click()
  End
End Sub
