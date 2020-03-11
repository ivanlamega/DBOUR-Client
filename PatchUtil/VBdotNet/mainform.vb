Public Delegate Function CallBack(ByVal Id As Integer, ByVal Parm As IntPtr) As IntPtr

' Sample CallBack function.  Note that there is very little
'  functionality in this CallBack.  It is meant as a guide on how
'  to define a CallBack that is of the form expected by our DLL
'
' The return value of this CallBack is often not used by RTPatchApply32.
'  However, returning a NULL pointer will cause the patch application
'  process to abort. 
'
' In many Id cases we simply abort the patch.  You would want to
'  do something reasonable in these situations (ie ask user for
'  some input and then set CallBack to the result of that query.
'
' Note that in some cases, you are required to return a string
'  (e.g., CallBack 15 - password). To do so, use this syntax:
'  RTPatchCallBack = Runtime.InteropServices.Marshal.StringToHGlobalAnsi("string")

Public Class RTPatch

    Declare Function lstrcpy Lib "kernel32" Alias "lstrcpyA" (ByVal lpDest As String, ByVal lpSource As IntPtr) As Integer
    Declare Sub CopyMemory Lib "kernel32" Alias "RtlMoveMemory" (ByRef pdst As Integer, ByVal pSrc As IntPtr, ByVal nBytes As Integer)
    Declare Function lstrlenByNum Lib "kernel32" Alias "lstrlenA" (ByVal lpString As IntPtr) As Integer
    Declare Sub CopyMemory2 Lib "kernel32" Alias "RtlMoveMemory" (ByRef pdst As IntPtr, ByVal pSrc As IntPtr, ByVal nBytes As Integer)

    ' Declare the apply entry point
    Declare Ansi Function RTPatchApply32 Lib "patchw32.dll" Alias "RTPatchApply32@12" _
     (ByVal CmdLine As String, _
      ByVal PatchCallBack As CallBack, _
      ByVal WaitFlag As Boolean) As Integer

    ' Declare the CallBack function
    Public Shared Function RTPatchCallBack(ByVal Id As Integer, ByVal Parm As IntPtr) As IntPtr
        Dim lRetCode As Integer
        Dim lLength As Integer
        Dim Abort As Boolean
        Dim sYesString As String
        Dim sBuffer As String
        sYesString = New String("y", 1)

        RTPatchCallBack = Runtime.InteropServices.Marshal.StringToHGlobalAnsi("")

        Dim perComplete As Integer
        Dim numPatchFiles As Integer
        Dim sysName As String
        Dim sysLoc As String
        Select Case Id
            Case 1 To 4
                'print warning and error messages
                lLength = lstrlenByNum(Parm)
                sBuffer = New String(Chr(0), lLength)
                lRetCode = lstrcpy(sBuffer, Parm)
                PrintLine(1, Parm)

            Case 5 'percent complete this file
                ' Parm points to a 16-bit Int, thus do
                ' a memcopy at the address given in Parm
                ' for 16 bits, or 2 bytes.

                'Note that the perComplete ranges from 0x0000 to
                ' 0x8000 (or 0 to 32768 in Base10).
                CopyMemory(perComplete, Parm, 2)

            Case 6 'number of patch files to process
                ' Parm points to a 32-bit Int, thus do
                ' a memcopy at the address given in Parm
                ' for 32 bits, or 4 bytes.
                CopyMemory(numPatchFiles, Parm, 4)

            Case 7 'patch file start

            Case 8 'current patch file complete

            Case 9 To 12
                'print progress messages
                lLength = lstrlenByNum(Parm)
                sBuffer = New String(Chr(0), lLength)
                lRetCode = lstrcpy(sBuffer, Parm)
                Print(1, sBuffer)

            Case 13
                'patch file dialog, return pointer to
                ' the full path of the patch file
                PrintLine(1, "Aborted on Patch File Loaction Dialog (ID #13)")
                Abort = True
            Case 14
                'invalid patch file
                PrintLine(1, "Aborted on Invalid Patch File (ID #14)")
                Abort = True

            Case 15
                'password dialog. 
                ' Use the following syntax
                ' RTPatchCallBack = Runtime.InteropServices.Marshal.StringToHGlobalAnsi("password")
                PrintLine(1, "Aborted on Password Dialog (ID #15)")
                'Abort = True

            Case 16
                'invalid password
                PrintLine(1, "Aborted on Invalid Password (ID #16)")
                Abort = True
            Case 17
                'next disk dialog
                PrintLine(1, "Aborted on Next Disk Dialog (ID #17)")
                Abort = True

            Case 18
                'invalid disk alert
                PrintLine(1, "Aborted on Invalid Disk Alert (ID #18)")
                Abort = True

            Case 19
                'location confirm

                ' Sample code provided demonstates how to access
                ' the systemName and systemLocation data.
                ' sysName and sysLoc hold this information after
                ' execution of the code below.  At this point, you may
                ' wish to prompt the user to confirm this location.

                ' We simply accept any location.

                Dim buffer(2) As IntPtr
                Dim test As IntPtr

                ' Copy array of string pointers into an array of integers
                CopyMemory2(buffer(0), Parm, 2 * 4)

                'buffer(0) = buffer(0)

                'Copy the systemName info into sysName
                lLength = lstrlenByNum(buffer(0))
                sysName = New String(Chr(0), lLength)
                lRetCode = lstrcpy(sysName, buffer(0))

                'Copy the systemLocation info into sysLoc
                lLength = lstrlenByNum(buffer(1))
                sysLoc = New String(Chr(0), lLength)
                lRetCode = lstrcpy(sysLoc, buffer(1))

                ' Return the address of a "y" string.  Note above comment
                RTPatchCallBack = Runtime.InteropServices.Marshal.StringToHGlobalAnsi(sYesString)

            Case 20
                ' location dialog
                PrintLine(1, "Aborted on Location Dialog (ID #20)")
                Abort = True

            Case 21 'idle callBack
            Case 22 'searching for system location

        End Select

        If Abort Then
            ' This will cause RTPatchApply32 to ABORT the patch
            RTPatchCallBack = New System.IntPtr(0)
        End If
    End Function
