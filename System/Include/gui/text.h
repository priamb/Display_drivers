#pragma once
#ifndef TEXT_H_
#define TEXT_H_

#include <stdio.h>
#include "lcd.h"

struct Text{
    const char* text;
    short background, foreground;
};

void showText(struct Text text);

#endif
