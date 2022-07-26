#pragma once
#ifndef TEXT_H_
#define TEXT_H_

#include <stdio.h>
#include "lcd.h"

struct Text{
    const char* text;
    short background, foreground;
};

void showText(struct Text text){
    UG_SetForecolor(text.foreground);
    UG_SetBackcolor(text.background);
    UG_PutString(10, 10, text.text);
}

#endif
