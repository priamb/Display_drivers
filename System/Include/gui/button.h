
#ifndef BUTTON_H_
#define BUTTON_H_

#include <stdio.h>
#include <stdint.h>
#include "lcd.h"

typedef struct {
    uint32_t x, y, w, h;
    char text[80];
    uint16_t text_color;
    uint16_t button_color;
    int action;
} button_t;

extern button_t button_SHRANJENE_MERE;
extern button_t button_PO_MERI;
extern button_t button_OK;
extern button_t button_BACK;
extern button_t button_180;
extern button_t button_190;
extern button_t button_200;
extern button_t button_210;
extern button_t button_220;
extern button_t button_230;

void buttonInit(void);

void showButton(button_t button);

int checkIfPressed(button_t button, int x, int y);

#endif
