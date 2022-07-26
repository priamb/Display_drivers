#include "gui/button.h"

void showButton(struct Button button){
    LCD_FillRect(button.x, button.y, button.w, button.h, 0xFFFF);
    UG_SetForecolor(C_BLACK);
    UG_SetBackcolor(C_WHITE);
    UG_PutString(button.x+5, button.y+(button.h/4), button.text);
}

int checkIfPressed(struct Button button, int x, int y){
    if (x >= button.x && x <= button.x+button.w && y >= button.y && y <= button.y+button.h){
        return button.action;
    }
    return 0;
}