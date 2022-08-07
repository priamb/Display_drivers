#include "text.h"
#include "slider.h"

text_t text_IME_PROJEKTA;
text_t text_IME_AVTORJA;
text_t text_PROJEKT;
text_t text_NAVODILA1;
text_t text_NAVODILA2;
text_t text_NAVODILA3;
text_t text_NAVODILA4;
text_t text_NAVODILA5;
text_t text_NAVODILA6;

void textInit(void)
{
	text_IME_PROJEKTA.text = "HOTBED SOLDERING";
	text_IME_PROJEKTA.background = 0x0000;
	text_IME_PROJEKTA.foreground = 0xFFFF;
	text_IME_PROJEKTA.x = 100;
	text_IME_PROJEKTA.y = 90;

	text_IME_AVTORJA.text = "SAMO IN PRIMOZ";
	text_IME_AVTORJA.background = 0x0000;
	text_IME_AVTORJA.foreground = 0xFFFF;
	text_IME_AVTORJA.x = 110;
	text_IME_AVTORJA.y = 120;

	text_PROJEKT.text = "OME PROJEKT";
	text_PROJEKT.background = 0x0000;
	text_PROJEKT.foreground = 0xFFFF;
	text_PROJEKT.x = 120;
	text_PROJEKT.y = 150;

	text_NAVODILA1.text = "Put PCB on hot surface";
	text_NAVODILA1.background = 0x0000;
	text_NAVODILA1.foreground = 0xFFFF;
	text_NAVODILA1.x = 70;
	text_NAVODILA1.y = 70;

	text_NAVODILA2.text = "Preheating PCB";
	text_NAVODILA2.background = 0x0000;
	text_NAVODILA2.foreground = 0xFFFF;
	text_NAVODILA2.x = 100;
	text_NAVODILA2.y = 70;

	text_NAVODILA3.text = "Soldering in process";
	text_NAVODILA3.background = 0x0000;
	text_NAVODILA3.foreground = 0xFFFF;
	text_NAVODILA3.x = 70;
	text_NAVODILA3.y = 70;

	text_NAVODILA4.text = "Soldering complet, remove PCB";
	text_NAVODILA4.background = 0x0000;
	text_NAVODILA4.foreground = 0xFFFF;
	text_NAVODILA4.x = 40;
	text_NAVODILA4.y = 70;

	text_NAVODILA5.text = "HOTBED cooling";
	text_NAVODILA5.background = 0x0000;
	text_NAVODILA5.foreground = 0xFFFF;
	text_NAVODILA5.x = 95;
	text_NAVODILA5.y = 70;

	text_NAVODILA6.text = "Slide for preferred temperature";
	text_NAVODILA6.background = 0x0000;
	text_NAVODILA6.foreground = 0xFFFF;
	text_NAVODILA6.x = 30;
	text_NAVODILA6.y = 30;

}

void showText(text_t text){
    UG_SetForecolor(text.foreground);
    UG_SetBackcolor(text.background);
    UG_PutString(text.x, text.y, text.text);
}
