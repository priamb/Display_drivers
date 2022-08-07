#include "button.h"

button_t button_SHRANJENE_MERE;
button_t button_PO_MERI;
button_t button_OK;
button_t button_BACK;
button_t button_180;
button_t button_190;
button_t button_200;
button_t button_210;
button_t button_220;
button_t button_230;

void buttonInit(void)
{
	button_SHRANJENE_MERE.x = 100;
	button_SHRANJENE_MERE.y = 50;
	button_SHRANJENE_MERE.w = 150;
	button_SHRANJENE_MERE.h = 40;
	button_SHRANJENE_MERE.button_color = 0x000F;
	snprintf(button_SHRANJENE_MERE.text, 80, "SHRANJENE MERE");
	button_SHRANJENE_MERE.text_color = 0xFFFF;
	button_SHRANJENE_MERE.action = 1;

	button_PO_MERI.x = 100;
	button_PO_MERI.y = 150;
	button_PO_MERI.w = 150;
	button_PO_MERI.h = 40;
	button_PO_MERI.button_color = 0x000F;
	snprintf(button_PO_MERI.text, 80, "PO MERI");
	button_PO_MERI.text_color = 0xFFFF;
	button_PO_MERI.action = 2;

	button_OK.x = 200;
	button_OK.y = 180;
	button_OK.w = 70;
	button_OK.h = 30;
	button_OK.button_color = 0x000F;
	snprintf(button_OK.text, 80, "OK");
	button_OK.text_color = 0xFFFF;
	button_OK.action = 3;

	button_BACK.x = 50;
	button_BACK.y = 180;
	button_BACK.w = 70;
	button_BACK.h = 30;
	button_BACK.button_color = 0x000F;
	snprintf(button_BACK.text, 80, "BACK");
	button_BACK.text_color = 0xFFFF;
	button_BACK.action = 4;

	button_180.x = 60;
	button_180.y = 30;
	button_180.w = 80;
	button_180.h = 50;
	button_180.button_color = 0x000F;
	snprintf(button_180.text, 80, "180%cC", 0xF8);
	button_180.text_color = 0xFFFF;
	button_180.action = 5;

	button_190.x = 60;
	button_190.y = 100;
	button_190.w = 80;
	button_190.h = 50;
	button_190.button_color = 0x000F;
	snprintf(button_190.text, 80, "190%cC", 0xF8);
	button_190.text_color = 0xFFFF;
	button_190.action = 6;

	button_200.x = 60;
	button_200.y = 170;
	button_200.w = 80;
	button_200.h = 50;
	button_200.button_color = 0x000F;
	snprintf(button_200.text, 80, "200%cC", 0xF8);
	button_200.text_color = 0xFFFF;
	button_200.action = 7;

	button_210.x = 190;
	button_210.y = 30;
	button_210.w = 80;
	button_210.h = 50;
	button_210.button_color = 0x000F;
	snprintf(button_210.text, 80, "210%cC", 0xF8);
	button_210.text_color = 0xFFFF;
	button_210.action = 8;

	button_220.x = 190;
	button_220.y = 100;
	button_220.w = 80;
	button_220.h = 50;
	button_220.button_color = 0x000F;
	snprintf(button_220.text, 80, "220%cC", 0xF8);
	button_220.text_color = 0xFFFF;
	button_220.action = 9;

	button_230.x = 190;
	button_230.y = 170;
	button_230.w = 80;
	button_230.h = 50;
	button_230.button_color = 0x000F;
	snprintf(button_230.text, 80, "230%cC", 0xF8);
	button_230.text_color = 0xFFFF;
	button_230.action = 10;

}

void showButton(button_t button){
    LCD_FillRect(button.x, button.y, button.w, button.h, button.button_color);
    UG_SetForecolor(button.text_color);
    UG_SetBackcolor(button.button_color);
    UG_PutString(button.x+5, button.y+(button.h/4), button.text);
}

int checkIfPressed(button_t button, int x, int y){
    if (x >= button.x && x <= button.x+button.w && y >= button.y && y <= button.y+button.h){
        return button.action;
    }
    return 0;
}
