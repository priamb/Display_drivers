#pragma once
#ifndef BUTTON_H_
#define BUTTON_H_
#include "lcd.h"

struct Button{
    int x, y, w, h;
    const char* text;
    int action;
};

void showButton(struct Button button);

int checkIfPressed(struct Button button, int x, int y);

#endif
