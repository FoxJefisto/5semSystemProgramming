object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 475
  ClientWidth = 475
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object PB1: TPaintBox
    Left = 40
    Top = 32
    Width = 400
    Height = 350
  end
  object PB2: TPaintBox
    Left = 152
    Top = 432
    Width = 75
    Height = 25
    OnMouseDown = PB2MouseDown
    OnMouseLeave = PB2MouseLeave
    OnMouseMove = PB2MouseMove
    OnMouseUp = PB2MouseUp
    OnPaint = PB2Paint
  end
  object Button1: TButton
    Left = 40
    Top = 432
    Width = 75
    Height = 25
    Caption = #1050#1085#1086#1087#1082#1072' 1'
    TabOrder = 0
    OnClick = Button1Click
  end
end