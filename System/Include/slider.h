
#ifndef INCLUDE_SLIDER_H_
#define INCLUDE_SLIDER_H_
#include "lcd.h"

typedef struct{
    int x, y, w, h;
    float value;
    float max;
} slider_t;

extern slider_t slider;

void sliderInit(void);

void showSlider(slider_t slider);
float checkIfValueChanged(slider_t slider, int x, int y);

#endif /* INCLUDE_SLIDER_H_ */
