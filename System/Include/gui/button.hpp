#pragma once
#include <stdio.h>
#include "gui/widget.hpp"
#include "lcd.h"
class Button: Widget{
    public: 
    int x;
    int y;
    int w;
    int h;
    const char* text;

    Button(int x, int y, int w, int h, const char* text){
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        this->text = text;
    }

    void show(){
        printf("Button: %s\n", text);
        LCD_FillRect(x, y, w, h, 0xFFFF);
        UG_SetForecolor(C_BLACK);
        UG_SetBackcolor(C_WHITE);
        UG_PutString(x+5, y+(h/4), text);
    }
};
