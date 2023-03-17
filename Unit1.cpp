//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAngry_Square *Angry_Square;

//zmienne
int s=0;
AnsiString life = 3;
AnsiString wynik = 0;
float p=0;
//ostatnie polozenie weza(uzyte w sterowaniu glowa)
int w=1,a=1,z=1,d=1;







//---------------------------------------------------------------------------
__fastcall TAngry_Square::TAngry_Square(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TAngry_Square::lewoTimer(TObject *Sender)
{       //poruszanie w lewo
        if(p>=0)
        {
        glowa->Left -= 6;
        }
        if(p>=7)
        {
        glowa->Left -= 8;
        }
        if(p>=15)
        {
        glowa->Left -= (7 + (p/20));
        }
        ogon->Left = glowa->Left+glowa->Width;
        ogon->Top = glowa->Top;

}
//---------------------------------------------------------------------------
void __fastcall TAngry_Square::prawoTimer(TObject *Sender)
{       //poruszanie w prawo
        if(p>=0)
        {
        glowa->Left += 6;
        }
        if(p>=7)
        {
        glowa->Left += 8;
        }
        if(p>=15)
        {
        glowa->Left += (7 + (p/20));
        }
        ogon->Left = glowa->Left-glowa->Width;
        ogon->Top = glowa->Top;

}
//---------------------------------------------------------------------------
void __fastcall TAngry_Square::goraTimer(TObject *Sender)
{       //poruszanie w gora
        if(p>=0)
        {
        glowa->Top -= 6;
        }
        if(p>=7)
        {
        glowa->Top -= 8;
        }
        if(p>=15)
        {
        glowa->Top -= (7 + (p/20));
        }
        ogon->Left = glowa->Left;
        ogon->Top = glowa->Top+glowa->Height;

}
//---------------------------------------------------------------------------
void __fastcall TAngry_Square::dolTimer(TObject *Sender)
{       //poruszanie w dol
        if(p>=0)
        {
        glowa->Top += 6;
        }
        if(p>=7)
        {
        glowa->Top += 8;
        }
        if(p>=15)
        {
        glowa->Top += (7 + (p/20));
        }
        ogon->Left = glowa->Left;
        ogon->Top = glowa->Top-glowa->Height;

}
//---------------------------------------------------------------------------
void __fastcall TAngry_Square::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{       //poruszanie sie, klikniencie klawisza

        if (w == 1)
        {
        if(Key == VK_LEFT || Key == 0x41)
        {
        lewo ->Enabled = true;
        prawo ->Enabled = false;
        gora ->Enabled = false;
        dol ->Enabled = false;


        glowa ->Picture->LoadFromFile("img/glowalewo.bmp");
        ogon ->Picture->LoadFromFile("img/ogonprawo.bmp");

        a=1;
        d=0;
        z=0;
        w=0;
        }
        else if(Key == VK_RIGHT || Key == 0x44)
        {
        prawo ->Enabled = true;
        lewo ->Enabled = false;
        gora ->Enabled = false;
        dol ->Enabled = false;


        glowa ->Picture->LoadFromFile("img/glowaprawo.bmp");
        ogon ->Picture->LoadFromFile("img/ogonlewo.bmp");

        a=0;
        d=1;
        z=0;
        w=0;
        }
        }

        if (z == 1)
        {
        if(Key == VK_LEFT || Key == 0x41)
        {
        lewo ->Enabled = true;
        prawo ->Enabled = false;
        gora ->Enabled = false;
        dol ->Enabled = false;


        glowa ->Picture->LoadFromFile("img/glowalewo.bmp");
        ogon ->Picture->LoadFromFile("img/ogonprawo.bmp");

        a=1;
        d=0;
        z=0;
        w=0;
        }
        else if(Key == VK_RIGHT || Key == 0x44)
        {
        prawo ->Enabled = true;
        lewo ->Enabled = false;
        gora ->Enabled = false;
        dol ->Enabled = false;


        glowa ->Picture->LoadFromFile("img/glowaprawo.bmp");
        ogon ->Picture->LoadFromFile("img/ogonlewo.bmp");

        a=0;
        d=1;
        z=0;
        w=0;
        }
        }

        if(a == 1)
        {
        if(Key == VK_UP || Key == 0x57)
        {
        gora ->Enabled = true;
        dol ->Enabled = false;
        lewo ->Enabled = false;
        prawo ->Enabled = false;


        glowa ->Picture->LoadFromFile("img/glowagora.bmp");
        ogon ->Picture->LoadFromFile("img/ogondol.bmp");

        a=0;
        d=0;
        z=0;
        w=1;
        }

        if(Key == VK_DOWN || Key == 0x53)
        {
        dol ->Enabled = true;
        gora ->Enabled = false;
        lewo ->Enabled = false;
        prawo ->Enabled = false;


        glowa ->Picture->LoadFromFile("img/glowadol.bmp");
        ogon ->Picture->LoadFromFile("img/ogongora.bmp");

        a=0;
        d=0;
        z=1;
        w=0;
        }
        }

        if(d == 1)
        {
        if(Key == VK_UP || Key == 0x57)
        {
        gora ->Enabled = true;
        dol ->Enabled = false;
        lewo ->Enabled = false;
        prawo ->Enabled = false;


        glowa ->Picture->LoadFromFile("img/glowagora.bmp");
        ogon ->Picture->LoadFromFile("img/ogondol.bmp");

        a=0;
        d=0;
        z=0;
        w=1;
        }

        if(Key == VK_DOWN || Key == 0x53)
        {
        dol ->Enabled = true;
        gora ->Enabled = false;
        lewo ->Enabled = false;
        prawo ->Enabled = false;


        glowa ->Picture->LoadFromFile("img/glowadol.bmp");
        ogon ->Picture->LoadFromFile("img/ogongora.bmp");

        a=0;
        d=0;
        z=1;
        w=0;
        }
        }

     //wyswietlanie strzalek
            if(Key == VK_UP || Key == 0x57)
    {
    strzalkagora->Visible = true;
    strzalkadol->Visible = false;
    strzalkalewo->Visible = false;
    strzalkaprawo->Visible = false;
    }
    if(Key == VK_DOWN || Key == 0x53)
    {
    strzalkadol->Visible = true;
    strzalkagora->Visible = false;
    strzalkalewo->Visible = false;
    strzalkaprawo->Visible = false;
    }
    if(Key == VK_LEFT || Key == 0x41)
    {
    strzalkalewo->Visible = true;
    strzalkagora->Visible = false;
    strzalkadol->Visible = false;
    strzalkaprawo->Visible = false;
    }
    if(Key == VK_RIGHT || Key == 0x44)
    {
    strzalkaprawo->Visible = true;
    strzalkagora->Visible = false;
    strzalkadol->Visible = false;
    strzalkalewo->Visible = false;
    }

}
//---------------------------------------------------------------------------
void __fastcall TAngry_Square::Timer_GlowaTimer(TObject *Sender)
{       //koniec przez dotkniecie ktorejs sciany
        if( life == 0 || glowa->Left <= tlo->Left ||
        glowa->Top <= tlo->Top ||
        glowa->Left+glowa->Width>= tlo->Width ||
        glowa->Top+glowa->Height>= tlo->Height)
        {
        //wyczyszczenie planszy
        Timer_Glowa->Enabled = false;
        glowa->Visible = false;
        owoc->Visible = false;
        owoc->Left = 1042;
        owoc->Top = 290;
        owoczly->Visible = false;
        Reset->Visible= true;
        Timer1 -> Enabled = false;
        Timer_Owoczly->Enabled = false;
        //stoi w miejscu przy starcie
        gora ->Enabled = false;
        dol ->Enabled = false;
        lewo ->Enabled = false;
        prawo ->Enabled = false;
        w=1,a=1,z=1,d=1;
        //reset strzalek
        strzalkagora->Visible = false;
        strzalkadol->Visible = false;
        strzalkalewo->Visible = false;
        strzalkaprawo->Visible = false;
        ogon->Visible=false;

        //dodanie najlepszego wyniku
        if(wynik == 0 && p > 0)
        {
        wynik = p;
        }
        else if (p >= wynik)
        {
         wynik = p;
        }

        //dzwiek konca gry
        dzwiek_koniec->Play();
        }

        //zjadanie owoca
        if(glowa->Left > owoc->Left-glowa->Width &&
        glowa->Left < owoc->Left+owoc->Width &&
        glowa->Top+glowa->Height > owoc->Top &&
        glowa->Top-glowa->Height < owoc->Top)
        {
        owoc->Visible = false;
        }

        //zjadanie zlego owoca
        if(glowa->Left > owoczly->Left-glowa->Width &&
        glowa->Left < owoczly->Left+owoczly->Width &&
        glowa->Top+glowa->Height > owoczly->Top &&
        glowa->Top-glowa->Height < owoczly->Top)
        {
         owoczly->Left = 1042;
         owoczly->Top = 290;
         owoczly->Visible = false;
         Timer_Owoczly->Enabled = false;
         life = life -1;
        }
}
//---------------------------------------------------------------------------
void __fastcall TAngry_Square::Timer_OwocTimer(TObject *Sender)
{
        //losowe pojawianie sie owoca
      if(glowa->Left > owoc->Left-glowa->Width &&
        glowa->Left < owoc->Left+owoc->Width &&
        glowa->Top+glowa->Height > owoc->Top &&
        glowa->Top-glowa->Height < owoc->Top)
      {
        owoc->Left =  rand()% (tlo->Height-50);
        owoc->Top = rand()% (tlo->Width-50);
        owoc->Visible = true;
        Timer_Owoczly->Enabled = true;
        p++;

        //dzwiek zdobycia punktu
        dzwiek_punkt->Play();

        if(p == 1)
        {
        ogon->Visible=true;
        }
      }
}
//---------------------------------------------------------------------------

void __fastcall TAngry_Square::ResetClick(TObject *Sender)
{
        //reset rozgrywki
        glowa->Left = 340;
        glowa->Top = 340;
        glowa->Visible = true;
        Timer_Glowa->Enabled = true;
        Timer_Owoczly->Enabled = true;
        owoc->Left = 666;
        owoc->Top = 666;
        owoc->Visible = true;
        owoczly->Visible = false;
        Reset->Visible = false;
        s=0;
        p=0;
        life =3;
        Timer1 -> Enabled = true;
        ogon->Left = 340;
        ogon->Top = 284;
        ogon->Visible=false;
        glowa ->Picture->LoadFromFile("img/glowadol.bmp");
        ogon ->Picture->LoadFromFile("img/ogongora.bmp");

        //znikniecie napisow wprowadzajacych
        Label2->Visible = false;
        Label3->Visible = false;
        Label4->Visible = false;
        Label5->Visible = false;
        Label6->Visible = false;
        Label7->Visible = false;
        Label8->Visible = false;
        Label9->Visible = false;

        //dzwiek startu
        //sndPlaySound("snd/start.wav",SND_SYNC);
        dzwiek_start->Play();
}
//---------------------------------------------------------------------------

void __fastcall TAngry_Square::Timer1Timer(TObject *Sender)
{//timer
    s++;

 int godzina, minuta, sekunda;
 AnsiString godz, min, sek;
 godzina = s / 3600;
 godz = IntToStr(godzina);
 if(godzina < 10) godz="0"+godz;

 minuta = (s - godzina * 3600) / 60;
 min = IntToStr(minuta);
  if(minuta < 10) min="0"+min;

 sekunda = s - godzina * 3600 - minuta * 60;
 sek = IntToStr(sekunda);
  if(sekunda < 10) sek="0"+sek;

 Label1 -> Caption = godz+":"+min+":"+sek;
}

//---------------------------------------------------------------------------



void __fastcall TAngry_Square::PunktyTimer(TObject *Sender)
{//punktacja
 AnsiString pkt;
 pkt = FloatToStr(p);
 Punktacja ->Caption = "PUNKTY:"+pkt;
}
//---------------------------------------------------------------------------




void __fastcall TAngry_Square::FormCreate(TObject *Sender)
{
        //wczytywanie dzwieku
        dzwiek_start->FileName = "snd/start.wav";
        dzwiek_start->Open();
        dzwiek_punkt->FileName = "snd/punkt.wav";
        dzwiek_punkt->Open();
        dzwiek_koniec->FileName = "snd/koniec.wav";
        dzwiek_koniec->Open();
}
//---------------------------------------------------------------------------


void __fastcall TAngry_Square::FormClose(TObject *Sender,
      TCloseAction &Action)
{       //zamykanie dzwieku

        dzwiek_start->Close();
        dzwiek_punkt->Close();
        dzwiek_koniec->Close();
}
//---------------------------------------------------------------------------



void __fastcall TAngry_Square::Timer_PredkoscTimer(TObject *Sender)
{       //wyswietlanie predkosci

        AnsiString spd;
        spd = FloatToStr(p);
        if( p >=0)
        {
        spd = 6;
        }
        if( p >=7)
        {
        spd = 8;
        }
        if( p >=15)
        {
        spd = (7 + (p/20));
        }
        Predkosc ->Caption = "PREDKOSC: "+spd;

}
//---------------------------------------------------------------------------




void __fastcall TAngry_Square::Timer_OwoczlyTimer(TObject *Sender)
{       //pojawianie sie zlego owoca
        if(p>=2 && glowa->Left > owoc->Left-glowa->Width &&
        glowa->Left < owoc->Left+owoc->Width &&
        glowa->Top+glowa->Height > owoc->Top &&
        glowa->Top-glowa->Height < owoc->Top)
        {
        owoczly->Left =  rand()% (tlo->Height-50);
        owoczly->Top = rand()% (tlo->Width-50);
        owoczly->Visible = true;
        }
}
//---------------------------------------------------------------------------




void __fastcall TAngry_Square::Timer_ZycieTimer(TObject *Sender)
{   //wyswietlanie zycia
     Zycie ->Caption = "ZYCIE: "+life;
}
//---------------------------------------------------------------------------

void __fastcall TAngry_Square::Timer_WynikTimer(TObject *Sender)
{     //wyswietlanie najlepszego wyniku
      Wynik ->Caption = "NAJLEPSZY WYNIK : "+wynik;
}
//---------------------------------------------------------------------------








