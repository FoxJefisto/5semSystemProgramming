//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool picture1;
bool isBtn2Press;
bool isBtn2MouseMove;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void DrawPicture1(TPaintBox *PB1)
{
	PB1->Canvas->Pen->Width = 1;
	// Рисование темно синего фона
	PB1->Canvas->Brush->Color = (TColor)RGB(49,67,109);
	PB1->Canvas->Pen->Color = (TColor)RGB(49,67,109);
	PB1->Canvas->Rectangle(0,0,400,300);
	// Рисование пола
	PB1->Canvas->Brush->Color = (TColor)RGB(163,152,65);
	PB1->Canvas->Pen->Color = (TColor)RGB(163,152,65);
	PB1->Canvas->Rectangle(0,300,400,350);
	// Рисование елки
	PB1->Canvas->Brush->Color = clGreen;
	PB1->Canvas->Pen->Color = clGreen;
	TPoint p[] =
	{ TPoint(195,125), TPoint(170,125), TPoint(210,190),
	TPoint(190,190),TPoint(235,265),
	TPoint(30,265),TPoint(75,190),TPoint(50,190),
	TPoint(90,125),TPoint(70,125),TPoint(133,23)};
	PB1->Canvas->Polygon(p,10);
	// Рисование ствола ёлки
	PB1->Canvas->Brush->Color = (TColor)RGB(119,67,20);
	PB1->Canvas->Pen->Color = (TColor)RGB(119,67,20);
	PB1->Canvas->Rectangle(113,266,150,300);
	// Рисование елочных игрушек
	PB1->Canvas->Brush->Color = (TColor)RGB(225,58,67);
	PB1->Canvas->Pen->Color = (TColor)RGB(225,58,67);
	PB1->Canvas->Ellipse(112,211,138,235);
	PB1->Canvas->Ellipse(138,157,163,181);
	PB1->Canvas->Ellipse(105,83,129,106);
	PB1->Canvas->Brush->Color = (TColor)RGB(68,168,185);
	PB1->Canvas->Pen->Color = (TColor)RGB(68,168,185);
	PB1->Canvas->Ellipse(140,110,165,134);
	PB1->Canvas->Ellipse(90,153,115,177);
	PB1->Canvas->Brush->Color = (TColor)RGB(247,223,119);
	PB1->Canvas->Pen->Color = (TColor)RGB(247,223,119);
	PB1->Canvas->Ellipse(60,235,86,260);
	PB1->Canvas->Ellipse(173,228,199,252);
	// Рисование корабок с подарками
	PB1->Canvas->Brush->Color = (TColor)RGB(254,51,123);
	PB1->Canvas->Pen->Color = (TColor)RGB(254,51,123);
	PB1->Canvas->Rectangle(157,278,185,300);
	PB1->Canvas->Brush->Color = (TColor)RGB(1,255,255);
	PB1->Canvas->Pen->Color = (TColor)RGB(1,255,255);
	PB1->Canvas->Rectangle(68,278,94,300);
	// Рисование ленты к подаркам
	PB1->Canvas->Brush->Color = (TColor)RGB(231,172,0);
	PB1->Canvas->Pen->Color = (TColor)RGB(231,172,0);
	PB1->Canvas->Rectangle(80,278,85,300);
	PB1->Canvas->Rectangle(68,286,94,290);
	PB1->Canvas->Rectangle(170,278,175,300);
	PB1->Canvas->Rectangle(157,288,185,293);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	picture1 = true;
	Form1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormPaint(TObject *Sender)
{
	if (picture1){
		DrawPicture1(PB1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PB2Paint(TObject *Sender)
{
	PB2->Canvas->Pen->Width = 1;
	PB2->Canvas->Pen->Color = (TColor) RGB(0,84,153);
	if(!isBtn2Press)

		}
		else
			PB2->Canvas->Brush->Color = (TColor) RGB(229,241,251);
	else
		PB2->Canvas->Brush->Color = (TColor) RGB(204,228,247);
	PB2->Canvas->Rectangle(0,0, PB2->Width, PB2->Height);
	PB2->Canvas->Font->Size = 8;
	PB2->Canvas->TextOut(20,12,"Кнопка 2");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PB2MouseMove(TObject *Sender, TShiftState Shift, int X, int Y)

{
    isBtn2MouseMove = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PB2MouseLeave(TObject *Sender)
{
	isBtn2MouseMove = false;
}
//---------------------------------------------------------------------------

