Attribute VB_Name = "Module1"
Sub ExportPPTInfo()

Dim DataTextStr As String
Dim SrcPpt As Application
Dim BaseObj As Object
Dim OutputText As String
Dim pShape As Shape
Dim pTextRange As TextRange
Dim pActionSetting As ActionSetting
Dim pSlide As Slide
Dim pTextFrame As TextFrame
Dim flag As Integer
Dim CurType As Integer
Dim SlideNo As Integer
Dim HyperlinkNo As Integer
Dim intOutFile As Integer
Dim Addr As String
Dim Filename As String
Dim Index As Integer
Dim stringLen As Integer
Dim Pos As Integer
Dim Notes As String
Dim defaulttxt, Options, WSH, inputtext, NameNoExt

    flag = 0
    CurType = 0
    SlideNo = 1
    HyperlinkNo = 1


    Set SrcPpt = Application
    For Each SlideItem In SrcPpt.ActivePresentation.Slides
        OutputText = OutputText + "Slide" + Str(SlideNo) + ":" + Chr$(13) & Chr$(10)
        OutputText = OutputText + "Slide Size:" + Chr$(13) & Chr$(10)
        OutputText = OutputText + "Width: " + Str(SlideItem.Master.Width) + Chr$(13) & Chr$(10) + "Height: " + Str(SlideItem.Master.Height) + Chr$(13) & Chr$(10) + Chr$(13) & Chr$(10)

'       MsgBox SlideItem.NotesPage.Shapes.Placeholders(2).TextFrame.TextRange.Text
        Notes = SlideItem.NotesPage.Shapes.Placeholders(2).TextFrame.TextRange.Text
        If Notes <> "" Then
            OutputText = OutputText + "Properties::" + Chr$(13) & Chr$(10)
            OutputText = OutputText + Notes + Chr$(13) & Chr$(10) + Chr$(13) & Chr$(10)
        End If
        
        SlideNo = SlideNo + 1
        HyperlinkNo = 0
        For Each linkitem In SlideItem.Hyperlinks
            flag = 0
            Addr = linkitem.Address
            If Addr = "BoxOnly" Then
                OutputText = OutputText + "Display Box:" + Chr$(13) & Chr$(10)
            Else
                HyperlinkNo = HyperlinkNo + 1
                OutputText = OutputText + "HyperLink" + Str(HyperlinkNo) + "::" + Chr$(13) & Chr$(10)
                OutputText = OutputText + Chr$(34) + "Link Address" + Chr$(34) + ": " + Addr + Chr$(13) & Chr$(10)
            End If
            
            If (TypeName(linkitem.Parent) = "Shape" Or TypeName(linkitem.Parent) = "TextRange") Then
                flag = 1
                If TypeName(linkitem.Parent) = "Shape" Then
                    Set pShape = linkitem.Parent
                    OutputText = OutputText + "Top: " + Str(pShape.Top) + Chr$(13) & Chr$(10) + "Left: " + Str(pShape.Left) + Chr$(13) & Chr$(10) + "Width: " + Str(pShape.Width) + Chr$(13) & Chr$(10) + "Height: " + Str(pShape.Height) + Chr$(13) & Chr$(10)
'                    MsgBox Str(pShape.Left) + " " + Str(pShape.Top)
                Else
                    Set pTextRange = linkitem.Parent
                    OutputText = OutputText + "Top: " + Str(pTextRange.BoundTop) + Chr$(13) & Chr$(10) + "Left: " + Str(pTextRange.BoundLeft) + Chr$(13) & Chr$(10) + "Width: " + Str(pTextRange.BoundWidth) + Chr$(13) & Chr$(10) + "Height: " + Str(pTextRange.BoundHeight) + Chr$(13) & Chr$(10)
