//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TRect btn2 {185 ,373, 270, 400};
enum Display{
		NOTHING,
		PICTURE,
		TEXT,
		FIGURE,
		FILL,
		CIRCLE
	};
Display dsp = NOTHING;
enum BtnStatus{
		NOTACTIVE,
		HOVERED,
		PRESSED
	};
BtnStatus btnSt = NOTACTIVE;
int rB, gB, bB, rP, gP, bP, rBack = 255, gBack = 255, bBack = 255;
bool isColorSelect;
bool isBackgroundSelect;
int xCircle = 180, yCircle = 120, rCircle = 60;
TRect Circle{xCircle - rCircle, yCircle - rCircle, xCircle + rCircle, yCircle + rCircle};
TRect CirclePrev = Circle;
int xPrev = xCircle, yPrev = yCircle;
bool isMBPressed;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void DrawPicture()
{
	Form1->Canvas->Pen->Width = 1;
	Form1->Canvas->Brush->Color = (TColor) RGB(rBack, gBack, bBack);
	Form1->Canvas->FillRect(Rect(0,0,Form1->Width, Form1->Height));
	// Рисование темно синего фона
	Form1->Canvas->Brush->Color = (TColor)RGB(49,67,109);
	Form1->Canvas->Pen->Color = (TColor)RGB(49,67,109);
	Form1->Canvas->Rectangle(0,0,Form1->Width,350);
	// Рисование пола
	Form1->Canvas->Brush->Color = (TColor)RGB(163,152,65);
	Form1->Canvas->Pen->Color = (TColor)RGB(163,152,65);
	Form1->Canvas->Rectangle(0,300,Form1->Width,350);
	// Рисование елки
	Form1->Canvas->Brush->Color = clGreen;
	Form1->Canvas->Pen->Color = clGreen;
	TPoint p[] =
	{ TPoint(195,125), TPoint(170,125), TPoint(210,190),
	TPoint(190,190),TPoint(235,265),
	TPoint(30,265),TPoint(75,190),TPoint(50,190),
	TPoint(90,125),TPoint(70,125),TPoint(133,23)};
	Form1->Canvas->Polygon(p,10);
	// Рисование ствола ёлки
	Form1->Canvas->Brush->Color = (TColor)RGB(119,67,20);
	Form1->Canvas->Pen->Color = (TColor)RGB(119,67,20);
	Form1->Canvas->Rectangle(113,266,150,300);
	// Рисование елочных игрушек
	Form1->Canvas->Brush->Color = (TColor)RGB(225,58,67);
	Form1->Canvas->Pen->Color = (TColor)RGB(225,58,67);
	Form1->Canvas->Ellipse(112,211,138,235);
	Form1->Canvas->Ellipse(138,157,163,181);
	Form1->Canvas->Ellipse(105,83,129,106);
	Form1->Canvas->Brush->Color = (TColor)RGB(68,168,185);
	Form1->Canvas->Pen->Color = (TColor)RGB(68,168,185);
	Form1->Canvas->Ellipse(140,110,165,134);
	Form1->Canvas->Ellipse(90,153,115,177);
	Form1->Canvas->Brush->Color = (TColor)RGB(247,223,119);
	Form1->Canvas->Pen->Color = (TColor)RGB(247,223,119);
	Form1->Canvas->Ellipse(60,235,86,260);
	Form1->Canvas->Ellipse(173,228,199,252);
	// Рисование корабок с подарками
	Form1->Canvas->Brush->Color = (TColor)RGB(254,51,123);
	Form1->Canvas->Pen->Color = (TColor)RGB(254,51,123);
	Form1->Canvas->Rectangle(157,278,185,300);
	Form1->Canvas->Brush->Color = (TColor)RGB(1,255,255);
	Form1->Canvas->Pen->Color = (TColor)RGB(1,255,255);
	Form1->Canvas->Rectangle(68,278,94,300);
	// Рисование ленты к подаркам
	Form1->Canvas->Brush->Color = (TColor)RGB(231,172,0);
	Form1->Canvas->Pen->Color = (TColor)RGB(231,172,0);
	Form1->Canvas->Rectangle(80,278,85,300);
	Form1->Canvas->Rectangle(68,286,94,290);
	Form1->Canvas->Rectangle(170,278,175,300);
	Form1->Canvas->Rectangle(157,288,185,293);
}
//---------------------------------------------------------------------------
void DrawText()
{
	Form1->Canvas->Pen->Width = 1;
	Form1->Canvas->Brush->Color = (TColor) RGB(rBack, gBack, bBack);
	Form1->Canvas->FillRect(Rect(0,0,Form1->Width, Form1->Height));
	// Рисование розового фона
	Form1->Canvas->Brush->Color = (TColor)RGB(223,183,219);
	Form1->Canvas->Pen->Color = (TColor)RGB(231,172,0);
	Form1->Canvas->Rectangle(0,0,Form1->Width,350);

	Form1->Canvas->MoveTo(40, 40);

	Form1->Canvas->Font->Name = "Algerian";
	Form1->Canvas->Font->Color = clRed;
	Form1->Canvas->Font->Height = 26;
	Form1->Canvas->TextOut(Form1->Canvas->PenPos.X, Form1->Canvas->PenPos.Y, "Soon, soon, the new year!");
	Form1->Canvas->MoveTo(40, 70);
	
	Form1->Canvas->Font->Name = "Forte";
	Form1->Canvas->Font->Color = clMaroon;
	Form1->Canvas->Font->Height = 26;
	Form1->Canvas->TextOut(Form1->Canvas->PenPos.X, Form1->Canvas->PenPos.Y, "Santa Claus is coming to visit.");
	Form1->Canvas->MoveTo(40, 100);

	Form1->Canvas->Font->Name = "Bradley Hand ITC";
	Form1->Canvas->Font->Color = clNavy;
	Form1->Canvas->Font->Height = 26;
	Form1->Canvas->TextOut(Form1->Canvas->PenPos.X, Form1->Canvas->PenPos.Y, "The kids are screaming: Yay!");
	Form1->Canvas->MoveTo(40, 130);

	Form1->Canvas->Font->Name = "Curlz MT";
	Form1->Canvas->Font->Color = clGreen;
	Form1->Canvas->Font->Height = 26;
	Form1->Canvas->TextOut(Form1->Canvas->PenPos.X, Form1->Canvas->PenPos.Y, "It's time to decorate the tree!");
}
//---------------------------------------------------------------------------
void DrawFigure(){
	Form1->Canvas->Brush->Color = (TColor) RGB(rBack, gBack, bBack);
	Form1->Canvas->FillRect(Rect(0,0,Form1->Width, Form1->Height));
	Form1->Canvas->Pen->Width = 3;
	if(!isColorSelect){
		rB = random(255);
		gB = random(255);
		bB = random(255);
		rP = random(255);
		gP = random(255);
		bP = random(255);
		isColorSelect = true;
	}
	Form1->Canvas->Brush->Color = (TColor)RGB(rB,gB,bB);
	Form1->Canvas->Pen->Color = (TColor)RGB(rP,gP,bP);
	Form1->Canvas->Ellipse(120,20,280,300);
}
//---------------------------------------------------------------------------
void FillForm(){
	if(!isBackgroundSelect){	
		rBack = random(255);
		gBack = random(255);
		bBack = random(255);
		isBackgroundSelect = true;
	}
	Form1->Canvas->Brush->Color = (TColor) RGB(rBack, gBack, bBack);
	Form1->Canvas->FillRect(Rect(0,0,Form1->Width, Form1->Height));
}
//---------------------------------------------------------------------------
void DrawCircle(){
	Form1->Canvas->Brush->Color = (TColor) RGB(rBack, gBack, bBack);
	Form1->Canvas->FillRect(Rect(0,0,Form1->Width, Form1->Height));
	Form1->Canvas->Brush->Color = clBlack;
	Form1->Canvas->Pen->Color = clBlack;
	Form1->Canvas->Ellipse(xCircle - rCircle, yCircle - rCircle, xCircle + rCircle, yCircle + rCircle);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	dsp = PICTURE;
	Form1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormPaint(TObject *Sender)
{
	switch(dsp){
		case PICTURE:
			DrawPicture();
			break;
        case TEXT:
			DrawText();
			break;
		case FIGURE:
			DrawFigure();
			break;
		case FILL:
			FillForm();
			break;
		case CIRCLE:
			DrawCircle();
			break;
		case NOTHING:
			break;
	}
	Form1->Canvas->Pen->Width = 1;
	Form1->Canvas->Pen->Color = (TColor) RGB(0,120,215);
	switch(btnSt){
		case NOTACTIVE:
			Form1->Canvas->Brush->Color = (TColor) RGB(225,225,225);
			Form1->Canvas->Pen->Width = 2;
			break;
		case HOVERED:
			Form1->Canvas->Brush->Color = (TColor) RGB(229,241,251);
			break;
		case PRESSED:
			Form1->Canvas->Brush->Color = (TColor) RGB(204,228,247);
			break;
	}
	Form1->Canvas->Rectangle(btn2);
	Form1->Canvas->Font->Size = 9;
	Form1->Canvas->Font->Name = "Tahoma";
	Form1->Canvas->Font->Color = clBlack;
	Form1->Canvas->TextOut(201,377,"Button2");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)

{
	if (btn2.Contains(TPoint(X,Y))){
		btnSt = HOVERED;
		::InvalidateRect(Form1->Handle, &btn2, false);
	}
	else
		if(btnSt == HOVERED){
		btnSt = NOTACTIVE;
		::InvalidateRect(Form1->Handle, &btn2, false);
		}

	if (CheckBox1->Checked && isMBPressed && dsp == CIRCLE && (X-xCircle)*(X-xCircle) + (Y-yCircle)*(Y-yCircle) < rCircle*rCircle) {
		int dx = X - xPrev, dy = Y - yPrev;
		xCircle += dx;
		yCircle += dy;
		CirclePrev = Circle;


		Circle.left += dx;
		Circle.right += dx;
		Circle.top += dy - 1;
		Circle.bottom += dy;
		::InvalidateRect(Form1->Handle, &CirclePrev, false);
		::InvalidateRect(Form1->Handle, &Circle, false);
	}
	xPrev = X;
	yPrev = Y;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if (btn2.Contains(TPoint(X,Y))){
		dsp = TEXT;
		btnSt = PRESSED;
		::InvalidateRect(Form1->Handle, &btn2, false);
		Form1->Refresh();
	}

	if( CheckBox1->Checked == false && (X-xCircle)*(X-xCircle) + (Y-yCircle)*(Y-yCircle) < rCircle*rCircle ){
		dsp = NOTHING;
		Form1->Refresh();
	}
	isMBPressed = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if (btn2.Contains(TPoint(X,Y))){
		btnSt = HOVERED;
		::InvalidateRect(Form1->Handle, &btn2, false);
	}
	isMBPressed = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	dsp = FIGURE;
	isColorSelect = false;
	Form1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	dsp = FILL;
	isBackgroundSelect = false;
	Form1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	dsp = CIRCLE;
	Form1->Refresh();	
}
//---------------------------------------------------------------------------

