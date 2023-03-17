//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TAngry_Square : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TImage *glowa;
        TTimer *lewo;
        TTimer *prawo;
        TTimer *gora;
        TTimer *dol;
        TTimer *Timer_Glowa;
        TImage *owoc;
        TTimer *Timer_Owoc;
        TButton *Reset;
        TLabel *Label1;
        TTimer *Timer1;
        TLabel *Punktacja;
        TTimer *Punkty;
        TImage *Tapeta;
        TImage *strzalkalewo;
        TImage *strzalkagora;
        TImage *strzalkaprawo;
        TImage *strzalkadol;
        TTimer *Timer_Ogon;
        TMediaPlayer *dzwiek_start;
        TMediaPlayer *dzwiek_koniec;
        TMediaPlayer *dzwiek_punkt;
        TMediaPlayer *dzwiek_muza;
        TImage *ogon;
        TTimer *Timer_Predkosc;
        TLabel *Predkosc;
        TImage *owoczly;
        TTimer *Timer_Owoczly;
        TLabel *Zycie;
        TTimer *Timer_Zycie;
        TTimer *Timer_Wynik;
        TLabel *Wynik;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        void __fastcall lewoTimer(TObject *Sender);
        void __fastcall prawoTimer(TObject *Sender);
        void __fastcall goraTimer(TObject *Sender);
        void __fastcall dolTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Timer_GlowaTimer(TObject *Sender);
        void __fastcall Timer_OwocTimer(TObject *Sender);
        void __fastcall ResetClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall PunktyTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Timer_PredkoscTimer(TObject *Sender);
        void __fastcall Timer_OwoczlyTimer(TObject *Sender);
        void __fastcall Timer_ZycieTimer(TObject *Sender);
        void __fastcall Timer_WynikTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TAngry_Square(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAngry_Square *Angry_Square;
//---------------------------------------------------------------------------
#endif
 