'                    MsgBox Str(pTextRange.BoundLeft) + " " + Str(pTextRange.BoundTop)
                End If
            Else
                Select Case TypeName(linkitem.Parent)
                    
                    Case "ActionSetting"
                        Set pActionSetting = linkitem.Parent
                        CurType = 3
                    Case "Slide"
                        Set pSlide = linkitem.Parent
                        CurType = 4
                    
                    Case "TextFrame"
                        Set pTextFrame = linkitem.Parent
                        CurType = 5
                    
                End Select
            
            End If
            While Not (flag = 1)
                Select Case CurType
                    Case 3
                        If (TypeName(pActionSetting.Parent) = "Shape" Or TypeName(pActionSetting.Parent) = "TextRange") Then
                            flag = 1
                            If TypeName(pActionSetting.Parent) = "Shape" Then
                                Set pShape = pActionSetting.Parent
                                OutputText = OutputText + "Top: " + Str(pShape.Top) + Chr$(13) & Chr$(10) + "Left: " + Str(pShape.Left) + Chr$(13) & Chr$(10) + "Width: " + Str(pShape.Width) + Chr$(13) & Chr$(10) + "Height: " + Str(pShape.Height) + Chr$(13) & Chr$(10)
            '                    MsgBox Str(pShape.Left) + " " + Str(pShape.Top)
                            Else
                                Set pTextRange = pActionSetting.Parent
                                OutputText = OutputText + "Top: " + Str(pTextRange.BoundTop) + Chr$(13) & Chr$(10) + "Left: " + Str(pTextRange.BoundLeft) + Chr$(13) & Chr$(10) + "Width: " + Str(pTextRange.BoundWidth) + Chr$(13) & Chr$(10) + "Height: " + Str(pTextRange.BoundHeight) + Chr$(13) & Chr$(10)
            '                    MsgBox Str(pTextRange.BoundLeft) + " " + Str(pTextRange.BoundTop)
                            End If
                        Else
                            Select Case TypeName(pActionSetting.Parent)
                                Case "ActionSetting"
                                    Set pActionSetting = pActionSetting.Parent
                                    CurType = 3
                                Case "Slide"
                                    Set pSlide = pActionSetting.Parent
                                    CurType = 4
                                Case "TextFrame"
                                    Set pTextFrame = pActionSetting.Parent
                                    CurType = 5
                            End Select
                        
                        End If
                    Case 4
                        If (TypeName(pSlide.Parent) = "Shape" Or TypeName(pSlide.Parent) = "TextRange") Then
                            flag = 1
                            If TypeName(pSlide.Parent) = "Shape" Then
                                Set pShape = pSlide.Parent
                                OutputText = OutputText + "Top: " + Str(pShape.Top) + Chr$(13) & Chr$(10) + "Left: " + Str(pShape.Left) + Chr$(13) & Chr$(10) + "Width: " + Str(pShape.Width) + Chr$(13) & Chr$(10) + "Height: " + Str(pShape.Height) + Chr$(13) & Chr$(10)
            '                    MsgBox Str(pShape.Left) + " " + Str(pShape.Top)
                            Else
                                Set pTextRange = pSlide.Parent
                                OutputText = OutputText + "Top: " + Str(pTextRange.BoundTop) + Chr$(13) & Chr$(10) + "Left: " + Str(pTextRange.BoundLeft) + Chr$(13) & Chr$(10) + "Width: " + Str(pTextRange.BoundWidth) + Chr$(13) & Chr$(10) + "Height: " + Str(pTextRange.BoundHeight) + Chr$(13) & Chr$(10)
            '                    MsgBox Str(pTextRange.BoundLeft) + " " + Str(pTextRange.BoundTop)
                            End If
                        Else
                            Select Case TypeName(pSlide.Parent)
                                Case "ActionSetting"
                                    Set pActionSetting = pSlide.Parent
                                    CurType = 3
                                Case "Slide"
                                    Set pSlide = pSlide.Parent
                                    CurType = 4
                                Case "TextFrame"
                                    Set pTextFrame = pSlide.Parent
                                    CurType = 5
                            End Select
                        
                        End If
                    Case 5
                        If (TypeName(pTextFrame.Parent) = "Shape" Or TypeName(pTextFrame.Parent) = "TextRange") Then
                            flag = 1
                            If TypeName(pTextFrame.Parent) = "Shape" Then
                                Set pShape = pTextFrame.Parent
                                OutputText = OutputText + "Top: " + Str(pShape.Top) + Chr$(13) & Chr$(10) + "Left: " + Str(pShape.Left) + Chr$(13) & Chr$(10) + "Width: " + Str(pShape.Width) + Chr$(13) & Chr$(10) + "Height: " + Str(pShape.Height) + Chr$(13) & Chr$(10)
            '                    MsgBox Str(pShape.Left) + " " + Str(pShape.Top)
                            Else
                                Set pTextRange = pTextFrame.Parent
                                OutputText = OutputText + "Top: " + Str(pTextRange.BoundTop) + Chr$(13) & Chr$(10) + "Left: " + Str(pTextRange.BoundLeft) + Chr$(13) & Chr$(10) + "Width: " + Str(pTextRange.BoundWidth) + Chr$(13) & Chr$(10) + "Height: " + Str(pTextRange.BoundHeight) + Chr$(13) & Chr$(10)
            '                    MsgBox Str(pTextRange.BoundLeft) + " " + Str(pTextRange.BoundTop)
                            End If
                        Else
                            Select Case TypeName(pTextFrame.Parent)
                                Case "ActionSetting"
                                    Set pActionSetting = pTextFrame.Parent
                                    CurType = 3
                                Case "Slide"
                                    Set pSlide = pTextFrame.Parent
                                    CurType = 4
                                Case "TextFrame"
                                    Set pTextFrame = pTextFrame.Parent
                                    CurType = 5
                            End Select
                        
                        End If
                End Select
            Wend
            
            
        OutputText = OutputText + Chr$(13) & Chr$(10)
        Next
        
        For Each linkitem In SlideItem.Master.Hyperlinks
            flag = 0
            Addr = linkitem.Address
            If Addr = "BoxOnly" Then
                OutputText = OutputText + "Display Box:" + Chr$(13) & Chr$(10)
            Else
                HyperlinkNo = HyperlinkNo + 1
                OutputText = OutputText + "HyperLink" + Str(HyperlinkNo) + "::" + Chr$(13) & Chr$(10)
                OutputText = OutputText + Chr$(34) + "Link Address" + Chr$(34) + ": " + Addr + Chr$(13) & Chr$(10)
            End If
            
            If (TypeName(linkitem.Parent) = "Shape" Or TypeName(linkitem.Parent) = "TextRange") Then
                flag = 1
                If TypeName(linkitem.Parent) = "Shape" Then
                    Set pShape = linkitem.Parent
                    OutputText = OutputText + "Top: " + Str(pShape.Top) + Chr$(13) & Chr$(10) + "Left: " + Str(pShape.Left) + Chr$(13) & Chr$(10) + "Width: " + Str(pShape.Width) + Chr$(13) & Chr$(10) + "Height: " + Str(pShape.Height) + Chr$(13) & Chr$(10)
