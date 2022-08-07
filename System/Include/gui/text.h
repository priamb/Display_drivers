#pragma once
#ifndef TEXT_H_
#define TEXT_H_

#include <stdio.h>
#include <stdint.h>
#include "lcd.h"

typedef struct {
	uint32_t x;
	uint32_t y;
    const char* text;
    short background, foreground;
} text_t;

extern text_t text_IME_PROJEKTA;
extern text_t text_IME_AVTORJA;
extern text_t text_PROJEKT;
extern text_t text_NAVODILA1;
extern text_t text_NAVODILA2;
extern text_t text_NAVODILA3;
extern text_t text_NAVODILA4;
extern text_t text_NAVODILA5;
extern text_t text_NAVODILA6;

void textInit(void);

void showText(text_t text);

#endif
