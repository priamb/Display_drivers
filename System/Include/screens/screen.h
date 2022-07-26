#pragma once
#ifndef SCREEN_H_
#define SCREEN_H_

#include <stdio.h>
#include "../gui/button.h"
#include "../gui/text.h"

struct Screen
{
    struct Button *btns[4];
    struct Text *text;
};

struct Screen getScreen(int id);
void showScreen(struct Screen screen);
int checkAllButtonsPressed(struct Screen screen, int x, int y);
void checkPressed(struct Screen screen);

#endif