'                    MsgBox Str(pShape.Left) + " " + Str(pShape.Top)
                Else
                    Set pTextRange = linkitem.Parent
                    OutputText = OutputText + "Top: " + Str(pTextRange.BoundTop) + Chr$(13) & Chr$(10) + "Left: " + Str(pTextRange.BoundLeft) + Chr$(13) & Chr$(10) + "Width: " + Str(pTextRange.BoundWidth) + Chr$(13) & Chr$(10) + "Height: " + Str(pTextRange.BoundHeight) + Chr$(13) & Chr$(10)
'                    MsgBox Str(pTextRange.BoundLeft) + " " + Str(pTextRange.BoundTop)
                End If
            Else
                Select Case TypeName(linkitem.Parent)
                    
                    Case "ActionSetting"
                        Set pActionSetting = linkitem.Parent
                        CurType = 3
                    Case "Slide"
                        Set pSlide = linkitem.Parent
                        CurType = 4
                    
                    Case "TextFrame"
                        Set pTextFrame = linkitem.Parent
                        CurType = 5
                    
                End Select
            
            End If
            While Not (flag = 1)
                Select Case CurType
                    Case 3
                        If (TypeName(pActionSetting.Parent) = "Shape" Or TypeName(pActionSetting.Parent) = "TextRange") Then
                            flag = 1
                            If TypeName(pActionSetting.Parent) = "Shape" Then
                                Set pShape = pActionSetting.Parent
                                OutputText = OutputText + "Top: " + Str(pShape.Top) + Chr$(13) & Chr$(10) + "Left: " + Str(pShape.Left) + Chr$(13) & Chr$(10) + "Width: " + Str(pShape.Width) + Chr$(13) & Chr$(10) + "Height: " + Str(pShape.Height) + Chr$(13) & Chr$(10)
            '                    MsgBox Str(pShape.Left) + " " + Str(pShape.Top)
                            Else
                                Set pTextRange = pActionSetting.Parent
                                OutputText = OutputText + "Top: " + Str(pTextRange.BoundTop) + Chr$(13) & Chr$(10) + "Left: " + Str(pTextRange.BoundLeft) + Chr$(13) & Chr$(10) + "Width: " + Str(pTextRange.BoundWidth) + Chr$(13) & Chr$(10) + "Height: " + Str(pTextRange.BoundHeight) + Chr$(13) & Chr$(10)
            '                    MsgBox Str(pTextRange.BoundLeft) + " " + Str(pTextRange.BoundTop)
                            End If
                        Else
                            Select Case TypeName(pActionSetting.Parent)
                                Case "ActionSetting"
                                    Set pActionSetting = pActionSetting.Parent
                                    CurType = 3
                                Case "Slide"
                                    Set pSlide = pActionSetting.Parent
                                    CurType = 4
                                Case "TextFrame"
                                    Set pTextFrame = pActionSetting.Parent
                                    CurType = 5
                            End Select
                        
                        End If
                    Case 4
                        If (TypeName(pSlide.Parent) = "Shape" Or TypeName(pSlide.Parent) = "TextRange") Then
                            flag = 1
                            If TypeName(pSlide.Parent) = "Shape" Then
                                Set pShape = pSlide.Parent
                                OutputText = OutputText + "Top: " + Str(pShape.Top) + Chr$(13) & Chr$(10) + "Left: " + Str(pShape.Left) + Chr$(13) & Chr$(10) + "Width: " + Str(pShape.Width) + Chr$(13) & Chr$(10) + "Height: " + Str(pShape.Height) + Chr$(13) & Chr$(10)
            '                    MsgBox Str(pShape.Left) + " " + Str(pShape.Top)
                            Else
                                Set pTextRange = pSlide.Parent
                                OutputText = OutputText + "Top: " + Str(pTextRange.BoundTop) + Chr$(13) & Chr$(10) + "Left: " + Str(pTextRange.BoundLeft) + Chr$(13) & Chr$(10) + "Width: " + Str(pTextRange.BoundWidth) + Chr$(13) & Chr$(10) + "Height: " + Str(pTextRange.BoundHeight) + Chr$(13) & Chr$(10)
            '                    MsgBox Str(pTextRange.BoundLeft) + " " + Str(pTextRange.BoundTop)
                            End If
                        Else
                            Select Case TypeName(pSlide.Parent)
                                Case "ActionSetting"
                                    Set pActionSetting = pSlide.Parent
                                    CurType = 3
                                Case "Slide"
                                    Set pSlide = pSlide.Parent
                                    CurType = 4
                                Case "TextFrame"
                                    Set pTextFrame = pSlide.Parent
                                    CurType = 5
                            End Select
                        
                        End If
                    Case 5
                        If (TypeName(pTextFrame.Parent) = "Shape" Or TypeName(pTextFrame.Parent) = "TextRange") Then
                            flag = 1
                            If TypeName(pTextFrame.Parent) = "Shape" Then
                                Set pShape = pTextFrame.Parent
                                OutputText = OutputText + "Top: " + Str(pShape.Top) + Chr$(13) & Chr$(10) + "Left: " + Str(pShape.Left) + Chr$(13) & Chr$(10) + "Width: " + Str(pShape.Width) + Chr$(13) & Chr$(10) + "Height: " + Str(pShape.Height) + Chr$(13) & Chr$(10)
            '                    MsgBox Str(pShape.Left) + " " + Str(pShape.Top)
                            Else
                                Set pTextRange = pTextFrame.Parent
                                OutputText = OutputText + "Top: " + Str(pTextRange.BoundTop) + Chr$(13) & Chr$(10) + "Left: " + Str(pTextRange.BoundLeft) + Chr$(13) & Chr$(10) + "Width: " + Str(pTextRange.BoundWidth) + Chr$(13) & Chr$(10) + "Height: " + Str(pTextRange.BoundHeight) + Chr$(13) & Chr$(10)
            '                    MsgBox Str(pTextRange.BoundLeft) + " " + Str(pTextRange.BoundTop)
                            End If
                        Else
                            Select Case TypeName(pTextFrame.Parent)
                                Case "ActionSetting"
                                    Set pActionSetting = pTextFrame.Parent
                                    CurType = 3
                                Case "Slide"
                                    Set pSlide = pTextFrame.Parent
                                    CurType = 4
                                Case "TextFrame"
                                    Set pTextFrame = pTextFrame.Parent
                                    CurType = 5
                            End Select
                        
                        End If
                End Select
            Wend
            
            
        OutputText = OutputText + Chr$(13) & Chr$(10)
        Next
        OutputText = OutputText + Chr$(13) & Chr$(10) + Chr$(13) & Chr$(10)
    Next
    
    stringLen = Len(SrcPpt.ActivePresentation.Name)
    For Index = 1 To stringLen
        If Mid(SrcPpt.ActivePresentation.Name, Index, 1) = "." Then
            Pos = Index
        End If
    Next
    
    Filename = Left(SrcPpt.ActivePresentation.Name, Pos - 1) + ".txt"
    NameNoExt = Left(SrcPpt.ActivePresentation.Name, Pos - 1)

    Open Filename For Output As #1
    Print #1, OutputText
    Close #1
    
' Save as PNG files
With Application.ActivePresentation
    '.SaveAs SrcPpt.ActivePresentation.Name, ppSaveAsBMP
    .Export SrcPpt.ActivePresentation.Name, "BMP", 320, 240
End With

Set WSH = CreateObject("WSCRIPT.SHELL")

defaulttxt = "-profile at91sam3u-ek"

inputtext = "Use following format:" + Chr$(13) & Chr$(10) + " -profile <EK-board-name>, default profiles" + Chr$(13) & Chr$(10) + "Or" + Chr$(13) & Chr$(10) + " -bitdepth xx -width xxx -height xxx -rotate xxx [-noreversebitorder]"

Do

Options = InputBox(inputtext, "Input convert param:", defaulttxt)

If Len(Options) = 0 Then
Exit Do

Else

inputtext = "../bin/CreateDemoBin.exe " + Options + " " + NameNoExt

WSH.POPUP (inputtext)

WSH.Run (inputtext)


Exit Do

End If

Loop

End Sub