End Class

Public Class Form1
    Inherits System.Windows.Forms.Form
#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call

    End Sub

    'Form overrides dispose to clean up the component list.
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing Then
            If Not (components Is Nothing) Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(disposing)
    End Sub
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents ApplyBtn As System.Windows.Forms.Button
    Friend WithEvents CacelBtn As System.Windows.Forms.Button

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.Container

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.ApplyBtn = New System.Windows.Forms.Button()
        Me.CacelBtn = New System.Windows.Forms.Button()
        Me.TextBox1 = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.Location = New System.Drawing.Point(16, 40)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(232, 16)
        Me.Label1.TabIndex = 1
        Me.Label1.Text = "Enter a valid RTPatch Apply Command Line"
        '
        'ApplyBtn
        '
        Me.ApplyBtn.Location = New System.Drawing.Point(176, 112)
        Me.ApplyBtn.Name = "ApplyBtn"
        Me.ApplyBtn.Size = New System.Drawing.Size(64, 32)
        Me.ApplyBtn.TabIndex = 2
        Me.ApplyBtn.Text = "Apply"
        '
        'CacelBtn
        '
        Me.CacelBtn.Location = New System.Drawing.Point(256, 112)
        Me.CacelBtn.Name = "CacelBtn"
        Me.CacelBtn.Size = New System.Drawing.Size(64, 32)
        Me.CacelBtn.TabIndex = 2
        Me.CacelBtn.Text = "Cancel"
        '
        'TextBox1
        '
        Me.TextBox1.Location = New System.Drawing.Point(16, 72)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.Size = New System.Drawing.Size(304, 20)
        Me.TextBox1.TabIndex = 0
        Me.TextBox1.Text = "patch.rtp"
        '
        'Form1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 13)
        Me.ClientSize = New System.Drawing.Size(328, 158)
        Me.Controls.AddRange(New System.Windows.Forms.Control() {Me.CacelBtn, Me.ApplyBtn, Me.Label1, Me.TextBox1})
        Me.Name = "Form1"
        Me.Text = "RTPatch VB.Net Example"
        Me.ResumeLayout(False)

    End Sub

#End Region

    Private Sub CancelBtn_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CacelBtn.Click
        End
    End Sub

    Private Sub ApplyBtn_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ApplyBtn.Click
        Dim x As Integer
        FileOpen(1, "\patch.log", OpenMode.Output)
        x = RTPatch.RTPatchApply32(TextBox1.Text, AddressOf RTPatch.RTPatchCallBack, True)
        FileClose(1)
        MsgBox(Str(x))
    End Sub
End Class
