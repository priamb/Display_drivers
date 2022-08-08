#pragma once
#ifndef SCREEN_H_
#define SCREEN_H_

#include <stdio.h>
#include "button.h"
#include "text.h"
#include "slider.h"

void drawScreen(int id);
int checkPressed(int id);
int checkAllButtonsPressed(int id, int x, int y);
int checkButtonPressed(button_t button, int x, int y);
int checkSlider(slider_t slider, int x, int y);
int checkAllSliders(int id, int x, int y);

#endif
