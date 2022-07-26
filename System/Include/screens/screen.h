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

struct Screen getScreen(int id)
{
    switch (id)
    {
    case 0: {
    	struct Screen screen;
        struct Text text;
        text.text = &"Temporary text"[0];
        text.foreground = C_GREEN;
        text.background = C_BLACK;
        screen.text = &text;
        for (int i = 0; i < 4; i++)
        {
            screen.btns[i] = NULL;
        }
        return screen;
        break;
    }
    case 1:

    default:{
    	struct Screen screen;
    	return screen;
        break;
    }
    }
}

void showScreen(struct Screen screen)
{
    if (screen.text != NULL)
    {
        showText(*screen.text);
    }
    for (int i = 0; i < 4; i++)
    {
        if (screen.btns[i] != NULL)
        {
            showButton(*screen.btns[i]);
        }
    }
}

int checkAllButtonsPressed(struct Screen screen, int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        if (screen.btns[i] != NULL)
        {
            int action = checkIfPressed(*screen.btns[i], x, y);
            if (action != 0)
            {
                return action;
            }
        }
    }
}

bool pressed = false;
uint16_t x = 0, y = 0;
void checkPressed(struct Screen screen)
{
    bool screenTouched = XPT2046_touch_get_coordinates_if_pressed(&x, &y);
    if (screenTouched && !pressed)
    {
        pressed = true;
    }

    if (!screenTouched && pressed)
    {
        pressed = false;
        // in na to mesto pritiska narišemo krogec s pomočjo uGUI funkcij.
        UG_FillCircle(x, y, 10, C_RED);
        checkAllButtonsPressed(screen, x, y);
    }

    if (pressed)
    {
        // in na to mesto pritiska narišemo krogec s pomočjo uGUI funkcij.
        UG_FillCircle(x, y, 2, C_GREEN);

        // Izpišemo lokacijo še preko SCI vmesnika.
        printf("x = %d\n", x);
        printf("y = %d\n", y);
        // pressed = false;
    }
}

#endif
